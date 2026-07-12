// Function: sub_A691C0
// Address: 0xa691c0
// Size: 0xc4

int __cdecl sub_A691C0(int a1, int a2)
{
  int v2; // eax
  int n2; // ecx
  double v4; // st7

  sub_836240(0, a2); /*0xa691ca*/
  sub_836240(1, a2 + 16); /*0xa691d5*/
  sub_836240(2, a2 + 32); /*0xa691e0*/
  *(_DWORD *)(a2 + 48) = unk_C8F508[0]; /*0xa691ea*/
  *(float *)(a2 + 52) = flt_C8F50C; /*0xa691f2*/
  *(float *)(a2 + 56) = flt_C8F510; /*0xa691fa*/
  *(float *)(a2 + 60) = flt_C8F514[0]; /*0xa69202*/
  v2 = a2 + 8; /*0xa69208*/
  n2 = 2; /*0xa6920b*/
  do /*0xa69244*/
  {
    v4 = *(float *)(v2 - 8); /*0xa69210*/
    v2 += 24; /*0xa69213*/
    *(float *)(v2 - 32) = -v4; /*0xa69218*/
    *(float *)(v2 - 28) = -*(float *)(v2 - 28); /*0xa69220*/
    *(float *)(v2 - 24) = -*(float *)(v2 - 24); /*0xa69228*/
    *(float *)(v2 - 20) = -*(float *)(v2 - 20); /*0xa69230*/
    *(float *)(v2 - 16) = -*(float *)(v2 - 16); /*0xa69238*/
    *(float *)(v2 - 12) = -*(float *)(v2 - 12); /*0xa69240*/
    --n2; /*0xa69243*/
  }
  while ( n2 ); /*0xa69244*/
  *(float *)(a2 + 44) = 1.0; /*0xa69248*/
... [1261 chars total]