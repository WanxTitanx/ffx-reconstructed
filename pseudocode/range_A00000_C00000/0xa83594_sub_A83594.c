// Function: sub_A83594
// Address: 0xa83594
// Size: 0x96
// Prototype: 

int __cdecl sub_A83594(unsigned int *a1, int a2, int a3, int a4, __m128i *a5)
{
  int v6; // edi

  v6 = a3 + 2 * a4;
  *a5 = _mm_add_epi16(
          _mm_add_epi16(
            _mm_add_epi16(
              _mm_mpsadbw_epu8(
                _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)a3), _mm_loadl_epi64((const __m128i *)(a3 + 8))),
                _mm_cvtsi32_si128(*a1),
                0),
              _mm_mpsadbw_epu8(
                _mm_unpacklo_epi64(
                  _mm_loadl_epi64((const __m128i *)(a3 + a4)),
                  _mm_loadl_epi64((const __m128i *)(a3 + a4 + 8))),
                _mm_cvtsi32_si128(*(unsigned int *)((char *)a1 + a2)),
                0)),
            _mm_mpsadbw_epu8(
              _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v6), _mm_loadl_epi64((const __m128i *)(v6 + 8))),
              _mm_cvtsi32_si128(*(unsigned int *)((char *)a1 + 2 * a2)),
              0)),
          _mm_mpsadbw_epu8(
            _mm_unpacklo_epi64(
              _mm_loadl_epi64((const __m128i *)(v6 + a4)),
              _mm_loadl_epi64((const __m128i *)(v6 + a4 + 8))),
            _mm_cvtsi32_si128(*(unsigned int *)((char *)a1 + 2 * a2 + a2)),
            0));
  return a2;
}

