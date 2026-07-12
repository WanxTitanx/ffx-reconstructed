// Function: sub_A53570
// Address: 0xa53570
// Size: 0x86a
// Prototype: 

int sub_A53570()
{
  int v0; // ecx
  unsigned __int8 n0xF; // al
  double v2; // st5
  double v3; // st7
  int n10; // eax
  int v5; // eax
  int v6; // esi
  __int16 n7; // cx
  int n12; // edi
  void (__cdecl **v9)(int); // esi
  int v10; // ecx
  int v11; // ecx
  float *v12; // ecx
  double v13; // st7
  double v14; // st6
  double v15; // st7
  double v16; // st6
  double v17; // st5
  int v18; // ecx
  int v19; // eax
  _DWORD *v20; // ecx
  _DWORD *v21; // ecx
  int result; // eax
  float n0xF_1; // [esp+14h] [ebp-18h]
  float v24; // [esp+14h] [ebp-18h]
  float n10_1; // [esp+14h] [ebp-18h]
  float v26; // [esp+14h] [ebp-18h]
  float v27; // [esp+14h] [ebp-18h]
  float v28; // [esp+14h] [ebp-18h]
  int v29; // [esp+18h] [ebp-14h] BYREF
  float v30; // [esp+1Ch] [ebp-10h]
  float v31; // [esp+20h] [ebp-Ch]
  float v32; // [esp+24h] [ebp-8h]

  v0 = dword_2305834[0];
  unk_1A85F70 = 1;
  if ( !*(_BYTE *)(dword_2305834[0] + 71096) )
  {
    *(_BYTE *)(unk_1A86108 + 5027) = 1;
    v0 = dword_2305834[0];
  }
  n0xF = *(_BYTE *)(v0 + 71096);
  if ( n0xF > 0x14u )
  {
    sub_A57520(0, v0 + 71276);
    v5 = dword_2305834[0];
    if ( *(_WORD *)(dword_2305834[0] + 71278) )
    {
      nullsub_34();
      v5 = dword_2305834[0];
    }
    v6 = unk_1A86108;
    if ( *(__int16 *)(unk_1A86108 + 9984) < 0 || *(__int16 *)(v5 + 71120) > 0 )
    {
      sub_A490C0();
      v5 = dword_2305834[0];
    }
    if ( *(__int16 *)(v6 + 9984) < 0 || *(__int16 *)(v5 + 71118) > 0 )
    {
      sub_A48F50();
      v5 = dword_2305834[0];
    }
    n7 = *(_WORD *)(v6 + 9984);
    if ( n7 >= 0 )
    {
      if ( n7 == 7 && (sub_A58EC0(), *(int (**)())(dword_2305834[0] + 71080) == sub_A59E80) )
        (*(void (**)(void))(dword_2305834[0] + 71080))();
      else
        sub_A583E0();
    }
    else if ( *(_DWORD *)(v5 + 71080) )
    {
      (*(void (**)(void))(v5 + 71080))();
    }
    n12 = 12;
    v9 = (void (__cdecl **)(int))(unk_1A86108 + 52);
    do
    {
      if ( *v9 )
        (*v9)((int)(v9 - 13));
      v9 += 208;
      --n12;
    }
    while ( n12 );
  }
  else
  {
    if ( n0xF )
    {
      if ( n0xF >= 0xFu )
      {
        *(float *)(v0 + 71144) = 1.0;
      }
      else
      {
        n0xF_1 = (float)n0xF;
        *(float *)(v0 + 71144) = n0xF_1 / 15.0;
      }
      v2 = 0.0;
      v3 = 128.0;
    }
    else
    {
      v2 = 0.0;
      v3 = 128.0;
      *(float *)(v0 + 71144) = 0.0;
    }
    v24 = *(float *)(v0 + 71144);
    *(float *)(dword_2305834[0] + 71152) = v24;
    *(float *)(dword_2305834[0] + 71148) = v24;
    n10 = *(unsigned __int8 *)(v0 + 71096) - 10;
    if ( n10 > 0 )
    {
      if ( n10 >= 10 )
      {
        *(float *)(dword_2305834[0] + 71156) = 1.0;
        *(_BYTE *)(dword_2305834[0] + 71097) = 0x80;
      }
      else
      {
        n10_1 = (float)n10;
        v26 = n10_1 / 10.0;
        *(float *)(dword_2305834[0] + 71156) = v26;
        *(_BYTE *)(dword_2305834[0] + 71097) = (int)(v3 * v26);
      }
      ++*(_BYTE *)(dword_2305834[0] + 71096);
    }
    else
    {
      *(float *)(dword_2305834[0] + 71156) = v2;
      *(_BYTE *)(dword_2305834[0] + 71097) = 0;
      ++*(_BYTE *)(dword_2305834[0] + 71096);
    }
  }
  sub_A47440();
  ++*(_DWORD *)(dword_2305834[0] + 71320);
  ++*(_DWORD *)(dword_2305834[0] + 71324);
  ++*(_DWORD *)(dword_2305834[0] + 71328);
  v10 = dword_2305834[0];
  if ( *(int *)(dword_2305834[0] + 71328) > 100 )
  {
    *(_DWORD *)(dword_2305834[0] + 71328) = 100;
    v10 = dword_2305834[0];
  }
  sub_6ED4B0(v10 + 70424, v10 + 70408);
  *(float *)&v29 = 341.0;
  v30 = 208.0;
  v31 = 0.0;
  v32 = 1.0;
  v27 = 1.0 / *(float *)(dword_2305834[0] + 70480);
  sub_6EDA30((int)&v29, (int)&v29, v27);
  v11 = dword_2305834[0];
  if ( *(float *)(dword_2305834[0] + 70424) >= *(float *)(dword_2305834[0] + 71164) + 128.0 + *(float *)&v29 )
  {
    if ( *(float *)(dword_2305834[0] + 70424) <= *(float *)(dword_2305834[0] + 71172) - 128.0 - *(float *)&v29
      || !*(_BYTE *)(dword_2305834[0] + 71104) )
    {
      goto LABEL_45;
    }
    *(_BYTE *)(dword_2305834[0] + 71104) = 0;
  }
  else
  {
    if ( *(_BYTE *)(dword_2305834[0] + 71104) == 1 )
      goto LABEL_45;
    *(_BYTE *)(dword_2305834[0] + 71104) = 1;
  }
  v11 = dword_2305834[0];
  if ( !*(_BYTE *)(dword_2305834[0] + 71098) )
  {
    *(_BYTE *)(dword_2305834[0] + 71106) = 1;
    v11 = dword_2305834[0];
  }
LABEL_45:
  *(float *)&v29 = 341.0;
  v30 = 208.0;
  v31 = 96.0;
  v32 = 1.0;
  v28 = 1.0 / *(float *)(v11 + 70480);
  sub_6EDA30((int)&v29, (int)&v29, v28);
  v12 = (float *)dword_2305834[0];
  *(float *)&v29 = *(float *)&v29 - v31;
  v30 = v30 - v31;
  v13 = *(float *)(dword_2305834[0] + 71164) + *(float *)&v29;
  v14 = *(float *)(dword_2305834[0] + 71172) - *(float *)&v29;
  if ( v14 >= v13 )
  {
    if ( *(float *)(dword_2305834[0] + 70424) >= v13 )
    {
      if ( *(float *)(dword_2305834[0] + 70424) > v14 )
      {
        *(float *)(dword_2305834[0] + 70424) = v14;
        v12 = (float *)dword_2305834[0];
      }
    }
    else
    {
      *(float *)(dword_2305834[0] + 70424) = v13;
      v12 = (float *)dword_2305834[0];
    }
    v15 = 0.0;
  }
  else
  {
    v15 = 0.0;
    *(float *)(dword_2305834[0] + 70424) = 0.0;
    v12 = (float *)dword_2305834[0];
  }
  v16 = v12[17792] + v30;
  v17 = v12[17794] - v30;
  if ( v17 >= v16 )
  {
    if ( v12[17607] >= v16 )
    {
      if ( v12[17607] > v17 )
      {
        v12[17607] = v17;
        v12 = (float *)dword_2305834[0];
      }
    }
    else
    {
      v12[17607] = v16;
      v12 = (float *)dword_2305834[0];
    }
  }
  else
  {
    v12[17607] = v15;
    v12 = (float *)dword_2305834[0];
  }
  sub_93D900(v12 + 17624);
  sub_72C8F0(dword_2305834[0] + 70688, dword_2305834[0] + 70464);
  sub_6ED4A0(dword_2305834[0] + 70752, dword_2305834[0] + 70496);
  sub_6ED700(dword_2305834[0] + 70880, dword_2305834[0] + 70816, dword_2305834[0] + 70752);
  v18 = dword_2305834[0];
  unk_C8F820 = *(float *)(dword_2305834[0] + 70480);
  unk_C8F824 = *(float *)(dword_2305834[0] + 70484);
  flt_C8F828 = *(float *)(dword_2305834[0] + 70488);
  unk_C8F82C = *(_DWORD *)(dword_2305834[0] + 70492);
  unk_C8F830 = *(float *)(dword_2305834[0] + 70688);
  unk_C8F834 = *(float *)(dword_2305834[0] + 70692);
  unk_C8F838 = *(float *)(dword_2305834[0] + 70696);
  unk_C8F83C = *(_DWORD *)(dword_2305834[0] + 70700);
  flt_C8F840 = *(float *)(dword_2305834[0] + 70704);
  flt_C8F844 = *(float *)(dword_2305834[0] + 70708);
  flt_C8F848 = *(float *)(dword_2305834[0] + 70712);
  unk_C8F84C = *(_DWORD *)(dword_2305834[0] + 70716);
  flt_C8F850 = *(float *)(dword_2305834[0] + 70720);
  flt_C8F854 = *(float *)(dword_2305834[0] + 70724);
  flt_C8F858 = *(float *)(dword_2305834[0] + 70728);
  v19 = *(_DWORD *)(dword_2305834[0] + 70732);
  unk_C8F830 = unk_C8F820 * unk_C8F830;
  unk_C8F85C = v19;
  unk_C8F834 = unk_C8F834 * unk_C8F820;
  unk_C8F838 = unk_C8F820 * unk_C8F838;
  flt_C8F840 = unk_C8F824 * flt_C8F840;
  flt_C8F844 = flt_C8F844 * unk_C8F824;
  flt_C8F848 = unk_C8F824 * flt_C8F848;
  flt_C8F850 = flt_C8F850 * flt_C8F828;
  flt_C8F854 = flt_C8F854 * flt_C8F828;
  flt_C8F858 = flt_C8F828 * flt_C8F858;
  *(float *)(dword_2305834[0] + 70688) = unk_C8F830;
  *(float *)(v18 + 70692) = unk_C8F834;
  *(float *)(v18 + 70696) = unk_C8F838;
  *(_DWORD *)(v18 + 70700) = unk_C8F83C;
  v20 = (_DWORD *)dword_2305834[0];
  *(float *)(dword_2305834[0] + 70704) = flt_C8F840;
  v20[17677] = LODWORD(flt_C8F844);
  v20[17678] = LODWORD(flt_C8F848);
  v20[17679] = unk_C8F84C;
  v21 = (_DWORD *)dword_2305834[0];
  *(float *)(dword_2305834[0] + 70720) = flt_C8F850;
  v21[17681] = LODWORD(flt_C8F854);
  v21[17682] = LODWORD(flt_C8F858);
  v21[17683] = unk_C8F85C;
  *(float *)(dword_2305834[0] + 70436) = 1.0;
  sub_6ED420(dword_2305834[0] + 70544, dword_2305834[0] + 70496, dword_2305834[0] + 70440);
  sub_6ED420(dword_2305834[0] + 70736, dword_2305834[0] + 70688, dword_2305834[0] + 70424);
  *(float *)(dword_2305834[0] + 70544) = -*(float *)(dword_2305834[0] + 70544);
  *(float *)(dword_2305834[0] + 70548) = -*(float *)(dword_2305834[0] + 70548);
  *(float *)(dword_2305834[0] + 70552) = 512.0 - *(float *)(dword_2305834[0] + 70552);
  *(float *)(dword_2305834[0] + 70736) = -*(float *)(dword_2305834[0] + 70736);
  *(float *)(dword_2305834[0] + 70740) = -*(float *)(dword_2305834[0] + 70740);
  *(float *)(dword_2305834[0] + 70744) = 512.0 - *(float *)(dword_2305834[0] + 70744);
  sub_6ED700(dword_2305834[0] + 70624, dword_2305834[0] + 70560, dword_2305834[0] + 70496);
  sub_642F50(
    flt_C44BE0[(*(int *)(dword_2305834[0] + 70464) >> 4) & 0xFFF],
    flt_C44BE0[((*(_DWORD *)(dword_2305834[0] + 70464) + 0x4000) >> 4) & 0xFFF],
    *(float *)(dword_2305834[0] + 70424),
    *(float *)(dword_2305834[0] + 70428),
    *(float *)(dword_2305834[0] + 70480));
  result = dword_2305834[0];
  if ( *(_BYTE *)(dword_2305834[0] + 71111) )
  {
    sub_A5A4B0();
    *(_BYTE *)(dword_2305834[0] + 71111) = 0;
    result = dword_2305834[0];
  }
  *(_BYTE *)(result + 71098) = 0;
  return result;
}

