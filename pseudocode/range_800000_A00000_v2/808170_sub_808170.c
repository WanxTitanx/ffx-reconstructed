// Function: sub_808170
// Address: 0x808170
int __cdecl sub_808170(int a1, int a2)
{
  int v2; // edi
  float v3; // ebx
  int v4; // ecx
  unsigned int n0x2000; // eax
  int v6; // esi
  int v8; // eax
  int i_2; // eax
  int v10; // edi
  int v11; // ebx
  int v12; // eax
  _DWORD *i_1; // edi
  int v14; // esi
  int v15; // eax
  char *v16; // esi
  char v17; // bl
  __int16 v18; // si
  int v19; // edi
  _DWORD *v20; // eax
  int v21; // edx
  _DWORD *v22; // ecx
  int v23; // edi
  int n256; // [esp-4h] [ebp-20h]
  int v25; // [esp+Ch] [ebp-10h]
  float v26; // [esp+10h] [ebp-Ch]
  _WORD *i; // [esp+10h] [ebp-Ch]
  int v28; // [esp+14h] [ebp-8h] BYREF
  float *v29; // [esp+18h] [ebp-4h]

  v2 = *(_DWORD *)(a1 + 544);
  v29 = (float *)v2;
  v3 = flt_12A80C0[*(unsigned __int8 *)(v2 + 24)];
  v26 = v3;
  v4 = *(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(v2 + 30) + 864);
  n0x2000 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( n0x2000 > 0x3000 )
  {
    switch ( n0x2000 )
    {
      case 0x4000u:
        v18 = *(_WORD *)(a2 + 2);
        v19 = sub_7E3720(v4, 9, *(__int16 *)(a2 + 4));
        v20 = (_DWORD *)sub_83CD20(LODWORD(v3), v18, &v28);
        v21 = 0;
        v22 = v20;
        if ( v28 > 0 )
        {
          v23 = v19 - (_DWORD)v20;
          do
          {
            *v22 = *(_DWORD *)((char *)v22 + v23);
            v22[1] = *(_DWORD *)((char *)v22 + v23 + 4);
            v22[2] = *(_DWORD *)((char *)v22 + v23 + 8);
            v22[3] = *(_DWORD *)((char *)v22 + v23 + 12);
            v21 += 16;
            v22 += 4;
          }
          while ( v21 < v28 );
        }
        return a2 + 6;
      case 0x5000u:
        if ( *(_DWORD *)(v2 + 188) )
        {
          v16 = (char *)&unk_12A2280 + 32 * sub_7FE890(LODWORD(v3), 0, 0);
          v17 = v16[23];
          v16[23] = v17 & 0xFE;
          sub_807790(
            LODWORD(v26),
            *(_DWORD *)(v2 + 188),
            (int)*(float *)(v2 + 64),
            (int)*(float *)(v2 + 68),
            (int)*(float *)(v2 + 72),
            (int)*(float *)(v2 + 60));
          v16[23] = v17;
        }
        return a2 + 2;
      case 0x6000u:
        v10 = *(__int16 *)(a2 + 2);
        v11 = sub_7E3720(v4, 3, v10);
        v12 = sub_7FF6A0(*(_DWORD *)(a1 + 936), 0x20000);
        i_1 = (_DWORD *)(v12 + ((v10 & 7) << 14));
        v25 = v12;
        i_1[2048] = *(_DWORD *)v11;
        i = i_1;
        v14 = (int)(i_1 + 1024);
        i_1 += 2048;
        i_1[1] = *(_DWORD *)(v11 + 4);
        i_1[2] = *(_DWORD *)(v11 + 8);
        i_1[3] = *(_DWORD *)(v11 + 12);
        n256 = *(unsigned __int16 *)(v11 + 2) >> 2;
        v15 = unknown_libname_741(*(_DWORD *)(v11 + 4));
        sub_808000(i, v15, n256);
        sub_807CE0(
          v14,
          (int)i,
          *(unsigned __int16 *)(v11 + 2) >> 2,
          (int)v29[16],
          (int)v29[17],
          (int)v29[18],
          (int)v29[15]);
        i_1[1] = v14;
        sub_7E45C0(i_1);
        sub_7FF0F0(*(_DWORD *)(a1 + 936), v25);
        return a2 + 4;
      default:
        return a2;
    }
  }
  else if ( n0x2000 == 12288 )
  {
    if ( *(_DWORD *)(v2 + 188) )
    {
      sub_7FF0F0(*(_DWORD *)(a1 + 936), *(_DWORD *)(v2 + 188));
      *(_DWORD *)(v2 + 188) = 0;
    }
    sub_83C890(LODWORD(v3));
    return a2 + 2;
  }
  else
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
    {
      i_2 = sub_7E3720(v4, 3, *(__int16 *)(a2 + 2));
      sub_7E45C0(i_2);
      return a2 + 4;
    }
    if ( n0x2000 != 4096 )
    {
      if ( n0x2000 == 0x2000 )
      {
        v6 = *(_DWORD *)(v2 + 188);
        if ( v6 )
          sub_807790(
            LODWORD(v3),
            v6,
            (int)*(float *)(v2 + 64),
            (int)*(float *)(v2 + 68),
            (int)*(float *)(v2 + 72),
            (int)*(float *)(v2 + 60));
        return a2 + 2;
      }
      return a2;
    }
    sub_83C790(LODWORD(v3));
    v28 = sub_807C90(LODWORD(v3));
    if ( v28 )
    {
      sub_7FF0F0(*(_DWORD *)(a1 + 936), *(_DWORD *)(v2 + 188));
      v8 = sub_7FF6A0(*(_DWORD *)(a1 + 936), v28);
      *(_DWORD *)(v2 + 188) = v8;
      sub_807AE0(LODWORD(v3), v8);
    }
    else
    {
      *(_DWORD *)(v2 + 188) = 0;
    }
    return a2 + 2;
  }
}
