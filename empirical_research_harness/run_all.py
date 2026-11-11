"""Run all 27 empirical BEFORE-vs-AFTER research benchmarks.

Usage:
    python run_all.py                 # one seed, all concepts
    python run_all.py --seeds 0 1 2   # multiple seeds (robustness sweep)
    python run_all.py --only 10 13    # subset of concept ids

Outputs (under results/):
    html/concept_XX_<slug>.html      interactive Plotly
    png/concept_XX_<slug>.png        static Matplotlib
    metrics.json                     every measured metric
    master_research_benchmarks.html  the master portal
"""
from __future__ import annotations

import argparse
import json
import os
import re
import sys
import time
import traceback
from typing import Any, Dict, List

HERE = os.path.dirname(os.path.abspath(__file__))
if HERE not in sys.path:
    sys.path.insert(0, HERE)

from aprism_harness.dashboard import build_dashboard          # noqa: E402
from aprism_harness.plots import export_figure               # noqa: E402

RESULTS = os.path.join(HERE, "results")
HTML_DIR = os.path.join(RESULTS, "html")
PNG_DIR = os.path.join(RESULTS, "png")
METRICS = os.path.join(RESULTS, "metrics.json")
MASTER = os.path.join(RESULTS, "master_research_benchmarks.html")

CONCEPT_MODULES = ["aprism_harness.concepts_a", "aprism_harness.concepts_b",
                   "aprism_harness.concepts_c"]


def slug(text: str) -> str:
    s = re.sub(r"[^a-z0-9]+", "_", text.lower()).strip("_")
    return s[:60]


def load_concepts() -> List[Dict[str, Any]]:
    out: List[Dict[str, Any]] = []
    seen = set()
    for modname in CONCEPT_MODULES:
        try:
            mod = __import__(modname, fromlist=["CONCEPTS"])
        except Exception as ex:
            print(f"[warn] could not import {modname}: {ex}")
            continue
        for c in getattr(mod, "CONCEPTS", []):
            if c["id"] in seen:
                continue
            seen.add(c["id"])
            out.append(c)
    out.sort(key=lambda c: c["id"])
    return out


def run_one(concept: Dict[str, Any], seeds: List[int]):
    """Run a concept over all seeds; return (result, artifacts, per_seed_rows)."""
    cid = concept["id"]
    base_metrics: Dict[str, Any] = {}
    after_metrics: Dict[str, Any] = {}
    figures: List[Dict[str, Any]] = []
    notes: List[str] = []
    per_seed = []
    source = concept.get("source", "")

    for seed in seeds:
        res = concept["run"](seed)
        b = res.get("baseline", {}).get("metrics", {})
        a = res.get("aprism", {}).get("metrics", {})
        # keep the first seed's metrics as the canonical ones
        if not base_metrics:
            base_metrics = dict(b)
            after_metrics = dict(a)
            figures = res.get("figures", [])
            notes.append(res.get("notes", ""))
            source = res.get("source", source)
        per_seed.append({"seed": seed, "baseline": b, "aprism": a})

    return base_metrics, after_metrics, figures, notes, per_seed, source


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--seeds", type=int, nargs="*", default=[0])
    ap.add_argument("--only", type=int, nargs="*", default=None)
    ap.add_argument("--no-png", action="store_true")
    args = ap.parse_args()

    seeds = args.seeds or [0]
    os.makedirs(HTML_DIR, exist_ok=True)
    os.makedirs(PNG_DIR, exist_ok=True)

    concepts = load_concepts()
    if args.only:
        keep = set(args.only)
        concepts = [c for c in concepts if c["id"] in keep]

    print(f"== APRISM empirical harness: {len(concepts)} concepts, seeds={seeds} ==")

    results: List[Dict[str, Any]] = []
    artifacts: Dict[int, List[Dict[str, Any]]] = {}
    failures: List[Dict[str, Any]] = []
    t0 = time.time()

    for c in concepts:
        cid = c["id"]
        try:
            b, a, figs, notes, per_seed, source = run_one(c, seeds)
        except Exception:
            failures.append({"id": cid, "title": c.get("title", ""),
                             "error": traceback.format_exc(limit=4)})
            print(f"  [FAIL] #{cid} {c.get('title','')}: {traceback.format_exc(limit=2)}")
            continue

        arts = []
        for f in figs:
            name = f"concept_{cid:02d}_{slug(f.get('id', c.get('title', 'fig')))}"
            hp = os.path.join(HTML_DIR, name + ".html")
            pp = None if args.no_png else os.path.join(PNG_DIR, name + ".png")
            info = export_figure(f["fig"], hp, pp, title=f.get("title", ""))
            info["title"] = f.get("title", "")
            arts.append(info)
        artifacts[cid] = arts

        note = " | ".join([n for n in notes if n])
        results.append({
            "id": cid, "title": c.get("title", ""), "source": source,
            "baseline": {"label": "BASELINE (feature OFF)", "metrics": b},
            "aprism": {"label": "A-PRISM (feature ON)", "metrics": a},
            "figures": [], "notes": note, "per_seed": per_seed,
        })
        nfig = len([x for x in arts if x.get("html")])
        print(f"  [ok] #{cid:2d} {c.get('title','')[:58]:58s} metrics={len(b)}/{len(a)} figures={nfig}")

    elapsed = time.time() - t0

    payload = {
        "generated": time.strftime("%Y-%m-%d %H:%M:%S"),
        "seeds": seeds,
        "elapsed_s": elapsed,
        "concepts": [
            {k: v for k, v in r.items() if k != "per_seed"} | {"per_seed": r["per_seed"]}
            for r in results
        ],
        "failures": failures,
        "artifacts": {str(k): v for k, v in artifacts.items()},
    }
    os.makedirs(RESULTS, exist_ok=True)
    with open(METRICS, "w", encoding="utf-8") as f:
        json.dump(payload, f, indent=2, default=str)

    build_dashboard(results, MASTER, artifacts,
                    {"generated": payload["generated"], "seeds": seeds, "elapsed_s": elapsed})

    # ---- verification ----
    problems = list(failures)
    for cid, arts in artifacts.items():
        for a in arts:
            if not os.path.exists(a["html"]) or os.path.getsize(a["html"]) == 0:
                problems.append({"id": cid, "error": f"missing/empty HTML {a['html']}"})
            if a.get("png") and (not os.path.exists(a["png"]) or os.path.getsize(a["png"]) == 0):
                problems.append({"id": cid, "error": f"missing/empty PNG {a['png']}"})
    if not os.path.exists(MASTER) or os.path.getsize(MASTER) == 0:
        problems.append({"id": 0, "error": "master dashboard missing/empty"})

    n_html = len([1 for a in artifacts.values() for x in a if x.get("html")])
    n_png = len([1 for a in artifacts.values() for x in a if x.get("png")])
    print(f"\nconcepts ok: {len(results)}/{len(concepts)}  "
          f"figures: {n_html} HTML / {n_png} PNG  elapsed {elapsed:.1f}s")
    print(f"metrics : {METRICS}")
    print(f"master  : {MASTER}")
    if problems:
        print(f"\nVERIFICATION PROBLEMS ({len(problems)}):")
        for p in problems[:20]:
            print(f"  #{p.get('id')}: {p.get('error', '')[:200]}")
        return 1
    print("\nVERIFICATION OK: all artefacts present and non-empty.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
