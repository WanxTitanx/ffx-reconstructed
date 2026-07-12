// Function: sub_A7F36F
// Address: 0xa7f36f
// Size: 0x1eb
// Prototype: 

int __cdecl sub_A7F36F(_QWORD *a1, int a2, int a3, int a4, __int32 a5)
{
  __int64 *v5; // edi
  __int64 v6; // xmm1_8
  int n8; // ecx
  _QWORD *v8; // edi
  __int64 v9; // xmm1_8
  int n8_1; // ecx
  __m128i *v11; // esi
  int result; // eax
  __m128i v13; // xmm5
  __m128i v14; // xmm6
  __m128i v15; // xmm7
  const __m128i *v16; // edi
  int n15; // ecx
  __m128i v18; // xmm1
  __m128i v19; // xmm2
  int n8_2; // edx
  __m128i v21; // xmm1
  __m128i v22; // xmm2
  __m128i v23; // xmm4
  __m128i v24; // xmm2
  __m128i v25; // xmm4
  __m128i v26; // xmm2
  __m128i v27; // xmm3
  __m128i v28; // xmm1
  _QWORD v29[16]; // [esp+0h] [ebp-A8h]
  __m128i v30; // [esp+80h] [ebp-28h]
  int *v31; // [esp+90h] [ebp-18h]
  int v32; // [esp+A0h] [ebp-8h] BYREF
  int n8_3; // [esp+B8h] [ebp+10h]

  v31 = &v32;
  v30.m128i_i32[0] = a5;
  v30.m128i_i32[1] = a5;
  v30.m128i_i32[2] = a5;
  v30.m128i_i32[3] = a5;
  n8_3 = a3 + 8;
  do
  {
    v5 = (_QWORD *)((char *)a1 + a2 * (n8_3 - 9));
    v6 = *v5;
    n8 = 8;
    do
    {
      v5 = (__int64 *)((char *)v5 + a2);
      *v5 = v6;
      --n8;
    }
    while ( n8 );
    v8 = a1;
    v9 = *a1;
    n8_1 = 8;
    do
    {
      v8 = (_QWORD *)((char *)v8 - a2);
      *v8 = v9;
      --n8_1;
    }
    while ( n8_1 );
    v11 = (__m128i *)&a1[-a2];
    result = a2;
    v13 = 0;
    v14 = 0;
    v15 = 0;
    v16 = v11;
    n15 = 15;
    do
    {
      v18 = _mm_unpacklo_epi8(_mm_loadl_epi64(v16), (__m128i)0LL);
      v13 = _mm_add_epi16(v13, v18);
      v19 = _mm_mullo_epi16(v18, v18);
      v14 = _mm_add_epi32(v14, _mm_unpacklo_epi16(v19, (__m128i)0LL));
      v15 = _mm_add_epi32(v15, _mm_unpackhi_epi16(v19, (__m128i)0LL));
      v16 = (const __m128i *)((char *)v16 + a2);
      --n15;
    }
    while ( n15 );
    n8_2 = 0;
    do
    {
      v21 = _mm_unpacklo_epi8(_mm_loadl_epi64(v11), (__m128i)0LL);
      v22 = _mm_unpacklo_epi8(_mm_loadl_epi64(v16), (__m128i)0LL);
      v13 = _mm_sub_epi16(_mm_add_epi16(v13, v22), v21);
      v23 = _mm_mullo_epi16(v22, v22);
      v24 = _mm_mullo_epi16(v21, v21);
      v14 = _mm_sub_epi32(
              _mm_add_epi32(v14, _mm_unpacklo_epi16(v23, (__m128i)0LL)),
              _mm_unpacklo_epi16(v24, (__m128i)0LL));
      v15 = _mm_sub_epi32(
              _mm_add_epi32(v15, _mm_unpackhi_epi16(v23, (__m128i)0LL)),
              _mm_unpackhi_epi16(v24, (__m128i)0LL));
      v25 = _mm_mulhi_epi16(v13, v13);
      v26 = _mm_mullo_epi16(v13, v13);
      v27 = _mm_packs_epi16(
              _mm_packs_epi32(
                _mm_srai_epi32(
                  _mm_sub_epi32(
                    _mm_sub_epi32(_mm_sub_epi32(_mm_slli_epi32(v14, 4u), v14), _mm_unpacklo_epi16(v26, v25)),
                    v30),
                  0x1Fu),
                _mm_srai_epi32(
                  _mm_sub_epi32(
                    _mm_sub_epi32(_mm_sub_epi32(_mm_slli_epi32(v15, 4u), v15), _mm_unpackhi_epi16(v26, v25)),
                    v30),
                  0x1Fu)),
              (__m128i)0LL);
      v28 = _mm_loadl_epi64((__m128i *)((char *)v11 + 8 * a2));
      v29[n8_2 & 0xF] = _mm_or_si128(
                          _mm_and_si128(
                            _mm_packus_epi16(
                              _mm_srai_epi16(
                                _mm_add_epi16(
                                  _mm_add_epi16(_mm_unpacklo_epi8(v28, (__m128i)0LL), v13),
                                  _mm_loadu_si128((const __m128i *)((char *)&xmmword_B7F7D8 + 2 * (n8_2 & 0x7F)))),
                                4u),
                              (__m128i)0LL),
                            v27),
                          _mm_andnot_si128(v27, _mm_move_epi64(v28))).m128i_u64[0];
      if ( n8_2 >= 8 )
        v11->m128i_i64[0] = v29[((_BYTE)n8_2 - 8) & 0xF];
      v11 = (__m128i *)((char *)v11 + a2);
      v16 = (const __m128i *)((char *)v16 + a2);
      ++n8_2;
    }
    while ( n8_2 < n8_3 );
    ++a1;
    a4 -= 8;
  }
  while ( a4 > 0 );
  return result;
}

