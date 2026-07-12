// Function: sub_A805D8
// Address: 0xa805d8
// Size: 0x240
// Prototype: 

int __cdecl sub_A805D8(const __m128i *a1, int a2, const __m128i **a3, int a4)
{
  const __m128i *v4; // edx
  const __m128i *v5; // edi
  const __m128i *v7; // et0
  __m128i si128; // xmm0
  __m128i v9; // xmm4
  __m128i v10; // xmm5
  __m128i v11; // xmm6
  __m128i v12; // xmm7
  __m128i v13; // xmm0
  __m128i v14; // xmm4
  __m128i v15; // xmm1
  __m128i v16; // xmm5
  __m128i v17; // xmm6
  const __m128i *v18; // esi
  const __m128i *v19; // ecx
  const __m128i *v20; // edx
  const __m128i *v21; // ebx
  const __m128i *v22; // edi
  __m128i v23; // xmm7
  __m128i v24; // xmm0
  __m128i v25; // xmm4
  __m128i v26; // xmm5
  __m128i v27; // xmm6
  __m128i v28; // xmm7
  __m128i v29; // xmm0
  __m128i v30; // xmm4
  __m128i v31; // xmm1
  __m128i v32; // xmm5
  __m128i v33; // xmm6
  const __m128i *v34; // esi
  const __m128i *v35; // ecx
  const __m128i *v36; // edx
  const __m128i *v37; // ebx
  const __m128i *v38; // edi
  __m128i v39; // xmm7
  __m128i v40; // xmm0
  __m128i v41; // xmm4
  __m128i v42; // xmm5
  __m128i v43; // xmm6
  __m128i v44; // xmm7
  __m128i v45; // xmm0
  __m128i v46; // xmm4
  __m128i v47; // xmm1
  __m128i v48; // xmm5
  __m128i v49; // xmm6
  const __m128i *v50; // esi
  const __m128i *v51; // ecx
  const __m128i *v52; // edx
  const __m128i *v53; // ebx
  const __m128i *v54; // edi
  __m128i v55; // xmm7
  __m128i v56; // xmm0
  __m128i v57; // xmm4
  __m128i v58; // xmm5
  __m128i v59; // xmm6
  __m128i v60; // xmm7
  __m128i v61; // xmm0
  __m128i v62; // xmm4
  __m128i v63; // xmm5
  __m128i v64; // xmm6
  __m128i v65; // xmm7
  _DWORD *v66; // ecx
  int v67; // [esp+0h] [ebp-10h]

  v4 = a3[1];
  v5 = a3[3];
  v7 = a3[2];
  si128 = _mm_load_si128(a1);
  v9 = _mm_sad_epu8(_mm_lddqu_si128(*a3), si128);
  v10 = _mm_sad_epu8(_mm_lddqu_si128(v4), si128);
  v11 = _mm_sad_epu8(_mm_lddqu_si128(v7), si128);
  v12 = _mm_sad_epu8(_mm_lddqu_si128(v5), si128);
  v13 = _mm_load_si128((const __m128i *)((char *)a1 + a2));
  v14 = _mm_add_epi16(v9, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)*a3 + a4)), v13));
  v15 = _mm_lddqu_si128((const __m128i *)((char *)v5 + a4));
  v16 = _mm_add_epi16(v10, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v4 + a4)), v13));
  v17 = _mm_add_epi16(v11, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v7 + a4)), v13));
  v18 = (const __m128i *)((char *)a1 + 2 * a2);
  v19 = (const __m128i *)((char *)*a3 + 2 * a4);
  v20 = (const __m128i *)((char *)v4 + 2 * a4);
  v21 = (const __m128i *)((char *)v7 + 2 * a4);
  v22 = (const __m128i *)((char *)v5 + 2 * a4);
  v23 = _mm_add_epi16(v12, _mm_sad_epu8(v15, v13));
  v24 = _mm_load_si128(v18);
  v25 = _mm_add_epi16(v14, _mm_sad_epu8(_mm_lddqu_si128(v19), v24));
  v26 = _mm_add_epi16(v16, _mm_sad_epu8(_mm_lddqu_si128(v20), v24));
  v27 = _mm_add_epi16(v17, _mm_sad_epu8(_mm_lddqu_si128(v21), v24));
  v28 = _mm_add_epi16(v23, _mm_sad_epu8(_mm_lddqu_si128(v22), v24));
  v29 = _mm_load_si128((const __m128i *)((char *)v18 + a2));
  v30 = _mm_add_epi16(v25, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v19 + a4)), v29));
  v31 = _mm_lddqu_si128((const __m128i *)((char *)v22 + a4));
  v32 = _mm_add_epi16(v26, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v20 + a4)), v29));
  v33 = _mm_add_epi16(v27, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v21 + a4)), v29));
  v34 = (const __m128i *)((char *)v18 + 2 * a2);
  v35 = (const __m128i *)((char *)v19 + 2 * a4);
  v36 = (const __m128i *)((char *)v20 + 2 * a4);
  v37 = (const __m128i *)((char *)v21 + 2 * a4);
  v38 = (const __m128i *)((char *)v22 + 2 * a4);
  v39 = _mm_add_epi16(v28, _mm_sad_epu8(v31, v29));
  v40 = _mm_load_si128(v34);
  v41 = _mm_add_epi16(v30, _mm_sad_epu8(_mm_lddqu_si128(v35), v40));
  v42 = _mm_add_epi16(v32, _mm_sad_epu8(_mm_lddqu_si128(v36), v40));
  v43 = _mm_add_epi16(v33, _mm_sad_epu8(_mm_lddqu_si128(v37), v40));
  v44 = _mm_add_epi16(v39, _mm_sad_epu8(_mm_lddqu_si128(v38), v40));
  v45 = _mm_load_si128((const __m128i *)((char *)v34 + a2));
  v46 = _mm_add_epi16(v41, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v35 + a4)), v45));
  v47 = _mm_lddqu_si128((const __m128i *)((char *)v38 + a4));
  v48 = _mm_add_epi16(v42, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v36 + a4)), v45));
  v49 = _mm_add_epi16(v43, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v37 + a4)), v45));
  v50 = (const __m128i *)((char *)v34 + 2 * a2);
  v51 = (const __m128i *)((char *)v35 + 2 * a4);
  v52 = (const __m128i *)((char *)v36 + 2 * a4);
  v53 = (const __m128i *)((char *)v37 + 2 * a4);
  v54 = (const __m128i *)((char *)v38 + 2 * a4);
  v55 = _mm_add_epi16(v44, _mm_sad_epu8(v47, v45));
  v56 = _mm_load_si128(v50);
  v57 = _mm_add_epi16(v46, _mm_sad_epu8(_mm_lddqu_si128(v51), v56));
  v58 = _mm_add_epi16(v48, _mm_sad_epu8(_mm_lddqu_si128(v52), v56));
  v59 = _mm_add_epi16(v49, _mm_sad_epu8(_mm_lddqu_si128(v53), v56));
  v60 = _mm_add_epi16(v55, _mm_sad_epu8(_mm_lddqu_si128(v54), v56));
  v61 = _mm_load_si128((const __m128i *)((char *)v50 + a2));
  v62 = _mm_add_epi16(v57, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v51 + a4)), v61));
  v63 = _mm_add_epi16(v58, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v52 + a4)), v61));
  v64 = _mm_add_epi16(v59, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v53 + a4)), v61));
  v65 = _mm_add_epi16(v60, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v54 + a4)), v61));
  v66 = *(_DWORD **)(v67 + 24);
  *v66 = _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v62), _mm_srli_si128(v62, 8)));
  v66[1] = _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v63), _mm_srli_si128(v63, 8)));
  v66[2] = _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v64), _mm_srli_si128(v64, 8)));
  v66[3] = _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v65), _mm_srli_si128(v65, 8)));
  return a2;
}

