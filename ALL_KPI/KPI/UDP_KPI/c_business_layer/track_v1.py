"""Tracker KPI v1 — the original ID-keyed matcher (baseline, unchanged).

Purpose: keep the pre-association behaviour callable by name so every later
version can be diffed against it. It matches objects on the composite key
``(scan_index, trkID)`` exactly as the shipped tracker KPI always did.

Inputs: the two ``KPI_DataModelStorage`` tracker streams (input/output) plus the
sensor id and stream name, forwarded untouched to ``tracker_matching_kpi``.
Outputs: the same ``{"kpi_results", "html_content", "success"}`` dict as before.
"""
from UDP_KPI.c_business_layer.tracker_matching_kpi import process_tracker_kpi  # noqa: F401

VERSION = "v1"
ALGORITHM = "legacy_id"
LABEL = "legacy ID-keyed (scan, trkID)"

__all__ = ["process_tracker_kpi", "VERSION", "ALGORITHM", "LABEL"]
