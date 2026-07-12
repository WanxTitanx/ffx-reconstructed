// Function: sub_A3A010
// Address: 0xa3a010
// Size: 0x55
// Prototype: 

int __cdecl sub_A3A010(_DWORD *a1, int a2)
{
  int v2; // edx
  int v3; // eax
  int result; // eax

  v2 = a1[6] + 16 + 56 * a2;
  *(_DWORD *)(a1[8] + 28) = a1[7];
  *(_DWORD *)(a1[7] + 32) = a1[8];
  a1[7] = v2;
  v3 = *(_DWORD *)(v2 + 32);
  a1[8] = v3;
  *(_DWORD *)(v3 + 28) = a1;
  *(_DWORD *)(a1[7] + 32) = a1;
  result = (a2 << 28) | a1[12] & 0xFFFFFFF;
  a1[12] = result;
  return result;
}

