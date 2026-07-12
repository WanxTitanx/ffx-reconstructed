// Function: sub_8EFB90
// Address: 0x8efb90
_DWORD *__cdecl sub_8EFB90(_DWORD *a1, int a2, int a3)
{
  *a1 = 16 * a2 + 8;
  a1[1] = 16 * a3 + 8;
  return a1 + 4;
}
