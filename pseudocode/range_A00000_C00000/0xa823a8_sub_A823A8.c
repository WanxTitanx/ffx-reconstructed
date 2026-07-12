// Function: sub_A823A8
// Address: 0xa823a8
// Size: 0x36f
// Prototype: 

const __m128i *__cdecl sub_A823A8(const __m128i *a1, int a2, int a3, const __m128i *a4, _QWORD *a5, int a6)
{
  const __m128i *v6; // esi
  __m128i v7; // xmm3
  __m128i v8; // xmm4
  __m128i v9; // xmm5
  const __m128i *v10; // esi
  _QWORD *v11; // edi
  __m128i si128; // xmm0
  const __m128i *result; // eax
  __m128i v14; // xmm1
  __m128i v15; // xmm3
  __m128i v16; // xmm3
  __m128i v17; // xmm7
  __m128i v18; // xmm6
  __m128i v19; // xmm6
  __m128i v20; // xmm6
  __m128i v21; // xmm7
  __m128i v22; // xmm0
  __m128i v23; // xmm2
  __m128i v24; // xmm3
  __m128i v25; // xmm4
  __m128i v26; // xmm5
  __m128i v27; // xmm6
  __m128i v28; // xmm7
  __m128i v29; // xmm1
  __m128i v30; // xmm2
  __m128i v31; // xmm3
  __m128i v32; // xmm4
  __m128i v33; // xmm5
  __m128i v34; // xmm6
  __m128i v35; // xmm1
  _QWORD *v36; // edi
  __m128i v37; // xmm2
  _QWORD *v38; // edi
  __m128i v39; // xmm7
  __m128i v40; // xmm1
  _QWORD *v41; // edi
  __m128i v42; // xmm1
  __m128i v43; // xmm3
  __m128i v44; // xmm5
  __m128i v45; // xmm7
  __m128i v46; // xmm1
  __m128i v47; // xmm3
  __m128i v48; // xmm5
  __m128i v49; // xmm7
  _QWORD *v50; // edi
  __m128i v51; // [esp+0h] [ebp-A8h] BYREF
  __m128i v52; // [esp+10h] [ebp-98h] BYREF
  __m128i v53; // [esp+20h] [ebp-88h] BYREF
  __m128i v54; // [esp+30h] [ebp-78h] BYREF
  __m128i v55; // [esp+40h] [ebp-68h] BYREF
  __m128i v56; // [esp+50h] [ebp-58h] BYREF
  __m128i v57; // [esp+60h] [ebp-48h] BYREF
  __m128i v58; // [esp+70h] [ebp-38h] BYREF
  __m128i v59; // [esp+80h] [ebp-28h] BYREF
  int *v60; // [esp+90h] [ebp-18h]
  int v61; // [esp+A0h] [ebp-8h] BYREF

  v60 = &v61;
  v6 = (const __m128i *)((char *)a1 + 3 * a2);
  v7 = _mm_loadu_si128(v6);
  v8 = _mm_loadu_si128((const __m128i *)((char *)v6 + a2));
  v9 = _mm_loadu_si128((const __m128i *)((char *)v6 + 2 * a2));
  v10 = (const __m128i *)((char *)v6 + 3 * a2);
  v51 = _mm_loadu_si128(a1);
  v52 = _mm_loadu_si128((const __m128i *)((char *)a1 + a2));
  v53 = _mm_loadu_si128((const __m128i *)((char *)a1 + 2 * a2));
  v54 = v7;
  v55 = v8;
  v56 = v9;
  v57 = _mm_loadu_si128(v10);
  v58 = _mm_loadu_si128((const __m128i *)((char *)v10 + a2));
  v59 = _mm_loadu_si128((const __m128i *)((char *)v10 + 2 * a2));
  if ( a3 )
  {
    v11 = a5;
    si128 = _mm_load_si128(&xmmword_25D75E0[a3]);
    result = a4;
    if ( a4 )
    {
      result = &xmmword_25D75E0[(_DWORD)a4];
      v14 = _mm_load_si128(result);
      v15 = _mm_load_si128(&v51);
      v16 = _mm_srai_epi16(
              _mm_add_epi16(
                _mm_maddubs_epi16(_mm_unpacklo_epi8(v15, _mm_srli_si128(v15, 1)), si128),
                (__m128i)xmmword_25D7450),
              7u);
      v17 = _mm_packus_epi16(v16, v16);
      do
      {
        v18 = _mm_load_si128(&v52);
        v19 = _mm_srai_epi16(
                _mm_add_epi16(
                  _mm_maddubs_epi16(_mm_unpacklo_epi8(v18, _mm_srli_si128(v18, 1)), si128),
                  (__m128i)xmmword_25D7450),
                7u);
        v20 = _mm_packus_epi16(v19, v19);
        v21 = _mm_srai_epi16(
                _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v17, v20), v14), (__m128i)xmmword_25D7450),
                7u);
        *v11 = _mm_packus_epi16(v21, v21).m128i_u64[0];
        v11 = (_QWORD *)((char *)v11 + a6);
        v17 = v20;
      }
      while ( v11 != &a5[a6] );
    }
    else
    {
      do
      {
        v42 = _mm_load_si128(&v51);
        v43 = _mm_load_si128(&v52);
        v44 = _mm_load_si128(&v53);
        v45 = _mm_load_si128(&v54);
        v46 = _mm_srai_epi16(
                _mm_add_epi16(
                  _mm_maddubs_epi16(_mm_unpacklo_epi8(v42, _mm_srli_si128(v42, 1)), si128),
                  (__m128i)xmmword_25D7450),
                7u);
        v47 = _mm_srai_epi16(
                _mm_add_epi16(
                  _mm_maddubs_epi16(_mm_unpacklo_epi8(v43, _mm_srli_si128(v43, 1)), si128),
                  (__m128i)xmmword_25D7450),
                7u);
        v48 = _mm_srai_epi16(
                _mm_add_epi16(
                  _mm_maddubs_epi16(_mm_unpacklo_epi8(v44, _mm_srli_si128(v44, 1)), si128),
                  (__m128i)xmmword_25D7450),
                7u);
        v49 = _mm_srai_epi16(
                _mm_add_epi16(
                  _mm_maddubs_epi16(_mm_unpacklo_epi8(v45, _mm_srli_si128(v45, 1)), si128),
                  (__m128i)xmmword_25D7450),
                7u);
        *v11 = _mm_packus_epi16(v46, v46).m128i_u64[0];
        *(_QWORD *)((char *)v11 + a6) = _mm_packus_epi16(v47, v47).m128i_u64[0];
        v50 = (_QWORD *)((char *)v11 + 2 * a6);
        *v50 = _mm_packus_epi16(v48, v48).m128i_u64[0];
        *(_QWORD *)((char *)v50 + a6) = _mm_packus_epi16(v49, v49).m128i_u64[0];
        v11 = (_QWORD *)((char *)v50 + 2 * a6);
      }
      while ( v11 != &a5[a6] );
    }
  }
  else
  {
    result = &xmmword_25D75E0[(_DWORD)a4];
    v22 = _mm_load_si128(result);
    v23 = _mm_loadl_epi64(&v52);
    v24 = _mm_loadl_epi64(&v53);
    v25 = _mm_loadl_epi64(&v54);
    v26 = _mm_loadl_epi64(&v55);
    v27 = _mm_loadl_epi64(&v56);
    v28 = _mm_loadl_epi64(&v57);
    v29 = _mm_srai_epi16(
            _mm_add_epi16(
              _mm_maddubs_epi16(_mm_unpacklo_epi8(_mm_loadl_epi64(&v51), v23), v22),
              (__m128i)xmmword_25D7450),
            7u);
    v30 = _mm_srai_epi16(
            _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v23, v24), v22), (__m128i)xmmword_25D7450),
            7u);
    v31 = _mm_srai_epi16(
            _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v24, v25), v22), (__m128i)xmmword_25D7450),
            7u);
    v32 = _mm_srai_epi16(
            _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v25, v26), v22), (__m128i)xmmword_25D7450),
            7u);
    v33 = _mm_srai_epi16(
            _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v26, v27), v22), (__m128i)xmmword_25D7450),
            7u);
    v34 = _mm_srai_epi16(
            _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v27, v28), v22), (__m128i)xmmword_25D7450),
            7u);
    *a5 = _mm_packus_epi16(v29, v29).m128i_u64[0];
    *(_QWORD *)((char *)a5 + a6) = _mm_packus_epi16(v30, v30).m128i_u64[0];
    v35 = _mm_loadl_epi64(&v58);
    v36 = (_QWORD *)((char *)a5 + 2 * a6);
    v37 = _mm_loadl_epi64(&v59);
    *v36 = _mm_packus_epi16(v31, v31).m128i_u64[0];
    *(_QWORD *)((char *)v36 + a6) = _mm_packus_epi16(v32, v32).m128i_u64[0];
    v38 = (_QWORD *)((char *)v36 + 2 * a6);
    *v38 = _mm_packus_epi16(v33, v33).m128i_u64[0];
    *(_QWORD *)((char *)v38 + a6) = _mm_packus_epi16(v34, v34).m128i_u64[0];
    v39 = _mm_srai_epi16(
            _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v28, v35), v22), (__m128i)xmmword_25D7450),
            7u);
    v40 = _mm_srai_epi16(
            _mm_add_epi16(_mm_maddubs_epi16(_mm_unpacklo_epi8(v35, v37), v22), (__m128i)xmmword_25D7450),
            7u);
    v41 = (_QWORD *)((char *)v38 + 2 * a6);
    *v41 = _mm_packus_epi16(v39, v39).m128i_u64[0];
    *(_QWORD *)((char *)v41 + a6) = _mm_packus_epi16(v40, v40).m128i_u64[0];
  }
  return result;
}

