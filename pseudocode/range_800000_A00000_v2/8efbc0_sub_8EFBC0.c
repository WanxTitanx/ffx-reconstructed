// Function: sub_8EFBC0
// Address: 0x8efbc0
_DWORD *__cdecl sub_8EFBC0(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  *a1 = a3 + 16 * a2;
  a1[1] = a5 + 16 * a4;
  return a1 + 4;
}
