// Function: sub_A34AE0
// Address: 0xa34ae0
// Size: 0x1c
// Prototype: 

int __cdecl sub_A34AE0(_DWORD *a1)
{
  int v1; // esi
  int result; // eax

  v1 = a1[1];
  result = sub_A3BAF0(*a1, *(_DWORD *)(v1 + 4));
  *(_DWORD *)(v1 + 8) = result;
  return result;
}

