#!/usr/bin/env python3
"""Count candidate functions that are byte-identical to a linked function.

Method (unambiguous, no anchor guessing):
  1. each candidate is parsed from `dumpbin /DISASM` output into one byte run;
  2. every IDB function boundary with exactly the same size is compared;
  3. comparison requires all bytes to agree, including address operands;
  4. only candidates matching exactly one boundary are counted.

Usage: definitive_match.py <dump-dis-dir> <inventory.tsv> <out.json>

The old masking is available only with --heuristic-candidates. Those results
are discovery leads, not proof of relocations or linked bytes.
"""

import argparse
import collections
import csv
import hashlib
import json
import os
import re
import struct
import sys
from pathlib import Path

EXE_DEFAULT = '/home/wanderson/Documents/ffx-editor-main/work/_ppp_pool/FFX.exe'
EXE_SHA256 = '78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced'
VA_HI = 0x02600000


def load_pe(path):
    return parse_pe(Path(path).read_bytes())


def parse_pe(data):
    """Validate and describe complete file-backed sections of a PE32 x86 image."""
    if len(data) < 64 or data[:2] != b'MZ':
        raise ValueError('reference is not a complete PE image')
    e = struct.unpack_from('<I', data, 0x3C)[0]
    if e + 24 > len(data) or data[e:e + 4] != bytes.fromhex('50450000'):
        raise ValueError('reference has an invalid PE signature or header')
    nsec = struct.unpack_from('<H', data, e + 6)[0]
    size_opt = struct.unpack_from('<H', data, e + 20)[0]
    if (size_opt < 96 or e + 24 + size_opt + nsec * 40 > len(data)
            or struct.unpack_from('<H', data, e + 24)[0] != 0x10B
            or struct.unpack_from('<H', data, e + 4)[0] != 0x14C):
        raise ValueError('reference must have complete PE32 x86 headers')
    base = struct.unpack_from('<I', data, e + 24 + 28)[0]
    secs = []
    for i in range(nsec):
        off = e + 24 + size_opt + i * 40
        name = data[off : off + 8].rstrip(b'\x00').decode('latin-1')
        vsize, vaddr, rawsize, rawptr = struct.unpack_from('<IIII', data, off + 8)
        if rawsize and (rawptr == 0 or rawptr + rawsize > len(data)):
            raise ValueError(f'reference section {name!r} extends outside the file')
        secs.append((name, base + vaddr, vsize, rawptr, rawsize))
    return data, secs


def va_reader(data, secs):
    def read(va, n):
        if n <= 0:
            return None
        for _name, vaddr, vsize, rawptr, rawsize in secs:
            if vaddr <= va < vaddr + max(vsize, rawsize):
                delta = va - vaddr
                off = rawptr + delta
                if delta + n > rawsize or off + n > len(data):
                    return None
                return data[off : off + n]
        return None

    return read


LABEL_RX = re.compile(r'^(\S.*?):\s*$')
INSN_ONLY_RX = re.compile(r'^[0-9A-F]{8}:')
INSN_RX = re.compile(r'^\s+([0-9A-F]+):\s+((?:[0-9A-F]{2}\s?)+)')


def functions_from_dump(path, *, source_text=None):
    out = []
    cur = None
    if source_text is None:
        source_text = Path(path).read_text(encoding='utf-8', errors='replace')
    for line in source_text.splitlines():
        stripped = line.lstrip()
        is_insn = bool(INSN_ONLY_RX.match(stripped))
        m = None if is_insn else LABEL_RX.match(line)
        if m:
            if cur and cur[1]:
                out.append((cur[0], cur[1]))
            cur = [m.group(1), []]
            continue
        if cur is None:
            continue
        mi = INSN_RX.match(line)
        if not mi:
            continue
        addr = int(mi.group(1), 16)
        bs = bytearray()
        for tok in mi.group(2).split():
            if re.fullmatch(r'[0-9A-F]{2}', tok):
                bs.append(int(tok, 16))
            else:
                break
        cur[1].append((addr, bytes(bs)))
    if cur and cur[1]:
        out.append((cur[0], cur[1]))
    return out


def contiguous(chunks):
    if not chunks:
        return None
    chunks = sorted(chunks)
    blob = bytearray()
    expect = chunks[0][0]
    for addr, bs in chunks:
        if addr != expect:
            return None
        blob += bs
        expect = addr + len(bs)
    return bytes(blob)


