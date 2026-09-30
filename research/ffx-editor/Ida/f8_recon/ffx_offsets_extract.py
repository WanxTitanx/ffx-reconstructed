# F8 UnX Fase 2 - query FFX dbs for UnX patch targets (read-only, no save)
# Usage: idat.exe -A -L<log> -S"<this file>" <ffx .i64>
import idc
import ida_funcs
import ida_name
import ida_bytes
import json
import os

OUT = r"C:\Users\wande\Documents\ffx-editor-main\work\f8_recon\ida"

# targets to identify (IDA flat addresses of FFX.exe @ image base 0x400000)
TARGETS = [
    ("unx_mem_s_392930", 0x792930),   # UnX "mem s 392930 1d7e/1deb" (RVA 0x392930)
    ("unx_mem_b_D2A8E2", 0xD2A8E2),   # UnX "mem b D2A8E2 2" (queue_death)
    ("our_debug_invincible", 0xD2A8F9),  # nosso DEBUG Invincible Party
    ("our_debug_no_mp", 0xD2A901),       # nosso DEBUG No MP Cost
    ("unx_fmod_sync_30B040", 0x70B040),  # UnX AudioSkip patch (RVA 0x30B040)
    ("our_fmod_switch", 0x7089F0),       # nosso MusicHook SwitchCrossfade (RVA 0x3089F0)
    ("our_fmod_play", 0x7097E0),         # nosso MusicHook PlayTrack (RVA 0x3097E0)
]

results = []


def describe(ea):
    f = ida_funcs.get_func(ea)
    name = ida_name.get_name(ea) or ""
    seg = idc.get_segm_name(ea)
    data = ida_bytes.get_bytes(ea, 16)
    hexs = " ".join("%02X" % b for b in data) if data else "(none)"
    fstart = ("func@%X size=%d" % (f.start_ea, f.size())) if f else "(no func)"
    return {"ea": hex(ea), "seg": seg, "name": name, "func": fstart, "bytes": hexs}


for label, ea in TARGETS:
    results.append((label, describe(ea)))
    # se for meio de funcao, mostra a funcao dona
    f = ida_funcs.get_func(ea)
    if f and f.start_ea != ea:
        results.append((label + "_owner", describe(f.start_ea)))

with open(os.path.join(OUT, "ffx_offsets_query.json"), "w", encoding="utf-8") as fh:
    json.dump(results, fh, indent=1)
for label, r in results:
    print("%s: %s" % (label, json.dumps(r)))
idc.qexit(0)
