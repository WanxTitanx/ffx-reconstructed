// Function: sub_A82E68
// Address: 0xa82e68
// Size: 0x2b8
// Prototype: 

int __cdecl sub_A82E68(const __m128i *a1, int a2, int a3, int a4, __m128i *a5)
{
  __m128i si128; // xmm0
  __m128i v7; // xmm3
  __m128i v8; // xmm2
  __m128i v9; // xmm1
  __m128i v10; // xmm2
  __m128i v11; // xmm0
  __m128i v12; // xmm4
  __m128i v13; // xmm1
  __m128i v14; // xmm0
  __m128i v15; // xmm3
  const __m128i *v16; // esi
  int v17; // edi
  __m128i v18; // xmm2
  __m128i v19; // xmm5
  __m128i v20; // xmm2
  __m128i v21; // xmm0
  __m128i v22; // xmm4
  __m128i v23; // xmm1
  __m128i v24; // xmm0
  __m128i v25; // xmm3
  __m128i v26; // xmm2
  __m128i v27; // xmm5
  __m128i v28; // xmm2
  __m128i v29; // xmm0
  __m128i v30; // xmm4
  __m128i v31; // xmm1
  __m128i v32; // xmm0
  __m128i v33; // xmm3
  __m128i v34; // xmm5
  __m128i v35; // xmm3
  const __m128i *v36; // esi
  int v37; // edi
  __m128i v38; // xmm2
  __m128i v39; // xmm5
  __m128i v40; // xmm2
  __m128i v41; // xmm0
  __m128i v42; // xmm1
  __m128i v43; // xmm0
  __m128i v44; // xmm3
  __m128i v45; // xmm2
  __m128i v46; // xmm5
  __m128i v47; // xmm2
  __m128i v48; // xmm0
  __m128i v49; // xmm4
  __m128i v50; // xmm1
  __m128i v51; // xmm0
  __m128i v52; // xmm3
  __m128i v53; // xmm5
  __m128i v54; // xmm3
  const __m128i *v55; // esi
  int v56; // edi
  __m128i v57; // xmm2
  __m128i v58; // xmm5
  __m128i v59; // xmm2
  __m128i v60; // xmm0
  __m128i v61; // xmm1
  __m128i v62; // xmm0
  __m128i v63; // xmm3
  __m128i v64; // xmm2
  __m128i v65; // xmm5
  __m128i v66; // xmm2
  __m128i v67; // xmm0
  __m128i v68; // xmm4
  __m128i v69; // xmm1
  __m128i v70; // xmm0
  __m128i v71; // xmm3
  __m128i v72; // xmm2
  __m128i v73; // xmm5
  __m128i v74; // xmm2
  __m128i v75; // xmm0
  __m128i v76; // xmm4

  si128 = _mm_load_si128(a1);
  v7 = _mm_loadl_epi64((const __m128i *)(a3 + 8));
  v8 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)a3), v7);
  v9 = _mm_mpsadbw_epu8(v8, si128, 0);
  v10 = _mm_mpsadbw_epu8(v8, si128, 5);
  v11 = _mm_srli_si128(si128, 8);
  v12 = _mm_unpacklo_epi64(v7, _mm_loadl_epi64((const __m128i *)(a3 + 16)));
  v13 = _mm_add_epi16(
          _mm_add_epi16(_mm_add_epi16(v9, v10), _mm_mpsadbw_epu8(v12, v11, 0)),
          _mm_mpsadbw_epu8(v12, v11, 5));
  v14 = _mm_load_si128((const __m128i *)((char *)a1 + a2));
  v15 = _mm_loadl_epi64((const __m128i *)(a3 + a4 + 8));
  v16 = (const __m128i *)((char *)a1 + 2 * a2);
  v17 = a3 + 2 * a4;
  v18 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)(a3 + a4)), v15);
  v19 = _mm_mpsadbw_epu8(v18, v14, 0);
  v20 = _mm_mpsadbw_epu8(v18, v14, 5);
  v21 = _mm_srli_si128(v14, 8);
  v22 = _mm_unpacklo_epi64(v15, _mm_loadl_epi64((const __m128i *)(a3 + a4 + 16)));
  v23 = _mm_add_epi16(
          v13,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v19, v20), _mm_mpsadbw_epu8(v22, v21, 0)),
            _mm_mpsadbw_epu8(v22, v21, 5)));
  v24 = _mm_load_si128(v16);
  v25 = _mm_loadl_epi64((const __m128i *)(v17 + 8));
  v26 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v17), v25);
  v27 = _mm_mpsadbw_epu8(v26, v24, 0);
  v28 = _mm_mpsadbw_epu8(v26, v24, 5);
  v29 = _mm_srli_si128(v24, 8);
  v30 = _mm_unpacklo_epi64(v25, _mm_loadl_epi64((const __m128i *)(v17 + 16)));
  v31 = _mm_add_epi16(
          v23,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v27, v28), _mm_mpsadbw_epu8(v30, v29, 0)),
            _mm_mpsadbw_epu8(v30, v29, 5)));
  v32 = _mm_load_si128((const __m128i *)((char *)v16 + a2));
  v33 = _mm_loadl_epi64((const __m128i *)(v17 + a4 + 8));
  v34 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)(v17 + a4)), v33);
  v35 = _mm_unpacklo_epi64(v33, _mm_loadl_epi64((const __m128i *)(v17 + a4 + 16)));
  v36 = (const __m128i *)((char *)v16 + 2 * a2);
  v37 = v17 + 2 * a4;
  v38 = v34;
  v39 = _mm_mpsadbw_epu8(v34, v32, 0);
  v40 = _mm_mpsadbw_epu8(v38, v32, 5);
  v41 = _mm_srli_si128(v32, 8);
  v42 = _mm_add_epi16(
          v31,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v39, v40), _mm_mpsadbw_epu8(v35, v41, 0)),
            _mm_mpsadbw_epu8(v35, v41, 5)));
  v43 = _mm_load_si128(v36);
  v44 = _mm_loadl_epi64((const __m128i *)(v37 + 8));
  v45 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v37), v44);
  v46 = _mm_mpsadbw_epu8(v45, v43, 0);
  v47 = _mm_mpsadbw_epu8(v45, v43, 5);
  v48 = _mm_srli_si128(v43, 8);
  v49 = _mm_unpacklo_epi64(v44, _mm_loadl_epi64((const __m128i *)(v37 + 16)));
  v50 = _mm_add_epi16(
          v42,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v46, v47), _mm_mpsadbw_epu8(v49, v48, 0)),
            _mm_mpsadbw_epu8(v49, v48, 5)));
  v51 = _mm_load_si128((const __m128i *)((char *)v36 + a2));
  v52 = _mm_loadl_epi64((const __m128i *)(v37 + a4 + 8));
  v53 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)(v37 + a4)), v52);
  v54 = _mm_unpacklo_epi64(v52, _mm_loadl_epi64((const __m128i *)(v37 + a4 + 16)));
  v55 = (const __m128i *)((char *)v36 + 2 * a2);
  v56 = v37 + 2 * a4;
  v57 = v53;
  v58 = _mm_mpsadbw_epu8(v53, v51, 0);
  v59 = _mm_mpsadbw_epu8(v57, v51, 5);
  v60 = _mm_srli_si128(v51, 8);
  v61 = _mm_add_epi16(
          v50,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v58, v59), _mm_mpsadbw_epu8(v54, v60, 0)),
            _mm_mpsadbw_epu8(v54, v60, 5)));
  v62 = _mm_load_si128(v55);
  v63 = _mm_loadl_epi64((const __m128i *)(v56 + 8));
  v64 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v56), v63);
  v65 = _mm_mpsadbw_epu8(v64, v62, 0);
  v66 = _mm_mpsadbw_epu8(v64, v62, 5);
  v67 = _mm_srli_si128(v62, 8);
  v68 = _mm_unpacklo_epi64(v63, _mm_loadl_epi64((const __m128i *)(v56 + 16)));
  v69 = _mm_add_epi16(
          v61,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v65, v66), _mm_mpsadbw_epu8(v68, v67, 0)),
            _mm_mpsadbw_epu8(v68, v67, 5)));
  v70 = _mm_load_si128((const __m128i *)((char *)v55 + a2));
  v71 = _mm_loadl_epi64((const __m128i *)(v56 + a4 + 8));
  v72 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)(v56 + a4)), v71);
  v73 = _mm_mpsadbw_epu8(v72, v70, 0);
  v74 = _mm_mpsadbw_epu8(v72, v70, 5);
  v75 = _mm_srli_si128(v70, 8);
  v76 = _mm_unpacklo_epi64(v71, _mm_loadl_epi64((const __m128i *)(v56 + a4 + 16)));
  *a5 = _mm_add_epi16(
          v69,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v73, v74), _mm_mpsadbw_epu8(v76, v75, 0)),
            _mm_mpsadbw_epu8(v76, v75, 5)));
  return a2;
}

