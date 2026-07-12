// Function: sub_8FC6A0
// Address: 0x8fc6a0
_DWORD *__cdecl sub_8FC6A0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _DWORD *v8; // eax

  v8 = dword_187168C;
  *dword_187168C = 32769;
  v8[1] = 1073954816;
  v8[2] = 17438;
  v8[3] = 0;
  dword_187168C = v8 + 4;
  sub_8FABE0(1, 1, 0, 0, 0, 0, 0, 0);
  sub_8FAB80(a5, a6, a7, a8);
  sub_8FACF0(a1, a2);
  sub_8FACF0(a1 + a3, a2 + a4);
  return sub_8F3A30();
}
