// Function: sub_A81D5F
// Address: 0xa81d5f
// Size: 0x1bc
// Prototype: 

int __cdecl sub_A81D5F(int a1, int a2, __m128i *a3, int a4, int a5, int a6)
{
  const __m128i *v6; // eax
  __m128i si128; // xmm5
  __m128i v8; // xmm6
  __m128i v9; // xmm7
  int v10; // esi
  __m128i *v11; // edi
  int v12; // ecx
  int result; // eax
  __m128i v14; // xmm2
  __m128i v15; // xmm3
  __m128i v16; // xmm2
  __m128i v17; // xmm1
  __m128i v18; // xmm2
  __m128i v19; // xmm6
  __m128i v20; // xmm7
  int v21; // esi
  __m128i *v22; // edi
  int v23; // ecx
  __m128i v24; // xmm2
  __m128i v25; // xmm1
  __m128i v26; // xmm5
  __m128i v27; // xmm5

  v6 = (const __m128i *)((char *)&unk_25D7460 + 16 * a6);
  if ( v6->m128i_i32[0] )
  {
    si128 = _mm_load_si128(v6);
    v8 = _mm_load_si128(v6 + 16);
    v9 = _mm_load_si128(v6 + 8);
    v10 = a1;
    v11 = a3;
    v12 = a5;
    result = a2 + a1;
    do
    {
      v14 = _mm_srai_epi16(
              _mm_adds_epi16(
                _mm_adds_epi16(
                  _mm_adds_epi16(
                    _mm_maddubs_epi16(
                      _mm_unpacklo_epi8(
                        _mm_loadl_epi64((const __m128i *)(v10 + a2)),
                        _mm_loadl_epi64((const __m128i *)(result + 2 * a2))),
                      v9),
                    _mm_maddubs_epi16(
                      _mm_unpacklo_epi8(
                        _mm_loadl_epi64((const __m128i *)(v10 + 2 * a2)),
                        _mm_loadl_epi64((const __m128i *)(v10 + 4 * a2))),
                      v8)),
                  _mm_maddubs_epi16(
                    _mm_unpacklo_epi8(
                      _mm_loadl_epi64((const __m128i *)v10),
                      _mm_loadl_epi64((const __m128i *)(result + 4 * a2))),
                    si128)),
                (__m128i)xmmword_25D7450),
              7u);
      v11->m128i_i64[0] = _mm_packus_epi16(v14, v14).m128i_u64[0];
      v15 = _mm_maddubs_epi16(
              _mm_unpacklo_epi8(
                _mm_loadl_epi64((const __m128i *)(v10 + 2 * a2 + 8)),
                _mm_loadl_epi64((const __m128i *)(v10 + 4 * a2 + 8))),
              v8);
      v16 = _mm_maddubs_epi16(
              _mm_unpacklo_epi8(
                _mm_loadl_epi64((const __m128i *)(v10 + a2 + 8)),
                _mm_loadl_epi64((const __m128i *)(result + 2 * a2 + 8))),
              v9);
      v17 = _mm_maddubs_epi16(
              _mm_unpacklo_epi8(
                _mm_loadl_epi64((const __m128i *)(v10 + 8)),
                _mm_loadl_epi64((const __m128i *)(result + 4 * a2 + 8))),
              si128);
      v10 += a2;
      result += a2;
      v18 = _mm_srai_epi16(_mm_adds_epi16(_mm_adds_epi16(_mm_adds_epi16(v16, v15), v17), (__m128i)xmmword_25D7450), 7u);
      v11->m128i_i64[1] = _mm_packus_epi16(v18, v18).m128i_u64[0];
      v11 = (__m128i *)((char *)v11 + a4);
      --v12;
    }
    while ( v12 );
  }
  else
  {
    v19 = _mm_load_si128(v6 + 16);
    v20 = _mm_load_si128(v6 + 8);
    v21 = a1;
    v22 = a3;
    v23 = a5;
    result = a2 + a1;
    do
    {
      v24 = _mm_srai_epi16(
              _mm_adds_epi16(
                _mm_adds_epi16(
                  _mm_maddubs_epi16(
                    _mm_unpacklo_epi8(
                      _mm_loadl_epi64((const __m128i *)(v21 + a2)),
                      _mm_loadl_epi64((const __m128i *)(result + 2 * a2))),
                    v20),
                  (__m128i)xmmword_25D7450),
                _mm_maddubs_epi16(
                  _mm_unpacklo_epi8(
                    _mm_loadl_epi64((const __m128i *)(v21 + 2 * a2)),
                    _mm_loadl_epi64((const __m128i *)(v21 + 4 * a2))),
                  v19)),
              7u);
      v25 = _mm_maddubs_epi16(
              _mm_unpacklo_epi8(
                _mm_loadl_epi64((const __m128i *)(v21 + 2 * a2 + 8)),
                _mm_loadl_epi64((const __m128i *)(v21 + 4 * a2 + 8))),
              v19);
      v26 = _mm_maddubs_epi16(
              _mm_unpacklo_epi8(
                _mm_loadl_epi64((const __m128i *)(v21 + a2 + 8)),
                _mm_loadl_epi64((const __m128i *)(result + 2 * a2 + 8))),
              v20);
      v21 += a2;
      result += a2;
      v27 = _mm_srai_epi16(
              _mm_adds_epi16(_mm_adds_epi16(v26, v25), _mm_load_si128((const __m128i *)&xmmword_25D7450)),
              7u);
      *v22 = _mm_unpacklo_epi64(_mm_packus_epi16(v24, v24), _mm_packus_epi16(v27, v27));
      v22 = (__m128i *)((char *)v22 + a4);
      --v23;
    }
    while ( v23 );
  }
  return result;
}

