// Function: sub_8EB150
// Address: 0x8eb150
_DWORD *__cdecl sub_8EB150(_DWORD *a1, int a2, int a3, int a4)
{
  *a1 = 2;
  a1[1] = 0x10000000;
  a1[2] = 14;
  a1[3] = 0;
  a1[4] = 556875264;
  a1[5] = 1074123782;
  a1[6] = 6;
  a1[7] = 0;
  a1[8] = &unk_2000000;
  a1[9] = &unk_1A00000;
  a1[10] = 64;
  a1[11] = 0;
  a1[12] = 32769;
  a1[13] = 1352876032;
  a1[14] = 279022;
  a1[15] = 0;
  dword_187168C = a1 + 16;
  sub_8FAA20(0, 1, 0, 1, 128);
  sub_8FABE0(1, 7, 0, 0, 0, 0, 0, 0);
  sub_8FAB80(0, 0, 0, 128);
  sub_8FACF0(a2, a3);
  sub_8FACF0(a2 + a4, a3 + 19);
  return dword_187168C;
}
