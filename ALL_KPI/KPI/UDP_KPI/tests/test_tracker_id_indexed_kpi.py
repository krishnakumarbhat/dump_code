import sys
from pathlib import Path

import numpy as np

KPI_ROOT = Path(__file__).resolve().parents[2]
if str(KPI_ROOT) not in sys.path:
    sys.path.insert(0, str(KPI_ROOT))

from UDP_KPI.b_data_storage.kpi_data_model_storage import KPI_DataModelStorage
from UDP_KPI.c_business_layer.tracker_matching_kpi import process_tracker_kpi

GRP = "F360_Object_Log"
SENSOR = "TEST_SENSOR"
STREAM = "TRACKER_STREAM"


def _build_tracker_storage(scan_payloads, grp_name=GRP):
    """scan_payloads: {scan_idx: {signal_name: [per-slot values]}}."""
    scan_indices = list(scan_payloads.keys())
    storage = KPI_DataModelStorage()
    storage.initialize(scan_indices, SENSOR)
    storage.init_parent(STREAM)
    # Preserve insertion order of first scan for parent/child discipline.
    signal_names = list(scan_payloads[scan_indices[0]].keys())
    for sig in signal_names:
        dataset = [
            np.asarray(scan_payloads[s][sig], dtype=np.float64)
            for s in scan_indices
        ]
        storage.set_value(dataset, sig, grp_name)
    return storage


def test_classic_layout_match():
    scans = [1, 2]
    inp = {
        1: {"trkID": [1, 2], "vcs_xposn": [10.0, 20.0], "vcs_yposn": [5.0, 6.0],
            "vcs_xvel": [1.0, 2.0], "vcs_yvel": [0.5, 0.6], "f_moving": [1, 0]},
        2: {"trkID": [1, 2], "vcs_xposn": [11.0, 21.0], "vcs_yposn": [5.1, 6.1],
            "vcs_xvel": [1.1, 2.1], "vcs_yvel": [0.5, 0.6], "f_moving": [1, 0]},
    }
    out = {
        1: {"trkID": [1, 2], "vcs_xposn": [10.005, 20.005], "vcs_yposn": [5.005, 6.005],
            "vcs_xvel": [1.005, 2.005], "vcs_yvel": [0.505, 0.605], "f_moving": [1, 0]},
        2: {"trkID": [1, 2], "vcs_xposn": [11.005, 21.005], "vcs_yposn": [5.105, 6.105],
            "vcs_xvel": [1.105, 2.105], "vcs_yvel": [0.505, 0.605], "f_moving": [1, 0]},
    }
    res = process_tracker_kpi(
        _build_tracker_storage(inp), _build_tracker_storage(out), SENSOR, STREAM
    )
    assert res["success"] is True
    kpi = res["kpi_results"]
    assert kpi["numerator"] >= 1  # tp
    assert kpi["accuracy"] > 0
    assert "Tracker Accuracy" in res["html_content"]


def test_matrix_fail_zero_percent_still_success():
    inp = {
        1: {"trkID": [1], "vcs_xposn": [10.0], "vcs_yposn": [5.0],
            "vcs_xvel": [1.0], "vcs_yvel": [0.5], "f_moving": [1]},
    }
    out = {
        1: {"trkID": [1], "vcs_xposn": [15.0], "vcs_yposn": [5.0],
            "vcs_xvel": [1.0], "vcs_yvel": [0.5], "f_moving": [1]},
    }
    res = process_tracker_kpi(
        _build_tracker_storage(inp), _build_tracker_storage(out), SENSOR, STREAM
    )
    assert res["success"] is True
    kpi = res["kpi_results"]
    assert kpi["numerator"] == 0  # tp
    assert kpi["total_fn"] > 0
    assert kpi["accuracy"] == 0.0


