import json

from InteractivePlot.c_data_storage.config_loader import load_plot_config


def test_plot_configs_merge_streams_and_later_signal_override(tmp_path):
    af = tmp_path / "af.json"
    detection = tmp_path / "detection.json"
    general = tmp_path / "general.json"
    af.write_text(json.dumps({"DETECTION_STREAM": {"ran": {"plot_types": ["scatter_plot"]}}}))
    detection.write_text(json.dumps({"DETECTION_STREAM": {"vel": {"plot_types": ["scatter_plot"]}}}))
    general.write_text(json.dumps({
        "DETECTION_STREAM": {"ran": {"plot_types": ["histogram_with_count"]}},
        "VSE_STREAM": {"veh_speed": {"plot_types": ["scatter_plot"]}},
    }))

    config, source = load_plot_config([str(af), str(detection), str(general)])

    assert list(config["DETECTION_STREAM"]) == ["ran", "vel"]
    assert config["DETECTION_STREAM"]["ran"]["plot_types"] == ["histogram_with_count"]
    assert "veh_speed" in config["VSE_STREAM"]
    assert source == " + ".join(map(str, (af, detection, general)))
