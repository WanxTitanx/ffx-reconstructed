// Function: sub_940380
// Address: 0x940380
int sub_940380()
{
  double v0; // st7
  float v2; // [esp+0h] [ebp-28h]
  int v3[4]; // [esp+4h] [ebp-24h] BYREF
  int v4; // [esp+14h] [ebp-14h] BYREF
  float v5; // [esp+18h] [ebp-10h]
  float v6; // [esp+1Ch] [ebp-Ch]
  float v7; // [esp+20h] [ebp-8h]

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
  unk_25D5F31 = 0;
  v2 = v0;
  sub_88A410((int)v3, dword_25D5F54[unk_25D5F90], dword_25D5F4C[unk_25D5F90], v2);
  sub_88B320((int)&v4, dword_25D5F54[unk_25D5F90], dword_25D5F4C[unk_25D5F90], unk_193C380);
  *(float *)&v4 = *(float *)&v4 + *(float *)v3;
  v5 = v5 + *(float *)&v3[1];
  v6 = v6 + *(float *)&v3[2];
  v7 = 1.0;
  FFX_BtlPool_SetPositionParameter(SLODWORD(flt_25D5EE0), *(float *)&v3[3]);
  FFX_BtlPool_WriteEntryTransform(SLODWORD(flt_25D5EE0), 0, (int)&v4);
  return FFX_BtlPool_WriteEntryTransform(SLODWORD(flt_25D5EE0), 1, (int)v3);
}
