import json
import sys

sys.path.insert(0, r"C:\Users\wande\Documents\ffx-editor-main\scripts")
import ida_mcp_client as c

batch = {
    "globals": [
        {"addr": "0x75B9F0", "name": "FFX_BoneAnim_AccumulateDoubleLayerFloat4"},
        {"addr": "0x75BAC0", "name": "FFX_PppHandler_SclAccele_SetFromGlobals"},
    ]
}
r = c.call_tool(13337, "rename", {"batch": batch})
print("RENAME:", json.dumps(r, indent=2, ensure_ascii=False))

cmt1 = (
    "pppSclAccele handler (entry 0xC3A550 idx2 +0x08; keyhole 0xC860F8 idx3 +0x08; "
    "alias 0xC3BC00 idx147 +0x08; HostContextTable 0xC64CE8). 3 args: (ctx, program, entry). "
    "Guard FFX_PppStatePausedFlag. Match: program[0] == ctx[+12]. "
    "Window: program+16..+28 = f32[4] delta (16B). "
    "Double layer: layerB (node[1]+a1+160..172) += delta; layerA (node[0]+a1+160..172) += layerB "
    "-> aceleracao (B cresce linear, A quadratico). "
    "Antigo nome enganoso FieldMap_AccumulateDoubleLayerDelta."
)
cmt2 = (
    "pppSclAccele +0x1C/+0x20 (entry 0xC3A550 idx2; keyhole idx3): seta layerB "
    "node[1]+a1+160..172 a partir de flt_C0A004..flt_C0A010 (estado inicial do bone). "
    "Mesmo padrao do FFX_PppHandler_Accele_SetFromGlobalQ (0x75B900). "
    "Antigo nome enganoso FFX_FieldMap_SetPositionFromGlobalC."
)
code = (
    "import idc\n"
    f"idc.set_cmt(0x75B9F0, {cmt1!r}, 0)\n"
    f"idc.set_cmt(0x75BAC0, {cmt2!r}, 0)\n"
    "print('comments set OK')\n"
)
r2 = c.call_tool(13337, "py_eval", {"code": code})
print("COMMENTS:", json.dumps(r2, indent=2, ensure_ascii=False))

code3 = "import idc; print(idc.get_func_name(0x75B9F0)); print(idc.get_func_name(0x75BAC0))"
r3 = c.call_tool(13337, "py_eval", {"code": code3})
print("VERIFY:", json.dumps(r3, indent=2, ensure_ascii=False))
