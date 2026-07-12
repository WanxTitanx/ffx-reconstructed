// Function: sub_9880E0
// Address: 0x9880e0
void *__usercall sub_9880E0@<eax>(int a1@<ebp>, void *dst_1, int a3)
{
  const void **p_src; // edx
  int v4; // esi
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 **v7; // edx
  int v8; // esi
  __m128 *v9; // eax
  _OWORD dst[2]; // [esp-30h] [ebp-3Ch] BYREF
  int v12; // [esp+0h] [ebp-Ch]
  void *v13; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v12 = a1;
  v13 = retaddr;
  p_src = *(const void ***)(a3 + 12);
  qmemcpy(dst, *p_src, sizeof(dst));
  v4 = *(_DWORD *)(a3 + 4);
  if ( v4 > 1 )
  {
    v5 = (__m128)dst[1];
    v6 = (__m128)dst[0];
    v7 = (__m128 **)(p_src + 1);
    v8 = v4 - 1;
    do
    {
      v9 = *v7++;
      v5 = _mm_max_ps(v5, v9[1]);
      v6 = _mm_min_ps(v6, *v9);
      dst[1] = v5;
      dst[0] = v6;
      --v8;
    }
    while ( v8 );
  }
  qmemcpy(dst_1, dst, 0x20u);
  return dst_1;
}
