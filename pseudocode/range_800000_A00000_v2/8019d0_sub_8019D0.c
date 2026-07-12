// Function: sub_8019D0
// Address: 0x8019d0
int __cdecl sub_8019D0(_DWORD *a1, int a2)
{
  int v2; // esi
  float v3; // ecx
  unsigned int n0x8000; // eax
  __int16 v6; // di
  int v7; // eax
  int v8; // esi
  float v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]

  v2 = a1[136];
  v10 = v2;
  v3 = flt_12A80C0[*(unsigned __int8 *)(v2 + 24)];
  n0x8000 = *((_WORD *)a1 + 269) & 0xF000;
  v9 = v3;
  if ( n0x8000 > 0x4000 )
  {
    if ( (*((_WORD *)a1 + 269) & 0xF000u) > 0x7000 )
    {
      if ( n0x8000 == 0x8000 )
      {
        sub_805320(a1, LODWORD(v3));
        sub_7E82C0(v2 + 192, a1, v2 + 192);
        return a2 + 2;
      }
    }
    else
    {
      switch ( n0x8000 )
      {
        case 0x7000u:
          sub_7EA5E0(a1);
          sub_7E9440(a1, a1, v2 + 48);
          sub_7E82C0(v2 + 192, v2 + 192, a1);
          return a2 + 2;
        case 0x5000u:
          sub_805320(a1, LODWORD(v3));
          sub_805350(a1 + 16, LODWORD(v9), *(__int16 *)(a2 + 2));
          sub_7E82C0(v2 + 192, a1, a1 + 16);
          return a2 + 4;
        case 0x6000u:
          sub_8052C0(LODWORD(v3), v2 + 192);
          return a2 + 2;
      }
    }
  }
  else
  {
    if ( n0x8000 == 0x4000 )
    {
      sub_7EA460(v2 + 192, v2 + 192, v2 + 144);
      return a2 + 2;
    }
    if ( (*((_WORD *)a1 + 269) & 0xF000u) > 0x2000 )
    {
      if ( n0x8000 == 12288 )
      {
        sub_7E82C0(v2 + 192, v2 + 192, a1 + 160);
        return a2 + 2;
      }
    }
    else
    {
      if ( n0x8000 == 0x2000 )
      {
        sub_7E78B0(v2 + 240, v2 + 192, v2 + 144);
        return a2 + 2;
      }
      if ( (*((_WORD *)a1 + 269) & 0xF000) == 0 )
      {
        v6 = *(_WORD *)(v2 + 184);
        *(_WORD *)(v2 + 184) = *(_WORD *)(a2 + 2);
        v7 = sub_801E20(a1, (unsigned __int16 *)v2);
        sub_6ED590(a1, v7);
        v8 = v2 + 144;
        sub_7E78B0(v8, a1, v8);
        sub_7EA760(v10 + 64, v8, 16.0);
        *(_WORD *)(v10 + 184) = v6;
        return a2 + 4;
      }
      if ( n0x8000 == 4096 )
      {
        sub_805350(v2 + 192, LODWORD(v3), *(__int16 *)(a2 + 2));
        return a2 + 4;
      }
    }
  }
  return a2;
}
