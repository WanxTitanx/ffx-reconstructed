import ida_hexrays, ida_funcs, ida_name, ida_bytes, json

OUT = r"C:\Users\wande\Documents\ffx-editor-main\work\research_tools\ida_magic_runtime.c"

# (addr, label) — key magic runtime functions
TARGETS = [
    (0x9da420, "FFX_MagicFile_LoadDllByMagicId"),
    (0x9dae70, "FFX_MagicFile_PreloadAsync"),
    (0x80CD60, "FFX_Magic_RunRuntimeRootPhase_structural (EgoVM timeline interpreter)"),
    (0x80BEA0, "FFX_Magic_RunAuxRuntimeRootPass_structural (side-pass)"),
    (0xA72380, "FFX_MagicVm_PppOpcodeExecute"),
    (0x7170F0, "FFX_Render_PppProgramProcessor"),
    (0x729BA0, "FFX_Render_PppRenderLoop"),
    (0x8621C0, "FFX_SeSep_DispatchStateMachine"),
    (0x7A0560, "FFX_SeSep_ProcessTransitionQueue"),
    (0x79E8E0, "FFX_Battle_StartMagicEffectAndQueue"),
    (0x7FD710, "FFX_Magic_RegisterEffectUnitRuntimeRecord"),
    (0x7FD9A0, "FFX_Magic_MaterializeRuntimeRoot_structural"),
    (0x712D10, "FFX_MagicHost_ClassifyPppOpcodeByte"),
    (0x712080, "FFX_MagicHost_RelocatePppResourceBlob"),
    (0x7FD640, "FFX_MagicCoreOp_01_Param_structural"),
    (0x7F72F0, "FFX_MagicCoreOp_7F_DrawAndCommitVfx"),
    (0x7F7500, "FFX_MagicCoreOp_8B_ParticleFieldRender"),
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
    fp.write("// FFX.exe magic runtime decompilations — extracted via ida-pro-mcp py_exec_file\n")
    fp.write("// DB: F:/ffx-reconstructed/extras/ffxoficial.exe.i64 (FFX.exe, imagebase 0x400000)\n")
    fp.write("// Lane: PURE RESEARCH 2026-08-19 — nothing in FFXProjectEditor/ modified\n\n")
    fp.write("\n".join(results))

print("WROTE", OUT, "funcs:", len(TARGETS))
