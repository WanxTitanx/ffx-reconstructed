# FFX.exe Decompilation — Batch 18 (Battle UI HUD)

**Database:** ffxoficial_COPY.i64 (session ffx-session-002)
**Date:** 2026-07-28
**Scope:** `FFX_BtlUI_*` (370 funcs) — battle HUD rendering, cursor ring, HP/MP bars, target overlay

---

## Summary

The **Battle UI** layer has **370 functions** covering **cursor ring** (CTB turn indicator), **HUD bars** (HP/MP/Overdrive), **target overlay** (selection diamond), **command menu** (navigate input), and **render command** dispatch. It reads from `FFX_System_Host` (batch_0011) via the cursor ring state initialized at boot.

| Subsystem | Functions | Key Functions |
|-----------|-----------|---------------|
| Cursor Ring (CTB) | ~50 | `InitCursorRingState`, `SetupCursorRing`, `DestroyCursorRingArray`, `FreeCursorRingAllocation` |
| HUD Bars | ~100 | `HudDrawTopGaugeWrapper`, `HudBar_UpdateVisibility`, `HudBar_ResetScale` |
| Target Overlay | ~60 | `HudTarget_FadeInWrapper`, `HudTarget_InitRender`, `HudTargetAnimateAndUpdateTexAnim` |
| Render Command | ~40 | `RenderCmd_SetParam`, `DrawHudAtlasQuad`, `SetHudDrawParam`, `GetHudDrawParam` |
| Icon/Condition | ~30 | `HudIconCondition_Iterate`, `HudIconFunction_Guarded` |
| String/Text | ~30 | `InitHudPairString`, `CreateStringHandle` |
| Navigation | ~20 | `HudCommand_NavigateWrapper` |
| State/Misc | ~40 | `CopyActorAtbMpState`, `ClearHudActorBuffer`, `SetCharHudBorderParam` |

`★ Insight ─────────────────────────────────────`
- **Cursor ring é CTB visual** — `FFX_BtlUI_InitCursorRingState` é chamado DENTRO de `FFX_System_Host_Constructor` (batch_0011). O anel de turno CTB nao e so UI — e parte do singleton de cena.
- **RenderCommand é abstraction em cima de PhyreEngine** — `DrawHudAtlasQuad` + `SetHudDrawParam` usam as vtables de PEntity/PComponent (batch_0010) para renderizar quads HUD. E uma camada 2D em cima do renderizador 3D.
- **HudIconCondition_Iterate + HudIconFunction_Guarded = systema de condicoes** — parece validar se um icone HUD deve aparecer (condicao: tem habilidade? tem MP?).
`─────────────────────────────────────────────────`

---

## Subsystem Analysis

### 1. Cursor Ring (CTB Turn Indicator)

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| `InitCursorRingState` | 0x64d070 | ~100B | Init cursor ring state (called from Host Constructor) |
| `InitCursorRingState2` | 0x64d720 | ~100B | Supplemental init |
| `InitCursorBufferState` | 0x64d7d0 | ~100B | Init render buffer for cursors |
| `SetupCursorRing` | 0x64d8e0 | ~500B | Build cursor ring display list |
| `FreeCursorRingAllocation` | 0x636430 | ~80B | Free cursor ring memory |
| `DestroyCursorRingArray` | 0x6364c0 | ~100B | Destroy cursor ring array |
| `ReadActorPositionFromInstance` | 0x63b370 | ~200B | Read actor position for cursor placement |

`InitCursorRingState` initializes the **24-byte cursor ring state** inside `FFX_System_Host.m_cursorRingState`. The cursor ring renders **active turn order** — up to 8 actors with delay/ready icons.

### 2. HUD Bars (HP/MP/OD)

| Function | Address | Purpose |
|----------|---------|---------|
| `HudDrawTopGaugeWrapper` | 0x642970 | Draw top gauge (HP/MP bar container) |
| `HudBar_ResetScale` | 0x642e10 | Reset bar scale (on new turn) |
| `HudBar_UpdateVisibility` | 0x643070 | Show/hide bar based on actor state |
| `SetHudElementOverlayId` | 0x6438d0 | Set overlay ID for element |
| `SetCharHudBorderParam` | 0x643970 | Set character HUD border |
| `CopyActorAtbMpState` | 0x644bb0 | Copy ATB/MP state for HUD |
| `ClearHudActorBuffer` | 0x644c60 | Clear HUD buffer between scenes |
| `GetMpConditional` | 0x648a70 | Get MP with condition check |

### 3. Target Overlay

| Function | Address | Purpose |
|----------|---------|---------|
| `HudTarget_FadeInWrapper` | 0x647fc0 | Fade in target overlay |
| `HudTarget_InitRender` | 0x648160 | Init target render state |
| `HudTargetAnimateAndUpdateTexAnim` | 0x6486f0 | Animate target texture (pulse) |

### 4. Render Command Layer

| Function | Address | Purpose |
|----------|---------|---------|
| `RenderCmd_SetParam` | 0x630770 | Set render command parameter |
| `DrawHudAtlasQuad` | 0x6308e0 | Draw HUD quad from atlas |
| `SetHudDrawParam` | 0x638f40 | Set HUD draw parameter |
| `GetHudDrawParam` | 0x641500 | Get HUD draw parameter |
| `GetOverlayIfNotInitialized` | 0x63a1b0 | Get/init overlay |

---

## Key Finding: HUD as 2D Over PhyreEngine

The `DrawHudAtlasQuad` function is the **fundamental HUD primitive**:

```c
void FFX_BtlUI_DrawHudAtlasQuad(
    int atlasId, int quadIndex, 
    float x, float y, float w, float h,
    float u1, float v1, float u2, float v2,  // UV coords
    DWORD color, float alpha)
```

It renders a single textured quad from an **atlas texture** using UV coordinates. The quads are batched and submitted via PhyreEngine's `PRendering` vtable (from batch_0010).

The HUD is **not a separate 2D system** — it's built on PhyreEngine's 3D renderer, just with orthographic projection.

---

## Key Findings

1. **370 HUD functions** — 5 subsystems (cursor ring, bars, target, render, strings).
2. **Cursor ring init in Host Constructor** — CTB visual is part of system host.
3. **HUD usa PhyreEngine rendering** — não é sistema 2D separado.
4. **Atlas-based quads** — toda UI usa texture atlas com UV coords.
5. **Condition system** — ícones HUD têm condições (tem MP? tem ability?).

---

**Next batch:** Cross-batch PhyreEngine architecture synthesis.