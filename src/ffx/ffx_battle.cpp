// ============================================================================
// Forward declarations
int FFX_Btl_GetActorIndex(void *a);
void *FFX_Btl_GetActorByIndex(int i);
int FFX_Btl_GetActorHp(void *a);
int FFX_Btl_GetActorMp(void *a);
int FFX_Btl_GetActorMaxHp(void *a);
int FFX_Btl_GetActorMaxMp(void *a);
int FFX_Btl_GetActorOverdrive(void *a);
int FFX_Btl_GetActorTeam(void *a);

// ffx_battle.cpp — FFX Battle System Stubs
// Phase 3-E: FFX Game Stubs
// Source: Agent naming CSVs (waves 2–97), V03_orphans, R04_dead_code_reclassify
// Each stub includes address, xref count, and brief description.
// ============================================================================

#include "ffx_battle.h"
#include <stdlib.h>  // calloc, free
#include <string.h>  // memset
#include <math.h>    // cosf, sinf
#include "ffx_renderqueue.h"

// Forward declarations from other translation units (PhyreEngine memory)
extern void* FFX_Heap_Alloc(int size);
extern void  FFX_Heap_Free(void* ptr);
extern void  FFX_SmallArray_DtorLoop_B(void* base, int count);
extern void* FFX_Heap_AllocGameArenaDebugFill_wrapper(int size);

// Global battle context pointer (0xCCC81C)
#define BATTLE_CTX_PTR (*(void**)0xCCC81C)
#define BATTLE_CTX_HUD_PARAM_OFFSET 11232
// ============================================================================
// Static state for stub implementations (global battle state)
// In the original EXE these live at fixed addresses; here we approximate
// with module-level statics until struct layouts are known.
// ============================================================================
static int s_battleInputMode = 0;      // Battle input mode (menu/target/idle)
static int s_encounterActive = 0;      // Non-zero when a battle is active

// Forward declarations and constants
#define MAX_ACTORS 12
#define MAX_ACTION_QUEUE 16

typedef struct {
  int  cmdId;
  int  actorIdx;
  int  targetIdx;
  int  flags;
  int  cost;
  void *reserved[3];
} ActionEntry;

typedef struct {
  int   hp;
  int   maxHp;
  int   mp;
  int   maxMp;
  int   overdrive;
  int   overdriveMax;
  int   team;
  int   statusFlags;
  int   ctbTurns;
  int   animId;
  void *modelNode;
} ActorEntry;

// Simulated actor and action queue arrays (original EXE uses fixed addresses)
static ActorEntry s_actors[MAX_ACTORS] = {{{0}}};
static int s_actorCount = 0;
static ActionEntry s_actionQueue[MAX_ACTION_QUEUE] = {{{0}}};
static int s_actionQueueHead = 0;
static int s_actionQueueTail = 0;
static int s_actionQueueCount = 0;

// GaugeSlot type for HUD gauge registration
typedef struct {
  int   type;
  int   actor;
  float x;
  float y;
  int   active;
} GaugeSlot;
static GaugeSlot s_gauges[16] = {{{0}}};
static int s_gaugeCount = 0;

// ============================================================================
// FFX_BtlUI — Battle HUD System
// ============================================================================

// 0x636430 — xrefs: 3
void FFX_BtlUI_FreeCursorRingAllocation(void *pAlloc) {
  // Frees a cursor ring allocation from the battle UI ring buffer.
  // __thiscall: this = pAlloc
  // struct has ptr @0, size @4, capacity @8
  void **ppAlloc = (void **)pAlloc;
  if (ppAlloc && *ppAlloc) {
    FFX_Heap_Free(*ppAlloc);
    *ppAlloc = NULL;
    ppAlloc[1] = NULL; // size
    ppAlloc[2] = NULL; // capacity
  }
}

// 0x6364c0 — xrefs: 3
void FFX_BtlUI_DestroyCursorRingArray(void *pArray) {
  // Destroys the cursor ring array used for targeting rings in battle.
  // __thiscall: struct has ptr @0, count @4, capacity @8
  int *arr = (int *)pArray;
  if (arr && *arr) {
    FFX_SmallArray_DtorLoop_B((void *)*arr, arr[1]);
    FFX_Heap_Free((void *)*arr);
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;
  }
}

// 0x638f40 — xrefs: 5
void FFX_BtlUI_SetHudDrawParam(void *pHudDrawParam) {
  // Sets the HUD draw parameters for battle UI rendering.
  // Writes param to battle context at offset 11232 (0x2BE0).
  void *ctx = BATTLE_CTX_PTR;
  if (ctx) {
    ((int *)ctx)[11232 / 4] = (int)pHudDrawParam;
  }
}

// 0x63a1b0 — xrefs: 8
void *FFX_BtlUI_GetOverlayIfNotInitialized(void *pOverlayCtx) {
  // Returns overlay context if not yet initialized; used for lazy overlay
  // setup. Checks global flag at 0x12BCE74, initializes if not set.
  // Original: __cdecl FFX_BtlUI_GetOverlayIfNotInitialized(char a1)
  extern void FFX_BtlUI_GetOverlaySub_structural(int renderState, char flag);
  extern int g_renderState; // from dword_C90B08 (0xCCB9D8)

  static volatile char s_overlayInitialized = 0;
  if (!s_overlayInitialized) {
    FFX_BtlUI_GetOverlaySub_structural((int)&g_renderState, (char)(int)pOverlayCtx);
    s_overlayInitialized = 1;
  }
  return NULL;
}

// 0x63b370 — xrefs: 8
void FFX_BtlUI_ReadActorPositionFromInstance(void *pInstance, void *pOutPos) {
  // Reads actor world position from a battle instance struct.
  // Original: __cdecl FFX_BtlUI_ReadActorPositionFromInstance(int instance, float *outX, float *outY, float *outZ)
  // instance struct: field0 = flags (bit31=valid), field4 = object pointer chain
  // Position at: *(*(*(instance->field4)->vtable[7]) + 0x10/0x14/0x18)
  // pOutPos points to 3 consecutive floats (x,y,z).
  if (!pInstance || !pOutPos) return;
  int *inst = (int *)pInstance;
  if ((inst[0] & 0x7FFFFFFF) == 0) return;
  // Dereference chain: inst[1] -> [0] -> [7] -> +0x10/0x14/0x18
  int *objPtr = *(int **)inst[1];
  int *vtblEntry7 = *(int **)((int)objPtr + 28); // +28 = [7] in dword units
  int *modelPos = *(int **)vtblEntry7;
  float *out = (float *)pOutPos;
  out[0] = *(float *)((int)modelPos + 16);  // x
  out[2] = *(float *)((int)modelPos + 20);  // z (note: z stored before y in this struct)
  out[1] = *(float *)((int)modelPos + 24);  // y
}

// 0x641500 — xrefs: 13
void *FFX_BtlUI_GetHudDrawParam(void *pContext) {
  // Returns the HUD draw parameter struct for the battle UI context.
  // Reads from battle context at offset 11232 (0x2BE0).
  void *ctx = BATTLE_CTX_PTR;
  if (!ctx) return NULL;
  return (void *)((int *)ctx)[11232 / 4];
}

// 0x648160 — xrefs: 1
int FFX_BtlUI_HudTarget_InitRender(void) {
  // Initializes rendering resources for a HUD target element.
  // Returns 1 — render target system already initialized via D3D11.
  return 1;
}

// 0x648a70 — xrefs: 1
int FFX_BtlUI_GetMpConditional(void *pActor) {
  // Returns MP value with conditional logic (e.g., zero-check or cap).
  // Original: checks global flag, calls HudTarget_GetMp if set.
  // Stub: delegates to simple GetActorMp.
  extern int FFX_Btl_GetActorMp(void *pActor);
  return pActor ? FFX_Btl_GetActorMp(pActor) : 0;
}

// 0x642e10 — xrefs: 1
void FFX_BtlUI_HudBar_ResetScale(void *pHudBar) {
  // Resets the HUD bar scale to default (HP/MP/Overdrive bars).
  if (pHudBar) {
    ((float *)pHudBar)[0] = 1.0f; // scaleX
    ((float *)pHudBar)[1] = 1.0f; // scaleY
  }
}

// 0x6438d0 — xrefs: 1
void FFX_BtlUI_SetHudElementOverlayId(void *pElement, int overlayId) {
  // Sets the overlay ID for a HUD element (e.g., status icon overlay).
  if (pElement) {
    ((int *)pElement)[0] = overlayId;
  }
}

// 0x643970 — xrefs: 1
void FFX_BtlUI_SetCharHudBorderParam(void *pHud, int borderParam) {
  // Sets border rendering parameters for a character HUD element.
  if (pHud) {
    ((int *)pHud)[0] = borderParam;
  }
}

// 0x644030 — xrefs: 1
void FFX_BtlUI_InitHudPairString(void *pHudPair) {
  // Initializes a HUD pair string (label + value) for battle display.
  if (pHudPair) {
    memset(pHudPair, 0, 32); // approximate pair string size
  }
}

// 0x644c60 — xrefs: 1
void FFX_BtlUI_ClearHudActorBuffer(void *pBuffer) {
  // Clears the HUD actor buffer that contains per-actor HUD data.
  if (pBuffer) {
    memset(pBuffer, 0, 2048); // approximate HUD buffer size
  }
}

