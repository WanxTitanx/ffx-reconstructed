#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Section/slot hunter: procura secoes primarias PPP validas (sem root) e
programas/slots soltos nas 234 NO_ROOT. Também diff do primeiro 1KB entre
NO_ROOT e OPEN_OK de mesmo toolchain."""
import json
import struct
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

sys.path.insert(0, r"C:\Users\wande\Documents\ffx-editor-main\scripts")
from ppp_disassembler.layer_c_resource import (
    _u16, _u32, _valid_primary_section, _valid_counted_u32_table,
)

AUDIT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\CORPUS_AUDIT.json")
CORPUS = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX")
OUT = Path(__file__).resolve().parent


def data_sec(raw: bytes) -> bytes | None:
    if len(raw) < 0x40:
        return None
    pe = struct.unpack_from("<I", raw, 0x3C)[0]
    if raw[pe:pe + 2] != b"PE":
        return None
    nsec = struct.unpack_from("<H", raw, pe + 6)[0]
    optsz = struct.unpack_from("<H", raw, pe + 20)[0]
    base = pe + 24 + optsz
    for i in range(nsec):
        off = base + i * 40
        name = raw[off:off + 8].rstrip(b"\x00")
        if name != b".data":
            continue
        rs = struct.unpack_from("<I", raw, off + 16)[0]
        rp = struct.unpack_from("<I", raw, off + 20)[0]
        return raw[rp:rp + rs]
    return None


def hunter(data: bytes) -> dict:
    """Procura seções primárias válidas (mesma lógica do parser) sem root."""
    L = len(data)
    found = []
    # passo 4 bytes; usa _valid_primary_section com root=offset (rel=0)
    for off in range(0, L - 56, 4):
        sz = _u32(data, off)
        if sz < 56 or off + sz > L:
            continue
        # quick: counted tables em +8/+12
        r8 = _u32(data, off + 8)
        r12 = _u32(data, off + 12)
        if not (16 <= r8 < sz and 16 <= r12 < sz):
            continue
        if not _valid_counted_u32_table(data, off, sz, r8):
            continue
        if not _valid_counted_u32_table(data, off, sz, r12):
            continue
        # slot density no primeiro programa
        sc = _u16(data, off + 54)  # program+38 = off+16+38
        if not (0 <= sc <= 256):
            continue
        if off + 16 + 40 + 16 * sc > off + sz:
            continue
        if not _valid_primary_section(data, off, 0):
            continue
        found.append(off)
        if len(found) > 8:
            break
    return found


def scan_one(dll_name: str) -> dict:
    raw = (CORPUS / dll_name).read_bytes()
    data = data_sec(raw)
    res = {"dll": dll_name, "data_len": len(data) if data else 0}
    if data is None:
        res["error"] = "no_data_section"
        return res
    res["sections"] = hunter(data)
    # densidade de floats 1.0f e de u16 pares
    res["f1"] = data.count(b"\x00\x00\x80\x3f")
    return res


def main() -> None:
    d = json.loads(AUDIT.read_text(encoding="utf-8"))
    nr = [k for k, v in d["dlls"].items() if v.get("status") == "NO_ROOT"]
    with ProcessPoolExecutor(max_workers=8) as ex:
        rows = list(ex.map(scan_one, sorted(nr)))
    with_sections = [r for r in rows if r.get("sections")]
    print(f"DLLs com secao primaria PPP orfa: {len(with_sections)}/{len(rows)}")
    for r in with_sections[:30]:
        print(f"  {r['dll']}: {[hex(x) for x in r['sections'][:4]]}")
    out = OUT / "section_hunter_raw.json"
    out.write_text(json.dumps(rows, indent=1), encoding="utf-8")
    print("wrote", out)


if __name__ == "__main__":
    main()
