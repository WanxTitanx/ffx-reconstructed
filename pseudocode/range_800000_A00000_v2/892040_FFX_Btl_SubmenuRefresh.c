// Function: FFX_Btl_SubmenuRefresh
// Address: 0x892040
// [Jarvis naming goal 2026-06-17] Battle submenu refresh/frame updater; calls Overdrive submenu row builder when row data changes and updates per-row position/cost/charge-ratio state. Fahrenheit external name TOBtlCtrlStatusWin is treated as alias/evidence, not sole source.
int FFX_Btl_SubmenuRefresh()
{
  unsigned __int8 v0; // bl
  char n3; // bl
  float *PartyDataArray; // eax
  int i; // ecx
  __int16 *v4; // ebx
  char *v5; // esi
  int n255; // eax
  int ActorCtbGaugeCurrent; // eax
  int ActorCtbGaugeTarget; // edi
  int ActorCtbTurns; // eax
  int i_4; // edx
  int i_3; // eax
  unsigned int v12; // edx
  char v13; // cl
  char n2; // al
  int ActorCtbGaugeTarget_1; // eax
  char v16; // cl
  int v17; // edi
  int n255_1; // ecx
  __int16 i_2; // [esp-10h] [ebp-28h]
  __int16 v20; // [esp-8h] [ebp-20h]
  __int16 v21; // [esp-4h] [ebp-1Ch]
  int v22; // [esp+Ch] [ebp-Ch] BYREF
  int ActorCtbTurns_1; // [esp+10h] [ebp-8h]
  int i_1; // [esp+14h] [ebp-4h] BYREF

  if ( unk_23CC088[0] == 255 )
    goto LABEL_7;
  v0 = *((_BYTE *)FFX_Btl_LookupCommandDataById(unk_133C91C[120 * unk_23CC092[0]], &v22) + 34);
  if ( (v0 & 1) == 0 )
  {
    FFX_Battle_SubmenuOvrRowBuild();
LABEL_7:
    n3_3 = 3;
    goto LABEL_8;
  }
  n3 = (v0 >> 1) & 3;
  if ( n3_3 != n3 )
    FFX_Battle_SubmenuOvrRowBuild();
  n3_3 = n3;
LABEL_8:
  i_1 = 0;
  PartyDataArray = FFX_Btl_GetPartyDataArray(0, 18, &i_1);
  for ( i = i_1; i > 0; i_1 = --i )
  {
    if ( *((_WORD *)PartyDataArray + i - 1) != 255 )
      break;
  }
  if ( *(_DWORD *)PartyDataArray != *(_DWORD *)unk_133F76C || *((_WORD *)PartyDataArray + 2) != unk_133F770 )
    FFX_Battle_SubmenuOvrRowBuild();
  v4 = unk_133F76C;
  v5 = (char *)&unk_133F7AC;
  do
  {
    n255 = (unsigned __int16)*v4;
    if ( (_WORD)n255 != 255 )
    {
      ActorCtbGaugeCurrent = FFX_Btl_GetActorCtbGaugeCurrent(*v4);
      v20 = *v4;
      i_1 = ActorCtbGaugeCurrent;
      ActorCtbGaugeTarget = FFX_Btl_GetActorCtbGaugeTarget(v20);
      ActorCtbTurns = FFX_Btl_GetActorCtbTurns(*v4);
      i_2 = *v4;
      ActorCtbTurns_1 = ActorCtbTurns;
      FFX_Btl_GetActorCtbSpeed(i_2);
      i_4 = *((_DWORD *)v5 - 2);
      i_3 = i_1;
      if ( i_1 != i_4 )
      {
        v12 = (int)((unsigned __int64)(1717986919LL * (i_1 - i_4)) >> 32) >> 2;
        *(_DWORD *)v5 = v12 + (v12 >> 31);
        i_3 = i_1;
        v5[4] = 10;
        *((_DWORD *)v5 - 2) = i_3;
      }
      v13 = v5[4];
      if ( v13 <= 0 )
      {
        *((_DWORD *)v5 - 1) = i_3;
        *(_DWORD *)v5 = 0;
        v5[4] = 0;
      }
      else
      {
        *((_DWORD *)v5 - 1) += *(_DWORD *)v5;
        v5[4] = v13 - 1;
      }
      switch ( FFX_Btl_ComputeCtbStateFromODRatio(*((_DWORD *)v5 - 1), ActorCtbTurns_1) )
      {
        case 1:
        case 2:
          n2 = 2;
          break;
        case 3:
          n2 = 83;
          break;
        default:
          n2 = 0;
          break;
      }
      v5[5] = n2;
      ActorCtbGaugeTarget_1 = *((_DWORD *)v5 + 4);
      if ( ActorCtbGaugeTarget != ActorCtbGaugeTarget_1 )
      {
        v5[28] = 10;
        *((_DWORD *)v5 + 6) = (ActorCtbGaugeTarget - ActorCtbGaugeTarget_1) / 10;
        *((_DWORD *)v5 + 4) = ActorCtbGaugeTarget;
      }
      v16 = v5[28];
      if ( v16 <= 0 )
      {
        *((_DWORD *)v5 + 5) = ActorCtbGaugeTarget;
        *((_DWORD *)v5 + 6) = 0;
        v5[28] = 0;
      }
      else
      {
        *((_DWORD *)v5 + 5) += *((_DWORD *)v5 + 6);
        v5[28] = v16 - 1;
      }
      v21 = *v4;
      v5[29] = 0;
      if ( FFX_Btl_GetOverdriveChargeMax(v21) <= 0 )
      {
        *((_DWORD *)v5 + 8) = 0;
      }
      else
      {
        v17 = unk_25D0AA4 * FFX_Btl_GetOverdriveCharge(*v4);
        *((_DWORD *)v5 + 8) = v17 / FFX_Btl_GetOverdriveChargeMax(*v4);
      }
      n255 = *((_DWORD *)v5 + 9);
      n255_1 = *((_DWORD *)v5 + 8);
      if ( n255 < n255_1 )
      {
        n255 += 6;
        *((_DWORD *)v5 + 9) = n255;
      }
      if ( *((_DWORD *)v5 + 9) > n255_1 )
        *((_DWORD *)v5 + 9) = n255_1;
    }
    ++v4;
    v5 += 144;
  }
  while ( (int)v4 < (int)&unk_133F772 );
  return n255;
}