// 0x6f1730 — xrefs: 1
void FFX_BtlUI_HudTarget_Render(void *pTarget) {
  // Renders a HUD target ring — pulsing circular selection indicator.
  // Uses FFX_RenderQueue_PushRect to draw quads arranged in a ring.
  // Color: green for ally, red for enemy (based on target type flag).
  if (!pTarget) return;

  // Target struct layout (guaranteed by original):
  // [0] = type/flags, [4] = target x, [8] = target y, [12] = target radius
  int   *targetWords = (int *)pTarget;
  float *targetPos   = (float *)pTarget;

  int    flags   = targetWords[0];
  float  tx      = targetPos[1];
  float  ty      = targetPos[2];
  float  radius  = targetPos[3] > 0.0f ? targetPos[3] : 32.0f;

  // Determine team color: flag bit0 = enemy
  uint32_t ringColor = (flags & 1) ? 0x66FF4444 : 0x6644FF44;

  // Pulse using a static frame counter (oscillates radius ±8px)
  static unsigned int s_pulseTick = 0;
  s_pulseTick++;
  float pulse = sinf((float)(s_pulseTick % 360) * 0.0174532f) * 8.0f;
  float r = radius + pulse;
  float halfR = r * 0.5f;

  // Inner glow (semi-transparent filled circle)
  FFX_RenderQueue_PushRect(tx - halfR, ty - halfR, r, r,
      0x22000000 | (ringColor & 0x00FFFFFF),
      0x22000000 | (ringColor & 0x00FFFFFF));

  // Ring segments — 12 small quads arranged on the circle perimeter
  int segments = 12;
  float angleStep = 6.2831855f / segments;
  float segW = 6.0f + pulse * 0.25f;  // quad width oscillates with pulse
  float segH = 4.0f;

  for (int i = 0; i < segments; i++) {
      float a = i * angleStep;
      float sx = tx + cosf(a) * r - segW * 0.5f;
      float sy = ty + sinf(a) * r - segH * 0.5f;
      FFX_RenderQueue_PushRect(sx, sy, segW, segH, ringColor, ringColor);
  }

  // Highlight dots at cardinal directions (N, S, E, W)
  uint32_t dotColor = ringColor | 0x99000000; // brighter
  for (int i = 0; i < 4; i++) {
      float a = i * 1.5707963f; // 90° increments
      float dx = tx + cosf(a) * (r + 6.0f) - 3.0f;
      float dy = ty + sinf(a) * (r + 6.0f) - 3.0f;
      FFX_RenderQueue_PushRect(dx, dy, 6.0f, 6.0f, dotColor, dotColor);
  }
}

// 0x92c130 — xrefs: 4
int FFX_BtlUI_HudGaugeRegister(int gaugeType, int actorIndex, float x, float y) {
  // Registers a HUD gauge slot for rendering.
  // Stores gauge registration in a static array; returns slot index or -1.
  if (s_gaugeCount >= 16) return -1;
  s_gauges[s_gaugeCount].type   = gaugeType;
  s_gauges[s_gaugeCount].actor  = actorIndex;
  s_gauges[s_gaugeCount].x      = x;
  s_gauges[s_gaugeCount].y      = y;
  s_gauges[s_gaugeCount].active = 1;
  s_gaugeCount++;
  return s_gaugeCount - 1;
}

// 0x92c250 — xrefs: 3
void FFX_BtlUI_RenderHudGauges(void) {
  // Renders all active HUD gauges (HP bars, etc.) for the current frame.
  // Draws HP and MP bars for up to 7 party members using FFX_RenderQueue_PushRect.
  for (int i = 0; i < 7 && i < s_actorCount; i++) {
    float gy = 20.0f + i * 45.0f;

    // HP bar background
    FFX_RenderQueue_PushRect(10, gy, 200, 18, 0x33000000, 0x44000000);

    // HP bar fill (green -> yellow -> red based on %)
    int hp    = s_actors[i].hp;
    int maxHp = s_actors[i].maxHp;
    if (maxHp > 0) {
      float pct = (float)hp / (float)maxHp;
      if (pct > 1.0f) pct = 1.0f;
      if (pct < 0.0f) pct = 0.0f;
      uint32_t barColor;
      if      (pct > 0.50f) barColor = 0xFF22AA22; // green
      else if (pct > 0.25f) barColor = 0xFFAAAA22; // yellow
      else                   barColor = 0xFFAA2222; // red
      FFX_RenderQueue_PushRect(10, gy, 200.0f * pct, 18, barColor, barColor);
    }

    // MP bar background (smaller, below HP)
    FFX_RenderQueue_PushRect(10, gy + 20, 200, 8, 0x33000000, 0x44000000);

    // MP bar fill (blue)
    int mp    = s_actors[i].mp;
    int maxMp = s_actors[i].maxMp;
    if (maxMp > 0) {
      float pct = (float)mp / (float)maxMp;
      if (pct > 1.0f) pct = 1.0f;
      if (pct < 0.0f) pct = 0.0f;
      FFX_RenderQueue_PushRect(10, gy + 20, 200.0f * pct, 8, 0xFF2222AA, 0xFF2222AA);
    }
  }
}

// 0x92c4c0 — xrefs: 1
void FFX_BtlUI_HudGaugeDrawParty(int actorIndex, float cx, float cy) {
    // Draw a simple CTB ring (circle outline) for party members
    int segments = 20;
    float verts[3 * 22]; // max 22 vertices (center + 20 segments + 1)
    int vCount = 0;

    float radius = 30.0f;
    float angleStep = 6.28318f / segments; // 2*PI / segments

    for (int i = 0; i <= segments; i++) {
        float angle = i * angleStep;
        verts[vCount++] = cx + cosf(angle) * radius;
        verts[vCount++] = cy + sinf(angle) * radius;
        verts[vCount++] = 0;
    }

    // Draw as filled circle using render queue triangles
    // For now, draw a colored circle approximation
    FFX_RenderQueue_PushRect(cx - radius, cy - radius, radius * 2, radius * 2,
        0x44FFFFFF, 0x44FFFFFF);
}

// 0x92eee0 — xrefs: 1
void FFX_BtlUI_MagicSlotInitByType(void *pSlot, int typeId) {
  // Initializes a magic slot by type ID (white/black magic categories).
  // Stub: initializes magic slot by type
  if (!pSlot) return;
  ((int *)pSlot)[0] = typeId;
}

// ============================================================================
// FFX_BtlUI — HUD Gauge helpers
// ============================================================================

// 0x92c010 — xrefs: 1
void FFX_BtlUI_HudGauge_InitCircleDraw(void *pGauge) {
  // Initializes circle-draw parameters for a HUD gauge (e.g., CTB ring).
  // Stub: initializes circle draw parameters
  if (!pGauge) return;
  memset(pGauge, 0, 128);
}

// 0x92c0a0 — xrefs: 2
void FFX_BtlUI_HudGauge_ComputeCircularPattern(float cx, float cy, float radius,
    float startAngle, float endAngle, int segments,
    float *outVertices, int *outVertexCount) {
    // Computes vertex positions for a circular gauge pattern (HP/MP arcs).
    if (!outVertices || !outVertexCount || segments < 3) return;

    int vCount = 0;
    float angleStep = (endAngle - startAngle) / segments;

    // Center vertex
    outVertices[vCount++] = cx; // x
    outVertices[vCount++] = cy; // y
    outVertices[vCount++] = 0;  // unused

    // Arc vertices
    for (int i = 0; i <= segments; i++) {
        float angle = startAngle + i * angleStep;
        outVertices[vCount++] = cx + cosf(angle) * radius;
        outVertices[vCount++] = cy + sinf(angle) * radius;
        outVertices[vCount++] = 0;
    }

    *outVertexCount = vCount / 3;
}

// 0x92c1e0 — xrefs: 3
void FFX_BtlUI_HudGaugeScaleVec4(void *pVec, float sx, float sy, float sz,
                                 float sw) {
  // Scales a 4-component vector used for HUD gauge color/position offsets.
  if (!pVec) return;
  float *v = (float *)pVec;
  v[0] *= sx;
  v[1] *= sy;
  v[2] *= sz;
  v[3] *= sw;
}

// 0x92c340 — xrefs: 1
void FFX_BtlUI_HudGaugeDrawEnemy(void *pGaugeCtx) {
  // Draws the enemy-party HUD gauge group (enemy HP bars).
  // Stub: draws enemy gauges
  (void)pGaugeCtx;
}

// 0x92c3a0 — xrefs: 1
void FFX_BtlUI_HudGaugeDrawOverdrive(void *pOdGauge) {
  // Draws the Overdrive gauge for the active character.
  // Yellow/orange segmented bar with pulse when full.
  // Layout: [0]=actorIndex, [1]=maxOD, [2]=currentOD, [3-5]=pos/scale
  if (!pOdGauge) return;

  int   *odWords = (int *)pOdGauge;
  float *odFloats = (float *)pOdGauge;

  int    actorIdx = odWords[0];
  int    maxOD    = odWords[1] > 0 ? odWords[1] : 20;
  int    curOD    = odWords[2];
  float  x        = odFloats[3];
  float  y        = odFloats[4];
  float  scale    = odFloats[5] > 0.0f ? odFloats[5] : 1.0f;

  float barW = 180.0f * scale;
  float barH = 12.0f * scale;
  float segCount = (maxOD > 8) ? 8.0f : (float)maxOD;
  float segW = barW / segCount;
  float pct = (float)curOD / (float)maxOD;
  if (pct > 1.0f) pct = 1.0f;
  if (pct < 0.0f) pct = 0.0f;

  // Background bar
  FFX_RenderQueue_PushRect(x, y, barW, barH, 0x44000000, 0x44000000);

  // Fill segments — each segment lights up progressively
  int filledSegs = (int)(pct * segCount);
  static unsigned int s_odTick = 0;
  s_odTick++;
  bool isFull = (curOD >= maxOD);
  float pulse = isFull ? (sinf((float)(s_odTick % 360) * 0.0174532f) * 0.3f + 0.7f) : 1.0f;

  for (int i = 0; i < (int)segCount && i < filledSegs; i++) {
    float sx = x + i * segW;
    // Gradient: first segments dimmer, last brighter
    float bright = ((float)(i + 1) / segCount) * pulse;
    uint8_t r = (uint8_t)(255 * bright);
    uint8_t g = (uint8_t)(200 * bright);
    uint8_t b = (uint8_t)(40 * bright);
    uint32_t segColor = 0xFF000000 | (r << 16) | (g << 8) | b;
    FFX_RenderQueue_PushRect(sx + 1, y + 1, segW - 2, barH - 2, segColor, segColor);
  }

  // "OD" label
  if (isFull) {
    // Bright flash border when full
    uint32_t flash = (s_odTick % 30 < 15) ? 0xFFFFCC00 : 0xFFCC8800;
    FFX_RenderQueue_PushRect(x, y, barW, barH, flash, flash);
  }
}

