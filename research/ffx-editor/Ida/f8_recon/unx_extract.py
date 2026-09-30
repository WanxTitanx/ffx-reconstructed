# F8 UnX Fase 1 - IDAPython extractor (runs inside idat.exe headless)
# Usage: idat.exe -A -L<log> -S"<this file>" unx.dll
import idc
import idautils
import ida_funcs
import ida_name
import ida_loader
import json
import os

OUT = r"C:\Users\wande\Documents\ffx-editor-main\work\f8_recon\ida"

KEY_STRINGS = [
    "Full Party AP", "Permanent Sensor", "Game Speed", "SPECIAL MODE",
    "Toggle VSYNC", "Speed Boost", "Toggle Time Stop", "Toggle Freelook",
    "Entire Party Earns AP", "Grant Permanent Sensor", "Seymour As Playable Character",
    "mem s 392930 1d7e", "mem s 392930 1deb", "mem b 9F7880 1",
    "mem b 9F7880 0", "mem b D2A8E2 2", "DI8_GetDeviceState_Override",
    "SK_Input_GetDI8Keyboard", "Kickstart", "Soft Reset", "Step Multiplier",
    "Speed Limit", "Dialog Skip At", "FFX_GameTick", "Sig Scan",
    "Setting up FFX Cheat Engine", "Game Boosters", "Sensor / Party AP",
    "Misc.", "Key Bindings", "Gamepad Config", "Language", "Voice",
    "Sound Effects", "Full Motion Video", "UNX_FFX_GameTick",
]


def main():
    funcs = []
    for ea in idautils.Functions():
        f = ida_funcs.get_func(ea)
        name = ida_name.get_name(ea) or ""
        funcs.append({"start": hex(ea), "name": name, "size": f.size() if f else 0})
    funcs.sort(key=lambda x: int(x["start"], 16))
    with open(os.path.join(OUT, "unx_functions.json"), "w", encoding="utf-8") as fh:
        json.dump({"count": len(funcs), "functions": funcs}, fh, indent=1)
    print("[f8] functions=%d" % len(funcs))

    # locate strings in .rdata and collect code xrefs
    xrefs = {}
    seg = idc.get_segm_by_sel(idc.selector_by_name(".rdata"))
    if seg:
        start = idc.get_segm_start(seg)
        end = idc.get_segm_end(seg)
        ea = start
        while ea < end:
            s = idc.get_strlit_contents(ea, -1, idc.STRTYPE_C)
            if s:
                try:
                    txt = s.decode("utf-8", "replace")
                except Exception:
                    txt = ""
                for key in KEY_STRINGS:
                    if txt == key or txt.startswith(key):
                        refs = []
                        for x in idautils.XrefsTo(ea):
                            refs.append({"from": hex(x.frm), "type": x.type})
                        if key not in xrefs:
                            xrefs[key] = {"string_ea": hex(ea), "xrefs": refs}
            ea = idc.next_head(ea, end)
    with open(os.path.join(OUT, "unx_string_xrefs.json"), "w", encoding="utf-8") as fh:
        json.dump(xrefs, fh, indent=1)
    print("[f8] string xrefs=%d" % len(xrefs))

    try:
        ida_loader.save_database(os.path.join(OUT, "unx.dll.i64"), 0)
        print("[f8] db saved")
    except Exception as exc:
        print("[f8] db save failed: %r" % exc)

    idc.qexit(0)


main()
