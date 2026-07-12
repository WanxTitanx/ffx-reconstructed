// Function: sub_9BEEF0
// Address: 0x9beef0
__m128 *__stdcall sub_9BEEF0(__m128 *a1, __m128 *a2, __m128 *a3)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm7
  __m128 v9; // xmm6
  __m128 v10; // xmm5
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  __m128 v15; // [esp-20h] [ebp-2Ch]
  __m128 v16; // [esp-10h] [ebp-1Ch]

  v4 = _mm_mul_ps(a3[1], a1[36]);
  v5 = _mm_mul_ps(*a3, a1[37]);
  v15 = _mm_shuffle_ps((__m128)a3[9].m128_u32[1], (__m128)a3[9].m128_u32[1], 0);
  v7 = _mm_mul_ps(a3[1], a2[36]);
  v8 = _mm_mul_ps(a3[2], a2[37]);
  v16 = _mm_shuffle_ps((__m128)a3[6].m128_u32[0], (__m128)a3[6].m128_u32[0], 0);
  v9 = _mm_shuffle_ps((__m128)a3[7].m128_u32[1], (__m128)a3[7].m128_u32[1], 0);
  v10 = _mm_sub_ps(
          _mm_sub_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)a3[8].m128_u32[3], (__m128)a3[8].m128_u32[3], 0),
              _mm_mul_ps(_mm_shuffle_ps((__m128)a3[9].m128_u32[0], (__m128)a3[9].m128_u32[0], 0), v16)),
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v4, v4, 170), _mm_shuffle_ps(v4, v4, 85)),
                  _mm_shuffle_ps(v4, v4, 0)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v5, v5, 170), _mm_shuffle_ps(v5, v5, 85)),
                  _mm_shuffle_ps(v5, v5, 0))),
              v9)),
          _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 170), _mm_shuffle_ps(v8, v8, 85)), _mm_shuffle_ps(v8, v8, 0)),
              _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 170), _mm_shuffle_ps(v7, v7, 85)), _mm_shuffle_ps(v7, v7, 0))),
            v9));
  v11 = _mm_add_ps(v10, v16);
  v12 = _mm_cmplt_ps(v11, v15);
  a3[6] = _mm_or_ps(_mm_andnot_ps(v12, v11), _mm_and_ps(v12, v15));
  v13 = _mm_mul_ps(a2[39], a3[1]);
  v14 = _mm_or_ps(_mm_and_ps(_mm_sub_ps(v15, v16), v12), _mm_andnot_ps(v12, v10));
  a1[36] = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(a1[39], a3[1]), v14), a1[36]);
  a1[37] = _mm_add_ps(_mm_mul_ps(a3[3], v14), a1[37]);
  a2[36] = _mm_sub_ps(a2[36], _mm_mul_ps(v14, v13));
  a2[37] = _mm_add_ps(_mm_mul_ps(a3[4], v14), a2[37]);
  return a2;
}
