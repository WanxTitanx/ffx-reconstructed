// Function: sub_A8B0B0
// Address: 0xa8b0b0
// Size: 0xd9
// Prototype: 

int __cdecl sub_A8B0B0(const __m128i *a1, int a2, __m128i *a3, int a4)
{
  int result; // eax
  __m128i v5; // xmm1
  __m128i v6; // xmm2
  const __m128i *v8; // esi
  __m128i *v9; // edi
  __m128i v10; // xmm4
  __m128i v11; // xmm5
  const __m128i *v12; // esi
  __m128i *v13; // edi
  __m128i v14; // xmm1
  __m128i v15; // xmm2
  const __m128i *v16; // esi
  __m128i v17; // xmm4
  __m128i *v18; // edi
  __m128i v19; // xmm5
  const __m128i *v20; // esi
  __m128i v21; // xmm1
  __m128i *v22; // edi
  __m128i v23; // xmm2

  result = a2;
  v5 = _mm_loadu_si128((const __m128i *)((char *)a1 + a2));
  v6 = _mm_loadu_si128((const __m128i *)((char *)a1 + 2 * a2));
  *a3 = _mm_loadu_si128(a1);
  v8 = (const __m128i *)((char *)a1 + 2 * a2 + a2);
  *(__m128i *)((char *)a3 + a4) = v5;
  *(__m128i *)((char *)a3 + 2 * a4) = v6;
  v9 = (__m128i *)((char *)a3 + 2 * a4 + a4);
  v10 = _mm_loadu_si128((const __m128i *)((char *)v8 + a2));
  v11 = _mm_loadu_si128((const __m128i *)((char *)v8 + 2 * a2));
  *v9 = _mm_loadu_si128(v8);
  v12 = (const __m128i *)((char *)v8 + 2 * result + result);
  *(__m128i *)((char *)v9 + a4) = v10;
  *(__m128i *)((char *)v9 + 2 * a4) = v11;
  v13 = (__m128i *)((char *)v9 + 2 * a4 + a4);
  v14 = _mm_loadu_si128((const __m128i *)((char *)v12 + a2));
  v15 = _mm_loadu_si128((const __m128i *)((char *)v12 + 2 * a2));
  *v13 = _mm_loadu_si128(v12);
  v16 = (const __m128i *)((char *)v12 + 2 * result + result);
  *(__m128i *)((char *)v13 + a4) = v14;
  *(__m128i *)((char *)v13 + 2 * a4) = v15;
  v17 = _mm_loadu_si128((const __m128i *)((char *)v16 + a2));
  v18 = (__m128i *)((char *)v13 + 2 * a4 + a4);
  v19 = _mm_loadu_si128((const __m128i *)((char *)v16 + 2 * a2));
  *v18 = _mm_loadu_si128(v16);
  v20 = (const __m128i *)((char *)v16 + 2 * result + result);
  *(__m128i *)((char *)v18 + a4) = v17;
  *(__m128i *)((char *)v18 + 2 * a4) = v19;
  v21 = _mm_loadu_si128((const __m128i *)((char *)v20 + a2));
  v22 = (__m128i *)((char *)v18 + 2 * a4 + a4);
  v23 = _mm_loadu_si128((const __m128i *)((char *)v20 + 2 * a2));
  *v22 = _mm_loadu_si128(v20);
  *(__m128i *)((char *)v22 + a4) = v21;
  *(__m128i *)((char *)v22 + 2 * a4) = v23;
  *(__m128i *)((char *)v22 + 2 * a4 + a4) = _mm_loadu_si128((const __m128i *)((char *)v20 + 2 * a2 + a2));
  return result;
}

