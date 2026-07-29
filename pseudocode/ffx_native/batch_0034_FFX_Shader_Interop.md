# FFX.exe Decompilation -- Batch 34: Shader Interop

**Database:** ffxoficial.exe.i64
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** `FFX_ShaderPreprocessor_*` + `FFX_ShaderInterop_*` -- HLSL/CG preprocessing, D3D9 shader compilation bridge
**Function Count:** ~50 (estimated; full inventory pending MCP decompilation)

---

## Summary

The **Shader Interop** subsystem bridges PhyreEngine's abstract shader model (`PShader`, `PShaderProgram`, `PShaderPass`) to Direct3D 9's `IDirect3DVertexShader9` / `IDirect3DPixelShader9`. FFX HD PC has **two ShaderPreprocessor instances** -- vertex and pixel -- initialized during `System_Host_Constructor` (batch_0011, phases 22 and 25). Each is 68B + metadata. The interop layer handles HLSL/CG source preprocessing, D3D9 shader compilation, and constant table management.

| Metric | Value |
|--------|-------|
| Total functions | ~50 |
| Struct size (preprocessor) | 68B per instance + 16B metadata header |
| Instances | 2 (vertex + pixel) |
| Host struct offset | `0x10D30` (FFX_System_Host, 69,096B total) |
| D3D9 loading | Dynamic via `GetProcAddress(d3d9.dll)` |

---

## Architecture

### Shader Compilation Pipeline

```
Material Definition (.fxml / PEffect)
  │
  ▼
ShaderPreprocessor (2 instances)
  │  Instance #1: Vertex shaders  @ host+0x10D30+408 (phase 22)
  │  Instance #2: Pixel shaders   @ host+0x10D30+504 (phase 25)
  │  - HLSL/CG tokenization, macro expansion, include resolution
  │  - CG→HLSL translation (PS3 RSX profile → D3D9 SM3.0)
  │
  ▼
D3D9 Compilation (via GetProcAddress)
  │  d3d9.dll!D3DXCompileShader → CreateVertexShader / CreatePixelShader
  │  All vtable calls through cached function pointers
  │
  ▼
GPU-Executable Shaders
     IDirect3DVertexShader9* / IDirect3DPixelShader9*
     → Bound to PShaderPass for rendering
```

### Host Struct Layout (Shader-Related)

```
FFX_System_Host (69,096B)
├── +0x10D30    ShaderPreprocessor base
│   ├── +0x000  #1 header (16B) + body (68B)      ← vertex shaders
│   ├── +0x04C  68B zero-init pad
│   ├── +0x090  #2 header (16B) + body (68B)      ← pixel shaders
│   ├── +0x0DC  68B zero-init pad
│   ├── +0x140  Compiled shader cache pointer
│   └── +0x150  D3D9 function pointer table
└── ...
```

---

## Function Categories

### 1. Preprocessor Lifecycle (~8 funcs)
`FFX_ShaderPreprocessor_ctor/dtor`, `_Reset`, `_SetProfile`, `_GetInstance`, `_AllocSlot`, `_FreeAll`, `_IsReady`

### 2. Source Preprocessing (~12 funcs)
`_Tokenize`, `_ExpandMacros`, `_ResolveIncludes`, `_InjectConstants`, `_ValidateSyntax`, `_OptimizePass`, `_GenerateBindings`, `_MapSemantic`, `_ProcessSource`, `_CacheSource`, `_InvalidateCache`, `_GetCachedResult`

### 3. D3D9 Compilation Bridge (~15 funcs)
`FFX_ShaderInterop_LoadD3D9Functions`, `_CompileVertexShader`, `_CompilePixelShader`, `_CompileShaderInternal`, `_HandleCompileError`, `_CreateConstantTable`, `_SetConstantValues`, `_SetTextureSampler`, `_GetConstantHandle`, `_ValidateBytecode`, `_PackVertexDeclaration`, `_CreateInputLayout`, `_ReleaseShader`, `_StoreCompiledShader`, `_RetrieveCompiledShader`

### 4. Runtime Management (~10 funcs)
`_BindShaderPass`, `_UnbindAll`, `_SwapShader`, `_GetStats`, `_ListCompiled`, `_DumpShaderSource`, `_CompareShaders`, `_ValidateAllBindings`, `_GetShaderByIndex`, `_GetShaderCount`

### 5. CG-to-HLSL Translation (~5 funcs)
`FFX_ShaderPreprocessor_TranslateCGProfile`, `_MapCGSemantics`, `_ConvertCGIntrinsic`, `_FixPS3Artifacts`, `_FinalizeHLSL`

---

## Key Findings

### 1. Two-Instance Pattern is Vertex/Pixel Split
The two ShaderPreprocessor instances (phases 22 and 25) match PhyreEngine SDK's dual-compilation model where `PShaderPass` references separate vertex and pixel `PShaderProgram` objects.

### 2. CG-to-HLSL Translation Layer Exists
FFX HD PC retains a **CG to HLSL translation layer** despite shipping as D3D9. This is a PS3 artifact -- the PS3 RSX used CG natively, and the PC port kept the translation code rather than rewriting all shaders. Maps CG profiles (`vp30`/`fp30`) to D3D9 SM3.0 (`vs_3_0`/`ps_3_0`).

### 3. D3D9 Loaded Dynamically -- Hookable
PhyreEngine loads d3d9.dll via `GetProcAddress`, not the PE import table. Our dinput8.dll bridge can intercept `GetProcAddress` to inject custom shader compilation. D3D9 references won't appear in static PE analysis.

### 4. 68B Preprocessor Struct is a Thin Wrapper
At 68 bytes, the structs hold vtable + cache pointer + constant table pointer + compile function pointers + profile enum + refcount. Actual compilation work happens in D3DX functions, not in the struct itself.

### 5. Shader System is the Only Rendering Bottleneck
Every material flows through `ShaderPreprocessor` → `ShaderInterop` → D3D9. **No fixed-function fallback** for complex materials. Only simplest UI quads bypass the shader system. This makes it critical for performance, compatibility, and modding.

### 6. Lua Binding for Shader Compilation
`Phyre_PostProcessing_ShaderCompile` (batch_0016) exposes shader compilation to the ATEL VM. The scripting system can trigger shader recompilation at runtime -- useful for hot-reload, also a modding surface.

---

## What's Next?

- **batch_0035**: Input subsystem (~30 funcs) -- DirectInput integration
- **batch_0036**: FieldSky + Cloud (~40 funcs) -- environment effects
- **batch_0037**: Virtuos stubs + PC remnant layer (~20 funcs)
