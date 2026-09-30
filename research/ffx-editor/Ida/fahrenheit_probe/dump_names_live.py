#!/usr/bin/env python3
"""dump_names_live.py — dumpa a nlist da COPY ABERTA (via MCP, sem qexit)."""
import os
import sys

sys.path.insert(0, r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe")
os.environ["OUT_JSON"] = r"F:\ffx-reconstructed\pseudocode\complete\copy_names.json"
import ida_pro  # noqa: E402

ida_pro.qexit = lambda code: print(f"(qexit ignorado: {code})", flush=True)
import dump_names  # noqa: E402

if __name__ == "__main__":
    dump_names.main()
    print("DUMP LIVE OK", flush=True)
