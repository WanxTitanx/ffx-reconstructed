#!/usr/bin/env python3
"""fix_last_bytes_live.py — marca os ultimos bytes unknown como db (sem qexit)."""
import sys

sys.path.insert(0, r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe")
import ida_pro

ida_pro.qexit = lambda code: print(f"(qexit ignorado: {code})", flush=True)
import fix_last_bytes  # noqa: E402

if __name__ == "__main__":
    fix_last_bytes.main()
    print("FIX LIVE COMPLETO — db modificada (salve com Ctrl+S)", flush=True)
