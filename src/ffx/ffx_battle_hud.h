#ifndef FFX_BATTLE_HUD_H
#define FFX_BATTLE_HUD_H

void FFX_BtlHUD_DrawHpBar(int actorIndex, int hp, int maxHp);
void FFX_BtlHUD_DrawMpBar(int actorIndex, int mp, int maxMp);
void FFX_BtlHUD_DrawOverdriveBar(int actorIndex, int od, int maxOd);
void FFX_BtlHUD_DrawActorHud(int actorIndex, void *pActor);
void FFX_BtlHUD_DrawPartyHud(void **pParty, int count);

#endif