def equal_modulo_relocations(cand, ref):
    """Absent relocation evidence, the compatibility API requires exact bytes.

    A pointer-shaped constant or an E8/E9 byte is not a relocation record.
    Discovery callers must request heuristic_candidate_match explicitly.
    """
    return cand == ref, 0


def heuristic_candidate_match(cand, ref):
    """Return an unverified discovery lead and the guessed masked byte count."""
    if len(cand) != len(ref):
        return False, 0
    mask = set()
    for k in range(len(cand) - 3):
        if cand[k : k + 4] == ref[k : k + 4]:
            continue
        v = struct.unpack_from('<I', ref, k)[0]
        if 0x400000 <= v < VA_HI:
            mask.update((k, k + 1, k + 2, k + 3))
            continue
        if k >= 1 and cand[k - 1] == ref[k - 1] and ref[k - 1] in (0xE8, 0xE9):
            mask.update((k, k + 1, k + 2, k + 3))
    for j in range(len(cand)):
        if cand[j] != ref[j] and j not in mask:
            return False, len(mask)
    return True, len(mask)


def normalize_coff_symbol(symbol):
    """Remove the x86 C calling-convention decoration from a COFF symbol."""
    symbol = symbol.strip()
    if symbol.startswith('@') and re.search(r'@\d+$', symbol):
        return symbol[1 : symbol.rfind('@')]
    if symbol.startswith('_') and re.search(r'@\d+$', symbol):
        return symbol[1 : symbol.rfind('@')]
    if symbol.startswith('_'):
        return symbol[1:]
    return symbol


def parse_dumpbin_relocations(text, section_index=3):
    """Read one DUMPBIN relocation section as (offset, type, symbol) tuples."""
    relocations = []
    current_section = None
    for line in text.splitlines():
        section = re.match(r'^\s*RELOCATIONS\s+#(\d+)', line)
        if section:
            current_section = int(section.group(1))
            continue
        if current_section != section_index:
            continue
        fields = line.split()
        if (len(fields) >= 5
                and re.fullmatch(r'[0-9A-Fa-f]{8}', fields[0])
                and re.fullmatch(r'[A-Za-z0-9_]+', fields[1])):
            # Layout: OFFSET TYPE APPLIED-TO INDEX NAME.  The symbol is every
            # field after the index, because DUMPBIN prints the undecorated
            # name followed by a kind annotation such as "(`string')".
            relocations.append((int(fields[0], 16), fields[1].upper(), ' '.join(fields[4:])))
    return relocations


