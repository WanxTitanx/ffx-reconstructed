# FFX.exe Decompilation — Batch 16 (VP8/VP9 Video Decoder)

**Database:** ffxoficial_COPY.i64 (session ffx-session-002)
**Date:** 2026-07-28
**Scope:** `FFX_Video_*` (107) + `FFX_VpxFrameDecoder_*` (201) — libvpx statically compiled

---

## Summary

FFX HD PC cutscenes are **VP8/VP9 video streams** stored in VBF archives, decoded at runtime by a **statically-compiled libvpx** port. The decoder has **308 functions** split into two layers: (1) `FFX_VpxFrameDecoder_*` (201 funcs) = the **frame decoder** (header parsing, macroblock reconstruction, reference frames), and (2) `FFX_Video_*` (107 funcs) = **SIMD-optimized primitives** (motion compensation, deblocking filter, SAD, DCT). Both layers are heavily optimized with **MMX/SSE2** intrinsics.

| Metric | Value |
|--------|-------|
| Total functions | 308 (201 VPX + 107 Video) |
| Codec | libvpx (VP8/VP9) statically compiled, MSVC 2012 |
| Decoder entry | `FFX_VpxFrameDecoder_Entry` @ 0x40ab90 (~500B) |
| Frame header | `FFX_VpxFrameDecoder_ParseFrameHeader` @ 0x409970 (~200B) |
| Macroblock | `FFX_VpxFrameDecoder_ProcessMacroblock` @ 0x40e6f0 |
| Tile threading | `FFX_VpxFrameDecoder_DecodeTile` @ 0x40a080 |
| SIMD | MMX (deblock), SSE2 (3-plane), MMX (SAD, ME) |

`★ Insight ─────────────────────────────────────`
- **libvpx versão 2012** — compilado com VS2012 toolchain, mesmo que o resto do executável. Otimizações SIMD manuais (MMX/SSE2) em vez de auto-vectorizadas. Isso data o port de ~2012-2013.
- **setjmp3 para recovery de erro** — `FFX_VpxFrameDecoder_Entry` usa `_setjmp3` (intrínseco MSVC) para recovery de erros de decoding. Se `DecodeFrame` falha, o longjmp restaura o estado e libera os frames de referência. É **tolerante a falhas** — cutscenes corrompidas não crasham, só pulam frames.
- **4 frames de referência** — slot array de 4 entries (índice 538-541). O decoder VP8/VP9 mantém até 4 frames de referência simultâneos para inter-prediction (mais que H.264 que tem 2).
- **SIMD dispatch layer** — `FFX_Video_McCompensateDispatch` roteia para implementações MMX ou SSE2 baseado em runtime CPUID. Todos os primitivos SAD têm wrapper MMX.
`─────────────────────────────────────────────────`

---

## Architecture: libvpx Static Port

```
VBF Archives (VP8/VP9 stream data)
    │
    └── FFX_VpxFrameDecoder_Entry (0x40ab90)
        │
        ├── FFX_VpxFrameDecoder_ParseFrameHeader (0x409970)
        │   ├── Reads sync bytes 0x9D, 0x01, 0x2A
        │   ├── Extracts width/height from 0x3FFF mask
        │   └── Returns error code or 0 on success
        │
        ├── FFX_VpxFrameDecoder_DecodeFrame (0x410830)
        │   ├── FFX_VpxFrameDecoder_DecodeTile (0x40a080)
        │   ├── FFX_VpxFrameDecoder_ProcessMacroblock (0x40e6f0)
        │   │   ├── InitTokenProbs (0x40f320)
        │   │   ├── InitMotionVectorProbs (0x40f450)
        │   │   ├── IntraFrameModeInit (0x40f930)
        │   │   └── InterFrameModeInit (0x40f9f0)
        │   └── FFX_VpxFrameDecoder_LoopFilterMacroblock (0x40e860)
        │
        ├── FFX_VpxFrameDecoder_UpdateRefFrames (0x40a960)
        │   └── FFX_VpxFrameDecoder_ValidateReferenceFrame (0x40a780)
        │
        └── FFX_VpxFrameDecoder_PostProcessFrame (0x40ad40)
            └── FFX_Video_FrameBorderExtend (0x415120)
```

