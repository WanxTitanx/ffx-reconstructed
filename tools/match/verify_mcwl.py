#!/usr/bin/env python3
"""Build the x86 instruction reconstruction and prove its complete code body."""
import argparse
import hashlib
import json
from pathlib import Path

import definitive_match as match
import mcwl_build
import coff_relocations as coff_reader

ROOT = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--exe', type=Path, default=Path(match.EXE_DEFAULT))
    parser.add_argument('--output-dir', type=Path,
                        default=ROOT / 'recon/ffx/byteproof/build')
    args = parser.parse_args()
    data, sections = match.load_pe(args.exe)
    if hashlib.sha256(data).hexdigest() != match.EXE_SHA256:
        raise ValueError('reference executable SHA-256 mismatch')
    reference = match.va_reader(data, sections)(0x617420, 144)
    if reference != (ROOT / 'recon/ffx/mcwl.ref.bin').read_bytes():
        raise ValueError('saved function reference disagrees with the pinned executable')
    output = args.output_dir.resolve()
    output.mkdir(parents=True, exist_ok=True)
    mcwl_build.build(ROOT,output)
    receipt,artifacts,observed=mcwl_build.read_bundle(ROOT,output)
    candidate=artifacts['mcwl.bin']
    if candidate != reference:
        raise ValueError('assembled function differs from the original 144 bytes')
    # Verify the COFF conversion too, rather than assuming that packaging is inert.
    coff_data = artifacts['mcwl.obj']
    sections = [s for s in coff_reader.parse_coff(coff_data)['sections']
                if s['name'] == '.text']
    if len(sections) != 1 or sections[0]['raw'] != reference or sections[0]['relocations']:
        raise ValueError('COFF body differs or has unresolved relocations')
    report = {
        'target_sha256': match.EXE_SHA256, 'target_size': len(data),
        'function': 'Phyre_MemCmp_WithLength', 'va': '0x617420', 'size': 144,
        'reconstruction_kind': 'assembly_source', 'recovered_c_source': False,
        'exact_bytes': True, 'masked_bytes': 0, 'coff_relocations': 0,
        'source_sha256': receipt['inputs']['source']['sha256'],
        'candidate_sha256': hashlib.sha256(candidate).hexdigest(),
        'reference_sha256': hashlib.sha256(reference).hexdigest(),
        'coff_sha256': hashlib.sha256(coff_data).hexdigest(),
        'semantic_harness_sha256': receipt['inputs']['harness']['sha256'],
        'semantic_checks': receipt['semantic_checks'], 'semantic_exit_code': 0,
        'semantic_host': 'Linux i386, native execution, Windows cdecl body',
        'commands': receipt['commands'],
        'assembler_version': receipt['assembler_version'],
        'compiler_version': receipt['compiler_version'],
        'build_manifest_sha256': hashlib.sha256((output/'build-manifest.json').read_bytes()).hexdigest(),
        'build_provenance_verified': True,
    }
    mcwl_build.support.check_unchanged(observed)
    (output / 'proof.json').write_text(json.dumps(report, indent=2) + chr(10))
    print(json.dumps({k: report[k] for k in
                      ('va', 'size', 'exact_bytes', 'masked_bytes', 'semantic_checks')}, indent=2))
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
