// Function: sub_8158F0
// Address: 0x8158f0
int __cdecl sub_8158F0(int a1, int a2)
{
  int v3; // edx
  float *v4; // edi
  __int16 v5; // cx
  __int16 v6; // bx
  int v7; // eax
  float *v8; // ebx
  int (__cdecl *sub_610000_1)(int, int); // ecx
  double v10; // st7
  double v11; // st6
  int v12; // esi
  int v14; // eax
  float *v15; // esi
  __int16 v16; // si
  double v17; // st7
  int v18; // eax
  float *v19; // [esp+0h] [ebp-24h]
  float v20; // [esp+4h] [ebp-20h]
  int v21; // [esp+4h] [ebp-20h]
  float v22; // [esp+4h] [ebp-20h]
  float v23; // [esp+4h] [ebp-20h]
  int v24; // [esp+14h] [ebp-10h]
  int v25; // [esp+18h] [ebp-Ch]
  int CurrentBattleFormationId; // [esp+1Ch] [ebp-8h]
  int sub_610000_2; // [esp+20h] [ebp-4h]
  int v28; // [esp+2Ch] [ebp+8h]
  float v29; // [esp+2Ch] [ebp+8h]
  float v30; // [esp+2Ch] [ebp+8h]
  float v31; // [esp+2Ch] [ebp+8h]
  float v32; // [esp+2Ch] [ebp+8h]
  float v33; // [esp+30h] [ebp+Ch]
  float v34; // [esp+30h] [ebp+Ch]
  float v35; // [esp+30h] [ebp+Ch]
  float v36; // [esp+30h] [ebp+Ch]

  CurrentBattleFormationId = FFX_Btl_GetCurrentBattleFormationId();
  sub_610000_2 = sub_782A30();
  v3 = *(_DWORD *)(a1 + 860);
  v4 = *(float **)(a1 + 544);
  v24 = a2 + 2;
  v5 = *(_WORD *)(a1 + 538) >> 12;
  v25 = *(unsigned __int16 *)(a2 + 2);
  v6 = *(_WORD *)(a2 + 2);
  v28 = v3;
  switch ( v5 )
  {
    case 0:
      sub_7EA760(a1, v4 + 36, 1.0);
      if ( v6 )
      {
        v7 = sub_800F80((_DWORD *)(a1 + 768), (int)v4, v6);
        v20 = 1.0;
        v25 = v7;
        v19 = (float *)(v7 + 144);
      }
      else
      {
        v20 = 0.0625;
        v19 = v4 + 12;
      }
      v8 = (float *)(a1 + 16);
      sub_7EA760(a1 + 16, v19, LODWORD(v20));
      if ( CurrentBattleFormationId != 595 && CurrentBattleFormationId != 148 )
        goto LABEL_28;
      if ( (int)(*(float *)(a1 + 4) * 10.0) == -205 )
      {
        *(float *)a1 = *(float *)a1 + 9.0;
        *(float *)(a1 + 8) = *(float *)(a1 + 8) + 3.0;
      }
      sub_610000_1 = (int (__cdecl *)(int, int))sub_610000_2;
      if ( (_UNKNOWN *)sub_610000_2 == &unk_1610014 )
      {
        if ( (int)*(float *)a1 > 12 || (int)*(float *)(a1 + 4) > 73 )
        {
LABEL_28:
          sub_610000_1 = (int (__cdecl *)(int, int))sub_610000_2;
        }
        else
        {
          sub_610000_1 = (int (__cdecl *)(int, int))sub_610000_2;
          if ( (int)(*(float *)(a1 + 24) * 100.0) == -4159 )
          {
            *(float *)a1 = (*v8 - *(float *)a1) * 0.300000011920929 + *(float *)a1;
            *(float *)(a1 + 4) = (*(float *)(a1 + 20) - *(float *)(a1 + 4)) * 0.300000011920929 + *(float *)(a1 + 4);
            *(float *)(a1 + 8) = 0.300000011920929 * (*(float *)(a1 + 24) - *(float *)(a1 + 8)) + *(float *)(a1 + 8);
            *(float *)(a1 + 20) = (*(float *)(a1 + 20) - *(float *)(a1 + 4)) * 0.3199999928474426 + *(float *)(a1 + 20);
          }
        }
        goto LABEL_29;
      }
      if ( (_UNKNOWN *)sub_610000_2 != &unk_2380000 && (_UNKNOWN *)sub_610000_2 != &unk_1050032 )
      {
        if ( (_UNKNOWN *)(sub_610000_2 & 0xFFFF0000) == &unk_F50000
          && *(float *)(a1 + 4) == -20.5
          && *(float *)(a1 + 20) == -13.0 )
        {
          v10 = *v8 - *(float *)a1;
          v11 = 0.3499999940395355;
        }
        else if ( (_UNKNOWN *)sub_610000_2 == &unk_14C0000
               && *(float *)(a1 + 4) == -20.5
               && *(float *)(a1 + 20) == -13.0 )
        {
          v10 = *v8 - *(float *)a1;
          v11 = 0.4000000059604645;
        }
        else
        {
          v10 = *v8 - *(float *)a1;
          v11 = 0.25;
        }
        goto LABEL_25;
      }
      *(float *)a1 = (*v8 - *(float *)a1) * 0.25 + *(float *)a1;
      *(float *)(a1 + 4) = (*(float *)(a1 + 20) - *(float *)(a1 + 4)) * 0.25 + *(float *)(a1 + 4);
      *(float *)(a1 + 8) = 0.25 * (*(float *)(a1 + 24) - *(float *)(a1 + 8)) + *(float *)(a1 + 8);
      sub_610000_1 = (int (__cdecl *)(int, int))sub_610000_2;
      if ( (int)*(float *)(a1 + 4) == -18 )
      {
        v10 = *v8 - *(float *)a1;
        v11 = 0.2000000029802322;
LABEL_25:
        *(float *)a1 = v10 * v11 + *(float *)a1;
        *(float *)(a1 + 4) = (*(float *)(a1 + 20) - *(float *)(a1 + 4)) * v11 + *(float *)(a1 + 4);
        *(float *)(a1 + 8) = v11 * (*(float *)(a1 + 24) - *(float *)(a1 + 8)) + *(float *)(a1 + 8);
      }
LABEL_29:
      if ( CurrentBattleFormationId == 306 )
      {
        if ( sub_610000_1 == sub_610000 && *(float *)(a1 + 4) > -85.0 )
          *(float *)(a1 + 4) = -85.0;
      }
      else if ( CurrentBattleFormationId == 170 && -11.0 == v4[37] && -17.0 == *(float *)(v25 + 148) && 0.0 == v4[15] )
      {
        v4[15] = 400.0;
      }
      v21 = a1;
      v12 = v28;
      FFX_BtlPool_WriteEntryTransform(v28, 1, v21);
      FFX_BtlPool_WriteEntryTransform(v28, 0, (int)v8);
      v29 = v4[19] * 3.141592025756836 * 0.00048828125;
      FFX_BtlPool_SetPositionParameter(v12, v29);
      v30 = v4[15] + 1024.0;
      FFX_BtlPool_SetSpeedParameter(v12, v30);
      return a2 + 4;
    case 1:
      nullsub_91(0);
      sub_79DDD0(1);
      v14 = sub_787890(4, 0, 7);
      *(_DWORD *)(a1 + 860) = v14;
      FFX_BtlCleanup_ReleasePoolEntry(v14, 0);
      FFX_BtlCleanup_ReleasePoolEntry(*(_DWORD *)(a1 + 860), 1);
      return a2 + 4;
    case 2:
      if ( unk_2322790 )
      {
        nullsub_91(1);
        v3 = v28;
      }
      if ( v3 )
      {
        sub_79DDD0(0);
        if ( !FFX_Battle_QueueGateCheck() )
          FFX_Btl_Death_ClearEffectPointerTable(0);
      }
      *(_DWORD *)(a1 + 860) = 0;
      return a2 + 4;
    case 3:
      sub_7BC040(v4[36], v4[37]);
      return a2 + 4;
    case 4:
      v15 = v4 + 36;
      sub_7BD3F0(1, v4 + 36);
      goto LABEL_48;
    case 5:
      v15 = v4 + 36;
      sub_7BD3F0(0, v4 + 36);
LABEL_48:
      sub_7EA760(v4 + 16, v15, 16.0);
      return a2 + 4;
    case 6:
      v16 = *(_WORD *)(a2 + 4);
      v33 = (float)(__int16)v25;
      v34 = v33 + 1024.0;
      FFX_BtlPool_SetSpeedParameter(v3, v34);
      v35 = (float)v16;
      v36 = v35 * 3.141592025756836 * 0.00048828125;
      FFX_BtlPool_SetPositionParameter(v28, v36);
      return v24 + 4;
    case 7:
      sub_7EA760(a1, v4 + 36, 1.0);
      if ( v6 )
      {
        v17 = 1.0;
        v18 = sub_800F80((_DWORD *)(a1 + 768), (int)v4, v6) + 144;
      }
      else
      {
        v17 = 0.0625;
        v18 = (int)(v4 + 12);
      }
      v22 = v17;
      sub_7EA760(a1 + 16, v18, LODWORD(v22));
      v31 = v4[19] * 3.141592025756836 * 0.00048828125;
      v23 = v31;
      v32 = v4[15] + 1024.0;
      sub_7BBA90(a1 + 16, a1, v32, v23);
      return a2 + 4;
    case 8:
      sub_7BBA80();
      return a2 + 4;
    case 9:
      unk_11A004C = v25 + 4096;
      sub_8176D0(a1 + 768);
      return a2 + 4;
    case 10:
      unk_11A004C = 0;
      return a2 + 4;
    default:
      return a2 + 4;
  }
}
