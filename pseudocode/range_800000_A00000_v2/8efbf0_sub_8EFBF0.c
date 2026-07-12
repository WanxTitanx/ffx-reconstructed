// Function: sub_8EFBF0
// Address: 0x8efbf0
_DWORD *__cdecl sub_8EFBF0(_DWORD *a1, int a2, int a3)
{
  *a1 = 16 * (a2 + 1792);
  a1[1] = 16 * (a3 + 1840);
  a1[2] = 16;
  a1[3] = 0;
  return a1 + 4;
}
