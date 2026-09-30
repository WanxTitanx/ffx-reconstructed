#!/usr/bin/env python3
"""Aplica renames em lote na db canonica a partir de um JSON {addr_hex: {name, ...}}.

Regras: aplica somente onde o nome atual e default (FUN_/sub_/dword_/unk_/...);
nunca sobrescreve nomes existentes. Uso: python ida_apply_renames_from_json.py <json> [db]
"""
import json
import re
import sys
from pathlib import Path

import idapro

FUNC_DEFAULT = re.compile(r"^(FUN_|sub_|nullsub_|loc_|j_|unknown)", re.I)
GLOB_DEFAULT = re.compile(r"^(dword_|unk_|byte_|word_|flt_|off_|dbl_|qword_)", re.I)


def main() -> int:
    import ida_name

    src = Path(sys.argv[1])
    db = sys.argv[2] if len(sys.argv) > 2 else r"F:\ffx-reconstructed\extras\ffxoficial.exe.i64"
    data = json.loads(src.read_text(encoding="utf-8"))
    print(f"OPEN {db}", flush=True)
    rc = idapro.open_database(db, False)
    if rc != 0:
        print(f"FATAL open rc={rc}", flush=True)
        return 2

    applied, skipped = [], []
    for addr_s, info in data.items():
        ea = int(addr_s, 16)
        name = info["name"] if isinstance(info, dict) else info
        if not re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", name):
            continue
        cur = ida_name.get_name(ea)
        if cur and not FUNC_DEFAULT.match(cur) and not GLOB_DEFAULT.match(cur):
            skipped.append({"ea": addr_s, "name": name, "current": cur})
            continue
        if ida_name.set_name(ea, name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
            applied.append({"ea": addr_s, "name": name})
        else:
            skipped.append({"ea": addr_s, "name": name, "fail": True})

    print(f"applied={len(applied)} skipped={len(skipped)}", flush=True)
    (src.with_suffix(".applied.json")).write_text(
        json.dumps({"applied": applied, "skipped": skipped}, indent=1, ensure_ascii=False), encoding="utf-8")
    idapro.close_database(True)
    print("DB saved.", flush=True)
    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except Exception:  # noqa: BLE001
        import traceback
        traceback.print_exc()
        sys.exit(1)
