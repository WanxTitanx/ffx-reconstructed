// Function: sub_A81A40
// Address: 0xa81a40
// Size: 0x119
// Prototype: 

int __cdecl sub_A81A40(int a1, int a2, int a3, int a4, int a5, int a6)
{
  __m128i si128; // xmm7
  const __m128i *v7; // eax
  __m128i v8; // xmm4
  __m128i v9; // xmm5
  __m128i v10; // xmm6
  int v11; // esi
  int result; // eax
  int v13; // ecx
  _QWORD *v14; // edi
  __m128i v15; // xmm1
  __m128i v16; // xmm0
  __m128i v17; // xmm5
  __m128i v18; // xmm6
  __m128i v19; // xmm3
  __m128i v20; // xmm4
  int v21; // esi
  int v22; // ecx
  _QWORD *v23; // edi
  __m128i v24; // xmm2
  __m128i v25; // xmm0

  si128 = _mm_load_si128((const __m128i *)&xmmword_25D7450);
  v7 = (const __m128i *)((char *)&unk_25D7460 + 16 * a6);
  if ( v7->m128i_i32[0] )
  {
    v8 = _mm_load_si128(v7);
    v9 = _mm_load_si128(v7 + 16);
    v10 = _mm_load_si128(v7 + 8);
    v11 = a1;
    result = a2;
    v13 = a5;
    v14 = (_QWORD *)(a3 - a4);
    do
    {
      v15 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(v11 - 2)), _mm_loadl_epi64((const __m128i *)(v11 + 3)));
      v14 = (_QWORD *)((char *)v14 + a4);
      v11 += a2;
      --v13;
      v16 = _mm_srai_epi16(
              _mm_adds_epi16(
                _mm_adds_epi16(
                  _mm_maddubs_epi16(v15, v8),
                  _mm_maddubs_epi16(_mm_shuffle_epi8(v15, (__m128i)xmmword_25D7430), v9)),
                _mm_adds_epi16(_mm_maddubs_epi16(_mm_shuffle_epi8(v15, (__m128i)xmmword_25D7440), v10), si128)),
              7u);
      *v14 = _mm_packus_epi16(v16, v16).m128i_u64[0];
    }
    while ( v13 );
  }
  else
  {
    v17 = _mm_load_si128(v7 + 16);
    v18 = _mm_load_si128(v7 + 8);
    v19 = _mm_load_si128((const __m128i *)&xmmword_25D7430);
    v20 = _mm_load_si128((const __m128i *)&xmmword_25D7440);
    v21 = a1;
    result = a2;
    v22 = a5;
    v23 = (_QWORD *)(a3 - a4);
    do
    {
      v24 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(v21 - 2)), _mm_loadl_epi64((const __m128i *)(v21 + 3)));
      v23 = (_QWORD *)((char *)v23 + a4);
      v21 += a2;
      --v22;
      v25 = _mm_srai_epi16(
              _mm_adds_epi16(
                _mm_adds_epi16(_mm_maddubs_epi16(_mm_shuffle_epi8(v24, v19), v17), si128),
                _mm_maddubs_epi16(_mm_shuffle_epi8(v24, v20), v18)),
              7u);
      *v23 = _mm_packus_epi16(v25, v25).m128i_u64[0];
    }
    while ( v22 );
  }
  return result;
}

