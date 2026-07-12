// Function: sub_814DF0
// Address: 0x814df0
int __cdecl sub_814DF0(int a1, int a2)
{
  int v2; // edi
  float *v3; // esi
  int v4; // eax

  v2 = *(_DWORD *)(a1 + 544);
  v3 = (float *)sub_800F80((_DWORD *)(a1 + 768), v2, *(_WORD *)(v2 + 160));
  v4 = ((int)*(float *)(v2 + 72) & 0xFFF) + 1024;
  *(float *)(v2 + 144) = flt_C43BE0[v4] * *(float *)(v2 + 64) * 0.0625 + v3[36];
  *(float *)(v2 + 152) = flt_C44BE0[v4 & 0xFFF] * *(float *)(v2 + 64) * 0.0625 + v3[38];
  *(float *)(v2 + 148) = 0.0625 * *(float *)(v2 + 68) + v3[37];
  return a2;
}
