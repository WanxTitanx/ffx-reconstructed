#!/usr/bin/env python3
"""Verify the VS2012 C/LTCG function build against the pinned FFX.exe."""
import argparse
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

import definitive_match as match

ROOT = Path(__file__).resolve().parents[2]
COMPILER_VERSION = '17.00.50727.1'


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def distinct_keys(pairs):
    result = {}
    for key, value in pairs:
        if key in result:
            raise ValueError(f'duplicate manifest key: {key}')
        result[key] = value
    return result


def verify_provenance(candidate_path, image):
    """Validate the build receipt against retained inputs and this checkout."""
    directory = candidate_path.parent
    manifest_path = directory / 'build-manifest.json'
    manifest_data = manifest_path.read_bytes()
    try:
        manifest = json.loads(manifest_data, object_pairs_hook=distinct_keys)
    except (ValueError, UnicodeError) as exc:
        raise ValueError(f'invalid build manifest: {exc}') from exc
    if (not isinstance(manifest, dict)
            or type(manifest.get('schema_version')) is not int
            or manifest['schema_version'] != 1
            or manifest.get('status') != 'complete'):
        raise ValueError('build manifest must describe a complete schema-version-1 build')

    def record(group, key, filename, data):
        records = manifest.get(group)
        entry = records.get(key) if isinstance(records, dict) else None
        if not isinstance(entry, dict) or entry.get('file') != filename:
            raise ValueError(f'invalid {key} file in build manifest')
        digest = sha256(data)
        if entry.get('sha256') != digest:
            raise ValueError(f'{key} SHA-256 differs from build manifest')
        return digest

    source = ROOT / 'recon/ffx/ffx_memcmp.c'
    recipe = ROOT / 'recon/ffx/byteproof/build_memcmp.bat'
    helper = recipe.with_name('build_memcmp.py')
    input_hashes = {}
    for key, current in (('source', source), ('recipe', recipe), ('helper', helper)):
        filename = 'inputs/' + current.name
        snapshot = (directory / filename).read_bytes()
        input_hashes[key] = record('inputs', key, filename, snapshot)
        if current.read_bytes() != snapshot:
            raise ValueError(f'current {key} differs from build-time snapshot; rebuild required')
    record('outputs', 'candidate', candidate_path.name, image)
    log_data = (directory / 'build.log').read_bytes()
    log_hash = record('outputs', 'build_log', 'build.log', log_data)
    versions = re.findall(r'Compiler Version ([0-9.]+) for x86',
                          log_data.decode('utf-8', errors='replace'))
    if (versions != [COMPILER_VERSION]
            or manifest.get('compiler_version') != COMPILER_VERSION
            or manifest.get('compiler_architecture') != 'x86'):
        raise ValueError('build manifest and log must identify the pinned x86 compiler')
    return {
        'source_sha256': input_hashes['source'],
        'build_recipe_sha256': input_hashes['recipe'],
        'build_helper_sha256': input_hashes['helper'],
        'build_log_sha256': log_hash,
        'build_manifest_sha256': sha256(manifest_data),
        'build_provenance_verified': True,
        'compiler_version': COMPILER_VERSION, 'compiler_architecture': 'x86',
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('candidate', type=Path)
    args = parser.parse_args()
    original, original_sections = match.load_pe(match.EXE_DEFAULT)
    if hashlib.sha256(original).hexdigest() != match.EXE_SHA256:
        raise ValueError('reference executable SHA-256 mismatch')
    image, sections = match.load_pe(args.candidate)
    provenance = verify_provenance(args.candidate, image)
    optional = struct.unpack_from('<I', image, 0x3c)[0] + 24
    entry = (struct.unpack_from('<I', image, optional + 16)[0]
             + struct.unpack_from('<I', image, optional + 28)[0])
    if not any(name == '.text' and start == entry and size == 112
               for name, start, size, _raw, _rawsize in sections):
        raise ValueError('candidate must contain exactly one 112-byte entry function')
    candidate = match.va_reader(image, sections)(entry, 112)
    reference = match.va_reader(original, original_sections)(0x401020, 112)
    if candidate is None or reference is None or candidate != reference:
        raise ValueError('compiled function is not byte-identical')
    report = {
        'target_sha256': match.EXE_SHA256,
        'function': 'FFX_memcmp', 'va': '0x401020', 'size': 112,
        'reconstruction_kind': 'c_source', 'exact_bytes': True, 'masked_bytes': 0,
        **provenance,
        'candidate_entry': hex(entry),
        'candidate_image_sha256': hashlib.sha256(image).hexdigest(),
        'candidate_sha256': hashlib.sha256(candidate).hexdigest(),
        'reference_sha256': hashlib.sha256(reference).hexdigest(),
        'candidate_image_is_runnable_game': False,
        'whole_executable_reconstructed': False,
    }
    output = args.candidate.with_name('proof.json')
    if output.resolve() == args.candidate.resolve():
        raise ValueError('proof output cannot replace the candidate image')
    output.write_text(json.dumps(report, indent=2) + chr(10))
    print(json.dumps(report, indent=2))
    return 0


if __name__ == '__main__':
    try:
        raise SystemExit(main())
    except (OSError, ValueError, struct.error) as exc:
        print(f'error: {exc}', file=sys.stderr)
        raise SystemExit(2)
