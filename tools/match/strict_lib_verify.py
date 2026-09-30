#!/usr/bin/env python3
"""Verify SDK static-library code against the PE with every COFF relocation resolved.

The masked library sweep credits an object section when its bytes match except
for the DWORDs the linker patches.  This tool resolves those patch sites so the
agreement is literal byte equality.  Placement is a relocation-free anchor: a
window of the section that occurs in the image and is not a patch site, which
fixes the section's VA.  Relocation targets are then resolved in two passes:
first every placed member publishes the VAs of the symbols it defines, then a
second pass resolves each patch site through that global map, falling back to
the IDA name map for symbols outside the archive.
"""
import argparse
import collections
import gzip
import hashlib
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import definitive_match as D
import lib_vs_exe as L

REL32 = 0x0014   # IMAGE_REL_I386_REL32
DIR32 = 0x0006   # IMAGE_REL_I386_DIR32


def parse_object(lib, off, size):
    machine, nsec, _ts, symptr, nsym, optsize, _chars = struct.unpack_from('<HHIIIHH', lib, off)
    if machine not in (0x14C, 0x8664):
        return None
    strtab = off + symptr + nsym * 18
    # Keep one entry per COFF symbol slot, auxiliary records included:
    # relocation symbol indices are raw slot numbers, so skipping aux records
    # would misalign every reference.  Auxiliary slots carry no name of their own.
    syms = []
    for i in range(nsym):
        so = off + symptr + i * 18
        if so + 18 > len(lib):
            break
        raw, val, sec, _typ, _stor, _naux = struct.unpack_from('<8sIhHBB', lib, so)
        if raw[:4] == b'\x00\x00\x00\x00' and raw[:8] != b'\x00' * 8:
            noff = struct.unpack_from('<I', raw, 4)[0] + strtab
            end = lib.find(b'\x00', noff)
            nm = lib[noff:end].decode('latin-1', 'replace')
        elif raw[:4] == b'\x00\x00\x00\x00':
            nm = ''
        else:
            nm = raw.rstrip(b'\x00').decode('latin-1', 'replace')
        syms.append({'name': nm, 'value': val, 'sec': sec})
    secs = []
    for idx in range(1, nsec + 1):
        o = off + 20 + optsize + (idx - 1) * 40
        if o + 40 > off + size:
            break
        rn = lib[o:o + 8]
        if rn.startswith(b'/'):
            digits = rn[1:].rstrip(b'\x00') or b'0'
            noff = strtab + int(digits)
            end = lib.find(b'\x00', noff)
            name = lib[noff:end].decode('latin-1', 'replace')
        else:
            name = rn.rstrip(b'\x00').decode('latin-1', 'replace')
        _vs, _va, rawsize, rawptr = struct.unpack_from('<IIII', lib, o + 8)
        relocptr, _ln, nreloc, _nr = struct.unpack_from('<IIHH', lib, o + 24)
        text = lib[off + rawptr: off + rawptr + rawsize] if rawptr else b''
        relocs = []
        for r in range(nreloc):
            ro = off + relocptr + r * 10
            if ro + 10 > len(lib):
                break
            rva, symidx, rtype = struct.unpack_from('<IIH', lib, ro)
            relocs.append((rva, symidx, rtype))
        secs.append({'index': idx, 'name': name, 'text': text, 'relocs': relocs})
    return {'symbols': syms, 'sections': secs}


