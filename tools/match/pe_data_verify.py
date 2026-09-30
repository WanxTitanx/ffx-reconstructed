#!/usr/bin/env python3
"""Resolve data-section symbols from their compiled COFF definitions."""
import argparse
import json
import re
from pathlib import Path
import coff_relocations as coff
import definitive_match as exact
import leaf_reconstruct as leaf
import leaf_build as support
import pe_data_source as source
ROOT = Path(__file__).resolve().parents[2]


def defined_bindings(obj, placements):
    result = {}
    for symbol in obj['symbols'].values():
        name = symbol['name']
        if not re.fullmatch('_sym_[0-9a-f]{8}', name) or symbol['section'] <= 0 or symbol['storage'] != 2:
            continue
        section = obj['sections'][symbol['section'] - 1]
        if section['name'] not in placements or not 0 <= symbol['value'] < section['raw_size']:
            raise ValueError('data symbol is outside its declared section')
        va = placements[section['name']] + symbol['value']
        if va != int(name[5:], 16) or name in result:
            raise ValueError('symbol label differs from the placed address')
        result[name] = va
    return result


def read_bundle(package):
    plan_data = (package/'plan.json').read_bytes()
    manifest_data = (package/'build/manifest.json').read_bytes()
    plan = support.parse_json(plan_data, 'data plan')
    manifest = support.parse_json(manifest_data, 'data manifest')
    if manifest['plan_sha256'] != support.digest(plan_data):
        raise ValueError('data plan changed after build')
    if plan['generator_sha256'] != support.digest(Path(source.__file__).read_bytes()):
        raise ValueError('data generator changed')
    observed = {package/'plan.json':plan_data, package/'build/manifest.json':manifest_data}
    for name,raw in (('plan.json',plan_data),('generator.py',Path(source.__file__).read_bytes())):
        snapshot=package/'build/inputs'/name
        if snapshot.read_bytes()!=raw:
            raise ValueError('data input snapshot changed')
        observed[snapshot]=raw
    log_path=package/'build/build.log'
    log_data=log_path.read_bytes()
    if support.digest(log_data)!=manifest['build_log_sha256']:
        raise ValueError('data assembly log changed')
    observed[log_path]=log_data
    objects = {}
    entries = {entry['source']:entry for entry in manifest['entries']}
    if len(entries) != len(manifest['entries']) or len(entries) != len(plan['chunks']):
        raise ValueError('duplicate or missing data build records')
    for chunk in plan['chunks']:
        entry = entries[chunk['source']]
        if entry['object'] != chunk['section'] + '.obj':
            raise ValueError('wrong data object path')
        source_path = package/chunk['source']
        source_data = source_path.read_bytes()
        if support.digest(source_data) != chunk['source_sha256'] or entry['source_sha256'] != chunk['source_sha256']:
            raise ValueError('data declaration changed')
        object_path = package/'build'/entry['object']
        raw = object_path.read_bytes()
        if support.digest(raw) != entry['object_sha256']:
            raise ValueError('data object changed')
        objects[chunk['section']] = coff.parse_coff(raw)
        observed[source_path] = source_data
        snapshot=package/'build/inputs'/chunk['source']
        if snapshot.read_bytes()!=source_data:
            raise ValueError('compiled data source snapshot differs')
        observed[snapshot]=source_data
        observed[object_path] = raw
    return plan, manifest, objects, observed


def verify(package, code_bindings=None):
    plan, manifest, objects, observed = read_bundle(package)
    original, original_sections = exact.load_pe(exact.EXE_DEFAULT)
    if support.digest(original) != exact.EXE_SHA256 or plan['target_sha256'] != exact.EXE_SHA256:
        raise ValueError('reference mismatch')
    read = exact.va_reader(original, original_sections)
    original_relocations = set(leaf.pe_relocations(original, original_sections))
    placements = {chunk['section']:chunk['va'] for chunk in plan['chunks']}
    bindings = {}
    for obj in objects.values():
        for name, va in defined_bindings(obj, placements).items():
            if name in bindings:
                raise ValueError('data symbol has multiple definitions')
            bindings[name] = va
    if code_bindings:
        for name, va in code_bindings.items():
            if name in bindings and bindings[name] != va:
                raise ValueError('conflicting code/data symbol')
            bindings[name] = va
    linked, pending, records = {}, {}, []
    for chunk in plan['chunks']:
        obj = objects[chunk['section']]
        selected = [s for s in obj['sections'] if s['name'] == chunk['section']]
        if len(selected) != 1:
            raise ValueError('declared data section is missing')
        section = selected[0]
        if section['raw_size'] != chunk['size']:
            raise ValueError('assembled data size differs')
        if chunk['zero_storage']:
            if section['raw'] or section['relocations']:
                raise ValueError('zero-initialized storage has file bytes or references')
            records.append(dict(chunk, verified_zero_storage=True))
            continue
        records_in_section = [r for r in section['relocations'] if r['type']]
        actual_sites = {chunk['va'] + r['offset'] for r in records_in_section}
        expected_sites = {x for x in original_relocations if chunk['va'] <= x < chunk['va'] + chunk['size']}
        if actual_sites != expected_sites or any(r['type'] != coff.DIR32 for r in records_in_section):
            raise ValueError('data COFF relocations differ from actual PE pointer sites')
        undefined = sorted({r['symbol_name'] for r in records_in_section if r['symbol_name'] not in bindings})
        if undefined:
            pending[chunk['section']] = undefined
            continue
        raw, evidence = coff.relocate(section, chunk['va'], bindings)
        reference = read(chunk['va'], chunk['size'])
        if raw != reference or support.digest(raw) != chunk['reference_sha256']:
            raise ValueError('data section differs after genuine relocation')
        linked[chunk['section']] = raw
        records.append(dict(chunk, exact_bytes=True, linked_sha256=support.digest(raw),
                            applied_relocations=len(evidence)))
    support.check_unchanged(observed)
    report = {'target_sha256':exact.EXE_SHA256, 'defined_data_symbols':len(bindings),
              'literal_data_bytes':sum(len(x) for x in linked.values()),
              'records':records, 'unresolved_sections':pending,
              'unresolved_code_symbols':sorted({s for names in pending.values() for s in names}),
              'complete_data_dependency_closure':not pending,
              'whole_executable_reconstructed':False}
    (package/'proof.json').write_bytes((json.dumps(report, indent=2)+'\n').encode())
    print('Data providers:',len(bindings),'symbols;',report['literal_data_bytes'],
          'fully linked bytes;',len(pending),'sections awaiting code symbols')
    return linked, bindings, report


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--package',type=Path,default=ROOT/'recon/ffx/pe_data')
    args = parser.parse_args()
    verify(args.package)
