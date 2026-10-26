"""Tracker KPI v2 — normalized spatial-kinematic Hungarian (DEFAULT).

Purpose: the production default. Objects are paired by solving a global
one-to-one assignment on a dimensionless cost built from the configured
position/velocity gates, so identity comes from geometry instead of ``trkID``.

Inputs: input/output tracker streams, sensor id, stream name.
Outputs: KPI dict with ``association_algorithm="hungarian_normalized"``.
"""
from UDP_KPI.c_business_layer.tracker_matching_kpi_v2 import process_tracker_kpi_v2

VERSION = "v2"
ALGORITHM = "hungarian_normalized"
LABEL = "Hungarian on normalized gate cost (default)"


def process_tracker_kpi(input_data, output_data, sensor_id: str, stream_name: str):
    """Run the tracker KPI with the normalized Hungarian backend."""
    return process_tracker_kpi_v2(input_data, output_data, sensor_id, stream_name,
                                  algorithm=ALGORITHM)


__all__ = ["process_tracker_kpi", "VERSION", "ALGORITHM", "LABEL"]
