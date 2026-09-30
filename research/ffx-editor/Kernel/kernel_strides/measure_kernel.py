#!/usr/bin/env python3
# KERNEL-STRIDES measurement script (research only, read-only on corpus)
# Parses the EntryListFile-style 20-byte header of every .bin under
# */battle/kernel/ in every locale dir and verifies stride claims.
#
# Header layout (per docs/reverse/bin-formats/ability_command.bin.md +
# FFXProjectEditor/FfxLib/Common/EntryListFile.cs):
#   0x00 u8   signature        (0x01 expected; 0x02 seen on btl.bin)
#   0x01 7B   unknown          (zeros)
#   0x08 i16  previousFileCount (split-file base index; monster2/3 use it)
#   0x0A i16  entryCount        (count - 1)
#   0x0C i16  entrySize         <-- STRIDE declared by the file itself
#   0x0E i16  entryTableSize    (count*size masked to u16)
#   0x10 i32  entryTableOffset  (0x14)
# Records start at entryTableOffset, then a text blob follows the record array.

import os, struct, json, math

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master"
LOCALES = ["jppc", "inpc", "uspc", "new_jppc", "new_uspc", "new_chpc",
           "new_depc", "new_frpc", "new_itpc", "new_krpc", "new_sppc"]

def parse(path):
    size = os.path.getsize(path)
    with open(path, "rb") as f:
        head = f.read(20)
    r = {"file": os.path.basename(path), "size": size}
    if size < 20:
        r["verdict"] = "TOO_SMALL"
        return r
    sig = head[0]
    unk = head[1:8]
    prev, count_m1, esize, tsize, toff = struct.unpack("<hhhh i", head[8:20])
    r.update(sig=sig, unk_zero=(unk == b"\x00"*7), prev=prev,
             count_field=count_m1, esize=esize, tsize=tsize & 0xFFFF,
             tsize_signed=tsize, toff=toff)
    if sig != 1 or unk != b"\x00"*7:
        r["verdict"] = "NONSTANDARD_HEADER"
        return r
    raw_count = count_m1 + 1
    real = raw_count - prev
    r["raw_count"] = raw_count
    r["real_count"] = real
    # table-size check: field stores (raw_count * esize) & 0xFFFF? or real*esize?
    r["tsize_match_raw"] = (raw_count * esize) & 0xFFFF == (tsize & 0xFFFF)
    r["tsize_match_real"] = (real * esize) & 0xFFFF == (tsize & 0xFFFF)
    data_end = toff + real * esize
    r["data_end"] = data_end
    r["trailing"] = size - data_end
    r["fits"] = data_end <= size
    # naive divisibility of whole file by stride (the "pure math" check)
    r["size_mod_stride"] = size % esize if esize else None
    r["body_mod_stride"] = (size - toff) % esize if esize else None
    r["verdict"] = "OK" if r["fits"] and r["tsize_match_real"] else "CHECK"
    return r

rows = []
for loc in LOCALES:
    d = os.path.join(ROOT, loc, "battle", "kernel")
    if not os.path.isdir(d):
        continue
    for fn in sorted(os.listdir(d)):
        if fn.startswith(".") or fn.endswith(".$$$"):
            continue
        p = os.path.join(d, fn)
        if not os.path.isfile(p):
            continue
        rec = parse(p)
        rec["locale"] = loc
        rows.append(rec)

# emit CSV + pretty table
cols = ["locale","file","size","sig","prev","raw_count","real_count","esize",
        "tsize","tsize_match_real","toff","data_end","trailing","fits",
        "size_mod_stride","verdict"]
with open("/home/wanderson/Documents/ffx-editor-main/work/_kernel_strides/kernel_strides.csv","w") as f:
    f.write(",".join(cols)+"\n")
    for r in rows:
        f.write(",".join(str(r.get(c,"")) for c in cols)+"\n")

with open("/home/wanderson/Documents/ffx-editor-main/work/_kernel_strides/kernel_strides.json","w") as f:
    json.dump(rows, f, indent=1)

# console: per-locale table for jppc + inpc (full sets)
for loc in LOCALES:
    loc_rows = [r for r in rows if r["locale"]==loc]
    if not loc_rows:
        continue
    print(f"\n===== {loc} =====")
    print(f"{'file':40s} {'size':>7s} {'sig':>3s} {'prev':>5s} {'cnt':>4s} {'real':>4s} {'esz':>4s} {'tsz':>6s} {'trail':>6s} {'mod':>4s} {'verdict'}")
    for r in loc_rows:
        print(f"{r['file']:40s} {r['size']:>7d} {r.get('sig',''):>3} "
              f"{r.get('prev',''):>5} {r.get('raw_count',''):>4} {r.get('real_count',''):>4} "
              f"{r.get('esize',''):>4} {r.get('tsize',''):>6} {r.get('trailing',''):>6} "
              f"{r.get('size_mod_stride',''):>4} {r['verdict']}")
