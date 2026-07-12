// Function: sub_A83120
// Address: 0xa83120
// Size: 0x184
// Prototype: 

int __cdecl sub_A83120(const __m128i *a1, int a2, int a3, int a4, __m128i *a5)
{
  __m128i v6; // xmm0
  __m128i v7; // xmm2
  __m128i v8; // xmm1
  __m128i v9; // xmm0
  const __m128i *v10; // esi
  int v11; // edi
  __m128i v12; // xmm2
  __m128i v13; // xmm1
  __m128i v14; // xmm0
  __m128i v15; // xmm2
  __m128i v16; // xmm1
  __m128i v17; // xmm0
  __m128i v18; // xmm5
  const __m128i *v19; // esi
  int v20; // edi
  __m128i v21; // xmm1
  __m128i v22; // xmm0
  __m128i v23; // xmm2
  __m128i v24; // xmm1
  __m128i v25; // xmm0
  __m128i v26; // xmm5
  const __m128i *v27; // esi
  int v28; // edi
  __m128i v29; // xmm1
  __m128i v30; // xmm0
  __m128i v31; // xmm2
  __m128i v32; // xmm1
  __m128i v33; // xmm0
  __m128i v34; // xmm2

  v6 = _mm_loadl_epi64(a1);
  v7 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)a3), _mm_loadl_epi64((const __m128i *)(a3 + 8)));
  v8 = _mm_add_epi16(_mm_mpsadbw_epu8(v7, v6, 0), _mm_mpsadbw_epu8(v7, v6, 5));
  v9 = _mm_loadl_epi64((const __m128i *)((char *)a1 + a2));
  v10 = (const __m128i *)((char *)a1 + 2 * a2);
  v11 = a3 + 2 * a4;
  v12 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)(a3 + a4)), _mm_loadl_epi64((const __m128i *)(a3 + a4 + 8)));
  v13 = _mm_add_epi16(v8, _mm_add_epi16(_mm_mpsadbw_epu8(v12, v9, 0), _mm_mpsadbw_epu8(v12, v9, 5)));
  v14 = _mm_loadl_epi64(v10);
  v15 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v11), _mm_loadl_epi64((const __m128i *)(v11 + 8)));
  v16 = _mm_add_epi16(v13, _mm_add_epi16(_mm_mpsadbw_epu8(v15, v14, 0), _mm_mpsadbw_epu8(v15, v14, 5)));
  v17 = _mm_loadl_epi64((const __m128i *)((char *)v10 + a2));
  v18 = _mm_unpacklo_epi64(
          _mm_loadl_epi64((const __m128i *)(v11 + a4)),
          _mm_loadl_epi64((const __m128i *)(v11 + a4 + 8)));
  v19 = (const __m128i *)((char *)v10 + 2 * a2);
  v20 = v11 + 2 * a4;
  v21 = _mm_add_epi16(v16, _mm_add_epi16(_mm_mpsadbw_epu8(v18, v17, 0), _mm_mpsadbw_epu8(v18, v17, 5)));
  v22 = _mm_loadl_epi64(v19);
  v23 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v20), _mm_loadl_epi64((const __m128i *)(v20 + 8)));
  v24 = _mm_add_epi16(v21, _mm_add_epi16(_mm_mpsadbw_epu8(v23, v22, 0), _mm_mpsadbw_epu8(v23, v22, 5)));
  v25 = _mm_loadl_epi64((const __m128i *)((char *)v19 + a2));
  v26 = _mm_unpacklo_epi64(
          _mm_loadl_epi64((const __m128i *)(v20 + a4)),
          _mm_loadl_epi64((const __m128i *)(v20 + a4 + 8)));
  v27 = (const __m128i *)((char *)v19 + 2 * a2);
  v28 = v20 + 2 * a4;
  v29 = _mm_add_epi16(v24, _mm_add_epi16(_mm_mpsadbw_epu8(v26, v25, 0), _mm_mpsadbw_epu8(v26, v25, 5)));
  v30 = _mm_loadl_epi64(v27);
  v31 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v28), _mm_loadl_epi64((const __m128i *)(v28 + 8)));
  v32 = _mm_add_epi16(v29, _mm_add_epi16(_mm_mpsadbw_epu8(v31, v30, 0), _mm_mpsadbw_epu8(v31, v30, 5)));
  v33 = _mm_loadl_epi64((const __m128i *)((char *)v27 + a2));
  v34 = _mm_unpacklo_epi64(
          _mm_loadl_epi64((const __m128i *)(v28 + a4)),
          _mm_loadl_epi64((const __m128i *)(v28 + a4 + 8)));
  *a5 = _mm_add_epi16(v32, _mm_add_epi16(_mm_mpsadbw_epu8(v34, v33, 0), _mm_mpsadbw_epu8(v34, v33, 5)));
  return a2;
}

