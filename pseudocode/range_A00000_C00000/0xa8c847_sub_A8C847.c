// Function: sub_A8C847
// Address: 0xa8c847
// Size: 0xc0
// Prototype: 

int __cdecl sub_A8C847(int a1, int a2, const __m128i *a3, int a4, int a5, _DWORD *a6, _DWORD *a7)
{
  __m128i v7; // xmm6
  __m128i v8; // xmm7
  int result; // eax
  __m128i v12; // xmm5
  int v13; // esi
  __m128i v14; // xmm1
  __m128i v15; // xmm5
  __m64 v16; // mm6
  __m64 v17; // mm7
  __m64 v18; // mm2

  v7 = 0;
  v8 = 0;
  result = a2;
  v12 = _mm_avg_epu8(_mm_loadl_epi64((const __m128i *)a1), _mm_loadl_epi64((const __m128i *)(a1 + 1)));
  v13 = a2 + a1;
  do
  {
    v14 = _mm_avg_epu8(_mm_loadl_epi64((const __m128i *)v13), _mm_loadl_epi64((const __m128i *)(v13 + 1)));
    v15 = _mm_sub_epi16(
            _mm_unpacklo_epi8(_mm_avg_epu8(v12, v14), (__m128i)0LL),
            _mm_unpacklo_epi8(_mm_loadl_epi64(a3), (__m128i)0LL));
    v7 = _mm_add_epi16(v7, v15);
    v8 = _mm_add_epi32(v8, _mm_madd_epi16(v15, v15));
    v12 = v14;
    v13 += a2;
    a3 = (const __m128i *)((char *)a3 + a4);
    --a5;
  }
  while ( a5 );
  v16 = _m_paddw(_mm_movepi64_pi64(v7), _mm_movepi64_pi64(_mm_srli_si128(v7, 8)));
  v17 = _m_paddd(_mm_movepi64_pi64(v8), _mm_movepi64_pi64(_mm_srli_si128(v8, 8)));
  v18 = _m_paddd(_m_punpcklwd(0, v16), _m_punpckhwd(0, v16));
  *a6 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(v18, _m_psrlqi(v18, 0x20u)), 0x10u));
  *a7 = _mm_cvtsi64_si32(_m_paddd(_m_psrlqi(v17, 0x20u), v17));
  return result;
}

