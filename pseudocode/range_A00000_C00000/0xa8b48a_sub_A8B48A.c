// Function: sub_A8B48A
// Address: 0xa8b48a
// Size: 0xaa
// Prototype: 

int __cdecl sub_A8B48A(_QWORD *a1, int a2, int a3, _BYTE *a4, int a5)
{
  __m128i si128; // xmm2
  unsigned int v7; // ebx
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  _BYTE *v10; // esi
  _QWORD *v11; // edi
  __m128i v12; // xmm0
  __m128i v13; // xmm3
  __m128i v14; // xmm1
  unsigned int v15; // ebx
  __m128 v16; // xmm0
  __m128 v17; // xmm1

  si128 = _mm_load_si128((const __m128i *)&xmmword_25D77E0);
  v7 = 3 * a5;
  LOBYTE(v7) = a4[3 * a5];
  v8 = (__m128)_mm_shuffle_epi8(_mm_unpacklo_epi8(_mm_cvtsi32_si128(*a4), _mm_cvtsi32_si128(a4[a5])), si128);
  v9 = (__m128)_mm_shuffle_epi8(_mm_unpacklo_epi8(_mm_cvtsi32_si128(a4[2 * a5]), _mm_cvtsi32_si128(v7)), si128);
  *a1 = v8.m128_u64[0];
  _mm_storeh_ps((double *)((char *)a1 + a2), v8);
  *(_QWORD *)((char *)a1 + 2 * a2) = v9.m128_u64[0];
  _mm_storeh_ps((double *)((char *)a1 + 3 * a2), v9);
  v10 = &a4[4 * a5];
  v11 = (_QWORD *)((char *)a1 + 4 * a2);
  LOBYTE(v7) = *v10;
  v12 = _mm_cvtsi32_si128(v7);
  LOBYTE(v7) = v10[a5];
  v13 = _mm_cvtsi32_si128(v7);
  LOBYTE(v7) = v10[2 * a5];
  v14 = _mm_cvtsi32_si128(v7);
  v15 = 3 * a5;
  LOBYTE(v15) = v10[3 * a5];
  v16 = (__m128)_mm_shuffle_epi8(_mm_unpacklo_epi8(v12, v13), si128);
  v17 = (__m128)_mm_shuffle_epi8(_mm_unpacklo_epi8(v14, _mm_cvtsi32_si128(v15)), si128);
  *v11 = v16.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v11 + a2), v16);
  *(_QWORD *)((char *)v11 + 2 * a2) = v17.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v11 + 3 * a2), v17);
  return a5;
}

