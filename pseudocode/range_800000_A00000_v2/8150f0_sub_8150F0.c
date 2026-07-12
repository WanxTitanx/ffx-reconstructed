// Function: sub_8150F0
// Address: 0x8150f0
int __cdecl sub_8150F0(int a1, int a2)
{
  int v2; // esi
  char v3; // al
  double v4; // st7
  int v5; // eax
  float v7; // [esp+4h] [ebp-8h]
  float v8; // [esp+14h] [ebp+8h]

  v2 = *(_DWORD *)(a1 + 544);
  v3 = *(_BYTE *)(v2 + 162);
  v7 = *(float *)(*(char *)(v2 + 161) + v2);
  if ( v3 )
    v4 = *(float *)(v3 + v2);
  else
    v4 = 0.0;
  v8 = v4;
  v5 = ((int)*(float *)(*(char *)(v2 + 160) + v2) & 0xFFF) + 1024;
  *(float *)(v2 + 148) = (flt_C43BE0[v5] * v7 + *(float *)(v2 + 68)) * 0.0625;
  *(float *)(v2 + 144) = (v7 * flt_C44BE0[v5 & 0xFFF] + *(float *)(v2 + 64)) * 0.0625;
  *(float *)(v2 + 152) = 0.0625 * (*(float *)(v2 + 72) + v8);
  return a2;
}
