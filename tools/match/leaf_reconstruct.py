#!/usr/bin/env python3
"""Synthesize bounded C leaf functions, then verify real MSVC COFF code bytes.

No original bytes are embedded in C or copied into generated objects. Recognition
supplies C operations; acceptance always compares the independently compiled body.
Targets are selected before compilation, so duplicate implementations can have
multiple intended addresses without pretending to infer an original symbol name.
"""
import argparse
import bisect
import csv
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

import definitive_match as exact
import leaf_build as provenance

ROOT = Path(__file__).resolve().parents[2]
DEFAULT_PROJECT = Path('/mnt/ssd-kingston/ffx-reconstructed')


def digest(data):
    return hashlib.sha256(data).hexdigest()


def pe_relocations(data, sections):
    """Return actual PE HIGHLOW relocation addresses, never guessed constants."""
    pe = struct.unpack_from('<I', data, 0x3c)[0]
    optional = pe + 24
    directories = struct.unpack_from('<I', data, optional + 92)[0]
    if directories <= 5:
        return []
    if struct.unpack_from('<H', data, pe + 20)[0] < 96 + 6 * 8:
        raise ValueError('incomplete PE relocation directory entry')
    rva, size = struct.unpack_from('<II', data, optional + 96 + 5 * 8)
    if not rva and not size:
        return []
    base = struct.unpack_from('<I', data, optional + 28)[0]
    table = exact.va_reader(data, sections)(base + rva, size)
    if not rva or table is None:
        raise ValueError('PE relocation directory is outside the file')
    relocations, cursor = set(), 0
    while cursor < len(table):
        if cursor + 8 > len(table):
            raise ValueError('truncated PE relocation block header')
        page, block_size = struct.unpack_from('<II', table, cursor)
        if block_size < 8 or block_size % 2 or cursor + block_size > len(table):
            raise ValueError('invalid PE relocation block size')
        for offset in range(cursor + 8, cursor + block_size, 2):
            entry = struct.unpack_from('<H', table, offset)[0]
            type_, displacement = entry >> 12, entry & 0xfff
            if type_ == 3:
                relocations.add(base + page + displacement)
            elif type_ != 0:
                raise ValueError('unsupported PE32 relocation type: %d' % type_)
        cursor += block_size
    return sorted(relocations)


def overlaps_relocation(relocations, va, size):
    index = bisect.bisect_left(relocations, va - 3)
    return index < len(relocations) and relocations[index] < va + size


def pointer(offset):
    return 'p' if not offset else 'p ' + ('+ ' if offset > 0 else '- ') + str(abs(offset))


def memory_operand(code, base):
    """Decode only [eax/ecx], [base+disp8], [base+disp32], reg field zero."""
    if not code:
        return None
    if code[0] == base:
        return 0, 1
    if code[0] == 0x40 + base and len(code) >= 2:
        return struct.unpack_from('<b', code, 1)[0], 2
    if code[0] == 0x80 + base and len(code) >= 5:
        return struct.unpack_from('<i', code, 1)[0], 5
    return None


