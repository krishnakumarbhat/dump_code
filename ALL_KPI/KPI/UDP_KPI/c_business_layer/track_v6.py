"""Tracker KPI v6 — multi-scan (temporal window) Hungarian association.

Purpose: allow a match across ``association_window`` scans so a track that is
dropped for one cycle is still paired with its continuation. Costs one extra
lookup per scan.

Inputs: input/output tracker streams, sensor id, stream name.
Outputs: KPI dict with ``association_algorithm="multi_scan"``.
"""
from UDP_KPI.c_business_layer.tracker_matching_kpi_v2 import process_tracker_kpi_v2

VERSION = "v6"
ALGORITHM = "multi_scan"
LABEL = "multi-scan temporal window"


def process_tracker_kpi(input_data, output_data, sensor_id: str, stream_name: str):
    """Run the tracker KPI with the multi-scan backend."""
    return process_tracker_kpi_v2(input_data, output_data, sensor_id, stream_name,
                                  algorithm=ALGORITHM)


__all__ = ["process_tracker_kpi", "VERSION", "ALGORITHM", "LABEL"]
