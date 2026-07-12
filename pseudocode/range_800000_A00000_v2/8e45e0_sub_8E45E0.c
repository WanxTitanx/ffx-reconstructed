// Function: sub_8E45E0
// Address: 0x8e45e0
int __cdecl sub_8E45E0(int a1, int a2, int a3, int a4)
{
  int v4; // esi

  v4 = sub_8AA150();
  unk_23CC12C = v4;
  *(_WORD *)(v4 + 48) = 2;
  *(_WORD *)(v4 + 58) = 2;
  *(_WORD *)(v4 + 72) = 1;
  *(_BYTE *)(v4 + 66) = 1;
  *(_BYTE *)(v4 + 62) = (a2 == 0) + 2;
  *(_DWORD *)(v4 + 36) = a1;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 12) = sub_8E3730;
  *(_DWORD *)(v4 + 16) = sub_8E3BC0;
  *(_DWORD *)(v4 + 20) = sub_8E4A50;
  *(_DWORD *)(v4 + 28) = 0;
  *(_DWORD *)(v4 + 92) = a3;
  *(_DWORD *)(v4 + 88) = a2;
  *(_DWORD *)(v4 + 96) = a4;
  sub_8AAAB0(v4);
  return v4;
}
