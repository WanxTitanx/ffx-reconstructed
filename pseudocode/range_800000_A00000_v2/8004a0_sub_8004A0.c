// Function: sub_8004A0
// Address: 0x8004a0
int sub_8004A0()
{
  int n256; // esi
  _WORD *v1; // ebx

  *((_DWORD *)off_C88A90 + 20) = off_C48D88;
  n256 = 0;
  v1 = dword_12EA030;
  memset(buf, 0, sizeof(buf));
  do
  {
    memset(v1, 0, 0x80u);
    v1[15] = n256++;
    v1 += 64;
  }
  while ( n256 < 256 );
  FFX_MagicHost_AttachPppResourceBuffer(dword_12F2030, 0, (int)&unk_2343520, 0x80000);
  return 0;
}
