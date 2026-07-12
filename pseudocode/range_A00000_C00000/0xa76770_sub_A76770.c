// Function: sub_A76770
// Address: 0xa76770
// Size: 0x3c9
// Prototype: 

void __cdecl sub_A76770(int a1, int a2)
{
  int CurrentBattleFormationId; // eax
  int v3; // ebx
  int v4; // edx
  __int16 v5; // cx
  int v6; // ebx
  __int16 v7; // di
  int j; // esi
  __int16 v9; // ax
  __int16 i_1; // ax
  __int16 i_2; // ax
  double v12; // st7
  double v13; // st6
  double v14; // st5
  double v15; // st4
  double v16; // st3
  float v17; // esi
  int n32; // edi
  double v19; // rt2
  double v20; // st3
  double v21; // st6
  double v22; // rtt
  double i_4; // st4
  double v24; // st5
  double v25; // st4
  double v26; // st4
  double v27; // st7
  double v28; // st6
  double v29; // st7
  double v30; // st4
  double v31; // st7
  double v32; // st6
  double v33; // st5
  int v34; // ebx
  float v35; // eax
  int v36; // esi
  int v37; // eax
  int v38; // esi
  int CurrentBattleFormationId_2; // edi
  __int64 v40; // [esp-34h] [ebp-B8h]
  __int64 n2622; // [esp-14h] [ebp-98h]
  __int64 n2622_1; // [esp-10h] [ebp-94h]
  char v43[28]; // [esp+10h] [ebp-74h] BYREF
  int v44; // [esp+2Ch] [ebp-58h]
  char v45[28]; // [esp+30h] [ebp-54h] BYREF
  int v46; // [esp+4Ch] [ebp-38h]
  double v47; // [esp+50h] [ebp-34h]
  double v48; // [esp+58h] [ebp-2Ch]
  int CurrentBattleFormationId_1; // [esp+60h] [ebp-24h]
  int v50; // [esp+64h] [ebp-20h]
  float v51; // [esp+68h] [ebp-1Ch]
  float v52; // [esp+6Ch] [ebp-18h]
  float v53; // [esp+70h] [ebp-14h]
  float v54; // [esp+74h] [ebp-10h]
  float i_3; // [esp+78h] [ebp-Ch]
  float v56; // [esp+7Ch] [ebp-8h]
  int i; // [esp+80h] [ebp-4h]

  if ( !unk_12FB790 )
  {
    CurrentBattleFormationId = FFX_Btl_GetCurrentBattleFormationId();
    v3 = *(_DWORD *)(a1 + 808);
    CurrentBattleFormationId_1 = CurrentBattleFormationId;
    v4 = v3 + 48;
    *(_DWORD *)(v3 + 16) = 134218240;
    *(_DWORD *)v3 = 0;
    LODWORD(v51) = v3 + 53312;
    *(_DWORD *)(v3 + 4) = 32;
    *(_DWORD *)(v3 + 8) = 20544;
    *(_DWORD *)(v3 + 12) = 0;
    *(_DWORD *)(v3 + 20) = 8912896;
    *(_WORD *)(v3 + 32) = 1536;
    v5 = 0;
    *(_WORD *)(v3 + 34) = *(_WORD *)(v3 + 16);
    v50 = v3;
    LODWORD(v53) = v3 + 20544;
    *(_DWORD *)(v3 + 40) = 6656;
    v56 = 0.0;
    for ( i = 0; i < 3328; i += 208 )
    {
      v6 = 0;
      v7 = 33 * v5;
      for ( j = 0; j < 4096; j += 128 )
      {
        *(_WORD *)(v4 + 24) = j;
        *(_WORD *)(v4 + 16) = v6 + v7;
        *(_WORD *)(v4 + 18) = v6 + v7 + 1;
        v9 = v7 + v6 + 33;
        *(_WORD *)(v4 + 20) = v9;
        *(_WORD *)(v4 + 22) = v9 + 1;
        i_1 = i;
        *(_WORD *)(v4 + 26) = i;
        *(_WORD *)(v4 + 30) = i_1;
        i_2 = i;
        *(_WORD *)(v4 + 28) = j + 128;
        i_2 += 208;
        *(_WORD *)(v4 + 32) = j;
        *(_WORD *)(v4 + 34) = i_2;
        *(_WORD *)(v4 + 36) = j + 128;
        *(_WORD *)(v4 + 38) = i_2;
        memset((void *)v4, 128, 16);
        v4 += 40;
        ++v6;
      }
      v5 = LOWORD(v56) + 1;
      ++LODWORD(v56);
    }
    *(_BYTE *)(v4 + 1) = -1;
    v54 = *(float *)(a2 + 48);
    i = 0;
    v52 = *(float *)(a2 + 52) * 0.00390625;
    v12 = v54 * v54;
    v48 = v12;
    v13 = 13.0;
    v14 = 104.0;
    v15 = 8.0;
    v16 = 128.0;
    while ( 1 )
    {
      v17 = v53;
      *(float *)&n32 = 0.0;
      v56 = 0.0;
      i_3 = (float)i;
      v19 = v16;
      v20 = v13 * i_3;
      v21 = v19;
      v22 = v15;
      i_4 = v20 - v14;
      v24 = v22;
      i_3 = i_4;
      v25 = i_3 * i_3;
      v47 = v25;
      while ( 1 )
      {
        v53 = (float)SLODWORD(v56);
        v56 = v24 * v53 - v21;
        v53 = v12 + v25 + v56 * v56;
        v53 = sqrt(v53);
        v27 = v53;
        v28 = v53;
        v53 = v53 - *(float *)(a2 + 48);
        v53 = v53 * v52;
        v53 = v28 - v53;
        v53 = v53 / v27;
        v29 = v53;
        v30 = v53 * i_3;
        *(_WORD *)LODWORD(v17) = (int)(v53 * v56 * 128.0 * 1.33299994468689);
        v31 = v29 * v54;
        *(_WORD *)(LODWORD(v17) + 2) = (int)(1.33299994468689 * (v30 * 128.0));
        v32 = v47;
        v33 = v48;
        ++n32;
        *(_WORD *)(LODWORD(v17) + 4) = (int)(v31 * -128.0);
        LODWORD(v17) += 6;
        v56 = *(float *)&n32;
        if ( n32 > 32 )
          break;
        v26 = v33;
        v24 = 8.0;
        v12 = v26;
        v25 = v32;
        v21 = 128.0;
      }
      v53 = v17;
      if ( ++i > 16 )
        break;
      v16 = 128.0;
      v12 = v48;
      v13 = 13.0;
      v15 = 8.0;
      v14 = 104.0;
    }
    v34 = a1 + 256;
    *(_DWORD *)(a1 + 280) = *(_DWORD *)(a2 + 200);
    *(_DWORD *)(a1 + 272) = 0;
    *(_DWORD *)(a1 + 276) = 0;
    *(_WORD *)(a1 + 264) = *(_WORD *)(a2 + 194);
    *(_DWORD *)(a1 + 256) = 144;
    *(_DWORD *)(a1 + 268) = 0;
    *(_DWORD *)(a1 + 284) = 0;
    *(_DWORD *)(a1 + 320) = *(_DWORD *)(a2 + 196);
    v35 = v51;
    *(_DWORD *)(a1 + 312) = 0;
    *(_DWORD *)(a1 + 316) = 0;
    *(_DWORD *)(a1 + 288) = a1 + 192;
    *(_DWORD *)(a1 + 324) = 0;
    *(float *)(a1 + 260) = v35;
    v36 = a1 + 128;
    v51 = *(float *)(a2 + 60) * 0.000000476837158203125;
    sub_7EA610((void *)(a1 + 128), v51);
    sub_7EA460(v36, v36, a2 + 144);
    v37 = sub_801E20(a1, a2);
    sub_7E82C0(v36, v37, v36);
    sub_7E7F20(a1 + 192, a1 + 128);
    v38 = v50;
    CurrentBattleFormationId_2 = CurrentBattleFormationId_1;
    *(_DWORD *)(a1 + 308) = *(_DWORD *)(a1 + 852);
    HIDWORD(v40) = CurrentBattleFormationId_2;
    LODWORD(v40) = 0;
    *(_DWORD *)(a1 + 312) = v38 + *(_DWORD *)(v38 + 8);
    if ( sub_645580(v40) )
    {
      v46 = v38;
      sub_7186F0(0, CurrentBattleFormationId_2, v45, v34);
      HIDWORD(n2622) = CurrentBattleFormationId_2;
      LODWORD(n2622) = 0;
      FFX_MagicHost_CommitDrawableResources(n2622);
    }
    else
    {
      HIDWORD(n2622_1) = CurrentBattleFormationId_2;
      LODWORD(n2622_1) = 0;
      v44 = v38;
      sub_711260(n2622_1, v43, v34, 8);
    }
  }
}

