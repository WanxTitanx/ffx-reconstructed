// Function: sub_A39A90
// Address: 0xa39a90
// Size: 0x70
// Prototype: 

int __cdecl sub_A39A90(int a1, int a2, int a3, int a4)
{
  int v4; // edx
  int v5; // eax
  int result; // eax

  *(_DWORD *)(a1 + 48) ^= (a2 ^ *(_DWORD *)(a1 + 48)) & 0xFFFFFFF;
  *(_DWORD *)(a1 + 20) = a3;
  **(_DWORD **)(a1 + 24) -= a2;
  v4 = *(_DWORD *)(a1 + 24) + 16 + 56 * a4;
  *(_DWORD *)(*(_DWORD *)(a1 + 32) + 28) = *(_DWORD *)(a1 + 28);
  *(_DWORD *)(*(_DWORD *)(a1 + 28) + 32) = *(_DWORD *)(a1 + 32);
  *(_DWORD *)(a1 + 28) = v4;
  v5 = *(_DWORD *)(v4 + 32);
  *(_DWORD *)(a1 + 32) = v5;
  *(_DWORD *)(v5 + 28) = a1;
  *(_DWORD *)(*(_DWORD *)(a1 + 28) + 32) = a1;
  result = (a4 << 28) | *(_DWORD *)(a1 + 48) & 0xFFFFFFF;
  *(_DWORD *)(a1 + 48) = result;
  return result;
}

