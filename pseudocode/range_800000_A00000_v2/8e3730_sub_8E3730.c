// Function: sub_8E3730
// Address: 0x8e3730
int __cdecl sub_8E3730(int a1)
{
  __int16 v1; // di
  __int16 v2; // bx
  int n4; // eax
  __int16 v4; // ax

  sub_8BE3E0();
  v1 = sub_8BE440();
  v2 = sub_8BE480();
  n4 = *(_DWORD *)(a1 + 40);
  while ( 2 )
  {
    switch ( n4 )
    {
      case 0:
        *(_BYTE *)(a1 + 69) = 0;
        *(_WORD *)(a1 + 72) = 1;
        if ( *(_DWORD *)(a1 + 88) )
        {
          *(_DWORD *)(a1 + 40) = 1;
        }
        else
        {
          n4 = (*(_DWORD *)(a1 + 144) != 1) + 2;
          *(_DWORD *)(a1 + 40) = n4;
        }
        return n4;
      case 1:
        if ( (v2 & 0x20) != 0 )
        {
          FFX_BtlEffect_Enable(-2147483647);
          n4 = 4;
          continue;
        }
        if ( (v2 & 0x40) != 0 )
        {
          FFX_BtlEffect_Enable(-2147483644);
          n4 = 6;
          continue;
        }
        if ( (v1 & 0x5000) != 0 )
        {
          FFX_BtlEffect_Enable(-2147483647);
          n4 = *(_WORD *)(a1 + 72) == 0;
          *(_WORD *)(a1 + 72) = n4;
        }
        return n4;
      case 2:
        if ( !v2 )
          return n4;
        if ( *(_BYTE *)(a1 + 55) )
          n4 = FFX_BtlEffect_Enable(-2147483647);
LABEL_17:
        *(_DWORD *)(a1 + 40) = 4;
        return n4;
      case 3:
        goto LABEL_17;
      case 4:
        v4 = *(_WORD *)(a1 + 72);
        *(_BYTE *)(a1 + 69) = 1;
        *(_WORD *)(a1 + 44) = v4;
        *(_DWORD *)(a1 + 40) = 5;
        n4 = 5;
        continue;
      case 6:
        *(_BYTE *)(a1 + 69) = 1;
        *(_WORD *)(a1 + 44) = 1;
        *(_WORD *)(a1 + 72) = 1;
        *(_DWORD *)(a1 + 40) = 7;
        n4 = 7;
        continue;
      default:
        return n4;
    }
  }
}