def test_id_absent_one_side_fp_fn():
    inp = {
        1: {"trkID": [1, 2], "vcs_xposn": [10.0, 20.0], "vcs_yposn": [5.0, 6.0],
            "vcs_xvel": [1.0, 2.0], "vcs_yvel": [0.5, 0.6], "f_moving": [1, 1]},
    }
    out = {
        1: {"trkID": [2, 3], "vcs_xposn": [20.005, 30.0], "vcs_yposn": [6.005, 7.0],
            "vcs_xvel": [2.005, 3.0], "vcs_yvel": [0.605, 0.7], "f_moving": [1, 1]},
    }
    res = process_tracker_kpi(
        _build_tracker_storage(inp), _build_tracker_storage(out), SENSOR, STREAM
    )
    assert res["success"] is True
    kpi = res["kpi_results"]
    assert kpi["numerator"] == 1  # only ID 2 co-occurs and passes
    assert kpi["total_fn"] == 1  # input-only ID 1
    assert kpi["total_fp"] == 1  # output-only ID 3


def test_fmoving_disagree_not_tp():
    inp = {
        1: {"trkID": [1], "vcs_xposn": [10.0], "vcs_yposn": [5.0],
            "vcs_xvel": [1.0], "vcs_yvel": [0.5], "f_moving": [1]},
    }
    out = {
        1: {"trkID": [1], "vcs_xposn": [10.005], "vcs_yposn": [5.005],
            "vcs_xvel": [1.005], "vcs_yvel": [0.505], "f_moving": [0]},
    }
    res = process_tracker_kpi(
        _build_tracker_storage(inp), _build_tracker_storage(out), SENSOR, STREAM
    )
    assert res["success"] is True
    assert res["kpi_results"]["numerator"] == 0


def test_al_layout_padding_ignored():
    inp = {
        1: {"object_trkID": [5, 0, 0], "object_xposn": [10.0, 0.0, 0.0],
            "object_yposn": [20.0, 0.0, 0.0], "object_xvel": [1.0, 0.0, 0.0],
            "object_yvel": [2.0, 0.0, 0.0], "object_f_moving": [1, 0, 0]},
    }
    out = {
        1: {"object_trkID": [5, 0, 0], "object_xposn": [10.005, 0.0, 0.0],
            "object_yposn": [20.005, 0.0, 0.0], "object_xvel": [1.005, 0.0, 0.0],
            "object_yvel": [2.005, 0.0, 0.0], "object_f_moving": [1, 0, 0]},
    }
    res = process_tracker_kpi(
        _build_tracker_storage(inp), _build_tracker_storage(out), SENSOR, STREAM
    )
    assert res["success"] is True
    kpi = res["kpi_results"]
    assert kpi["numerator"] == 1
    assert kpi["denominator"] == 1  # padding slots excluded


def test_duplicate_ids_multiset_consume():
    inp = {
        1: {"trkID": [7, 7], "vcs_xposn": [10.0, 10.0], "vcs_yposn": [20.0, 20.0],
            "vcs_xvel": [1.0, 1.0], "vcs_yvel": [2.0, 2.0], "f_moving": [1, 1]},
    }
    out = {
        1: {"trkID": [7, 7], "vcs_xposn": [10.005, 10.005], "vcs_yposn": [20.005, 20.005],
            "vcs_xvel": [1.005, 1.005], "vcs_yvel": [2.005, 2.005], "f_moving": [1, 1]},
    }
    res = process_tracker_kpi(
        _build_tracker_storage(inp), _build_tracker_storage(out), SENSOR, STREAM
    )
    assert res["success"] is True
    tp = res["kpi_results"]["numerator"]
    assert tp == 2  # bounded by min(2, 2), not 2*2=4


def test_missing_velocity_still_matches():
    inp = {
        1: {"trkID": [1], "vcs_xposn": [10.0], "vcs_yposn": [5.0], "f_moving": [1]},
    }
    out = {
        1: {"trkID": [1], "vcs_xposn": [10.005], "vcs_yposn": [5.005], "f_moving": [1]},
    }
    res = process_tracker_kpi(
        _build_tracker_storage(inp), _build_tracker_storage(out), SENSOR, STREAM
    )
    assert res["success"] is True
    assert res["kpi_results"]["numerator"] >= 1


def test_missing_core_signal_fails():
    inp = {
        1: {"trkID": [1], "vcs_xposn": [10.0]},
    }
    out = {
        1: {"trkID": [1], "vcs_xposn": [10.005]},
    }
    res = process_tracker_kpi(
        _build_tracker_storage(inp), _build_tracker_storage(out), SENSOR, STREAM
    )
    assert res["success"] is False
    assert "Failed to process tracker KPIs" in res["html_content"]


