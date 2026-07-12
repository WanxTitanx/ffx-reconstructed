// Function: sub_A5B490
// Address: 0xa5b490
// Size: 0x2c
// Prototype: 

int __cdecl sub_A5B490(int a1, int a2)
{
  if ( sub_A49440(a1, (_DWORD *)a2) )
  {
    *(_BYTE *)(a1 + 34) |= *(_BYTE *)(a2 + 16);
    *(_DWORD *)(a2 + 12) = 0;
  }
  return 0;
}

