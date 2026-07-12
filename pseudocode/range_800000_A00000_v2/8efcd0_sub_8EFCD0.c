// Function: sub_8EFCD0
// Address: 0x8efcd0
_DWORD *__cdecl sub_8EFCD0(_DWORD *a1, int a2, int a3, int a4)
{
  *a1 = a2;
  a1[1] = a3;
  a1[2] = a4;
  a1[3] = 0;
  return a1 + 4;
}
