// Function: sub_A8FFD0
// Address: 0xa8ffd0
// Size: 0x44
// Prototype: 

void *__cdecl sub_A8FFD0(int a1)
{
  void *v1; // esi
  void *result; // eax

  *(_QWORD *)a1 = 0;
  *(_QWORD *)(a1 + 8) = 0;
  *(_QWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 24) = 0;
  v1 = calloc_0(1u, 0xE50u);
  result = memset(v1, 0, 0xE50u);
  *(_DWORD *)(a1 + 28) = v1;
  return result;
}

