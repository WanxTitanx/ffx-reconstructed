// Function: sub_940580
// Address: 0x940580
int sub_940580()
{
  int v0; // ecx
  float *v1; // eax
  double v2; // st7
  float v4; // [esp+0h] [ebp-34h]
  float v5; // [esp+0h] [ebp-34h]
  int v6; // [esp+4h] [ebp-30h]
  float v7; // [esp+4h] [ebp-30h]
  float v8; // [esp+8h] [ebp-2Ch]
  float v9; // [esp+8h] [ebp-2Ch]
  float v10; // [esp+Ch] [ebp-28h]
  float v11; // [esp+Ch] [ebp-28h]
  float v12[4]; // [esp+10h] [ebp-24h] BYREF
  float v13[4]; // [esp+20h] [ebp-14h] BYREF

  v8 = 0.0;
  v0 = dword_25D5F4C[unk_25D5F90];
  v10 = 0.0;
  v1 = (float *)dword_25D5F54[unk_25D5F90];
  v4 = 0.0;
  v6 = v0;
  if ( v0 > 0 )
  {
    do
    {
      v2 = *v1;
      v1 += 4;
      v4 = v2 + v4;
      v10 = *(v1 - 3) + v10;
      v8 = *(v1 - 2) + v8;
      --v0;
    }
    while ( v0 );
  }
  v7 = (float)v6;
  v5 = v4 / v7;
  v11 = v10 / v7;
  v9 = v8 / v7;
  v13[0] = v5;
  v12[0] = v5;
  v13[2] = v9;
  v12[2] = v9;
  v12[1] = v11;
  v13[1] = v11 + 400.0;
  FFX_BtlPool_WriteEntryTransform(SLODWORD(flt_25D5EE0), 0, (int)v12);
  return FFX_BtlPool_WriteEntryTransform(SLODWORD(flt_25D5EE0), 1, (int)v13);
}
