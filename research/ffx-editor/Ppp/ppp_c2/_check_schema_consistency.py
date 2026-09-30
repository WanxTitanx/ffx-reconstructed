import json, glob, os, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

sch = {}
for f in glob.glob(r"C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/families/*.json"):
    sch[os.path.basename(f).replace(".json", "")] = json.load(open(f, encoding="utf-8-sig"))
fm = json.load(open(r"C:/Users/wande/Documents/ffx-editor-main/work/magic_editor/field_map.json", encoding="utf-8"))
fams = fm["families"]
print("schemas C2:", len(sch), "| field_map famílias:", len(fams))
diff = []
for k, sv in sch.items():
    if k not in fams:
        continue
    fw = fams[k].get("window")
    if not fw:
        continue
    sw = sv.get("window") or {}
    if sw.get("width") != fw.get("width"):
        diff.append((k, sw.get("width"), fw.get("width")))
print("divergencias de janela schema vs field_map:", diff if diff else "NENHUMA")
