// Function: sub_989780
// Address: 0x989780
__m128 *__usercall sub_989780@<eax>(int a1@<ebp>, int *this, _DWORD *dst)
{
  int v4; // edx
  __m128 *src; // esi
  BOOL v6; // ecx
  int v7; // ecx
  __m128 *src_2; // esi
  __m128 *v9; // eax
  __m128 *v10; // ecx
  __m128 v11; // xmm2
  float dst_1[8]; // [esp-30h] [ebp-3Ch] BYREF
  int v13; // [esp-8h] [ebp-14h]
  __m128 *src_1; // [esp-4h] [ebp-10h]
  int v15; // [esp+0h] [ebp-Ch]
  void *v16; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v15 = a1;
  v16 = retaddr;
  if ( dst == (_DWORD *)*this )
  {
    *this = 0;
    return 0;
  }
  else
  {
    v4 = dst[8];
    src = *(__m128 **)(v4 + 32);
    v6 = *(_DWORD *)(v4 + 40) == (_DWORD)dst;
    v13 = v4;
    src_1 = src;
    v7 = *(_DWORD *)(v4 + 4 * (10 - v6));
    if ( src )
    {
      src[2].m128_i32[(src[2].m128_i32[2] == v4) + 1] = v7;
      *(_DWORD *)(v7 + 32) = src;
      sub_9D4D50(*(this + 1));
      *(this + 1) = v13;
      while ( 1 )
      {
        qmemcpy(dst_1, src, sizeof(dst_1));
        src_2 = src_1;
        v9 = (__m128 *)src_1[2].m128_i32[1];
        v10 = (__m128 *)src_1[2].m128_i32[2];
        v11 = _mm_max_ps(v9[1], v10[1]);
        *src_1 = _mm_min_ps(*v9, *v10);
        src_2[1] = v11;
        if ( dst_1[0] == src_2->m128_f32[0]
          && dst_1[1] == src_2->m128_f32[1]
          && dst_1[2] == src_2->m128_f32[2]
          && dst_1[4] == src_2[1].m128_f32[0]
          && dst_1[5] == src_2[1].m128_f32[1]
          && dst_1[6] == src_2[1].m128_f32[2] )
        {
          break;
        }
        src = (__m128 *)src_2[2].m128_i32[0];
        src_1 = src;
        if ( !src )
          return (__m128 *)*this;
      }
      return src_2;
    }
    else
    {
      *this = v7;
      *(_DWORD *)(v7 + 32) = 0;
      sub_9D4D50(*(this + 1));
      *(this + 1) = v13;
      return (__m128 *)*this;
    }
  }
}
