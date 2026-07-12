// Function: sub_A04E50
// Address: 0xa04e50
// Size: 0x56b
// Prototype: int __cdecl(int, float, int, float, float)

int __cdecl sub_A04E50(int a1, float a2, int n2, float a4, float a5)
{
  int *v5; // ebx
  int v6; // eax
  int v7; // esi
  int v8; // edx
  _DWORD *v9; // ebx
  float *v10; // edi
  unsigned int n3; // esi
  int v12; // ebx
  int v13; // esi
  int v14; // eax
  float v15; // edi
  int v16; // esi
  int v17; // eax
  int v18; // edi
  int v19; // eax
  float *v20; // eax
  float *v21; // ecx
  double v22; // st7
  double v23; // st5
  double v24; // st3
  double v25; // st3
  double v26; // st7
  float *v27; // eax
  double v28; // st6
  double v29; // st5
  double v30; // st6
  double v31; // st5
  int v32; // ebx
  int v33; // esi
  int v34; // eax
  int v36; // [esp+0h] [ebp-50h]
  int v37; // [esp+4h] [ebp-4Ch]
  _DWORD v38[2]; // [esp+10h] [ebp-40h] BYREF
  _DWORD v39[2]; // [esp+18h] [ebp-38h] BYREF
  _DWORD v40[2]; // [esp+20h] [ebp-30h] BYREF
  int *v41; // [esp+28h] [ebp-28h]
  float *v42; // [esp+2Ch] [ebp-24h]
  float v43; // [esp+30h] [ebp-20h]
  float v44; // [esp+34h] [ebp-1Ch]
  float v45; // [esp+38h] [ebp-18h]
  float v46; // [esp+3Ch] [ebp-14h]
  float v47; // [esp+40h] [ebp-10h]
  int v48; // [esp+4Ch] [ebp-4h]
  float v49; // [esp+60h] [ebp+10h]
  int v50; // [esp+60h] [ebp+10h]

  v5 = (int *)sub_4410E0(1, (int)&unk_C99C80, 0);
  v41 = v5;
  if ( *v5 != 1 )
  {
    v6 = sub_42FC60(108, 4);
    v7 = v6;
    if ( v6 )
    {
      sub_434530(v6, 1);
      v8 = v5[1];
      if ( v8 != v7 && *v5 >= 0 )
        sub_434310(v8, *v5 & 0x7FFFFFFF);
      v5[1] = v7;
      *v5 = 1;
    }
  }
  v9 = *((_DWORD **)v5 + 1);
  v44 = *(float *)&v9;
  v9[4] = 2;
  if ( v9[10] != 3 )
  {
    v10 = (float *)sub_42FC60(192, 4);
    v42 = v10;
    if ( v10 )
    {
      *(float *)&n3 = 0.0;
      v43 = 0.0;
      do
      {
        LODWORD(v45) = &v10[16 * n3];
        v48 = 0;
        if ( v45 != 0.0 )
          sub_55DDC0(v36, v37);
        ++n3;
        v48 = -1;
        v43 = *(float *)&n3;
      }
      while ( n3 < 3 );
      sub_434F40(v10, 3);
    }
  }
  v12 = v9[11];
  sub_483690(12, 12, 1);
  v13 = *(_DWORD *)(v12 + 4) * *(_DWORD *)v12;
  if ( *(_DWORD *)(v12 + 56) != v13 )
  {
    if ( (unsigned __int8)sub_562F10(v12) )
      sub_564830(v36, v37);
    *(_DWORD *)(v12 + 56) = v13;
  }
  v14 = *(_DWORD *)(v12 + 12);
  v15 = v44;
  *(_BYTE *)(v14 + 8) = 2;
  *(_DWORD *)(v14 + 4) = &unk_C985B4;
  *(_DWORD *)v14 = 0;
  v16 = *(_DWORD *)(LODWORD(v15) + 44) + 64;
  sub_483690(8, 12, 1);
  LODWORD(v43) = *(_DWORD *)(v16 + 4) * *(_DWORD *)v16;
  if ( *(_DWORD *)(v16 + 56) != LODWORD(v43) )
  {
    if ( (unsigned __int8)sub_562F10(v16) )
      sub_564830(v36, v37);
    *(float *)(v16 + 56) = v43;
  }
  v17 = *(_DWORD *)(v16 + 12);
  *(_BYTE *)(v17 + 8) = 1;
  *(_DWORD *)(v17 + 4) = &unk_C98638;
  *(_DWORD *)v17 = 0;
  v18 = *(_DWORD *)(LODWORD(v15) + 44) + 128;
  sub_483690(12, 12, 1);
  LODWORD(v43) = *(_DWORD *)(v18 + 4) * *(_DWORD *)v18;
  if ( *(_DWORD *)(v18 + 56) != LODWORD(v43) )
  {
    if ( (unsigned __int8)sub_562F10(v18) )
      sub_564830(v36, v37);
    *(float *)(v18 + 56) = v43;
  }
  v19 = *(_DWORD *)(v18 + 12);
  *(_BYTE *)(v19 + 8) = 2;
  *(_DWORD *)(v19 + 4) = &unk_C9862C;
  *(_DWORD *)v19 = 0;
  sub_434D50(v40);
  sub_434D50(v39);
  sub_434D50(v38);
  v47 = 0.0;
  v20 = (float *)v40[0];
  v44 = 1.0;
  v43 = 1.0;
  v42 = (float *)v39[0];
  v21 = (float *)v38[0];
  v46 = 1.0;
  v45 = 1.0;
  if ( n2 == 1 )
  {
    v22 = 1.0;
    v47 = (a2 - a4) / (a5 - a4);
    v44 = 1.0;
    v43 = 1.0;
    v46 = 1.0;
    v45 = 1.0 - (a5 - a2) / (1.0 - a2);
    v23 = 0.0;
  }
  else if ( n2 == 3 )
  {
    v47 = (1.0 - a4) / (a5 - a4);
    v44 = 1.0 - (a4 - a2) / (1.0 - a2);
    v23 = 0.0;
    v22 = 1.0;
    v43 = 0.0;
    v46 = 0.0;
    v45 = 0.0;
  }
  else
  {
    v23 = 0.0;
    v22 = 1.0;
    if ( n2 == 2 )
    {
      v47 = 0.0;
      v24 = 1.0 - a2;
      v46 = 1.0 - (a4 - a2) / v24;
      v45 = 1.0 - (a5 - a2) / v24;
    }
  }
  *(float *)v40[0] = -1.0;
  v20[1] = -1.0;
  v20[2] = 1.0;
  v25 = v47 + v47 - v22;
  v26 = v47;
  v49 = v25;
  v20[3] = v49;
  v20[4] = -1.0;
  v20[5] = 1.0;
  v20[6] = -1.0;
  v20[7] = 1.0;
  v20[8] = 1.0;
  v20[9] = v49;
  v20[10] = 1.0;
  v20[11] = 1.0;
  v20[12] = -1.0;
  v20[13] = 1.0;
  v20[14] = 1.0;
  v20[15] = v49;
  v20[16] = -1.0;
  v20[17] = 1.0;
  v20[18] = v49;
  v20[19] = -1.0;
  v20[20] = 1.0;
  v20[21] = 1.0;
  v20[22] = -1.0;
  v20[23] = 1.0;
  v20[24] = v49;
  v20[25] = 1.0;
  v20[26] = 1.0;
  v20[27] = 1.0;
  v20[28] = 1.0;
  v20[29] = 1.0;
  v20[30] = v49;
  v20[31] = 1.0;
  v20[32] = 1.0;
  v20[33] = 1.0;
  v20[34] = -1.0;
  v20[35] = 1.0;
  v27 = v42;
  *v42 = v23;
  v27[1] = v23;
  v27[2] = v26;
  v27[3] = v23;
  v27[4] = v23;
  v27[5] = 1.0;
  v27[6] = v26;
  v27[7] = 1.0;
  v27[8] = v23;
  v27[9] = 1.0;
  v27[10] = v26;
  v27[11] = v23;
  v27[12] = v26;
  v27[13] = v23;
  v27[14] = 1.0;
  v27[15] = v23;
  v27[16] = v26;
  v27[17] = 1.0;
  v27[18] = 1.0;
  v27[19] = 1.0;
  v27[20] = v26;
  v27[21] = 1.0;
  v27[22] = 1.0;
  v27[23] = v23;
  v28 = v44;
  *v21 = v44;
  v21[1] = 1.0;
  v21[2] = 1.0;
  v29 = v43;
  v21[3] = v43;
  v21[4] = 1.0;
  v21[5] = 1.0;
  v21[6] = v28;
  v21[7] = 1.0;
  v21[8] = 1.0;
  v21[9] = v29;
  v21[10] = 1.0;
  v21[11] = 1.0;
  v21[12] = v28;
  v21[13] = 1.0;
  v21[14] = 1.0;
  v21[15] = v29;
  v21[16] = 1.0;
  v21[17] = 1.0;
  v30 = v46;
  v21[18] = v46;
  v21[19] = 1.0;
  v21[20] = 1.0;
  v31 = v45;
  v21[21] = v45;
  v21[22] = 1.0;
  v21[23] = 1.0;
  v21[24] = v30;
  v21[25] = 1.0;
  v21[26] = 1.0;
  v21[27] = v31;
  v21[28] = 1.0;
  v21[29] = 1.0;
  v21[30] = v30;
  v21[31] = 1.0;
  v21[32] = 1.0;
  v21[33] = v31;
  v21[34] = 1.0;
  v21[35] = 1.0;
  v50 = (*(_DWORD *)(v12 + 24) & 0x7FFFFFFF) != *(_DWORD *)(v12 + 16) + 1 ? *(_DWORD *)(v12 + 16) + 1 : 0;
  if ( !sub_564E10(v50, v40) )
  {
    *(_DWORD *)(v12 + 16) = v50;
    *(_BYTE *)(v12 + 20) = 0;
  }
  v32 = (*(_DWORD *)(v16 + 24) & 0x7FFFFFFF) != *(_DWORD *)(v16 + 16) + 1 ? *(_DWORD *)(v16 + 16) + 1 : 0;
  if ( !sub_564E10(v32, v39) )
  {
    *(_DWORD *)(v16 + 16) = v32;
    *(_BYTE *)(v16 + 20) = 0;
  }
  v33 = (*(_DWORD *)(v18 + 24) & 0x7FFFFFFF) != *(_DWORD *)(v18 + 16) + 1 ? *(_DWORD *)(v18 + 16) + 1 : 0;
  if ( !sub_564E10(v33, v38) )
  {
    *(_DWORD *)(v18 + 16) = v33;
    *(_BYTE *)(v18 + 20) = 0;
  }
  v34 = sub_440C40(1, (int)&unk_CA7228, 0);
  if ( !v34 || !*(_DWORD *)(v34 + 52) )
    return 0;
  v42 = *(float **)(v34 + 52);
  v48 = 1;
  return sub_4F2940(v41);
}

