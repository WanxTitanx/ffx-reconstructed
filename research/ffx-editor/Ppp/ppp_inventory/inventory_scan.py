# -*- coding: utf-8 -*-
"""PASSO 1 — Inventário de opcodes PPP por efeito (magic DLLs, SOMENTE LEITURA).

Varre TODAS as magic_*.dll em
  D:\\SteamLibrary\\steamapps\\common\\FINAL FANTASY FFX&FFX-2 HD Remaster\\magicFiles\\FFX\\
e, para cada uma:

  (a) parseia a seção .data via c2_effect_overlay.parse_pe_data_section;
  (b) percorre o PPP resource blob (layer_c_resource.find_ppp_resource_roots +
      layer_c_resource.iter_ppp_slots) enumerando os slots C1
      (handler_table_index + argument_relative);
  (c) resolve cada handler index contra a dispatch table global
      (FFX.exe VA 0xC3A500, 40B/entry, nome em slot +8) com fallback para o
      dicionário estático de docs\\reverse\\magic_dlls\\PPP_HANDLER_NAMES.json;
  (d) salva work\\ppp_inventory\\INVENTORY_20260731.json no formato
      {dll: {opcode: count, ..., slots: n}}.

DLLs que falham no walker C1 (formatos diferentes) são registradas com
status 'unparsed' e o scan segue. Nada é escrito nas DLLs.

Uso:
    python inventory_scan.py [--limit N] [--force] [--resume]
"""

from __future__ import annotations

import argparse
import json
import os
import re
import struct
import sys
import time
from pathlib import Path

# ---------------------------------------------------------------------------
# Bootstrap de imports — scripts\\ppp_disassembler (módulos do repo, NÃO editar)
# ---------------------------------------------------------------------------
REPO_ROOT = Path(__file__).resolve().parents[2]
SCRIPTS_DIR = REPO_ROOT / "scripts"
if str(SCRIPTS_DIR) not in sys.path:
    sys.path.insert(0, str(SCRIPTS_DIR))

from ppp_disassembler.c2_effect_overlay import parse_pe_data_section  # noqa: E402
from ppp_disassembler.layer_c_resource import (  # noqa: E402
    find_ppp_resource_roots,
    iter_ppp_slots,
)

# ---------------------------------------------------------------------------
# Constantes
# ---------------------------------------------------------------------------
MAGIC_DIR = Path(
    r"D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster\magicFiles\FFX"
)
FFX_EXE = Path(
    r"D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster\FFX.exe"
)
HANDLER_NAMES_JSON = (
    REPO_ROOT / "docs" / "reverse" / "magic_dlls" / "PPP_HANDLER_NAMES.json"
)
OUT_JSON = Path(__file__).resolve().parent / "INVENTORY_20260731.json"

DISPATCH_TABLE_VA = 0xC3A500      # FFX.exe — dispatch table global
DISPATCH_ENTRY_SIZE = 40          # 40 bytes por entrada
DISPATCH_NAME_OFFSET = 8          # nome (ponteiro) em slot +8
DISPATCH_MAX_ENTRIES = 1024       # teto de entradas lidas

STAMP = "20260731"
IDENT_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


# ---------------------------------------------------------------------------
# Dicionário estático index -> nome
# ---------------------------------------------------------------------------
def load_static_opcode_names() -> dict[int, str]:
    """Dicionário estático índice->nome a partir de PPP_HANDLER_NAMES.json."""
    names: dict[int, str] = {}
    if HANDLER_NAMES_JSON.is_file():
        try:
            data = json.loads(HANDLER_NAMES_JSON.read_text(encoding="utf-8-sig"))
            for entry in data.get("entries", []):
                idx = int(entry["index"])
                name = str(entry["name"]).strip()
                if name and idx >= 0:
                    names[idx] = name
        except Exception as exc:  # nunca derruba o scan por causa da tabela
            print(f"[warn] PPP_HANDLER_NAMES.json ilegível: {exc}")
    return names


# ---------------------------------------------------------------------------
# Dispatch table do FFX.exe (0xC3A500, 40B/entry, nome em slot +8)
# ---------------------------------------------------------------------------
def _parse_pe_layout(data: bytes):
    """Retorna (imagebase, [(name, va, vsize, raw_ptr, raw_size), ...])."""
    if len(data) < 0x40:
        return None
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    if pe + 24 > len(data) or data[pe:pe + 4] != b"PE\x00\x00":
        return None
    magic = struct.unpack_from("<H", data, pe + 24)[0]
    if magic == 0x10B:  # PE32
        imagebase = struct.unpack_from("<I", data, pe + 24 + 28)[0]
    elif magic == 0x20B:  # PE32+
        imagebase = struct.unpack_from("<Q", data, pe + 24 + 24)[0]
    else:
        return None
    num_sections = struct.unpack_from("<H", data, pe + 6)[0]
    opt_size = struct.unpack_from("<H", data, pe + 20)[0]
    table_start = pe + 24 + opt_size
    sections = []
    for i in range(num_sections):
        off = table_start + i * 40
        if off + 40 > len(data):
            break
        name = data[off:off + 8].rstrip(b"\x00").decode("ascii", "replace")
        vsize, va, raw_size, raw_ptr = struct.unpack_from("<IIII", data, off + 8)
        sections.append((name, va, vsize, raw_ptr, raw_size))
    return imagebase, sections


