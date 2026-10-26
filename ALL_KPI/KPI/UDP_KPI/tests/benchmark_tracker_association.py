"""Entry point required by the KPI test layout.

The implementation lives in
``empirical_research_harness/benchmarks/benchmark_tracker_kpi_algorithms.py``;
this alias keeps the benchmark runnable from the UDP_KPI test directory.
"""
from pathlib import Path
import runpy

_IMPL = Path(__file__).resolve().parents[4] / "empirical_research_harness" / "benchmarks" / (
    "benchmark_tracker_kpi_algorithms.py"
)
runpy.run_path(str(_IMPL), run_name="__main__")
