// Function: sub_A47C60
// Address: 0xa47c60
// Size: 0xe2
// Prototype: 

__int16 __cdecl sub_A47C60(__int16 *a1)
{
  int v2; // ecx
  double v3; // st7
  __int16 result; // ax
  float v5; // [esp+10h] [ebp+8h]
  float v6; // [esp+10h] [ebp+8h]

  v2 = a1[24];
  a1[28] = 18;
  unk_2305830 = v2;
  dword_230582C = a1[25];
  v5 = (float)(v2 + a1[28]);
  unk_2305828 = (int)(v5 / *(float *)(unk_2305834 + 70480));
  v6 = (float)dword_230582C;
  v3 = (v6 + 2.0) / *(float *)(unk_2305834 + 70480);
  unk_2305818 = 16 * ((dword_230582C + 4) / 2);
  dword_2305824 = (int)v3;
  unk_2305814 = 16 * (dword_230582C + 4);
  unk_2305820 = 0;
  unk_230581C = 0;
  n11 = 11;
  n10_0 = 10;
  unk_2305808 = -18;
  unk_2305804 = 0;
  a1[26] = (int)v3 >> 1;
  result = dword_2305824;
  a1[27] = dword_2305824;
  return result;
}

