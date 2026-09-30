#!/usr/bin/env python3
"""ppp_dll_census.py — authoritative census of FFX PC magic DLLs (K-F77).

Counts/classifies every ``magic_*.dll`` in a directory and reconciles the
historical counts floating around the docs:

  * 466  = "PPP root" family claim (FFX_MAGIC_DLL_PPP_EGOVM_COMPLETE_2026-08-19
           §5.1: files with NEITHER ``EgoBs2`` NOR ``WD3\\x01`` markers).
  * 581  = vanilla numbered set (overlay CSV snapshot 2026-06-02).
  * 583  = reconstructed corpus F:\\ffx-reconstructed\\extras\\magicFiles\\FFX
           (581 numbered + 2 mut fixtures).
  * 587  = legacy atlas/classification (581 + 6 clone DLLs 0714-0719).
  * 589  = current Steam install dir (587 + research copies 0720/0721).
  * 591  = RT0 ROUNDTRIP_ALL (589 Steam + 2 mut fixtures).

Per-DLL fields written to a TSV:
  name, size, sha256, first16 hex, has_EgoBs2, ego_off, has_SeSep, sesep_off,
  has_WD3, wd3_off, ppp_name_count, root_found (MagicDllRoot.FindRoots port),
  family signature bucket.

Usage:
  python3 research_tools/QA/ppp_dll_census.py <dir> [<dir>...] --out <prefix>
      writes <prefix>_<dirtag>.tsv per dir + <prefix>_summary.txt
"""
from __future__ import annotations

import hashlib
import re
import struct
import sys
from pathlib import Path

MARKER_EGO = b"EgoBs2"
MARKER_SESEP = b"SeSep"
MARKER_WD3 = b"WD3\x01"
PPP_NAME_RE = re.compile(rb"ppp[A-Za-z0-9_]{2,}")


# ---------------------------------------------------------------------------
# Port of FFXProjectEditor/FfxLib/MagicDll/MagicDllRoot.cs FindRoots
# (sanity checks only — full program/slot model not needed for coverage).
# ---------------------------------------------------------------------------

def _u16(b: bytes, o: int) -> int:
    return struct.unpack_from("<H", b, o)[0] if 0 <= o <= len(b) - 2 else 0


def _i16(b: bytes, o: int) -> int:
    return struct.unpack_from("<h", b, o)[0] if 0 <= o <= len(b) - 2 else 0


def _i32(b: bytes, o: int) -> int:
    return struct.unpack_from("<i", b, o)[0] if 0 <= o <= len(b) - 4 else 0


def _u32(b: bytes, o: int) -> int:
    return struct.unpack_from("<I", b, o)[0] if 0 <= o <= len(b) - 4 else 0


def _valid_counted_u32_table(data: bytes, section: int, section_size: int, rel: int) -> bool:
    if rel < 16 or rel + 4 > section_size:
        return False
    table = section + rel
    count = _i32(data, table)
    if count > 4096 or rel + 4 + 4 * count > section_size:
        return False
    for i in range(count):
        if _u32(data, table + 4 + 4 * i) >= section_size:
            return False
    return True


def _valid_aux_tables(data: bytes, root: int, c2: int, c3: int, c4: int,
                      t2: int, t3: int, t4: int) -> bool:
    resource_size = len(data) - root
    s2 = root + t2
    if s2 + 32 * c2 > len(data):
        return False
    for i in range(c2):
        e = s2 + 32 * i
        if (_u32(data, e + 20) >= resource_size or _u32(data, e + 24) >= resource_size
                or _u32(data, e + 28) >= resource_size):
            return False
    s3 = root + t3
    if s3 + 4 * c3 > len(data):
        return False
    for i in range(c3):
        if _u32(data, s3 + 4 * i) >= resource_size:
            return False
    s4 = root + t4
    if s4 + 8 * c4 > len(data):
        return False
    for i in range(c4):
        if _u32(data, s4 + 8 * i + 4) >= resource_size:
            return False
    return True