// 0x92c550 — xrefs: 1
void FFX_BtlUI_HudGaugeDrawStatusIcons(void *pIconGroup) {
  // Draws status-effect icons below the character HUD gauge group.
  // Stub: draws status icons
  (void)pIconGroup;
}

// 0x92cb50 — xrefs: 1
void FFX_BtlUI_HudGaugeAnimateIn(void *pGauge) {
  // Plays the entrance animation for a HUD gauge (fade-in / scale-up).
  // Stub: HUD gauge entrance animation
  if (!pGauge) return;
  ((int *)pGauge)[2] = 1; // animate flag
}

// 0x92cbe0 — xrefs: 1
void FFX_BtlUI_HudGaugeAnimateOut(void *pGauge) {
  // Plays the exit animation for a HUD gauge (fade-out / scale-down).
  // Stub: HUD gauge exit animation
  if (!pGauge) return;
  ((int *)pGauge)[2] = 0; // animate flag
}

// 0x92cc70 — xrefs: 3
void FFX_BtlUI_HudGaugeUpdatePosition(void *pGauge, float x, float y) {
  // Updates the on-screen position of a HUD gauge element.
  // Assumes position is the first 8 bytes of the gauge struct.
  if (!pGauge) return;
  ((float *)pGauge)[0] = x;
  ((float *)pGauge)[1] = y;
}

// ============================================================================
// FFX_BtlUI — HUD Slot / Node System
// ============================================================================

// 0x92c750 — xrefs: 2
void FFX_BtlUI_InitSlotStruct(void *pSlot, int slotType) {
  // Initializes a HUD slot struct by type (magic/item/ability slot).
  // Stub: initializes HUD slot by type
  if (!pSlot) return;
  memset(pSlot, 0, 256);
  ((int *)pSlot)[0] = slotType;
}

// 0x92c600 — xrefs: 4
void FFX_BtlUI_TransformHudElement(void *pElement, void *pTransform) {
  // Applies a transformation (translate/rotate/scale) to a HUD element.
  // Stub: applies transformation to HUD element
  if (!pElement || !pTransform) return;
  memcpy(pElement, pTransform, 64);
}

// 0x92c6a0 — xrefs: 5
void FFX_BtlUI_UpdateNodeTransform(void *pNode) {
  // Recomputes the world transform for a HUD scene-graph node.
  // Stub: recomputes node transform
  if (!pNode) return;
  // Mark transform as dirty (will be recalculated on next frame)
  ((int *)pNode)[2] = 1;
}

// 0x92c7e0 — xrefs: 2
void FFX_BtlUI_SlotSetPosition(void *pSlot, float x, float y) {
  // Sets the screen-space position of a HUD slot element.
  if (!pSlot) return;
  ((float *)pSlot)[0] = x;
  ((float *)pSlot)[1] = y;
}

// 0x92c880 — xrefs: 2
void FFX_BtlUI_SlotSetScale(void *pSlot, float sx, float sy) {
  // Sets the scale factor of a HUD slot element.
  // Assumes struct layout: [x,y] @0, [sx,sy] @8
  if (!pSlot) return;
  ((float *)pSlot)[2] = sx;
  ((float *)pSlot)[3] = sy;
}

// 0x92c910 — xrefs: 1
void FFX_BtlUI_SlotSetColor(void *pSlot, int color) {
  // Sets the tint color (ARGB) of a HUD slot element.
  // Assumes color field at offset 16 (after pos[2]+scale[2] floats).
  if (!pSlot) return;
  ((int *)pSlot)[4] = color;
}

// 0x92c9a0 — xrefs: 2
void FFX_BtlUI_SlotSetVisibility(void *pSlot, int visible) {
  // Sets the visibility flag of a HUD slot (shown/hidden in battle UI).
  // Assumes visibility field at offset 20 (after pos[2]+scale[2]+color).
  if (!pSlot) return;
  ((int *)pSlot)[5] = visible;
}

// 0x92ca30 — xrefs: 3
void *FFX_BtlUI_NodeAllocate(void *pNodePool, int type) {
  // Allocates a HUD scene-graph node from the node pool by type.
  // Stub: allocates HUD scene-graph node from pool
  if (!pNodePool) return NULL;
  (void)type;
  return calloc(1, 256);
}

// 0x92cac0 — xrefs: 2
void FFX_BtlUI_NodeFree(void *pNodePool, void *pNode) {
  // Returns a HUD scene-graph node to the node pool.
  // Stub: returns HUD node to pool
  if (!pNodePool || !pNode) return;
  free(pNode);
}

// ============================================================================
// FFX_Battle — Battle State / Action Queue System
// ============================================================================

// 0x637100 — xrefs: 8
int FFX_Battle_IsEncounterActive(void) {
  // Returns non-zero if a battle encounter is currently active.
  return s_encounterActive;
}

// 0x6371a0 — xrefs: 12
int FFX_Battle_QueueAction(void *pAction) {
  // Queues a battle action for processing by the CTB/action system.
  // Stub: validates and stores to a simple circular buffer.
  if (!pAction || !s_encounterActive) return 0;
  ActionEntry *entry = (ActionEntry *)pAction;
  // Validate command ID range
  if (entry->cmdId < 0 || entry->cmdId > 255) return 0;
  // Note: original stores into game's internal action queue.
  // This stub accepts the action and returns success.
  s_battleInputMode = 2; // indicate action pending
  return 1;
}

// 0x637240 — xrefs: 4
void FFX_Battle_SetTargetPosition(void *pTarget, float x, float y, float z) {
  // Sets the world-space position for a battle target (cursor highlight).
  // Original: __thiscall copies 12 floats from source array.
  // Stub: stores position into target structure offsets 64004/64008/64012.
  if (!pTarget) return;
  float *pos = (float *)pTarget;
  pos[16001] = x;
  pos[16002] = y;
  pos[16003] = z;
}

// 0x6372e0 — xrefs: 6
void FFX_Battle_SetInputMode(int mode) {
  // Sets the battle input mode (menu navigation / target selection / idle).
  s_battleInputMode = mode;
}

// 0x637380 — xrefs: 4
int FFX_Battle_GetInputMode(void) {
  // Returns the current battle input mode.
  return s_battleInputMode;
}

// 0x637410 — xrefs: 3
void FFX_Battle_ClearEncounterState(void) {
  // Clears all encounter state data when leaving a battle.
  s_encounterActive = 0;
  s_battleInputMode = 0;
}

// 0x6374b0 — xrefs: 5
int FFX_Battle_GetCurrentCommand(void *pActor) {
  // Returns the currently-selected command ID for an actor.
  // Stub: returns first non-zero field from action queue entry.
  if (!pActor) return 0;
  int actorIdx = FFX_Btl_GetActorIndex(pActor);
  for (int i = 0; i < MAX_ACTION_QUEUE; i++) {
    if (s_actionQueue[i].actorIdx == actorIdx)
      return s_actionQueue[i].cmdId;
  }
  return 0;
}

// 0x637550 — xrefs: 3
void FFX_Battle_SetCurrentCommand(void *pActor, int cmdId) {
  // Sets the currently-selected command ID for an actor.
  if (!pActor) return;
  int actorIdx = FFX_Btl_GetActorIndex(pActor);
  if (actorIdx < 0) return;
  // Store as highest-priority pending action
  s_actionQueue[s_actionQueueTail].cmdId = cmdId;
  s_actionQueue[s_actionQueueTail].actorIdx = actorIdx;
  s_actionQueueTail = (s_actionQueueTail + 1) % MAX_ACTION_QUEUE;
  if (s_actionQueueCount < MAX_ACTION_QUEUE) s_actionQueueCount++;
}

// 0x6375f0 — xrefs: 2
int FFX_Battle_GetTargetCount(void *pAction) {
  // Returns the number of valid targets for a queued action.
  if (!pAction) return 0;
  // Stub: count non-negative target indices from action entry
  ActionEntry *entry = (ActionEntry *)pAction;
  return (entry->targetIdx >= 0) ? 1 : 0;
}

// 0x637690 — xrefs: 2
void *FFX_Battle_AllocateTargetList(int maxTargets) {
  // Allocates a target list for multi-target action resolution.
  // Stub: uses static buffer
  (void)maxTargets;
  static int s_targetBuf[12];
  return s_targetBuf;
}

// 0x637730 — xrefs: 2
void FFX_Battle_FreeTargetList(void *pTargetList) {
  // Frees a previously-allocated target list.
  (void)pTargetList;
  // Stub: static buffer, no-op
}

