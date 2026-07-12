// Function: sub_A832A4
// Address: 0xa832a4
// Size: 0x2f0
// Prototype: 

int __cdecl sub_A832A4(const __m128i *a1, int a2, int a3, int a4, __m128i *a5)
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
  __m128i v34; // xmm5
  const __m128i *v35; // esi
  int v36; // edi
  __m128i v37; // xmm1
  __m128i v38; // xmm0
  __m128i v39; // xmm2
  __m128i v40; // xmm1
  __m128i v41; // xmm0
  __m128i v42; // xmm5
  const __m128i *v43; // esi
  int v44; // edi
  __m128i v45; // xmm1
  __m128i v46; // xmm0
  __m128i v47; // xmm2
  __m128i v48; // xmm1
  __m128i v49; // xmm0
  __m128i v50; // xmm5
  const __m128i *v51; // esi
  int v52; // edi
  __m128i v53; // xmm1
  __m128i v54; // xmm0
  __m128i v55; // xmm2
  __m128i v56; // xmm1
  __m128i v57; // xmm0
  __m128i v58; // xmm5
  const __m128i *v59; // esi
  int v60; // edi
  __m128i v61; // xmm1
  __m128i v62; // xmm0
  __m128i v63; // xmm2
  __m128i v64; // xmm1
  __m128i v65; // xmm0
  __m128i v66; // xmm2

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
  v35 = (const __m128i *)((char *)v27 + 2 * a2);
  v36 = v28 + 2 * a4;
  v37 = _mm_add_epi16(v32, _mm_add_epi16(_mm_mpsadbw_epu8(v34, v33, 0), _mm_mpsadbw_epu8(v34, v33, 5)));
  v38 = _mm_loadl_epi64(v35);
  v39 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v36), _mm_loadl_epi64((const __m128i *)(v36 + 8)));
  v40 = _mm_add_epi16(v37, _mm_add_epi16(_mm_mpsadbw_epu8(v39, v38, 0), _mm_mpsadbw_epu8(v39, v38, 5)));
  v41 = _mm_loadl_epi64((const __m128i *)((char *)v35 + a2));
  v42 = _mm_unpacklo_epi64(
          _mm_loadl_epi64((const __m128i *)(v36 + a4)),
          _mm_loadl_epi64((const __m128i *)(v36 + a4 + 8)));
  v43 = (const __m128i *)((char *)v35 + 2 * a2);
  v44 = v36 + 2 * a4;
  v45 = _mm_add_epi16(v40, _mm_add_epi16(_mm_mpsadbw_epu8(v42, v41, 0), _mm_mpsadbw_epu8(v42, v41, 5)));
  v46 = _mm_loadl_epi64(v43);
  v47 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v44), _mm_loadl_epi64((const __m128i *)(v44 + 8)));
  v48 = _mm_add_epi16(v45, _mm_add_epi16(_mm_mpsadbw_epu8(v47, v46, 0), _mm_mpsadbw_epu8(v47, v46, 5)));
  v49 = _mm_loadl_epi64((const __m128i *)((char *)v43 + a2));
  v50 = _mm_unpacklo_epi64(
          _mm_loadl_epi64((const __m128i *)(v44 + a4)),
          _mm_loadl_epi64((const __m128i *)(v44 + a4 + 8)));
  v51 = (const __m128i *)((char *)v43 + 2 * a2);
  v52 = v44 + 2 * a4;
  v53 = _mm_add_epi16(v48, _mm_add_epi16(_mm_mpsadbw_epu8(v50, v49, 0), _mm_mpsadbw_epu8(v50, v49, 5)));
  v54 = _mm_loadl_epi64(v51);
  v55 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v52), _mm_loadl_epi64((const __m128i *)(v52 + 8)));
  v56 = _mm_add_epi16(v53, _mm_add_epi16(_mm_mpsadbw_epu8(v55, v54, 0), _mm_mpsadbw_epu8(v55, v54, 5)));
  v57 = _mm_loadl_epi64((const __m128i *)((char *)v51 + a2));
  v58 = _mm_unpacklo_epi64(
          _mm_loadl_epi64((const __m128i *)(v52 + a4)),
          _mm_loadl_epi64((const __m128i *)(v52 + a4 + 8)));
  v59 = (const __m128i *)((char *)v51 + 2 * a2);
  v60 = v52 + 2 * a4;
  v61 = _mm_add_epi16(v56, _mm_add_epi16(_mm_mpsadbw_epu8(v58, v57, 0), _mm_mpsadbw_epu8(v58, v57, 5)));
  v62 = _mm_loadl_epi64(v59);
  v63 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v60), _mm_loadl_epi64((const __m128i *)(v60 + 8)));
  v64 = _mm_add_epi16(v61, _mm_add_epi16(_mm_mpsadbw_epu8(v63, v62, 0), _mm_mpsadbw_epu8(v63, v62, 5)));
  v65 = _mm_loadl_epi64((const __m128i *)((char *)v59 + a2));
  v66 = _mm_unpacklo_epi64(
          _mm_loadl_epi64((const __m128i *)(v60 + a4)),
          _mm_loadl_epi64((const __m128i *)(v60 + a4 + 8)));
  *a5 = _mm_add_epi16(v64, _mm_add_epi16(_mm_mpsadbw_epu8(v66, v65, 0), _mm_mpsadbw_epu8(v66, v65, 5)));
  return a2;
}

