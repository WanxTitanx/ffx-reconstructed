// Function: sub_A7FA8D
// Address: 0xa7fa8d
// Size: 0x1b5
// Prototype: 

int __cdecl sub_A7FA8D(const __m128i *a1, int a2, int a3, int a4, _DWORD *a5)
{
  __m128i si128; // xmm0
  __m128i v7; // xmm5
  __m128i v8; // xmm6
  __m128i v9; // xmm7
  __m128i v10; // xmm0
  const __m128i *v11; // esi
  int v12; // edi
  __m128i v13; // xmm5
  __m128i v14; // xmm6
  __m128i v15; // xmm7
  __m128i v16; // xmm0
  __m128i v17; // xmm5
  __m128i v18; // xmm6
  __m128i v19; // xmm7
  __m128i v20; // xmm0
  __m128i v21; // xmm1
  __m128i v22; // xmm2
  __m128i v23; // xmm3
  const __m128i *v24; // esi
  int v25; // edi
  __m128i v26; // xmm5
  __m128i v27; // xmm6
  __m128i v28; // xmm7
  __m128i v29; // xmm0
  __m128i v30; // xmm5
  __m128i v31; // xmm6
  __m128i v32; // xmm7
  __m128i v33; // xmm0
  __m128i v34; // xmm1
  __m128i v35; // xmm2
  __m128i v36; // xmm3
  const __m128i *v37; // esi
  int v38; // edi
  __m128i v39; // xmm5
  __m128i v40; // xmm6
  __m128i v41; // xmm7
  __m128i v42; // xmm0
  __m128i v43; // xmm5
  __m128i v44; // xmm6
  __m128i v45; // xmm7
  __m128i v46; // xmm0
  __m128i v47; // xmm5
  __m128i v48; // xmm6
  __m128i v49; // xmm7

  si128 = _mm_load_si128(a1);
  v7 = _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)a3), si128);
  v8 = _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(a3 + 1)), si128);
  v9 = _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(a3 + 2)), si128);
  v10 = _mm_load_si128((const __m128i *)((char *)a1 + a2));
  v11 = (const __m128i *)((char *)a1 + 2 * a2);
  v12 = a3 + 2 * a4;
  v13 = _mm_add_epi16(v7, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(a3 + a4)), v10));
  v14 = _mm_add_epi16(v8, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(a3 + a4 + 1)), v10));
  v15 = _mm_add_epi16(v9, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(a3 + a4 + 2)), v10));
  v16 = _mm_load_si128(v11);
  v17 = _mm_add_epi16(v13, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)v12), v16));
  v18 = _mm_add_epi16(v14, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v12 + 1)), v16));
  v19 = _mm_add_epi16(v15, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v12 + 2)), v16));
  v20 = _mm_load_si128((const __m128i *)((char *)v11 + a2));
  v21 = _mm_lddqu_si128((const __m128i *)(v12 + a4));
  v22 = _mm_lddqu_si128((const __m128i *)(v12 + a4 + 1));
  v23 = _mm_lddqu_si128((const __m128i *)(v12 + a4 + 2));
  v24 = (const __m128i *)((char *)v11 + 2 * a2);
  v25 = v12 + 2 * a4;
  v26 = _mm_add_epi16(v17, _mm_sad_epu8(v21, v20));
  v27 = _mm_add_epi16(v18, _mm_sad_epu8(v22, v20));
  v28 = _mm_add_epi16(v19, _mm_sad_epu8(v23, v20));
  v29 = _mm_load_si128(v24);
  v30 = _mm_add_epi16(v26, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)v25), v29));
  v31 = _mm_add_epi16(v27, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v25 + 1)), v29));
  v32 = _mm_add_epi16(v28, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v25 + 2)), v29));
  v33 = _mm_load_si128((const __m128i *)((char *)v24 + a2));
  v34 = _mm_lddqu_si128((const __m128i *)(v25 + a4));
  v35 = _mm_lddqu_si128((const __m128i *)(v25 + a4 + 1));
  v36 = _mm_lddqu_si128((const __m128i *)(v25 + a4 + 2));
  v37 = (const __m128i *)((char *)v24 + 2 * a2);
  v38 = v25 + 2 * a4;
  v39 = _mm_add_epi16(v30, _mm_sad_epu8(v34, v33));
  v40 = _mm_add_epi16(v31, _mm_sad_epu8(v35, v33));
  v41 = _mm_add_epi16(v32, _mm_sad_epu8(v36, v33));
  v42 = _mm_load_si128(v37);
  v43 = _mm_add_epi16(v39, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)v38), v42));
  v44 = _mm_add_epi16(v40, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v38 + 1)), v42));
  v45 = _mm_add_epi16(v41, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v38 + 2)), v42));
  v46 = _mm_load_si128((const __m128i *)((char *)v37 + a2));
  v47 = _mm_add_epi16(v43, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v38 + a4)), v46));
  v48 = _mm_add_epi16(v44, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v38 + a4 + 1)), v46));
  v49 = _mm_add_epi16(v45, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v38 + a4 + 2)), v46));
  *a5 = _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v47), _mm_srli_si128(v47, 8)));
  a5[1] = _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v48), _mm_srli_si128(v48, 8)));
  a5[2] = _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v49), _mm_srli_si128(v49, 8)));
  return a2;
}

