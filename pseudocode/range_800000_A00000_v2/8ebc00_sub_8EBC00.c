// Function: sub_8EBC00
// Address: 0x8ebc00
_DWORD *__cdecl sub_8EBC00(
        _DWORD *a1,
        int a2,
        int a3,
        int a4,
        unsigned __int8 n128,
        unsigned __int8 a6,
        unsigned __int8 a7,
        unsigned __int8 a8)
{
  _DWORD *v8; // eax

  *a1 = 1;
  a1[1] = 805306368;
  a1[2] = 3822;
  a1[3] = 0;
  dword_187168C = a1 + 4;
  sub_8FAA20(0, 1, 0, 1, 128);
  v8 = dword_187168C;
  *dword_187168C = 15;
  v8[1] = 0;
  v8[2] = 71;
  v8[3] = 0;
  v8[4] = 556875264;
  v8[5] = 1074123782;
  v8[6] = 6;
  v8[7] = 0;
  v8[8] = 32771;
  v8[9] = 1353662464;
  v8[10] = 275505;
  v8[11] = 0;
  dword_187168C = v8 + 12;
  sub_8FAB80(n128, a6, a7, a8);
  sub_8FACA0(103, 0);
  sub_8FACF0(a2 - 14, a3 - 3);
  sub_8FACA0(117, 19);
  sub_8FACF0(a2, a3 + 16);
  sub_8FAB80(n128, a6, a7, a8);
  sub_8FACA0(117, 0);
  sub_8FACF0(a2, a3 - 3);
  sub_8FACA0(120, 19);
  sub_8FACF0(a2 + a4, a3 + 16);
  sub_8FAB80(n128, a6, a7, a8);
  sub_8FACA0(121, 0);
  sub_8FACF0(a2 + a4, a3 - 3);
  sub_8FACA0(133, 19);
  sub_8FACF0(a2 + a4 + 12, a3 + 16);
  return dword_187168C;
}
