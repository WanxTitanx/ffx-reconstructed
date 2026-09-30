#!/usr/bin/env python3
"""Compara os nomes atuais dos handlers da tabela Battle com o catalogo do Spira."""
import json
from pathlib import Path

import ida_bytes
import ida_name

CAT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\_spira_modifier_decomp\atel_call_targets.json")


def main():
    cat = {e["id"]: e for e in json.loads(CAT.read_text(encoding="utf-8"))}
    raw = ida_bytes.get_bytes(0xC42618, 0x1370)
    diffs, matched = [], 0
    for i in range(0, len(raw), 4):
        ptr = int.from_bytes(raw[i:i + 4], "little")
        cid = 0x7000 + i // 4
        e = cat.get(cid)
        if not e or ptr == 0:
            continue
        cur = ida_name.get_name(ptr)
        if cur and e["name"] != cur:
            diffs.append((hex(cid), e["name"], cur, hex(ptr)))
        elif cur:
            matched += 1
    print(f"MATCHED={matched} DIVERGENCIAS={len(diffs)}")
    for d in diffs[:25]:
        print(" ", d)


if __name__ == "__main__":
    main()
