import json
import logging
import os
from typing import Dict, Iterable, List, Optional, Tuple, Union

from InteractivePlot.c_data_storage.config_storage import Gen7V1_V2


_ACTIVE_PLOT_CONFIG = Gen7V1_V2
_ACTIVE_PLOT_CONFIG_SOURCE = "InteractivePlot/c_data_storage/config_storage.py"

ConfigPathArg = Union[None, str, Iterable[str]]



def _normalize_config(raw_config: dict) -> dict:
    if not isinstance(raw_config, dict):
        raise ValueError("Config content must be a JSON object")

    if "Gen7V1_V2" in raw_config and isinstance(raw_config["Gen7V1_V2"], dict):
        return raw_config["Gen7V1_V2"]

    return raw_config



def _as_path_list(config_json_path: ConfigPathArg) -> List[str]:
    """Purpose: accept one path, a list of paths or None. Outputs: clean ordered list."""
    if not config_json_path:
        return []
    if isinstance(config_json_path, (str, os.PathLike)):
        return [os.fspath(config_json_path)]
    return [os.fspath(path) for path in config_json_path if path]



def _merge_config(target: Dict, source: Dict) -> Dict:
    """Purpose: merge stream/signal maps; per-stream union, later file wins per signal."""
    for stream, signals in source.items():
        if isinstance(signals, dict) and isinstance(target.get(stream), dict):
            target[stream].update(signals)
        else:
            target[stream] = signals
    return target



def _is_valid_plot_config(candidate: dict) -> bool:
    if not isinstance(candidate, dict) or not candidate:
        return False

    has_stream_dict = any(isinstance(value, dict) for value in candidate.values())
    return has_stream_dict



def load_plot_config(config_json_path: ConfigPathArg = None) -> Tuple[Dict, str]:
    """Purpose: load and merge one or many plot config JSONs over the built-in default.

    Inputs: a path, a list of paths (merged in order; per-stream signals are unioned,
    a later file overrides an earlier one for the same signal), or None to use
    ./config.json then config_storage.py.
    Outputs: (active config, human readable source description).

    A file that is missing, empty or malformed is skipped with a warning, matching
    the previous single-file behaviour: the run never dies because of one bad config.
    """
    global _ACTIVE_PLOT_CONFIG, _ACTIVE_PLOT_CONFIG_SOURCE

    paths = _as_path_list(config_json_path)
    if not paths:
        default_path = os.path.join(os.getcwd(), "config.json")
        if os.path.exists(default_path):
            paths = [default_path]

    merged: Dict = {}
    loaded_sources: List[str] = []
    for path in paths:
        try:
            if os.path.getsize(path) == 0:
                raise ValueError("Config JSON file is empty")

            with open(path, "r", encoding="utf-8") as cfg_file:
                loaded = json.load(cfg_file)

            normalized = _normalize_config(loaded)
            if not _is_valid_plot_config(normalized):
                raise ValueError("Config JSON is not in expected stream/signal format")
        except Exception as ex:
            logging.warning(
                "Failed to load plot config from %s (%s). Skipping it.", path, ex
            )
            continue

        _merge_config(merged, normalized)
        loaded_sources.append(path)

    if merged:
        _ACTIVE_PLOT_CONFIG = merged
        _ACTIVE_PLOT_CONFIG_SOURCE = " + ".join(loaded_sources)
        logging.info("Using plot configuration from JSON: %s", _ACTIVE_PLOT_CONFIG_SOURCE)
        return _ACTIVE_PLOT_CONFIG, _ACTIVE_PLOT_CONFIG_SOURCE

    _ACTIVE_PLOT_CONFIG = Gen7V1_V2
    _ACTIVE_PLOT_CONFIG_SOURCE = "InteractivePlot/c_data_storage/config_storage.py"
    return _ACTIVE_PLOT_CONFIG, _ACTIVE_PLOT_CONFIG_SOURCE



def get_plot_config() -> Dict:
    return _ACTIVE_PLOT_CONFIG



def get_plot_config_source() -> str:
    return _ACTIVE_PLOT_CONFIG_SOURCE


def get_xy_plot_specs(stream_name: str, stream_config: Optional[Dict] = None) -> list:
    """Return (X, Y) plot specifications declared for a stream.

    A signal config opts into arbitrary axis pairing by declaring
    ``x_signal``/``y_signal`` (each a ``{"stream":..., "name":...}`` dict or a
    plain signal name) plus optional ``color_signal``, ``title``, ``x_label``,
    ``y_label``. This is the schema for Task 2 generalizable (X, Y) plotting.

    Returns a list of spec dicts, one per declared XY plot.
    """
    config = stream_config if stream_config is not None else get_plot_config()
    if not config:
        return []
    stream = config.get(stream_name) if isinstance(config, dict) else None
    if not isinstance(stream, dict):
        upper = str(stream_name or "").upper()
        for key, value in (config or {}).items():
            if isinstance(value, dict) and str(key).upper() == upper:
                stream = value
                break
    if not isinstance(stream, dict):
        return []
    specs = []
    for signal_name, signal_config in stream.items():
        if not isinstance(signal_config, dict):
            continue
        if "x_signal" not in signal_config and "y_signal" not in signal_config:
            continue
        specs.append(
            {
                "plot_id": signal_config.get("plot_id", signal_name),
                "plot_type": signal_config.get("plot_type", "scatter_xy"),
                "x_signal": signal_config.get("x_signal"),
                "y_signal": signal_config.get("y_signal"),
                "color_signal": signal_config.get("color_signal"),
                "title": signal_config.get("title", signal_name),
                "x_label": signal_config.get("x_label", "X"),
                "y_label": signal_config.get("y_label", "Y"),
            }
        )
    return specs
