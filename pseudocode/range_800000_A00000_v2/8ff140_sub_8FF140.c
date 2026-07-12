// Function: sub_8FF140
// Address: 0x8ff140
_DWORD *__cdecl sub_8FF140(int n16)
{
  _DWORD *n16_1; // eax

  n16_1 = (_DWORD *)n16;
  if ( n16 < 16 )
  {
    n16_1 = (_DWORD *)((char *)&unk_18762A0 + 16 * n16);
    *n16_1 = 0;
    n16_1[1] = 0;
    n16_1[2] = 0;
    n16_1[3] = 0;
  }
  return n16_1;
}
