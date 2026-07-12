// Function: sub_818F00
// Address: 0x818f00
int __cdecl sub_818F00(int a1, int a2)
{
  int v3; // edi
  unsigned __int16 *v4; // esi
  int v5; // eax
  float *v7; // [esp+4h] [ebp-4h]
  float v8; // [esp+10h] [ebp+8h]
  float v9; // [esp+10h] [ebp+8h]
  int v10; // [esp+14h] [ebp+Ch]

  v7 = *(float **)(a1 + 544);
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
    return a2;
  v3 = a1 + 128;
  v4 = (unsigned __int16 *)sub_800F80((_DWORD *)(a1 + 768), *(_DWORD *)(a1 + 544), *(_WORD *)(a2 + 2));
  sub_7EA5E0((void *)(a1 + 128));
  sub_7EA460(v3, v3, v4 + 72);
  v5 = sub_801E20((_DWORD *)a1, v4);
  sub_7E82C0(v3, v5, v3);
  sub_7E82C0(a1 + 192, a1 + 704, a1 + 128);
  *(_DWORD *)a1 = word_C8F508[0];
  *(float *)(a1 + 4) = word_C8F50C;
  *(float *)(a1 + 8) = word_C8F510;
  *(float *)(a1 + 12) = word_C8F514[0];
  sub_7E9A60(a1, a1 + 192, a1);
  v10 = (*(_DWORD *)(a1 + 4) - 0x8000) >> 4;
  v8 = (float)((*(_DWORD *)a1 - 0x8000) >> 4);
  v7[36] = v8 * v7[16] * 0.00390625;
  v9 = (float)v10;
  v7[37] = 0.00390625 * (v9 * v7[16]);
  return a2 + 4;
}