def test_zero_empty_storages_fail_no_exception():
    empty_in = KPI_DataModelStorage()
    empty_in.initialize([1, 2], SENSOR)
    empty_in.init_parent(STREAM)
    empty_out = KPI_DataModelStorage()
    empty_out.initialize([1, 2], SENSOR)
    empty_out.init_parent(STREAM)
    res = process_tracker_kpi(empty_in, empty_out, SENSOR, STREAM)
    assert res["success"] is False  # no exception raised


# --- v2 association backend: zero-regression and ID-independence checks ---

from UDP_KPI.c_business_layer.tracker_matching_kpi_v2 import (  # noqa: E402
    AssociationConfig, associate_arrays, process_tracker_kpi_v2,
)


def _shuffled_id_storages():
    """Same physical objects, output IDs shifted by 10 (no ID overlap)."""
    inp = {
        1: {"trkID": [1, 2], "vcs_xposn": [10.0, 20.0], "vcs_yposn": [5.0, 6.0],
            "vcs_xvel": [1.0, 2.0], "vcs_yvel": [0.5, 0.6], "f_moving": [1, 0]},
        2: {"trkID": [1, 2], "vcs_xposn": [11.0, 21.0], "vcs_yposn": [5.1, 6.1],
            "vcs_xvel": [1.1, 2.1], "vcs_yvel": [0.5, 0.6], "f_moving": [1, 0]},
    }
    out = {
        1: {"trkID": [11, 12], "vcs_xposn": [10.0, 20.0], "vcs_yposn": [5.0, 6.0],
            "vcs_xvel": [1.0, 2.0], "vcs_yvel": [0.5, 0.6], "f_moving": [1, 0]},
        2: {"trkID": [11, 12], "vcs_xposn": [11.0, 21.0], "vcs_yposn": [5.1, 6.1],
            "vcs_xvel": [1.1, 2.1], "vcs_yvel": [0.5, 0.6], "f_moving": [1, 0]},
    }
    return _build_tracker_storage(inp), _build_tracker_storage(out)


def test_v2_legacy_is_byte_compatible_with_v1():
    inp, out = _shuffled_id_storages()
    v1 = process_tracker_kpi(inp, out, SENSOR, STREAM)["kpi_results"]
    v2 = process_tracker_kpi_v2(inp, out, SENSOR, STREAM,
                                algorithm="legacy_id")["kpi_results"]
    for key in ("numerator", "denominator", "total_fp", "total_fn",
                "precision", "recall", "f1", "jaccard"):
        assert v1[key] == v2[key], key
    assert v1["matching_mode"] == v2["matching_mode"]


def test_v2_matches_when_ids_are_shuffled():
    inp, out = _shuffled_id_storages()
    v1 = process_tracker_kpi(inp, out, SENSOR, STREAM)["kpi_results"]
    assert v1["numerator"] == 0  # the reported failure mode
    res = process_tracker_kpi_v2(inp, out, SENSOR, STREAM,
                                 algorithm="hungarian_normalized")
    kpi = res["kpi_results"]
    assert res["success"] is True
    assert kpi["numerator"] == 4  # 2 tracks x 2 scans, IDs ignored
    assert kpi["recall"] == 100.0
    assert "hungarian_normalized" in res["html_content"]
    assert "ID-independent" in res["html_content"]


def test_v2_all_backends_recover_shuffled_ids():
    inp, out = _shuffled_id_storages()
    fields_in = {"track_id": np.array([[1.0, 2.0], [1.0, 2.0]]),
                 "x_position": np.array([[10.0, 20.0], [11.0, 21.0]]),
                 "y_position": np.array([[5.0, 6.0], [5.1, 6.1]]),
                 "x_velocity": np.array([[1.0, 2.0], [1.1, 2.1]]),
                 "y_velocity": np.array([[0.5, 0.6], [0.5, 0.6]]),
                 "f_moving": np.array([[1.0, 0.0], [1.0, 0.0]])}
    fields_out = dict(fields_in, track_id=np.array([[11.0, 12.0], [11.0, 12.0]]))
    for algo in ("hungarian_normalized", "mahalanobis", "gospa",
                 "multi_scan", "obb_auction"):
        cfg = AssociationConfig(tx=0.011, ty=0.011, tvx=0.021, tvy=0.021,
                                algorithm=algo, window=1)
        result = associate_arrays(fields_in, fields_out, cfg)
        assert result["total_matches"] == 4, algo
        assert result["total_fp"] == 0, algo
        assert result["total_fn"] == 0, algo