def _walk_section(data: bytes, root: int, section_rel: int) -> bool:
    section = root + section_rel
    if section + 56 > len(data):
        return False
    section_size = _i32(data, section)
    if section_size < 56:
        return False
    available = len(data) - section
    if section_size > available:
        section_size = available  # tolerant truncation (NOROOT_INVESTIGATION)
    if not _valid_counted_u32_table(data, section, section_size, _i32(data, section + 8)):
        return False
    if not _valid_counted_u32_table(data, section, section_size, _i32(data, section + 12)):
        return False
    program = section + 16
    visited: set[int] = set()
    found_slot = False
    while True:
        program_rel = program - section
        if program_rel in visited or program + 40 > section + section_size:
            return False
        visited.add(program_rel)
        slot_count = _i16(data, program + 38)
        if slot_count < 0 or slot_count > 256:
            return False
        if program + 40 + 16 * slot_count > section + section_size:
            return False
        for si in range(slot_count):
            slot_abs = program + 40 + 16 * si
            handler = _u32(data, slot_abs)
            primary_cb = _u32(data, slot_abs + 8)
            secondary_cb = _u32(data, slot_abs + 12)
            if handler > 255:
                return False
            if primary_cb >= section_size or secondary_cb >= section_size:
                return False
            found_slot = True
        nxt = _i32(data, program)
        if nxt == 0:
            return found_slot
        if nxt <= program_rel or nxt % 4 != 0:
            return False
        program = section + nxt


def _try_root(data: bytes, off: int) -> bool:
    if off < 0 or off + 32 > len(data):
        return False
    primary_count = _u16(data, off + 6)
    c2 = _u16(data, off + 8)
    c3 = _u16(data, off + 10)
    c4 = _u16(data, off + 12)
    if primary_count == 0 or primary_count > 64:
        return False
    if c2 > 256 or c3 > 256 or c4 > 256:
        return False
    tables = [_i32(data, off + 16), _i32(data, off + 20),
              _i32(data, off + 24), _i32(data, off + 28)]
    if any(t < 32 or t % 4 != 0 for t in tables):
        return False
    if any(tables[i] <= tables[i - 1] for i in range(1, 4)):
        return False
    if any(off + t >= len(data) for t in tables):
        return False
    primary_table = off + tables[0]
    if primary_table + 4 * primary_count > len(data):
        return False
    sections = []
    for i in range(primary_count):
        rel = _i32(data, primary_table + 4 * i)
        if rel < 32 or rel % 4 != 0:
            return False
        sections.append(rel)
    for srel in sections:
        if not _walk_section(data, off, srel):
            return False
    return _valid_aux_tables(data, off, c2, c3, c4, tables[1], tables[2], tables[3])


def find_roots(data: bytes) -> int:
    """Count of valid PPP resource roots in a .data blob (FindRoots port).

    Byte-level prefilter before the full structural check: primaryCount u16
    must be 1..64 (b[+6]!=0, b[+7]==0); counts 2/3/4 u16 <=256 (hi bytes 0 or
    low-valued); table offsets i32 >=32 -> top bytes zero at +19/+23/+27/+31.
    This keeps the scan O(n) with ~zero _try_root calls on random data.
    """
    n = 0
    mv = memoryview(data)
    end = len(data) - 32
    for off in range(0, end + 1, 4):
        if (mv[off + 7] != 0 or mv[off + 6] == 0 or mv[off + 6] > 64
                or mv[off + 9] > 1 or mv[off + 11] > 1 or mv[off + 13] > 1
                or mv[off + 19] != 0 or mv[off + 23] != 0
                or mv[off + 27] != 0 or mv[off + 31] != 0):
            continue
        if _try_root(data, off):
            n += 1
    return n


# ---------------------------------------------------------------------------
# Minimal PE reader — just enough to locate the .data section.
# ---------------------------------------------------------------------------

