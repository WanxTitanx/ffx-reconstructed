#!/usr/bin/env python3
"""dump_names_canon.py — dumpa a nlist da CANONICA (idat headless, com qexit)."""
import os
import sys

sys.path.insert(0, r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe")
os.environ["OUT_JSON"] = r"F:\ffx-reconstructed\pseudocode\complete\canon_names.json"
import dump_names  # noqa: E402

if __name__ == "__main__":
    dump_names.main()
    import ida_pro
    ida_pro.qexit(0)
