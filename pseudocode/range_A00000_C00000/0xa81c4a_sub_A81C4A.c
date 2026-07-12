// Function: sub_A81C4A
// Address: 0xa81c4a
// Size: 0x115
// Prototype: 

int __cdecl sub_A81C4A(int a1, int a2, _DWORD *a3, int a4, int a5, int a6)
{
  const __m128i *v6; // eax
  __m128i si128; // xmm7
  __m128i v8; // xmm4
  __m128i v9; // xmm5
  __m128i v10; // xmm6
  int v11; // esi
  _DWORD *v12; // edi
  int result; // eax
  int v14; // ecx
  __m128i v15; // xmm2
  __m128i v16; // xmm0
  __m128i v17; // xmm5
  __m128i v18; // xmm6
  __m128i v19; // xmm0
  __m128i v20; // xmm3
  int v21; // esi
  _DWORD *v22; // edi
  int v23; // ecx
  __m128i v24; // xmm2
  __m128i v25; // xmm1

  v6 = (const __m128i *)((char *)&unk_25D7460 + 16 * a6);
  si128 = _mm_load_si128((const __m128i *)&xmmword_25D7450);
  if ( v6->m128i_i32[0] )
  {
    v8 = _mm_load_si128(v6);
    v9 = _mm_load_si128(v6 + 16);
    v10 = _mm_load_si128(v6 + 8);
    v11 = a1;
    v12 = a3;
    result = a2;
    v14 = a5;
    do
    {
      v15 = _mm_loadu_si128((const __m128i *)(v11 - 2));
      v11 += a2;
      v16 = _mm_srai_epi16(
              _mm_adds_epi16(
                _mm_adds_epi16(
                  _mm_adds_epi16(
                    _mm_maddubs_epi16(_mm_shuffle_epi8(v15, (__m128i)xmmword_25D7400), v8),
                    _mm_maddubs_epi16(_mm_shuffle_epi8(v15, (__m128i)xmmword_25D7410), v9)),
                  si128),
                _mm_maddubs_epi16(_mm_shuffle_epi8(v15, (__m128i)xmmword_25D7420), v10)),
              7u);
      *v12 = _mm_cvtsi128_si32(_mm_packus_epi16(v16, v16));
      v12 = (_DWORD *)((char *)v12 + a4);
      --v14;
    }
    while ( v14 );
  }
  else
  {
    v17 = _mm_load_si128(v6 + 16);
    v18 = _mm_load_si128(v6 + 8);
    v19 = _mm_load_si128((const __m128i *)&xmmword_25D7410);
    v20 = _mm_load_si128((const __m128i *)&xmmword_25D7420);
    v21 = a1;
    v22 = a3;
    result = a2;
    v23 = a5;
    do
    {
      v24 = _mm_loadu_si128((const __m128i *)(v21 - 2));
      v21 += a2;
      v25 = _mm_srai_epi16(
              _mm_adds_epi16(
                _mm_adds_epi16(_mm_maddubs_epi16(_mm_shuffle_epi8(v24, v19), v17), si128),
                _mm_maddubs_epi16(_mm_shuffle_epi8(v24, v20), v18)),
              7u);
      *v22 = _mm_cvtsi128_si32(_mm_packus_epi16(v25, v25));
      v22 = (_DWORD *)((char *)v22 + a4);
      --v23;
    }
    while ( v23 );
  }
  return result;
}

