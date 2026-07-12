// Function: sub_A83A90
// Address: 0xa83a90
// Size: 0x157
// Prototype: 

unsigned __int32 __cdecl sub_A83A90(const __m128i *a1, _WORD *a2)
{
  __m128i v2; // xmm2
  __m128i si128; // xmm3
  __m128i v4; // xmm0
  __m128i v5; // xmm3
  __m128i v6; // xmm4
  __m128i v7; // xmm0
  __m128i v8; // xmm1
  __m128i v9; // xmm4
  __m128i v10; // xmm0
  __m128i v11; // xmm3
  __m128i v12; // xmm1
  __m128i v13; // xmm2
  __m128i v14; // xmm3
  __m128i v15; // xmm0
  __m128i v16; // xmm4
  __m128i v17; // xmm3
  __m128i v18; // xmm5
  __m128i v19; // xmm4
  __m128i v20; // xmm1
  __m128i v21; // xmm5
  __m128i v22; // xmm4
  int v23; // eax
  int v24; // ecx
  __m128i v25; // xmm5
  __m128i v26; // xmm4
  int v27; // eax
  int v28; // ecx
  __m128i v29; // xmm5
  __m128i v30; // xmm4
  int v31; // eax
  int v32; // ecx

  v2 = _mm_shuffle_epi32(_mm_load_si128(a1 + 1), 78);
  si128 = _mm_load_si128(a1);
  v4 = _mm_add_epi16(si128, v2);
  v5 = _mm_sub_epi16(si128, v2);
  v6 = v4;
  v7 = _mm_unpacklo_epi64(v4, v5);
  v8 = _mm_unpackhi_epi64(v6, v5);
  v9 = _mm_add_epi16(v8, v7);
  v10 = _mm_sub_epi16(v7, v8);
  v11 = _mm_unpackhi_epi16(v9, v10);
  v12 = _mm_unpacklo_epi16(v9, v10);
  v13 = _mm_shuffle_epi32(_mm_unpackhi_epi16(v12, v11), 78);
  v14 = _mm_unpacklo_epi16(v12, v11);
  v15 = _mm_shuffle_epi32(_mm_cvtsi32_si128(0x30003u), 0);
  v16 = _mm_add_epi16(v14, v13);
  v17 = _mm_sub_epi16(v14, v13);
  v18 = v16;
  v19 = _mm_unpacklo_epi64(v16, v17);
  v20 = _mm_unpackhi_epi64(v18, v17);
  v21 = _mm_srai_epi16(_mm_add_epi16(_mm_add_epi16(v20, v19), v15), 3u);
  v22 = _mm_srai_epi16(_mm_add_epi16(_mm_sub_epi16(v19, v20), v15), 3u);
  v23 = _mm_cvtsi128_si32(v21);
  v24 = _mm_cvtsi128_si32(v22);
  v25 = _mm_srli_si128(v21, 4);
  v26 = _mm_srli_si128(v22, 4);
  *a2 = v23;
  a2[32] = v24;
  a2[64] = HIWORD(v23);
  a2[96] = HIWORD(v24);
  v27 = _mm_cvtsi128_si32(v25);
  v28 = _mm_cvtsi128_si32(v26);
  v29 = _mm_srli_si128(v25, 4);
  v30 = _mm_srli_si128(v26, 4);
  a2[128] = v27;
  a2[160] = v28;
  a2[192] = HIWORD(v27);
  a2[224] = HIWORD(v28);
  v31 = _mm_cvtsi128_si32(v29);
  v32 = _mm_cvtsi128_si32(v30);
  a2[16] = v31;
  a2[48] = v32;
  a2[80] = HIWORD(v31);
  a2[112] = HIWORD(v32);
  a2[144] = v29.m128i_i16[2];
  a2[176] = v30.m128i_i16[2];
  a2[208] = v29.m128i_i16[3];
  a2[240] = v30.m128i_i16[3];
  return HIWORD(v29.m128i_i32[1]);
}

