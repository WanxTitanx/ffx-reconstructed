// Function: sub_A81F1B
// Address: 0xa81f1b
// Size: 0x110
// Prototype: 

__int8 *__cdecl sub_A81F1B(const __m128i *a1, int a2, _QWORD *a3, int a4, int a5, int a6)
{
  const __m128i *v6; // eax
  __m128i si128; // xmm5
  __m128i v10; // xmm6
  __m128i v11; // xmm7
  const __m128i *v12; // esi
  __int8 *result; // eax
  __m128i v14; // xmm3
  __m128i v15; // xmm2
  __m128i v16; // xmm1
  __m128i v17; // xmm2
  __m128i v18; // xmm6
  __m128i v19; // xmm7
  __m128i v20; // xmm5
  const __m128i *v21; // esi
  __m128i v22; // xmm3
  __m128i v23; // xmm2
  __m128i v24; // xmm2

  v6 = (const __m128i *)((char *)&unk_25D7460 + 16 * a6);
  if ( v6->m128i_i32[0] )
  {
    si128 = _mm_load_si128(v6);
    v10 = _mm_load_si128(v6 + 16);
    v11 = _mm_load_si128(v6 + 8);
    v12 = a1;
    result = &a1->m128i_i8[a2];
    do
    {
      v14 = _mm_maddubs_epi16(
              _mm_unpacklo_epi8(
                _mm_loadl_epi64((const __m128i *)((char *)v12 + 2 * a2)),
                _mm_loadl_epi64((const __m128i *)((char *)v12 + 4 * a2))),
              v10);
      v15 = _mm_maddubs_epi16(
              _mm_unpacklo_epi8(
                _mm_loadl_epi64((const __m128i *)((char *)v12 + a2)),
                _mm_loadl_epi64((const __m128i *)&result[2 * a2])),
              v11);
      v16 = _mm_maddubs_epi16(
              _mm_unpacklo_epi8(_mm_loadl_epi64(v12), _mm_loadl_epi64((const __m128i *)&result[4 * a2])),
              si128);
      v12 = (const __m128i *)((char *)v12 + a2);
      result += a2;
      v17 = _mm_srai_epi16(
              _mm_adds_epi16(
                _mm_adds_epi16(_mm_adds_epi16(v15, v14), v16),
                _mm_load_si128((const __m128i *)&xmmword_25D7450)),
              7u);
      *a3 = _mm_packus_epi16(v17, v17).m128i_u64[0];
      a3 = (_QWORD *)((char *)a3 + a4);
      --a5;
    }
    while ( a5 );
  }
  else
  {
    v18 = _mm_load_si128(v6 + 16);
    v19 = _mm_load_si128(v6 + 8);
    v20 = _mm_load_si128((const __m128i *)&xmmword_25D7450);
    v21 = a1;
    result = &a1->m128i_i8[a2];
    do
    {
      v22 = _mm_maddubs_epi16(
              _mm_unpacklo_epi8(
                _mm_loadl_epi64((const __m128i *)((char *)v21 + 2 * a2)),
                _mm_loadl_epi64((const __m128i *)((char *)v21 + 4 * a2))),
              v18);
      v23 = _mm_maddubs_epi16(
              _mm_unpacklo_epi8(
                _mm_loadl_epi64((const __m128i *)((char *)v21 + a2)),
                _mm_loadl_epi64((const __m128i *)&result[2 * a2])),
              v19);
      v21 = (const __m128i *)((char *)v21 + a2);
      result += a2;
      v24 = _mm_srai_epi16(_mm_adds_epi16(_mm_adds_epi16(v23, v22), v20), 7u);
      *a3 = _mm_packus_epi16(v24, v24).m128i_u64[0];
      a3 = (_QWORD *)((char *)a3 + a4);
      --a5;
    }
    while ( a5 );
  }
  return result;
}

