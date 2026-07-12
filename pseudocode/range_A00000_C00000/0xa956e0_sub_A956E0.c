// Function: sub_A956E0
// Address: 0xa956e0
// Size: 0x29
// Prototype: int __cdecl(const void *, const void *)

int __cdecl sub_A956E0(float **a1, _DWORD **a2)
{
  return (__PAIR64__(*(float *)*a2 > **a1, **a2) - *(unsigned int *)*a1) >> 32;
}

