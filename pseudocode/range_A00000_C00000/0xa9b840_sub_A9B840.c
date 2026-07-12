// Function: sub_A9B840
// Address: 0xa9b840
// Size: 0x25b
// Prototype: 

void *__fastcall sub_A9B840(_DWORD *a1, int a2)
{
  int v2; // eax
  int v4; // ecx
  void *v5; // esi
  int i; // esi
  float v7; // xmm0_4
  float *v8; // esi
  int n7; // ebx
  int v10; // edi
  double v11; // xmm1_8
  double v12; // xmm0_8
  double v13; // xmm0_8
  void *v14; // edi
  size_t Count; // esi
  void *v16; // edi
  void *result; // eax
  _DWORD *v18; // [esp+14h] [ebp-14h]
  int v19; // [esp+18h] [ebp-10h]
  int n7_1; // [esp+1Ch] [ebp-Ch]
  _DWORD *v21; // [esp+20h] [ebp-8h]
  int v22; // [esp+24h] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 28);
  v4 = *(_DWORD *)(a2 + 4);
  a1[1] = 128;
  a1[2] = 64;
  a1[3] = *(_DWORD *)(v2 + 2932);
  *a1 = v4;
  a1[41] = 128;
  v18 = a1;
  v19 = v4;
  a1[44] = *(_DWORD *)(v2 + 4) / 2;
  v5 = calloc_0(0x80u, 4u);
  memset(v5, 0, 0x200u);
  a1[9] = v5;
  sub_A9D680(a1 + 4, 128);
  for ( i = 0; i < 128; *(float *)(a1[9] + 4 * i - 4) = *(float *)(a1[9] + 4 * i - 4) * *(float *)(a1[9] + 4 * i - 4) )
  {
    libm_sse2_sin_precise();
    v7 = (double)i++ / 127.0 * 3.141592741012573;
    *(float *)(a1[9] + 4 * i - 4) = v7;
  }
  a1[10] = 2;
  a1[11] = 4;
  a1[14] = 4;
  a1[15] = 5;
  a1[18] = 6;
  a1[19] = 6;
  a1[22] = 9;
  a1[23] = 8;
  a1[26] = 13;
  a1[27] = 8;
  a1[30] = 17;
  a1[31] = 8;
  a1[34] = 22;
  a1[35] = 8;
  v8 = (float *)(a1 + 13);
  n7 = 7;
  n7_1 = 7;
  do
  {
    v22 = *((_DWORD *)v8 - 2);
    v21 = malloc_0(4 * v22);
    *((_DWORD *)v8 - 1) = v21;
    v10 = 0;
    if ( v22 > 0 )
    {
      v11 = (double)v22;
      do
      {
        v12 = ((double)v10 + 0.5) / v11 * 3.141592741012573;
        libm_sse2_sin_precise();
        v11 = (double)v22;
        *(float *)&v12 = v12;
        v21[v10++] = LODWORD(v12);
        v21 = (_DWORD *)*((_DWORD *)v8 - 1);
        *v8 = *(float *)&v21[v10 - 1] + *v8;
      }
      while ( v10 < v22 );
      n7 = n7_1;
    }
    v13 = *v8;
    v8 += 4;
    n7_1 = --n7;
    *(v8 - 4) = 1.0 / v13;
  }
  while ( n7 );
  v14 = calloc_0(7 * v19, 0x90u);
  memset(v14, 0, 1008 * v19);
  Count = v18[41];
  v18[38] = v14;
  v16 = calloc_0(Count, 4u);
  result = memset(v16, 0, 4 * Count);
  v18[40] = v16;
  return result;
}

