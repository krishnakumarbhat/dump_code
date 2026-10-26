"""Tracker KPI v4 — GOSPA-based association.

Purpose: use the Generalized Optimal Sub-Pattern Assignment cost so missed
targets and false tracks are penalised inside the assignment itself, not only
in the KPI afterwards. Cut-off distance comes from ``gospa_cutoff``.

Inputs: input/output tracker streams, sensor id, stream name.
Outputs: KPI dict with ``association_algorithm="gospa"``.
"""
from UDP_KPI.c_business_layer.tracker_matching_kpi_v2 import process_tracker_kpi_v2

VERSION = "v4"
ALGORITHM = "gospa"
LABEL = "GOSPA (cardinality-aware) cost"


def process_tracker_kpi(input_data, output_data, sensor_id: str, stream_name: str):
    """Run the tracker KPI with the GOSPA backend."""
    return process_tracker_kpi_v2(input_data, output_data, sensor_id, stream_name,
                                  algorithm=ALGORITHM)


__all__ = ["process_tracker_kpi", "VERSION", "ALGORITHM", "LABEL"]