def recognize(code):
    if len(code) == 6 and code[0] == 0xb8 and code[-1] == 0xc3:
        return {'return_type': 'unsigned int', 'convention': '__cdecl',
                'arguments': 'void', 'body': 'return 0x%08xu;' % struct.unpack_from('<I', code, 1)[0]}
    modes = [(b'', b'\xc3', 1, '__fastcall'),
             (bytes.fromhex('558bec8b4508'), bytes.fromhex('5dc3'), 0, '__cdecl')]
    loads = [(b'\x8b', 'unsigned int', 'unsigned int'),
             (bytes.fromhex('0fb6'), 'unsigned char', 'unsigned int'),
             (bytes.fromhex('0fbe'), 'signed char', 'int'),
             (bytes.fromhex('0fb7'), 'unsigned short', 'unsigned int'),
             (bytes.fromhex('0fbf'), 'short', 'int'),
             (b'\xd9', 'float', 'float'), (b'\xdd', 'double', 'double')]
    for prologue, epilogue, base, convention in modes:
        if not code.startswith(prologue) or not code.endswith(epilogue):
            continue
        body = code[len(prologue):len(code)-len(epilogue)]
        for opcode, field_type, return_type in loads:
            if not body.startswith(opcode):
                continue
            operand = memory_operand(body[len(opcode):], base)
            if operand is None or len(opcode) + operand[1] != len(body):
                continue
            offset, _ = operand
            return {'return_type': return_type, 'convention': convention,
                    'arguments': 'const unsigned char *p',
                    'body': 'return *(const %s *)(%s);' % (field_type, pointer(offset))}
        if body.startswith(b'\xc7'):
            operand = memory_operand(body[1:], base)
            if operand is not None and 1 + operand[1] + 4 == len(body):
                value = struct.unpack_from('<I', body, 1 + operand[1])[0]
                return {'return_type': 'void', 'convention': convention,
                        'arguments': 'unsigned char *p',
                        'body': '*(unsigned int *)(%s) = 0x%08xu;' % (pointer(operand[0]), value)}
    known = {
        '558bec8b45088b4d0c3bc17d028bc18b4d103bc17e028bc15dc3':
            ('int', 'int value, int low, int high',
             'if (value < low) value = low; if (value > high) value = high; return value;'),
        '558bec8b450885c0790433c05dc383f8077c05b8060000005dc3':
            ('int', 'int value', 'if (value < 0) return 0; if (value >= 7) return 6; return value;'),
        '558bec8b4d0c33c085c9740c8b55089003028d52044975f85dc3':
            ('unsigned int', 'const unsigned int *p, unsigned int count',
             'unsigned int sum = 0; while (count--) sum += *p++; return sum;'),
    }
    if code.hex() in known:
        result, args, body = known[code.hex()]
        return {'return_type': result, 'convention': '__cdecl', 'arguments': args, 'body': body}
    # Reviewed parameter order and x87 operation order from the pinned binary.
    # Hashes select reference bodies; they are not inserted into generated C.
    copies = 'dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; dst[3] = src[3];'
    math = {
        '9c829d8685064ad95226b14957e45b255cec45186b8caa870e52921039596120':
            ('unsigned int *dst, const unsigned int *src', copies),
        '07ebe535d68946db45292c64e7a35e36a65c7f0720e2fcab4bfcaff9d300c077':
            ('const unsigned int *src, unsigned int *dst', copies),
        'cf53a5a6e021c0a7582704df9be54a2f5d5ce4ad1b89837ea1d84142e1ab2190':
            ('float *dst, const float *src, float scale',
             'dst[0] = src[0] * scale; dst[1] = src[1] * scale; dst[2] = src[2] * scale;'),
        '0e10d5f3e754e80ee363048582902cf74c207db1062645694f08e209548e78cc':
            ('float *dst, const float *src, float x, float y, float z',
             'dst[0] = src[0] * x; dst[1] = src[1] * y; dst[2] = src[2] * z;'),
        'afc7d0c91594173688623e0086b338c08a66d32adc4653ad857f0ac77c2c4dec':
            ('float *dst, const float *src, unsigned int unused, float amount', '*dst = *src + amount;'),
        '7c2b5cbafe2250157b48446586596a2b37a33e6a4fefade66ac184e353355557':
            ('float *dst, const float *src, unsigned int unused1, unsigned int unused2, float amount', '*dst = *src + amount;'),
        'b66d8d60cd7891e0ec1b2502c939ef70445ddef2f4fca22f27c0056c637fb8e4':
            ('float *dst, const float *src', copies),
        '8891e843d3f4d6cbfadccc6ee4ec8a9891507b9e4b137acfd16be6011ad53ce5':
            ('float *dst, const float *src, float scale',
             'dst[0] = src[0] * scale; dst[1] = src[1] * scale; dst[2] = src[2] * scale; dst[3] = src[3] * scale; return src;'),
        '8df1f788847c56bb970bdadaa2fdc36aa154ddfc8813f53135cb2ddfdba899be':
            ('float *dst, const float *src, float scale', '*dst = *src * scale;'),
    }
    if digest(code) in math:
        args, body = math[digest(code)]
        # The original Vec4 body leaves the input pointer in EAX. Declaring that
        # observable return keeps the matching EAX/ECX allocation under VS2012.
        result = 'const float *' if digest(code) == '8891e843d3f4d6cbfadccc6ee4ec8a9891507b9e4b137acfd16be6011ad53ce5' else 'void'
        return {'return_type': result, 'convention': '__cdecl', 'arguments': args, 'body': body}
    return None


