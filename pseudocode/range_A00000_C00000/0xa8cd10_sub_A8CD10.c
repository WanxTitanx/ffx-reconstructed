// Function: sub_A8CD10
// Address: 0xa8cd10
// Size: 0x346
// Prototype: 

__m128i *__cdecl sub_A8CD10(int a1, __m128i *a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8, _DWORD *a9)
{
  __m128i v9; // xmm6
  __m128i v10; // xmm7
  __m128i *result; // eax
  __m128i *v12; // edx
  int v13; // edi
  int v14; // ecx
  __m128i v15; // xmm1
  __m128i v16; // xmm2
  __m128i v17; // xmm0
  __int8 *v18; // esi
  __m128i v19; // xmm2
  __m128i v20; // xmm3
  __m128i v21; // xmm1
  __m128i v22; // xmm2
  __m128i v23; // xmm3
  __m128i v24; // xmm2
  __m128i v25; // xmm3
  __m128i *v26; // edx
  int v27; // edi
  int v28; // ecx
  __m128i v29; // xmm1
  const __m128i *v30; // esi
  __m128i v31; // xmm2
  __m128i v32; // xmm0
  __m128i v33; // xmm1
  __m128i v34; // xmm2
  int v35; // esi
  int v36; // edi
  int v37; // ecx
  __m128i v38; // xmm1
  __m128i v39; // xmm2
  int v40; // esi
  int v41; // edi
  int v42; // ecx
  __m128i v43; // xmm2
  __m128i v44; // xmm3
  __m128i v45; // xmm1
  __m128i v46; // xmm3
  __m128i v47; // xmm1
  __m128i v48; // xmm6
  __m128i v49; // xmm0

  v9 = 0;
  v10 = 0;
  if ( a6 )
  {
    result = (__m128i *)((char *)&unk_25D7950 + 16 * a6);
    if ( a7 )
    {
      v12 = (__m128i *)((char *)&unk_25D7950 + 16 * a7);
      v13 = a3;
      v14 = a5;
      v15 = _mm_loadu_si128((const __m128i *)(a1 + 1));
      v16 = _mm_loadu_si128((const __m128i *)a1);
      v17 = _mm_packus_epi16(
              _mm_srai_epi16(
                _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v16, v15), *result), (__m128i)xmmword_25D7940),
                7u),
              _mm_srai_epi16(
                _mm_add_epi16(_mm_maddubs_epi16(_mm_unpackhi_epi8(v16, v15), *result), (__m128i)xmmword_25D7940),
                7u));
      v18 = &a2->m128i_i8[a1];
      do
      {
        v19 = _mm_loadu_si128((const __m128i *)(v18 + 1));
        v20 = _mm_loadu_si128((const __m128i *)v18);
        v21 = _mm_packus_epi16(
                _mm_srai_epi16(
                  _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v20, v19), *result), (__m128i)xmmword_25D7940),
                  7u),
                _mm_srai_epi16(
                  _mm_add_epi16(_mm_maddubs_epi16(_mm_unpackhi_epi8(v20, v19), *result), (__m128i)xmmword_25D7940),
                  7u));
        v22 = v17;
        v17 = v21;
        v23 = v22;
        v24 = _mm_sub_epi16(
                _mm_srai_epi16(
                  _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v22, v21), *v12), (__m128i)xmmword_25D7940),
                  7u),
                _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)v13), (__m128i)0LL));
        v25 = _mm_sub_epi16(
                _mm_srai_epi16(
                  _mm_add_epi16(_mm_maddubs_epi16(_mm_unpackhi_epi8(v23, v21), *v12), (__m128i)xmmword_25D7940),
                  7u),
                _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(v13 + 8)), (__m128i)0LL));
        v9 = _mm_add_epi16(_mm_add_epi16(v9, v24), v25);
        v10 = _mm_add_epi32(_mm_add_epi32(v10, _mm_madd_epi16(v24, v24)), _mm_madd_epi16(v25, v25));
        v18 = &v18[(_DWORD)a2];
        v13 += a4;
        --v14;
      }
      while ( v14 );
    }
    else
    {
      v40 = a1;
      v41 = a3;
      v42 = a5;
      do
      {
        v43 = _mm_loadu_si128((const __m128i *)(v40 + 1));
        v44 = _mm_loadu_si128((const __m128i *)v40);
        v45 = _mm_sub_epi16(
                _mm_srai_epi16(
                  _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v44, v43), *result), (__m128i)xmmword_25D7940),
                  7u),
                _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)v41), (__m128i)0LL));
        v46 = _mm_sub_epi16(
                _mm_srai_epi16(
                  _mm_add_epi16(_mm_maddubs_epi16(_mm_unpackhi_epi8(v44, v43), *result), (__m128i)xmmword_25D7940),
                  7u),
                _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(v41 + 8)), (__m128i)0LL));
        v9 = _mm_add_epi16(_mm_add_epi16(v9, v45), v46);
        v10 = _mm_add_epi32(_mm_add_epi32(v10, _mm_madd_epi16(v45, v45)), _mm_madd_epi16(v46, v46));
        v40 += (int)a2;
        v41 += a4;
        --v42;
      }
      while ( v42 );
    }
  }
  else if ( a7 )
  {
    v26 = (__m128i *)((char *)&unk_25D7950 + 16 * a7);
    v27 = a3;
    v28 = a5;
    result = a2;
    v29 = _mm_loadu_si128((const __m128i *)a1);
    v30 = (__m128i *)((char *)a2 + a1);
    do
    {
      v31 = v29;
      v32 = _mm_loadu_si128(v30);
      v33 = _mm_sub_epi16(
              _mm_srai_epi16(
                _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v29, v32), *v26), (__m128i)xmmword_25D7940),
                7u),
              _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)v27), (__m128i)0LL));
      v34 = _mm_sub_epi16(
              _mm_srai_epi16(
                _mm_add_epi16(_mm_maddubs_epi16(_mm_unpackhi_epi8(v31, v32), *v26), (__m128i)xmmword_25D7940),
                7u),
              _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(v27 + 8)), (__m128i)0LL));
      v9 = _mm_add_epi16(_mm_add_epi16(v9, v33), v34);
      v10 = _mm_add_epi32(_mm_add_epi32(v10, _mm_madd_epi16(v33, v33)), _mm_madd_epi16(v34, v34));
      v29 = v32;
      v30 = (__m128i *)((char *)a2 + (_DWORD)v30);
      v27 += a4;
      --v28;
    }
    while ( v28 );
  }
  else
  {
    v35 = a1;
    v36 = a3;
    v37 = a5;
    result = a2;
    do
    {
      v38 = _mm_sub_epi16(
              _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)v35), (__m128i)0LL),
              _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)v36), (__m128i)0LL));
      v39 = _mm_sub_epi16(
              _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(v35 + 8)), (__m128i)0LL),
              _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(v36 + 8)), (__m128i)0LL));
      v9 = _mm_add_epi16(_mm_add_epi16(v9, v38), v39);
      v10 = _mm_add_epi32(_mm_add_epi32(v10, _mm_madd_epi16(v38, v38)), _mm_madd_epi16(v39, v39));
      v35 += (int)a2;
      v36 += a4;
      --v37;
    }
    while ( v37 );
  }
  v47 = _mm_add_epi32(
          _mm_srai_epi32(_mm_unpacklo_epi16((__m128i)0LL, v9), 0x10u),
          _mm_srai_epi32(_mm_unpackhi_epi16((__m128i)0LL, v9), 0x10u));
  v48 = _mm_add_epi32(_mm_unpacklo_epi32(v10, (__m128i)0LL), _mm_unpackhi_epi32(v10, (__m128i)0LL));
  v49 = _mm_add_epi32(_mm_unpacklo_epi32(v47, (__m128i)0LL), _mm_unpackhi_epi32(v47, (__m128i)0LL));
  *a8 = _mm_cvtsi128_si32(_mm_add_epi32(v49, _mm_srli_si128(v49, 8)));
  *a9 = _mm_cvtsi128_si32(_mm_add_epi32(v48, _mm_srli_si128(v48, 8)));
  return result;
}