def pe_data_section(blob: bytes) -> tuple[int, int] | None:
    """Return (raw_offset, raw_size) of the .data section, or None."""
    if len(blob) < 0x40 or blob[:2] != b"MZ":
        return None
    pe_off = _u32(blob, 0x3C)
    if pe_off + 4 + 20 > len(blob) or blob[pe_off:pe_off + 4] != b"PE\x00\x00":
        return None
    nsec = _u16(blob, pe_off + 6)
    opt_size = _u16(blob, pe_off + 20)
    sec_off = pe_off + 24 + opt_size
    for i in range(nsec):
        sh = sec_off + 40 * i
        if sh + 40 > len(blob):
            return None
        name = blob[sh:sh + 8].rstrip(b"\x00")
        if name == b".data":
            raw_size = _u32(blob, sh + 16)
            raw_ptr = _u32(blob, sh + 20)
            return raw_ptr, raw_size
    return None


def census_file(path: Path) -> dict:
    blob = path.read_bytes()
    sha = hashlib.sha256(blob).hexdigest()
    ego = blob.find(MARKER_EGO)
    sesep = blob.find(MARKER_SESEP)
    wd3 = blob.find(MARKER_WD3)
    ppp_names = len(set(PPP_NAME_RE.findall(blob)))
    dsec = pe_data_section(blob)
    roots = -1
    if dsec is not None:
        raw_ptr, raw_size = dsec
        data = blob[raw_ptr:raw_ptr + raw_size]
        roots = find_roots(data)
    if ego >= 0:
        family = "EgoBs2"
    elif wd3 >= 0:
        family = "WD3-only"
    else:
        family = "PPP-root"
    return {
        "name": path.name,
        "size": len(blob),
        "sha256": sha,
        "first16": blob[:16].hex(),
        "ego_off": ego,
        "sesep_off": sesep,
        "wd3_off": wd3,
        "ppp_names": ppp_names,
        "roots": roots,
        "family": family,
    }


def main() -> int:
    out_prefix = "census"
    argv = sys.argv[1:]
    dirs_raw: list[str] = []
    i = 0
    while i < len(argv):
        if argv[i] == "--out" and i + 1 < len(argv):
            out_prefix = argv[i + 1]
            i += 2
            continue
        if argv[i].startswith("--"):
            i += 1
            continue
        dirs_raw.append(argv[i])
        i += 1
    dirs = [Path(a) for a in dirs_raw]
    if not dirs:
        print(__doc__)
        return 2
    summary_lines: list[str] = []
    for d in dirs:
        files = sorted(p for p in d.iterdir()
                       if p.is_file() and re.fullmatch(r"magic_.*\.dll", p.name))
        tag = re.sub(r"[^A-Za-z0-9]+", "_", str(d)).strip("_")[-40:]
        tsv = Path(f"{out_prefix}_{tag}.tsv")
        rows = [census_file(p) for p in files]
        with tsv.open("w", newline="") as fh:
            fh.write("name\tsize\tsha256\tfirst16\tego_off\tsesep_off\twd3_off"
                     "\tppp_names\troots\tfamily\n")
            for r in rows:
                fh.write("\t".join(str(r[k]) for k in
                                   ("name", "size", "sha256", "first16", "ego_off",
                                    "sesep_off", "wd3_off", "ppp_names", "roots",
                                    "family")) + "\n")
        n = len(rows)
        ego_n = sum(1 for r in rows if r["ego_off"] >= 0)
        sesep_n = sum(1 for r in rows if r["sesep_off"] >= 0)
        wd3_n = sum(1 for r in rows if r["wd3_off"] >= 0)
        both = sum(1 for r in rows if r["ego_off"] >= 0 and r["wd3_off"] >= 0)
        wd3_only = sum(1 for r in rows if r["ego_off"] < 0 and r["wd3_off"] >= 0)
        neither = sum(1 for r in rows if r["ego_off"] < 0 and r["wd3_off"] < 0)
        roots0 = sum(1 for r in rows if r["roots"] == 0)
        roots_pos = sum(1 for r in rows if r["roots"] > 0)
        line = (f"{d}\n  files={n} EgoBs2={ego_n} SeSep={sesep_n} WD3={wd3_n}"
                f" (EgoBs2+WD3 overlap={both}, WD3-only={wd3_only})"
                f" neither(PPP-root)={neither}\n  roots>0={roots_pos} roots=0={roots0}"
                f"\n  tsv={tsv}")
        print(line)
        summary_lines.append(line)
    Path(f"{out_prefix}_summary.txt").write_text("\n\n".join(summary_lines) + "\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
