// Function: sub_A06AB0
// Address: 0xa06ab0
// Size: 0x3a4
// Prototype: 

int __cdecl sub_A06AB0(int a1, unsigned int a2)
{
  int *v2; // ebx
  int v3; // eax
  int v4; // esi
  int v5; // edx
  _DWORD *v6; // eax
  _DWORD *v7; // edi
  unsigned int n2; // esi
  unsigned int v9; // ebx
  _DWORD *v10; // edi
  int v11; // esi
  _DWORD *v12; // esi
  int v13; // edi
  int v14; // eax
  float v15; // esi
  double v16; // st7
  double v17; // st7
  unsigned int v18; // edi
  float *v19; // eax
  __int16 v20; // dx
  __int16 v21; // si
  __int16 v22; // bx
  __int16 v23; // dx
  int v24; // edi
  __int16 v25; // cx
  __int16 v26; // ax
  int v27; // esi
  __int16 v28; // ax
  __int16 v29; // ax
  _DWORD *v30; // edi
  int v31; // esi
  _DWORD *v32; // edi
  int v33; // esi
  int v34; // eax
  int v36; // [esp+0h] [ebp-6Ch]
  int v37; // [esp+4h] [ebp-68h]
  _DWORD v38[2]; // [esp+10h] [ebp-5Ch] BYREF
  _DWORD v39[2]; // [esp+18h] [ebp-54h] BYREF
  int *v40; // [esp+20h] [ebp-4Ch]
  _DWORD *v41; // [esp+24h] [ebp-48h]
  float v42; // [esp+28h] [ebp-44h]
  float v43; // [esp+2Ch] [ebp-40h]
  float v44; // [esp+30h] [ebp-3Ch]
  float v45; // [esp+34h] [ebp-38h]
  float v46; // [esp+38h] [ebp-34h]
  int v47; // [esp+3Ch] [ebp-30h]
  unsigned int v48; // [esp+40h] [ebp-2Ch]
  _DWORD *v49; // [esp+44h] [ebp-28h]
  int v50; // [esp+48h] [ebp-24h]
  int v51; // [esp+4Ch] [ebp-20h]
  float *v52; // [esp+50h] [ebp-1Ch]
  unsigned int v53; // [esp+54h] [ebp-18h]
  float v54; // [esp+58h] [ebp-14h]
  float v55; // [esp+5Ch] [ebp-10h]
  int v56; // [esp+68h] [ebp-4h]

  v2 = (int *)sub_4410E0(1, (int)&unk_C99C80, 0);
  v40 = v2;
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
  v6 = (_DWORD *)v2[1];
  v49 = v6;
  v6[4] = 2;
  if ( v6[10] != 2 )
  {
    v7 = (_DWORD *)sub_42FC60(128, 4);
    v41 = v7;
    if ( v7 )
    {
      *(float *)&n2 = 0.0;
      v46 = 0.0;
      do
      {
        LODWORD(v42) = &v7[16 * n2];
        v56 = 0;
        if ( v42 != 0.0 )
          sub_55DDC0(v36, v37);
        ++n2;
        v56 = -1;
        v46 = *(float *)&n2;
      }
      while ( n2 < 2 );
      sub_434F40(v7, 2);
    }
  }
  v9 = a2;
  v10 = v49 + 12;
  v11 = 6 * a2 * a2;
  v47 = (a2 + 1) * (a2 + 1);
  v49[14] = v11;
  *((_BYTE *)v10 + 12) = 12;
  *v10 = 0;
  v10[1] = (a2 + 1) * (a2 + 1);
  LODWORD(v46) = v11 * sub_55BDB0(12);
  if ( v10[13] != LODWORD(v46) )
  {
    if ( (unsigned __int8)sub_562F20(v10) )
      sub_564A20(v36, v37);
    *((float *)v10 + 13) = v46;
  }
  sub_434DD0(v38);
  v41 = (_DWORD *)v49[11];
  v12 = v41;
  sub_483690(12, v47, 1);
  v13 = v12[1] * *v12;
  if ( v12[14] != v13 )
  {
    if ( (unsigned __int8)sub_562F10(v12) )
      sub_564830(v36, v37);
    v12[14] = v13;
  }
  v14 = v12[3];
  *(_BYTE *)(v14 + 8) = 2;
  *(_DWORD *)(v14 + 4) = &unk_C98620;
  *(_DWORD *)v14 = 0;
  sub_434D50(v39);
  v52 = (float *)v39[0];
  v51 = v38[0];
  v46 = (float)a2;
  v15 = 0.0;
  v50 = 0;
  v16 = v46;
  v46 = 0.0;
  v42 = 6.283185482025146 / v16;
  v43 = 3.141592741012573 / v16;
  v17 = 0.0;
  v54 = 0.0;
  do
  {
    v55 = v17;
    v18 = 0;
    v47 = 0;
    v45 = cos(v54);
    v44 = sin(v54);
    do
    {
      *(float *)&v48 = sin(v55);
      *v52 = v45 * *(float *)&v48;
      *(float *)&v53 = cos(v55);
      v19 = v52 + 3;
      v52[1] = *(float *)&v53;
      v52 = v19;
      v53 = v48;
      *(v19 - 1) = v44 * *(float *)&v48;
      if ( v18 < v9 && LODWORD(v15) < v9 )
      {
        v20 = LOWORD(v15);
        v21 = LOWORD(v15) * (v9 + 1);
        v48 = v9 + 1;
        v22 = v18;
        v23 = v48 * (v20 + 1);
        v24 = 3 * (v18 + v50);
        *(_WORD *)(v51 + 4 * v24) = v21 + v22;
        v25 = v23 + v22;
        *(_WORD *)(v51 + 4 * v24 + 2) = v23 + v22;
        v26 = v21 + 1;
        v27 = v51;
        v28 = v22 + v26;
        *(_WORD *)(v51 + 4 * v24 + 4) = v28;
        *(_WORD *)(v27 + 4 * v24 + 6) = v28;
        v29 = v22 + 1;
        v9 = a2;
        *(_WORD *)(v27 + 4 * v24 + 8) = v25;
        *(_WORD *)(v27 + 4 * v24 + 10) = v23 + v29;
        v18 = v47;
        v15 = v46;
      }
      v47 = ++v18;
      v55 = v55 + v43;
    }
    while ( v18 <= v9 );
    v50 += v9;
    ++LODWORD(v15);
    v46 = v15;
    v54 = v54 + v42;
    v17 = 0.0;
  }
  while ( LODWORD(v15) <= v9 );
  v30 = v41;
  v31 = (v41[6] & 0x7FFFFFFF) != v41[4] + 1 ? v41[4] + 1 : 0;
  if ( !sub_564E10(v31, v39) )
  {
    v30[4] = v31;
    *((_BYTE *)v30 + 20) = 0;
  }
  v32 = v49;
  v33 = (v49[17] & 0x7FFFFFFF) != v49[16] + 1 ? v49[16] + 1 : 0;
  if ( !sub_565160(v33, v38) )
  {
    v32[16] = v33;
    *((_BYTE *)v32 + 62) = 0;
  }
  v34 = sub_440C40(1, (int)&unk_CA7228, 0);
  if ( !v34 || !*(_DWORD *)(v34 + 52) )
    return 0;
  v41 = *(_DWORD **)(v34 + 52);
  v56 = 1;
  return sub_4F2940(v40);
}

