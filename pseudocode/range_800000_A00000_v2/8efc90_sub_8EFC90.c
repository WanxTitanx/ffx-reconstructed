// Function: sub_8EFC90
// Address: 0x8efc90
_DWORD *__cdecl sub_8EFC90(_DWORD *a1, int a2, int a3, int a4)
{
  *a1 = 16 * (a2 + 1792);
  a1[1] = 16 * (a3 + 1840);
  a1[2] = 16 * a4;
  a1[3] = 0;
  return a1 + 4;
}
