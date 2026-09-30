# F8 UnX Fase 1 - IDAPython extractor for dxgi.dll (SpecialK 0.8.36 fork)
# Usage: idat.exe -A -L<log> -S"<this file>" dxgi.dll
import idc
import idautils
import ida_funcs
import ida_name
import ida_loader
import json
import os

OUT = r"C:\Users\wande\Documents\ffx-editor-main\work\f8_recon\ida"

KEY_STRINGS = [
    "SK_CreateFuncHook", "SK_CreateDLLHook", "SK_ApplyQueuedHooks",
    "D3D11CreateDevice", "CreateDXGIFactory", "Present", "ResizeBuffers",
    "GetDeviceState", "GetKeyboardState", "SK_UpdateSoftware", "SK_FetchVersionInfo",
    "SK_BeginBufferSwap", "SpecialK", "UnX", "ProjectX", "0.8.36",
]


def main():
    funcs = []
    for ea in idautils.Functions():
        f = ida_funcs.get_func(ea)
        name = ida_name.get_name(ea) or ""
        funcs.append({"start": hex(ea), "name": name, "size": f.size() if f else 0})
    funcs.sort(key=lambda x: int(x["start"], 16))
    with open(os.path.join(OUT, "dxgi_functions.json"), "w", encoding="utf-8") as fh:
        json.dump({"count": len(funcs), "functions": funcs}, fh, indent=1)
    print("[f8-dxgi] functions=%d" % len(funcs))

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
    with open(os.path.join(OUT, "dxgi_string_xrefs.json"), "w", encoding="utf-8") as fh:
        json.dump(xrefs, fh, indent=1)
    print("[f8-dxgi] string xrefs=%d" % len(xrefs))

    try:
        ida_loader.save_database(os.path.join(OUT, "dxgi.dll.i64"), 0)
        print("[f8-dxgi] db saved")
    except Exception as exc:
        print("[f8-dxgi] db save failed: %r" % exc)

    idc.qexit(0)


main()
