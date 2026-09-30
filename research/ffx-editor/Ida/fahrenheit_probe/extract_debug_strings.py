#!/usr/bin/env python3
"""Frente 3: extrai strings de debug (regiao 0xB4F000-0xB80000)."""
import ida_bytes
import re

START = 0xB4F000
END = 0xB80000
PAT = re.compile(rb"[\x20-\x7E]{8,}")


def main():
    raw = ida_bytes.get_bytes(START, END - START) or b""
    strings = []
    for m in PAT.finditer(raw):
        s = m.group().decode("ascii", "replace")
        strings.append((START + m.start(), s))
    print(f"strings: {len(strings)}", flush=True)
    import json
    with open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\debug_strings.json", "w", encoding="utf-8") as f:
        json.dump([{"ea": hex(e), "s": s} for e, s in strings], f, indent=1, ensure_ascii=False)
    print("JSON salvo", flush=True)
    for ea, s in strings[:6]:
        print(f"  {hex(ea)}: {s[:90]}", flush=True)


if __name__ == "__main__":
    main()
