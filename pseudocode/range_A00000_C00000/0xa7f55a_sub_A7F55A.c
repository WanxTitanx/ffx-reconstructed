// Function: sub_A7F55A
// Address: 0xa7f55a
// Size: 0x1a0
// Prototype: 

int __cdecl sub_A7F55A(__m64 *a1, int a2, int a3, unsigned int a4, __int32 a5)
{
  unsigned int v5; // ecx
  __m64 v6; // mm1
  __m64 v7; // mm1
  int n6; // edi
  unsigned int v9; // edx
  __m64 v10; // mm1
  __m64 v11; // mm1
  int v12; // eax
  __m128i v13; // xmm7
  __m128i v14; // xmm6
  unsigned int v15; // ecx
  __m64 v16; // mm0
  __m64 v17; // mm1
  __m128i v18; // xmm1
  __m128i v19; // xmm2
  __m128i v20; // xmm1
  __m128i v21; // xmm6
  __m128i v22; // xmm7
  __m128i v23; // xmm1
  __m128i v24; // xmm2
  __m128i v25; // xmm7
  __m128i v26; // xmm6
  __m128i v27; // xmm5
  __m128i v28; // xmm1
  int result; // eax
  __m128i v30; // [esp+0h] [ebp-28h]

  v30.m128i_i32[0] = a5;
  v30.m128i_i32[1] = a5;
  v30.m128i_i32[2] = a5;
  v30.m128i_i32[3] = a5;
  do
  {
    v5 = 0;
    v6 = _m_punpcklbw((__m64)a1->m64_u64, (__m64)a1->m64_u64);
    v7 = _m_punpcklwd(v6, v6);
    n6 = -8;
    a1[-1].m64_u64 = (unsigned __int64)_m_punpckldq(v7, v7);
    v9 = a4;
    v10 = _m_punpcklbw(*(__m64 *)((char *)a1 + a4 - 1), *(__m64 *)((char *)a1 + a4 - 1));
    v11 = _m_punpcklwd(v10, v10);
    *(__m64 *)((char *)a1 + a4) = _m_punpckldq(v11, v11);
    do
    {
      v12 = a1->m64_u8[n6];
      v5 += v12;
      v9 += (unsigned __int16)((unsigned __int8)v12 * (unsigned __int8)v12);
      ++n6;
    }
    while ( n6 <= 6 );
    v13 = _mm_cvtsi32_si128(v9);
    v14 = _mm_cvtsi32_si128(v5);
    v15 = 0;
    v16.m64_u64 = 0;
    v17.m64_u64 = 0;
    do
    {
      v18 = _mm_unpacklo_epi16(
              _mm_unpacklo_epi8(_mm_cvtsi32_si128(a1[-1].m64_u32[v15 / 4]), (__m128i)0LL),
              (__m128i)0LL);
      v19 = _mm_sub_epi32(
              _mm_unpacklo_epi16(
                _mm_unpacklo_epi8(
                  _mm_cvtsi32_si128(*(unsigned __int32 *)((char *)&a1->m64_u32[v15 / 4 + 1] + 3)),
                  (__m128i)0LL),
                (__m128i)0LL),
              v18);
      v20 = _mm_madd_epi16(_mm_add_epi32(_mm_add_epi32(v18, v18), v19), v19);
      v21 = _mm_shuffle_epi32(_mm_add_epi32(v14, v19), 0);
      v22 = _mm_shuffle_epi32(_mm_add_epi32(v13, v20), 0);
      v23 = _mm_srli_si128(v20, 4);
      v24 = _mm_srli_si128(v19, 4);
      v25 = _mm_add_epi32(
              _mm_add_epi32(_mm_add_epi32(v22, _mm_shuffle_epi32(v23, 3)), _mm_shuffle_epi32(v23, 95)),
              _mm_shuffle_epi32(v23, 191));
      v26 = _mm_add_epi32(
              _mm_add_epi32(_mm_add_epi32(v21, _mm_shuffle_epi32(v24, 3)), _mm_shuffle_epi32(v24, 95)),
              _mm_shuffle_epi32(v24, 191));
      v27 = _mm_packs_epi16(
              _mm_packs_epi32(
                _mm_srai_epi32(
                  _mm_sub_epi32(
                    _mm_sub_epi32(_mm_sub_epi32(_mm_slli_epi32(v25, 4u), v25), _mm_madd_epi16(v26, v26)),
                    v30),
                  0x1Fu),
                (__m128i)0LL),
              (__m128i)0LL);
      v28 = _mm_cvtsi32_si128(a1->m64_u32[v15 / 4]);
      a1[-1].m64_i32[v15 / 4] = _mm_cvtsi64_si32(v16);
      v16 = v17;
      v17 = _mm_movepi64_pi64(
              _mm_or_si128(
                _mm_andnot_si128(v27, _mm_move_epi64(v28)),
                _mm_and_si128(
                  _mm_packus_epi16(
                    _mm_packs_epi32(
                      _mm_srai_epi32(
                        _mm_add_epi32(
                          _mm_add_epi32(_mm_unpacklo_epi16(_mm_unpacklo_epi8(v28, (__m128i)0LL), (__m128i)0LL), v26),
                          (__m128i)xmmword_25D73B0),
                        4u),
                      (__m128i)0LL),
                    (__m128i)0LL),
                  v27)));
      v13 = _mm_srli_si128(v25, 12);
      v14 = _mm_srli_si128(v26, 12);
      v15 += 4;
    }
    while ( (int)v15 < (int)(a4 + 8) );
    result = a2;
    a1 = (__m64 *)((char *)a1 + a2);
    --a3;
  }
  while ( a3 > 0 );
  return result;
}