// 0x6377d0 — xrefs: 7
void *FFX_Battle_ResolveTarget(void *pAction, int slot) {
  // Resolves the actor pointer for a given target slot in an action.
  if (!pAction) return NULL;
  ActionEntry *entry = (ActionEntry *)pAction;
  int idx = entry->targetIdx;
  if (slot > 0) idx += slot; // multi-target offset
  return FFX_Btl_GetActorByIndex(idx);
}

// 0x637870 — xrefs: 5
int FFX_Battle_ProcessActionQueue(void) {
  // Processes the next action in the battle action queue (CTB tick).
  if (s_actionQueueCount == 0) return 0;
  ActionEntry *entry = &s_actionQueue[s_actionQueueHead];
  // Stub: validate target is alive, apply action effects
  void *target = FFX_Btl_GetActorByIndex(entry->targetIdx);
  if (target) {
    int hp = FFX_Btl_GetActorHp(target);
    if (hp > 0) {
      // Action processing would occur here
      s_encounterActive = 1;
    }
  }
  s_actionQueueHead = (s_actionQueueHead + 1) % MAX_ACTION_QUEUE;
  s_actionQueueCount--;
  return 1;
}

// 0x637910 — xrefs: 3
int FFX_Battle_ValidateAction(void *pAction) {
  // Validates that a queued action is still legal (target alive, MP
  // sufficient).
  if (!pAction) return 0;
  ActionEntry *entry = (ActionEntry *)pAction;
  // Check target is alive
  void *target = FFX_Btl_GetActorByIndex(entry->targetIdx);
  if (!target) return 0;
  if (FFX_Btl_GetActorHp(target) <= 0) return 0;
  // Check source has enough MP
  void *source = FFX_Btl_GetActorByIndex(entry->actorIdx);
  if (!source) return 0;
  if (FFX_Btl_GetActorMp(source) < entry->cost) return 0;
  return 1;
}

// 0x6379b0 — xrefs: 3
int FFX_Battle_ComputeActionCost(void *pAction) {
  // Computes the MP/HP cost for an action before execution.
  if (!pAction) return 0;
  ActionEntry *entry = (ActionEntry *)pAction;
  // Stub: actions with cmdId >= 100 cost 10 MP, others cost 0
  entry->cost = (entry->cmdId >= 100) ? 10 : 0;
  return entry->cost;
}

// ============================================================================
// FFX_Encounter — Encounter/Event Trigger System
// ============================================================================

// 0x63b3f0 — xrefs: 9
int FFX_Encounter_CheckAnyInstancePassesTrigger(void *pTrigger,
                                                void **ppInstances, int count) {
  // Checks if any instance in the list passes the encounter trigger conditions.
  // Original: __cdecl FFX_Encounter_CheckAnyInstancePassesTrigger(_DWORD *a1)
  // Iterates instances array and tests each for frustum visibility.
  // struct has field0 = count (bit31=valid), field4 = instances array pointer
  extern int FFX_Encounter_TestFrustumCull(int renderState, int instancePtr);

  if (!pTrigger) return 0;
  int *trig = (int *)pTrigger;
  int instanceCount = trig[0] & 0x7FFFFFFF;
  if (instanceCount == 0) return 0;
  int *instances = (int *)trig[1];
  for (int i = 0; i < instanceCount; i++) {
    int instancePtr = instances[i];
    if (FFX_Encounter_TestFrustumCull(0, instancePtr))
      return 1;
  }
  return 0;
}

// 0x82e280 — xrefs: 3
int FFX_Encounter_IsEventEncounterType(void *pEncounter, int type) {
  // Checks if the encounter is of a specific event-driven encounter type.
  if (!pEncounter) return 0;
  int *enc = (int *)pEncounter;
  return (enc[2] == type) ? 1 : 0;
}

// 0x82e2a0 — xrefs: 2
int FFX_Encounter_EvaluateDistanceTrigger(void *pEncounter, void *pPlayerPos) {
  // Evaluates distance-based triggers for proximity encounters.
  (void)pPlayerPos;
  if (!pEncounter) return 0;
  return s_encounterActive ? 1 : 0;
}

// 0x830c10 — xrefs: 1
void FFX_Encounter_ReleaseInstanceAttachments(void *pInstance) {
  // Releases attachment resources for a battle instance.
}

// 0x831500 — xrefs: 1
void FFX_Encounter_UpdateEncounterMode(void *pEncounter, int mode) {
  // Updates the encounter mode state machine (idle/triggered/active).
  if (!pEncounter) return;
  int *enc = (int *)pEncounter;
  enc[3] = mode;
  s_encounterActive = (mode != 0) ? 1 : 0;
}

// 0x833720 — xrefs: 1
int FFX_Encounter_FindAndFlagInstance(void *pEncounter, int instanceId) {
  // Finds an instance by ID and flags it for encounter processing.
  if (!pEncounter) return 0;
  s_encounterActive = 1;
  return instanceId;
}

// ============================================================================
// FFX_Encounter — Field Override System
// ============================================================================

// 0x834000 — xrefs: 4
int FFX_Encounter_ResolveFieldOverrideOrDefault(void *pEncounter) {
  // Resolves the field override for an encounter, falling back to default.
  // Currently returns -1 (no override) since struct layout is unknown.
  return -1;
}

// 0x834090 — xrefs: 3
int FFX_Encounter_GetFieldOverride(void *pEncounter) {
  // Returns the field-override ID if set, or -1 if no override is active.
  return -1;
}

// 0x834120 — xrefs: 2
void FFX_Encounter_SetFieldOverride(void *pEncounter, int fieldOverride) {
  // Sets a field-override ID to redirect the encounter to a different field.
  // Requires struct layout to store; currently a no-op.
}

// 0x8341b0 — xrefs: 5
int FFX_Encounter_GetCurrentField(void *pEncounter) {
  // Returns the current field ID where the encounter is taking place.
  return 0;
}

// 0x834240 — xrefs: 3
void FFX_Encounter_SetCurrentField(void *pEncounter, int fieldId) {
  // Sets the current field ID for the encounter context.
  // Requires struct layout to store; currently a no-op.
}

// 0x8342d0 — xrefs: 2
int FFX_Encounter_GetFormationOverride(void *pEncounter) {
  // Returns the formation override ID, or -1 if none is set.
  return -1;
}

// 0x8343f0 — xrefs: 2
int FFX_Encounter_GetMusicOverride(void *pEncounter) {
  // Returns the music-track override ID, or -1 if none is set.
  return -1;
}

// 0x834480 — xrefs: 2
void FFX_Encounter_SetMusicOverride(void *pEncounter, int trackOverride) {
  // Sets a music-track override for the encounter (BGM replacement).
  // Requires struct layout to store; currently a no-op.
}

// ============================================================================
// FFX_Battle — Battle Init / Shutdown / Memory Management
// ============================================================================

// 0x637a50 — xrefs: 2
void *FFX_Battle_AllocateContext(void) {
  // Allocates the top-level battle context struct.
  return calloc(1, 4096); // approximate total battle context size
}

// 0x637af0 — xrefs: 1
void FFX_Battle_FreeContext(void *pCtx) {
  // Frees the top-level battle context struct and all sub-resources.
  free(pCtx);
}

// 0x637b90 — xrefs: 2
int FFX_Battle_InitContext(void *pCtx) {
  // Initializes the battle context to default state (no encounter loaded).
  // Zero-initialize the context to reset all fields.
  if (pCtx) {
    memset(pCtx, 0, 4096);
  }
  return 0;
}

// 0x637c30 — xrefs: 1
void FFX_Battle_ShutdownContext(void *pCtx) {
  // Tears down the battle context, releasing all active allocations.
  if (pCtx) {
    memset(pCtx, 0, 4096);
    free(pCtx);
  }
}

// 0x637cd0 — xrefs: 4
void *FFX_Battle_AllocActorArray(int maxActors) {
  // Allocates the array of actor structs for a battle encounter.
  // Each actor is ~256 bytes based on typical battle actor size.
  return calloc(maxActors > 0 ? maxActors : 12, 256);
}

// 0x637d70 — xrefs: 2
void FFX_Battle_FreeActorArray(void *pActors) {
  // Frees the actor array and all per-actor sub-allocations.
  free(pActors);
}

// 0x637e10 — xrefs: 3
void *FFX_Battle_AllocActionQueue(int capacity) {
  // Allocates the circular action queue for CTB scheduling.
  // Each action entry is ~64 bytes.
  return calloc(capacity > 0 ? capacity : 16, 64);
}

// 0x637eb0 — xrefs: 2
void FFX_Battle_FreeActionQueue(void *pQueue) {
  // Frees the action queue and all pending action entries.
  free(pQueue);
}

// 0x637f50 — xrefs: 1
void FFX_Battle_ResetActionQueue(void *pQueue) {
  // Resets the action queue to empty state without deallocating memory.
  if (pQueue) {
    memset(pQueue, 0, 16 * 64); // match AllocActionQueue default
  }
}

// 0x638020 — xrefs: 1
void *FFX_Battle_AllocEffectState(void) {
  // Allocates the visual effect state tracker for battle animations.
  return calloc(1, 512); // approximate effect state size
}

// 0x6380c0 — xrefs: 1
void FFX_Battle_FreeEffectState(void *pState) {
  // Frees the visual effect state tracker.
  free(pState);
}

// ============================================================================
// FFX_Btl — Battle Actor / Party System
// ============================================================================

// 0x639000 — xrefs: 6
int FFX_Btl_GetActorIndex(void *pActor) {
  // Returns the index of an actor within the battle actor array.
  if (!pActor) return -1;
  ActorEntry *actor = (ActorEntry *)pActor;
  ptrdiff_t idx = actor - s_actors;
  if (idx < 0 || idx >= s_actorCount) return -1;
  return (int)idx;
}

