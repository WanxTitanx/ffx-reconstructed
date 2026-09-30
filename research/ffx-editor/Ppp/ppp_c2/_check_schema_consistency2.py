import json, glob, os, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

sch = {}
for f in glob.glob(r"C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/families/*.json"):
    sch[os.path.basename(f).replace(".json", "")] = json.load(open(f, encoding="utf-8-sig"))
fm = json.load(open(r"C:/Users/wande/Documents/ffx-editor-main/work/magic_editor/field_map.json", encoding="utf-8"))
fams = fm["families"]

diff = []
for k, sv in sch.items():
    if k not in fams:
        continue
    fw = fams[k].get("window")
    sw = sv.get("runtime_window")
    if not fw or not sw:
        continue
    if sw.get("start") != fw.get("start") or sw.get("width") != fw.get("width"):
        diff.append((k, f"schema {sw} vs field_map {fw}"))
print("divergencias (runtime_window vs field_map):", diff if diff else "NENHUMA — consistente!")
