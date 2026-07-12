// Function: sub_A384B0
// Address: 0xa384b0
// Size: 0x18
// Prototype: 

int *__stdcall sub_A384B0(int a1, int *a2)
{
  *a2 = *(_DWORD *)(a1 + 48) & 0xFFFFFFF;
  return a2;
}