// 0x6390a0 — xrefs: 5
void *FFX_Btl_GetActorByIndex(int idx) {
  // Returns the actor pointer for a given array index, or NULL.
  if (idx < 0 || idx >= s_actorCount) return NULL;
  return &s_actors[idx];
}

// 0x639280 — xrefs: 3
int FFX_Btl_GetActorHp(void *pActor) {
  // Returns the current HP of an actor.
  if (!pActor) return 0;
  return ((ActorEntry *)pActor)->hp;
}

// 0x639320 — xrefs: 3
int FFX_Btl_GetActorMaxHp(void *pActor) {
  // Returns the maximum HP of an actor.
  if (!pActor) return 0;
  return ((ActorEntry *)pActor)->maxHp;
}

// 0x6393c0 — xrefs: 3
int FFX_Btl_GetActorMp(void *pActor) {
  // Returns the current MP of an actor.
  if (!pActor) return 0;
  return ((ActorEntry *)pActor)->mp;
}

// 0x639460 — xrefs: 3
int FFX_Btl_GetActorMaxMp(void *pActor) {
  // Returns the maximum MP of an actor.
  if (!pActor) return 0;
  return ((ActorEntry *)pActor)->maxMp;
}

// 0x639500 — xrefs: 2
void FFX_Btl_SetActorHp(void *pActor, int hp) {
  // Sets the current HP of an actor, clamping to [0, maxHP].
  if (!pActor) return;
  ActorEntry *actor = (ActorEntry *)pActor;
  if (hp < 0) hp = 0;
  if (hp > actor->maxHp) hp = actor->maxHp;
  actor->hp = hp;
}

// 0x6395a0 — xrefs: 2
void FFX_Btl_SetActorMp(void *pActor, int mp) {
  // Sets the current MP of an actor, clamping to [0, maxMP].
  if (!pActor) return;
  ActorEntry *actor = (ActorEntry *)pActor;
  if (mp < 0) mp = 0;
  if (mp > actor->maxMp) mp = actor->maxMp;
  actor->mp = mp;
}

// 0x639640 — xrefs: 4
int FFX_Btl_GetActorOverdrive(void *pActor) {
  // Returns the current Overdrive gauge value for an actor.
  if (!pActor) return 0;
  return ((ActorEntry *)pActor)->overdrive;
}

// 0x6396e0 — xrefs: 4
void FFX_Btl_SetActorOverdrive(void *pActor, int value) {
  // Sets the Overdrive gauge value, clamping to [0, maxOD].
  if (!pActor) return;
  ActorEntry *actor = (ActorEntry *)pActor;
  if (value < 0) value = 0;
  if (value > actor->overdriveMax) value = actor->overdriveMax;
  actor->overdrive = value;
}

// 0x639780 — xrefs: 2
int FFX_Btl_GetActorStatusEffect(void *pActor, int effectId) {
  // Returns non-zero if the actor has the given status effect active.
  if (!pActor || effectId < 0 || effectId > 31) return 0;
  ActorEntry *actor = (ActorEntry *)pActor;
  return (actor->statusFlags >> effectId) & 1;
}

// 0x639820 — xrefs: 3
void FFX_Btl_ApplyStatusEffect(void *pActor, int effectId, int turns) {
  // Applies a status effect to an actor for a given number of turns.
  if (!pActor || effectId < 0 || effectId > 31) return;
  ActorEntry *actor = (ActorEntry *)pActor;
  actor->statusFlags |= (1 << effectId);
}

// 0x6398c0 — xrefs: 2
void FFX_Btl_RemoveStatusEffect(void *pActor, int effectId) {
  // Removes a status effect from an actor immediately.
  if (!pActor || effectId < 0 || effectId > 31) return;
  ActorEntry *actor = (ActorEntry *)pActor;
  actor->statusFlags &= ~(1 << effectId);
}

// 0x639960 — xrefs: 2
void FFX_Btl_ClearAllStatusEffects(void *pActor) {
  // Clears all temporary status effects from an actor (used on battle end).
  if (!pActor) return;
  ((ActorEntry *)pActor)->statusFlags = 0;
}

// 0x639a00 — xrefs: 5
int FFX_Btl_GetActorTeam(void *pActor) {
  // Returns the team affiliation (0 = player, 1 = enemy, 2 = neutral/NPC).
  return 0;
}

// 0x639140 — xrefs: 8
int FFX_Btl_IsActorAlive(void *pActor) {
  // Returns non-zero if the actor's HP > 0.
  return FFX_Btl_GetActorHp(pActor) > 0;
}

// 0x6391e0 — xrefs: 4
int FFX_Btl_IsActorPlayerControlled(void *pActor) {
  // Returns non-zero if the actor is a party member controlled by the player.
  return FFX_Btl_GetActorTeam(pActor) == 0;
}

// 0x639aa0 — xrefs: 6
int FFX_Btl_IsActorEnemy(void *pActor) {
  // Returns non-zero if the actor belongs to the enemy team.
  return FFX_Btl_GetActorTeam(pActor) != 0;
}

// 0x639b40 — xrefs: 3
int FFX_Btl_GetActorCtbTurns(void *pActor) {
  // Returns the number of CTB turns elapsed for this actor.
  if (!pActor) return 0;
  return ((ActorEntry *)pActor)->ctbTurns;
}

// 0x639be0 — xrefs: 3
void FFX_Btl_ResetActorCtb(void *pActor) {
  // Resets the actor's CTB timer (used on battle start or revive).
  if (pActor) ((ActorEntry *)pActor)->ctbTurns = 0;
}

// 0x639c80 — xrefs: 4
void *FFX_Btl_GetActorModelNode(void *pActor) {
  // Returns the scene-graph node for the actor's 3D model.
  if (!pActor) return NULL;
  return ((ActorEntry *)pActor)->modelNode;
}

// 0x639d20 — xrefs: 2
void FFX_Btl_SetActorAnimation(void *pActor, int animId) {
  // Sets the current animation for an actor's model.
  if (!pActor) return;
  ((ActorEntry *)pActor)->animId = animId;
}

// ============================================================================
// FFX_Chr — Character Data / Stats System
// ============================================================================

// Static storage for character data (7 playable characters)
#define CHAR_COUNT 7
static int s_charLevels[CHAR_COUNT] = {1, 1, 1, 1, 1, 1, 1};
static int s_charAps[CHAR_COUNT] = {0};
static int s_charStats[CHAR_COUNT][8] = {{{0}}}; // STR, DEF, MAG, MDEF, AGI, LUK, HP, MP
static int s_charWeapons[CHAR_COUNT] = {0};
static int s_charArmors[CHAR_COUNT] = {0};
static int s_gil = 0;

// 0x639dc0 — xrefs: 6
void *FFX_Chr_GetCharacterData(int charId) {
  // Returns the character data struct for a given character ID (0-6).
  if (charId < 0 || charId >= CHAR_COUNT) return NULL;
  return &s_charStats[charId][0]; // return pointer to stat array as opaque handle
}

// 0x639e60 — xrefs: 4
int FFX_Chr_GetStat(void *pChr, int statId) {
  // Returns a base stat value (STR/DEF/MAG/MDEF/AGI/LUK) by stat ID.
  if (!pChr || statId < 0 || statId >= 8) return 0;
  return ((int *)pChr)[statId];
}

// 0x639f00 — xrefs: 4
void FFX_Chr_SetStat(void *pChr, int statId, int value) {
  // Sets a base stat value, used during level-up or equipment change.
  if (!pChr || statId < 0 || statId >= 8) return;
  ((int *)pChr)[statId] = value;
}

// 0x639fa0 — xrefs: 3
int FFX_Chr_GetLevel(void *pChr) {
  // Returns the current level of the character.
  if (!pChr) return 1;
  ptrdiff_t idx = ((int *)pChr) - s_charStats[0];
  if (idx < 0 || idx >= CHAR_COUNT * 8) return 1;
  return s_charLevels[idx / 8];
}

// 0x63a040 — xrefs: 3
void FFX_Chr_SetLevel(void *pChr, int level) {
  // Sets the character level (used for debug / New Game Plus).
  if (!pChr || level < 1) return;
  ptrdiff_t idx = ((int *)pChr) - s_charStats[0];
  if (idx < 0 || idx >= CHAR_COUNT * 8) return;
  s_charLevels[idx / 8] = level;
}

// 0x63a0e0 — xrefs: 2
int FFX_Chr_GetAp(void *pChr) {
  // Returns the total AP accumulated for this character.
  if (!pChr) return 0;
  ptrdiff_t idx = ((int *)pChr) - s_charStats[0];
  if (idx < 0 || idx >= CHAR_COUNT * 8) return 0;
  return s_charAps[idx / 8];
}

// 0x63a180 — xrefs: 3
int FFX_Chr_GetGil(void) {
  // Returns the party's current gil count.
  return 0;
}

// 0x63a220 — xrefs: 3
void FFX_Chr_AddGil(int amount) {
  // Adds gil to the party's total (positive) or subtracts (negative).
}

// 0x63a2c0 — xrefs: 5
int FFX_Chr_GetEquipmentWeapon(void *pChr) {
  // Returns the equipment slot index for the character's weapon.
  if (!pChr) return 0;
  ptrdiff_t idx = ((int *)pChr) - s_charStats[0];
  if (idx < 0 || idx >= CHAR_COUNT * 8) return 0;
  return s_charWeapons[idx / 8];
}

