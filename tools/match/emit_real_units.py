#!/usr/bin/env python3
"""Emit one compilable translation unit per decompiled function.

Same corpus and repair as gen_pseudocode_chunks.py, but one function per file
(the form used for byte-identity scoring against the image).  All units share the
typed global prelude produced by analyze_globals.py.
"""
import os
import json
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import gen_pseudocode_chunks as G

if __name__ == '__main__':
    out = sys.argv[1] if len(sys.argv) > 1 else '/tmp/real'
    if len(sys.argv) > 2:
        with open(sys.argv[2], encoding='utf-8') as f:
            G.FUNCTION_CONVENTIONS = json.load(f)
    G.emit_units(out)
