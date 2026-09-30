# F8 UnX Fase 1/2 - decompile key handlers from saved unx.dll.i64
# Usage: idat.exe -A -L<log> -S"<this file>" unx.dll.i64
import idc
import idautils
import ida_funcs
import ida_hexrays
import ida_name
import json
import os

OUT = r"C:\Users\wande\Documents\ffx-editor-main\work\f8_recon\ida"

# (label, address or name)
TARGETS = [
    ("ffx_memory_s_ctor", 0x100016C0),
    ("ffx2_memory_s_ctor", 0x10001690),
    ("CheatTimer_FFX", 0x1001DF40),
    ("CheatManager_Init", 0x1001E610),
    ("UNX_ToggleSensor", 0x1001E520),
    ("UNX_FFX_AudioSkip", 0x1001E880),
    ("UNX_PatchLanguageFFX", 0x10027450),
    ("UNX_PatchLanguageFFX2", 0x10027270),
    ("InputManager_Init", 0x10024DA0),
    ("UNX_FFX2_UnitTest", 0x1001DEE0),
]

# string xrefs -> containing function (from unx_string_xrefs.json)
with open(os.path.join(OUT, "unx_string_xrefs.json"), encoding="utf-8") as fh:
    XREFS = json.load(fh)

results = []
seen = set()


def dump_func(ea, label):
    f = ida_funcs.get_func(ea)
    if not f:
        results.append("// %s: no func at %s" % (label, hex(ea)))
        return
    fstart = f.start_ea
    if fstart in seen:
        return
    seen.add(fstart)
    name = ida_name.get_name(fstart) or "sub_%X" % fstart
    cf = ida_hexrays.decompile(fstart)
    body = str(cf) if cf else "(decompile failed)"
    results.append("// ===== %s :: %s @ %s (ref %s) =====" % (label, name, hex(fstart), hex(ea)))
    results.append(body)
    results.append("")


for key, info in XREFS.items():
    for x in info.get("xrefs", []):
        ea = int(x["from"], 16)
        dump_func(ea, "xref:" + key.replace(" ", "_")[:40])

for label, ea in TARGETS:
    dump_func(ea, label)

with open(os.path.join(OUT, "unx_decompiled.c"), "w", encoding="utf-8") as fh:
    fh.write("\n".join(results))
print("[f8] decompiled %d functions -> unx_decompiled.c" % len(seen))
idc.qexit(0)
