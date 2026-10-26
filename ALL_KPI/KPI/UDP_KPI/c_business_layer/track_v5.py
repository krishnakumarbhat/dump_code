"""Tracker KPI v5 — oriented-bounding-box (OBB) auction association.

Purpose: compare rectangles (centre, length, width, heading) rather than
points, and resolve the assignment with an auction instead of a Hungarian
solve. Best position error of the measured backends, lowest F1 of them.

Inputs: input/output tracker streams, sensor id, stream name.
Outputs: KPI dict with ``association_algorithm="obb_auction"``.
"""
from UDP_KPI.c_business_layer.tracker_matching_kpi_v2 import process_tracker_kpi_v2

VERSION = "v5"
ALGORITHM = "obb_auction"
LABEL = "OBB overlap + auction"


def process_tracker_kpi(input_data, output_data, sensor_id: str, stream_name: str):
    """Run the tracker KPI with the OBB auction backend."""
    return process_tracker_kpi_v2(input_data, output_data, sensor_id, stream_name,
                                  algorithm=ALGORITHM)


__all__ = ["process_tracker_kpi", "VERSION", "ALGORITHM", "LABEL"]
