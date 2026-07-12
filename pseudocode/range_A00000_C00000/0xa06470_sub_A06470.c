// Function: sub_A06470
// Address: 0xa06470
// Size: 0x2d4
// Prototype: 

int sub_A06470()
{
  int *v0; // ebx
  int v1; // eax
  int v2; // esi
  int v3; // edx
  _DWORD *v4; // esi
  bool v5; // zf
  int v6; // edi
  unsigned int n2; // esi
  int v8; // edi
  int v9; // esi
  int v10; // eax
  _DWORD *v11; // esi
  int v12; // esi
  int v13; // eax
  float *v14; // eax
  float *v15; // ecx
  int v16; // edi
  int v17; // eax
  int v18; // ecx
  int v20; // [esp+0h] [ebp-40h]
  int v21; // [esp+4h] [ebp-3Ch]
  _DWORD v22[2]; // [esp+10h] [ebp-30h] BYREF
  _DWORD v23[2]; // [esp+18h] [ebp-28h] BYREF
  int v24; // [esp+20h] [ebp-20h]
  int v25; // [esp+24h] [ebp-1Ch]
  int v26; // [esp+28h] [ebp-18h]
  unsigned int n2_1; // [esp+2Ch] [ebp-14h]
  _DWORD *v28; // [esp+30h] [ebp-10h]
  int v29; // [esp+3Ch] [ebp-4h]

  v0 = (int *)sub_4410E0(1, (int)&unk_C99C80, 0);
  if ( *v0 != 1 )
  {
    v1 = sub_42FC60(108, 4);
    v2 = v1;
    if ( v1 )
    {
      sub_434530(v1, 1);
      v3 = v0[1];
      if ( v3 != v2 && *v0 >= 0 )
        sub_434310(v3, *v0 & 0x7FFFFFFF);
      v0[1] = v2;
      *v0 = 1;
    }
  }
  v4 = (_DWORD *)v0[1];
  v28 = v4;
  v4[4] = 2;
  v5 = v4[10] == 2;
  v26 = (int)(v4 + 10);
  if ( !v5 )
  {
    v6 = sub_42FC60(128, 4);
    v25 = v6;
    if ( v6 )
    {
      n2 = 0;
      n2_1 = 0;
      do
      {
        v24 = v6 + (n2 << 6);
        v29 = 0;
        if ( v24 )
          sub_55DDC0(v20, v21);
        ++n2;
        v29 = -1;
        n2_1 = n2;
      }
      while ( n2 < 2 );
      sub_434F40(v6, 2);
      v4 = v28;
    }
  }
  v8 = v4[11];
  sub_483690(12, 6, 1);
  v9 = *(_DWORD *)(v8 + 4) * *(_DWORD *)v8;
  if ( *(_DWORD *)(v8 + 56) != v9 )
  {
    if ( (unsigned __int8)sub_562F10(v8) )
      sub_564830(v20, v21);
    *(_DWORD *)(v8 + 56) = v9;
  }
  v10 = *(_DWORD *)(v8 + 12);
  v11 = v28;
  *(_BYTE *)(v10 + 8) = 2;
  *(_DWORD *)(v10 + 4) = &unk_C98620;
  *(_DWORD *)v10 = 0;
  v12 = v11[11] + 64;
  sub_483690(8, 6, 1);
  v26 = *(_DWORD *)(v12 + 4) * *(_DWORD *)v12;
  if ( *(_DWORD *)(v12 + 56) != v26 )
  {
    if ( (unsigned __int8)sub_562F10(v12) )
      sub_564830(v20, v21);
    *(_DWORD *)(v12 + 56) = v26;
  }
  v13 = *(_DWORD *)(v12 + 12);
  *(_BYTE *)(v13 + 8) = 1;
  *(_DWORD *)(v13 + 4) = &unk_C98638;
  *(_DWORD *)v13 = 0;
  sub_434D50(v23);
  sub_434D50(v22);
  v14 = (float *)v23[0];
  v15 = (float *)v22[0];
  *(float *)v23[0] = -1.0;
  v14[1] = -1.0;
  v14[2] = 1.0;
  v14[3] = 1.0;
  v14[4] = -1.0;
  v14[5] = 1.0;
  v14[6] = -1.0;
  v14[7] = 1.0;
  v14[8] = 1.0;
  v14[9] = 1.0;
  v14[10] = 1.0;
  v14[11] = 1.0;
  v14[12] = -1.0;
  v14[13] = 1.0;
  v14[14] = 1.0;
  v14[15] = 1.0;
  v14[16] = -1.0;
  v14[17] = 1.0;
  *v15 = 0.0;
  v15[1] = 0.0;
  v15[2] = 1.0;
  v15[3] = 0.0;
  v15[4] = 0.0;
  v15[5] = 1.0;
  v15[6] = 1.0;
  v15[7] = 1.0;
  v15[8] = 0.0;
  v15[9] = 1.0;
  v15[10] = 1.0;
  v15[11] = 0.0;
  v26 = (*(_DWORD *)(v8 + 24) & 0x7FFFFFFF) != *(_DWORD *)(v8 + 16) + 1 ? *(_DWORD *)(v8 + 16) + 1 : 0;
  if ( !sub_564E10(v26, v23) )
  {
    *(_DWORD *)(v8 + 16) = v26;
    *(_BYTE *)(v8 + 20) = 0;
  }
  v16 = (*(_DWORD *)(v12 + 24) & 0x7FFFFFFF) != *(_DWORD *)(v12 + 16) + 1 ? *(_DWORD *)(v12 + 16) + 1 : 0;
  if ( !sub_564E10(v16, v22) )
  {
    *(_DWORD *)(v12 + 16) = v16;
    *(_BYTE *)(v12 + 20) = 0;
  }
  v17 = sub_440C40(1, (int)&unk_CA7228, 0);
  if ( !v17 )
    return 0;
  v18 = *(_DWORD *)(v17 + 52);
  v24 = v18;
  if ( !v18 )
    return 0;
  v25 = v18;
  v29 = 1;
  return sub_4F2940(v0);
}