def resolve_rel32_relocations(code, function_va, relocations, symbol_addresses):
    """Apply x86 REL32 call/jump fixups and return the reconstructed bytes.

    Relocation offsets point at the four-byte displacement field. Only direct
    CALL/JMP REL32 entries are accepted; unknown symbols and other relocation
    types fail closed so a masked comparison cannot be reported as exact.
    """
    patched = bytearray(code)
    seen = set()
    for offset, relocation_type, symbol in relocations:
        if relocation_type.upper() not in ('REL32', 'IMAGE_REL_I386_REL32'):
            raise ValueError('unsupported relocation type: %s' % relocation_type)
        if offset in seen:
            raise ValueError('duplicate relocation offset: 0x%X' % offset)
        seen.add(offset)
        if offset < 1 or offset + 4 > len(patched):
            raise ValueError('REL32 offset outside function: 0x%X' % offset)
        if patched[offset - 1] not in (0xE8, 0xE9):
            raise ValueError('REL32 is not attached to CALL/JMP at 0x%X' % offset)
        name = normalize_coff_symbol(symbol)
        target = symbol_addresses.get(name)
        if isinstance(target, (set, list, tuple)):
            if len(target) != 1:
                raise ValueError('ambiguous COFF symbol: %s' % symbol)
            target = next(iter(target))
        if target is None:
            raise ValueError('unresolved COFF symbol: %s' % symbol)
        displacement = int(target) - (function_va + offset + 4)
        if not -0x80000000 <= displacement <= 0x7FFFFFFF:
            raise ValueError('REL32 target out of range: %s' % symbol)
        struct.pack_into('<i', patched, offset, displacement)
    return bytes(patched)


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('dis_dir', type=Path)
    parser.add_argument('inventory', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--exe', type=Path, default=Path(EXE_DEFAULT))
    parser.add_argument('--expected-sha256', default=EXE_SHA256)
    parser.add_argument('--heuristic-candidates', action='store_true')
    parser.add_argument('--quarantine-invalid-inventory', action='store_true',
                        help='Keep bad-hash rows as ambiguity competitors without crediting them')
    args = parser.parse_args(argv)
    dis_dir, inv_path, out_path = args.dis_dir, args.inventory, args.output
    data, secs = load_pe(args.exe)
    target_digest = hashlib.sha256(data).hexdigest()
    if target_digest != args.expected_sha256.lower():
        raise ValueError(f'reference SHA-256 mismatch: {target_digest}')
    if out_path.resolve() in {args.exe.resolve(), inv_path.resolve()}:
        raise ValueError('output must not overwrite the reference or inventory')
    read = va_reader(data, secs)

    by_size = collections.defaultdict(list)
    by_bytes = collections.defaultdict(list)
    seen = set()
    quarantined = set()
    with inv_path.open(encoding='utf-8') as stream:
        rows = csv.DictReader(stream, delimiter='\t')
        fields = rows.fieldnames or []
        required = {'start', 'size', 'name', 'sha256'}
        if not required.issubset(fields) or len(fields) != len(set(fields)):
            raise ValueError('inventory must have distinct columns for start, size, name and sha256')
        for row in rows:
            if None in row or any(not row.get(key) for key in required):
                raise ValueError('malformed inventory row')
            va, size = int(row['start'], 16), int(row['size'])
            ref = read(va, size)
            if va in seen or ref is None:
                raise ValueError(f'inventory range/hash is invalid at {va:#x}')
            if hashlib.sha256(ref).hexdigest() != row['sha256'].lower():
                if not args.quarantine_invalid_inventory:
                    raise ValueError(f'inventory range/hash is invalid at {va:#x}')
                quarantined.add(va)
            seen.add(va)
            by_size[size].append((va, row['name'], ref))
            by_bytes[ref].append((va, row['name'], 0))

    confirmed, ambiguous, scanned = [], 0, 0
    for fn in sorted(os.listdir(dis_dir)):
        if not fn.endswith('.txt'):
            continue
        tag = fn[:-4]
        dump_path = dis_dir / fn
        if dump_path.resolve() == out_path.resolve():
            raise ValueError('output must not overwrite a candidate disassembly')
        dump_data = dump_path.read_bytes()
        dump_digest = hashlib.sha256(dump_data).hexdigest()
        for name, chunks in functions_from_dump(
                dump_path, source_text=dump_data.decode('utf-8', errors='replace')):
            blob = contiguous(chunks)
            if blob is None or len(blob) < 16:
                continue
            scanned += 1
            hits = []
            pool = by_size.get(len(blob), ()) if args.heuristic_candidates else (
                (va, name, blob) for va, name, _ in by_bytes.get(blob, ()))
            for va, idb_name, ref in pool:
                if ref is None:
                    continue
                compare = heuristic_candidate_match if args.heuristic_candidates else equal_modulo_relocations
                ok, nmask = compare(blob, ref)
                if ok:
                    hits.append((va, idb_name, nmask))
            if len(hits) == 1 and hits[0][0] not in quarantined:
                ref = read(hits[0][0], len(blob))
                identical = blob == ref
                confirmed.append(
                    {
                        'object': tag,
                        'source_name': name,
                        'size': len(blob),
                        'va': hits[0][0],
                        'idb_name': hits[0][1],
                        'reloc_dwords': 0,
                        'masked_bytes': hits[0][2],
                        'match_kind': 'exact_bytes' if identical else 'heuristic_candidate',
                        'byte_identical': identical,
                        'candidate_sha256': hashlib.sha256(blob).hexdigest(),
                        'reference_sha256': hashlib.sha256(ref).hexdigest(),
                        'target_sha256': target_digest,
                        'disassembly_sha256': dump_digest,
                    }
                )
            elif len(hits) > 1:
                ambiguous += 1

    with out_path.open('w', encoding='utf-8') as stream:
        json.dump(confirmed, stream, indent=1)
        stream.write('\n')
    unique_exact = {c['va']: c['size'] for c in confirmed if c['byte_identical']}
    total = sum(unique_exact.values())
    print(f'candidates scanned                          : {scanned}')
    print(f'quarantined inventory rows (no credit)       : {len(quarantined)}')
    print(f'unique raw-byte-identical functions         : {len(unique_exact)}')
    print(f'unverified heuristic records                : {sum(not c["byte_identical"] for c in confirmed)}')
    print(f'ambiguous (more than one same-size match)   : {ambiguous}')
    print(f'confirmed code bytes                        : {total:,}')
    return 0


if __name__ == '__main__':
    try:
        raise SystemExit(main())
    except (OSError, ValueError, struct.error) as exc:
        print(f'error: {exc}', file=sys.stderr)
        raise SystemExit(2)
