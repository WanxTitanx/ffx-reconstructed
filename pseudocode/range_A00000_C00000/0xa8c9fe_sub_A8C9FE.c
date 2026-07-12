// Function: sub_A8C9FE
// Address: 0xa8c9fe
// Size: 0xa8
// Prototype: 

int __cdecl sub_A8C9FE(const __m128i *a1, int a2, const __m128i *a3, int a4, int a5, _DWORD *a6, _DWORD *a7)
{
  __m128i v7; // xmm6
  __m128i v8; // xmm7
  int result; // eax
  __m128i v13; // xmm5
  __m64 v14; // mm6
  __m64 v15; // mm7
  __m64 v16; // mm2

  v7 = 0;
  v8 = 0;
  result = a2;
  do
  {
    v13 = _mm_sub_epi16(
            _mm_unpacklo_epi8(
              _mm_avg_epu8(_mm_loadl_epi64(a1), _mm_loadl_epi64((const __m128i *)((char *)a1 + a2))),
              (__m128i)0LL),
            _mm_unpacklo_epi8(_mm_loadl_epi64(a3), (__m128i)0LL));
    v7 = _mm_add_epi16(v7, v13);
    v8 = _mm_add_epi32(v8, _mm_madd_epi16(v13, v13));
    a1 = (const __m128i *)((char *)a1 + a2);
    a3 = (const __m128i *)((char *)a3 + a4);
    --a5;
  }
  while ( a5 );
  v14 = _m_paddw(_mm_movepi64_pi64(v7), _mm_movepi64_pi64(_mm_srli_si128(v7, 8)));
  v15 = _m_paddd(_mm_movepi64_pi64(v8), _mm_movepi64_pi64(_mm_srli_si128(v8, 8)));
  v16 = _m_paddd(_m_punpcklwd(0, v14), _m_punpckhwd(0, v14));
  *a6 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(v16, _m_psrlqi(v16, 0x20u)), 0x10u));
  *a7 = _mm_cvtsi64_si32(_m_paddd(_m_psrlqi(v15, 0x20u), v15));
  return result;
}

