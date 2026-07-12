// Function: sub_8EF800
// Address: 0x8ef800
_DWORD *__cdecl sub_8EF800(_DWORD *a1, int a2)
{
  a1[1] = a2 << 24;
  *a1 = 0;
  a1[2] = 10;
  a1[3] = 0;
  return a1 + 4;
}