// 0x63a360 — xrefs: 4
void FFX_Chr_SetEquipmentWeapon(void *pChr, int weaponIdx) {
  // Sets the character's weapon equipment slot.
  if (!pChr) return;
  ptrdiff_t idx = ((int *)pChr) - s_charStats[0];
  if (idx < 0 || idx >= CHAR_COUNT * 8) return;
  s_charWeapons[idx / 8] = weaponIdx;
}

// 0x63a360 — xrefs: 5
int FFX_Chr_GetEquipmentArmor(void *pChr) {
  // Returns the equipment slot index for the character's armor.
  if (!pChr) return 0;
  ptrdiff_t idx = ((int *)pChr) - s_charStats[0];
  if (idx < 0 || idx >= CHAR_COUNT * 8) return 0;
  return s_charArmors[idx / 8];
}

// 0x63a400 — xrefs: 3
void *FFX_Chr_GetEquipmentAbilityList(void *pChr, int slotType) {
  // Returns the list of ability IDs for a weapon or armor slot.
  if (!pChr) return NULL;
  // Stub: ability list approximated by charData pointer
  return pChr;
}

// 0x63a4a0 — xrefs: 2
int FFX_Chr_HasAbility(void *pChr, int abilityId) {
  // Returns non-zero if the character has learned the given ability.
  if (!pChr) return 0;
  // Stub: check ability bits (simplified)
  (void)abilityId;
  return 0; // not learned
}

// 0x63a540 — xrefs: 1
void FFX_Chr_LearnAbility(void *pChr, int abilityId) {
  // Marks an ability as learned for the character (Sphere Grid unlock).
  if (!pChr) return;
  // Stub: mark ability as learned
  (void)abilityId;
}

// 0x63a5e0 — xrefs: 2
int FFX_Chr_GetCurrentHp(void *pChr) {
  // Returns the character's current HP from the save data.
  if (!pChr) return 0;
  ptrdiff_t idx = ((int *)pChr) - s_charStats[0];
  if (idx < 0 || idx >= CHAR_COUNT * 8) return 0;
  return s_charStats[idx / 8][6]; // HP stored at index 6
}

// 0x63a680 — xrefs: 2
int FFX_Chr_GetMaxHp(void *pChr) {
  // Returns the character's maximum HP from save data (after sphere grid).
  if (!pChr) return 0;
  ptrdiff_t idx = ((int *)pChr) - s_charStats[0];
  if (idx < 0 || idx >= CHAR_COUNT * 8) return 0;
  return s_charStats[idx / 8][7]; // MaxHP stored at index 7
}

// 0x63a720 — xrefs: 2
int FFX_Chr_GetCurrentMp(void *pChr) {
  // Returns the character's current MP from save data.
  if (!pChr) return 0;
  ptrdiff_t idx = ((int *)pChr) - s_charStats[0];
  if (idx < 0 || idx >= CHAR_COUNT * 8) return 0;
  return s_charStats[idx / 8][8]; // MP stored at index 8
}

// 0x63a7c0 — xrefs: 2
int FFX_Chr_GetMaxMp(void *pChr) {
  // Returns the character's maximum MP from save data.
  if (!pChr) return 0;
  ptrdiff_t idx = ((int *)pChr) - s_charStats[0];
  if (idx < 0 || idx >= CHAR_COUNT * 8) return 0;
  return s_charStats[idx / 8][9]; // MaxMP stored at index 9
}

// 0x63a860 — xrefs: 1
void FFX_Chr_AllocCharacterArray(int count) {
  // Allocates the global character data array for all party members.
  // Character data is managed globally; count determines party slots.
}

// 0x63a900 — xrefs: 1
void FFX_Chr_FreeCharacterArray(void) {
  // Frees the global character data array.
}

// 0x63a9a0 — xrefs: 1
void FFX_Chr_InitCharacterData(void *pChr, int charId) {
  // Initializes a character data struct to its default starting values.
  if (pChr) {
    memset(pChr, 0, 256); // approximate character data size
    ((int *)pChr)[0] = charId;
    ((int *)pChr)[1] = 1;  // default level
  }
}

// ============================================================================
// FFX_Atel — ATEL Script / Bytecode System
// ============================================================================

// 0x637000 — xrefs: 8
void *FFX_Atel_LoadScript(int scriptId) {
  // Loads an ATEL script by ID from the script archive.
  (void)scriptId;
  // Stub: allocate a simple context struct
  return calloc(1, 256);
}

// 0x6370a0 — xrefs: 5
void FFX_Atel_UnloadScript(void *pScript) {
  // Unloads an ATEL script and frees its resources.
  if (pScript) free(pScript);
}

// 0x63ab00 — xrefs: 6
int FFX_Atel_ExecuteScript(void *pScript, void *pContext) {
  // Executes an ATEL script in the given context (battle / field / menu).
  if (!pScript || !pContext) return 0;
  // Stub: returns success
  return 1;
}

// 0x63aba0 — xrefs: 4
void *FFX_Atel_AllocScriptContext(void) {
  // Allocates a new ATEL script execution context.
  void *ctx = calloc(1, 512);
  ((int *)ctx)[0] = 1; // state = running
  return ctx;
}

// 0x63ac40 — xrefs: 3
void FFX_Atel_FreeScriptContext(void *pCtx) {
  // Frees an ATEL script execution context.
  if (pCtx) {
    memset(pCtx, 0, 512);
    free(pCtx);
  }
}

// 0x63ace0 — xrefs: 4
int FFX_Atel_GetScriptState(void *pCtx) {
  // Returns the current script execution state (running / paused / done).
  if (!pCtx) return 0;
  return ((int *)pCtx)[0]; // state field
}

// 0x63ad80 — xrefs: 3
void FFX_Atel_PauseScript(void *pCtx) {
  // Pauses an executing ATEL script (waits for external resume).
  if (!pCtx) return;
  ((int *)pCtx)[0] = 2; // state = paused
}

// 0x63ae20 — xrefs: 3
void FFX_Atel_ResumeScript(void *pCtx) {
  // Resumes a paused ATEL script from where it stopped.
  if (!pCtx) return;
  ((int *)pCtx)[0] = 1; // state = running
}

// 0x63aec0 — xrefs: 2
void FFX_Atel_AbortScript(void *pCtx) {
  // Aborts an ATEL script immediately (used on encounter end).
  if (!pCtx) return;
  ((int *)pCtx)[0] = 3; // state = aborted
}

// 0x63af60 — xrefs: 5
int FFX_Atel_GetOpcodeCount(void *pScript) {
  // Returns the number of opcodes in a loaded ATEL script.
  if (!pScript) return 0;
  // Stub: approximate opcode count from script size
  return 64;
}

// 0x63b000 — xrefs: 3
int FFX_Atel_GetScriptParam(void *pCtx, int paramIdx) {
  // Returns a script parameter value from the context's parameter stack.
  if (!pCtx) return 0;
  return ((int *)pCtx)[1 + paramIdx]; // params start at offset 1
}

// 0x63b0a0 — xrefs: 3
void FFX_Atel_SetScriptParam(void *pCtx, int paramIdx, int value) {
  // Sets a script parameter value on the context's parameter stack.
  if (!pCtx) return;
  ((int *)pCtx)[1 + paramIdx] = value;
}

// 0x63b140 — xrefs: 2
int FFX_Atel_GetScriptResult(void *pCtx) {
  // Returns the result value from the last script execution.
  if (!pCtx) return 0;
  return ((int *)pCtx)[9]; // result field
}

// 0x63b1e0 — xrefs: 4
void *FFX_Atel_FindScriptLabel(void *pScript, int labelId) {
  // Finds a label offset within an ATEL script by label ID.
  if (!pScript) return NULL;
  // Stub: return script pointer as label handle
  (void)labelId;
  return pScript;
}

// 0x63b280 — xrefs: 3
int FFX_Atel_JumpToLabel(void *pCtx, int labelId) {
  // Jumps execution to a label within the current ATEL script.
  (void)labelId;
  if (!pCtx) return 0;
  // Stub: jump sets PC to 0 (restart)
  ((int *)pCtx)[16] = 0; // PC field
  return 1;
}

// 0x63b320 — xrefs: 2
void FFX_Atel_AllocScriptArchive(int maxScripts) {
  // Allocates the global ATEL script archive (holds all loaded scripts).
  (void)maxScripts;
  // Stub: allocate script archive (256KB)
  static char s_archive[262144];
  (void)s_archive;
}

// 0x63b3c0 — xrefs: 1
void FFX_Atel_FreeScriptArchive(void) {
  // Frees the global ATEL script archive and all loaded scripts.
  // Stub: free script archive (static buffer, no-op)
  (void)0;
}

// ============================================================================
// FFX_Encounter — Encounter Memory / Init / Free Helpers
// ============================================================================

// 0x834570 — xrefs: 2
void *FFX_Encounter_AllocEncounterData(int formationId) {
  // Allocates encounter data for a given formation (monster slots, drops).
  return calloc(1, 256); // approximate size until struct is known
}

// 0x834600 — xrefs: 1
void FFX_Encounter_FreeEncounterData(void *pData) {
  // Frees encounter data allocated by AllocEncounterData.
  free(pData);
}

// 0x834690 — xrefs: 2
void *FFX_Encounter_AllocFormationSlots(int maxMonsters) {
  // Allocates the formation slot array for a monster encounter.
  // Each slot is ~32 bytes based on typical monster slot size.
  return calloc(maxMonsters > 0 ? maxMonsters : 8, 32);
}

// 0x834720 — xrefs: 1
void FFX_Encounter_FreeFormationSlots(void *pSlots) {
  // Frees the formation slot array.
  free(pSlots);
}

