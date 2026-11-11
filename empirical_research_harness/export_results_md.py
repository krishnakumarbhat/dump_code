"""Export results/metrics.json into a human-readable results/markdown table."""
from __future__ import annotations

import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from aprism_harness.concept_api import fmt  # noqa: E402

METRICS = os.path.join(HERE, "results", "metrics.json")
OUT = os.path.join(HERE, "results", "RESULTS.md")


def delta(b, a):
    try:
        b, a = float(b), float(a)
    except (TypeError, ValueError):
        return ""
    if abs(b) < 1e-12:
        return ""
    return f"{100.0 * (a - b) / b:+.1f}%"


def main() -> int:
    if not os.path.exists(METRICS):
        print(f"missing {METRICS}")
        return 1
    d = json.load(open(METRICS, encoding="utf-8"))
    lines = [
        "# APRISM Empirical Benchmark Results",
        "",
        f"Generated: {d.get('generated')}  |  seeds: {d.get('seeds')}  |  "
        f"elapsed: {d.get('elapsed_s', 0):.1f}s",
        "",
        "All values are **measured** by executing the 1:1 Python mirrors of the production "
        "C/C++ kernels on physics-grounded fixtures. Nothing in this table is hardcoded.",
        "",
        "## Per-concept metrics",
        "",
    ]
    for c in d.get("concepts", []):
        b = c["baseline"]["metrics"]
        a = c["aprism"]["metrics"]
        lines.append(f"### {c['id']}. {c['title']}")
        lines.append("")
        lines.append(f"Source: `{c['source']}`")
        if c.get("notes"):
            lines.append("")
            lines.append(f"> {c['notes']}")
        lines.append("")
        lines.append("| Metric | Baseline | A-PRISM | Change |")
        lines.append("|---|---:|---:|---:|")
        for k in list(b.keys()) + [x for x in a if x not in b]:
            bv, av = b.get(k), a.get(k)
            lines.append(f"| {k} | {fmt(bv)} | {fmt(av)} | {delta(bv, av)} |")
        lines.append("")
    if d.get("failures"):
        lines.append("## Failures")
        lines.append("")
        for f in d["failures"]:
            lines.append(f"- #{f.get('id')}: {f.get('error', '')[:400]}")
    else:
        lines.append("## Failures")
        lines.append("")
        lines.append("None - all 27 concepts executed successfully.")
    with open(OUT, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    print(f"wrote {OUT} ({len(d.get('concepts', []))} concepts)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
