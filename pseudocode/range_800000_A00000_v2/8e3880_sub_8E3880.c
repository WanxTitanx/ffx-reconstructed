// Function: sub_8E3880
// Address: 0x8e3880
char __cdecl sub_8E3880(int a1)
{
  int n8; // edi
  __int16 v2; // bx
  int v3; // ecx
  int n10; // eax
  int (__cdecl *v5)(int, _DWORD, _DWORD); // ecx

  n8 = (unsigned __int16)sub_8BE3E0();
  v2 = sub_8BE440();
  v3 = (unsigned __int16)sub_8BE480();
  *(_WORD *)(a1 + 70) += *(_WORD *)(a1 + 56);
  if ( *(__int16 *)(a1 + 70) > 4096 )
    *(_WORD *)(a1 + 70) = 4096;
  if ( *(__int16 *)(a1 + 70) < 0 )
    *(_WORD *)(a1 + 70) = 0;
  n10 = *(_DWORD *)(a1 + 40);
  while ( 2 )
  {
    switch ( n10 )
    {
      case 0:
      case 1:
        LOBYTE(n10) = sub_8AAE60(*(_DWORD *)(a1 + 12 * *(__int16 *)(a1 + 72) + 92));
        *(_DWORD *)(a1 + 40) = 2;
        return n10;
      case 2:
        *(_DWORD *)(a1 + 40) = 3;
        return n10;
      case 3:
      case 4:
        *(_DWORD *)(a1 + 40) = 5;
        return n10;
      case 5:
        if ( *(_WORD *)(a1 + 70) != 4096 )
          return n10;
        if ( (v3 & 0x20) != 0 )
        {
          v5 = *(int (__cdecl **)(int, _DWORD, _DWORD))(a1 + 28);
          if ( !v5 || v5(a1, *(__int16 *)(a1 + 72), *(char *)(a1 + 69)) )
          {
            LOBYTE(n10) = FFX_BtlEffect_Enable(-2147483647);
            *(_DWORD *)(a1 + 40) = 6;
          }
          else
          {
            LOBYTE(n10) = FFX_BtlEffect_Enable(-2147483645);
          }
          return n10;
        }
        if ( (v3 & 0x40) != 0 )
        {
          LOBYTE(n10) = FFX_BtlEffect_Enable(-2147483644);
          *(_DWORD *)(a1 + 40) = 8;
          return n10;
        }
        if ( *(_WORD *)(a1 + 48) <= 1u )
          goto LABEL_28;
        if ( v2 < 0 )
        {
          FFX_BtlEffect_Enable(-2147483647);
          if ( (__int16)--*(_WORD *)(a1 + 72) < 0 )
            *(_WORD *)(a1 + 72) = *(_WORD *)(a1 + 48) - 1;
LABEL_24:
          LOBYTE(n10) = sub_8AAE60(*(_DWORD *)(a1 + 12 * *(__int16 *)(a1 + 72) + 92));
          return n10;
        }
        if ( (v2 & 0x2000) != 0 )
        {
          FFX_BtlEffect_Enable(-2147483647);
          if ( (__int16)++*(_WORD *)(a1 + 72) >= (int)*(unsigned __int16 *)(a1 + 48) )
            *(_WORD *)(a1 + 72) = 0;
          goto LABEL_24;
        }
LABEL_28:
        LOBYTE(n10) = *(_BYTE *)(a1 + 68);
        if ( (_BYTE)n10 )
        {
          if ( (_BYTE)n10 == 1 )
          {
            n10 = sub_8A9BA0();
            if ( n10 > 1 )
            {
              n10 = sub_8AB1D0();
              if ( n10 )
              {
                if ( (v2 & 4) != 0 && n8 == 4 )
                {
                  FFX_BtlEffect_Enable(-2147483644);
                  LOBYTE(n10) = sub_8AAF90();
                }
                else if ( (v2 & 8) != 0 && n8 == 8 )
                {
                  FFX_BtlEffect_Enable(-2147483644);
                  LOBYTE(n10) = sub_8AAF20();
                }
              }
            }
          }
        }
        else
        {
          n10 = sub_8A9AE0(v3);
          if ( n10 > 1 )
          {
            n10 = sub_8AB1D0();
            if ( n10 )
            {
              if ( (v2 & 4) != 0 && n8 == 4 )
              {
                FFX_BtlEffect_Enable(-2147483644);
                LOBYTE(n10) = sub_8AAF50();
              }
              else if ( (v2 & 8) != 0 && n8 == 8 )
              {
                FFX_BtlEffect_Enable(-2147483644);
                LOBYTE(n10) = sub_8AAEC0();
              }
            }
          }
        }
        return n10;
      case 6:
        LOWORD(n10) = *(_WORD *)(a1 + 72);
        *(_BYTE *)(a1 + 69) = 1;
        *(_WORD *)(a1 + 44) = n10;
        *(_DWORD *)(a1 + 40) = 7;
        return n10;
      case 8:
        *(_BYTE *)(a1 + 69) = -1;
        *(_DWORD *)(a1 + 40) = 9;
        goto LABEL_8;
      case 9:
LABEL_8:
        n10 = 10;
        continue;
      case 10:
        *(_DWORD *)(a1 + 40) = 11;
        return n10;
      case 14:
        *(_DWORD *)(a1 + 40) = 15;
        return n10;
      case 15:
        *(_DWORD *)(a1 + 40) = 16;
        return n10;
      case 16:
        *(_DWORD *)(a1 + 40) = 4;
        return n10;
      default:
        return n10;
    }
  }
}
