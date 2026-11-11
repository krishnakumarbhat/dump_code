"""Allowlisted configuration file operations for the KPI page."""

from __future__ import annotations

import json
import os
import re
import shutil
import uuid
import xml.etree.ElementTree as ET
from datetime import datetime, timezone
from pathlib import Path
from typing import Any


CONFIGURATION_SPECS = {
    'config_json': {
        'filename': 'config.json',
        'purpose': 'Interactive Plot configuration.',
        'format': 'json',
    },
    'input_output_json': {
        'filename': 'InputsInteractivePlot.json',
        'purpose': 'Interactive Plot input and output settings.',
        'format': 'json',
    },
    'udp_config_xml': {
        'filename': 'ConfigInteractivePlots.xml',
        'purpose': 'UDP KPI Interactive Plot configuration.',
        'format': 'xml',
    },
    'can_config_xml': {
        'filename': 'ConfigInteractivePlots_bordnet.xml',
        'purpose': 'CAN KPI Interactive Plot configuration.',
        'format': 'xml',
    },
}


def _project_root() -> Path:
    explicit = (os.environ.get('HPCC_PROJECT_ROOT') or '').strip()
    if explicit:
        return Path(explicit)
    return Path(__file__).resolve().parents[1]


def _user_config_dir(net_id: str) -> Path:
    """Return this user's private configuration directory, rejecting unsafe IDs."""
    safe_net_id = str(net_id or '').strip()
    if not re.fullmatch(r'[A-Za-z0-9][A-Za-z0-9._-]{0,63}', safe_net_id):
        raise ValueError('A valid NetID is required to access KPI configurations.')
    configured_root = (os.environ.get('HPCC_KPI_CONFIG_ROOT') or '').strip()
    root = Path(configured_root).expanduser() if configured_root else Path.home() / '.hpcc_kpi_configs'
    root.mkdir(parents=True, exist_ok=True, mode=0o700)
    try:
        root.chmod(0o700)
    except OSError:
        pass
    user_dir = root / safe_net_id
    user_dir.mkdir(parents=True, exist_ok=True, mode=0o700)
    try:
        user_dir.chmod(0o700)
    except OSError:
        pass
    return user_dir


def _path_for(config_id: str, net_id: str, *, seed: bool = True) -> Path:
    """Resolve a user-owned config, seeding it from the bundled defaults once."""
    if config_id not in CONFIGURATION_SPECS:
        raise KeyError(f'Unknown configuration: {config_id}')
    spec = CONFIGURATION_SPECS[config_id]
    path = _user_config_dir(net_id) / spec['filename']
    default_path = _project_root() / 'KPI' / 'intplot_kpi' / spec['filename']
    if seed and not path.exists() and default_path.is_file():
        try:
            with default_path.open('rb') as source, path.open('xb') as destination:
                shutil.copyfileobj(source, destination)
            try:
                path.chmod(0o600)
            except OSError:
                pass
        except FileExistsError:
            pass
    return path


def _validate_content(config_id: str, content: str) -> dict[str, Any]:
    spec = CONFIGURATION_SPECS[config_id]
    if not isinstance(content, str) or not content.strip():
        raise ValueError('Configuration content cannot be empty.')
    try:
        if spec['format'] == 'json':
            json.loads(content)
        else:
            ET.fromstring(content)
    except (json.JSONDecodeError, ET.ParseError) as exc:
        raise ValueError(f"Invalid {spec['format'].upper()} syntax: {exc}") from exc
    return {'valid': True, 'format': spec['format'], 'filename': spec['filename']}


def list_configurations(net_id: str) -> list[dict[str, Any]]:
    entries = []
    for config_id, spec in CONFIGURATION_SPECS.items():
        path = _path_for(config_id, net_id)
        exists = path.is_file()
        entry = {
            'id': config_id,
            'filename': spec['filename'],
            'purpose': spec['purpose'],
            'format': spec['format'],
            'configured_path': str(path),
            'path': str(path),
            'exists': exists,
            'size': path.stat().st_size if exists else 0,
            'modified': datetime.fromtimestamp(path.stat().st_mtime, timezone.utc).isoformat() if exists else None,
        }
        entries.append(entry)
    return entries


def get_configuration(config_id: str, net_id: str) -> tuple[dict[str, Any], str]:
    if config_id not in CONFIGURATION_SPECS:
        raise KeyError(f'Unknown configuration: {config_id}')
    path = _path_for(config_id, net_id)
    if not path.is_file():
        raise FileNotFoundError(f"{CONFIGURATION_SPECS[config_id]['filename']} is not available in the bundled defaults.")
    content = path.read_text(encoding='utf-8')
    metadata = next(item for item in list_configurations(net_id) if item['id'] == config_id)
    return metadata, content


def validate_configuration(config_id: str, content: str, net_id: str) -> dict[str, Any]:
    if config_id not in CONFIGURATION_SPECS:
        raise KeyError(f'Unknown configuration: {config_id}')
    result = _validate_content(config_id, content)
    result['path'] = str(_path_for(config_id, net_id))
    return result


def configuration_path(config_id: str, net_id: str) -> str:
    if config_id not in CONFIGURATION_SPECS:
        raise KeyError(f'Unknown configuration: {config_id}')
    path = _path_for(config_id, net_id)
    if not path.is_file():
        raise FileNotFoundError(f"{CONFIGURATION_SPECS[config_id]['filename']} is not available in the bundled defaults.")
    return str(path)


def save_configuration(config_id: str, content: str, net_id: str) -> dict[str, Any]:
    validate_configuration(config_id, content, net_id)
    path = _path_for(config_id, net_id)

    backup_path = None
    if path.exists():
        stamp = datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
        backup_path = path.with_name(f'{path.name}.bak-{stamp}')
        shutil.copy2(path, backup_path)

    temporary_path = path.with_name(f'.{path.name}.{uuid.uuid4().hex}.tmp')
    try:
        temporary_path.write_text(content, encoding='utf-8', newline='\n')
        try:
            temporary_path.chmod(0o600)
        except OSError:
            pass
        os.replace(temporary_path, path)
    finally:
        if temporary_path.exists():
            temporary_path.unlink()

    metadata = next(item for item in list_configurations(net_id) if item['id'] == config_id)
    metadata['backup_path'] = str(backup_path) if backup_path else None
    return metadata


def save_uploaded_configuration(config_id: str, data: bytes, net_id: str) -> dict[str, Any]:
    try:
        content = data.decode('utf-8')
    except UnicodeDecodeError as exc:
        raise ValueError('Configuration files must be UTF-8 text.') from exc
    return save_configuration(config_id, content, net_id)
