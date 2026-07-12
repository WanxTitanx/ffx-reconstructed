// Function: sub_A8167E
// Address: 0xa8167e
// Size: 0x26b
// Prototype: 

__m128i *__cdecl sub_A8167E(int a1, __m128i *a2, int a3, int a4, __m128i *a5, int a6)
{
  __m128i *v6; // edi
  int v7; // esi
  __m128i si128; // xmm1
  __m128i v9; // xmm2
  __m128i *result; // eax
  __m128i v11; // xmm4
  __m128i v12; // xmm6
  __m128i v13; // xmm7
  __int8 *v14; // esi
  __m128i v15; // xmm4
  __m128i v16; // xmm6
  __m128i v17; // xmm3
  __m128i v18; // xmm4
  __m128i v19; // xmm5
  __m128i v20; // xmm6
  __m128i v21; // xmm3
  __m128i v22; // xmm4
  __m128i *v23; // edi
  __m128i v24; // xmm1
  __m128i v25; // xmm2
  __m128i v26; // xmm7
  const __m128i *v27; // esi
  __m128i v28; // xmm5
  __m128i v29; // xmm6
  __m128i v30; // xmm4
  __m128i v31; // xmm6

  if ( a3 )
  {
    v6 = a5;
    v7 = a1;
    si128 = _mm_load_si128(&xmmword_B81350[2 * a3]);
    v9 = _mm_load_si128(&xmmword_B81350[2 * a3 + 1]);
    if ( a4 )
    {
      result = &xmmword_B81350[2 * a4];
      v11 = _mm_loadu_si128((const __m128i *)a1);
      v12 = _mm_loadu_si128((const __m128i *)(a1 + 1));
      v13 = _mm_packus_epi16(
              _mm_srai_epi16(
                _mm_add_epi16(
                  _mm_add_epi16(
                    _mm_mullo_epi16(_mm_unpacklo_epi8(v11, (__m128i)0LL), si128),
                    _mm_mullo_epi16(_mm_unpacklo_epi8(v12, (__m128i)0LL), v9)),
                  (__m128i)xmmword_25D73F0),
                7u),
              _mm_srai_epi16(
                _mm_add_epi16(
                  _mm_add_epi16(
                    _mm_mullo_epi16(_mm_unpackhi_epi8(v11, (__m128i)0LL), si128),
                    _mm_mullo_epi16(_mm_unpackhi_epi8(v12, (__m128i)0LL), v9)),
                  (__m128i)xmmword_25D73F0),
                7u));
      v14 = &a2->m128i_i8[a1];
      do
      {
        v15 = _mm_loadu_si128((const __m128i *)v14);
        v16 = _mm_loadu_si128((const __m128i *)(v14 + 1));
        v17 = _mm_add_epi16(
                _mm_mullo_epi16(_mm_unpacklo_epi8(v15, (__m128i)0LL), si128),
                _mm_mullo_epi16(_mm_unpacklo_epi8(v16, (__m128i)0LL), v9));
        v18 = _mm_add_epi16(
                _mm_mullo_epi16(_mm_unpackhi_epi8(v15, (__m128i)0LL), si128),
                _mm_mullo_epi16(_mm_unpackhi_epi8(v16, (__m128i)0LL), v9));
        v19 = _mm_mullo_epi16(_mm_unpacklo_epi8(v13, (__m128i)0LL), *result);
        v20 = _mm_mullo_epi16(_mm_unpackhi_epi8(v13, (__m128i)0LL), *result);
        v21 = _mm_srai_epi16(_mm_add_epi16(v17, (__m128i)xmmword_25D73F0), 7u);
        v22 = _mm_srai_epi16(_mm_add_epi16(v18, (__m128i)xmmword_25D73F0), 7u);
        v13 = _mm_packus_epi16(v21, v22);
        *v6 = _mm_packus_epi16(
                _mm_srai_epi16(
                  _mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(v21, result[1]), v19), (__m128i)xmmword_25D73F0),
                  7u),
                _mm_srai_epi16(
                  _mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(v22, result[1]), v20), (__m128i)xmmword_25D73F0),
                  7u));
        v14 = &v14[(_DWORD)a2];
        v6 = (__m128i *)((char *)v6 + a6);
      }
      while ( v6 != (__m128i *)((char *)a5 + 8 * a6 + 8 * a6) );
    }
    else
    {
      result = a2;
      do
      {
        v30 = _mm_loadu_si128((const __m128i *)v7);
        v31 = _mm_loadu_si128((const __m128i *)(v7 + 1));
        *v6 = _mm_packus_epi16(
                _mm_srai_epi16(
                  _mm_add_epi16(
                    _mm_add_epi16(
                      _mm_mullo_epi16(_mm_unpacklo_epi8(v30, (__m128i)0LL), si128),
                      _mm_mullo_epi16(_mm_unpacklo_epi8(v31, (__m128i)0LL), v9)),
                    (__m128i)xmmword_25D73F0),
                  7u),
                _mm_srai_epi16(
                  _mm_add_epi16(
                    _mm_add_epi16(
                      _mm_mullo_epi16(_mm_unpackhi_epi8(v30, (__m128i)0LL), si128),
                      _mm_mullo_epi16(_mm_unpackhi_epi8(v31, (__m128i)0LL), v9)),
                    (__m128i)xmmword_25D73F0),
                  7u));
        v7 += (int)a2;
        v6 = (__m128i *)((char *)v6 + a6);
      }
      while ( v6 != (__m128i *)((char *)a5 + 8 * a6 + 8 * a6) );
    }
  }
  else
  {
    v23 = a5;
    v24 = _mm_load_si128(&xmmword_B81350[2 * a4]);
    v25 = _mm_load_si128(&xmmword_B81350[2 * a4 + 1]);
    result = a2;
    v26 = _mm_loadu_si128((const __m128i *)a1);
    v27 = (__m128i *)((char *)a2 + a1);
    do
    {
      v28 = v26;
      v29 = v26;
      v26 = _mm_loadu_si128(v27);
      *v23 = _mm_packus_epi16(
               _mm_srai_epi16(
                 _mm_add_epi16(
                   _mm_add_epi16(
                     _mm_mullo_epi16(_mm_unpacklo_epi8(v26, (__m128i)0LL), v25),
                     _mm_mullo_epi16(_mm_unpacklo_epi8(v28, (__m128i)0LL), v24)),
                   (__m128i)xmmword_25D73F0),
                 7u),
               _mm_srai_epi16(
                 _mm_add_epi16(
                   _mm_add_epi16(
                     _mm_mullo_epi16(_mm_unpackhi_epi8(v26, (__m128i)0LL), v25),
                     _mm_mullo_epi16(_mm_unpackhi_epi8(v29, (__m128i)0LL), v24)),
                   (__m128i)xmmword_25D73F0),
                 7u));
      v27 = (const __m128i *)((char *)v27 + (_DWORD)a2);
      v23 = (__m128i *)((char *)v23 + a6);
    }
    while ( v23 != (__m128i *)((char *)a5 + 8 * a6 + 8 * a6) );
  }
  return result;
}