def _read_cstr(data: bytes, off: int, cap: int = 64) -> str | None:
    if off < 0 or off >= len(data):
        return None
    end = data.find(b"\x00", off, min(off + cap, len(data)))
    if end < 0:
        return None
    try:
        return data[off:end].decode("ascii")
    except UnicodeDecodeError:
        return None


def load_exe_dispatch_names(exe_path: Path) -> dict[int, str]:
    """Resolve a dispatch table do FFX.exe (VA 0xC3A500) -> {index: nome}."""
    names: dict[int, str] = {}
    if not exe_path.is_file():
        print(f"[warn] FFX.exe não encontrado: {exe_path}")
        return names
    data = exe_path.read_bytes()
    layout = _parse_pe_layout(data)
    if layout is None:
        print("[warn] FFX.exe: layout PE não reconhecido")
        return names
    imagebase, sections = layout

    def va_to_off(va: int) -> int | None:
        rva = va - imagebase if va >= imagebase else va
        for _name, s_va, s_vsize, s_raw_ptr, s_raw_size in sections:
            if s_va <= rva < s_va + max(s_vsize, s_raw_size):
                delta = rva - s_va
                if delta < s_raw_size:
                    return s_raw_ptr + delta
                return None
        return None

    table_off = va_to_off(DISPATCH_TABLE_VA)
    if table_off is None:
        print(f"[warn] dispatch table 0x{DISPATCH_TABLE_VA:X} fora das seções do FFX.exe")
        return names

    for idx in range(DISPATCH_MAX_ENTRIES):
        entry_off = table_off + DISPATCH_ENTRY_SIZE * idx
        if entry_off + 12 > len(data):
            break
        # FFX.exe dispatch table: ptr a nome em +0, handler em +8
        name_ptr = struct.unpack_from("<I", data, entry_off)[0]
        if name_ptr == 0:
            break
        name_off = va_to_off(name_ptr)
        if name_off is None:
            break
        name = _read_cstr(data, name_off, cap=80)
        if name is None or not IDENT_RE.match(name):
            break
        names[idx] = name
    return names



def resolve_name(index: int, static: dict[int, str], exe: dict[int, str]) -> str:
    """Nome do opcode: estático (JSON) > exe (0xC3A500) > idx_hex cru."""
    if index in static:
        return static[index]
    if index in exe:
        return exe[index]
    return f"idx_{index:02X}"

# ---------------------------------------------------------------------------
# Scan de uma DLL
# ---------------------------------------------------------------------------
def scan_dll_bytes(dll_bytes: bytes, static: dict[int, str], exe: dict[int, str]):
    """Retorna (status, {opcode: count}, total_slots, nota)."""
    data_section = parse_pe_data_section(dll_bytes)
    if data_section is None:
        return "unparsed", {}, 0, "no_.data_section"

    try:
        roots = find_ppp_resource_roots(data_section.bytes)
    except Exception as exc:
        return "unparsed", {}, 0, f"root_scan_error:{type(exc).__name__}"
    if not roots:
        return "unparsed", {}, 0, "no_ppp_resource_root"

    counts: dict[str, int] = {}
    seen: set[int] = set()
    total = 0
    for root in roots:
        try:
            for rec in iter_ppp_slots(data_section.bytes, root):
                if rec.offset in seen:
                    continue
                seen.add(rec.offset)
                name = resolve_name(rec.slot.handler_table_index, static, exe)
                counts[name] = counts.get(name, 0) + 1
                total += 1
        except Exception as exc:
            return "partial", counts, total, (
                f"slot_walk_error:{type(exc).__name__} (roots={len(roots)})"
            )
    return "ok", counts, total, ""


# ---------------------------------------------------------------------------
# Persistência incremental (resume seguro)
# ---------------------------------------------------------------------------
def _save_atomic(payload: dict) -> None:
    tmp = OUT_JSON.with_suffix(".json.tmp")
    tmp.write_text(json.dumps(payload, indent=1, ensure_ascii=False), encoding="utf-8")
    os.replace(tmp, OUT_JSON)


