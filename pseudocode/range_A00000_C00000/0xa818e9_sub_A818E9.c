// Function: sub_A818E9
// Address: 0xa818e9
// Size: 0x155
// Prototype: 

__m128i *__cdecl sub_A818E9(const __m128i *a1, int a2, int a3, int a4, _QWORD *a5, int a6)
{
  __m128i v6; // xmm1
  __m128i v7; // xmm2
  const __m128i *v8; // esi
  __m128i v9; // xmm3
  __m128i v10; // xmm4
  __m128i v11; // xmm5
  const __m128i *v12; // esi
  __m128i v13; // xmm6
  __m128i v14; // xmm7
  __m128i v15; // xmm0
  _QWORD *v16; // edi
  __m128i si128; // xmm1
  __m128i v18; // xmm2
  __m128i *result; // eax
  __m128i v20; // xmm5
  __m128i v21; // xmm6
  __m128i v22; // xmm3
  __m128i v23; // xmm7
  __m128i v24; // xmm3
  __m128i v25; // xmm4
  __m128i v26; // xmm3
  __m128i v27; // [esp+0h] [ebp-A8h] BYREF
  __m128i v28[8]; // [esp+10h] [ebp-98h] BYREF
  int *v29; // [esp+90h] [ebp-18h]
  int v30; // [esp+A0h] [ebp-8h] BYREF

  v29 = &v30;
  v6 = _mm_loadu_si128((const __m128i *)((char *)a1 + a2));
  v7 = _mm_loadu_si128((const __m128i *)((char *)a1 + 2 * a2));
  v8 = (const __m128i *)((char *)a1 + 3 * a2);
  v9 = _mm_loadu_si128(v8);
  v10 = _mm_loadu_si128((const __m128i *)((char *)v8 + a2));
  v11 = _mm_loadu_si128((const __m128i *)((char *)v8 + 2 * a2));
  v12 = (const __m128i *)((char *)v8 + 3 * a2);
  v13 = _mm_loadu_si128(v12);
  v14 = _mm_loadu_si128((const __m128i *)((char *)v12 + a2));
  v27 = _mm_loadu_si128(a1);
  v15 = _mm_loadu_si128((const __m128i *)((char *)v12 + 2 * a2));
  v28[0] = v6;
  v28[1] = v7;
  v28[2] = v9;
  v28[3] = v10;
  v28[4] = v11;
  v28[5] = v13;
  v28[6] = v14;
  v28[7] = v15;
  v16 = a5;
  si128 = _mm_load_si128(&xmmword_B81350[2 * a3]);
  v18 = _mm_load_si128(&xmmword_B81350[2 * a3 + 1]);
  result = &xmmword_B81350[2 * a4];
  v20 = _mm_load_si128(result);
  v21 = _mm_load_si128(result + 1);
  v22 = _mm_load_si128(&v27);
  v23 = _mm_srai_epi16(
          _mm_add_epi16(
            _mm_add_epi16(
              _mm_mullo_epi16(_mm_unpacklo_epi8(v22, (__m128i)0LL), si128),
              _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_srli_si128(v22, 1), (__m128i)0LL), v18)),
            (__m128i)xmmword_25D73F0),
          7u);
  do
  {
    v24 = _mm_load_si128(v28);
    v25 = _mm_srai_epi16(
            _mm_add_epi16(
              _mm_add_epi16(
                _mm_mullo_epi16(_mm_unpacklo_epi8(v24, (__m128i)0LL), si128),
                _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_srli_si128(v24, 1), (__m128i)0LL), v18)),
              (__m128i)xmmword_25D73F0),
            7u);
    v26 = _mm_add_epi16(_mm_mullo_epi16(v25, v21), _mm_mullo_epi16(v23, v20));
    v23 = v25;
    *v16 = _mm_packus_epi16(_mm_srai_epi16(_mm_add_epi16(v26, (__m128i)xmmword_25D73F0), 7u), (__m128i)0LL).m128i_u64[0];
    v16 = (_QWORD *)((char *)v16 + a6);
  }
  while ( v16 != &a5[a6] );
  return result;
}

