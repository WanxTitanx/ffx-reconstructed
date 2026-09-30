#!/usr/bin/env python3
"""F8 UnX Fase 1 - headless IDA analysis of unx.dll (menu F8 / plugin SpecialK).

Opens unx.dll with its PDB (symbols), waits for auto-analysis, exports:
  - all functions (name/start/size) to unx_functions.json
  - xrefs to key menu strings (handlers) to unx_string_xrefs.json
  - saves .i64 in work/f8_recon/ida/ for reuse
Pattern: docs/reverse/magic_dlls/batch_decompile.py (idapro package).
"""

import json
import os
import sys
import traceback
from pathlib import Path

IDA_INSTALL = r"C:\IDA\IDA Professional-9.2-Haly"
os.environ["IDADIR"] = IDA_INSTALL

UNX_DLL = Path(
    r"C:\Users\wande\Downloads\Compressed\UnX_0_9_1_9\unx.dll"
)
OUT_DIR = Path(
    r"C:\Users\wande\Documents\ffx-editor-main\work\f8_recon\ida"
)
OUT_DIR.mkdir(parents=True, exist_ok=True)

# Strings-chave do menu (extraidas do unx_strings_*.txt) - handlers a mapear
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

import idapro


def main():
    db_path = UNX_DLL
    print(f"[f8] opening {db_path} (run_auto_analysis=True)...", flush=True)
    ok = idapro.open_database(str(db_path), run_auto_analysis=True)
    if not ok:
        print("[f8] FAILED to open database", flush=True)
        return 1
    print("[f8] auto-analysis done. exporting...", flush=True)

    import idc
    import idautils
    import ida_funcs
    import ida_bytes
    import ida_name

    funcs = []
    for ea in idautils.Functions():
        name = ida_name.get_name(ea) or ""
        size = ida_funcs.get_func(ea).size() if ida_funcs.get_func(ea) else 0
        funcs.append({"start": hex(ea), "name": name, "size": size})
    funcs.sort(key=lambda f: int(f["start"], 16))

    with open(OUT_DIR / "unx_functions.json", "w", encoding="utf-8") as f:
        json.dump({"count": len(funcs), "functions": funcs}, f, indent=1)
    print(f"[f8] functions: {len(funcs)} -> unx_functions.json", flush=True)

    # xrefs: string addr -> list of code xrefs
    string_xrefs = {}
    for key in KEY_STRINGS:
        ea = idc.get_name_ea_simple(key) or idc.get_name_ea_simple("a" + key)
        if ea != idc.BADADDR:
            refs = []
            for xref in idautils.XrefsTo(ea):
                refs.append({"from": hex(xref.frm), "type": xref.type})
            string_xrefs[key] = {"string_ea": hex(ea), "xrefs": refs}
        else:
            string_xrefs[key] = {"string_ea": None, "xrefs": []}

    with open(OUT_DIR / "unx_string_xrefs.json", "w", encoding="utf-8") as f:
        json.dump(string_xrefs, f, indent=1)
    print(f"[f8] string xrefs -> unx_string_xrefs.json", flush=True)

    # save reusable .i64
    i64 = OUT_DIR / "unx.dll.i64"
    import ida_loader
    try:
        ida_loader.save_database(str(i64), 0)
        print(f"[f8] database saved: {i64}", flush=True)
    except Exception as exc:  # noqa
        print(f"[f8] db save skipped: {exc}", flush=True)

    idapro.close_database(save=False)
    print("[f8] done", flush=True)
    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except Exception:
        traceback.print_exc()
        sys.exit(2)
