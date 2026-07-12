// Function: sub_A7CB68
// Address: 0xa7cb68
// Size: 0x2a2
// Prototype: 

int __cdecl sub_A7CB68(int a1, int a2, const __m128i *a3, const __m128i *a4, const __m128i *a5, const double *a6)
{
  __m128i v7; // xmm2
  __m128i v8; // xmm4
  __m128i v9; // xmm5
  const double *v10; // edi
  __m128i si128; // xmm7
  __m128i v12; // xmm0
  __m128i v13; // xmm1
  __m128i v14; // xmm2
  __m128i v15; // xmm6
  __m128i v16; // xmm3
  __m128i v17; // xmm5
  __m128i v18; // xmm1
  __m128i v19; // xmm2
  __m128i v20; // xmm6
  __m128i v21; // xmm5
  __m128i v22; // xmm5
  __m128i v23; // xmm2
  __m128i v24; // xmm5
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
  _QWORD *v44; // esi
  double *v45; // edi
  __m128i v46; // xmm4
  __m128 v47; // xmm6
  __m128 v48; // xmm3
  __m128 v49; // xmm1
  __m128 v50; // xmm7
  __m128i v51; // [esp+0h] [ebp-B8h] BYREF
  __m128i v52[2]; // [esp+10h] [ebp-A8h] BYREF
  __m128i v53; // [esp+30h] [ebp-88h]
  __m128i v54[3]; // [esp+40h] [ebp-78h] BYREF
  __m128i v55; // [esp+70h] [ebp-48h] BYREF
  __m128i v56; // [esp+80h] [ebp-38h]
  int *v57; // [esp+A0h] [ebp-18h]
  int v58; // [esp+B0h] [ebp-8h] BYREF

  v57 = &v58;
  v7 = (__m128i)_mm_loadh_ps((const double *)((char *)a6 + 2 * a2 + a2));
  v8 = (__m128i)_mm_loadh_ps((const double *)((char *)a6 + a2));
  v9 = (__m128i)_mm_loadh_ps(a6);
  v10 = (const double *)((char *)a6 + a2 + -4 * a2);
  v56 = (__m128i)_mm_loadh_ps((const double *)((char *)a6 + a2 + a2));
  v55 = v8;
  si128 = _mm_load_si128(a4);
  v12 = v9;
  v51 = _mm_or_si128(_mm_subs_epu8(v9, v8), _mm_subs_epu8(v8, v9));
  v13 = _mm_max_epu8(
          _mm_max_epu8(
            _mm_or_si128(_mm_subs_epu8(v56, v7), _mm_subs_epu8(v7, v56)),
            _mm_or_si128(_mm_subs_epu8(v8, v56), _mm_subs_epu8(v56, v8))),
          v51);
  v14 = (__m128i)_mm_loadh_ps((const double *)((char *)a6 - 4 * a2));
  v15 = (__m128i)_mm_loadh_ps((const double *)((char *)v10 + a2));
  v53 = (__m128i)_mm_loadh_ps(v10);
  v54[0] = v15;
  v16 = _mm_load_si128(&v55);
  v17 = (__m128i)_mm_loadh_ps((const double *)((char *)v10 + 2 * a2));
  v52[0] = _mm_or_si128(_mm_subs_epu8(v15, v17), _mm_subs_epu8(v17, v15));
  v18 = _mm_subs_epu8(
          _mm_max_epu8(
            _mm_max_epu8(
              _mm_max_epu8(
                _mm_max_epu8(_mm_max_epu8(v13, _mm_subs_epu8(v53, v14)), _mm_subs_epu8(v14, v53)),
                _mm_subs_epu8(v53, v15)),
              _mm_subs_epu8(v15, v53)),
            v52[0]),
          si128);
  v19 = _mm_and_si128(_mm_or_si128(_mm_subs_epu8(v15, v16), _mm_subs_epu8(v16, v15)), (__m128i)xmmword_25D7000);
  v20 = v17;
  v21 = _mm_or_si128(_mm_subs_epu8(v17, v12), _mm_subs_epu8(v12, v17));
  v22 = _mm_adds_epu8(_mm_adds_epu8(v21, v21), _mm_srli_epi16(v19, 1u));
  v23 = _mm_load_si128(a5);
  v24 = _mm_subs_epu8(v22, _mm_load_si128(a3));
  v25 = _mm_xor_si128(
          _mm_cmpeq_epi8(
            _mm_add_epi8(_mm_subs_epu8(_mm_load_si128(&v51), v23), _mm_subs_epu8(_mm_load_si128(v52), v23)),
            v24),
          (__m128i)-1LL);
  v26 = _mm_load_si128(xmmword_25D7010);
  v27 = _mm_xor_si128(_mm_load_si128(&v55), v26);
  v28 = _mm_xor_si128(v20, v26);
  v29 = _mm_and_si128(_mm_subs_epi8(_mm_xor_si128(_mm_load_si128(v54), v26), v27), v25);
  v30 = _mm_xor_si128(v12, v26);
  v31 = _mm_subs_epi8(v30, v28);
  v32 = _mm_and_si128(
          _mm_cmpeq_epi8(_mm_or_si128(v18, v24), (__m128i)0LL),
          _mm_adds_epi8(_mm_adds_epi8(_mm_adds_epi8(v29, v31), v31), v31));
  v33 = _mm_adds_epi8(v32, (__m128i)xmmword_25D7040);
  v34 = _mm_adds_epi8(v32, (__m128i)xmmword_25D7030);
  v35 = _mm_unpacklo_epi8(v31, v33);
  v36 = _mm_packs_epi16(
          _mm_srai_epi16(_mm_unpacklo_epi8(v34, v34), 0xBu),
          _mm_srai_epi16(_mm_unpackhi_epi8(v24, v34), 0xBu));
  v37 = _mm_srai_epi16(_mm_unpackhi_epi8(v33, v33), 0xBu);
  v38 = _mm_srai_epi16(v35, 0xBu);
  v39 = _mm_packs_epi16(v38, v37);
  v40 = _mm_adds_epi8(v28, v36);
  v41 = _mm_load_si128((const __m128i *)&xmmword_25D7050);
  v42 = _mm_packs_epi16(_mm_srai_epi16(_mm_adds_epi16(v38, v41), 1u), _mm_srai_epi16(_mm_adds_epi16(v37, v41), 1u));
  v43 = _mm_load_si128(xmmword_25D7010);
  v44 = (_QWORD *)(a1 + a2 - 4 * a2 + 2 * a2);
  v45 = (double *)((char *)v10 + 2 * a2);
  v46 = _mm_andnot_si128(v25, v42);
  v47 = (__m128)_mm_xor_si128(v40, v43);
  v48 = (__m128)_mm_xor_si128(_mm_subs_epi8(v30, v39), v43);
  v49 = (__m128)_mm_xor_si128(_mm_adds_epi8(_mm_xor_si128(_mm_load_si128(v54), v43), v46), v43);
  v50 = (__m128)_mm_xor_si128(_mm_subs_epi8(v27, v46), v43);
  *v44 = v47.m128_u64[0];
  _mm_storeh_ps(v45, v47);
  *(_QWORD *)((char *)v44 - a2) = v49.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v45 - a2), v49);
  *(_QWORD *)((char *)v44 + a2) = v48.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v45 + a2), v48);
  *(_QWORD *)((char *)v44 + 2 * a2) = v50.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v45 + 2 * a2), v50);
  return -a2;
}