def main() -> None:
    ap = argparse.ArgumentParser(description="Inventário de opcodes PPP por magic DLL")
    ap.add_argument("--limit", type=int, default=0, help="varre só as N primeiras DLLs")
    ap.add_argument("--force", action="store_true", help="reescanear tudo (ignora resume)")
    ap.add_argument("--resume", action="store_true", help="retoma scan parcial existente")
    args = ap.parse_args()

    t0 = time.time()
    static = load_static_opcode_names()
    exe = load_exe_dispatch_names(FFX_EXE)
    print(f"[init] estático={len(static)} entradas | exe 0xC3A500={len(exe)} entradas | "
          f"{time.time() - t0:.1f}s")

    dll_paths = sorted(MAGIC_DIR.glob("magic_*.dll"))
    if args.limit > 0:
        dll_paths = dll_paths[: args.limit]
    print(f"[init] {len(dll_paths)} DLLs alvo em {MAGIC_DIR}")

    dlls: dict[str, dict] = {}
    if (args.resume or OUT_JSON.is_file()) and not args.force:
        if OUT_JSON.is_file():
            try:
                prev = json.loads(OUT_JSON.read_text(encoding="utf-8"))
                dlls = dict(prev.get("dlls", {}))
                print(f"[resume] {len(dlls)} DLLs já registradas — pulando")
            except Exception:
                dlls = {}

    skipped = 0
    unparsed = 0
    partial = 0
    parsed_ok = 0
    for i, path in enumerate(dll_paths, 1):
        name = path.name
        if name in dlls:
            skipped += 1
            continue
        try:
            blob = path.read_bytes()
        except OSError as exc:
            dlls[name] = {"slots": 0, "status": "unparsed", "note": f"read_error:{exc}"}
            unparsed += 1
            continue

        status, counts, total, note = scan_dll_bytes(blob, static, exe)
        entry = dict(counts)
        entry["slots"] = total
        entry["status"] = status
        if note:
            entry["note"] = note
        dlls[name] = entry

        if status == "ok":
            parsed_ok += 1
        elif status == "partial":
            partial += 1
        else:
            unparsed += 1

        if i % 10 == 0 or i == len(dll_paths):
            elapsed = time.time() - t0
            print(f"[scan] {i}/{len(dll_paths)} ok={parsed_ok} partial={partial} "
                  f"unparsed={unparsed} ({elapsed:.0f}s)", flush=True)

        # persistência incremental: nunca perde progresso
        payload = {
            "meta": {
                "stamp": STAMP,
                "tool": "inventory_scan.py (PASSO 1)",
                "magic_dir": str(MAGIC_DIR),
                "n_dlls_total": len(dll_paths),
                "dispatch_table_va": hex(DISPATCH_TABLE_VA),
                "dispatch_entry_size": DISPATCH_ENTRY_SIZE,
                "dispatch_name_offset": DISPATCH_NAME_OFFSET,
                "static_names_source": str(HANDLER_NAMES_JSON),
                "static_names_count": len(static),
                "exe_names_count": len(exe),
            },
            "dlls": dlls,
        }
        if i % 20 == 0:
            _save_atomic(payload)

    # ---- summary agregado ----
    opcode_totals: dict[str, int] = {}
    total_slots = 0
    for entry in dlls.values():
        total_slots += int(entry.get("slots", 0))
        for key, count in entry.items():
            if key in ("slots", "status", "note"):
                continue
            opcode_totals[key] = opcode_totals.get(key, 0) + int(count)

    top = sorted(opcode_totals.items(), key=lambda kv: kv[1], reverse=True)[:25]
    payload = {
        "meta": {
            "stamp": STAMP,
            "tool": "inventory_scan.py (PASSO 1)",
            "magic_dir": str(MAGIC_DIR),
            "n_dlls_total": len(dll_paths),
            "n_dlls_ok": parsed_ok,
            "n_dlls_partial": partial,
            "n_dlls_unparsed": unparsed,
            "n_dlls_skipped_resume": skipped,
            "total_slots": total_slots,
            "distinct_opcodes": len(opcode_totals),
            "dispatch_table_va": hex(DISPATCH_TABLE_VA),
            "dispatch_entry_size": DISPATCH_ENTRY_SIZE,
            "dispatch_name_offset": DISPATCH_NAME_OFFSET,
            "static_names_source": str(HANDLER_NAMES_JSON),
            "static_names_count": len(static),
            "exe_names_count": len(exe),
            "elapsed_seconds": round(time.time() - t0, 1),
        },
        "opcode_totals": dict(sorted(opcode_totals.items(), key=lambda kv: kv[1], reverse=True)),
        "top25_opcodes": [{"opcode": k, "slots": v} for k, v in top],
        "dlls": dlls,
    }
    _save_atomic(payload)
    print(f"[done] {len(dll_paths)} DLLs | ok={parsed_ok} partial={partial} "
          f"unparsed={unparsed} | slots={total_slots} | opcodes={len(opcode_totals)} | "
          f"{time.time() - t0:.0f}s -> {OUT_JSON}")


if __name__ == "__main__":
    main()

