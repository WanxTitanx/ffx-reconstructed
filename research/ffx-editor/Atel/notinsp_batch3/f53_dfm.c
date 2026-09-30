// FFX: Battle damage formula dispatch — dispatches damage formula by type (proven: str³/32+30)
// FFX Battle: Damage formula dispatch — main damage calculator
// Damage formula dispatcher. Uses canonical formula str^3/32+30 for base damage. Dispatches by damage type (physical/magical/item). Accesses attacker->strength(0x5A8), defender->defense(0x5A9), attacker->magic(0x5AA), defender->magicDef(0x5AB).
int __fastcall FFX_Battle_DamageFormulaDispatch(
        FFX_DamageFormula formulaType,
        FFXBattleActorRecord *attacker,
        FFXBattleActorRecord *target,
        int basePower)
{
  int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; // eax
  int basePower_1; // ecx
  int v7; // esi
  int v8; // eax
  char Indexed31; // al
  int n256; // edi
  int v11; // eax
  int v12; // eax
  int fallbackValue_1; // esi
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // edi
  FFXBattleActorData *attackera_1; // ebx
  int v19; // ecx
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  unsigned __int8 n0x12; // al
  int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1; // [esp+Ch] [ebp-Ch]
  int v26; // [esp+10h] [ebp-8h]
  int v27; // [esp+14h] [ebp-4h]
  FFXBattleActorData *attackera; // [esp+20h] [ebp+8h]
  int cmdCtx; // [esp+28h] [ebp+10h]
  FFX_DamageFormula formulaTypea; // [esp+2Ch] [ebp+14h]
  int basePowera; // [esp+30h] [ebp+18h]
  char dmgFlags; // [esp+34h] [ebp+1Ch]
  FFX_DamageType statCategory; // [esp+38h] [ebp+20h]
  FFX_DamageType statCategorya; // [esp+38h] [ebp+20h]
  int useRandomVariance; // [esp+3Ch] [ebp+24h]
  int *outAttackerStat; // [esp+40h] [ebp+28h]
  int *outDefenderStat; // [esp+44h] [ebp+2Ch]
  int fallbackValue; // [esp+48h] [ebp+30h]

  [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = FFX_Btl_UI_MapActorSlotToCommandIndex(
                                                                      (FFX_Aeon)formulaType,
                                                                      attacker,
                                                                      LOBYTE(target->m_state),
                                                                      0);// [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass.
  basePower_1 = basePower;
  [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg;
  v7 = 0;
  v26 = *(unsigned __int8 *)(basePower + 1449);
  attackera = (FFXBattleActorData *)*(unsigned __int8 *)(basePower + 1451);
  v27 = 0;
  switch ( statCategory )
  {
    case DAMAGE_HP:
      v7 = *(_DWORD *)(basePower + 1764);
      v8 = *(_DWORD *)(basePower + 1428);
      goto LABEL_7;
    case DAMAGE_MP:
      v7 = *(_DWORD *)(basePower + 1768);
      v8 = *(_DWORD *)(basePower + 1432);
      goto LABEL_7;
    case DAMAGE_CTB:
      v7 = *(_DWORD *)(basePower + 1772);
      v8 = *(unsigned __int8 *)(basePower + 1629);
LABEL_7:
      v27 = v8;
      break;
  }
  if ( cmdCtx && (*(_BYTE *)(cmdCtx + 35) & 1) != 0 )
  {
    v26 = (dmgFlags & 0x40) == 0 ? v26 : 0;
    attackera = (dmgFlags & 0x80) == 0 ? (FFXBattleActorData *)*(unsigned __int8 *)(basePower + 1451) : 0;
  }
  if ( useRandomVariance )
  {
    Indexed31 = FFX_Rng_NextIndexed31([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1);
    basePower_1 = basePower;
    n256 = (Indexed31 & 0x1F) + 240;
  }
  else
  {
    n256 = 256;
  }
  statCategorya = n256;
  switch ( formulaTypea )
  {
    case DMG_NORMAL:
      v11 = (15 - *(unsigned __int8 *)(basePower + 1630))
          * ((((unsigned __int8)target->pad_0764[330] + (unsigned __int8)target->pad_0764[512])
            * ((unsigned __int8)target->pad_0764[330] + (unsigned __int8)target->pad_0764[512])
            * ((unsigned __int8)target->pad_0764[330] + (unsigned __int8)target->pad_0764[512])
            / 32
            + 30)
           * (730 - (51 * v26 - v26 * v26 / 11) / 10)
           / 730)
          / 15;
      goto LABEL_16;
    case DMG_IGNORE_DEF:
      v14 = (unsigned __int8)target->pad_0764[512];
      v15 = (unsigned __int8)target->pad_0764[330];
      goto LABEL_19;
    case DMG_MAGIC:
      v16 = (unsigned __int8)target->pad_0764[332];
      v17 = (unsigned __int8)target->pad_0764[514];
      attackera_1 = attackera;
      fallbackValue_1 = statCategorya
                      * ((15 - *(unsigned __int8 *)(basePower + 1632))
                       * (basePowera
                        * (basePowera + (v16 + v17) * (v16 + v17) / 6)
                        / 4
                        * (730 - (51 * (int)attackera - (int)attackera * (int)attackera / 11) / 10)
                        / 730)
                       / 15)
                      / 256;
      goto LABEL_44;
    case DMG_IGNORE_MDEF:
      v19 = (unsigned __int8)target->pad_0764[332] + (unsigned __int8)target->pad_0764[514];
      v12 = basePowera * (basePowera + v19 * v19 / 6) / 4;
      goto LABEL_17;
    case DMG_TARGET_HP:
      fallbackValue_1 = basePowera * v7 / 16;
      break;
    case MultiplesOf50:
      fallbackValue_1 = 50 * basePowera;
      break;
    case DMG_HEALING:
      fallbackValue_1 = basePowera
                      * n256
                      * ((basePowera + (unsigned __int8)target->pad_0764[514] + (unsigned __int8)target->pad_0764[332])
                       / 2)
                      / 256;
      break;
    case DMG_TARGET_MAXHP:
      fallbackValue_1 = basePowera * v27 / 16;
      break;
    case MultiplesOf50R:
      fallbackValue_1 = 50 * basePowera * n256 / 256;
      break;
    case TargetMaxMp:
      fallbackValue_1 = (unsigned int)(basePowera * *(_DWORD *)(basePower_1 + 1432)) >> 4;
      break;
    case TargetTickSpeed:
      fallbackValue_1 = basePowera * *(unsigned __int8 *)(basePower_1 + 1629) / 16;
      break;
    case TargetMp:
      fallbackValue_1 = basePowera * *(_DWORD *)(basePower_1 + 1768) / 16;
      break;
    case TargetTickCounter:
      fallbackValue_1 = basePowera * *(_DWORD *)(basePower_1 + 1772) / 16;
      break;
    case IgnoreDefenseNR:
      return basePowera
           * ((unsigned __int8)target->pad_0764[330]
            * (unsigned __int8)target->pad_0764[330]
            * (unsigned __int8)target->pad_0764[330]
            / 32
            + 30)
           / 16;
    case SpecialMagic:
      v14 = (unsigned __int8)target->pad_0764[514];
      v15 = (unsigned __int8)target->pad_0764[332];
LABEL_19:
      v11 = (v15 + v14) * (v15 + v14) * (v15 + v14) / 32 + 30;
LABEL_16:
      v12 = basePowera * v11 / 16;
LABEL_17:
      fallbackValue_1 = n256 * v12 / 256;
      break;
    case WielderMaxHp:
      fallbackValue_1 = basePowera * *(_DWORD *)&target->pad_0764[310] / 0xAu;
      break;
    case WielderHighHp:
      v21 = (unsigned __int8)target->pad_0764[330] + (unsigned __int8)target->pad_0764[512];
      fallbackValue_1 = (n256
                       * ((basePowera
                         * ((v21 * v21 * v21 / 32 + 30)
                          * ((unsigned int)(100 * *(_DWORD *)&target->pad_0764[370]) / *(_DWORD *)&target->pad_0764[310]
                           + 10)
                          / 0x6E)) >> 4)) >> 8;
      break;
    case WielderHighMp:
      v22 = (unsigned __int8)target->pad_0764[330] + (unsigned __int8)target->pad_0764[512];
      fallbackValue_1 = (n256
                       * ((basePowera
                         * ((v22 * v22 * v22 / 32 + 30)
                          * ((unsigned int)(100 * *(_DWORD *)&target->pad_0764[374]) / *(_DWORD *)&target->pad_0764[314]
                           + 10)
                          / 0x6E)) >> 4)) >> 8;
      break;
    case WielderLowHp:
      v23 = (unsigned __int8)target->pad_0764[330] + (unsigned __int8)target->pad_0764[512];
      fallbackValue_1 = (n256
                       * ((basePowera
                         * ((v23 * v23 * v23 / 32 + 30)
                          * (130
                           - (unsigned int)(100 * *(_DWORD *)&target->pad_0764[370]) / *(_DWORD *)&target->pad_0764[310])
                          / 0x3C)) >> 4)) >> 8;
      break;
    case SpecialMagicNR:
      return basePowera
           * ((unsigned __int8)target->pad_0764[332]
            * (unsigned __int8)target->pad_0764[332]
            * (unsigned __int8)target->pad_0764[332]
            / 32
            + 30)
           / 16;
    case DMG_GIL_SPENT:
      fallbackValue_1 = n7_0 / 10;
      break;
    case TargetKillCount:
      n0x12 = *(_BYTE *)(basePower_1 + 12);
      if ( n0x12 >= 0x12u )
        goto LABEL_42;
      fallbackValue_1 = basePowera * unk_11320B0[37 * n0x12];
      break;
    case MultiplesOf9999:
      fallbackValue_1 = 9999 * basePowera;
      break;
    default:
LABEL_42:
      fallbackValue_1 = fallbackValue;
      break;
  }
  attackera_1 = attackera;
LABEL_44:
  if ( cmdCtx && (*(_BYTE *)(cmdCtx + 32) & 0x10) != 0 && (dmgFlags & 2) == 0 )
    fallbackValue_1 = -fallbackValue_1;
  if ( outAttackerStat )
    *outAttackerStat = v26;
  if ( outDefenderStat )
    *outDefenderStat = (int)attackera_1;
  return fallbackValue_1;
}