#!/usr/bin/env python3
"""count_live.py — conta unexplored na db aberta (sem qexit)."""
import sys

sys.path.insert(0, r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe")
import ida_pro

ida_pro.qexit = lambda code: print(f"(qexit ignorado: {code})", flush=True)
import count_unexplored  # noqa: E402

if __name__ == "__main__":
    count_unexplored.main()
    print("COUNT LIVE OK", flush=True)
