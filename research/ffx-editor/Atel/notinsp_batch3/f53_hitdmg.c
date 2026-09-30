// FFX: Battle computes hit damage — computes hit damage formula
// FFX Battle: Compute hit damage — large damage calculator
// Core hit damage computation. Applies element resistance, status modifiers, critical hit chance, overdrive modifiers. Calls DamageFormulaDispatch for base formula, then applies multipliers.
int __fastcall FFX_Battle_ComputeHitDamage(
        FFX_DamageType dmgType,
        FFXBattleActorRecord *attacker,
        FFXBattleActorRecord *target,
        int basePower)
{
  bool v4; // zf
  int magicDefense; // eax
  int v6; // eax
  int v7; // edx
  int v8; // eax
  FFXBattleActorRecord *attacker_1; // edx
  FFX_ElementType element; // ecx
  FFXBattleActorRecord *attacker_2; // edx
  FFX_HitCalcType hitType; // ecx
  int v13; // eax
  int n2_3; // eax
  FFXBattleActorRecord *actorData; // edx
  char n2_2; // al
  _DWORD *p_n17_1; // eax
  int v18; // eax
  FFXBattleActorRecord *attacker_3; // edx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  FFXBattleActorRecord *actorData_1; // edx
  int v25; // eax
  int currentMagic_1; // eax
  FFXBattleActorRecord *actorData_2; // edx
  FFX_ElementType element_1; // ecx
  int v29; // eax
  int v30; // eax
  int v31; // eax
  FFXBattleActorRecord *actorData_3; // edx
  FFX_ElementType element_2; // ecx
  FFXBattleActorRecord *actorData_4; // edx
  FFX_OverdriveType odType; // ecx
  int currentMagic; // ecx
  FFXBattleActorRecord *formulaType_1; // edx
  int currentMagic_2; // eax
  int v39; // eax
  FFXBattleActorRecord *attacker_4; // edx
  FFX_DamageFormula EffectsAndMultipliers_1; // ecx
  int p_n2_1; // eax
  int v43; // eax
  int EffectsAndMultipliers_2; // eax
  int v45; // ecx
  FFXBattleActorRecord *actorData_5; // edx
  FFX_StatusEffect effect; // ecx
  __int16 v48; // ax
  int n9999; // ebx
  _DWORD *dmgBufferBase_1; // edx
  int *v51; // esi
  int *p_currentStrength; // ecx
  char *v53; // eax
  int n9999_1; // eax
  BOOL v55; // eax
  FFXBattleActorRecord *attacker_5; // edx
  FFX_DamageFormula formulaType_2; // ecx
  int v58; // eax
  int *n100_1; // edi
  int v61; // [esp-38h] [ebp-F8h]
  int n2_1; // [esp-34h] [ebp-F4h]
  FFXBattleActorData *defender_2; // [esp-30h] [ebp-F0h]
  int v64; // [esp-10h] [ebp-D0h]
  int v65; // [esp+Ch] [ebp-B4h]
  int v66; // [esp+20h] [ebp-A0h]
  int v67; // [esp+28h] [ebp-98h]
  char n2; // [esp+38h] [ebp-88h]
  int outDefenderStat; // [esp+3Ch] [ebp-84h]
  int v70; // [esp+40h] [ebp-80h] BYREF
  int v71; // [esp+44h] [ebp-7Ch]
  int p_n3; // [esp+48h] [ebp-78h] BYREF
  int n100; // [esp+4Ch] [ebp-74h]
  int EffectsAndMultipliers; // [esp+50h] [ebp-70h]
  int basePowera; // [esp+54h] [ebp-6Ch]
  int p_n2; // [esp+58h] [ebp-68h] BYREF
  FFX_DamageFormula formulaType; // [esp+5Ch] [ebp-64h]
  int v78; // [esp+60h] [ebp-60h] BYREF
  int p_n17; // [esp+64h] [ebp-5Ch] BYREF
  __int16 v80[2]; // [esp+68h] [ebp-58h] BYREF
  FFXBattleActorData *defender_1; // [esp+6Ch] [ebp-54h]
  _DWORD effectCounters[3]; // [esp+70h] [ebp-50h] BYREF
  int v83; // [esp+7Ch] [ebp-44h]
  int v84; // [esp+80h] [ebp-40h]
  int v85; // [esp+84h] [ebp-3Ch]
  int v86; // [esp+88h] [ebp-38h]
  int v87; // [esp+8Ch] [ebp-34h]
  int hitCounters[4]; // [esp+90h] [ebp-30h] BYREF
  int v89; // [esp+A0h] [ebp-20h]
  int v90; // [esp+A4h] [ebp-1Ch]
  int v91; // [esp+A8h] [ebp-18h]
  int v92; // [esp+ACh] [ebp-14h]
  int p_n10000; // [esp+B0h] [ebp-10h] BYREF
  int n10000; // [esp+B4h] [ebp-Ch]
  int v95; // [esp+B8h] [ebp-8h]
  FFXBattleActorRecord *n8; // [esp+D0h] [ebp+10h]
  FFXBattleActorData *defender; // [esp+D4h] [ebp+14h]
  int cmdCtx; // [esp+D8h] [ebp+18h]
  int n12524; // [esp+DCh] [ebp+1Ch]
  int hitResultCtx; // [esp+E0h] [ebp+20h]
  int dmgBufferBase; // [esp+E4h] [ebp+24h]
  _DWORD *counterPtr; // [esp+E8h] [ebp+28h]
  int hitResultCode; // [esp+ECh] [ebp+2Ch]
  int *outValue; // [esp+F0h] [ebp+30h]

  p_n17 = hitResultCode; // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass.
  *(_DWORD *)v80 = 0;
  EffectsAndMultipliers = 0;
  v66 = 0;
  p_n3 = 0;
  p_n10000 = 0;
  n10000 = 0;
  v95 = 0;
  n2 = 0;
  p_n2 = 0;
  v65 = *(_DWORD *)&defender->pad1739_pre[4];
  n100 = defender->defense;
  v4 = (*(_DWORD *)(cmdCtx + 28) & 0x40000) == 0;
  magicDefense = defender->magicDefense;
  defender_1 = defender;
  memset(hitCounters, 0, sizeof(hitCounters));
  memset(effectCounters, 0, sizeof(effectCounters));
  v83 = 0;
  v89 = 0;
  v84 = 0;
  v90 = 0;
  v85 = 0;
  v91 = 0;
  v86 = 0;
  v92 = 0;
  v87 = 0;
  v70 = 0;
  v71 = 0;
  outDefenderStat = magicDefense;
  if ( v4 )
  {
    formulaType = *(unsigned __int8 *)(cmdCtx + 40);
    basePowera = *(unsigned __int8 *)(cmdCtx + 42);
    v8 = *(unsigned __int16 *)(cmdCtx + 84);
  }
  else
  {
    formulaType = *(unsigned __int8 *)(basePower + 1473);
    basePowera = *(unsigned __int8 *)(basePower + 1479);
    v6 = *(unsigned __int16 *)(basePower + 1540);
    v7 = *(unsigned __int16 *)(cmdCtx + 84);
    if ( (v7 & 0x3E) != 0 )
      v6 &= 0xFFC1u;
    v8 = v7 | v6;
  }
  v67 = v8;
  v78 = FFX_Battle_CheckPreemptiveAttack(0, (int)target, basePower, (int)n8, (int)defender, cmdCtx);
  FFX_Battle_ResolveHitElementalCounters(element, attacker_1, (FFXBattleActorRecord *)cmdCtx);
  if ( v13 )
  {
    *(_DWORD *)v80 = *(unsigned __int8 *)(cmdCtx + 35);
    v64 = *(unsigned __int8 *)(hitResultCtx + 7);
    n2_1 = *(_WORD *)(cmdCtx + 32) & 3;
    v70 = 1;
    n2 = 2;
    p_n17 = FFX_Btl_LoadMonsterBins(
              (int)target,
              (int)n8,
              n2_1,
              0,
              0,
              0,
              &p_n10000,
              hitCounters,
              effectCounters,
              cmdCtx,
              0,
              v64,
              v80[0],
              0,
              &v70);
    if ( !v78 )
      goto LABEL_35;
  }
  else
  {
    FFX_Battle_ResolveHitAccuracyAndEffects(hitType, attacker_2, (FFXBattleActorRecord *)basePower);
    if ( n2_3 == 1 )
    {
      n2 = 1;
      ++*(_DWORD *)p_n17;
      if ( target != n8 || (n2_2 = *(_BYTE *)(cmdCtx + 32) & 3, p_n17 = 17, n2_2 == 2) )
        p_n17 = 1;
      v71 = 1;
    }
    else
    {
      if ( n2_3 == 2 )
      {
        p_n17_1 = (_DWORD *)p_n17;
        p_n17 = 0;
        ++*p_n17_1;
        v71 = 1;
        goto LABEL_35;
      }
      ++*counterPtr;
      v18 = *(unsigned __int8 *)(cmdCtx + 35);
      *(_DWORD *)v80 = v18;
      v78 = v18;
      if ( basePowera )
      {
        if ( (v18 & 1) != 0 )
        {
          FFX_Battle_ProcessPhysicalHitStatus(DMGFLAG_PHYSICAL, actorData);
          v20 = FFX_Battle_DamageFormulaDispatch(
                  (FFX_DamageFormula)(1 - unk_112A908),
                  attacker_3,
                  (FFXBattleActorRecord *)basePower,
                  (int)defender_1);
          v21 = FFX_Battle_ComputeDamageQuarterMultiplier((int)defender_1, v80, v20);
          v22 = FFX_Battle_ComputeMagicGuardHalving(cmdCtx, (int *)v80, &p_n2, hitResultCtx, v21);
          v23 = FFX_Battle_ComputePhysGuardHalving(cmdCtx, (int *)v80, &p_n2, hitResultCtx, v22);
          if ( !unk_112A909 )
            v23 = FFX_Battle_ComputeCriticalHit((unsigned __int8 *)basePower, (int)defender_1, cmdCtx, v80, v23);
          p_n17 = FFX_Battle_ComputeDoublecastDamage((_WORD *)basePower, v23);
          FFX_Battle_CheckZanmatoOrInstantKill(basePower, cmdCtx, n12524, &p_n17);
          FFX_Battle_CheckDoubleDamagePierce(basePower, cmdCtx, n12524, formulaType, p_n17);
          FFX_Battle_ApplyElementAffinityModifier((FFX_ElementType)target, actorData_1, (int)target);
          currentMagic_1 = FFX_Battle_ComputeMagicAbsorb((int)defender_1, formulaType, &v78, 1, &v70, v25);
          FFX_Battle_ApplyDamagePolarityReversal(basePower, cmdCtx, hitResultCtx, currentMagic_1);
          FFX_Battle_ApplyElementResist(element_1, actorData_2, &defender_1->modelHandle);
          v30 = FFX_Battle_ComputeShieldDamage(basePower, defender_1, cmdCtx, hitResultCtx, &p_n3, v29);
          v31 = FFX_Battle_ComputeGuardDamage((int)defender_1, cmdCtx, v80, hitResultCtx, v30);
          FFX_Battle_ApplyPierceDamageHalving(basePower, cmdCtx, v31);
          FFX_Battle_TryConsumeElementNullStatus(element_2, actorData_3);
          p_n10000 = FFX_Battle_ComputeOverdriveDamageMul(odType, actorData_4);
          n2 = p_n2;
          v18 = *(_DWORD *)v80;
        }
        if ( (v18 & 2) != 0 )
        {
          p_n17 = FFX_Battle_DamageFormulaDispatch(
                    (FFX_DamageFormula)(1 - unk_112A908),
                    actorData,
                    (FFXBattleActorRecord *)basePower,
                    (int)defender_1);
          FFX_Battle_CheckZanmatoOrInstantKill(basePower, cmdCtx, n12524, &p_n17);
          currentMagic = FFX_Battle_CheckDoubleDamagePierce(basePower, cmdCtx, n12524, formulaType, p_n17);
          if ( currentMagic > 0 && defender_1->currentMagic < currentMagic )
            currentMagic = defender_1->currentMagic;
          n10000 = FFX_Battle_ApplyDamagePolarityReversal(basePower, cmdCtx, hitResultCtx, currentMagic);
          v18 = *(_DWORD *)v80;
        }
        else
        {
          formulaType_1 = (FFXBattleActorRecord *)formulaType;
        }
        if ( (v18 & 4) != 0 )
        {
          v78 &= ~4u;
          currentMagic_2 = FFX_Battle_DamageFormulaDispatch(
                             (FFX_DamageFormula)(1 - unk_112A908),
                             formulaType_1,
                             (FFXBattleActorRecord *)basePower,
                             (int)defender_1);
          v95 = FFX_Battle_ApplyDamagePolarityReversal(basePower, cmdCtx, hitResultCtx, currentMagic_2);
          v18 = *(_DWORD *)v80;
        }
      }
      v39 = FFX_Battle_ApplyDamageAmplifier(defender_1, cmdCtx, v18, &p_n10000);
      EffectsAndMultipliers_1 = FFX_Battle_CheckAssessConceal(defender_1, hitResultCtx, &v78, 4, v39, &v70, &p_n10000);
      p_n2_1 = *(unsigned __int16 *)(hitResultCtx + 20);
      EffectsAndMultipliers = EffectsAndMultipliers_1;
      p_n2 = p_n2_1;
      if ( !unk_112A906 )
      {
        v43 = FFX_Battle_MainDamageFormula(EffectsAndMultipliers_1, attacker_4, target, basePower);
        EffectsAndMultipliers_2 = FFX_Battle_ResolveHitTargetEffectsAndMultipliers(
                                    (int)target,
                                    basePower,
                                    (int)n8,
                                    defender_1,
                                    cmdCtx,
                                    hitCounters,
                                    effectCounters,
                                    hitResultCtx,
                                    v43,
                                    &p_n10000,
                                    v67);
        v4 = (*(_BYTE *)(hitResultCtx + 20) & 4) == 0;
        EffectsAndMultipliers = EffectsAndMultipliers_2;
        if ( v4 )
          *(_BYTE *)(hitResultCtx + 6) |= *(_BYTE *)(cmdCtx + 90);
        LOBYTE(p_n2_1) = p_n2;
      }
      FFX_Battle_CheckEjectHit(defender_1, hitResultCtx, p_n2_1, &v78, hitCounters, &p_n10000);
      FFX_Battle_TrackDeathAndOverkill(v45, &p_n10000, hitCounters, effectCounters, EffectsAndMultipliers, 0);
      *(_DWORD *)v80 = FFX_Battle_CheckFirstStrikeMultiplier(
                         (int)defender_1,
                         hitResultCtx,
                         p_n2,
                         EffectsAndMultipliers,
                         &p_n10000);
      FFX_Battle_ApplyStatusEffectFromMask(effect, actorData_5);
      FFX_Battle_ComputeOverdriveChargeFromHit((int)n8, defender_1, cmdCtx, hitCounters, hitResultCtx);
      v66 = v78;
      p_n17 = FFX_Btl_LoadMonsterBins(
                (int)target,
                (int)n8,
                *(_WORD *)(cmdCtx + 32) & 3,
                p_n3,
                n100,
                outDefenderStat,
                &p_n10000,
                hitCounters,
                effectCounters,
                cmdCtx,
                *(_WORD *)(hitResultCtx + 20),
                *(unsigned __int8 *)(hitResultCtx + 7),
                v80[0],
                v78,
                &v70);
    }
  }
  FFX_Battle_CheckPreemptiveAttack(1, (int)target, basePower, (int)n8, (int)defender_1, cmdCtx);
LABEL_35:
  if ( MEMORY[0x112A90E] )
  {
    if ( (v80[0] & 1) != 0 )
      p_n10000 = 1;
    if ( (v80[0] & 2) != 0 )
      n10000 = 1;
  }
  if ( MEMORY[0x112A90F] )
  {
    if ( (v80[0] & 1) != 0 )
      p_n10000 = 10000;
    if ( (v80[0] & 2) != 0 )
      n10000 = 10000;
  }
  if ( MEMORY[0x112A910] )
  {
    if ( (v80[0] & 1) != 0 )
      p_n10000 = 100000;
    if ( (v80[0] & 2) != 0 )
      n10000 = 100000;
  }
  v48 = *(_WORD *)(cmdCtx + 32);
  n9999 = (*(_WORD *)(basePower + 1726) & 0x800) != 0 ? 99999 : 9999;
  if ( (v48 & 0x80u) == 0 )
  {
    if ( (v48 & 0x40) != 0 )
      n9999 = 9999;
  }
  else
  {
    n9999 = 99999;
  }
  if ( (*(_BYTE *)(basePower + 1600) & 8) != 0 && (v80[0] & 1) != 0 )
  {
    if ( (unsigned int)(p_n10000 - 1) > 0x270D )
    {
      if ( (unsigned int)(p_n10000 + 9998) <= 0x270D )
        p_n10000 = -9999;
    }
    else
    {
      p_n10000 = 9999;
    }
  }
  dmgBufferBase_1 = (_DWORD *)dmgBufferBase;
  n100 = hitResultCtx + 32;
  v51 = (int *)(hitResultCtx + 32);
  p_currentStrength = &defender_1->currentStrength;
  v53 = (char *)&p_n10000 - dmgBufferBase;
  p_n3 = 3;
  do
  {
    n9999_1 = *(_DWORD *)((char *)dmgBufferBase_1 + (_DWORD)v53);
    if ( n9999_1 >= -n9999 )
    {
      if ( n9999_1 > n9999 )
        n9999_1 = n9999;
    }
    else
    {
      n9999_1 = -n9999;
    }
    *v51 = n9999_1;
    p_currentStrength[404] += n9999_1;
    *p_currentStrength -= n9999_1;
    if ( dmgBufferBase )
      *dmgBufferBase_1 -= n9999_1;
    v55 = *p_currentStrength < 0;
    ++v51;
    ++dmgBufferBase_1;
    ++p_currentStrength;
    *(p_currentStrength - 1) = v55 ? 0 : *(p_currentStrength - 1);
    v4 = p_n3-- == 1;
    v53 = (char *)&p_n10000 - dmgBufferBase;
  }
  while ( !v4 );
  if ( v65 - *(_DWORD *)n100 <= 0 )
    *(_DWORD *)v80 |= 0x80u;
  *(_BYTE *)hitResultCtx = p_n17;
  *(_BYTE *)(hitResultCtx + 1) = FFX_Battle_CheckHitResultCounters(v66, &v70);
  *(_WORD *)(hitResultCtx + 24) = v80[0];
  defender_2 = defender_1;
  *(_WORD *)(hitResultCtx + 26) = EffectsAndMultipliers;
  *(_BYTE *)(hitResultCtx + 2) = (_BYTE)attacker_5;
  *(_BYTE *)(hitResultCtx + 3) = n2;
  v58 = FFX_Battle_DamageFormulaDispatch(formulaType_2, attacker_5, (FFXBattleActorRecord *)basePower, (int)defender_2);
  v61 = v89;
  *(_DWORD *)(hitResultCtx + 28) = v58;
  *(_BYTE *)(hitResultCtx + 4) = v92;
  n100_1 = (int *)n100;
  FFX_Battle_CheckStatModifiersActive((int)target, basePower, cmdCtx, (int *)n100, v61);
  if ( v83 )
    *(_BYTE *)(basePower + 3562) = 7;
  if ( outValue )
    *outValue = v89;
  return *n100_1;
}
/* Orphan comments:
[Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass.
*/