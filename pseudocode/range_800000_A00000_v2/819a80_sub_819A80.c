// Function: sub_819A80
// Address: 0x819a80
int __cdecl sub_819A80(int a1, int a2)
{
  float *v2; // esi
  int v3; // eax
  __int16 v4; // bx
  int v5; // edx
  int v6; // ecx
  int result; // eax

  v2 = *(float **)(a1 + 544);
  v3 = sub_800F80((_DWORD *)(a1 + 768), (int)v2, *(_WORD *)(a2 + 4));
  v4 = *(_WORD *)(a2 + 2);
  v5 = v3;
  v6 = (__int16)(16 * (v4 & 7));
  if ( (v4 & 0x1000) != 0 )
    *(float *)((char *)v2 + v6 + 48) = *(float *)(v6 + v3 + 48);
  if ( (v4 & 0x2000) != 0 )
    *(float *)((char *)v2 + v6 + 52) = *(float *)(v6 + v3 + 52);
  if ( (v4 & 0x4000) != 0 )
    *(float *)((char *)v2 + v6 + 56) = *(float *)(v6 + v3 + 56);
  if ( v4 < 0 )
    *(float *)((char *)v2 + v6 + 60) = *(float *)(v6 + v3 + 60);
  if ( (v4 & 0x10) == 0 )
    return a2 + 6;
  if ( (v4 & 0x1000) != 0 )
    v2[36] = *(float *)(v3 + 144);
  if ( (v4 & 0x2000) != 0 )
    v2[37] = *(float *)(v3 + 148);
  result = a2 + 6;
  if ( (v4 & 0x4000) != 0 )
    v2[38] = *(float *)(v5 + 152);
  return result;
}
