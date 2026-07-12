// Function: sub_A8C44D
// Address: 0xa8c44d
// Size: 0x19c
// Prototype: 

_DWORD *__cdecl sub_A8C44D(const __m128i *a1, int a2, const __m128i *a3, int a4, _DWORD *a5, _DWORD *a6)
{
  __m128i v6; // xmm1
  __m128i v7; // xmm2
  __m128i v8; // xmm7
  __m128i v9; // xmm1
  __m128i v10; // xmm2
  __m128i v11; // xmm7
  __m128i v12; // xmm1
  __int8 *v13; // esi
  __int8 *v14; // edi
  __m128i v15; // xmm2
  __m128i v16; // xmm7
  __m128i v17; // xmm1
  __m128i v18; // xmm2
  __m128i v19; // xmm7
  __m128i v20; // xmm1
  char *v21; // esi
  char *v22; // edi
  __m128i v23; // xmm2
  __m128i v24; // xmm7
  __m128i v25; // xmm1
  __m128i v26; // xmm2
  __m128i v27; // xmm7
  __m128i v28; // xmm1
  __m128i v29; // xmm2
  __m128i v30; // xmm7
  __m128i v31; // xmm2
  __m128i v32; // xmm7
  __m128i v33; // xmm2
  __m128i v34; // xmm7

  v6 = _mm_subs_epi16(
         _mm_unpacklo_epi8(_mm_loadl_epi64(a1), (__m128i)0LL),
         _mm_unpacklo_epi8(_mm_loadl_epi64(a3), (__m128i)0LL));
  v7 = _mm_subs_epi16(
         _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)((char *)a1 + a2)), (__m128i)0LL),
         _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)((char *)a3 + a4)), (__m128i)0LL));
  v8 = _mm_add_epi16(_mm_add_epi16((__m128i)0LL, v6), v7);
  v9 = _mm_add_epi32(_mm_madd_epi16(v6, v6), _mm_madd_epi16(v7, v7));
  v10 = _mm_subs_epi16(
          _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)((char *)a1 + 2 * a2)), (__m128i)0LL),
          _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)((char *)a3 + 2 * a4)), (__m128i)0LL));
  v11 = _mm_add_epi16(v8, v10);
  v12 = _mm_add_epi32(v9, _mm_madd_epi16(v10, v10));
  v13 = &a1->m128i_i8[2 * a2];
  v14 = &a3->m128i_i8[2 * a4];
  v15 = _mm_subs_epi16(
          _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)&v13[a2]), (__m128i)0LL),
          _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)&v14[a4]), (__m128i)0LL));
  v16 = _mm_add_epi16(v11, v15);
  v17 = _mm_add_epi32(v12, _mm_madd_epi16(v15, v15));
  v18 = _mm_subs_epi16(
          _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)&v13[2 * a2]), (__m128i)0LL),
          _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)&v14[2 * a4]), (__m128i)0LL));
  v19 = _mm_add_epi16(v16, v18);
  v20 = _mm_add_epi32(v17, _mm_madd_epi16(v18, v18));
  v21 = &v13[2 * a2];
  v22 = &v14[2 * a4];
  v23 = _mm_subs_epi16(
          _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)&v21[a2]), (__m128i)0LL),
          _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)&v22[a4]), (__m128i)0LL));
  v24 = _mm_add_epi16(v19, v23);
  v25 = _mm_add_epi32(v20, _mm_madd_epi16(v23, v23));
  v26 = _mm_subs_epi16(
          _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)&v21[2 * a2]), (__m128i)0LL),
          _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)&v22[2 * a4]), (__m128i)0LL));
  v27 = _mm_add_epi16(v24, v26);
  v28 = _mm_add_epi32(v25, _mm_madd_epi16(v26, v26));
  v29 = _mm_subs_epi16(
          _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)&v21[2 * a2 + a2]), (__m128i)0LL),
          _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)&v22[2 * a4 + a4]), (__m128i)0LL));
  v30 = _mm_add_epi16(v27, v29);
  v31 = _mm_add_epi32(v28, _mm_madd_epi16(v29, v29));
  v32 = _mm_add_epi16(_mm_unpacklo_epi16(v30, (__m128i)0LL), _mm_unpackhi_epi16(v30, (__m128i)0LL));
  v33 = _mm_add_epi32(_mm_unpacklo_epi32(v31, (__m128i)0LL), _mm_unpackhi_epi32(v31, (__m128i)0LL));
  v34 = _mm_add_epi16(_mm_unpacklo_epi32(v32, (__m128i)0LL), _mm_unpackhi_epi32(v32, (__m128i)0LL));
  *a6 = (__int16)_mm_cvtsi128_si32(_mm_add_epi16(v34, _mm_srli_si128(v34, 8)));
  *a5 = _mm_cvtsi128_si32(_mm_add_epi32(_mm_srli_si128(v33, 8), v33));
  return a6;
}

