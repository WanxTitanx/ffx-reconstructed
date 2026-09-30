#!/usr/bin/env python3
"""scan_vtables2.py — vtable scan with COL-aware boundary splitting.
A vtable boundary = position where dword_at(pos-4) parses as an MSVC COL
(sig 0/1, small offsets, pTD/pCHD in rdata, TD name '.?')."""
import json, pickle, struct
from collections import Counter

REGIONS = [(0xB0C8C0, "rdata.bin"), (0xC0A000, "ext.bin")]
TEXT_LO, TEXT_HI = 0x401000, 0xB0C000

bufs = {b: open(f, "rb").read() for b, f in REGIONS}
def region(a):
    for base in sorted(bufs):
        if base <= a < base + len(bufs[base]):
            return base
def dword_at(a):
    b = region(a)
    return None if b is None else struct.unpack_from("<I", bufs[b], a - b)[0]
def cstring_at(a, mx=300):
    b = region(a)
    if b is None: return None
    buf = bufs[b]; off = a - b
    e = buf.find(b"\x00", off, min(off + mx, len(buf)))
    if e < 0: return None
    return buf[off:e].decode("ascii", "replace")

funcs = pickle.load(open("all_funcs.pkl", "rb"))
func_starts = set(int(f["addr"], 16) for f in funcs)
func_names = {int(f["addr"], 16): f["name"] for f in funcs}
globs = json.load(open("rdata_globals.json"))
gmap = {int(g["addr"], 16): g["name"] for g in globs}

def is_rdata_ptr(v):
    return v is not None and (v & 3) == 0 and region(v) is not None

def parse_col(a):
    sig = dword_at(a); off = dword_at(a + 4); cd = dword_at(a + 8)
    td = dword_at(a + 0xC); chd = dword_at(a + 0x10)
    if sig not in (0, 1) or off is None or off > 0x10000 or cd is None or cd > 0x10000:
        return None
    if not is_rdata_ptr(td) or not is_rdata_ptr(chd):
        return None
    name = cstring_at(td + 8)
    if not name or not name.startswith(".?"):
        return None
    # hierarchy depth via CHD numBaseClasses
    nb = dword_at(chd + 8)
    return {"col": a, "td": td, "chd": chd, "mangled": name, "nbases": nb}

def demangle(m):
    """'.?AVC@B@A@@' -> 'A::B::C'; templates: inner '@'-separated tokens kept."""
    if not m.startswith(".?A"):
        return m
    body = m[1:]
    if body.endswith("@@"):
        body = body[:-2]
    parts = [p for p in body.split("@") if p]
    parts = [p[3:] if p[:3] in ("?AV", "?AU", "?AT") else p for p in parts]
    parts = [p.lstrip("$") for p in parts]
    return "::".join(reversed(parts)) if parts else m

results = []
for base in sorted(bufs):
    buf = bufs[base]; n = len(buf); off = 0
    while off + 4 <= n:
        v = struct.unpack_from("<I", buf, off)[0]
        if v in func_starts:
            start = off
            while off + 4 <= n and struct.unpack_from("<I", buf, off)[0] in func_starts:
                off += 4
            run_lo, run_len = start, (off - start) // 4
            # split run at internal COL boundaries
            seg_start = start
            for k in range(1, run_len):
                prevd = struct.unpack_from("<I", buf, start + 4 * k - 4)[0]
                if is_rdata_ptr(prevd) and parse_col(prevd):
                    # boundary at start+4k
                    seg_len = k - (seg_start - start) // 4
                    results.append((base + seg_start, seg_len))
                    seg_start = start + 4 * k
            results.append((base + seg_start, run_len - (seg_start - start) // 4))
        else:
            off += 4

out = []
for vaddr, length in results:
    if length < 3:
        continue
    prev = dword_at(vaddr - 4)
    col = parse_col(prev) if is_rdata_ptr(prev) else None
    e = {"vtable": hex(vaddr), "slots": length, "prev": hex(prev or 0),
         "name_now": gmap.get(vaddr), "has_col": col is not None}
    if col:
        e["class"] = demangle(col["mangled"]); e["mangled"] = col["mangled"]
        e["col"] = hex(col["col"]); e["nbases"] = col["nbases"]
    e["members"] = [{"i": i, "addr": hex(dword_at(vaddr + 4 * i)),
                     "name": func_names.get(dword_at(vaddr + 4 * i))} for i in range(length)]
    out.append(e)

json.dump(out, open("vtables2.json", "w"), indent=1)
c = Counter()
for e in out:
    n = e["name_now"]
    kind = "none" if not n else ("mangled" if n.startswith("??_7") else
          ("auto" if n.startswith(("off_", "dword_", "unk_")) else "friendly"))
    c[kind + ("+col" if e["has_col"] else "-nocol")] += 1
print("vtables:", len(out), dict(c))
EOF_MARKER = None
