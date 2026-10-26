"""Tracker KPI v3 — Mahalanobis (gate-independent) association.

Purpose: score candidate pairs by the squared Mahalanobis distance of the
position/velocity residual instead of the normalized gate cost. Because it is
scale-aware it keeps its accuracy when the configured gate is unrealistically
tight — which is exactly why it is not the default.

Inputs: input/output tracker streams, sensor id, stream name.
Outputs: KPI dict with ``association_algorithm="mahalanobis"``.
"""
from UDP_KPI.c_business_layer.tracker_matching_kpi_v2 import process_tracker_kpi_v2

VERSION = "v3"
ALGORITHM = "mahalanobis"
LABEL = "Mahalanobis residual cost"


def process_tracker_kpi(input_data, output_data, sensor_id: str, stream_name: str):
    """Run the tracker KPI with the Mahalanobis backend."""
    return process_tracker_kpi_v2(input_data, output_data, sensor_id, stream_name,
                                  algorithm=ALGORITHM)


__all__ = ["process_tracker_kpi", "VERSION", "ALGORITHM", "LABEL"]