---

## Key Function Analysis

### 1. FFX_VpxFrameDecoder_ParseFrameHeader (0x409970, ~200B)

Parses the VP8/VP9 frame header — the first function called on every video frame:

```c
int FFX_VpxFrameDecoder_ParseFrameHeader(
    BYTE *data, unsigned int size, DWORD *outWidthHeight,
    void (*callback)(int, BYTE*, BYTE*, int), int cbData)
{
    BYTE *ptr = data;
    int result = 0;
    BYTE buf[12];

    if (&ptr[size] <= ptr) return 8;    // invalid size
    
    // Optional copy callback (for header data)
    if (callback) {
        int n = (size > 10) ? 10 : size;
        callback(cbData, data, buf, n);
        ptr = buf;
    }
    
    outWidthHeight[3] = 0;  // clear version byte
    
    if (size < 10 || (*ptr & 1) != 0) return 5;  // error
    
    outWidthHeight[3] = 1;  // set "valid header" flag
    
    // Magic bytes: 0x9D 0x01 0x2A at offset 3-5
    if (ptr[3] == 0x9D && ptr[4] == 0x01 && ptr[5] == 0x2A) {
        outWidthHeight[1] = *(WORD*)(ptr + 6) & 0x3FFF;  // width (14-bit)
        outWidthHeight[2] = *(WORD*)(ptr + 8) & 0x3FFF;  // height (14-bit)
        
        if (outWidthHeight[1] == 0 || outWidthHeight[2] == 0)
            return 5;  // zero size = error
        
        return 0;  // OK
    }
    return 5;  // invalid magic
}
```

**Magic bytes:** `0x9D 0x01 0x2A` = VP8 frame sync code. The `0x3FFF` mask gives 14-bit width/height (max 16383px).

**Note:** VP9 uses different sync bytes (`0x83 0x01 0x2A`). FFX HD likely uses VP8 (wider compatibility in 2012).

### 2. FFX_VpxFrameDecoder_Entry (0x40ab90, ~500B)

The **main decoder entry point** — orchestrates frame decoding with error recovery:

```c
int FFX_VpxFrameDecoder_Entry(ctx, a2, a3) {
    v4 = ctx;                     // decoder context
    v5 = ctx + 980;               // frame data area
    v5[0] = 0;                    // clear error flag
    
    result = FFX_VpxFrameDecoder_ReleaseFrame(ctx);  // release previous frame
    
    if (result > 0) {
        // Find free reference frame slot (max 4)
        for (i = 0; i < 4; i++) {
            if (!ctx->refFrameInUse[i]) break;
        }
        ctx->refFrameInUse[i] = 1;
        ctx->currentSlot = i;
        
        // Map 4 reference frame pointers
        ctx->refFrames[0] = &base[27 * ctx->slotOrder[0] + 430];
        ctx->refFrames[1] = &base[27 * ctx->slotOrder[1] + 430];
        ctx->refFrames[2] = &base[27 * ctx->slotOrder[2] + 430];
        ctx->refFrames[3] = &base[27 * ctx->slotOrder[3] + 430];
        
        // setjmp for error recovery
        if (setjmp3(ctx->jmpBuf, 0)) {
            // Error path: mark corrupt, free slot
            ctx->errState = 1;
            ctx->refFrameInUse[ctx->currentSlot]--;
        } else {
            // Normal path: decode the frame
            int ret = FFX_VpxFrameDecoder_DecodeFrame(ctx);
            
            if (ret >= 0) {
                if (!FFX_VpxFrameDecoder_UpdateRefFrames(ctx)) {
                    // Success! Set output dimensions
                    ctx->outWidth = a2;
                    ctx->outHeight = a3;
                }
            } else {
                // Decode failure: free the slot
                ctx->refFrameInUse[ctx->currentSlot]--;
            }
        }
        
        // Clear setjmp state
        ctx->processing = 0;
        return ret;
    }
    return result;
}
```

