// Function: sub_A8D107
// Address: 0xa8d107
// Size: 0x28e
// Prototype: 

const __m128i *__cdecl sub_A8D107(const __m128i *a1, __m128i *a2, __m128i *a3, int a4)
{
  __m128i si128; // xmm0
  __m128i v6; // xmm2
  __m128i v7; // xmm1
  __m128i v8; // xmm3
  __m128i v9; // xmm1
  __m128i v10; // xmm3
  __m128i v11; // xmm4
  __m128i v12; // xmm0
  __m128i v13; // xmm1
  __m128i v14; // xmm4
  __m128i v15; // xmm2
  __m128i v16; // xmm3
  __m128i v17; // xmm0
  __m128i v18; // xmm7
  __m128i v19; // xmm3
  __m128i v20; // xmm6
  __m128i v21; // xmm2
  __m128i v22; // xmm4
  __m128i v23; // xmm0
  __m128i v24; // xmm6
  __m128i v25; // xmm5
  __m128i v26; // xmm4
  __m128i v27; // xmm5
  __m128i v28; // xmm1
  __m128i v29; // xmm6
  __m128i v30; // xmm7
  __m128i v31; // xmm6
  __m128i v32; // xmm5
  __m128i v33; // xmm2
  __m128i v34; // xmm5
  __m128i v35; // xmm7
  __m128i v36; // xmm0
  __m128i v37; // xmm2
  __m128i v38; // xmm1
  __m128i v39; // xmm3
  __m128i v40; // xmm0
  __m128i v41; // xmm2
  __m128i v42; // xmm7
  __m128i v43; // xmm3
  __m128i v44; // xmm0
  __m128i v45; // xmm6
  __m128i v46; // xmm2
  __m128i v47; // xmm4
  __m128i v48; // xmm0
  __m128i v49; // xmm6
  __m128i v50; // xmm7
  __m128i v51; // xmm5
  __m128i v52; // xmm4
  __m128i v53; // xmm5
  __m128i v54; // xmm1
  __m128i v55; // xmm6
  __m128i v56; // xmm7
  __m128i v57; // xmm6
  __m128i v58; // xmm5
  __m128i v59; // xmm2
  __m128i v60; // xmm5
  __m128i v61; // xmm7

  si128 = _mm_load_si128(a1);
  v6 = _mm_load_si128(a1 + 1);
  v7 = _mm_load_si128(a1 + 2);
  v8 = _mm_load_si128(a1 + 3);
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  v9 = _mm_mullo_epi16(v7, *a2);
  v10 = _mm_mullo_epi16(v8, a2[1]);
  v11 = _mm_mullo_epi16(si128, *a2);
  v12 = _mm_unpacklo_epi32(v11, v9);
  v13 = _mm_shuffle_epi32(_mm_unpackhi_epi32(v11, v9), 216);
  v14 = _mm_mullo_epi16(v6, a2[1]);
  v15 = _mm_shuffle_epi32(_mm_unpacklo_epi32(v14, v10), 216);
  v16 = _mm_shuffle_epi32(_mm_unpackhi_epi32(v14, v10), 216);
  v17 = _mm_sub_epi16(_mm_shuffle_epi32(v12, 216), v15);
  v18 = _mm_sub_epi16(
          _mm_add_epi16(_mm_mulhi_epi16(v16, (__m128i)xmmword_25D79F0), v16),
          _mm_add_epi16(_mm_mulhi_epi16(v13, (__m128i)xmmword_25D79E0), v13));
  v19 = _mm_add_epi16(
          _mm_add_epi16(_mm_mulhi_epi16(v16, (__m128i)xmmword_25D79E0), v16),
          _mm_add_epi16(_mm_mulhi_epi16(v13, (__m128i)xmmword_25D79F0), v13));
  v20 = _mm_add_epi16(_mm_add_epi16(v15, v15), v17);
  v21 = _mm_add_epi16(v20, v19);
  v22 = _mm_add_epi16(v17, v18);
  v23 = _mm_sub_epi16(v17, v18);
  v24 = _mm_sub_epi16(v20, v19);
  v25 = v22;
  v26 = _mm_unpacklo_epi16(v22, v24);
  v27 = _mm_unpackhi_epi16(v25, v24);
  v28 = _mm_unpacklo_epi16(v21, v23);
  v29 = _mm_unpackhi_epi16(v21, v23);
  v30 = _mm_unpacklo_epi32(v29, v27);
  v31 = _mm_unpackhi_epi32(v29, v27);
  v32 = _mm_unpacklo_epi32(v28, v26);
  v33 = _mm_unpacklo_epi32(v32, v30);
  v34 = _mm_unpackhi_epi32(v32, v30);
  v35 = _mm_unpackhi_epi32(v28, v26);
  v36 = _mm_shuffle_epi32(v33, 216);
  v37 = _mm_shuffle_epi32(_mm_unpacklo_epi32(v35, v31), 216);
  v38 = _mm_shuffle_epi32(v34, 216);
  v39 = _mm_shuffle_epi32(_mm_unpackhi_epi32(v35, v31), 216);
  v40 = _mm_sub_epi16(v36, v37);
  v41 = _mm_add_epi16(_mm_add_epi16(v37, v37), v40);
  v42 = _mm_sub_epi16(
          _mm_add_epi16(_mm_mulhi_epi16(v39, (__m128i)xmmword_25D79F0), v39),
          _mm_add_epi16(_mm_mulhi_epi16(v38, (__m128i)xmmword_25D79E0), v38));
  v43 = _mm_add_epi16(
          _mm_add_epi16(_mm_mulhi_epi16(v39, (__m128i)xmmword_25D79E0), v39),
          _mm_add_epi16(_mm_mulhi_epi16(v38, (__m128i)xmmword_25D79F0), v38));
  v44 = _mm_add_epi16(v40, (__m128i)xmmword_25D79D0);
  v45 = _mm_add_epi16(v41, (__m128i)xmmword_25D79D0);
  v46 = _mm_add_epi16(v45, v43);
  v47 = _mm_add_epi16(v44, v42);
  v48 = _mm_srai_epi16(_mm_sub_epi16(v44, v42), 3u);
  v49 = _mm_srai_epi16(_mm_sub_epi16(v45, v43), 3u);
  v50 = _mm_srai_epi16(v46, 3u);
  v51 = _mm_srai_epi16(v47, 3u);
  v52 = _mm_unpacklo_epi16(v51, v49);
  v53 = _mm_unpackhi_epi16(v51, v49);
  v54 = _mm_unpacklo_epi16(v50, v48);
  v55 = _mm_unpackhi_epi16(v50, v48);
  v56 = _mm_unpacklo_epi32(v55, v53);
  v57 = _mm_unpackhi_epi32(v55, v53);
  v58 = _mm_unpacklo_epi32(v54, v52);
  v59 = _mm_unpacklo_epi32(v58, v56);
  v60 = _mm_unpackhi_epi32(v58, v56);
  v61 = _mm_unpackhi_epi32(v54, v52);
  v48.m128i_i64[0] = _mm_packus_epi16(
                       _mm_add_epi16(_mm_shuffle_epi32(v59, 216), _mm_unpacklo_epi8(_mm_loadl_epi64(a3), (__m128i)0LL)),
                       (__m128i)0LL).m128i_u64[0];
  v54.m128i_i64[0] = _mm_packus_epi16(
                       _mm_add_epi16(
                         _mm_shuffle_epi32(v60, 216),
                         _mm_unpacklo_epi8(_mm_loadl_epi64((__m128i *)((char *)a3 + a4)), (__m128i)0LL)),
                       (__m128i)0LL).m128i_u64[0];
  v59.m128i_i64[0] = _mm_packus_epi16(
                       _mm_add_epi16(
                         _mm_shuffle_epi32(_mm_unpacklo_epi32(v61, v57), 216),
                         _mm_unpacklo_epi8(_mm_loadl_epi64((__m128i *)((char *)a3 + 2 * a4)), (__m128i)0LL)),
                       (__m128i)0LL).m128i_u64[0];
  v43.m128i_i64[0] = _mm_packus_epi16(
                       _mm_add_epi16(
                         _mm_shuffle_epi32(_mm_unpackhi_epi32(v61, v57), 216),
                         _mm_unpacklo_epi8(_mm_loadl_epi64((__m128i *)((char *)a3 + 3 * a4)), (__m128i)0LL)),
                       (__m128i)0LL).m128i_u64[0];
  a3->m128i_i64[0] = v48.m128i_i64[0];
  *(__int64 *)((char *)a3->m128i_i64 + a4) = v54.m128i_i64[0];
  *(__int64 *)((char *)a3->m128i_i64 + 2 * a4) = v59.m128i_i64[0];
  *(__int64 *)((char *)a3->m128i_i64 + 3 * a4) = v43.m128i_i64[0];
  return a1;
}