def coff_functions(data):
    if len(data) < 20:
        raise ValueError('truncated COFF header')
    machine, count, _, symptr, nsym, optsize, _ = struct.unpack_from('<HHIIIHH', data)
    if machine != 0x14c or count == 0 or optsize or 20 + count * 40 > len(data):
        raise ValueError('expected complete x86 COFF object sections')
    string_start = symptr + nsym * 18
    if symptr < 20 + count * 40 or string_start + 4 > len(data):
        raise ValueError('COFF symbol table is outside the file')
    string_size = struct.unpack_from('<I', data, string_start)[0]
    if string_size < 4 or string_start + string_size > len(data):
        raise ValueError('COFF string table is incomplete')
    sections = []
    for index in range(count):
        header = 20 + 40 * index
        size, raw, reloc = struct.unpack_from('<III', data, header + 16)
        nreloc = struct.unpack_from('<H', data, header + 32)[0]
        characteristics = struct.unpack_from('<I', data, header + 36)[0]
        if size and (not raw or raw + size > len(data)):
            raise ValueError('COFF section bytes are incomplete')
        if nreloc and (not reloc or reloc + nreloc * 10 > len(data)):
            raise ValueError('COFF relocations are incomplete')
        sections.append((data[raw:raw+size], nreloc, bool(characteristics & 0x20)))
    result, index = {}, 0
    while index < nsym:
        start = symptr + index * 18
        rawname = data[start:start+8]
        value, section, type_, storage, auxiliary = struct.unpack_from('<IhHBB', data, start+8)
        if rawname[:4] == b'\0' * 4:
            offset = struct.unpack_from('<I', rawname, 4)[0]
            if offset < 4 or offset >= string_size:
                raise ValueError('COFF symbol string offset is invalid')
            end = data.find(b'\0', string_start+offset, string_start+string_size)
            if end < 0:
                raise ValueError('COFF symbol string is unterminated')
            name = data[string_start+offset:end].decode('ascii', errors='replace')
        else:
            name = rawname.rstrip(b'\0').decode('ascii', errors='replace')
        if index + auxiliary >= nsym:
            raise ValueError('COFF auxiliary symbol count is invalid')
        selected = re.fullmatch(r'[@_](leaf_[0-9a-f]{8})(?:@[0-9]+)?', name)
        if selected and storage == 2 and type_ & 0x20 and 0 < section <= count:
            blob, relocations, is_code = sections[section-1]
            if value != 0 or not is_code or selected.group(1) in result:
                raise ValueError('leaf symbol is not a distinct function section')
            result[selected.group(1)] = {'bytes': blob, 'relocations': relocations}
        index += 1 + auxiliary
    return result


BATCH = '@echo off\nsetlocal\npy -3 "%~dp0leaf_build.py" %*\nexit /b %errorlevel%\n'


def inventory_rows(data):
    reader = csv.DictReader(data.decode('utf-8').splitlines(), delimiter='\t', strict=True)
    required = {'start', 'size', 'name', 'sha256'}
    fields = reader.fieldnames or []
    if not required.issubset(fields) or len(fields) != len(set(fields)):
        raise ValueError('invalid inventory columns')
    rows = []
    for number, row in enumerate(reader, 2):
        if None in row or any(value is None for value in row.values()) or any(not row[key] for key in required):
            raise ValueError(f'malformed inventory row {number}')
        try:
            va, size = int(row['start'], 16), int(row['size'])
            end = int(row['end'], 16) if 'end' in row else va + size
        except ValueError as exc:
            raise ValueError(f'invalid inventory range on row {number}') from exc
        if (not 0 < va < 2**32 or size <= 0 or va + size > 2**32 or end != va + size
                or not provenance.is_digest(row['sha256'].lower())):
            raise ValueError(f'invalid inventory range/hash on row {number}')
        rows.append({'va': va, 'size': size, 'sha256': row['sha256'].lower(), 'idb_name': row['name']})
    if not rows:
        raise ValueError('inventory is empty')
    provenance.check_ranges([(row['va'], row['size']) for row in rows], 'inventory')
    return rows


def prepare(project, output):
    data, sections = exact.load_pe(exact.EXE_DEFAULT)
    if digest(data) != exact.EXE_SHA256:
        raise ValueError('target SHA-256 mismatch')
    read = exact.va_reader(data, sections)
    inventory = project / 'tools/match/inventory.tsv'
    inventory_bytes = inventory.read_bytes()
    groups = {}
    for row in inventory_rows(inventory_bytes):
        va, size = row['va'], row['size']
        if size < 4 or size > 80:
            continue
        raw = read(va, size)
        if raw is None or digest(raw) != row['sha256']:
            continue
        spec = recognize(raw)
        if spec is None:
            continue
        key = digest(raw)
        if key not in groups:
            groups[key] = {'symbol': 'leaf_%08x' % va, 'source': spec, 'targets': []}
        groups[key]['targets'].append({'va': va, 'size': size, 'idb_name': row['idb_name'], 'sha256': key})
    source_bytes = provenance.render_source(groups.values())
    jobs = {'target_sha256': exact.EXE_SHA256, 'inventory_sha256': digest(inventory_bytes),
            'source_sha256': digest(source_bytes), 'groups': list(groups.values())}
    provenance.validate_jobs(jobs, source_bytes)
    output.mkdir(parents=True, exist_ok=True)
    (output / 'proof.json').unlink(missing_ok=True)
    (output / 'build/build-manifest.json').unlink(missing_ok=True)
    (output / 'ffx_leaf.c').write_bytes(source_bytes)
    (output / 'build.bat').write_bytes(BATCH.encode('utf-8'))
    (output / 'leaf_build.py').write_bytes(Path(provenance.__file__).read_bytes())
    (output / 'leaf_manifest.ps1').unlink(missing_ok=True)
    (output / 'jobs.json').write_text(json.dumps(jobs, indent=2) + '\n', encoding='utf-8')
    print('C implementations:', len(groups), 'intended functions:', sum(len(g['targets']) for g in groups.values()))


