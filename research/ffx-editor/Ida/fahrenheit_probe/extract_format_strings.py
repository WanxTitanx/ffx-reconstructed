#!/usr/bin/env python3
"""Frente 8: extrai strings de format (printf-style) do exe — o logging do jogo."""
import ida_bytes
import re
import json

START = 0xC00000
END = 0xC80000
FMT_RE = re.compile(rb"[^\x00]{8,}%[dscxXfp]\w*[^\x00]{0,60}")


def main():
    raw = ida_bytes.get_bytes(START, END - START) or b""
    seen = set()
    out = []
    for m in FMT_RE.finditer(raw):
        s = m.group().decode("ascii", "replace")
        if s not in seen and "%" in s:
            seen.add(s)
            out.append((START + m.start(), s))
    print(f"strings de format: {len(out)}", flush=True)
    for ea, s in out[:30]:
        print(f"  {hex(ea)}: {s[:90]}", flush=True)
    with open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\exe_format_strings.json", "w", encoding="utf-8") as f:
        json.dump([{"ea": hex(ea), "s": s} for ea, s in out], f, indent=1, ensure_ascii=False)


if __name__ == "__main__":
    main()
