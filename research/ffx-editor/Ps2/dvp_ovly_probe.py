#!/usr/bin/env python3
"""dvp_ovly_probe.py — decode `.DVP.ovlytab` + `.DVP.overlay.*` in SLPS_250.88.

Mission (Jarvis-DVPOVLY research lane, wave-17 2026-09-18): crack the SN
linker DVP overlay table of the FFX International EE executable. Builds on
`slps_mips_probe.py` (same repo dir) — reuses its ELF parser, xref engine and
capstone window disasm, and adds the ovlytab-specific decoders:

WHAT IT DOES
  - parses `.DVP.ovlytab` records ({name_ptr, target, f3} × 12 bytes) and
    resolves each record against its `.DVP.overlay.<name>` section header
    (sh_addr / sh_offset / sh_size / sh_flags) — the section header is the
    AUTHORITATIVE size field (the ovlytab itself has no size word)
  - decodes the section-name grammar `.DVP.overlay..{vma}.{ck}.{mod}.{reg}`
    (ck = linker checksum/build-id, mod = module id, reg = overlay region)
  - maps each record's `target` into the ELF layout (which loaded section it
    lands in) and dumps the payload bytes actually present at that target
    (for .vutext targets the union image bodies ARE in the file)
  - classifies payload content: all-zero / fill-byte / VU-microcode /
    EE-MIPS-code / data, via byte-histogram + a small VU-pair heuristic
  - scans ALL of .text for `lui+op` materialization of any vaddr inside an
    overlay target window (who touches each overlay at runtime)
  - optional capstone disasm windows around the discovered sites

USAGE
  python3 dvp_ovly_probe.py --tab [--csv out.csv]
  python3 dvp_ovly_probe.py --payloads [--csv out.csv]
  python3 dvp_ovly_probe.py --sites [--csv out.csv]
  python3 dvp_ovly_probe.py --all --csv-dir docs/reverse/data/wave15

Exit codes: 0 ok, 2 usage error, 3 capstone missing (only for --disasm).
"""

import argparse
import csv
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from slps_mips_probe import (ElfImage, u32, code_xrefs, jump_xrefs,  # noqa: E402
                             _hi_lo, OP_LUI, I_DEST_OPS, MEM_OPS,   # noqa: E402
                             LO_MATERIALIZE_OPS, XREF_LOOKAHEAD)    # noqa: E402

FILL_BYTES = (0x00, 0x6E)   # 0x6e observed as the linker's pad fill (last stub)


# ── record decode ──────────────────────────────────────────────────────────

def parse_overlay_name(name):
    """`.DVP.overlay..{vma}.{ck}.{mod}.{reg}` -> dict of fields or None."""
    pfx = '.DVP.overlay..'
    if not name.startswith(pfx):
        return None
    parts = name[len(pfx):].split('.')
    if len(parts) != 4:
        return None
    vma, ck, mod, reg = parts
    try:
        return {'vma': vma, 'ck': int(ck), 'mod': int(mod), 'reg': int(reg)}
    except ValueError:
        return None


