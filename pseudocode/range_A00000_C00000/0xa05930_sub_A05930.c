// Function: sub_A05930
// Address: 0xa05930
// Size: 0x539
// Prototype: int __cdecl(int, float, int, float, float)

int __cdecl sub_A05930(int a1, float a2, int n2, float a4, float a5)
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
  double v22; // st5
  double v23; // st4
  double v24; // st6
  float *v25; // eax
  double v26; // st6
  double v27; // st5
  double v28; // st6
  double v29; // st5
  int v30; // ebx
  int v31; // esi
  int v32; // eax
  int v34; // [esp+0h] [ebp-4Ch]
  int v35; // [esp+4h] [ebp-48h]
  _DWORD v36[2]; // [esp+10h] [ebp-3Ch] BYREF
  _DWORD v37[2]; // [esp+18h] [ebp-34h] BYREF
  _DWORD v38[2]; // [esp+20h] [ebp-2Ch] BYREF
  int *v39; // [esp+28h] [ebp-24h]
  float *v40; // [esp+2Ch] [ebp-20h]
  float v41; // [esp+30h] [ebp-1Ch]
  float v42; // [esp+34h] [ebp-18h]
  float v43; // [esp+38h] [ebp-14h]
  float v44; // [esp+3Ch] [ebp-10h]
  int v45; // [esp+48h] [ebp-4h]
  float v46; // [esp+5Ch] [ebp+10h]
  int v47; // [esp+5Ch] [ebp+10h]

  v5 = (int *)sub_4410E0(1, (int)&unk_C99C80, 0);
  v39 = v5;
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
  v42 = *(float *)&v9;
  v9[4] = 2;
  if ( v9[10] != 3 )
  {
    v10 = (float *)sub_42FC60(192, 4);
    v40 = v10;
    if ( v10 )
    {
      *(float *)&n3 = 0.0;
      v41 = 0.0;
      do
      {
        LODWORD(v43) = &v10[16 * n3];
        v45 = 0;
        if ( v43 != 0.0 )
          sub_55DDC0(v34, v35);
        ++n3;
        v45 = -1;
        v41 = *(float *)&n3;
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
      sub_564830(v34, v35);
    *(_DWORD *)(v12 + 56) = v13;
  }
  v14 = *(_DWORD *)(v12 + 12);
  v15 = v42;
  *(_BYTE *)(v14 + 8) = 2;
  *(_DWORD *)(v14 + 4) = &unk_C985B4;
  *(_DWORD *)v14 = 0;
  v16 = *(_DWORD *)(LODWORD(v15) + 44) + 64;
  sub_483690(8, 12, 1);
  LODWORD(v41) = *(_DWORD *)(v16 + 4) * *(_DWORD *)v16;
  if ( *(_DWORD *)(v16 + 56) != LODWORD(v41) )
  {
    if ( (unsigned __int8)sub_562F10(v16) )
      sub_564830(v34, v35);
    *(float *)(v16 + 56) = v41;
  }
  v17 = *(_DWORD *)(v16 + 12);
  *(_BYTE *)(v17 + 8) = 1;
  *(_DWORD *)(v17 + 4) = &unk_C98638;
  *(_DWORD *)v17 = 0;
  v18 = *(_DWORD *)(LODWORD(v15) + 44) + 128;
  sub_483690(12, 12, 1);
  LODWORD(v41) = *(_DWORD *)(v18 + 4) * *(_DWORD *)v18;
  if ( *(_DWORD *)(v18 + 56) != LODWORD(v41) )
  {
    if ( (unsigned __int8)sub_562F10(v18) )
      sub_564830(v34, v35);
    *(float *)(v18 + 56) = v41;
  }
  v19 = *(_DWORD *)(v18 + 12);
  *(_BYTE *)(v19 + 8) = 2;
  *(_DWORD *)(v19 + 4) = &unk_C9862C;
  *(_DWORD *)v19 = 0;
  sub_434D50(v38);
  sub_434D50(v37);
  sub_434D50(v36);
  v41 = 1.0;
  v20 = (float *)v38[0];
  v42 = 0.0;
  v40 = (float *)v37[0];
  v21 = (float *)v36[0];
  v43 = 1.0;
  v44 = 1.0;
  v22 = a2;
  if ( n2 == 1 )
  {
    v23 = 1.0;
    v24 = 1.0;
    v41 = 1.0;
    v42 = 1.0;
    v43 = 1.0;
    v44 = v24 - (a5 - v22) / (v24 - v22);
  }
  else
  {
    if ( n2 == 3 )
    {
      v41 = 1.0 - (a4 - v22) / (1.0 - v22);
      v42 = 0.0;
      v43 = 0.0;
      v44 = 0.0;
    }
    else if ( n2 == 2 )
    {
      v43 = 1.0 - (a4 - v22) / (1.0 - v22);
      v44 = 1.0 - (a5 - v22) / (1.0 - v22);
    }
    v23 = 1.0;
    v24 = 1.0;
  }
  *(float *)v38[0] = -1.0;
  v20[1] = -1.0;
  v20[2] = v23;
  v20[3] = v23;
  v20[4] = -1.0;
  v20[5] = v23;
  v20[6] = -1.0;
  v46 = v22 + v22 - v24;
  v20[7] = v46;
  v20[8] = v23;
  v20[9] = v23;
  v20[10] = v46;
  v20[11] = v23;
  v20[12] = -1.0;
  v20[13] = v46;
  v20[14] = v23;
  v20[15] = v23;
  v20[16] = -1.0;
  v20[17] = v23;
  v20[18] = -1.0;
  v20[19] = v46;
  v20[20] = v23;
  v20[21] = v23;
  v20[22] = v46;
  v20[23] = v23;
  v20[24] = -1.0;
  v20[25] = v23;
  v20[26] = v23;
  v20[27] = v23;
  v20[28] = v23;
  v20[29] = v23;
  v20[30] = -1.0;
  v20[31] = v23;
  v20[32] = v23;
  v20[33] = v23;
  v20[34] = v46;
  v20[35] = v23;
  v25 = v40;
  *v40 = 0.0;
  v25[1] = 0.0;
  v25[2] = v23;
  v25[3] = 0.0;
  v25[4] = 0.0;
  v25[5] = a2;
  v25[6] = v23;
  v25[7] = a2;
  v25[8] = 0.0;
  v25[9] = a2;
  v25[10] = v23;
  v25[11] = 0.0;
  v25[12] = 0.0;
  v25[13] = a2;
  v25[14] = v23;
  v25[15] = a2;
  v25[16] = 0.0;
  v25[17] = v23;
  v25[18] = v23;
  v25[19] = v23;
  v25[20] = 0.0;
  v25[21] = v23;
  v25[22] = v23;
  v25[23] = a2;
  *v21 = v23;
  v26 = v42;
  v21[1] = v42;
  v21[2] = v23;
  v21[3] = v23;
  v21[4] = v26;
  v21[5] = v23;
  v21[6] = v23;
  v27 = v41;
  v21[7] = v41;
  v21[8] = v23;
  v21[9] = v23;
  v21[10] = v27;
  v21[11] = v23;
  v21[12] = v23;
  v21[13] = v27;
  v21[14] = v23;
  v21[15] = v23;
  v21[16] = v26;
  v21[17] = v23;
  v21[18] = v23;
  v28 = v44;
  v21[19] = v44;
  v21[20] = v23;
  v21[21] = v23;
  v21[22] = v28;
  v21[23] = v23;
  v21[24] = v23;
  v29 = v43;
  v21[25] = v43;
  v21[26] = v23;
  v21[27] = v23;
  v21[28] = v29;
  v21[29] = v23;
  v21[30] = v23;
  v21[31] = v29;
  v21[32] = v23;
  v21[33] = v23;
  v21[34] = v28;
  v21[35] = v23;
  v47 = (*(_DWORD *)(v12 + 24) & 0x7FFFFFFF) != *(_DWORD *)(v12 + 16) + 1 ? *(_DWORD *)(v12 + 16) + 1 : 0;
  if ( !sub_564E10(v47, v38) )
  {
    *(_DWORD *)(v12 + 16) = v47;
    *(_BYTE *)(v12 + 20) = 0;
  }
  v30 = (*(_DWORD *)(v16 + 24) & 0x7FFFFFFF) != *(_DWORD *)(v16 + 16) + 1 ? *(_DWORD *)(v16 + 16) + 1 : 0;
  if ( !sub_564E10(v30, v37) )
  {
    *(_DWORD *)(v16 + 16) = v30;
    *(_BYTE *)(v16 + 20) = 0;
  }
  v31 = (*(_DWORD *)(v18 + 24) & 0x7FFFFFFF) != *(_DWORD *)(v18 + 16) + 1 ? *(_DWORD *)(v18 + 16) + 1 : 0;
  if ( !sub_564E10(v31, v36) )
  {
    *(_DWORD *)(v18 + 16) = v31;
    *(_BYTE *)(v18 + 20) = 0;
  }
  v32 = sub_440C40(1, (int)&unk_CA7228, 0);
  if ( !v32 || !*(_DWORD *)(v32 + 52) )
    return 0;
  v45 = 1;
  return sub_4F2940(v39);
}

