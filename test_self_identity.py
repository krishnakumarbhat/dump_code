#!/usr/bin/env python3
"""Quick input-vs-input (identity) test for tracker association gates."""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', 'ALL_KPI', 'KPI'))
sys.path.insert(0, '.')
from threshold_sweep_tracker_kpi import load_scenes, score

def main():
    scenes = load_scenes()
    _, inp, _ = scenes[0]
    print("=== INPUT VS INPUT (same HDF, same array = identity match) ===")
    print("pos  vel    F1%  prec%  rec%   tp  fp  fn  idsw  p95m")
    for p, v in [(0.01, 0.02), (0.5, 0.5), (1.0, 0.5), (1.5, 0.5),
                 (1.5, 1.0), (2.0, 1.0), (3.0, 2.0)]:
        m = score(inp, inp, 'hungarian_normalized', p+1e-7, v+1e-7)
        print(f"{p:>4.2f} {v:>4.2f}  {m['f1_pct']:>5.1f} {m['precision_pct']:>6.1f} "
              f"{m['recall_pct']:>6.1f}  {m['tp']:>4} {m['fp']:>3} {m['fn']:>3} "
              f"{m['id_switches']:>5} {m['pos_err_p95_m']:>5.2f}")

if __name__ == '__main__':
    main()