def verify(output, project=DEFAULT_PROJECT):
    # Failure must not leave an earlier success proof looking current.
    proof_path = output / 'proof.json'
    proof_path.unlink(missing_ok=True)
    jobs, manifest, manifest_data, object_data, inputs, log, observed = provenance.read_bundle(output)
    inventory_path = project / 'tools/match/inventory.tsv'
    inventory_data = inventory_path.read_bytes()
    if digest(inventory_data) != jobs['inventory_sha256']:
        raise ValueError('current project inventory differs from build-time jobs')
    inventory = {row['va']: row for row in inventory_rows(inventory_data)}
    observed[inventory_path] = inventory_data
    data, sections = exact.load_pe(exact.EXE_DEFAULT)
    if digest(data) != exact.EXE_SHA256 or jobs['target_sha256'] != exact.EXE_SHA256:
        raise ValueError('target SHA-256 mismatch')
    read = exact.va_reader(data, sections)
    reference_relocations = pe_relocations(data, sections)
    objects = {variant: coff_functions(raw) for variant, raw in object_data.items()}
    matches, unmatched, symbols = {}, [], set()
    for group in jobs['groups']:
        symbol = group['symbol']
        for target in group['targets']:
            if inventory.get(target['va']) != target:
                raise ValueError(f'target is not its recorded inventory boundary: {target["va"]:#x}')
            reference = read(target['va'], target['size'])
            if reference is None or digest(reference) != target['sha256']:
                raise ValueError('target changed since job selection')
            if overlaps_relocation(reference_relocations, target['va'], target['size']):
                unmatched.append(dict(target, symbol=symbol, reason='original_base_relocations_unresolved'))
                continue
            found = False
            for variant, functions in objects.items():
                function = functions.get(symbol)
                if function and not function['relocations'] and function['bytes'] == reference:
                    matches[target['va']] = dict(target, symbol=symbol, variant=variant,
                                                object_sha256=digest(object_data[variant]), match_kind='exact_bytes',
                                                relocations=0, masked_bytes=0)
                    symbols.add(symbol)
                    found = True
                    break
            if not found:
                candidates = [functions[symbol] for functions in objects.values() if symbol in functions]
                reason = ('symbol_missing' if not candidates else
                          'coff_relocations_unresolved' if all(f['relocations'] for f in candidates) else
                          'codegen_mismatch')
                unmatched.append(dict(target, symbol=symbol, reason=reason))
    records = list(matches.values())
    report = {'target_sha256': exact.EXE_SHA256, 'source_sha256': digest(inputs['source']),
              'build_recipe_sha256': digest(inputs['recipe']), 'build_helper_sha256': digest(inputs['helper']),
              'build_manifest_sha256': digest(manifest_data), 'build_log_sha256': digest(log),
              'jobs_sha256': digest(inputs['jobs']), 'inventory_sha256': digest(inventory_data),
              'build_provenance_verified': True, 'inventory_verified': True,
              'object_sha256': {key: digest(raw) for key, raw in object_data.items()},
              'compiler_version': manifest['compiler_version'], 'compiler_architecture': manifest['compiler_architecture'],
              'distinct_c_implementations': len(symbols), 'exact_target_functions': len(matches),
              'exact_target_code_bytes': sum(m['size'] for m in records),
              'unmatched_functions': len(unmatched), 'functions': records, 'unmatched': unmatched,
              'method': 'address-selected C reconstruction; independently compiled COFF; zero masks',
              'original_pe_relocations_checked': True,
              'calling_convention_note': 'ECX-only member bodies use ABI-equivalent one-argument fastcall C functions',
              'whole_executable_reconstructed': False, 'layout_reconstructed': False}
    provenance.check_unchanged(observed)
    pending = output / 'proof.json.tmp'
    pending.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    pending.replace(proof_path)
    print('Exact C implementations:', len(symbols), 'functions:', len(matches),
          'code bytes:', report['exact_target_code_bytes'], 'unmatched:', len(unmatched))
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=('prepare', 'verify'))
    parser.add_argument('--project', type=Path, default=DEFAULT_PROJECT)
    parser.add_argument('--output', type=Path, default=ROOT / 'recon/ffx/c_leaf')
    args = parser.parse_args()
    if args.action == 'prepare':
        prepare(args.project, args.output)
    else:
        verify(args.output, args.project)
    return 0


if __name__ == '__main__':
    try:
        raise SystemExit(main())
    except (OSError, ValueError, csv.Error, struct.error) as exc:
        print(f'error: {exc}', file=sys.stderr)
        raise SystemExit(2)
