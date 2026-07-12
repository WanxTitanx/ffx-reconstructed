// Function: sub_A82111
// Address: 0xa82111
// Size: 0x297
// Prototype: 

const __m128i *__cdecl sub_A82111(int a1, const __m128i *a2, int a3, int a4, __m128i *a5, int a6)
{
  __m128i *v6; // edi
  __int8 *v7; // esi
  __m128i si128; // xmm1
  const __m128i *result; // eax
  __m128i v10; // xmm2
  __int8 *v11; // esi
  __m128i v12; // xmm7
  __m128i v13; // xmm6
  __m128i v14; // xmm4
  __m128i v15; // xmm5
  __m128i v16; // xmm6
  __m128i v17; // xmm5
  __m128i *v18; // edi
  __m128i v19; // xmm1
  __m128i v20; // xmm4
  __m128i v21; // xmm2
  __int8 *v22; // esi
  __m128i v23; // xmm3
  __m128i v24; // xmm5
  __m128i v25; // xmm7
  __m128i v26; // xmm6
  __m128i v27; // xmm3
  __m128i v28; // xmm2
  __m128i v29; // xmm4
  __int8 *v30; // esi
  __m128i v31; // xmm5
  __m128i v32; // xmm6
  __m128i *v33; // edi

  if ( a3 )
  {
    v6 = a5;
    v7 = (__int8 *)a1;
    si128 = _mm_load_si128(&xmmword_25D75E0[a3]);
    if ( a4 )
    {
      result = &xmmword_25D75E0[a4];
      v10 = _mm_load_si128(result);
      v11 = &a2->m128i_i8[a1];
      v12 = _mm_packus_epi16(
              _mm_srai_epi16(
                _mm_add_epi16(
                  _mm_maddubs_epi16(
                    _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)a1), _mm_loadl_epi64((const __m128i *)(a1 + 1))),
                    si128),
                  (__m128i)xmmword_25D7450),
                7u),
              _mm_srai_epi16(
                _mm_add_epi16(
                  _mm_maddubs_epi16(
                    _mm_unpacklo_epi8(
                      _mm_loadl_epi64((const __m128i *)(a1 + 8)),
                      _mm_loadl_epi64((const __m128i *)(a1 + 9))),
                    si128),
                  (__m128i)xmmword_25D7450),
                7u));
      do
      {
        v13 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)v11), _mm_loadl_epi64((const __m128i *)(v11 + 1)));
        v14 = _mm_loadl_epi64((const __m128i *)(v11 + 8));
        v15 = _mm_loadl_epi64((const __m128i *)(v11 + 9));
        v11 = &a2->m128i_i8[(_DWORD)v11];
        v16 = _mm_packus_epi16(
                _mm_srai_epi16(_mm_add_epi16(_mm_maddubs_epi16(v13, si128), (__m128i)xmmword_25D7450), 7u),
                _mm_srai_epi16(
                  _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v14, v15), si128), (__m128i)xmmword_25D7450),
                  7u));
        v17 = _mm_packus_epi16(
                _mm_srai_epi16(
                  _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v12, v16), v10), (__m128i)xmmword_25D7450),
                  7u),
                _mm_srai_epi16(
                  _mm_add_epi16(_mm_maddubs_epi16(_mm_unpackhi_epi8(v12, v16), v10), (__m128i)xmmword_25D7450),
                  7u));
        v12 = v16;
        *v6 = v17;
        v6 = (__m128i *)((char *)v6 + a6);
      }
      while ( v6 != (__m128i *)((char *)a5 + 8 * a6 + 8 * a6) );
    }
    else
    {
      result = a2;
      do
      {
        v27 = _mm_loadl_epi64((const __m128i *)(v7 + 8));
        v28 = _mm_maddubs_epi16(
                _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)v7), _mm_loadl_epi64((const __m128i *)(v7 + 1))),
                si128);
        v29 = _mm_loadl_epi64((const __m128i *)(v7 + 9));
        v30 = &a2->m128i_i8[(_DWORD)v7];
        v31 = _mm_maddubs_epi16(
                _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)v30), _mm_loadl_epi64((const __m128i *)(v30 + 1))),
                si128);
        v32 = _mm_maddubs_epi16(
                _mm_unpacklo_epi8(
                  _mm_loadl_epi64((const __m128i *)(v30 + 8)),
                  _mm_loadl_epi64((const __m128i *)(v30 + 9))),
                si128);
        *v6 = _mm_packus_epi16(
                _mm_srai_epi16(_mm_add_epi16(v28, (__m128i)xmmword_25D7450), 7u),
                _mm_srai_epi16(
                  _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v27, v29), si128), (__m128i)xmmword_25D7450),
                  7u));
        v33 = (__m128i *)((char *)v6 + a6);
        v7 = &a2->m128i_i8[(_DWORD)v30];
        *v33 = _mm_packus_epi16(
                 _mm_srai_epi16(_mm_add_epi16(v31, (__m128i)xmmword_25D7450), 7u),
                 _mm_srai_epi16(_mm_add_epi16(v32, (__m128i)xmmword_25D7450), 7u));
        v6 = (__m128i *)((char *)v33 + a6);
      }
      while ( v6 != (__m128i *)((char *)a5 + 8 * a6 + 8 * a6) );
    }
  }
  else
  {
    v18 = a5;
    v19 = _mm_load_si128(&xmmword_25D75E0[a4]);
    result = a2;
    v20 = _mm_loadl_epi64((const __m128i *)a1);
    v21 = _mm_loadl_epi64((const __m128i *)(a1 + 8));
    v22 = &a2->m128i_i8[a1];
    do
    {
      v23 = _mm_loadl_epi64((const __m128i *)v22);
      v24 = _mm_loadl_epi64((const __m128i *)(v22 + 8));
      v25 = _mm_loadl_epi64((const __m128i *)((char *)a2 + (_DWORD)v22));
      v26 = _mm_loadl_epi64((const __m128i *)((char *)&a2->m128i_u64[1] + (_DWORD)v22));
      *v18 = _mm_packus_epi16(
               _mm_srai_epi16(
                 _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v20, v23), v19), (__m128i)xmmword_25D7450),
                 7u),
               _mm_srai_epi16(
                 _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v21, v24), v19), (__m128i)xmmword_25D7450),
                 7u));
      v20 = v25;
      *(__m128i *)((char *)v18 + a6) = _mm_packus_epi16(
                                         _mm_srai_epi16(
                                           _mm_add_epi16(
                                             _mm_maddubs_epi16(_mm_unpacklo_epi8(v23, v25), v19),
                                             (__m128i)xmmword_25D7450),
                                           7u),
                                         _mm_srai_epi16(
                                           _mm_add_epi16(
                                             _mm_maddubs_epi16(_mm_unpacklo_epi8(v24, v26), v19),
                                             (__m128i)xmmword_25D7450),
                                           7u));
      v22 += 2 * (_DWORD)a2;
      v21 = v26;
      v18 = (__m128i *)((char *)v18 + 2 * a6);
    }
    while ( v18 != (__m128i *)((char *)a5 + 8 * a6 + 8 * a6) );
  }
  return result;
}

