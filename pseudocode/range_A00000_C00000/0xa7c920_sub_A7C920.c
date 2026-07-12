// Function: sub_A7C920
// Address: 0xa7c920
// Size: 0x248
// Prototype: 

int __cdecl sub_A7C920(__m128i *a1, int a2, const __m128i *a3, const __m128i *a4, const __m128i *a5)
{
  __m128i si128; // xmm2
  int result; // eax
  __m128i v7; // xmm7
  __m128i v8; // xmm6
  __m128i v9; // xmm3
  __m128i v10; // xmm0
  __m128i v11; // xmm1
  __m128i v12; // xmm2
  __m128i v13; // xmm6
  __m128i v14; // xmm5
  __m128i v15; // xmm1
  __m128i v16; // xmm3
  __m128i v17; // xmm5
  __m128i v18; // xmm2
  __m128i v19; // xmm6
  __m128i v20; // xmm5
  __m128i v21; // xmm5
  __m128i v22; // xmm2
  __m128i v23; // xmm5
  __m128i v24; // xmm1
  __m128i v25; // xmm4
  __m128i v26; // xmm3
  __m128i v27; // xmm7
  __m128i v28; // xmm6
  __m128i v29; // xmm2
  __m128i v30; // xmm3
  __m128i v31; // xmm0
  __m128i v32; // xmm2
  __m128i v33; // xmm1
  __m128i v34; // xmm2
  __m128i v35; // xmm0
  __m128i v36; // xmm2
  __m128i v37; // xmm1
  __m128i v38; // xmm5
  __m128i v39; // xmm0
  __m128i v40; // xmm6
  __m128i v41; // xmm2
  __m128i v42; // xmm5
  __m128i v43; // xmm2
  __m128i v44; // xmm4
  __m128i v45; // xmm1
  __m128i v46; // [esp+0h] [ebp-B8h] BYREF
  __m128i v47[9]; // [esp+10h] [ebp-A8h] BYREF
  int *v48; // [esp+A0h] [ebp-18h]
  int v49; // [esp+B0h] [ebp-8h] BYREF

  v48 = &v49;
  si128 = _mm_load_si128((__m128i *)((char *)a1 + 2 * a2 + a2));
  result = -a2;
  v7 = _mm_load_si128(a4);
  v8 = _mm_load_si128((__m128i *)((char *)a1 + 2 * a2));
  v9 = _mm_load_si128((__m128i *)((char *)a1 + a2));
  v10 = _mm_load_si128(a1);
  v46 = _mm_or_si128(_mm_subs_epu8(v10, v9), _mm_subs_epu8(v9, v10));
  v11 = _mm_max_epu8(
          _mm_max_epu8(
            _mm_or_si128(_mm_subs_epu8(v8, si128), _mm_subs_epu8(si128, v8)),
            _mm_or_si128(_mm_subs_epu8(v9, v8), _mm_subs_epu8(v8, v9))),
          v46);
  v12 = _mm_load_si128((__m128i *)((char *)a1 - 4 * a2));
  v13 = _mm_load_si128((__m128i *)((char *)a1 - 2 * a2));
  v14 = _mm_load_si128((__m128i *)((char *)a1 + a2 + -4 * a2));
  v15 = _mm_max_epu8(
          _mm_max_epu8(
            _mm_max_epu8(_mm_max_epu8(v11, _mm_subs_epu8(v14, v12)), _mm_subs_epu8(v12, v14)),
            _mm_subs_epu8(v14, v13)),
          _mm_subs_epu8(v13, v14));
  v16 = _mm_load_si128((__m128i *)((char *)a1 + a2));
  v17 = _mm_load_si128((__m128i *)((char *)a1 - a2));
  v47[0] = _mm_or_si128(_mm_subs_epu8(v13, v17), _mm_subs_epu8(v17, v13));
  v18 = _mm_and_si128(_mm_or_si128(_mm_subs_epu8(v13, v16), _mm_subs_epu8(v16, v13)), (__m128i)xmmword_25D7000);
  v19 = v17;
  v20 = _mm_or_si128(_mm_subs_epu8(v17, v10), _mm_subs_epu8(v10, v17));
  v21 = _mm_adds_epu8(_mm_adds_epu8(v20, v20), _mm_srli_epi16(v18, 1u));
  v22 = _mm_load_si128(a5);
  v23 = _mm_subs_epu8(v21, _mm_load_si128(a3));
  v24 = _mm_cmpeq_epi8(_mm_or_si128(_mm_subs_epu8(_mm_max_epu8(v15, v47[0]), v7), v23), (__m128i)0LL);
  v25 = _mm_xor_si128(
          _mm_cmpeq_epi8(
            _mm_add_epi8(_mm_subs_epu8(_mm_load_si128(&v46), v22), _mm_subs_epu8(_mm_load_si128(v47), v22)),
            v23),
          (__m128i)-1LL);
  v26 = _mm_load_si128(xmmword_25D7010);
  v27 = _mm_xor_si128(_mm_load_si128((__m128i *)((char *)a1 + a2)), v26);
  v28 = _mm_xor_si128(v19, v26);
  v29 = _mm_and_si128(_mm_subs_epi8(_mm_xor_si128(_mm_load_si128((__m128i *)((char *)a1 - 2 * a2)), v26), v27), v25);
  v30 = _mm_xor_si128(v10, v26);
  v31 = _mm_subs_epi8(v30, v28);
  v32 = _mm_and_si128(v24, _mm_adds_epi8(_mm_adds_epi8(_mm_adds_epi8(v29, v31), v31), v31));
  v33 = _mm_adds_epi8(v32, (__m128i)xmmword_25D7040);
  v34 = _mm_adds_epi8(v32, (__m128i)xmmword_25D7030);
  v35 = _mm_unpacklo_epi8(v31, v33);
  v36 = _mm_packs_epi16(
          _mm_srai_epi16(_mm_unpacklo_epi8(v34, v34), 0xBu),
          _mm_srai_epi16(_mm_unpackhi_epi8(v23, v34), 0xBu));
  v37 = _mm_srai_epi16(_mm_unpackhi_epi8(v33, v33), 0xBu);
  v38 = _mm_srai_epi16(v35, 0xBu);
  v39 = _mm_packs_epi16(v38, v37);
  v40 = _mm_adds_epi8(v28, v36);
  v41 = _mm_load_si128((const __m128i *)&xmmword_25D7050);
  v42 = _mm_packs_epi16(_mm_srai_epi16(_mm_adds_epi16(v38, v41), 1u), _mm_srai_epi16(_mm_adds_epi16(v37, v41), 1u));
  v43 = _mm_load_si128(xmmword_25D7010);
  v44 = _mm_andnot_si128(v25, v42);
  v45 = _mm_xor_si128(_mm_adds_epi8(_mm_xor_si128(_mm_load_si128((__m128i *)((char *)a1 - 2 * a2)), v43), v44), v43);
  *(__m128i *)((char *)a1 + result) = _mm_xor_si128(v40, v43);
  *(__m128i *)((char *)a1 + 2 * result) = v45;
  *a1 = _mm_xor_si128(_mm_subs_epi8(v30, v39), v43);
  *(__m128i *)((char *)a1 + a2) = _mm_xor_si128(_mm_subs_epi8(v27, v44), v43);
  return result;
}