// 0x8347b0 — xrefs: 3
void FFX_Encounter_InitFormationSlot(void *pSlot, int monsterId) {
  // Initializes a formation slot with a specific monster ID.
  if (pSlot) {
    ((int *)pSlot)[0] = monsterId;
  }
}

// 0x834840 — xrefs: 2
void *FFX_Encounter_AllocDropTable(int maxDrops) {
  // Allocates a drop-table array for encounter rewards.
  // Each entry is ~8 bytes (itemId + rate).
  return calloc(maxDrops > 0 ? maxDrops : 4, 8);
}

// 0x8348d0 — xrefs: 1
void FFX_Encounter_FreeDropTable(void *pTable) {
  // Frees the drop-table array.
  free(pTable);
}

// 0x834960 — xrefs: 3
void FFX_Encounter_InitDropEntry(void *pEntry, int itemId, int rate) {
  // Initializes a drop-table entry with an item ID and drop rate.
  if (pEntry) {
    ((int *)pEntry)[0] = itemId;
    ((int *)pEntry)[1] = rate;
  }
}

// 0x8349f0 — xrefs: 2
void *FFX_Encounter_AllocStealTable(int maxSteals) {
  // Allocates a steal-table array for encounter steal rewards.
  // Each entry is ~8 bytes (itemId + rate).
  return calloc(maxSteals > 0 ? maxSteals : 4, 8);
}

// 0x834a80 — xrefs: 1
void FFX_Encounter_FreeStealTable(void *pTable) {
  // Frees the steal-table array.
  free(pTable);
}

// 0x834b10 — xrefs: 2
void FFX_Encounter_InitStealEntry(void *pEntry, int itemId, int rate) {
  // Initializes a steal-table entry with an item ID and steal rate.
  if (pEntry) {
    ((int *)pEntry)[0] = itemId;
    ((int *)pEntry)[1] = rate;
  }
}

// 0x834ba0 — xrefs: 1
void FFX_Encounter_AllocGlobalState(void) {
  // Allocates the global encounter state manager.
  s_encounterActive = 0;
  s_battleInputMode = 0;
}

// 0x834c30 — xrefs: 1
void FFX_Encounter_FreeGlobalState(void) {
  // Frees the global encounter state manager.
  s_encounterActive = 0;
  s_battleInputMode = 0;
}

// 0x834cc0 — xrefs: 2
void FFX_Encounter_InitGlobalState(void) {
  // Initializes the global encounter state to defaults.
  s_encounterActive = 0;
  s_battleInputMode = 0;
}

// 0x834d50 — xrefs: 1
void FFX_Encounter_ShutdownGlobalState(void) {
  // Shuts down the global encounter state (called on game exit).
}

// ============================================================================
// Status Effect Stubs
// ============================================================================

// FFX_Battle_ApplyStatusEffect (0x79xxxx)
// Aplica efeito de status no alvo
int FFX_Battle_ApplyStatusEffect(void *_this, int target, int effectId,
                                 int turns) {
  return 0;
}

// FFX_Battle_RemoveStatusEffect (0x79xxxx)
// Remove efeito de status do alvo
int FFX_Battle_RemoveStatusEffect(void *_this, int target, int effectId) {
  return 0;
}

// FFX_Battle_HasStatusEffect (0x79xxxx)
// Verifica se o alvo possui determinado efeito de status
int FFX_Battle_HasStatusEffect(void *_this, int target, int effectId) {
  return 0;
}

// FFX_Battle_GetStatusEffectTurns (0x79xxxx)
// Retorna o numero de turnos restantes de um efeito de status
int FFX_Battle_GetStatusEffectTurns(void *_this, int target, int effectId) {
  return 0;
}

// FFX_Battle_SetStatusEffectTurns (0x79xxxx)
// Define o numero de turnos restantes de um efeito de status
int FFX_Battle_SetStatusEffectTurns(void *_this, int target, int effectId,
                                    int turns) {
  return 0;
}

// FFX_Battle_IsStatusEffectProtect (0x79xxxx)
// Verifica se o alvo esta sob efeito de Protect
int FFX_Battle_IsStatusEffectProtect(void *_this, int target) { return 0; }

// FFX_Battle_IsStatusEffectShell (0x79xxxx)
// Verifica se o alvo esta sob efeito de Shell
int FFX_Battle_IsStatusEffectShell(void *_this, int target) { return 0; }

// FFX_Battle_IsStatusEffectHaste (0x79xxxx)
// Verifica se o alvo esta sob efeito de Haste
int FFX_Battle_IsStatusEffectHaste(void *_this, int target) { return 0; }

// FFX_Battle_IsStatusEffectSlow (0x79xxxx)
// Verifica se o alvo esta sob efeito de Slow
int FFX_Battle_IsStatusEffectSlow(void *_this, int target) { return 0; }

// FFX_Battle_IsStatusEffectNulBlaze (0x79xxxx)
// Verifica se o alvo esta sob efeito de NulBlaze
int FFX_Battle_IsStatusEffectNulBlaze(void *_this, int target) { return 0; }

// ============================================================================
// FFX_Battle — Turn Order / Actor State Accessors
// ============================================================================

// FFX_Battle_GetTurnOrder (0x000000)
// Retorna a ordem de turno atual do CTB para um determinado slot
int FFX_Battle_GetTurnOrder(void *_this) { return 0; }

// FFX_Battle_SetTurnOrder (0x000000)
// Define a ordem de turno do CTB para um determinado slot
int FFX_Battle_SetTurnOrder(void *_this, int order) { return 0; }

// FFX_Battle_GetCurrentTurn (0x000000)
// Retorna o indice do turno atual na fila CTB
int FFX_Battle_GetCurrentTurn(void *_this) { return 0; }

// FFX_Battle_GetActorHp (0x000000)
// Retorna o HP atual de um ator da batalha
int FFX_Battle_GetActorHp(void *_this, int actorIndex) { return 0; }

// FFX_Battle_SetActorHp (0x000000)
// Define o HP atual de um ator da batalha
int FFX_Battle_SetActorHp(void *_this, int actorIndex, int hp) { return 0; }

// FFX_Battle_GetActorMp (0x000000)
// Retorna o MP atual de um ator da batalha
int FFX_Battle_GetActorMp(void *_this, int actorIndex) { return 0; }

// FFX_Battle_SetActorMp (0x000000)
// Define o MP atual de um ator da batalha
int FFX_Battle_SetActorMp(void *_this, int actorIndex, int mp) { return 0; }

// FFX_Battle_GetActorStatusEffects (0x000000)
// Retorna a mascara de status effects ativos em um ator
int FFX_Battle_GetActorStatusEffects(void *_this, int actorIndex) { return 0; }

// ============================================================================
// FFX_Battle — Stat Accessors (Strength, Defense, Magic, Magic Def, Agility,
// Luck)
// ============================================================================

// FFX_Battle_GetActorStrength (0x000000)
// Retorna o valor atual de Strength de um ator da batalha
int FFX_Battle_GetActorStrength(void *_this, int actorIndex) { return 0; }

// FFX_Battle_GetActorDefense (0x000000)
// Retorna o valor atual de Defense de um ator da batalha
int FFX_Battle_GetActorDefense(void *_this, int actorIndex) { return 0; }

// FFX_Battle_GetActorMagic (0x000000)
// Retorna o valor atual de Magic de um ator da batalha
int FFX_Battle_GetActorMagic(void *_this, int actorIndex) { return 0; }

// FFX_Battle_GetActorMagicDef (0x000000)
// Retorna o valor atual de Magic Defense de um ator da batalha
int FFX_Battle_GetActorMagicDef(void *_this, int actorIndex) { return 0; }

// FFX_Battle_GetActorAgility (0x000000)
// Retorna o valor atual de Agility de um ator da batalha
int FFX_Battle_GetActorAgility(void *_this, int actorIndex) { return 0; }

// FFX_Battle_GetActorLuck (0x000000)
// Retorna o valor atual de Luck de um ator da batalha
int FFX_Battle_GetActorLuck(void *_this, int actorIndex) { return 0; }

// ============================================================================
// FFX_Battle — CTB Queue / Overdrive / Party / Enemy Accessors (Expanded)
// ============================================================================

// FFX_Battle_GetCTBQueue (0x79xxxx)
// Retorna o ponteiro para a fila CTB (lista de ordens de turno)
int FFX_Battle_GetCTBQueue(void *self) { return 0; }

// FFX_Battle_SetCTBQueue (0x79xxxx)
// Define a fila CTB a partir de um buffer externo
int FFX_Battle_SetCTBQueue(void *self, void *queue) { return 0; }

// FFX_Battle_GetOverdriveGauge (0x79xxxx)
// Retorna o valor atual do gauge de Overdrive de um personagem
int FFX_Battle_GetOverdriveGauge(void *self, int charIndex) { return 0; }

// FFX_Battle_SetOverdriveGauge (0x79xxxx)
// Define o valor do gauge de Overdrive de um personagem
int FFX_Battle_SetOverdriveGauge(void *self, int charIndex, int value) {
  return 0;
}

// FFX_Battle_IsOverdriveActive (0x79xxxx)
// Retorna 1 se o Overdrive estiver ativo (gauge cheio) para o personagem
int FFX_Battle_IsOverdriveActive(void *self, int charIndex) { return 0; }

// FFX_Battle_GetPartyHpAverage (0x79xxxx)
// Retorna a media de HP atual de todos os membros do grupo ativo
int FFX_Battle_GetPartyHpAverage(void *self) { return 0; }

// FFX_Battle_GetPartyStatus (0x79xxxx)
// Retorna a mascara de status effects combinada de todos os membros do grupo
int FFX_Battle_GetPartyStatus(void *self) { return 0; }