def test_v2_rejects_unknown_algorithm_and_scipy_gate():
    inp, out = _shuffled_id_storages()
    res = process_tracker_kpi_v2(inp, out, SENSOR, STREAM, algorithm="nope")
    assert res["success"] is False
    try:
        AssociationConfig(tx=0.0)
    except ValueError:
        pass
    else:  # pragma: no cover
        raise AssertionError("zero gate must be rejected")


def test_v2_clutter_precision_not_hidden():
    """50 false alarms must lower precision, not be silently consumed."""
    fields_in = {"track_id": np.array([[1.0]]),
                 "x_position": np.array([[10.0]]), "y_position": np.array([[5.0]]),
                 "x_velocity": np.array([[0.0]]), "y_velocity": np.array([[0.0]]),
                 "f_moving": np.array([[1.0]])}
    clutter_ids = np.arange(100, 150, dtype=float).reshape(1, -1)
    fields_out = {"track_id": np.concatenate([[[2.0]], clutter_ids], axis=1),
                  "x_position": np.concatenate([[[10.0]], np.full((1, 50), 99.0)], axis=1),
                  "y_position": np.concatenate([[[5.0]], np.full((1, 50), 99.0)], axis=1),
                  "x_velocity": np.zeros((1, 51)), "y_velocity": np.zeros((1, 51)),
                  "f_moving": np.ones((1, 51))}
    cfg = AssociationConfig(tx=0.011, ty=0.011, algorithm="hungarian_normalized")
    result = associate_arrays(fields_in, fields_out, cfg)
    assert result["total_matches"] == 1
    assert result["total_fp"] == 50
    assert result["total_fn"] == 0


def test_factory_switches_backend_from_config(monkeypatch):
    """The production flag must select v1 or v2 without touching call sites."""
    from UDP_KPI.b_data_storage.kpi_config_storage import KPI_VALIDATION_RULES
    from UDP_KPI.c_business_layer import kpi_factory

    inp, out = _shuffled_id_storages()
    data = {"TRACKER_STREAM": {"input": inp, "output": out}}

    monkeypatch.setitem(KPI_VALIDATION_RULES["tracker_thresholds"],
                        "association_algorithm", "legacy_id")
    legacy = kpi_factory._run_tracker(data, SENSOR)[0]["kpi_results"]
    assert legacy["numerator"] == 0  # IDs do not overlap

    monkeypatch.setitem(KPI_VALIDATION_RULES["tracker_thresholds"],
                        "association_algorithm", "hungarian_normalized")
    v2 = kpi_factory._run_tracker(data, SENSOR)[0]["kpi_results"]
    assert v2["numerator"] == 4
    assert v2["association_algorithm"] == "hungarian_normalized"


def test_gospa_penalizes_a_scan_with_no_outputs():
    """Empty scans must add GOSPA missed-target penalty, not disappear."""
    fields_in = {
        "track_id": [np.array([1.0]), np.array([1.0])],
        "x_position": [np.array([10.0]), np.array([10.5])],
        "y_position": [np.array([5.0]), np.array([5.0])],
        "x_velocity": [np.array([0.0]), np.array([0.0])],
        "y_velocity": [np.array([0.0]), np.array([0.0])],
        "f_moving": [np.array([1.0]), np.array([1.0])],
    }
    fields_out = {
        "track_id": [np.array([2.0]), np.array([])],
        "x_position": [np.array([10.0]), np.array([])],
        "y_position": [np.array([5.0]), np.array([])],
        "x_velocity": [np.array([0.0]), np.array([])],
        "y_velocity": [np.array([0.0]), np.array([])],
        "f_moving": [np.array([1.0]), np.array([])],
    }
    cfg = AssociationConfig(algorithm="gospa", gospa_cutoff=2.0)
    result = associate_arrays(fields_in, fields_out, cfg)
    assert result["total_matches"] == 1
    assert result["gospa"]["missed_mean"] > 0.0
    assert result["gospa"]["scans"] == 2
