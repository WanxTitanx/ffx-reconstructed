// Function: sub_A92650
// Address: 0xa92650
// Size: 0x21
// Prototype: int __cdecl(const void *, const void *)

int __cdecl sub_A92650(_DWORD **a1, _DWORD **a2)
{
  return (__PAIR64__(**a2 < **a1, **a1) - (unsigned int)**a2) >> 32;
}

