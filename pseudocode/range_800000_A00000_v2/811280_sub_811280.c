// Function: sub_811280
// Address: 0x811280
char __cdecl sub_811280(float a1, float a2)
{
  int v2; // ebx
  float v3; // edi
  double v4; // st7
  double v5; // st6
  double v6; // st5
  double v7; // st4
  double v8; // st5
  double v9; // st6
  double v10; // rt0
  double v11; // st7
  int v12; // eax
  double v13; // st7
  int v14; // eax
  int v15; // esi
  unsigned __int16 v16; // ax
  bool v17; // zf
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  __int16 *v21; // ecx
  int v22; // esi
  __int64 v24; // [esp-1Ch] [ebp-38h]
  __int64 n2622; // [esp-18h] [ebp-34h]
  __int64 v26; // [esp-10h] [ebp-2Ch]
  __int64 v27; // [esp-8h] [ebp-24h]
  float v28; // [esp+0h] [ebp-1Ch]
  float v29; // [esp+10h] [ebp-Ch]
  float v30; // [esp+18h] [ebp-4h]

  v2 = LODWORD(a1);
  v3 = *(float *)(LODWORD(a1) + 544);
  *(_DWORD *)(LODWORD(a1) + 4) = *(_DWORD *)(LODWORD(v3) + 200);
  LODWORD(a1) = *(__int16 *)(LODWORD(v3) + 242);
  v4 = (double)SLODWORD(a1);
  LODWORD(a1) = *(__int16 *)(LODWORD(v3) + 244);
  v30 = v4;
  v29 = (float)SLODWORD(a1);
  v5 = 255.0;
  v6 = 0.0;
  if ( *(_BYTE *)(LODWORD(v3) + 168) == 1 )
  {
    v30 = *(float *)(LODWORD(v3) + 60);
  }
  else if ( *(_BYTE *)(LODWORD(v3) + 168) == 2 )
  {
    a1 = *(float *)(LODWORD(v3) + 60);
    v7 = a1;
    if ( a1 <= 255.0 )
    {
      if ( v7 < 0.0 )
      {
        a1 = 0.0;
        v7 = (float)0.0;
      }
      v9 = 0.0;
      v8 = 255.0;
    }
    else
    {
      v8 = 255.0;
      v9 = 0.0;
      a1 = 255.0;
      v7 = (float)255.0;
    }
    *(_BYTE *)(v2 + 7) = (int)v7;
    v10 = v8;
    v6 = v9;
    v5 = v10;
  }
  if ( *(_BYTE *)(LODWORD(v3) + 169) == 1 )
  {
    v30 = *(float *)(LODWORD(v3) + 76);
  }
  else if ( *(_BYTE *)(LODWORD(v3) + 169) == 2 )
  {
    a1 = *(float *)(LODWORD(v3) + 76);
    v11 = a1;
    if ( a1 <= 255.0 )
    {
      if ( v6 > v11 )
      {
        a1 = v6;
        v11 = a1;
      }
    }
    else
    {
      a1 = v5;
      v11 = a1;
    }
    *(_BYTE *)(v2 + 7) = (int)v11;
  }
  *(_WORD *)(v2 + 2) = *(_WORD *)(LODWORD(v3) + 192);
  v12 = *(_DWORD *)(LODWORD(v3) + 208);
  a1 = v30 * 0.000244140625;
  v13 = a1;
  *(_DWORD *)(v2 + 8) = v12;
  v28 = v13;
  sub_7EA610((void *)(v2 + 128), v28);
  if ( *(_BYTE *)(LODWORD(v3) + 170) )
  {
    sub_7E9440(v2 + 128, v2 + 128, LODWORD(v3) + 48);
  }
  else if ( 0.0 != v29 )
  {
    sub_7E9670(v2 + 128, v2 + 128, v29);
  }
  *(_QWORD *)&n1065353216 = *(_QWORD *)(LODWORD(v3) + 144);
  n1065353216_2 = *(_DWORD *)(LODWORD(v3) + 152);
  n1065353216_3 = *(_DWORD *)(LODWORD(v3) + 156);
  *(_QWORD *)(v2 + 64) = *(_QWORD *)&n1065353216;
  *(_DWORD *)(v2 + 72) = n1065353216_2;
  *(_DWORD *)(v2 + 76) = n1065353216_3;
  v14 = sub_801E20((_DWORD *)v2, (unsigned __int16 *)LODWORD(v3));
  sub_7E78B0(v2 + 176, v14, v2 + 64);
  if ( (*(_WORD *)(LODWORD(v3) + 192) & 0x100) != 0 )
  {
    *(float *)(v2 + 176) = *(float *)(LODWORD(v3) + 48) * 0.0625 + *(float *)(v2 + 176);
    *(float *)(v2 + 180) = *(float *)(LODWORD(v3) + 52) * 0.0625 + *(float *)(v2 + 180);
    *(float *)(v2 + 184) = 0.0625 * *(float *)(LODWORD(v3) + 56) + *(float *)(v2 + 184);
  }
  v15 = LODWORD(a2);
  *(_DWORD *)(v2 + 16) = v2 + 128;
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(v15 + 84);
  if ( *(_WORD *)(LODWORD(v3) + 198) )
  {
    *(_DWORD *)(v2 + 28) = v2 + 256;
    sub_7E7F20(v2 + 256, v2 + 128);
    LODWORD(a1) = *(__int16 *)(LODWORD(v3) + 198);
    a2 = (float)SLODWORD(a1);
    *(float *)(v2 + 312) = a2 * 0.0625 + *(float *)(v2 + 312);
  }
  else
  {
    *(_DWORD *)(v2 + 28) = 0;
  }
  *(_WORD *)(v2 + 12) = *(_WORD *)(LODWORD(v3) + 196);
  v16 = *(_WORD *)(LODWORD(v3) + 240);
  v17 = *(_WORD *)(LODWORD(v3) + 238) == v16;
  *(_WORD *)(LODWORD(v3) + 238) -= v16;
  v18 = *(_DWORD *)(LODWORD(v3) + 224);
  if ( v17 )
  {
    ++*(_WORD *)(LODWORD(v3) + 236);
    v19 = *(__int16 *)(v18 + 4);
    LODWORD(a2) = *(unsigned __int16 *)(LODWORD(v3) + 236);
    if ( LOWORD(a2) >= v19 )
    {
      if ( *(char *)(v18 + 8 * (unsigned __int16)(LOWORD(a2) - 1) + 20) >= 0 && *(__int16 *)(LODWORD(v3) + 192) >= 0 )
      {
        sub_800C30(v15, *(_WORD *)(v2 + 532));
        --*(_WORD *)(v2 + 536);
        *(_WORD *)(LODWORD(v3) + 176) |= 0x8000u;
        LOBYTE(v20) = 0;
        return v20;
      }
      *(_WORD *)(LODWORD(v3) + 236) = 0;
    }
    v21 = (__int16 *)(v18 + 8 * (*(unsigned __int16 *)(LODWORD(v3) + 236) + 2));
    *(_DWORD *)(LODWORD(v3) + 228) = v21;
    *(_DWORD *)(LODWORD(v3) + 232) = v18 + *v21;
    *(_WORD *)(LODWORD(v3) + 238) = v21[1];
  }
  LOBYTE(v20) = byte_12A8480[*(unsigned __int8 *)(LODWORD(v3) + 24)];
  if ( ((unsigned __int8)v20 & *(_BYTE *)(LODWORD(v3) + 179)) == 0 )
  {
    a1 = COERCE_FLOAT(unknown_libname_742(v18));
    *((float *)&v27 + 1) = v3;
    LODWORD(v27) = 0;
    a2 = v3;
    v17 = sub_645580(v27) == 0;
    v20 = *(_DWORD *)(LODWORD(v3) + 232);
    if ( v17 )
    {
      v22 = FFX_MagicHost_ClassifyPppOpcodeByte(*(unsigned __int8 *)(*(_DWORD *)(v20 + 4) + v20 + 4));
      sub_7176F0(8);
      *((float *)&v24 + 1) = a2;
      LODWORD(v24) = 0;
      FFX_MagicHost_BindPppResourceToDrawable(v24, &a1, v2, *(unsigned __int16 *)(LODWORD(v3) + 236), v22);
      LOBYTE(v20) = sub_7176E0();
    }
    else if ( *(__int16 *)(v20 + 2) > 0 )
    {
      *((float *)&v26 + 1) = v3;
      LODWORD(v26) = 0;
      FFX_MagicHost_ApplyPppDrawableColors(v26, (int *)&a1, v2, *(_WORD *)(LODWORD(v3) + 236));
      *((float *)&n2622 + 1) = v3;
      LODWORD(n2622) = 0;
      LOBYTE(v20) = FFX_MagicHost_CommitDrawableResources(n2622);
    }
  }
  return v20;
}
