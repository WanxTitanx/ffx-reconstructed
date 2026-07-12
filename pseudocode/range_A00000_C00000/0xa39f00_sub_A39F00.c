// Function: sub_A39F00
// Address: 0xa39f00
// Size: 0x53
// Prototype: 

unsigned int __cdecl sub_A39F00(_DWORD *a1)
{
  unsigned int n0x20000000; // eax
  int v2; // edx
  int v3; // eax

  n0x20000000 = a1[12] & 0xF0000000;
  if ( n0x20000000 == 0x20000000 )
  {
    v2 = a1[6];
    *(_DWORD *)(a1[8] + 28) = a1[7];
    *(_DWORD *)(a1[7] + 32) = a1[8];
    v2 += 72;
    a1[7] = v2;
    v3 = *(_DWORD *)(v2 + 32);
    a1[8] = v3;
    *(_DWORD *)(v3 + 28) = a1;
    *(_DWORD *)(a1[7] + 32) = a1;
    n0x20000000 = a1[12] & 0xFFFFFFF | 0x10000000;
    a1[12] = n0x20000000;
  }
  return n0x20000000;
}

