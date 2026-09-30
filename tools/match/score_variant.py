#!/usr/bin/env python3
"""Score one C variant against the reference bytes of FFX_memcmp.

Usage: score_variant.py <variant.c>   (run on the Windows VM side via batch,
or locally after fetching the obj disassembly -- see run_score.bat).
"""

import re
import subprocess
import sys

REF_HEX = (
    '558bec8b4d1085c9750433c05dc38b5508568b750c83e90472178d9b00000000'
    '8b023b06751083c20483c60483e90473ef83f9fc74358a023a06752783f9fd742a'
    '8a42013a4601751a83f9fe741d8a42023a4602750d83f9ff74108a42033a4603740'
    '81bc083c8015e5dc333c05e5dc3'
)


def obj_text_bytes(disasm: str) -> bytes:
    """Parse dumpbin /DISASM output, return concatenated .text code bytes."""
    out = bytearray()
    for line in disasm.splitlines():
        m = re.match(r'^\s+[0-9A-F]+:\s+((?:[0-9A-F]{2}\s?)+)', line)
        if m:
            toks = m.group(1).split()
            bs = bytearray()
            for tok in toks:
                if re.fullmatch(r'[0-9A-F]{2}', tok):
                    bs.append(int(tok, 16))
                else:
                    break
            out += bs
    return bytes(out)


def main() -> int:
    disasm_path = sys.argv[1]
    disasm = open(disasm_path, encoding='utf-8', errors='replace').read()
    got = obj_text_bytes(disasm)
    ref = bytes.fromhex(REF_HEX)
    n = min(len(got), len(ref))
    same = sum(1 for i in range(n) if got[i] == ref[i])
    first = next((i for i in range(n) if got[i] != ref[i]), n)
    print(f'got_len={len(got)} ref_len={len(ref)} agree={same}/{n}={100*same/max(n,1):.1f}% first_diff=+{first}')
    if first < n:
        print(f'  ref : {ref[max(0,first-6):first+10].hex()}')
        print(f'  got : {got[max(0,first-6):first+10].hex()}')
    # feature flags
    feats = {
        'sbb': '1bc0' in got.hex(),
        'or_eax1': '83c801' in got.hex(),
        'and_eax': '83e0fe' in got.hex(),
        'mov_bl': '8a1e' in got.hex(),
        'jb_entry': '7217' in got.hex() or '7211' in got.hex(),
        'js_entry': '7817' in got.hex() or '7811' in got.hex(),
        'jae_loop': '73ef' in got.hex(),
        'jns_loop': '79ef' in got.hex(),
        'setne': '0f95c0' in got.hex(),
        'push_ebx': '53' in got.hex()[:40],
    }
    print('feats: ' + ' '.join(f'{k}={int(v)}' for k, v in feats.items()))
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
