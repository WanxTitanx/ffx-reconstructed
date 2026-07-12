// Function: sub_8EB5F0
// Address: 0x8eb5f0
_DWORD *__cdecl sub_8EB5F0(_DWORD *a1, int a2, int a3, int a4)
{
  int v4; // ebx

  *a1 = 32769;
  a1[1] = &loc_AF4000;
  a1[2] = 826491678;
  a1[3] = 1128469556;
  a1[4] = 556875264;
  a1[5] = 1074123782;
  a1[6] = 6;
  a1[7] = 0;
  dword_187168C = a1 + 8;
  v4 = (a4 - 10) & ((a4 - 10 < 0) - 1);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(144, 40);
  sub_8FACF0(a2, a3);
  sub_8FACA0(151, 54);
  sub_8FACF0(a2 + 7, a3 + 14);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(151, 40);
  sub_8FACF0(a2 + 5, a3);
  sub_8FACA0(201, 54);
  sub_8FACF0(v4 + a2 + 7, a3 + 14);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(202, 40);
  sub_8FACF0(v4 + a2 + 5, a3);
  sub_8FACA0(209, 54);
  sub_8FACF0(v4 + a2 + 14, a3 + 14);
  return dword_187168C;
}
