// Function: sub_80B5C0
// Address: 0x80b5c0
int __cdecl sub_80B5C0(int a1, int a2)
{
  int v2; // edx
  int v3; // eax
  float *v4; // esi
  __int16 *v5; // edx

  if ( (*(_WORD *)(a1 + 538) & 0xF00) != 0 )
    return a2;
  FFX_MagicCoreOp_32_LoadedByOPURecordSpawn(a1, a2);
  v2 = *(__int16 *)(a2 + 4);
  v3 = *(__int16 *)(v2 + a2);
  v4 = *(float **)a1;
  v5 = (__int16 *)(a2 + v2);
  v4[12] = (float)v3;
  v4[13] = (float)v5[1];
  v4[14] = (float)v5[2];
  v4[15] = (float)v5[3];
  v4[16] = (float)v5[4];
  v4[17] = (float)v5[5];
  v4[18] = (float)v5[6];
  v4[19] = (float)v5[7];
  return a2 + 6;
}
