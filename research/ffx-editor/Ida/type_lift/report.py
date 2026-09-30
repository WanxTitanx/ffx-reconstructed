#!/usr/bin/env python3
"""report.py — per-candidate evidence table for signature rewrite."""
import json, re, os, sys

frames = json.load(open("stack_frames.json"))
protos = json.load(open("caller_protos.json"))

def frame_args(addr):
    fr = frames.get(addr.lower()) or frames.get(addr)
    if not fr: return []
    vars = fr.get("vars") or []
    ret = None
    for v in vars:
        if v["name"] == "__return_address":
            ret = int(v["offset"], 16)
    if ret is None:
        return [v["name"] for v in vars]
    return [f'{v["name"]}@{hex(int(v["offset"],16)-ret-4)}:{v.get("type","?")}'
            for v in vars if int(v["offset"],16) > ret]

def tail_before_rets(lines):
    tails = []
    for i,ln in enumerate(lines):
        if re.search(r"\bretn?\b", ln):
            tails.append([l.strip() for l in lines[max(0,i-5):i+1]])
    return tails

def main():
    only = sys.argv[1:] if len(sys.argv)>1 else None
    for fn in sorted(os.listdir("disasm")):
        if not fn.endswith(".asm"): continue
        a = fn[:-4]
        if only and a not in only: continue
        lines = open(f"disasm/{fn}").read().splitlines()
        name = lines[0][2:]
        proto = lines[1][9:]
        print("="*100)
        print(f'{a} {name}')
        print(f'  OLD: {proto}')
        print(f'  STACK-ARGS: {frame_args(a)}')
        for t in tail_before_rets(lines):
            print("  RET-TAIL:")
            for l in t: print("      ", l[:100])
        # lines with arg reads / ecx / edx usage
        for l in lines[2:]:
            if re.search(r"\[ebp\+(arg_|n0x|n[0-9A-F])", l) or re.search(r"\be(cx|dx)\b", l.split(";")[0]):
                print("  USE:", l.strip()[:110])
main()
