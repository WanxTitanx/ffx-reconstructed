// Function: sub_A06120
// Address: 0xa06120
// Size: 0x34e
// Prototype: 

int sub_A06120()
{
  int *v0; // ebx
  int v1; // eax
  int v2; // esi
  int v3; // edx
  _DWORD *v4; // ebx
  int v5; // edi
  unsigned int n3; // esi
  int v7; // ebx
  int v8; // esi
  int v9; // eax
  int v10; // edi
  int v11; // esi
  int v12; // eax
  int v13; // edi
  int v14; // eax
  float *v15; // eax
  float *v16; // ecx
  float *v17; // edx
  int v18; // ebx
  int v19; // esi
  int v20; // eax
  int v21; // ecx
  int v23; // [esp+0h] [ebp-48h]
  int v24; // [esp+4h] [ebp-44h]
  _DWORD v25[2]; // [esp+10h] [ebp-38h] BYREF
  _DWORD v26[2]; // [esp+18h] [ebp-30h] BYREF
  _DWORD v27[2]; // [esp+20h] [ebp-28h] BYREF
  int v28; // [esp+28h] [ebp-20h]
  int v29; // [esp+2Ch] [ebp-1Ch]
  int *v30; // [esp+30h] [ebp-18h]
  int v31; // [esp+34h] [ebp-14h]
  unsigned int n3_1; // [esp+38h] [ebp-10h]
  int v33; // [esp+44h] [ebp-4h]

  v0 = (int *)sub_4410E0(1, (int)&unk_C99C80, 0);
  v30 = v0;
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
  v31 = (int)v4;
  v4[4] = 2;
  if ( v4[10] != 3 )
  {
    v5 = sub_42FC60(192, 4);
    v29 = v5;
    if ( v5 )
    {
      n3 = 0;
      n3_1 = 0;
      do
      {
        v28 = v5 + (n3 << 6);
        v33 = 0;
        if ( v28 )
          sub_55DDC0(v23, v24);
        ++n3;
        v33 = -1;
        n3_1 = n3;
      }
      while ( n3 < 3 );
      sub_434F40(v5, 3);
    }
  }
  v7 = v4[11];
  sub_483690(12, 3, 1);
  v8 = *(_DWORD *)(v7 + 4) * *(_DWORD *)v7;
  if ( *(_DWORD *)(v7 + 56) != v8 )
  {
    if ( (unsigned __int8)sub_562F10(v7) )
      sub_564830(v23, v24);
    *(_DWORD *)(v7 + 56) = v8;
  }
  v9 = *(_DWORD *)(v7 + 12);
  v10 = v31;
  *(_BYTE *)(v9 + 8) = 2;
  *(_DWORD *)(v9 + 4) = &unk_C98620;
  *(_DWORD *)v9 = 0;
  v11 = *(_DWORD *)(v10 + 44) + 64;
  sub_483690(8, 3, 1);
  v31 = *(_DWORD *)(v11 + 4) * *(_DWORD *)v11;
  if ( *(_DWORD *)(v11 + 56) != v31 )
  {
    if ( (unsigned __int8)sub_562F10(v11) )
      sub_564830(v23, v24);
    *(_DWORD *)(v11 + 56) = v31;
  }
  v12 = *(_DWORD *)(v11 + 12);
  *(_BYTE *)(v12 + 8) = 1;
  *(_DWORD *)(v12 + 4) = &unk_C98638;
  *(_DWORD *)v12 = 0;
  v13 = *(_DWORD *)(v10 + 44) + 128;
  sub_483690(16, 4, 1);
  v31 = *(_DWORD *)(v13 + 4) * *(_DWORD *)v13;
  if ( *(_DWORD *)(v13 + 56) != v31 )
  {
    if ( (unsigned __int8)sub_562F10(v13) )
      sub_564830(v23, v24);
    *(_DWORD *)(v13 + 56) = v31;
  }
  v14 = *(_DWORD *)(v13 + 12);
  *(_BYTE *)(v14 + 8) = 3;
  *(_DWORD *)(v14 + 4) = &unk_C98650;
  *(_DWORD *)v14 = 0;
  sub_434D50(v27);
  sub_434D50(v26);
  sub_434D50(v25);
  v15 = (float *)v27[0];
  v16 = (float *)v26[0];
  v17 = (float *)v25[0];
  *(float *)v27[0] = -1.0;
  v15[1] = -1.0;
  v15[2] = 1.0;
  v15[3] = 3.0;
  v15[4] = -1.0;
  v15[5] = 1.0;
  v15[6] = -1.0;
  v15[7] = 3.0;
  v15[8] = 1.0;
  *v16 = 0.0;
  v16[1] = 0.0;
  v16[2] = 2.0;
  v16[3] = 0.0;
  v16[4] = 0.0;
  v16[5] = 2.0;
  *v17 = 1.0;
  v17[1] = 1.0;
  v17[2] = 1.0;
  v17[3] = 1.0;
  v17[4] = 1.0;
  v17[5] = 1.0;
  v17[6] = 1.0;
  v17[7] = 1.0;
  v17[8] = 1.0;
  v17[9] = 1.0;
  v17[10] = 1.0;
  v17[11] = 1.0;
  v31 = (*(_DWORD *)(v7 + 24) & 0x7FFFFFFF) != *(_DWORD *)(v7 + 16) + 1 ? *(_DWORD *)(v7 + 16) + 1 : 0;
  if ( !sub_564E10(v31, v27) )
  {
    *(_DWORD *)(v7 + 16) = v31;
    *(_BYTE *)(v7 + 20) = 0;
  }
  v18 = (*(_DWORD *)(v11 + 24) & 0x7FFFFFFF) != *(_DWORD *)(v11 + 16) + 1 ? *(_DWORD *)(v11 + 16) + 1 : 0;
  if ( !sub_564E10(v18, v26) )
  {
    *(_DWORD *)(v11 + 16) = v18;
    *(_BYTE *)(v11 + 20) = 0;
  }
  v19 = (*(_DWORD *)(v13 + 24) & 0x7FFFFFFF) != *(_DWORD *)(v13 + 16) + 1 ? *(_DWORD *)(v13 + 16) + 1 : 0;
  if ( !sub_564E10(v19, v25) )
  {
    *(_DWORD *)(v13 + 16) = v19;
    *(_BYTE *)(v13 + 20) = 0;
  }
  v20 = sub_440C40(1, (int)&unk_CA7228, 0);
  if ( !v20 )
    return 0;
  v21 = *(_DWORD *)(v20 + 52);
  v28 = v21;
  if ( !v21 )
    return 0;
  v29 = v21;
  v33 = 1;
  return sub_4F2940(v30);
}

