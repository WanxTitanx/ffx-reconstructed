// Function: sub_988D30
// Address: 0x988d30
__m128 *__cdecl sub_988D30(int *this, __int32 a2, __m128 *dst)
{
  int *this_1; // ecx
  __m128 *dst_1; // eax
  __int32 v5; // edi
  __m128 v6; // xmm4
  __m128 v7; // xmm2
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 *v11; // edx
  __int32 v12; // esi
  int v13; // eax
  __m128 v14; // xmm2
  __m128 *v15; // ecx
  __m128 v16; // xmm2

  this_1 = this;
  if ( *this )
  {
    v5 = a2;
    if ( *(_DWORD *)(a2 + 40) )
    {
      v6 = _mm_add_ps(dst[1], *dst);
      do
      {
        v7 = _mm_and_ps(
               _mm_sub_ps(_mm_add_ps(*(__m128 *)(*(_DWORD *)(v5 + 36) + 16), *(__m128 *)*(_DWORD *)(v5 + 36)), v6),
               (__m128)xmmword_B6F9E0);
        v8 = _mm_add_ps(_mm_movehl_ps(v7, v7), v7);
        v9 = _mm_and_ps(
               _mm_sub_ps(_mm_add_ps(*(__m128 *)(*(_DWORD *)(v5 + 40) + 16), *(__m128 *)*(_DWORD *)(v5 + 40)), v6),
               (__m128)xmmword_B6F9E0);
        v10 = _mm_add_ps(_mm_movehl_ps(v9, v9), v9);
        v10.m128_f32[0] = v10.m128_f32[0] + _mm_shuffle_ps(v10, v10, 1).m128_f32[0];
        v8.m128_f32[0] = v8.m128_f32[0] + _mm_shuffle_ps(v8, v8, 1).m128_f32[0];
        v5 = *(_DWORD *)(v5 + 4 * (_mm_cmple_ss(v10, v8).m128_u32[0] & 1) + 36);
      }
      while ( *(_DWORD *)(v5 + 40) );
      this_1 = this;
    }
    v11 = (__m128 *)this_1[1];
    v12 = *(_DWORD *)(v5 + 32);
    if ( v11 )
    {
      this_1[1] = 0;
    }
    else
    {
      v13 = sub_9D4CE0(48, 16);
      this_1 = this;
      v11 = (__m128 *)v13;
    }
    dst_1 = dst;
    v11[2].m128_i32[0] = v12;
    v11[2].m128_i32[1] = 0;
    v11[2].m128_i32[2] = 0;
    v14 = _mm_max_ps(dst[1], *(__m128 *)(v5 + 16));
    *v11 = _mm_min_ps(*dst, *(__m128 *)v5);
    v11[1] = v14;
    if ( v12 )
    {
      dst_1 = dst;
      *(_DWORD *)(v12 + 4 * (*(_DWORD *)(*(_DWORD *)(v5 + 32) + 40) == v5) + 36) = v11;
      v11[2].m128_i32[1] = v5;
      *(_DWORD *)(v5 + 32) = v11;
      v11[2].m128_i32[2] = (__int32)dst;
      dst[2].m128_i32[0] = (__int32)v11;
      do
      {
        if ( v11->m128_f32[0] >= (double)*(float *)v12
          && v11->m128_f32[1] >= (double)*(float *)(v12 + 4)
          && v11->m128_f32[2] >= (double)*(float *)(v12 + 8)
          && *(float *)(v12 + 16) >= (double)v11[1].m128_f32[0]
          && *(float *)(v12 + 20) >= (double)v11[1].m128_f32[1]
          && *(float *)(v12 + 24) >= (double)v11[1].m128_f32[2] )
        {
          break;
        }
        v15 = *(__m128 **)(v12 + 36);
        dst_1 = *(__m128 **)(v12 + 40);
        v16 = _mm_max_ps(v15[1], dst_1[1]);
        *(__m128 *)v12 = _mm_min_ps(*v15, *dst_1);
        *(__m128 *)(v12 + 16) = v16;
        v11 = (__m128 *)v12;
        v12 = *(_DWORD *)(v12 + 32);
      }
      while ( v12 );
    }
    else
    {
      v11[2].m128_i32[1] = v5;
      *(_DWORD *)(v5 + 32) = v11;
      v11[2].m128_i32[2] = (__int32)dst;
      dst[2].m128_i32[0] = (__int32)v11;
      *this_1 = (int)v11;
    }
  }
  else
  {
    *this = (int)dst;
    dst[2].m128_i32[0] = 0;
    return dst;
  }
  return dst_1;
}
