// Function: sub_A3B0C0
// Address: 0xa3b0c0
// Size: 0x38
// Prototype: 

int __stdcall sub_A3B0C0(_DWORD *a1, int a2, int a3)
{
  int n5; // ecx

  n5 = a1[12] >> 28;
  if ( n5 != 5 )
  {
    if ( a1[5] != a2 )
      return 0;
    if ( n5 == 1 )
      sub_A3A010(a1, 2);
  }
  return 1;
}