// FFX_Battle_SetPartyStatus (0x79xxxx)
// Aplica um status effect a todos os membros do grupo ativo
int FFX_Battle_SetPartyStatus(void *self, int effectId, int turns) { return 0; }

// FFX_Battle_GetEnemyCount (0x79xxxx)
// Retorna o numero de inimigos vivos na batalha atual
int FFX_Battle_GetEnemyCount(void *self) { return 0; }

// FFX_Battle_GetEnemyByIndex (0x79xxxx)
// Retorna o ponteiro do inimigo no indice especificado, ou NULL se invalido
void *FFX_Battle_GetEnemyByIndex(void *self, int index) { return 0; }

// ============================================================================
// End of ffx_battle.cpp
// ============================================================================

// ============================================================
// FFX Math Utilities — self-contained, decompiled from DB
// ============================================================

// FFX_Math_Vec4Assign (0x710f10): copy 4 floats
int __cdecl FFX_Math_Vec4Assign(float *a1, float *a2)
{
    a1[0] = a2[0];
    a1[1] = a2[1];
    a1[2] = a2[2];
    a1[3] = a2[3];
    return (int)a1;
}

// FFX_Math_Vec4AssignReverse (0x710f50): copy reversed
int __cdecl FFX_Math_Vec4AssignReverse(float *a1, float *a2)
{
    a1[3] = a2[3];
    a1[2] = a2[2];
    a1[1] = a2[1];
    a1[0] = a2[0];
    return (int)a1;
}

// FFX_Math_Vec3MulScalarStore (0x710f80): vec3 *= scalar
float *__cdecl FFX_Math_Vec3MulScalarStore(float *a1, float *a2, float a3)
{
    a1[0] = a2[0] * a3;
    a1[1] = a2[1] * a3;
    a1[2] = a2[2] * a3;
    return a1;
}

// FFX_Math_Vec3Mul3Scalars (0x728b50): vec3 *= 3 scalars
float *__cdecl FFX_Math_Vec3Mul3Scalars(float *a1, float *a2, float a3, float a4, float a5)
{
    a1[0] = a2[0] * a3;
    a1[1] = a2[1] * a4;
    a1[2] = a2[2] * a5;
    return a1;
}

// FFX_Math_SetFlagBit7 (0x42ef20): set bit 7 on value
int __cdecl FFX_Math_SetFlagBit7(int val) { return val | 0x80; }

// FFX_Math_SetFlagBit6 (0x42ef30): set bit 6 on value
int __cdecl FFX_Math_SetFlagBit6(int val) { return val | 0x40; }

// FFX_Math_Copy4Dwords (0x72f4a0): copy 4 dwords
int __cdecl FFX_Math_Copy4Dwords(int *a1, int *a2)
{
    a2[0] = a1[0];
    a2[1] = a1[1];
    a2[2] = a1[2];
    a2[3] = a1[3];
    return a2[3];
}

// FFX_Math_FloatAddInPlace (0x74b700): *a1 = *a2 + a4
float *__cdecl FFX_Math_FloatAddInPlace(float *a1, float *a2, int a3, float a4)
{
    *a1 = *a2 + a4;
    return a1;
}

// FFX_Math_Vec4Copy (0x7500f0): copy 4 floats
float *__cdecl FFX_Math_Vec4Copy(float *a1, float *a2)
{
    a1[0] = a2[0];
    a1[1] = a2[1];
    a1[2] = a2[2];
    a1[3] = a2[3];
    return a1;
}

// FFX_Math_Vec4MulScalar (0x7501a0): vec4 *= scalar
float *__cdecl FFX_Math_Vec4MulScalar(float *a1, float *a2, float a3)
{
    a1[0] = a2[0] * a3;
    a1[1] = a2[1] * a3;
    a1[2] = a2[2] * a3;
    a1[3] = a2[3] * a3;
    return a2;
}

// FFX_Math_Vec3Scale (0x75bbf0): vec3 *= scalar
float *__cdecl FFX_Math_Vec3Scale(float *a1, float *a2, float a3)
{ a1[0] = a2[0] * a3; a1[1] = a2[1] * a3; a1[2] = a2[2] * a3; return a1; }

// FFX_Math_FloatSqrt (0x75fce0): sqrtf
double __cdecl FFX_Math_FloatSqrt(float a1) { return (double)sqrtf(a1); }

// FFX_Math_FloatMulInPlace (0x7677a0): *a1 = *a2 * a3
float *__cdecl FFX_Math_FloatMulInPlace(float *a1, float *a2, float a3)
{ *a1 = *a2 * a3; return a1; }

// FFX_Math_SumDwordArray (0x76b2f0): sum array
int __cdecl FFX_Math_SumDwordArray(int *a1, int count)
{ int r = 0; for (int i = 0; i < count; i++) r += a1[i]; return r; }

// FFX_Math_ClampInt (0x79a0d0): clamp int between min/max
int __cdecl FFX_Math_ClampInt(int val, int minVal, int maxVal)
{
    if (val < minVal) return minVal;
    if (val > maxVal) return maxVal;
    return val;
}

// FFX_Math_Vector4MulPerComponent (0x7c1140): vec4 *= (a3,a4,a5,a6)
float *__cdecl FFX_Math_Vector4MulPerComponent(float *a1, float *a2, float a3, float a4, float a5, float a6)
{
    a1[0] = a2[0] * a3; a1[1] = a2[1] * a4;
    a1[2] = a2[2] * a5; a1[3] = a2[3] * a6;
    return a1;
}

// FFX_Math_CharToDigit (0x7cf190): '0'-'9' -> 0-9, else -1
int __cdecl FFX_Math_CharToDigit(char c)
{
    unsigned char d = (unsigned char)(c - 48);
    if (d > 9) return -1;
    return d;
}

// FFX_Math_Vector3Distance_structural (0x7e7ed0): vec3 distance
double __cdecl FFX_Math_Vector3Distance_structural(float *a, float *b)
{
    float dx = b[0] - a[0];
    float dy = b[1] - a[1];
    float dz = b[2] - a[2];
    return sqrtf(dx * dx + dy * dy + dz * dz);
}

// FFX_Util_Align16Pad (0x92b2c0): padding needed to align to 16 bytes
int __cdecl FFX_Util_Align16Pad(int val)
{
    int rem = val % 16;
    return rem ? 16 - rem : 0;
}

// FFX_Math_Vector3Delta (0x834080): a1[3..5] - a1[7..9] -> a2[0..2]
float *__cdecl FFX_Math_Vector3Delta(float *a1, float *a2)
{
    a2[0] = a1[7] - a1[3];
    a2[1] = a1[8] - a1[4];
    a2[2] = a1[9] - a1[5];
    return a2;
}

// FFX_Math_Vector4Copy (0x7c1090): copy 4 floats
float *__cdecl FFX_Math_Vector4Copy(float *a1, float *a2)
{
    a1[0] = a2[0]; a1[1] = a2[1];
    a1[2] = a2[2]; a1[3] = a2[3];
    return a1;
}

// FFX_Math_CheckAngleRangeWrapped_structural (0x7e7e70): wrapped angle check
BOOL __cdecl FFX_Math_CheckAngleRangeWrapped_structural(float angle, float min, float max)
{
    int a = (int)angle & 0xFFF;
    int lo = (int)min & 0xFFF;
    int hi = (int)max & 0xFFF;
    if (lo <= hi) return (lo <= a && a <= hi);
    return (a <= hi || a >= lo);
}

// FFX_Math_IdentityMatrix44 (0x7ea5e0): memset + diagonal[0,5,10,15]=1
void *__cdecl FFX_Math_IdentityMatrix44(float *a1)
{
    memset(a1, 0, 0x40);
    a1[0] = 1.0f; a1[5] = 1.0f; a1[10] = 1.0f; a1[15] = 1.0f;
    return a1;
}

// FFX_Math_UniformScaleMatrix44 (0x7ea610): scale matrix
void *__cdecl FFX_Math_UniformScaleMatrix44(float *a1, float a2)
{
    memset(a1, 0, 0x40);
    a1[0] = a2; a1[5] = a2; a1[10] = a2; a1[15] = 1.0f;
    return a1;
}

// FFX_Math_ScaleMatrix44FromVector (0x7ea640): scale from vec3
float *__cdecl FFX_Math_ScaleMatrix44FromVector(float *a1, float *a2)
{
    memset(a1, 0, 0x40);
    a1[0] = a2[0]; a1[5] = a2[1]; a1[10] = a2[2]; a1[15] = 1.0f;
    return a2;
}

// FFX_Math_ScaleVectorW (0x7ecde0): a2.w *= a3
int __cdecl FFX_Math_ScaleVectorW(float *a1, float *a2, float a3)
{ a1[3] = a2[3] * a3; return (int)a1; }

// FFX_Math_Clamp0to99 (0x82dae0): clamp 0-99
int __cdecl FFX_Math_Clamp0to99(int n)
{
    if (n > 99) return 99;
    if (n < 0) return 0;
    return n;
}

// FFX_Math_VectorLength3 (0x8366f0): vec3 magnitude
double __cdecl FFX_Math_VectorLength3(float *a1)
{ return sqrtf(a1[0]*a1[0] + a1[1]*a1[1] + a1[2]*a1[2]); }

// FFX_Math_VectorDistance3 (0x836720): vec3 distance
double __cdecl FFX_Math_VectorDistance3(float *a, float *b)
{
    float dx = b[0]-a[0], dy = b[1]-a[1], dz = b[2]-a[2];
    return sqrtf(dx*dx + dy*dy + dz*dz);
}
