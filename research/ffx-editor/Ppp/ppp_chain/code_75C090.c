// [STATIC][SOURCE_WITNESS_ONLY] PPP SclMove endpoint candidate: same observed float4 double-layer accumulator shape. COPY IDB only; not RT2/canonical proof.
int *__cdecl FieldMap_AccumulateDoubleLayerDelta_C(int a1, int a2, int a3)
{
  int *result; // eax
  int v4; // ebx
  int v5; // edi
  float *v6; // ecx
  float *v7; // edx

  result = *(int **)(a3 + 12); /*0x75c09e*/
  v4 = *result; /*0x75c0a2*/
  v5 = result[1]; /*0x75c0a8*/
  if ( !unk_230FD34 ) /*0x75c0ab*/
  {
    if ( *(_DWORD *)a2 == *(_DWORD *)(a1 + 12) ) /*0x75c0b9*/
    {
      v6 = (float *)(v5 + a1); /*0x75c0be*/
      *(float *)(v5 + a1 + 160) = *(float *)(a2 + 16) + *(float *)(v5 + a1 + 160); /*0x75c0c8*/
      v6[41] = *(float *)(a2 + 20) + *(float *)(v5 + a1 + 164); /*0x75c0d8*/
      v6[42] = *(float *)(a2 + 24) + *(float *)(v5 + a1 + 168); /*0x75c0e7*/
      v6[43] = *(float *)(a2 + 28) + *(float *)(v5 + a1 + 172); /*0x75c0f6*/
    }
    v7 = (float *)(v4 + a1); /*0x75c103*/
    *(float *)(v4 + a1 + 160) = *(float *)(v5 + a1 + 160) + *(float *)(v4 + a1 + 160); /*0x75c110*/
    v7[41] = *(float *)(v5 + a1 + 164) + *(float *)(v4 + a1 + 164); /*0x75c123*/
    v7[42] = *(float *)(v5 + a1 + 168) + *(float *)(v4 + a1 + 168); /*0x75c135*/
    v7[43] = *(float *)(v5 + a1 + 172) + *(float *)(v4 + a1 + 172); /*0x75c147*/
    return (int *)(v5 + a1); /*0x75c10d*/
  }
  return result; /*0x75c14d*/
}