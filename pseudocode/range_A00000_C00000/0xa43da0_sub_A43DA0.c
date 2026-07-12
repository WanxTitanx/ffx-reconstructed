// Function: sub_A43DA0
// Address: 0xa43da0
// Size: 0x40
// Prototype: int __cdecl(int, void *, int)

size_t __cdecl sub_A43DA0(unsigned __int8 *a1, void *a2, size_t *a3)
{
  size_t Size; // esi

  Size = a1[1] + ((a1[2] + ((a1[3] + (a1[4] << 8)) << 8)) << 8);
  memcpy(a2, a1 + 5, Size);
  *a3 = Size;
  return Size;
}

