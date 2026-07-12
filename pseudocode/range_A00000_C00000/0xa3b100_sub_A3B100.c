// Function: sub_A3B100
// Address: 0xa3b100
// Size: 0x55
// Prototype: 

unsigned int __stdcall sub_A3B100(_DWORD *a1, int a2, int a3)
{
  unsigned int n0x20000000; // eax
  int v4; // edx
  int v5; // eax

  n0x20000000 = a1[12] & 0xF0000000;
  if ( n0x20000000 == 0x20000000 )
  {
    v4 = a1[6];
    *(_DWORD *)(a1[8] + 28) = a1[7];
    *(_DWORD *)(a1[7] + 32) = a1[8];
    v4 += 72;
    a1[7] = v4;
    v5 = *(_DWORD *)(v4 + 32);
    a1[8] = v5;
    *(_DWORD *)(v5 + 28) = a1;
    *(_DWORD *)(a1[7] + 32) = a1;
    n0x20000000 = a1[12] & 0xFFFFFFF | 0x10000000;
    a1[12] = n0x20000000;
  }
  return n0x20000000;
}

