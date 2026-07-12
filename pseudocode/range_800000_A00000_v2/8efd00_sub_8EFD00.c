// Function: sub_8EFD00
// Address: 0x8efd00
_DWORD *__cdecl sub_8EFD00(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  *a1 = 16 * (a2 + 1792);
  a1[1] = 16 * (a3 + 1840);
  a1[2] = 16 * a4;
  a1[3] = 16 * a5;
  return a1 + 4;
}
