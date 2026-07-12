// Function: sub_A5E7B0
// Address: 0xa5e7b0
// Size: 0xc6
// Prototype: 

int __cdecl sub_A5E7B0(_DWORD *a1, int a2, int a3)
{
  int v3; // ecx
  int v4; // esi
  unsigned int v5; // ecx

  v3 = unk_228615C;
  if ( !unk_228615C )
    v3 = a3;
  if ( v3 == -1 )
    LOBYTE(v3) = unk_22881D4;
  v4 = word_C87880 + 4 * (v3 & 3);
  *a1 = 1;
  a1[1] = 0x20000000;
  a1[2] = 30;
  a1[3] = 0;
  v5 = word_C87870 | 0x99404000;
  a1[5] = ((unsigned __int64)word_C87870 >> 32) | (32 * v4) | 0x20000005;
  a1[12] = a2 | 0x8000;
  a1[4] = v5;
  a1[6] = 6;
  a1[7] = 0;
  a1[10] = 128;
  a1[11] = 128;
  a1[8] = 128;
  a1[9] = 128;
  a1[13] = (a2 >> 31) | 0x408B4000;
  a1[14] = 17219;
  a1[15] = 0;
  return 64;
}

