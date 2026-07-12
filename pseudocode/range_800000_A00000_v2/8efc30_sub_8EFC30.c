// Function: sub_8EFC30
// Address: 0x8efc30
_DWORD *__cdecl sub_8EFC30(_DWORD *a1, int a2, int a3)
{
  *a1 = a2;
  a1[1] = a3;
  a1[2] = 16;
  a1[3] = 0;
  return a1 + 4;
}
