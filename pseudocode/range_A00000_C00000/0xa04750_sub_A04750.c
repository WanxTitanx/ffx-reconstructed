// Function: sub_A04750
// Address: 0xa04750
// Size: 0x1cd
// Prototype: int __cdecl(int, int, float, char)

unsigned int __cdecl sub_A04750(int a1, int a2, float a3, char a4)
{
  unsigned int n0x18; // esi
  double v6; // st7
  int v7; // edx
  int n21_1; // eax
  int v9; // eax
  int v10; // esi
  float v11; // [esp+0h] [ebp-2D4h]
  int n21; // [esp+18h] [ebp-2BCh]
  _BYTE v13[4]; // [esp+1Ch] [ebp-2B8h] BYREF
  int v14[84]; // [esp+20h] [ebp-2B4h]
  _BYTE v15[4]; // [esp+170h] [ebp-164h] BYREF
  int v16[84]; // [esp+174h] [ebp-160h]
  int v17; // [esp+2D0h] [ebp-4h]

  if ( *(_DWORD *)(*(_DWORD *)a2 + 8) != 12 || *(_DWORD *)(a2 + 28) != *(_DWORD *)(a1 + 28) )
    return 5;
  sub_583610(v15);
  v17 = 0;
  n0x18 = sub_A1B430(v15);
  if ( !n0x18 && v16[0] )
  {
    sub_583610(v13);
    LOBYTE(v17) = 1;
    n0x18 = sub_A1B4C0(v13);
    if ( n0x18 || !v14[0] )
    {
      if ( !sub_59E190(*(_DWORD *)(a2 + 8), v15) )
        *(_BYTE *)(a2 + 4) = 0;
    }
    else
    {
      v6 = a3;
      n21 = 0;
      while ( 1 )
      {
        v7 = *(int *)((char *)v14 + n0x18);
        if ( !*(int *)((char *)v16 + n0x18) || !v7 )
          break;
        v11 = v6;
        n21_1 = sub_A042C0(
                  v7,
                  *(int *)((char *)v16 + n0x18),
                  *(_DWORD *)(a2 + 28),
                  *(_DWORD *)(a2 + 28),
                  4 * *(_DWORD *)(a2 + 28),
                  *(_DWORD *)a1,
                  v11,
                  a4);
        if ( n21_1 )
        {
          n21 = n21_1;
          goto LABEL_16;
        }
        v6 = a3;
        n0x18 += 4;
        if ( n0x18 >= 0x18 )
          goto LABEL_16;
      }
      n21 = 21;
LABEL_16:
      if ( !sub_59E190(*(_DWORD *)(a2 + 8), v15) )
        *(_BYTE *)(a2 + 4) = 0;
      v9 = *(_DWORD *)(a1 + 32) & 0x7FFFFFFF;
      if ( !v9 )
        v9 = 1;
      v10 = v9 != *(_DWORD *)(a1 + 8) + 1 ? *(_DWORD *)(a1 + 8) + 1 : 0;
      if ( !sub_59E360(v10, v13) )
      {
        *(_DWORD *)(a1 + 8) = v10;
        *(_BYTE *)(a1 + 4) = 0;
      }
      n0x18 = n21;
    }
    LOBYTE(v17) = 0;
    nullsub_21(v13);
  }
  v17 = -1;
  nullsub_21(v15);
  return n0x18;
}

