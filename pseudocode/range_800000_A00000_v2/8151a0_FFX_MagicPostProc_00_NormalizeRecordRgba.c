// Function: FFX_MagicPostProc_00_NormalizeRecordRgba
// Address: 0x8151a0
// Jarvis-HEAVY H06: PostProc 00. Normalizes record RGBA floats from record+0x40..0x4C into record+0x90..0x9C using 1/16 scale. Strong direct color/tint evidence, research-only.
int __cdecl FFX_MagicPostProc_00_NormalizeRecordRgba(int a1, int a2)
{
  float *v2; // ecx
  float v3; // eax

  v2 = *(float **)(a1 + 544);
  unk_C8F934 = unk_C8F53C;
  unk_C8F938 = unk_C8F540;
  unk_C8F93C = unk_C8F544;
  n3_11 = 1031798784;
  flt_C8F930 = 0.0625;
  flt_C8F8E0 = v2[16];
  flt_C8F8E4 = v2[17];
  flt_C8F8E8 = v2[18];
  v3 = v2[19];
  flt_C8F8E0 = flt_C8F8E0 * 0.0625;
  flt_C8F8E4 = flt_C8F8E4 * 0.0625;
  flt_C8F8E8 = flt_C8F8E8 * 0.0625;
  flt_C8F8EC = 0.0625 * v3;
  v2[36] = flt_C8F8E0;
  v2[37] = flt_C8F8E4;
  v2[38] = flt_C8F8E8;
  v2[39] = flt_C8F8EC;
  return a2;
}
