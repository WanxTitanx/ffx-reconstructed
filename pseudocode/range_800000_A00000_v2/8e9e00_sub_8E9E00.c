// Function: sub_8E9E00
// Address: 0x8e9e00
_DWORD *__cdecl sub_8E9E00(
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

  *a1 = 32769;
  a1[1] = -2135998464;
  a1[2] = 1128472302;
  a1[3] = 0;
  dword_187168C = a1 + 4;
  sub_8FAA20(0, 1, 0, 1, 128);
  v8 = dword_187168C + 8;
  *dword_187168C = 15;
  *(v8 - 7) = 0;
  *(v8 - 6) = 71;
  *(v8 - 5) = 0;
  *(v8 - 4) = 556875264;
  *(v8 - 3) = 1074123782;
  *(v8 - 2) = 6;
  *(v8 - 1) = 0;
  dword_187168C = v8;
  sub_8FAB80(n128, a6, a7, a8);
  if ( a4 )
  {
    if ( a4 == 1 )
    {
      sub_8FACA0(98, 0);
      sub_8FACF0(a2, a3);
      sub_8FACA0(64, 18);
      sub_8FACF0(a2 + 34, a3 + 18);
    }
    return dword_187168C;
  }
  else
  {
    sub_8FACA0(64, 0);
    sub_8FACF0(a2 - 36, a3);
    sub_8FACA0(98, 18);
    sub_8FACF0(a2 - 2, a3 + 18);
    return dword_187168C;
  }
}