class AnchorIndex:
    """Map 16-byte windows of the image to their file offsets.

    Placement needs to answer "where does this section live?" for thousands of
    objects; scanning the image with `bytes.find` per candidate made the global
    pass quadratic in practice.  One pass over the image builds the index.
    """
    WINDOW = 16

    # Anchoring does not need every byte offset: entry points and section
    # starts are 4-byte aligned, so indexing in steps of 4 finds the same
    # placement while keeping the index a quarter the size.
    STRIDE = 4

    def __init__(self, data, secs):
        self.image = data
        self.secs = secs
        self.index = collections.defaultdict(list)
        for _nm, _vaddr, _vsize, rawptr, rawsize in secs:
            end = rawptr + rawsize
            for off in range(rawptr, end - self.WINDOW + 1, self.STRIDE):
                self.index[data[off:off + self.WINDOW]].append(off)

    def locate_wildcard(self, text, relocs):
        """Place a section whose relocations cover most of its bytes.

        A COMDAT inline body can be almost entirely patch sites, so no
        relocation-free window exists.  Each relocation patches a four-byte
        field, so all four bytes at every relocation offset are wildcards; the
        remaining literal bytes must then occur exactly once in the image,
        which is what makes the placement evidence rather than a guess.
        """
        mask = set()
        for rva, _sym, _type in relocs:
            for k in range(4):
                mask.add(rva + k)
        keep = [i for i in range(len(text)) if i not in mask]
        if len(keep) < 10:
            return None
        runs = []
        cur = []
        for i in range(len(text)):
            if i in mask:
                if cur:
                    runs.append(cur)
                    cur = []
            else:
                cur.append(i)
        if cur:
            runs.append(cur)
        if not runs:
            return None
        anchor = max(runs, key=len)
        if len(anchor) < 8:
            return None
        pattern = bytes(text[i] for i in anchor)
        first = anchor[0]
        hits = set()
        start = 0
        while True:
            j = self.image.find(pattern, start)
            if j < 0:
                break
            base = j - first
            if (base >= 0 and base + len(text) <= len(self.image)
                    and all(self.image[base + i] == text[i] for i in keep)):
                for _nm, vaddr, vsize, rawptr, rawsize in self.secs:
                    if rawptr <= base < rawptr + rawsize:
                        hits.add(vaddr + (base - rawptr))
                        break
                if len(hits) > 1:
                    return None
            start = j + 1
        return next(iter(hits)) if len(hits) == 1 else None

    def locate_bytes(self, blob):
        """Return the VA of an exact byte run, or None when it is not unique.

        Called after relocations are resolved, so the section needs no
        relocation-free window: the patched bytes are literal image content.
        """
        if len(blob) < self.WINDOW:
            return None
        hits = set()
        for start in range(0, len(blob) - self.WINDOW + 1, self.STRIDE):
            for off in self.index.get(blob[start:start + self.WINDOW], ()):
                j = off - start
                if j < 0 or j + len(blob) > len(self.image):
                    continue
                if self.image[j:j + len(blob)] != blob:
                    continue
                for _nm, vaddr, vsize, rawptr, rawsize in self.secs:
                    if rawptr <= j < rawptr + rawsize:
                        hits.add(vaddr + (j - rawptr))
                        break
            if len(hits) > 1:
                return None
        return next(iter(hits)) if len(hits) == 1 else None

    def locate(self, text, relset):
        """Anchor the section, preferring the longest relocation-free window.

        The 16-byte index only narrows candidates.  A candidate is accepted
        after checking the whole window agrees, so a short match elsewhere in
        the image cannot misplace the section.
        """
        for win in (96, 64, 48, 32, 24, self.WINDOW):
            if win > len(text):
                continue
            step = max(1, win // 4)
            for start in range(0, max(1, len(text) - win + 1), step):
                if any((start + k) in relset for k in range(win)):
                    continue
                for off in self.index.get(text[start:start + self.WINDOW], ())[:8]:
                    j = off - start
                    if j < 0 or j + win > len(self.image):
                        continue
                    if self.image[j:j + win] != text[start:start + win]:
                        continue
                    for _nm, vaddr, vsize, rawptr, rawsize in self.secs:
                        if rawptr <= j < rawptr + rawsize:
                            return start, vaddr + (j - rawptr) - start
        return None


def image_bytes_at(data, secs, va, n):
    for _nm, vaddr, vsize, rawptr, rawsize in secs:
        if vaddr <= va < vaddr + max(vsize, rawsize):
            d = va - vaddr
            if d + n > rawsize:
                return None
            return data[rawptr + d: rawptr + d + n]
    return None


def collect_placements(lib_paths, data, secs, symbol_va, names, symbol_va_local=None, anchor=None):
    """Place every member of every library and publish the symbols it defines.

    A global symbol map is required because an object routinely calls into a
    different archive (BulletCollision into LinearMath, lua into the CRT).
    """
    if symbol_va_local is None:
        symbol_va_local = collections.defaultdict(set)
    if anchor is None:
        anchor = AnchorIndex(data, secs)
    placed = []
    for lib_path in lib_paths:
        lib = Path(lib_path).read_bytes()
        for name, off, size in L.parse_archive(lib):
            obj = parse_object(lib, off, size)
            if obj is None:
                continue
            # Every section of the object is placed, not just .text: a body
            # refers to its own .rdata constants and to local labels, and both
            # are section-relative symbols.
            obj_sec_va = {}
            for sec in obj['sections']:
                if not sec['text']:
                    continue
                relset = {r[0] for r in sec['relocs']}
                p = anchor.locate(sec['text'], relset)
                if p is None:
                    continue
                start, sec_va = p
                obj_sec_va[sec['index']] = sec_va
                obj['sec_va'] = obj_sec_va
                if sec['name'].startswith('.text') and len(sec['text']) >= 16:
                    placed.append((Path(lib_path).name, obj, sec, start, sec_va))
                for s in obj['symbols']:
                    if s['sec'] == sec['index']:
                        symbol_va[s['name']].add(sec_va + s['value'])
                        symbol_va_local[(Path(lib_path).name, s['name'])].add(sec_va + s['value'])
    return placed


def patch_section(sec, obj, sec_va, symbol_va, symbol_va_local, names, lib_name):
    """Apply every relocation of a section and return the patched bytes.

    Returns None when a target cannot be resolved.  This is the single place
    that decides what a relocation means, so both the placement and the final
    comparison use the same resolution order.
    """
    patched = bytearray(sec['text'])
    for rva, symidx, rtype in sec['relocs']:
        if rva + 4 > len(patched) or symidx >= len(obj['symbols']):
            return None
        s = obj['symbols'][symidx]
        target = None
        same_lib = symbol_va_local.get((lib_name, s['name'])) if symbol_va_local else None
        if same_lib and len(same_lib) == 1:
            target = next(iter(same_lib))
        if target is None:
            local = symbol_va.get(s['name'])
            if local and len(local) == 1:
                target = next(iter(local))
        if target is None:
            ext = names.get(s['name']) or names.get('_' + s['name'])
            if ext and len(ext) == 1:
                target = next(iter(ext))
            elif s['sec'] > 0 and obj.get('sec_va', {}).get(s['sec']) is not None:
                target = obj['sec_va'][s['sec']] + s['value']
        if target is None:
            return None
        if rtype == REL32:
            struct.pack_into('<i', patched, rva, target - (sec_va + rva + 4))
        elif rtype == DIR32:
            struct.pack_into('<I', patched, rva, target)
        else:
            return None
    return bytes(patched)


def anchor_resolved(lib_paths, data, secs, symbol_va, names, symbol_va_local, anchor, placed):
    """Second pass: place sections that had no relocation-free window.

    A COMDAT body is mostly patch sites, so it cannot anchor before its
    relocations are known.  Once most of the library is placed, the symbols it
    references are known, so the section is patched and matched literally.
    """
    done = set()
    added = []
    for rounds in range(3):
        grew = False
        for lib_path in lib_paths:
            lib_name = Path(lib_path).name
            lib = Path(lib_path).read_bytes()
            for name, off, size in L.parse_archive(lib):
                key = (lib_name, off)
                if key in done:
                    continue
                obj = parse_object(lib, off, size)
                if obj is None:
                    done.add(key)
                    continue
                changed = False
                for sec in obj['sections']:
                    if sec['index'] in obj.get('sec_va', {}):
                        continue
                    if not sec['text'] or sec['name'].startswith('.debug'):
                        continue
                    # A relocation-free window is preferred; when the patch
                    # sites cover the section, the wildcard match that ignores
                    # exactly those four-byte fields is the next best evidence.
                    relset = {r[0] for r in sec['relocs']}
                    placed_at = anchor.locate(sec['text'], relset)
                    if placed_at is not None:
                        va = placed_at[1]
                    else:
                        va = anchor.locate_wildcard(sec['text'], sec['relocs'])
                    if va is None:
                        continue
                    obj.setdefault('sec_va', {})[sec['index']] = va
                    changed = True
                    if sec['name'].startswith('.text') and len(sec['text']) >= 16:
                        added.append((lib_name, obj, sec, 0, va))
                    for s in obj['symbols']:
                        if s['sec'] == sec['index']:
                            symbol_va[s['name']].add(va + s['value'])
                            symbol_va_local[(lib_name, s['name'])].add(va + s['value'])
                if changed:
                    grew = True
                done.add(key)
        if not grew:
            break
    placed.extend(added)
    return len(added)


def verify(paths, data, secs, names, symbol_va, placed, symbol_va_local=None):
    proven = {}
    stats = collections.Counter()
    for name, obj, sec, start, sec_va in placed:
        lib_name = name
        text = sec['text']
        patched = bytearray(text)
        ok = True
        for rva, symidx, rtype in sec['relocs']:
            if rva + 4 > len(patched) or symidx >= len(obj['symbols']):
                ok = False
                break
            s = obj['symbols'][symidx]
            target = None
            # A release and a debug archive both define the same symbols at
            # different addresses, so the global map alone is ambiguous.  The
            # own library is authoritative; other archives only fill gaps.
            same_lib = symbol_va_local.get((lib_name, s['name'])) if symbol_va_local else None
            if same_lib and len(same_lib) == 1:
                target = next(iter(same_lib))
            if target is None:
                local = symbol_va.get(s['name'])
                if local and len(local) == 1:
                    target = next(iter(local))
            if target is None:
                ext = names.get(s['name']) or names.get('_' + s['name'])
                if ext and len(ext) == 1:
                    target = next(iter(ext))
                elif s['sec'] > 0 and obj.get('sec_va', {}).get(s['sec']) is not None:
                    # Section-relative symbol (a local label such as $LN5, or an
                    # .rdata constant such as __real@3f800000) resolves against
                    # the VA where that section was placed.
                    target = obj['sec_va'][s['sec']] + s['value']
            if target is None:
                ok = False
                break
            if rtype == REL32:
                struct.pack_into('<i', patched, rva, target - (sec_va + rva + 4))
            elif rtype == DIR32:
                struct.pack_into('<I', patched, rva, target)
            else:
                ok = False
                break
        if not ok:
            stats['unresolved_reloc'] += 1
            continue
        ref = image_bytes_at(data, secs, sec_va, len(text))
        if ref is None or len(ref) != len(text):
            stats['not_in_section'] += 1
            continue
        if bytes(patched) == ref:
            stats['exact_sections'] += 1
            proven[sec_va] = {'size': len(text), 'member': name, 'section': sec['name'], 'library': lib_name,
                              'byte_sha256': hashlib.sha256(ref).hexdigest()}
        else:
            diff = sum(1 for a, b in zip(patched, ref) if a != b)
            stats['byte_mismatch'] += 1
            if diff <= 8:
                stats['byte_mismatch_small'] += 1
    return proven, stats


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('libraries', nargs='+')
    ap.add_argument('--exe', default=D.EXE_DEFAULT)
    ap.add_argument('--output')
    ap.add_argument('--names', default='recon/ffx/analysis_map/names.tsv.gz')
    args = ap.parse_args()
    data, secs = D.load_pe(args.exe)
    names = {}
    with gzip.open(args.names, 'rt') as f:
        f.readline()
        for line in f:
            p = line.split('\t')
            if len(p) < 2:
                continue
            try:
                va = int(p[0], 16)
            except ValueError:
                continue
            names.setdefault(p[1], set()).add(va)
    # Every library is placed before any relocation is resolved, so a symbol
    # defined in one archive resolves when another archive references it.
    symbol_va = collections.defaultdict(set)
    symbol_va_local = collections.defaultdict(set)
    anchor = AnchorIndex(data, secs)
    placed = collect_placements(args.libraries, data, secs, symbol_va, names, symbol_va_local, anchor)
    by_lib = collections.Counter(name for name, *_ in placed)
    print('placed sections', len(placed), 'symbols', len(symbol_va))
    extra = anchor_resolved(args.libraries, data, secs, symbol_va, names, symbol_va_local, anchor, placed)
    print('resolved-anchor extra sections', extra)
    proven, stats = verify(args.libraries, data, secs, names, symbol_va, placed, symbol_va_local)
    print('overall', dict(stats), 'exact', len(proven))
    out = {}
    for lib in args.libraries:
        name = Path(lib).name
        rows = [{'va': va, **rec} for va, rec in sorted(proven.items()) if rec.get('library') == name]
        out[name] = {'sections': rows}
        print(' ', name, 'exact', len(rows))
    if args.output:
        Path(args.output).write_text(json.dumps(out, indent=1) + '\n')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
