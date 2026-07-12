// Function: sub_A3B480
// Address: 0xa3b480
// Size: 0x75
// Prototype: 

int __cdecl sub_A3B480(int a1, int a2)
{
  int v2; // ecx
  int v3; // eax
  int v4; // edx
  int v5; // eax
  int result; // eax

  sub_A34BC0((_DWORD *)a1);
  *(_WORD *)a2 |= 8u;
  ++*(_WORD *)(a2 + 6);
  *(_DWORD *)(a2 + 32) += *(_DWORD *)(a1 + 48) & 0xFFFFFFF;
  **(_DWORD **)(a1 + 24) += *(_DWORD *)(a1 + 48) & 0xFFFFFFF;
  v2 = *(_DWORD *)(a1 + 32);
  v3 = *(_DWORD *)(a1 + 28);
  *(_DWORD *)(a1 + 48) &= 0xF0000000;
  v4 = *(_DWORD *)(a1 + 24);
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(v2 + 28) = v3;
  *(_DWORD *)(*(_DWORD *)(a1 + 28) + 32) = *(_DWORD *)(a1 + 32);
  v4 += 16;
  *(_DWORD *)(a1 + 28) = v4;
  v5 = *(_DWORD *)(v4 + 32);
  *(_DWORD *)(a1 + 32) = v5;
  *(_DWORD *)(v5 + 28) = a1;
  result = *(_DWORD *)(a1 + 28);
  *(_DWORD *)(result + 32) = a1;
  *(_DWORD *)(a1 + 48) &= 0xFFFFFFFu;
  return result;
}

