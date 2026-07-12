// Function: sub_8FDE50
// Address: 0x8fde50
_DWORD *__cdecl sub_8FDE50(int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // eax

  v4 = dword_187168C;
  *dword_187168C = 32769;
  v4[1] = 1889943552;
  v4[2] = 71386142;
  v4[3] = 0;
  dword_187168C = v4 + 4;
  sub_8FAA20(0, 1, 0, 1, 128);
  sub_8FAB80(16, 16, 112, 88);
  sub_8FACF0(a1, a2);
  sub_8FACF0(a3, a2);
  sub_8FAB80(80, 80, 80, 96);
  sub_8FACF0(a1, a4);
  sub_8FACF0(a3, a4);
  return sub_8F3A30();
}
