# F8 Fase 4 - analyze ffx-probe.dll: what is at RVA 0x12C1 (crash site with UnX present)
# Usage: idat.exe -A -L<log> -S"<this file>" ffx-probe.dll
import idc
import idautils
import ida_funcs
import ida_name
import ida_hexrays
import ida_bytes
import idaapi
import json
import os

OUT = r"C:\Users\wande\Documents\ffx-editor-main\work\f8_recon\ida"
TARGET_RVA = 0x12C1
BASE = idaapi.get_imagebase()
TARGET = BASE + TARGET_RVA

results = []

funcs = []
for ea in idautils.Functions():
    f = ida_funcs.get_func(ea)
    funcs.append({"start": hex(ea), "rva": hex(ea - BASE), "name": ida_name.get_name(ea) or "",
                  "size": f.size() if f else 0})
funcs.sort(key=lambda x: int(x["start"], 16))
with open(os.path.join(OUT, "probe_functions.json"), "w", encoding="utf-8") as fh:
    json.dump({"imagebase": hex(BASE), "count": len(funcs), "functions": funcs}, fh, indent=1)

owner = None
for f in funcs:
    s = int(f["start"], 16)
    if s <= TARGET < s + f["size"]:
        owner = f
        break
results.append({"target": hex(TARGET), "target_rva": hex(TARGET_RVA), "imagebase": hex(BASE), "owner": owner})

data = ida_bytes.get_bytes(TARGET, 16)
results.append({"target_bytes": " ".join("%02X" % b for b in data) if data else None})

if owner:
    ea = int(owner["start"], 16)
    cf = ida_hexrays.decompile(ea)
    results.append({"owner_decompiled": str(cf) if cf else "(failed)"})

# exports (FF10HgetName/FF10HgetVer) - where are they?
results.append({"exports_near": [f for f in funcs if f["name"] in ("FF10HgetName", "FF10HgetVer", "DllMain")]})

with open(os.path.join(OUT, "probe_0x12C1_query.json"), "w", encoding="utf-8") as fh:
    json.dump(results, fh, indent=1)
print("[probe] base:", hex(BASE), "owner:", json.dumps(owner))
idc.qexit(0)
