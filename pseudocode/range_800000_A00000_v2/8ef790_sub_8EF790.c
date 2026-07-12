// Function: sub_8EF790
// Address: 0x8ef790
_DWORD *__cdecl sub_8EF790(_DWORD *a1, unsigned int a2)
{
  *a1 = (unsigned __int8)a2;
  a1[1] = BYTE1(a2);
  a1[2] = BYTE2(a2);
  a1[3] = HIBYTE(a2);
  return a1 + 4;
}
