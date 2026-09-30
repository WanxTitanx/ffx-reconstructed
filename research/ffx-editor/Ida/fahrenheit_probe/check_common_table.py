#!/usr/bin/env python3
"""Verifica a base de IDs da tabela Common: entrada 95 (halt) e outras do catalogo."""
import json
from pathlib import Path

import ida_bytes
import ida_name

CAT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\_spira_modifier_decomp\atel_call_targets.json")
TABLE = 0xC50050


def main():
    cat = {e["id"]: e for e in json.loads(CAT.read_text(encoding="utf-8"))}
    for n in (95, 166, 169, 347, 439):
        ptr = int.from_bytes(ida_bytes.get_bytes(TABLE + n * 16, 4), "little")
        cur = ida_name.get_name(ptr) if ptr else None
        entry = cat.get(n)
        print(f"ID {n} ({entry['name'] if entry else '?'}) -> {hex(ptr)} nome={cur}")


if __name__ == "__main__":
    main()
