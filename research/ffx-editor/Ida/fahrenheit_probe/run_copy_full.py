#!/usr/bin/env python3
"""
run_copy_full.py — Roda na ffxoficial_COPY.i64 via idat headless:
1. decompile_complete (FORCE — regenera todos os .c e grava o CACHE do Hex-Rays na COPY)
2. explore_all (100% explorada — zero unexplored)
3. salva a db (idat salva no exit com -A)
Uso: idat64.exe -A -L<log> -I"run_copy_full.py" <db>
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import decompile_complete
import explore_all


def main():
    decompile_complete.main(force=True)
    explore_all.main()


if __name__ == "__main__":
    main()
