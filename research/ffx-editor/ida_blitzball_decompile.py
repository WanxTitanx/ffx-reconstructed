import ida_hexrays, ida_funcs, ida_name

OUT = r"C:\Users\wande\Documents\ffx-editor-main\work\research_tools\ida_blitzball_runtime.c"

# (addr, label) — statically-anchorable FFX.exe functions relevant to the blitzball system
TARGETS = [
    (0x872E90, "FFX_Event_LoadObjResources (loads bltz event objects — blitzball scene entry)"),
    (0x6B9E10, "FFX_DebugUI_SystemStatusFormat (Full Blitz / Blitz Cheat debug flags)"),
    (0x6B9F60, "FFX_DebugFieldMapUI_Init (bltz map debug UI)"),
    (0x874BE0, "FFX_Ps3Data_ResolveEventObjectTexListPath (bltz0000/0005/0006/0200/0201 tex paths)"),
    (0x647F20, "FFX_Save_ValidateChecksum (save CRC validation — blitzball state rides in payload)"),
    (0x8B1400, "FFX_Save_ComputeCrc16 (save CRC-16/IBM-3740)"),
    (0x646CE0, "FFX_Save_ReadFile_CHAPPU (reads %02d.SAV)"),
    (0x877720, "FFX_Atel_DispatchNativeCall (ATEL native dispatch — no blitzball funcspace)"),
    (0x869D00, "FFX_Atel_FetchOpcode (ATEL opcode fetch)"),
    (0x86D660, "FFX_Atel_InitVmAndRegisterFuncspaces (funcspace registration — proves no blitzball ns)"),
    (0x785300, "FFX_SceneState_GetBase (SaveData getter &0x112CA90)"),
    (0x864180, "FFX_Field_EventParser_structural (ATEL interpreter — blitzball logic is ATEL script)"),
]

results = []
for addr, label in TARGETS:
    f = ida_funcs.get_func(addr)
    if not f:
        results.append(f"// ===== {label} @ {hex(addr)} — NOT A FUNCTION =====\n")
        continue
    name = ida_name.get_name(f.start_ea) or "sub_" + hex(f.start_ea)[2:]
    try:
        cf = ida_hexrays.decompile(f.start_ea)
        body = str(cf) if cf else "// decompile failed"
    except Exception as e:
        body = f"// decompile exception: {e}"
    results.append(f"// ===== {label} @ {hex(addr)} (name in DB: {name}, size {hex(f.size())}) =====\n{body}\n\n")

with open(OUT, "w", encoding="utf-8") as fp:
    fp.write("// ============================================================================\n")
    fp.write("// FFX.exe Blitzball RUNTIME — batch decompile (2026-08-19)\n")
    fp.write("// DB: F:/ffx-reconstructed/extras/ffxoficial.exe.i64 (FFX.exe, imagebase 0x400000)\n")
    fp.write("// Lane: PURE RESEARCH — nothing in FFXProjectEditor/ modified\n")
    fp.write("// NOTE: the blitzball MATCH ENGINE (physics/shot-tackle/AI) is native C++ reached by\n")
    fp.write("// scene transition and is NOT statically anchorable (no funcspace, no named funcs,\n")
    fp.write("// no string anchors, zero xrefs to the blitzball save region). These are the\n")
    fp.write("// statically-reachable functions that frame the blitzball system.\n")
    fp.write("// ============================================================================\n\n")
    fp.write("\n".join(results))

print("WROTE", OUT, "funcs:", len(TARGETS))
