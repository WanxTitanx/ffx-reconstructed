// Function: sub_8EB4E0
// Address: 0x8eb4e0
_DWORD *__cdecl sub_8EB4E0(_DWORD *a1)
{
  _DWORD *result; // eax

  *a1 = 32773;
  a1[1] = 0x10000000;
  a1[2] = 14;
  a1[3] = 0;
  dword_187168C = a1 + 4;
  sub_8FAC80();
  result = dword_187168C + 16;
  *dword_187168C = &unk_2000000;
  *(result - 15) = &unk_1A00000;
  *(result - 14) = 64;
  *(result - 13) = 0;
  *(result - 12) = 0;
  *(result - 11) = 0;
  *(result - 10) = 8;
  *(result - 9) = 0;
  *(result - 8) = 68;
  *(result - 7) = 128;
  *(result - 6) = 66;
  *(result - 5) = 0;
  *(result - 4) = 15;
  *(result - 3) = 0;
  *(result - 2) = 71;
  *(result - 1) = 0;
  dword_187168C = result;
  return result;
}
