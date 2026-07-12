// Function: sub_8142B0
// Address: 0x8142b0
int __cdecl sub_8142B0(int a1, int a2)
{
  int v2; // esi
  __int16 *p_n30; // ebx
  int v4; // ecx
  int v5; // edx
  int n8; // edi
  unsigned int n24576; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int i; // esi
  int j; // esi
  int v15; // ecx
  int v16; // eax
  int v17; // [esp+Ch] [ebp-4h]

  v2 = a2;
  p_n30 = (__int16 *)(a2 + 2);
  v17 = *(_DWORD *)(a1 + 544);
  v4 = *(unsigned __int8 *)(v17 + 30);
  v5 = *(_DWORD *)(a1 + 4 * v4 + 864);
  if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 )
  {
    n8 = 8;
  }
  else
  {
    n8 = 0x10000;
    if ( *(_BYTE *)(v17 + 30) )
    {
      do
      {
        n8 *= 2;
        --v4;
      }
      while ( v4 );
    }
  }
  n24576 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( n24576 <= 0x6000 )
  {
    if ( n24576 == 24576 )
    {
      v12 = sub_7E3720(v5, 6, (unsigned __int16)*p_n30);
      sub_8002B0(v12, *(__int16 *)(a2 + 4));
      return a2 + 6;
    }
    if ( (*(_WORD *)(a1 + 538) & 0xF000u) > 0x3000 )
    {
      if ( n24576 == 0x4000 )
      {
        v11 = sub_7E3720(v5, 6, (unsigned __int16)*p_n30);
        sub_7FFC40(v11, v17 + 144, 256);
        return a2 + 6;
      }
      if ( n24576 == 20480 )
      {
        v10 = sub_7E3720(v5, 6, (unsigned __int16)*p_n30);
        sub_7FFB80(v10, v17 + 144, 256);
        return a2 + 6;
      }
      return v2;
    }
    if ( n24576 == 12288 )
    {
      if ( sub_800010() )
      {
        *(_BYTE *)(a1 + 528) = 1;
        return a2;
      }
    }
    else
    {
      if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
      {
        v9 = sub_7E3720(v5, 6, (unsigned __int16)*p_n30);
        sub_7FFD30(v9, 64, 256);
        return a2 + 4;
      }
      if ( n24576 != 4096 )
      {
        if ( n24576 == 0x2000 )
        {
          sub_7FFE50(n8);
          return a2 + 2;
        }
        return v2;
      }
      sub_8001E0(v5, 0, 1000, n8);
    }
    return a2 + 2;
  }
  if ( (*(_WORD *)(a1 + 538) & 0xF000u) > 0xA000 )
  {
    if ( n24576 == 45056 )
    {
      v16 = sub_7E3720(v5, 6, (unsigned __int16)*p_n30);
      sub_7FFD00(v16, *(__int16 *)(a2 + 4));
      return a2 + 6;
    }
    if ( n24576 != 49152 )
      return v2;
    v15 = FFX_BtlMenu_PostBattle_FadeTransitionSetup();
    if ( v15 >= 0 )
      sub_886AA0(v15, *p_n30, 0);
    return a2 + 4;
  }
  else
  {
    if ( n24576 != 40960 )
    {
      switch ( n24576 )
      {
        case 0x7000u:
          sub_79FD40(*(_BYTE *)(v17 + 24), 1);
          break;
        case 0x8000u:
          sub_79FD40(*(_BYTE *)(v17 + 24), 0);
          break;
        case 0x9000u:
          for ( i = 0; i < 32; ++i )
          {
            if ( LODWORD(flt_12A80C0[i]) )
              sub_79FD40(i, 1);
          }
          return a2 + 2;
        default:
          return v2;
      }
      return a2 + 2;
    }
    for ( j = 0; j < 32; ++j )
    {
      if ( LODWORD(flt_12A80C0[j]) )
        sub_79FD40(j, 0);
    }
    return a2 + 2;
  }
}
