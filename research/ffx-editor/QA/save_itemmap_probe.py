#!/usr/bin/env python3
"""MASTER-§11-UNKNOWN: save item_map_x/item_map_y probe.
§11.37 lists u16@file+0xF4 (item_map_x) and u16@file+0xF6 (item_map_y) as
'Meaning unknown'. Corpus: 66 TAS saves + converter saves + user saves
(G: disco-velho). Histogram (x,y) pairs, correlate with room_id@+0xFA,
spawn@+0xF8, game_time@+0xFC. Files are 26880 B (Steam .ffx payload).
"""
import os, sys, json, struct, collections

CORPUS_DIRS = [
    ("tas",      "/home/wanderson/Documents/ffx-editor-main/Utilities/FFX_TAS_Python/tas_saves"),
    ("conv",     "/home/wanderson/Documents/ffx-editor-main/Utilities/Final-Fantasy-X-HD-Cross-platform-Save-Converter/Extracted Saves/FFX"),
    ("user_bak", "/mnt/disco-velho/Backup C 2026-09-02/Users/wande/Documents/SQUARE ENIX/FINAL FANTASY X&X-2 HD Remaster/FINAL FANTASY X"),
    ("user_old", "/mnt/disco-velho/Old C/Users/wande/Documents/SQUARE ENIX/FINAL FANTASY X&X-2 HD Remaster/FINAL FANTASY X"),
]

def is_save(path):
    try:
        return os.path.isfile(path) and os.path.getsize(path) == 26880
    except OSError:
        return False

rows = []
for tag, d in CORPUS_DIRS:
    if not os.path.isdir(d):
        print(f"[{tag}] MISSING dir {d}")
        continue
    n = 0
    for dp, _, fns in os.walk(d):
        for fn in fns:
            p = os.path.join(dp, fn)
            if not is_save(p):
                continue
            n += 1
            data = open(p, "rb").read(0x120)
            rows.append({
                "src": tag, "name": fn, "path": p,
                "item_x": struct.unpack_from("<H", data, 0xF4)[0],
                "item_y": struct.unpack_from("<H", data, 0xF6)[0],
                "spawn": data[0xF8],
                "room": struct.unpack_from("<H", data, 0xFA)[0],
                "time": struct.unpack_from("<I", data, 0xFC)[0],
                "battle_status": data[0x53],
            })
    print(f"[{tag}] {n} saves")

hist = collections.Counter((r["item_x"], r["item_y"]) for r in rows)
print(f"\ntotal saves={len(rows)}  distinct (item_x,item_y)={len(hist)}")
print("top pairs:")
for (x, y), c in hist.most_common(40):
    print(f"  x=0x{x:04X} y=0x{y:04X}  x{c}")
# zero stats
zx = sum(1 for r in rows if r["item_x"] == 0)
zy = sum(1 for r in rows if r["item_y"] == 0)
print(f"item_x==0: {zx}/{len(rows)}   item_y==0: {zy}/{len(rows)}")
xs = [r["item_x"] for r in rows]; ys = [r["item_y"] for r in rows]
if xs:
    print(f"item_x range {min(xs)}..{max(xs)}  item_y range {min(ys)}..{max(ys)}")
# per-room correlation: does (x,y) depend on room?
byroom = collections.defaultdict(set)
for r in rows:
    byroom[r["room"]].add((r["item_x"], r["item_y"]))
multi = {k: v for k, v in byroom.items() if len(v) > 1}
print(f"rooms={len(byroom)}  rooms with >1 distinct (x,y): {len(multi)}")
for k, v in list(multi.items())[:15]:
    print(f"  room 0x{k:04X}: {sorted(v)}")
# battle_status byte histogram (bits 1,2 mapped: sys/dummy_enc)
bsh = collections.Counter(r["battle_status"] for r in rows)
print("\nbattle_status@0x53 hist:", {hex(k): c for k, c in sorted(bsh.items())})
seen_bits = set()
for k in bsh:
    for b in range(8):
        if k >> b & 1:
            seen_bits.add(b)
print("bits ever set:", sorted(seen_bits))

with open(os.path.join(os.path.dirname(os.path.abspath(__file__)),
                       "save_itemmap_probe.json"), "w") as fo:
    json.dump({"rows": rows,
               "pair_hist": {f"{x:04X},{y:04X}": c for (x, y), c in hist.items()},
               "battle_status_hist": {hex(k): c for k, c in bsh.items()}},
              fo, indent=1)
