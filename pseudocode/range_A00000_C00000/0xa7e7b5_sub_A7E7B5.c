// Function: sub_A7E7B5
// Address: 0xa7e7b5
// Size: 0x2bb
// Prototype: 

int __cdecl sub_A7E7B5(int a1, int a2, const __m128i *a3)
{
  unsigned int *v3; // edi
  unsigned int *v4; // edx
  __m128i v5; // xmm4
  __m128i v6; // xmm1
  __m128i v7; // xmm0
  __m128i v8; // xmm1
  __m128i v9; // xmm2
  __m128i v10; // xmm0
  __m128i v11; // xmm2
  unsigned int *v12; // esi
  _DWORD *v13; // edi
  unsigned int *v14; // edx
  _DWORD *v15; // ecx
  __m128i v16; // xmm1
  __m128i v17; // xmm7
  __m128i v18; // xmm4
  __m128i v19; // xmm7
  __m128i v20; // xmm6
  __m128i v21; // xmm4
  __m128i v22; // xmm6
  __m128i v23; // xmm1
  __m128i v24; // xmm3
  __m128i v25; // xmm0
  __m128i v26; // xmm1
  __m128i v27; // xmm2
  __m128i v28; // xmm3
  __m128i v29; // xmm5
  __m128i si128; // xmm4
  __m128i v31; // xmm5
  __m128i v32; // xmm0
  __m128i v33; // xmm1
  __m128i v34; // xmm3
  __m128i v35; // xmm2
  __m128i v36; // xmm0
  __m128i v37; // xmm5
  __m128i v38; // xmm0
  __m128i v39; // xmm6
  __m128i v40; // xmm2
  __m128i v41; // xmm3
  __m128i v42; // xmm1
  __m128i v43; // xmm4
  __m128i v44; // xmm6
  __m128i v45; // xmm5
  __m128i v46; // xmm3
  __m128i v47; // xmm5
  __m128i v48; // xmm2
  __m128i v49; // xmm0
  __m128i v50; // xmm2
  __m128i v51; // xmm3
  __m128i v52; // xmm6
  __m128i v53; // xmm3
  __m128i v54; // xmm6
  __m128i v55; // xmm3
  __m128i v56; // xmm6
  __m128i v57; // xmm3
  _DWORD *v58; // esi
  _DWORD *v60; // edi
  _DWORD *v61; // edx
  _DWORD *v62; // ecx
  __m128i v63; // xmm0
  __m128i v64; // xmm2
  __m128i v65; // xmm0
  __m128i v66; // xmm2
  __m128i v67; // [esp+0h] [ebp-38h] BYREF
  __m128i v68; // [esp+10h] [ebp-28h] BYREF
  int *v69; // [esp+20h] [ebp-18h]
  int v70; // [esp+30h] [ebp-8h] BYREF

  v69 = &v70;
  v3 = (unsigned int *)(a1 - 2 + a2);
  v4 = (unsigned int *)(a1 - 2 + 4 * a2);
  v5 = _mm_unpacklo_epi8(
         _mm_unpacklo_epi32(
           _mm_cvtsi32_si128(*(_DWORD *)(a1 - 2 + 2 * a2)),
           _mm_cvtsi32_si128(*(unsigned int *)((char *)v4 + 2 * a2))),
         _mm_unpacklo_epi32(
           _mm_cvtsi32_si128(*(unsigned int *)((char *)v3 + 2 * a2)),
           _mm_cvtsi32_si128(*(unsigned int *)((char *)v4 + 2 * a2 + a2))));
  v6 = _mm_unpacklo_epi8(
         _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(_DWORD *)(a1 - 2)), _mm_cvtsi32_si128(*v4)),
         _mm_unpacklo_epi32(_mm_cvtsi32_si128(*v3), _mm_cvtsi32_si128(*(unsigned int *)((char *)v4 + a2))));
  v7 = _mm_unpacklo_epi16(v6, v5);
  v8 = _mm_unpackhi_epi16(v6, v5);
  v9 = v7;
  v10 = _mm_unpacklo_epi32(v7, v8);
  v11 = _mm_unpackhi_epi32(v9, v8);
  v12 = (unsigned int *)(a1 - 2 + 8 * a2);
  v13 = (unsigned int *)((char *)v12 + a2);
  v14 = &v12[a2];
  v15 = (unsigned int *)((char *)v14 + a2);
  v16 = _mm_unpacklo_epi8(
          _mm_unpacklo_epi32(
            _mm_cvtsi32_si128(*(unsigned int *)((char *)v12 + 2 * a2)),
            _mm_cvtsi32_si128(*(unsigned int *)((char *)v14 + 2 * a2))),
          _mm_unpacklo_epi32(
            _mm_cvtsi32_si128(*(unsigned int *)((char *)v12 + 2 * a2 + a2)),
            _mm_cvtsi32_si128(*(unsigned int *)((char *)v14 + 2 * a2 + a2))));
  v17 = _mm_unpacklo_epi8(
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(*v12), _mm_cvtsi32_si128(*v14)),
          _mm_unpacklo_epi32(
            _mm_cvtsi32_si128(*(unsigned int *)((char *)v12 + a2)),
            _mm_cvtsi32_si128(*(unsigned int *)((char *)v14 + a2))));
  v18 = _mm_unpacklo_epi16(v17, v16);
  v19 = _mm_unpackhi_epi16(v17, v16);
  v20 = v18;
  v21 = _mm_unpacklo_epi32(v18, v19);
  v22 = _mm_unpackhi_epi32(v20, v19);
  v23 = v10;
  v24 = v11;
  v25 = _mm_unpacklo_epi64(v10, v21);
  v26 = _mm_unpackhi_epi64(v23, v21);
  v27 = _mm_unpacklo_epi64(v11, v22);
  v28 = _mm_unpackhi_epi64(v24, v22);
  v29 = _mm_or_si128(_mm_subs_epu8(v26, v27), _mm_subs_epu8(v27, v26));
  si128 = _mm_load_si128(xmmword_25D7010);
  v31 = _mm_cmpeq_epi8(
          _mm_subs_epu8(
            _mm_adds_epu8(
              _mm_adds_epu8(v29, v29),
              _mm_srli_epi16(
                _mm_and_si128(_mm_or_si128(_mm_subs_epu8(v25, v28), _mm_subs_epu8(v28, v25)), (__m128i)xmmword_25D7000),
                1u)),
            _mm_load_si128(a3)),
          (__m128i)0LL);
  v67 = v25;
  v68 = v28;
  v32 = _mm_subs_epi8(_mm_xor_si128(v25, si128), _mm_xor_si128(v28, si128));
  v33 = _mm_xor_si128(v26, si128);
  v34 = _mm_xor_si128(v27, si128);
  v35 = _mm_subs_epi8(v34, v33);
  v36 = _mm_and_si128(v31, _mm_adds_epi8(_mm_adds_epi8(_mm_adds_epi8(v32, v35), v35), v35));
  v37 = _mm_adds_epi8(v36, (__m128i)xmmword_25D7030);
  v38 = _mm_adds_epi8(v36, (__m128i)xmmword_25D7040);
  v39 = _mm_load_si128((const __m128i *)&xmmword_25D7080);
  v40 = _mm_load_si128((const __m128i *)&xmmword_25D7090);
  v41 = _mm_xor_si128(
          _mm_subs_epi8(
            v34,
            _mm_or_si128(
              _mm_and_si128(_mm_srli_epi16(v38, 3u), v40),
              _mm_and_si128(_mm_cmpgt_epi8((__m128i)0LL, v38), v39))),
          si128);
  v42 = _mm_xor_si128(
          _mm_adds_epi8(
            v33,
            _mm_or_si128(
              _mm_and_si128(_mm_srli_epi16(v37, 3u), v40),
              _mm_and_si128(_mm_cmpgt_epi8((__m128i)0LL, v37), v39))),
          si128);
  v43 = _mm_load_si128(&v68);
  v44 = _mm_load_si128(&v67);
  v45 = v41;
  v46 = _mm_unpacklo_epi8(v41, v43);
  v47 = _mm_unpackhi_epi8(v45, v43);
  v48 = _mm_unpacklo_epi8(v44, v42);
  v49 = _mm_unpacklo_epi16(v48, v46);
  v50 = _mm_unpackhi_epi16(v48, v46);
  v51 = _mm_unpackhi_epi8(v44, v42);
  v52 = _mm_unpacklo_epi16(v51, v47);
  v53 = _mm_unpackhi_epi16(v51, v47);
  *v12 = _mm_cvtsi128_si32(v52);
  *v14 = _mm_cvtsi128_si32(v53);
  v54 = _mm_srli_si128(v52, 4);
  v55 = _mm_srli_si128(v53, 4);
  *v13 = _mm_cvtsi128_si32(v54);
  *v15 = _mm_cvtsi128_si32(v55);
  v56 = _mm_srli_si128(v54, 4);
  v57 = _mm_srli_si128(v55, 4);
  *(unsigned int *)((char *)v12 + 2 * a2) = _mm_cvtsi128_si32(v56);
  *(unsigned int *)((char *)v14 + 2 * a2) = _mm_cvtsi128_si32(v57);
  *(_DWORD *)((char *)v13 + 2 * a2) = v56.m128i_i32[1];
  *(_DWORD *)((char *)v15 + 2 * a2) = v57.m128i_i32[1];
  v58 = (_DWORD *)(a1 - 2);
  v60 = (_DWORD *)(a1 - 2 + a2);
  v61 = (_DWORD *)(a1 - 2 + 4 * a2);
  v62 = (_DWORD *)((char *)v61 + a2);
  *v58 = _mm_cvtsi128_si32(v49);
  *v61 = _mm_cvtsi128_si32(v50);
  v63 = _mm_srli_si128(v49, 4);
  v64 = _mm_srli_si128(v50, 4);
  *v60 = _mm_cvtsi128_si32(v63);
  *v62 = _mm_cvtsi128_si32(v64);
  v65 = _mm_srli_si128(v63, 4);
  v66 = _mm_srli_si128(v64, 4);
  *(_DWORD *)((char *)v58 + 2 * a2) = _mm_cvtsi128_si32(v65);
  *(_DWORD *)((char *)v61 + 2 * a2) = _mm_cvtsi128_si32(v66);
  *(_DWORD *)((char *)v60 + 2 * a2) = v65.m128i_i32[1];
  *(_DWORD *)((char *)v62 + 2 * a2) = v66.m128i_i32[1];
  return a2;
}

