// Function: sub_80B7D0
// Address: 0x80b7d0
__int16 *__cdecl sub_80B7D0(int a1, __int16 *a2)
{
  int v2; // esi
  int v3; // edx
  int n0x2000; // eax
  int v5; // eax
  int v6; // eax
  double v8; // st7
  __int16 v10; // bx
  int v11; // eax
  int v12; // ebx
  int v13; // [esp+4h] [ebp-4h]
  float v14; // [esp+4h] [ebp-4h]
  float v15; // [esp+10h] [ebp+8h]
  float v16; // [esp+10h] [ebp+8h]
  float v17; // [esp+14h] [ebp+Ch]

  v2 = *(_DWORD *)(a1 + 544);
  v3 = *(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(v2 + 30) + 864);
  v13 = v3;
  n0x2000 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( n0x2000 == 4096 )
    {
      v15 = sub_795100(*(_BYTE *)(v2 + 24));
      v14 = sub_795A30(*(_BYTE *)(v2 + 24));
      v8 = v15;
      if ( v14 > (double)v15 )
        v8 = v14;
      v16 = v8 / 18.0;
      *(float *)(v2 + 220) = v16 * *(float *)(v2 + 220);
      return a2 + 1;
    }
    else if ( n0x2000 == 0x2000 )
    {
      v5 = sub_7E3720(v3, 8, a2[1]);
      v6 = sub_A6A320(v5, a2[2]);
      sub_7E37B0(v13, 4, a2[3], v6);
      return a2 + 4;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    v10 = a2[2];
    v11 = sub_7E3720(v3, 8, a2[1]);
    *(_DWORD *)(v2 + 208) = v11;
    *(_BYTE *)(v2 + 212) = v10;
    v17 = (float)a2[3];
    *(float *)(v2 + 220) = v17 * 0.00390625;
    v12 = *(_DWORD *)(a1 + 848);
    if ( v11 )
    {
      (*(void (__cdecl **)(int))(v12 + 64))(v2);
      (*(void (__cdecl **)(int))(v12 + 68))(v2);
      *(_BYTE *)(v2 + 187) = 3;
      return a2 + 4;
    }
    else
    {
      nullsub_34();
      return a2 + 4;
    }
  }
}
