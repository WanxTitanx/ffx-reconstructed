// Function: sub_A8C5E9
// Address: 0xa8c5e9
// Size: 0x25e
// Prototype: 

__m128i *__cdecl sub_A8C5E9(
        int a1,
        __m128i *a2,
        const __m128i *a3,
        int a4,
        int a5,
        int a6,
        int a7,
        _DWORD *a8,
        _DWORD *a9)
{
  __m128i v9; // xmm6
  __m128i v10; // xmm7
  __m128i si128; // xmm4
  __m128i *result; // eax
  const __m128i *v13; // edi
  int v14; // ecx
  __m128i v15; // xmm5
  __int8 *v16; // esi
  __m128i v17; // xmm3
  __m128i v18; // xmm1
  const __m128i *v19; // edi
  int v20; // ecx
  __m128i v21; // xmm1
  const __m128i *v22; // esi
  __m128i v23; // xmm5
  __m128i v24; // xmm1
  const __m128i *v25; // esi
  const __m128i *v26; // edi
  int v27; // ecx
  __m128i v28; // xmm1
  int v29; // esi
  const __m128i *v30; // edi
  int v31; // ecx
  __m128i v32; // xmm1
  __m64 v33; // mm6
  __m64 v34; // mm7
  __m64 v35; // mm2

  v9 = 0;
  v10 = 0;
  si128 = _mm_load_si128((const __m128i *)asc_25D7830);
  if ( a6 )
  {
    result = &xmmword_25D7840[2 * a6];
    if ( a7 )
    {
      v13 = a3;
      v14 = a5;
      v15 = _mm_srai_epi16(
              _mm_add_epi16(
                _mm_add_epi16(
                  _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)a1), (__m128i)0LL), *result),
                  _mm_mullo_epi16(
                    _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(a1 + 1)), (__m128i)0LL),
                    result[1])),
                si128),
              7u);
      v16 = &a2->m128i_i8[a1];
      do
      {
        v17 = v15;
        v15 = _mm_srai_epi16(
                _mm_add_epi16(
                  _mm_add_epi16(
                    _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)v16), (__m128i)0LL), *result),
                    _mm_mullo_epi16(
                      _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(v16 + 1)), (__m128i)0LL),
                      result[1])),
                  si128),
                7u);
        v18 = _mm_sub_epi16(
                _mm_srai_epi16(
                  _mm_add_epi16(
                    _mm_add_epi16(
                      _mm_mullo_epi16(v15, xmmword_25D7840[2 * a7 + 1]),
                      _mm_mullo_epi16(v17, xmmword_25D7840[2 * a7])),
                    si128),
                  7u),
                _mm_unpacklo_epi8(_mm_loadl_epi64(v13), (__m128i)0LL));
        v9 = _mm_add_epi16(v9, v18);
        v10 = _mm_add_epi32(v10, _mm_madd_epi16(v18, v18));
        v16 = &a2->m128i_i8[(_DWORD)v16];
        v13 = (const __m128i *)((char *)v13 + a4);
        --v14;
      }
      while ( v14 );
    }
    else
    {
      v29 = a1;
      v30 = a3;
      v31 = a5;
      do
      {
        v32 = _mm_sub_epi16(
                _mm_srai_epi16(
                  _mm_add_epi16(
                    _mm_add_epi16(
                      _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)v29), (__m128i)0LL), *result),
                      _mm_mullo_epi16(
                        _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(v29 + 1)), (__m128i)0LL),
                        result[1])),
                    si128),
                  7u),
                _mm_unpacklo_epi8(_mm_loadl_epi64(v30), (__m128i)0LL));
        v9 = _mm_add_epi16(v9, v32);
        v10 = _mm_add_epi32(v10, _mm_madd_epi16(v32, v32));
        v29 += (int)a2;
        v30 = (const __m128i *)((char *)v30 + a4);
        --v31;
      }
      while ( v31 );
    }
  }
  else if ( a7 )
  {
    v19 = a3;
    v20 = a5;
    result = a2;
    v21 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)a1), (__m128i)0LL);
    v22 = (__m128i *)((char *)a2 + a1);
    do
    {
      v23 = _mm_unpacklo_epi8(_mm_loadl_epi64(v22), (__m128i)0LL);
      v24 = _mm_sub_epi16(
              _mm_srai_epi16(
                _mm_add_epi16(
                  _mm_add_epi16(
                    _mm_mullo_epi16(v21, xmmword_25D7840[2 * a7]),
                    _mm_mullo_epi16(v23, xmmword_25D7840[2 * a7 + 1])),
                  si128),
                7u),
              _mm_unpacklo_epi8(_mm_loadl_epi64(v19), (__m128i)0LL));
      v9 = _mm_add_epi16(v9, v24);
      v10 = _mm_add_epi32(v10, _mm_madd_epi16(v24, v24));
      v21 = v23;
      v22 = (__m128i *)((char *)a2 + (_DWORD)v22);
      v19 = (const __m128i *)((char *)v19 + a4);
      --v20;
    }
    while ( v20 );
  }
  else
  {
    v25 = (const __m128i *)a1;
    v26 = a3;
    v27 = a5;
    result = a2;
    do
    {
      v28 = _mm_sub_epi16(
              _mm_unpacklo_epi8(_mm_loadl_epi64(v25), (__m128i)0LL),
              _mm_unpacklo_epi8(_mm_loadl_epi64(v26), (__m128i)0LL));
      v9 = _mm_add_epi16(v9, v28);
      v10 = _mm_add_epi32(v10, _mm_madd_epi16(v28, v28));
      v25 = (__m128i *)((char *)a2 + (_DWORD)v25);
      v26 = (const __m128i *)((char *)v26 + a4);
      --v27;
    }
    while ( v27 );
  }
  v33 = _m_paddw(_mm_movepi64_pi64(v9), _mm_movepi64_pi64(_mm_srli_si128(v9, 8)));
  v34 = _m_paddd(_mm_movepi64_pi64(v10), _mm_movepi64_pi64(_mm_srli_si128(v10, 8)));
  v35 = _m_paddd(_m_punpcklwd(0, v33), _m_punpckhwd(0, v33));
  *a8 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(v35, _m_psrlqi(v35, 0x20u)), 0x10u));
  *a9 = _mm_cvtsi64_si32(_m_paddd(_m_psrlqi(v34, 0x20u), v34));
  return result;
}

