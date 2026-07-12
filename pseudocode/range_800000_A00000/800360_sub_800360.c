// Function: sub_800360
// Address: 0x800360
// Size: 0xef

int sub_800360()
{
  _DWORD *v0; // ecx
  int v1; // eax

  v0 = unk_23C3540;
  v1 = 0;
  do
  {
    *v0 = 0;
    v0[32] = 0;
    ++v0;
    *(_DWORD *)((char *)&unk_23C37A4 + v1) = 0;
    *(_DWORD *)((char *)&unk_23C37A0 + v1) = 0;
    *(_DWORD *)((char *)&unk_23C36A4 + v1) = 0;
    *(_DWORD *)((char *)&unk_23C36A0 + v1) = 0;
    v1 += 8;
  }
  while ( (int)v0 < (int)dword_23C35C0 );
  unk_23C3660 = 32.0;
  *(_DWORD *)unk_23C3640 = 0;
  unk_23C364C = 0;
  unk_23C3664 = 512.0;
  dword_23C3648[0] = 0;
  n3_8 = 0;
  unk_23C3668 = 127.0;
  unk_23C366C = 96.0;
  unk_23C3670 = 64.0;
  unk_23C3674 = 768.0;
  unk_23C3678 = 96.0;
  unk_23C367C = 32.0;
  unk_23C3688 = 64.0;
  unk_23C3684 = -0.064583331;
  unk_23C3680 = 129.06667;
  unk_23C368C = 0.041666668;
  return 0;
}
