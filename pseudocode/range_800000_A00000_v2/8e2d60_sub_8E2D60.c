// Function: sub_8E2D60
// Address: 0x8e2d60
int sub_8E2D60()
{
  int v0; // esi

  v0 = sub_8AA150();
  *(_DWORD *)(v0 + 8) = nullsub_156;
  *(_DWORD *)(v0 + 12) = sub_8E2B30;
  *(_DWORD *)(v0 + 16) = sub_8E2B60;
  *(_DWORD *)(v0 + 20) = 0;
  *(_DWORD *)(v0 + 28) = 0;
  *(_BYTE *)(v0 + 62) = 7;
  unk_1871658 = v0;
  *(_DWORD *)(v0 + 88) = 128;
  *(_DWORD *)(v0 + 92) = 128;
  *(_DWORD *)(v0 + 96) = 128;
  *(_DWORD *)(v0 + 100) = 0;
  *(_DWORD *)(v0 + 104) = 6;
  sub_8AAAB0(v0);
  return v0;
}
