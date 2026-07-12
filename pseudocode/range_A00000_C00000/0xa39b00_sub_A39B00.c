// Function: sub_A39B00
// Address: 0xa39b00
// Size: 0x3b
// Prototype: 

int __cdecl sub_A39B00(_DWORD *a1)
{
  int v1; // edx
  int v2; // eax
  int result; // eax

  v1 = a1[6];
  *(_DWORD *)(a1[8] + 28) = a1[7];
  *(_DWORD *)(a1[7] + 32) = a1[8];
  v1 += 16;
  a1[7] = v1;
  v2 = *(_DWORD *)(v1 + 32);
  a1[8] = v2;
  *(_DWORD *)(v2 + 28) = a1;
  result = a1[7];
  *(_DWORD *)(result + 32) = a1;
  a1[12] &= 0xFFFFFFFu;
  return result;
}

