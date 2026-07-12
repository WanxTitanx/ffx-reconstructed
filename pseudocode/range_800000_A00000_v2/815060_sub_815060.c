// Function: sub_815060
// Address: 0x815060
int __cdecl sub_815060(int a1, int a2)
{
  int v2; // edi
  int v3; // esi
  int v4; // eax

  v2 = *(_DWORD *)(a1 + 544);
  v3 = sub_800F80((_DWORD *)(a1 + 768), v2, *(_WORD *)(v2 + 160));
  v4 = ((int)*(float *)(v2 + 72) & 0xFFF) + 1024;
  *(float *)(v2 + 144) = flt_C43BE0[v4] * *(float *)(v2 + 64) * 0.0625 + *(float *)(v3 + 144);
  *(float *)(v2 + 152) = flt_C44BE0[v4 & 0xFFF] * *(float *)(v2 + 64) * 0.0625 + *(float *)(v3 + 152);
  *(float *)(v2 + 148) = 0.0625 * *(float *)(v2 + 68);
  return a2;
}