The use of `setjmp3` (MSVC-specific intrínseco) instead of `setjmp`/`longjmp` padrão indica que a codebase original PS3 usava o próprio setjmp do SDK.

### 3. FFX_Video_McCompensateDispatch (0x417940)

Dispatcher para motion compensation — roteia entre 2 implementações:

- `FFX_Video_McCompensate_DualSSE` (0x417a00) — SSE2 dual-issue
- `FFX_Video_McCompensate_ShuffleSSE` (0x417a30) — SSE2 shuffle

### 4. FFX_Video_DeblockFilter (3 variantes)

```c
FFX_Video_DeblockFilter_MMX_3plane  (0x417a60)  // MMX path
FFX_Video_DeblockFilter_SSE2_3plane (0x417ac0)  // SSE2 path
FFX_Video_DeblockFilter_3plane      (0x417ce0)  // auto-dispatch
```

O loop filter tem **3 implementações**: MMX legado, SSE2 rápido, e auto-dispatch que escolhe baseado em CPUID.

### 5. SAD (Sum of Absolute Differences) primitives

16 funções SAD para motion estimation:

| Função | Address | Descrição |
|--------|---------|-----------|
| `FFX_Video_SAD_BlockDiff_MMX_wrapper` | 0x417ee0 | Block diff SAD |
| `FFX_Video_SAD_QuarterPel_MMX_wrapper` | 0x417f20 | Quarter-pel search |
| `FFX_Video_SAD_HalfPel_H_MMX` | 0x4180b0 | Half-pel horizontal |
| `FFX_Video_SAD_HalfPel_V_MMX` | 0x418110 | Half-pel vertical |
| `FFX_Video_SAD_Weighted_MMX_wrapper` | 0x418180 | Weighted SAD |

---

## Key Data Flow

```
Frame Data (compressed stream)
    │
    ▼
ParseFrameHeader → width, height, version
    │
    ▼
InitFrame → aloca buffers, init probabilidades de entropia
    │
    ├─ IntraFrameModeInit (keyframe)
    └─ InterFrameModeInit (delta frame)
    │
    ▼
ProcessMacroblock (para cada macrobloco 16×16)
    │
    ├─ InitTokenProbs → probabilidades de tokens
    ├─ InitMotionVectorProbs → probabilidades de MV
    ├─ Decodifica coeficientes DCT
    ├─ TransformBlock_DCT → IDCT inversa
    ├─ McCompensateDispatch → motion compensation
    └─ LoopFilterMacroblock → deblocking filter
    │
    ▼
UpdateRefFrames → atualiza pool de 4 reference frames
    │
    ▼
PostProcessFrame → FrameBorderExtend + color transform
    │
    ▼
Frame YUV → Renderizado como textura via PhyreEngine
```

---

## Key Findings

1. **308 funções libvpx** estaticamente compiladas — 201 frame decoder + 107 SIMD primitives.

2. **Magic `0x9D 0x01 0x2A`** — VP8 sync bytes. 14-bit width/height (max 16383px).

3. **setjmp3 para error recovery** — frames corrompidos não crasham. Meta: tolerância a falhas.

4. **4 reference frame slots** — VP8/VP9 inter-prediction com pool de 4 frames.

5. **SIMD dispatch layer** — MMX/SSE2 com auto-dispatch via CPUID. Multiplas implementações do mesmo primitivo.

6. **16+ funções SAD** — motion estimation totalmente otimizada em MMX.

7. **3 implementações de deblock filter** — MMX legado, SSE2 rápido, auto-dispatch.

8. **Formato YUV** — saída do decoder é YUV420, convertido para RGB via PhyreEngine shader.

9. **Tile-based decoding** — `DecodeTile` + `InitTileContext` + `InitTileWorkerData` para decoding multi-threaded.

10. **Sync bytes em offset 3-5** — cabecalho fixo de 10 bytes.

---

**Next batch:** Cross-batch PhyreEngine architecture synthesis.