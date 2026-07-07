#include "ffx_renderqueue.h"
#include <stdint.h>

extern int FFX_Btl_GetActorHp(void *a);
extern int FFX_Btl_GetActorMaxHp(void *a);
extern int FFX_Btl_GetActorMp(void *a);
extern int FFX_Btl_GetActorMaxMp(void *a);
extern int FFX_Btl_GetActorOverdrive(void *a);

#define BTL_HUD_BAR_W  120.0f
#define BTL_HUD_BAR_H  8.0f
#define BTL_HUD_BAR_X  20.0f
#define BTL_HUD_BAR_Y  20.0f
#define BTL_HUD_BAR_GAP 22.0f

#define COLOR_HP_FULL   0xFF00FF00
#define COLOR_HP_MID    0xFFFFFF00
#define COLOR_HP_LOW    0xFF0000FF
#define COLOR_MP        0xFF0080FF
#define COLOR_OVERDRIVE 0xFFFF8000
#define COLOR_BG        0xFF202020
#define COLOR_BORDER    0xFF404040

static int clamp_int(int v, int lo, int hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static uint32_t hp_color_by_percent(int pct) {
    if (pct > 50) return COLOR_HP_FULL;
    if (pct > 25) return COLOR_HP_MID;
    return COLOR_HP_LOW;
}

void FFX_BtlHUD_DrawHpBar(int actorIndex, int hp, int maxHp) {
    if (maxHp <= 0) maxHp = 1;
    int pct = clamp_int((hp * 100) / maxHp, 0, 100);

    float x = BTL_HUD_BAR_X;
    float y = BTL_HUD_BAR_Y + (actorIndex * BTL_HUD_BAR_GAP);
    float fillW = (BTL_HUD_BAR_W * pct) / 100.0f;

    FFX_RenderQueue_PushRect(x, y, BTL_HUD_BAR_W, BTL_HUD_BAR_H, COLOR_BG, COLOR_BG);
    FFX_RenderQueue_PushRect(x, y, fillW, BTL_HUD_BAR_H, hp_color_by_percent(pct), hp_color_by_percent(pct));
    FFX_RenderQueue_PushRect(x, y, BTL_HUD_BAR_W, 1.0f, COLOR_BORDER, COLOR_BORDER);
    FFX_RenderQueue_PushRect(x, y + BTL_HUD_BAR_H - 1.0f, BTL_HUD_BAR_W, 1.0f, COLOR_BORDER, COLOR_BORDER);
}

void FFX_BtlHUD_DrawMpBar(int actorIndex, int mp, int maxMp) {
    if (maxMp <= 0) maxMp = 1;
    int pct = clamp_int((mp * 100) / maxMp, 0, 100);

    float x = BTL_HUD_BAR_X + BTL_HUD_BAR_W + 8.0f;
    float y = BTL_HUD_BAR_Y + (actorIndex * BTL_HUD_BAR_GAP);
    float fillW = (60.0f * pct) / 100.0f;

    FFX_RenderQueue_PushRect(x, y, 60.0f, BTL_HUD_BAR_H, COLOR_BG, COLOR_BG);
    FFX_RenderQueue_PushRect(x, y, fillW, BTL_HUD_BAR_H, COLOR_MP, COLOR_MP);
}

void FFX_BtlHUD_DrawOverdriveBar(int actorIndex, int od, int maxOd) {
    if (maxOd <= 0) maxOd = 1;
    int pct = clamp_int((od * 100) / maxOd, 0, 100);

    float x = BTL_HUD_BAR_X + BTL_HUD_BAR_W + 76.0f;
    float y = BTL_HUD_BAR_Y + (actorIndex * BTL_HUD_BAR_GAP);
    float fillW = (40.0f * pct) / 100.0f;

    FFX_RenderQueue_PushRect(x, y, 40.0f, BTL_HUD_BAR_H, COLOR_BG, COLOR_BG);
    FFX_RenderQueue_PushRect(x, y, fillW, BTL_HUD_BAR_H, COLOR_OVERDRIVE, COLOR_OVERDRIVE);
}

void FFX_BtlHUD_DrawActorHud(int actorIndex, void *pActor) {
    if (!pActor) return;

    int hp = FFX_Btl_GetActorHp(pActor);
    int maxHp = FFX_Btl_GetActorMaxHp(pActor);
    int mp = FFX_Btl_GetActorMp(pActor);
    int maxMp = FFX_Btl_GetActorMaxMp(pActor);
    int od = FFX_Btl_GetActorOverdrive(pActor);

    FFX_BtlHUD_DrawHpBar(actorIndex, hp, maxHp);
    FFX_BtlHUD_DrawMpBar(actorIndex, mp, maxMp);
    FFX_BtlHUD_DrawOverdriveBar(actorIndex, od, 100);
}

void FFX_BtlHUD_DrawPartyHud(void **pParty, int count) {
    if (!pParty) return;
    for (int i = 0; i < count && i < 3; i++) {
        FFX_BtlHUD_DrawActorHud(i, pParty[i]);
    }
}
