// Function: sub_9402C0
// Address: 0x9402c0
int sub_9402C0()
{
  double v0; // st7
  float v2; // [esp+0h] [ebp-Ch]

  unk_193C380 = unk_193C380 + unk_193C384;
  if ( unk_193C380 < 1.0 )
  {
    v0 = unk_193C380;
  }
  else
  {
    unk_193C380 = 1.0;
    v0 = (float)1.0;
  }
  *(_DWORD *)(dword_25D5F54[unk_25D5F90] - 16) = dword_25D5F4C[unk_25D5F90];
  *(_DWORD *)(dword_25D5F54[unk_25D5F90] - 12) = 0;
  v2 = v0;
  *(_DWORD *)(dword_25D5F54[unk_25D5F90] - 8) = 0;
  *(_DWORD *)(dword_25D5F54[unk_25D5F90] - 4) = 0;
  return sub_7BFC20(SLODWORD(flt_25D5EE0), 1, dword_25D5F54[unk_25D5F90] - 16, v2, 0.0, 0);
}
