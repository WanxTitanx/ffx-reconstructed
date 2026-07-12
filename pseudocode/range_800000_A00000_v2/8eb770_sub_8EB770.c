// Function: sub_8EB770
// Address: 0x8eb770
_DWORD *__cdecl sub_8EB770(
        _DWORD *a1,
        int a2,
        int a3,
        int a4,
        unsigned __int8 n128,
        unsigned __int8 a6,
        unsigned __int8 a7,
        unsigned __int8 a8)
{
  int v8; // esi
  int v10; // [esp+20h] [ebp+14h]

  v10 = a4 - 24;
  *a1 = 32769;
  a1[1] = &loc_AF4000;
  a1[2] = 826491678;
  a1[3] = 1128469556;
  a1[4] = 556875264;
  a1[5] = 1074123782;
  a1[6] = 6;
  a1[7] = 0;
  dword_187168C = a1 + 8;
  sub_8FAB80(n128, a6, a7, a8);
  sub_8FACA0(112, 40);
  sub_8FACF0(a2, a3);
  sub_8FACA0(124, 58);
  sub_8FACF0(a2 + 12, a3 + 18);
  sub_8FAB80(n128, a6, a7, a8);
  sub_8FACA0(124, 40);
  sub_8FACF0(a2 + 12, a3);
  sub_8FACA0(127, 58);
  v8 = a2 + v10 + 12;
  sub_8FACF0(v8, a3 + 18);
  sub_8FAB80(n128, a6, a7, a8);
  sub_8FACA0(128, 40);
  sub_8FACF0(v8, a3);
  sub_8FACA0(140, 58);
  sub_8FACF0(a2 + 24 + v10, a3 + 18);
  return dword_187168C;
}