def ovlytab_records(img):
    """Join `.DVP.ovlytab` records with their `.DVP.overlay.*` shdr.

    Record layout (verified against shdrs 2026-09-18):
        +0  name_ptr  vaddr into .DVP.ovlystrtab (bookkeeping vaddr 0x21370f0)
        +4  target    runtime destination vaddr for the overlay body
        +8  f3        per-region field — VU progmem offset (unknvma) or 0
    The 12-byte record has NO size field; size comes from the section header.
    """
    tab = img.section_named('.DVP.ovlytab')
    strtab = img.section_named('.DVP.ovlystrtab')
    if tab is None or strtab is None:
        return []
    rows = []
    for i in range(tab.size // 12):
        name_ptr, target, f3 = struct.unpack_from(
            '<3I', img.blob, tab.off + i * 12)
        off = strtab.off + (name_ptr - strtab.addr)
        name = '<bad ptr>'
        if strtab.off <= off < strtab.off + strtab.size:
            end = img.blob.index(b'\0', off)
            name = img.blob[off:end].decode('ascii', 'replace')
        sec = img.section_named(name) if name.startswith('.DVP') else None
        meta = parse_overlay_name(name) or {}
        home = img.section_at_vaddr(target)
        rows.append({
            'idx': i, 'name': name, 'name_ptr': name_ptr,
            'target': target, 'f3': f3,
            'vma_tag': meta.get('vma', '?'), 'ck': meta.get('ck', -1),
            'mod': meta.get('mod', -1), 'reg': meta.get('reg', -1),
            'sec_off': sec.off if sec else -1,
            'sec_size': sec.size if sec else 0,
            'sec_flags': sec.flags if sec else 0,
            'target_sec': home.name if home else '(unmapped)',
        })
    return rows


# ── payload classification ─────────────────────────────────────────────────

def mpg_prefix(img, rec):
    """Look for the VIF `MPG` command word that precedes a .vutext body.

    Decoded 2026-09-18: each union-image body is preceded by a VIF packet
    word `0x4a{num:02x}{addr_qw:04x}` (code 0x4a = MPG, bits[23:16] = count
    of 64-bit instructions with 0 meaning 256, bits[15:0] = VU instr-memory
    load offset in quadwords).  The proven invariant is
    ``addr_qw * 8 == rec.f3`` for every resident VU record.
    The MPG word sits at target-4 (one per segment; an 8-byte pad may
    separate it from the previous body).
    """
    tgt, f3, size = rec['target'], rec['f3'], rec['sec_size']
    for back in (4, 8):
        off = img.vaddr_to_off(tgt - back)
        if off is None:
            continue
        w = u32(img.blob, off)
        if (w >> 24) == 0x4A:
            num = (w >> 16) & 0xFF or 256
            addr_qw = w & 0xFFFF
            ok = (addr_qw * 8 == f3) and (num == size // 8)
            return {'at': tgt - back, 'word': w, 'num': num,
                    'addr_qw': addr_qw, 'match': ok}
    return None


def classify_payload(img, rec):
    """Return (kind, detail, file_bytes) for the overlay body.

    For .vutext targets the union image bytes are in the ELF; for .bss
    targets there is no file content (runtime-loaded). The .DVP.overlay.*
    stub bytes are checked too (expected filler).
    """
    tgt, size = rec['target'], rec['sec_size']
    home = img.section_at_vaddr(tgt)
    foff = img.vaddr_to_off(tgt)
    data = img.blob[foff:foff + size] if foff is not None else b''
    if not data:
        return 'no-file-image', 'target has no file bytes (bss/unmapped)', b''
    nz = sum(1 for c in data if c)
    if nz == 0:
        return 'zero-fill', 'all 0x00', data
    uniq = set(data)
    if len(uniq) == 1:
        return 'fill', f'all 0x{data[0]:02x}', data
    # VU microprogram: 64-bit instr pairs (lower|upper).  Metrics that
    # distinguish it from EE MIPS code / data:
    #   * upper-pipe NOP ratio  (upper word == 0x000002ff is VU NOP)
    #   * E-bit words           (upper word bit30 = end-of-program marker)
    #   * a matching VIF MPG command word immediately before the body
    pairs = size // 8
    up_nop = sum(1 for i in range(0, size - 7, 8)
                 if u32(data, i + 4) == 0x000002FF)
    e_bit = sum(1 for i in range(0, size - 7, 8)
                if u32(data, i + 4) & 0x40000000)
    lo_80 = sum(1 for i in range(0, size - 7, 8)
                if (u32(data, i) >> 24) == 0x80)
    ascii_ratio = sum(1 for c in data if 0x20 <= c < 0x7F) / len(data)
    mpg = mpg_prefix(img, rec)
    if mpg is not None or up_nop > pairs * 0.10:
        tag = f'MPG@{mpg["at"]:#x} num={mpg["num"]} addr_qw={mpg["addr_qw"]:#x}' \
              f'{" MATCH" if mpg["match"] else " MISMATCH"}' if mpg else 'no MPG'
        return 'vu-microcode', \
            f'{tag} pairs={pairs} upNOP={up_nop} E={e_bit} ' \
            f'lo80={lo_80} ascii={ascii_ratio:.2f}', data
    words = [u32(data, i) for i in range(0, len(data) - 3, 4)]
    zero_words = sum(1 for w in words if w == 0)
    if ascii_ratio > 0.6:
        return 'text/data', f'ascii={ascii_ratio:.2f}', data
    return 'code/data', \
        f'nz={nz}/{len(data)} zerowords={zero_words} ascii={ascii_ratio:.2f}', \
        data


def stub_fill_check(img, rec):
    """What the `.DVP.overlay.*` section file bytes actually contain."""
    off, size = rec['sec_off'], rec['sec_size']
    if off < 0 or size == 0:
        return '-'
    d = img.blob[off:off + size]
    nz = sum(1 for c in d if c)
    if nz == 0:
        return 'all-0x00'
    if len(set(d)) == 1:
        return f'all-0x{d[0]:02x}'
    return f'nonzero={nz}/{size}'


# ── runtime access sites ───────────────────────────────────────────────────

def find_region_sites(img, lo, hi):
    """Every .text lui+op site materializing a vaddr in [lo,hi).

    Generalizes slps_mips_probe.code_xrefs to a range: scan all `lui`
    instructions whose imm could be %hi(addr) or raw-hi(addr) for any addr
    in the window; confirm by pairing the %lo.
    """
    text = img.section_named('.text')
    if text is None:
        return []
    data = img.blob[text.off:text.off + text.size]
    n = text.size // 4
    hits = []
    # lui values that can cover the window: hi = (v+0x8000)>>16 or v>>16
    his = set()
    for v in (lo, hi - 1):
        his.add(((v + 0x8000) >> 16) & 0xFFFF)
        his.add((v >> 16) & 0xFFFF)
    for i in range(n):
        w = u32(data, i * 4)
        if w >> 26 != OP_LUI or (w & 0xFFFF) not in his:
            continue
        imm, rt = w & 0xFFFF, (w >> 16) & 0x1F
        for k in range(1, XREF_LOOKAHEAD + 1):
            j = i + k
            if j >= n:
                break
            w2 = u32(data, j * 4)
            op2, rs2, rt2 = w2 >> 26, (w2 >> 21) & 0x1F, (w2 >> 16) & 0x1F
            rd2, imm2 = (w2 >> 11) & 0x1F, w2 & 0xFFFF
            if rs2 == rt and op2 in LO_MATERIALIZE_OPS:
                # reconstruct the address as the code computes it
                if op2 in (0x09, 0x19, 0x08, 0x18):       # addiu family
                    lo_s = imm2 - 0x10000 if imm2 & 0x8000 else imm2
                    addr = (imm << 16) + lo_s
                else:                                    # ori/andi/xori
                    addr = (imm << 16) | imm2
                if lo <= addr < hi:
                    hits.append({'site': text.addr + i * 4,
                                 'pair': text.addr + j * 4,
                                 'addr': addr})
                break
            if rs2 == rt and op2 in MEM_OPS:
                lo_s = imm2 - 0x10000 if imm2 & 0x8000 else imm2
                addr = (imm << 16) + lo_s
                if lo <= addr < hi:
                    hits.append({'site': text.addr + i * 4,
                                 'pair': text.addr + j * 4,
                                 'addr': addr})
                # keep scanning — base reg may hit several members
            if op2 in I_DEST_OPS and rt2 == rt:
                break
            if op2 == 0 and rd2 == rt:
                break
    return hits


# ── reporting ──────────────────────────────────────────────────────────────

def _write_csv(path, fields, rows):
    os.makedirs(os.path.dirname(os.path.abspath(path)) or '.', exist_ok=True)
    with open(path, 'w', newline='') as f:
        w = csv.writer(f)
        w.writerow(fields)
        w.writerows(rows)
    print(f'wrote {len(rows)} rows -> {path}')


def main(argv=None):
    ap = argparse.ArgumentParser(description='SLPS_250.88 DVP overlay probe')
    ap.add_argument('--elf',
                    default='/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/'
                            'FFXINTERNATIONAL/unipyx/SLPS_250.88')
    ap.add_argument('--tab', action='store_true')
    ap.add_argument('--payloads', action='store_true')
    ap.add_argument('--sites', action='store_true')
    ap.add_argument('--all', action='store_true')
    ap.add_argument('--csv-dir', metavar='DIR')
    args = ap.parse_args(argv)

    img = ElfImage(args.elf)
    recs = ovlytab_records(img)
    print(f'# {args.elf}')
    print(f'# .DVP.ovlytab: {len(recs)} records')

    if args.all:
        args.tab = args.payloads = args.sites = True

    if args.tab:
        rows = []
        for r in recs:
            print(f"[{r['idx']}] {r['name']}")
            print(f"     target={r['target']:#010x} f3={r['f3']:#x} "
                  f"vma={r['vma_tag']} ck={r['ck']:#x} mod={r['mod']} "
                  f"reg={r['reg']}")
            print(f"     shdr off={r['sec_off']:#x} size={r['sec_size']:#x} "
                  f"flags={r['sec_flags']:#x} target-in={r['target_sec']} "
                  f"stub={stub_fill_check(img, r)}")
            rows.append((r['idx'], r['name'], f"{r['target']:#x}",
                         f"{r['f3']:#x}", r['vma_tag'], f"{r['ck']:#x}",
                         r['mod'], r['reg'], f"{r['sec_off']:#x}",
                         f"{r['sec_size']:#x}", f"{r['sec_flags']:#x}",
                         r['target_sec'], stub_fill_check(img, r)))
        if args.csv_dir:
            _write_csv(os.path.join(args.csv_dir, 'dvp_ovlytab.csv'),
                       ['idx', 'name', 'target', 'f3', 'vma_tag', 'cksum',
                        'module_id', 'region', 'sec_off', 'sec_size',
                        'sec_flags', 'target_section', 'stub_fill'], rows)

    if args.payloads:
        rows = []
        for r in recs:
            kind, detail, data = classify_payload(img, r)
            print(f"[{r['idx']}] mod={r['mod']} target={r['target']:#x} "
                  f"size={r['sec_size']:#x} kind={kind} ({detail})")
            if data and kind not in ('zero-fill', 'fill', 'no-file-image'):
                print('     head:', data[:32].hex())
                print('     tail:', data[-32:].hex())
            rows.append((r['idx'], r['mod'], r['reg'], f"{r['target']:#x}",
                         f"{r['sec_size']:#x}", r['target_sec'], kind, detail))
        if args.csv_dir:
            _write_csv(os.path.join(args.csv_dir, 'dvp_ovly_payloads.csv'),
                       ['idx', 'module_id', 'region', 'target', 'size',
                        'target_section', 'kind', 'detail'], rows)

    if args.sites:
        rows = []
        for r in recs:
            lo, hi = r['target'], r['target'] + max(r['sec_size'], 4)
            for h in find_region_sites(img, lo, hi):
                print(f"  mod={r['mod']} target={r['target']:#x} "
                      f"site={h['site']:#x} pair={h['pair']:#x} "
                      f"addr={h['addr']:#x}")
                rows.append((r['idx'], r['mod'], f"{r['target']:#x}",
                             f"{h['addr']:#x}", f"{h['site']:#x}",
                             f"{h['pair']:#x}"))
        if args.csv_dir:
            _write_csv(os.path.join(args.csv_dir, 'dvp_ovly_sites.csv'),
                       ['idx', 'module_id', 'target', 'ref_addr',
                        'site', 'pair'], rows)
    return 0


if __name__ == '__main__':
    sys.exit(main())
