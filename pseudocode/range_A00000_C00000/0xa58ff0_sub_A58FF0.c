// Function: sub_A58FF0
// Address: 0xa58ff0
// Size: 0x2dc
// Prototype: _DWORD __cdecl(int (__cdecl *sub_A45000)(int))

void __cdecl sub_A58FF0(int (__cdecl *sub_A45000)(int))
{
  int v1; // esi
  __int16 *v2; // esi
  __int16 *v3; // esi
  int v4; // ecx
  double v5; // st7
  double v6; // st7
  unsigned __int16 v7; // cx
  __int16 v8; // cx
  double v9; // st7
  double v10; // st6
  double v11; // st6
  double v12; // st6
  float v13; // [esp+Ch] [ebp-18h] BYREF
  float v14; // [esp+10h] [ebp-14h] BYREF
  float v15; // [esp+14h] [ebp-10h]

  v1 = dword_2305834[0] + 70328;
  if ( *(_DWORD *)(dword_2305834[0] + 71088) )
    return;
  if ( *(float *)(dword_2305834[0] + 71140) < 0.0 )
    *(float *)(dword_2305834[0] + 71140) = 1.0;
  if ( sub_A56BD0(&v14) )
  {
    *(_BYTE *)(dword_2305834[0] + 71117) = 1;
    *(float *)v1 = *(float *)v1 + v14;
    *(float *)(v1 + 4) = *(float *)(v1 + 4) + v15;
    v4 = dword_2305834[0];
    if ( *(float *)(dword_2305834[0] + 71180) <= (double)*(float *)v1 )
    {
      if ( *(float *)(dword_2305834[0] + 71188) >= (double)*(float *)v1 )
        goto LABEL_17;
      v5 = *(float *)(dword_2305834[0] + 71188);
    }
    else
    {
      v5 = *(float *)(dword_2305834[0] + 71180);
    }
    *(float *)v1 = v5;
    v4 = dword_2305834[0];
LABEL_17:
    if ( *(float *)(v4 + 71184) <= (double)*(float *)(v1 + 4) )
    {
      if ( *(float *)(v4 + 71192) >= (double)*(float *)(v1 + 4) )
        goto LABEL_22;
      v6 = *(float *)(v4 + 71192);
    }
    else
    {
      v6 = *(float *)(v4 + 71184);
    }
    *(float *)(v1 + 4) = v6;
    v4 = dword_2305834[0];
LABEL_22:
    *(_DWORD *)(v4 + 70408) = *(_DWORD *)(v4 + 70328);
    *(_DWORD *)(v4 + 70412) = *(_DWORD *)(v4 + 70332);
    *(_DWORD *)(v4 + 70416) = *(_DWORD *)(v4 + 70336);
    *(_DWORD *)(v4 + 70420) = *(_DWORD *)(v4 + 70340);
    v7 = (unsigned __int16)sub_A56A40(&v13, (float *)v1, (int (__cdecl *)(__int16 *))sub_A45000);
    if ( *(float *)(v1 + 60) < (double)v13 )
      return;
    v8 = v7 - LOWORD(dword_2305834[0]) - 2056;
    *(_WORD *)(v1 + 68) = v8 / 40;
    v13 = sub_A56F30((unsigned __int16)(v8 / 40));
    v9 = v13;
    v10 = *(float *)(v1 + 60);
    if ( v13 >= v10 )
    {
      if ( v10 >= v9 )
        return;
      v13 = *(float *)(v1 + 60) + 2.0;
      v12 = v13;
      *(float *)(v1 + 60) = v13;
      if ( v12 <= v9 )
        return;
    }
    else
    {
      v13 = v10 - 2.0;
      v11 = v13;
      *(float *)(v1 + 60) = v13;
      if ( v11 >= v9 )
        return;
    }
    *(float *)(v1 + 60) = v9;
    return;
  }
  if ( *(_BYTE *)(dword_2305834[0] + 71117) )
  {
    *(_BYTE *)(dword_2305834[0] + 71117) = 0;
    v2 = sub_A56A40(&v13, (float *)v1, (int (__cdecl *)(__int16 *))sub_A45000);
    if ( v2 )
    {
      FFX_BtlEffect_Enable(-2147483647);
      sub_A48D20(((int)v2 - dword_2305834[0] - 2056) / 40, 0.5);
    }
  }
  else if ( 0.0 != v14 || v15 != 0.0 )
  {
    v3 = sub_A56860((float *)v1, (int)&v14, (int (__cdecl *)(__int16 *))sub_A45000);
    if ( v3 )
    {
      FFX_BtlEffect_Enable(-2147483647);
      sub_A48D20(((int)v3 - dword_2305834[0] - 2056) / 40, 0.25);
    }
  }
}

