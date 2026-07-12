// Function: sub_A04B20
// Address: 0xa04b20
// Size: 0x32b
// Prototype: 

int __cdecl sub_A04B20(int a1, unsigned int a2)
{
  int *v2; // ebx
  int v3; // eax
  int v4; // esi
  int v5; // edx
  int v6; // ebx
  int v7; // edi
  unsigned int n2; // esi
  int v9; // edi
  int v10; // esi
  int v11; // ebx
  int v12; // eax
  int v13; // ebx
  int v14; // ecx
  float *v15; // ebx
  double v16; // st6
  _WORD *v17; // edi
  unsigned int v18; // esi
  float v19; // ecx
  unsigned int v20; // edx
  int v21; // ebx
  int v22; // esi
  int v23; // eax
  int v25; // [esp+0h] [ebp-48h]
  int v26; // [esp+4h] [ebp-44h]
  _DWORD v27[2]; // [esp+10h] [ebp-38h] BYREF
  _DWORD v28[2]; // [esp+18h] [ebp-30h] BYREF
  int *v29; // [esp+20h] [ebp-28h]
  int v30; // [esp+24h] [ebp-24h]
  int v31; // [esp+28h] [ebp-20h]
  float v32; // [esp+2Ch] [ebp-1Ch]
  float v33; // [esp+30h] [ebp-18h]
  float v34; // [esp+34h] [ebp-14h]
  float v35; // [esp+38h] [ebp-10h]
  int v36; // [esp+44h] [ebp-4h]

  v2 = (int *)sub_4410E0(1, (int)&unk_C99C80, 0);
  v29 = v2;
  if ( *v2 != 1 )
  {
    v3 = sub_42FC60(108, 4);
    v4 = v3;
    if ( v3 )
    {
      sub_434530(v3, 1);
      v5 = v2[1];
      if ( v5 != v4 && *v2 >= 0 )
        sub_434310(v5, *v2 & 0x7FFFFFFF);
      v2[1] = v4;
      *v2 = 1;
    }
  }
  v6 = v2[1];
  *(_DWORD *)(v6 + 16) = 2;
  if ( *(_DWORD *)(v6 + 40) != 2 )
  {
    v7 = sub_42FC60(128, 4);
    v30 = v7;
    if ( v7 )
    {
      *(float *)&n2 = 0.0;
      v34 = 0.0;
      do
      {
        v31 = v7 + (n2 << 6);
        v36 = 0;
        if ( v31 )
          sub_55DDC0(v25, v26);
        ++n2;
        v36 = -1;
        v34 = *(float *)&n2;
      }
      while ( n2 < 2 );
      sub_434F40(v7, 2);
    }
  }
  v9 = v6 + 48;
  LODWORD(v35) = a2 + 2;
  v31 = v6 + 48;
  *(_DWORD *)(v6 + 56) = 6 * a2;
  *(_BYTE *)(v6 + 60) = 12;
  *(_DWORD *)(v6 + 48) = 0;
  *(_DWORD *)(v6 + 52) = a2 + 2;
  LODWORD(v34) = 6 * a2 * sub_55BDB0(12);
  if ( *(_DWORD *)(v6 + 100) != LODWORD(v34) )
  {
    if ( (unsigned __int8)sub_562F20(v9) )
      sub_564A20(v25, v26);
    *(float *)(v6 + 100) = v34;
  }
  sub_434DD0(v27);
  v30 = *(_DWORD *)(v6 + 44);
  v10 = v30;
  sub_483690(12, LODWORD(v35), 1);
  v11 = *(_DWORD *)(v10 + 4) * *(_DWORD *)v10;
  if ( *(_DWORD *)(v10 + 56) != v11 )
  {
    if ( (unsigned __int8)sub_562F10(v10) )
      sub_564830(v25, v26);
    *(_DWORD *)(v10 + 56) = v11;
  }
  v12 = *(_DWORD *)(v10 + 12);
  *(_BYTE *)(v12 + 8) = 2;
  *(_DWORD *)(v12 + 4) = &unk_C98620;
  *(_DWORD *)v12 = 0;
  sub_434D50(v28);
  v13 = v28[0];
  v14 = v27[0];
  *(float *)v28[0] = 0.0;
  *(float *)(v13 + 4) = 0.0;
  v15 = (float *)(v13 + 24);
  *(v15 - 4) = 0.0;
  *(v15 - 3) = 0.0;
  *(v15 - 2) = 0.0;
  *(v15 - 1) = -1.0;
  v34 = (float)a2;
  v16 = v34;
  v34 = 0.0;
  v32 = 6.283185482025146 / v16;
  v35 = 0.0;
  if ( a2 )
  {
    v17 = (_WORD *)(v14 + 2);
    v18 = a2;
    do
    {
      v33 = cos(v35);
      *v15 = v33;
      v33 = sin(v35);
      v19 = v34;
      v15[1] = v33;
      v20 = (LODWORD(v19) + 1) % v18;
      v15[2] = -1.0;
      v35 = v35 + v32;
      *(v17 - 1) = 0;
      *v17 = LOWORD(v19) + 2;
      v17[4] = 1;
      v18 = a2;
      v17[3] = LOWORD(v19) + 2;
      v15 += 3;
      LODWORD(v34) = LODWORD(v19) + 1;
      v17 += 6;
      LOWORD(v20) = v20 + 2;
      *(v17 - 5) = v20;
      *(v17 - 4) = v20;
    }
    while ( LODWORD(v19) + 1 < a2 );
    v9 = v31;
    v10 = v30;
  }
  v21 = (*(_DWORD *)(v10 + 24) & 0x7FFFFFFF) != *(_DWORD *)(v10 + 16) + 1 ? *(_DWORD *)(v10 + 16) + 1 : 0;
  if ( !sub_564E10(v21, v28) )
  {
    *(_DWORD *)(v10 + 16) = v21;
    *(_BYTE *)(v10 + 20) = 0;
  }
  v22 = (*(_DWORD *)(v9 + 20) & 0x7FFFFFFF) != *(_DWORD *)(v9 + 16) + 1 ? *(_DWORD *)(v9 + 16) + 1 : 0;
  if ( !sub_565160(v22, v27) )
  {
    *(_DWORD *)(v9 + 16) = v22;
    *(_BYTE *)(v9 + 14) = 0;
  }
  v23 = sub_440C40(1, (int)&unk_CA7228, 0);
  if ( !v23 || !*(_DWORD *)(v23 + 52) )
    return 0;
  v30 = *(_DWORD *)(v23 + 52);
  v36 = 1;
  return sub_4F2940(v29);
}

