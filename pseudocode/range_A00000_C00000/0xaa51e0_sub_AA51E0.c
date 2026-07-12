// Function: sub_AA51E0
// Address: 0xaa51e0
// Size: 0x12
// Prototype: __m128(void)

__m128d __usercall sub_AA51E0@<xmm0>(__m128i a1@<xmm0>)
{
  __m128d v1; // xmm2
  __m128d v2; // xmm3
  __m128d v3; // xmm0
  __m128d v4; // xmm2
  __m128i v5; // xmm3
  __m128d v6; // xmm1
  __m128d v7; // xmm2
  __m128d v8; // xmm4
  __m128d v10; // xmm0
  __m128d v11; // xmm2
  __m128d v12; // xmm5
  __m128i v13; // xmm2
  int n3; // eax
  __m128d v15; // xmm4
  __m128d v16; // xmm3
  __m128d v17; // xmm1
  __m128d v18; // xmm0
  __m128d v19; // xmm3
  __m128d v20; // xmm1
  __m128i v21; // xmm5
  __m128d v22; // xmm0
  __m128d v23; // xmm5
  __m128d v24; // xmm4
  __m128d v25; // xmm0
  __m128d v26; // xmm6
  int v27; // edx
  __m128d v28; // xmm3
  __m128d v29; // xmm2
  __m128d v30; // xmm4
  __m128d v31; // xmm5
  __m128d v32; // xmm1
  __m128d v33; // xmm6
  __m128d v34; // xmm7
  __m128d v35; // xmm1
  __m128d v36; // xmm0
  __m128d v37; // xmm4
  __m128d v38; // xmm7
  __m128d v39; // xmm5
  __m128d v40; // xmm0
  __m128d v41; // xmm0
  __m128d v42; // xmm0
  char n3_1; // bl
  __m128i v45; // [esp+30h] [ebp-80h]
  __m128d v46; // [esp+40h] [ebp-70h] BYREF
  __m128i v47; // [esp+50h] [ebp-60h]
  _UNKNOWN **v48; // [esp+60h] [ebp-50h]
  __m128i v49; // [esp+70h] [ebp-40h]
  __m128d v50; // [esp+80h] [ebp-30h]
  __m128i v51; // [esp+90h] [ebp-20h] BYREF
  __m128d v52; // [esp+A0h] [ebp-10h]
  _UNKNOWN *retaddr; // [esp+B0h] [ebp+0h] BYREF

  if ( n2_9 >= 2 )
  {
    v10 = (__m128d)_mm_and_si128(a1, (__m128i)xmmword_25D8250);
    v11 = _mm_mul_pd(_mm_add_pd((__m128d)xmmword_25D8200, v10), (__m128d)xmmword_25D8230);
    v12 = _mm_sub_pd(_mm_round_pd(v11, 0), (__m128d)xmmword_25D8270);
    v13 = _mm_slli_epi64((__m128i)_mm_sub_pd(v11, (__m128d)xmmword_25D8210), 0x3Fu);
    n3 = _mm_movemask_pd((__m128d)_mm_cmpgt_epi32(
                                    _mm_and_si128((__m128i)v10, (__m128i)xmmword_25D8250),
                                    (__m128i)xmmword_25D8260));
    v15 = _mm_mul_pd((__m128d)xmmword_25D8220, v12);
    v16 = _mm_mul_pd((__m128d)xmmword_25D8240, v12);
    v17 = _mm_mul_pd((__m128d)xmmword_25D8280, v12);
    if ( !n3 )
    {
      v18 = _mm_sub_pd(_mm_sub_pd(_mm_sub_pd(v10, v15), v16), v17);
      v19 = (__m128d)xmmword_25D82A0;
      v20 = (__m128d)xmmword_25D82B0;
      v21 = (__m128i)_mm_add_pd(_mm_mul_pd(v12, (__m128d)xmmword_25D8290), v18);
      v22 = _mm_mul_pd(v18, v18);
      v23 = (__m128d)_mm_xor_si128(v21, v13);
LABEL_8:
      v24 = v22;
      v25 = _mm_mul_pd(v22, v22);
      return _mm_add_pd(
               _mm_mul_pd(
                 _mm_mul_pd(
                   v25,
                   _mm_add_pd(
                     _mm_mul_pd(
                       _mm_add_pd(
                         _mm_mul_pd(_mm_add_pd(_mm_mul_pd(v19, v25), (__m128d)xmmword_25D82C0), v25),
                         (__m128d)xmmword_25D82E0),
                       v25),
                     (__m128d)xmmword_25D8300)),
                 v23),
               _mm_add_pd(
                 _mm_mul_pd(
                   _mm_add_pd(
                     _mm_mul_pd(
                       _mm_add_pd(
                         _mm_mul_pd(_mm_add_pd(_mm_mul_pd(v20, v25), (__m128d)xmmword_25D82D0), v25),
                         (__m128d)xmmword_25D82F0),
                       v25),
                     (__m128d)xmmword_25D8310),
                   _mm_mul_pd(v24, v23)),
                 v23));
    }
    v26 = _mm_and_pd((__m128d)xmmword_25D8250, v10);
    v48 = &retaddr;
    v50 = v26;
    v27 = _mm_movemask_pd(_mm_cmple_pd((__m128d)xmmword_25D8320, v26));
    if ( n3 == 3 )
    {
      if ( !v27 )
      {
        v28 = (__m128d)_mm_or_si128(
                         _mm_shuffle_epi32(_mm_cvttpd_epi32(_mm_mul_pd((__m128d)xmmword_25D8350, v26)), 220),
                         (__m128i)xmmword_25D8340);
        v29 = _mm_sub_pd(_mm_or_pd((__m128d)xmmword_25D8330, v28), (__m128d)xmmword_25D8330);
        v30 = _mm_mul_pd((__m128d)xmmword_25D8380, v29);
        v31 = _mm_mul_pd((__m128d)xmmword_25D8390, v29);
        v32 = _mm_sub_pd(v26, _mm_mul_pd((__m128d)xmmword_25D8370, v29));
        v33 = _mm_sub_pd(v32, v30);
        v34 = _mm_sub_pd(v33, v31);
        v35 = _mm_add_pd(_mm_sub_pd(_mm_sub_pd(v32, v33), v30), _mm_sub_pd(_mm_sub_pd(v33, v34), v31));
        v36 = _mm_add_pd(v34, v35);
        v37 = _mm_mul_pd((__m128d)xmmword_25D83A0, v29);
        v38 = _mm_sub_pd(v34, v36);
        v39 = v36;
        v40 = _mm_sub_pd(v36, v37);
        v41 = _mm_add_pd(
                v40,
                _mm_sub_pd(
                  _mm_add_pd(_mm_add_pd(v35, v38), _mm_sub_pd(_mm_sub_pd(v39, v40), v37)),
                  _mm_mul_pd(v29, (__m128d)xmmword_25D83B0)));
        v23 = (__m128d)_mm_xor_si128(
                         _mm_xor_si128(
                           _mm_and_si128((__m128i)xmmword_25D8360, _mm_slli_epi64((__m128i)v28, 0x3Eu)),
                           (__m128i)xmmword_25D8360),
                         (__m128i)v41);
        v22 = _mm_mul_pd(v41, v41);
        v19 = (__m128d)xmmword_25D82A0;
        v20 = (__m128d)xmmword_25D82B0;
        goto LABEL_8;
      }
    }
    else
    {
      v42 = _mm_sub_pd(_mm_sub_pd(_mm_sub_pd(v10, v15), v16), v17);
      v49 = v13;
      v51 = (__m128i)_mm_add_pd(_mm_mul_pd(v12, (__m128d)xmmword_25D8290), v42);
      v52 = _mm_mul_pd(v42, v42);
    }
    n3_1 = n3;
    if ( (n3 & 1) != 0 )
    {
      v49.m128i_i32[1] = __common_cos_reduction_LA(LODWORD(v50.m128d_f64[0]), HIDWORD(v50.m128d_f64[0]), &v51);
      v49.m128i_i32[0] = 0;
      v52.m128d_f64[0] = *(double *)v51.m128i_i64 * *(double *)v51.m128i_i64;
    }
    if ( (n3_1 & 2) != 0 )
    {
      v49.m128i_i32[3] = __common_cos_reduction_LA(
                           LODWORD(v50.m128d_f64[1]),
                           HIDWORD(v50.m128d_f64[1]),
                           &v51.m128i_u64[1]);
      v49.m128i_i32[2] = 0;
      v52.m128d_f64[1] = *(double *)&v51.m128i_i64[1] * *(double *)&v51.m128i_i64[1];
    }
    v22 = v52;
    v23 = (__m128d)_mm_xor_si128(v49, v51);
    v19 = (__m128d)xmmword_25D82A0;
    v20 = (__m128d)xmmword_25D82B0;
    goto LABEL_8;
  }
  v49.m128i_i32[1] = (__int32)&retaddr;
  v1 = (__m128d)_mm_and_si128(a1, (__m128i)xmmword_25D80A0);
  v2 = _mm_add_pd(
         _mm_mul_pd(_mm_add_pd(v1, (__m128d)xmmword_25D8120), (__m128d)xmmword_25D8000),
         (__m128d)xmmword_25D80B0);
  v3 = _mm_sub_pd(_mm_sub_pd(v2, (__m128d)xmmword_25D80B0), (__m128d)xmmword_25D8110);
  if ( _mm_movemask_pd((__m128d)_mm_cmpgt_epi32((__m128i)v1, (__m128i)xmmword_25D8100)) )
  {
    v47 = _mm_and_si128(a1, (__m128i)xmmword_25D80A0);
    *(__int64 *)((char *)v45.m128i_i64 + 4) = (unsigned int)__common_cos_reduction_LA(
                                                              v47.m128i_i32[0],
                                                              v47.m128i_i32[1],
                                                              &v46);
    v45.m128i_i32[0] = 0;
    v45.m128i_i32[3] = __common_cos_reduction_LA(v47.m128i_i32[2], v47.m128i_i32[3], &v46.m128d_f64[1]);
    v4 = v46;
    v5 = v45;
  }
  else
  {
    v4 = _mm_sub_pd(
           _mm_sub_pd(
             _mm_sub_pd(
               _mm_sub_pd(v1, _mm_mul_pd((__m128d)xmmword_25D80C0, v3)),
               _mm_mul_pd((__m128d)xmmword_25D80D0, v3)),
             _mm_mul_pd((__m128d)xmmword_25D80E0, v3)),
           _mm_mul_pd((__m128d)xmmword_25D80F0, v3));
    v5 = _mm_slli_epi64((__m128i)v2, 0x3Fu);
  }
  v6 = v4;
  v7 = _mm_mul_pd(v4, v4);
  v8 = _mm_mul_pd(v7, v7);
  return (__m128d)_mm_xor_si128(
                    (__m128i)_mm_add_pd(
                               _mm_mul_pd(
                                 _mm_mul_pd(
                                   _mm_add_pd(
                                     _mm_mul_pd(
                                       _mm_add_pd(
                                         _mm_mul_pd(
                                           _mm_add_pd(
                                             _mm_mul_pd((__m128d)xmmword_25D8080, v8),
                                             (__m128d)xmmword_25D8060),
                                           v8),
                                         (__m128d)xmmword_25D8040),
                                       v8),
                                     (__m128d)xmmword_25D8020),
                                   v8),
                                 v6),
                               _mm_add_pd(
                                 _mm_mul_pd(
                                   _mm_add_pd(
                                     _mm_mul_pd(
                                       _mm_add_pd(
                                         _mm_mul_pd(
                                           _mm_add_pd(
                                             _mm_mul_pd((__m128d)xmmword_25D8070, v8),
                                             (__m128d)xmmword_25D8050),
                                           v8),
                                         (__m128d)xmmword_25D8030),
                                       v8),
                                     (__m128d)xmmword_25D8010),
                                   _mm_mul_pd(v7, v6)),
                                 v6)),
                    v5);
}

