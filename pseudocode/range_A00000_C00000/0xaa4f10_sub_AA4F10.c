// Function: sub_AA4F10
// Address: 0xaa4f10
// Size: 0x25
// Prototype: 

int __cdecl sub_AA4F10(float *a1, _DWORD *a2)
{
  return (__PAIR64__(*(float *)a2 > *a1, *a2) - *(unsigned int *)a1) >> 32;
}

