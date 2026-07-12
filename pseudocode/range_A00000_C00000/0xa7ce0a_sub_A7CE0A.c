// Function: sub_A7CE0A
// Address: 0xa7ce0a
// Size: 0x2ec
// Prototype: 

int __cdecl sub_A7CE0A(__m128i *a1, int a2, const __m128i *a3, const __m128i *a4, const __m128i *a5)
{
  __m128i *v5; // edi
  __m128i si128; // xmm2
  int result; // eax
  __m128i v8; // xmm7
  __m128i v9; // xmm6
  __m128i v10; // xmm3
  __m128i v11; // xmm0
  __m128i v12; // xmm1
  __m128i v13; // xmm2
  __m128i v14; // xmm6
  __m128i v15; // xmm5
  __m128i v16; // xmm1
  __m128i v17; // xmm3
  __m128i v18; // xmm5
  __m128i v19; // xmm2
  __m128i v20; // xmm6
  __m128i v21; // xmm5
  __m128i v22; // xmm5
  __m128i v23; // xmm2
  __m128i v24; // xmm5
  __m128i v25; // xmm1
  __m128i v26; // xmm4
  __m128i v27; // xmm3
  __m128i v28; // xmm7
  __m128i v29; // xmm6
  __m128i v30; // xmm2
  __m128i v31; // xmm3
  __m128i v32; // xmm0
  __m128i v33; // xmm1
  __m128i v34; // xmm2
  __m128i v35; // xmm4
  __m128i v36; // xmm0
  __m128i v37; // xmm1
  __m128i v38; // xmm4
  __m128i v39; // xmm5
  __m128i v40; // xmm2
  __m128i v41; // xmm0
  __m128i v42; // xmm6
  __m128i v43; // xmm3
  __m128i v44; // xmm7
  __m128i v45; // xmm4
  __m128i v46; // xmm2
  __m128i v47; // xmm0
  __m128i v48; // xmm1
  __m128i v49; // xmm5
  __m128i v50; // xmm2
  __m128i v51; // xmm0
  __m128i v52; // xmm5
  __m128i v53; // xmm2
  __m128i v54; // xmm7
  __m128i v55; // xmm1
  __m128i v56; // xmm4
  __m128i v57; // xmm2
  __m128i v58; // [esp+0h] [ebp-B8h] BYREF
  __m128i v59[9]; // [esp+10h] [ebp-A8h] BYREF
  int *v60; // [esp+A0h] [ebp-18h]
  int v61; // [esp+B0h] [ebp-8h] BYREF

  v60 = &v61;
  v5 = (__m128i *)((char *)a1 + a2);
  si128 = _mm_load_si128((__m128i *)((char *)a1 + 2 * a2 + a2));
  result = -a2;
  v8 = _mm_load_si128(a4);
  v9 = _mm_load_si128((__m128i *)((char *)a1 + 2 * a2));
  v10 = _mm_load_si128((__m128i *)((char *)a1 + a2));
  v11 = _mm_load_si128(a1);
  v58 = _mm_or_si128(_mm_subs_epu8(v11, v10), _mm_subs_epu8(v10, v11));
  v12 = _mm_max_epu8(
          _mm_max_epu8(
            _mm_or_si128(_mm_subs_epu8(v9, si128), _mm_subs_epu8(si128, v9)),
            _mm_or_si128(_mm_subs_epu8(v10, v9), _mm_subs_epu8(v9, v10))),
          v58);
  v13 = _mm_load_si128((__m128i *)((char *)a1 - 4 * a2));
  v14 = _mm_load_si128((__m128i *)((char *)a1 - 2 * a2));
  v15 = _mm_load_si128((__m128i *)((char *)a1 + a2 + -4 * a2));
  v16 = _mm_max_epu8(
          _mm_max_epu8(
            _mm_max_epu8(_mm_max_epu8(v12, _mm_subs_epu8(v15, v13)), _mm_subs_epu8(v13, v15)),
            _mm_subs_epu8(v15, v14)),
          _mm_subs_epu8(v14, v15));
  v17 = _mm_load_si128((__m128i *)((char *)a1 + a2));
  v18 = _mm_load_si128((__m128i *)((char *)a1 - a2));
  v59[0] = _mm_or_si128(_mm_subs_epu8(v14, v18), _mm_subs_epu8(v18, v14));
  v19 = _mm_and_si128(_mm_or_si128(_mm_subs_epu8(v14, v17), _mm_subs_epu8(v17, v14)), (__m128i)xmmword_25D7000);
  v20 = v18;
  v21 = _mm_or_si128(_mm_subs_epu8(v18, v11), _mm_subs_epu8(v11, v18));
  v22 = _mm_adds_epu8(_mm_adds_epu8(v21, v21), _mm_srli_epi16(v19, 1u));
  v23 = _mm_load_si128(a5);
  v24 = _mm_subs_epu8(v22, _mm_load_si128(a3));
  v25 = _mm_cmpeq_epi8(_mm_or_si128(_mm_subs_epu8(_mm_max_epu8(v16, v59[0]), v8), v24), (__m128i)0LL);
  v26 = _mm_xor_si128(
          _mm_cmpeq_epi8(
            _mm_add_epi8(_mm_subs_epu8(_mm_load_si128(&v58), v23), _mm_subs_epu8(_mm_load_si128(v59), v23)),
            v24),
          (__m128i)-1LL);
  v27 = _mm_load_si128(xmmword_25D7010);
  v28 = _mm_xor_si128(_mm_load_si128((__m128i *)((char *)a1 + a2)), v27);
  v29 = _mm_xor_si128(v20, v27);
  v30 = _mm_subs_epi8(_mm_xor_si128(_mm_load_si128((__m128i *)((char *)a1 - 2 * a2)), v27), v28);
  v31 = _mm_xor_si128(v11, v27);
  v32 = _mm_subs_epi8(v31, v29);
  v33 = _mm_and_si128(v25, _mm_adds_epi8(_mm_adds_epi8(_mm_adds_epi8(v30, v32), v32), v32));
  v34 = _mm_and_si128(v33, v26);
  v35 = _mm_andnot_si128(v26, v33);
  v36 = _mm_unpacklo_epi8((__m128i)0LL, v35);
  v37 = _mm_unpackhi_epi8((__m128i)0LL, v35);
  v38 = _mm_load_si128((const __m128i *)&xmmword_25D7060);
  v39 = _mm_adds_epi8(v34, (__m128i)xmmword_25D7030);
  v40 = _mm_adds_epi8(v34, (__m128i)xmmword_25D7040);
  v41 = _mm_mulhi_epi16(v36, v38);
  v42 = _mm_adds_epi8(
          v29,
          _mm_packs_epi16(
            _mm_srai_epi16(_mm_unpacklo_epi8(v39, v39), 0xBu),
            _mm_srai_epi16(_mm_unpackhi_epi8(v28, v39), 0xBu)));
  v43 = _mm_subs_epi8(
          v31,
          _mm_packs_epi16(
            _mm_srai_epi16(_mm_unpacklo_epi8(v40, v40), 0xBu),
            _mm_srai_epi16(_mm_unpackhi_epi8(v38, v40), 0xBu)));
  v44 = _mm_mulhi_epi16(v37, v38);
  v45 = _mm_load_si128((const __m128i *)&xmmword_25D7070);
  v46 = v41;
  v47 = _mm_add_epi16(v41, v45);
  v48 = _mm_add_epi16(v44, v45);
  v49 = _mm_add_epi16(_mm_add_epi16(v46, v46), v47);
  v50 = _mm_add_epi16(v46, v47);
  v51 = _mm_packs_epi16(_mm_srai_epi16(v47, 7u), _mm_srai_epi16(v48, 7u));
  v52 = _mm_packs_epi16(_mm_srai_epi16(v49, 7u), _mm_srai_epi16(_mm_add_epi16(_mm_add_epi16(v44, v44), v48), 7u));
  v53 = _mm_packs_epi16(_mm_srai_epi16(v50, 7u), _mm_srai_epi16(_mm_add_epi16(v44, v48), 7u));
  v54 = _mm_load_si128(xmmword_25D7010);
  v55 = _mm_subs_epi8(_mm_xor_si128(_mm_load_si128((__m128i *)((char *)a1 + a2)), v54), v53);
  v56 = _mm_adds_epi8(_mm_xor_si128(_mm_load_si128((__m128i *)((char *)a1 - 2 * a2)), v54), v53);
  v57 = _mm_xor_si128(
          _mm_adds_epi8(_mm_xor_si128(_mm_load_si128((__m128i *)((char *)a1 + a2 + -4 * a2)), v54), v51),
          v54);
  *(__m128i *)((char *)a1 + a2 + a2) = _mm_xor_si128(
                                         _mm_subs_epi8(
                                           _mm_xor_si128(_mm_load_si128((__m128i *)((char *)a1 + a2 + a2)), v54),
                                           v51),
                                         v54);
  *v5 = _mm_xor_si128(v55, v54);
  *a1 = _mm_xor_si128(_mm_subs_epi8(v43, v52), v54);
  *(__m128i *)((char *)a1 + result) = _mm_xor_si128(_mm_adds_epi8(v42, v52), v54);
  *(__m128i *)((char *)a1 + 2 * result) = _mm_xor_si128(v56, v54);
  *(__m128i *)((char *)v5 + 4 * result) = v57;
  return result;
}

