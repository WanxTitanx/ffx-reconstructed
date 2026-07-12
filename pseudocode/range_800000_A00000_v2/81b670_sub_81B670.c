// Function: sub_81B670
// Address: 0x81b670
__int16 *__cdecl sub_81B670(int a1, __int16 *a2)
{
  int v2; // ebx
  unsigned int n12288; // eax
  int v5; // eax
  double v6; // st7
  __int16 *result; // eax
  __int16 v8; // si
  int v9; // edx
  int v10; // eax
  float *v11; // esi
  __int16 *v12; // ecx
  _DWORD *v13; // edx
  int v14; // edi
  float *v15; // eax
  double v16; // st7
  __int16 v17; // ax
  int v18; // eax
  double v19; // st7
  bool v20; // zf
  float v21; // [esp+Ch] [ebp-24h]
  int v22; // [esp+1Ch] [ebp-14h]
  float v23; // [esp+1Ch] [ebp-14h]
  float v24; // [esp+1Ch] [ebp-14h]
  __int16 *v25; // [esp+20h] [ebp-10h]
  __int16 v26; // [esp+24h] [ebp-Ch]
  int v27; // [esp+28h] [ebp-8h]
  __int16 *v28; // [esp+2Ch] [ebp-4h]
  float v29; // [esp+2Ch] [ebp-4h]
  float v30; // [esp+2Ch] [ebp-4h]
  float v31; // [esp+3Ch] [ebp+Ch]

  v2 = *(_DWORD *)(a1 + 544);
  n12288 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( n12288 > 0x2000 )
  {
    v20 = n12288 == 12288;
    result = a2;
    if ( v20 )
    {
      *(_BYTE *)(v2 + 186) = 10;
      *(_WORD *)(v2 + 160) = a2[1];
      *(_WORD *)(v2 + 162) = a2[2];
      return a2 + 3;
    }
  }
  else if ( n12288 == 0x2000 )
  {
    if ( a2[1] )
      v18 = sub_800F80((_DWORD *)(a1 + 768), v2, a2[1]);
    else
      v18 = *(_DWORD *)(a1 + 544);
    v29 = *(float *)(v2 + 76);
    v25 = *(__int16 **)(v18 + 188);
    v23 = v29 * 0.00390625;
    sub_7EA030(a1, v23, *((_DWORD *)v25 + 2), *((_DWORD *)v25 + 3), *v25);
    if ( 0.0 == *(float *)(v2 + 108) )
      v19 = v29 + 0.0000009999999974752427;
    else
      v19 = *(float *)(v2 + 108) + v29;
    v30 = v19;
    v24 = v30 * 0.00390625;
    sub_7EA030(a1 + 16, v24, *((_DWORD *)v25 + 2), *((_DWORD *)v25 + 3), *v25);
    if ( a2[2] )
    {
      sub_7EA760(v2 + 64, a1, 16.0);
      sub_7EA760(a1 + 16, a1 + 16, 16.0);
    }
    else
    {
      sub_7EA760(v2 + 64, a1, 1.0);
    }
    sub_7EA760(v2 + 144, v2 + 64, 0.0625);
    sub_7EA760(a1 + 16, a1 + 16, 0.0625);
    sub_7E7240(a1 + 64, v2 + 144, a1 + 16);
    sub_7E82C0(v2 + 192, a1 + 640, a1 + 64);
    return a2 + 3;
  }
  else if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( n12288 == 4096 )
    {
      if ( a2[1] )
        v5 = sub_800F80((_DWORD *)(a1 + 768), v2, a2[1]);
      else
        v5 = *(_DWORD *)(a1 + 544);
      v31 = *(float *)(v2 + 76) * 0.00390625;
      sub_7EA030(
        a1,
        v31,
        *(_DWORD *)(*(_DWORD *)(v5 + 188) + 8),
        *(_DWORD *)(*(_DWORD *)(v5 + 188) + 12),
        **(__int16 **)(v5 + 188));
      if ( a2[2] )
        v6 = 16.0;
      else
        v6 = 1.0;
      v21 = v6;
      sub_7EA760(v2 + 64, a1, LODWORD(v21));
      sub_7EA760(v2 + 144, v2 + 64, 0.0625);
      return a2 + 3;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    v8 = a2[1];
    sub_7FF0F0(*(_DWORD *)(a1 + 936), *(_DWORD *)(v2 + 188));
    v9 = sub_7FF6A0(*(_DWORD *)(a1 + 936), 32 * v8 + 16);
    v10 = v8;
    *(_DWORD *)(v2 + 188) = v9;
    *(_WORD *)v9 = v8;
    v11 = (float *)(v9 + 16);
    *(_DWORD *)(v9 + 12) = v9 + 16 + 16 * v10;
    *(_DWORD *)(v9 + 8) = v9 + 16;
    v22 = v9;
    v12 = (__int16 *)((char *)a2 + a2[2]);
    v28 = v12;
    v26 = a2[3];
    v27 = 0;
    if ( v10 > 0 )
    {
      v13 = (_DWORD *)(a1 + 768);
      v14 = v10;
      do
      {
        v15 = (float *)sub_800F80(v13, v2, *v12);
        if ( v26 )
        {
          *v11 = v15[36];
          v11[1] = v15[37];
          v16 = v15[38];
        }
        else
        {
          *v11 = v15[16];
          v11[1] = v15[17];
          v16 = v15[18];
        }
        v17 = v27;
        v11[2] = v16;
        v13 = (_DWORD *)(a1 + 768);
        ++v27;
        v12 = v28 + 1;
        v11 += 4;
        ++v28;
      }
      while ( (__int16)(v17 + 1) < v14 );
      v10 = v14;
    }
    sub_7EA1E0(*(_DWORD *)(v22 + 12), *(_DWORD *)(v22 + 8), v10);
    *(_BYTE *)(v22 + 7) = v26 == 0;
    return a2 + 4;
  }
  return result;
}
