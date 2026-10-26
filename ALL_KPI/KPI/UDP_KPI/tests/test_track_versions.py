"""Guard the six selectable matcher versions and the ``main.py`` CLI contract."""
import importlib
import subprocess
import sys
from pathlib import Path

import pytest

BUSINESS = Path(__file__).resolve().parents[1] / "c_business_layer"
VERSIONS = ("v1", "v2", "v3", "v4", "v5", "v6")
EXPECTED = {
    "v1": "legacy_id",
    "v2": "hungarian_normalized",
    "v3": "mahalanobis",
    "v4": "gospa",
    "v5": "obb_auction",
    "v6": "multi_scan",
}


@pytest.mark.parametrize("version", VERSIONS)
def test_each_version_binds_one_algorithm(version):
    """Every track_vN module exists, is callable and names its own backend."""
    sys.path.insert(0, str(BUSINESS.parents[1]))
    mod = importlib.import_module(f"UDP_KPI.c_business_layer.track_{version}")
    assert mod.ALGORITHM == EXPECTED[version]
    assert mod.VERSION == version
    assert callable(mod.process_tracker_kpi)


def test_default_version_is_hungarian():
    """The CLI default must stay on the production Hungarian backend."""
    sys.path.insert(0, str(BUSINESS.parents[1]))
    main = importlib.import_module("UDP_KPI.c_business_layer.main")
    assert main.DEFAULT_VERSION == "v2"
    assert importlib.import_module(
        f"UDP_KPI.c_business_layer.track_{main.DEFAULT_VERSION}").ALGORITHM == "hungarian_normalized"


def test_cli_rejects_unknown_version():
    """An unknown selector fails loudly instead of silently picking a default."""
    out = subprocess.run([sys.executable, str(BUSINESS / "main.py"), "a.h5", "b.h5", "v9"],
                         capture_output=True, text=True, cwd=str(BUSINESS))
    assert out.returncode != 0
    assert "invalid choice" in (out.stderr or "").lower()
