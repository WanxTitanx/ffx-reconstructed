// Function: sub_9BF430
// Address: 0x9bf430
__int32 __userpurge sub_9BF430@<eax>(char a1@<efl>, __m128 *a2, __m128 *a3, __m128 *a4)
{
  float v4; // xmm0_4
  bool v5; // cf
  bool v6; // zf
  char v7; // sf
  char v8; // of
  char v9; // pf
  __int32 result; // eax
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm4
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm7
  __m128 v17; // xmm2
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm5
  __m128 v21; // xmm7
  __m128 v22; // xmm0
  __m128 v23; // xmm3
  __m128 v24; // xmm5
  __m128 v25; // xmm1
  __m128 v26; // [esp-10h] [ebp-1Ch]
  __m128 v27; // [esp-10h] [ebp-1Ch]

  v4 = a4[9].m128_f32[3];
  v5 = v4 < 0.0;
  v9 = 0;
  v6 = v4 == 0.0;
  v7 = 0;
  v8 = 0;
  BYTE1(result) = a1;
  if ( v4 != 0.0 )
  {
    ++unk_193F664;
    v11 = _mm_mul_ps(a2[40], a4[1]);
    v12 = _mm_mul_ps(a2[41], *a4);
    v13 = _mm_mul_ps(a4[1], a3[40]);
    v14 = _mm_mul_ps(a4[2], a3[41]);
    v26 = _mm_shuffle_ps((__m128)a4[5].m128_u32[0], (__m128)a4[5].m128_u32[0], 0);
    v15 = _mm_shuffle_ps((__m128)a4[7].m128_u32[1], (__m128)a4[7].m128_u32[1], 0);
    v16 = _mm_sub_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)a4[9].m128_u32[3], (__m128)a4[9].m128_u32[3], 0),
              _mm_mul_ps(_mm_shuffle_ps((__m128)a4[9].m128_u32[0], (__m128)a4[9].m128_u32[0], 0), v26)),
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v11, v11, 170), _mm_shuffle_ps(v11, v11, 85)),
                  _mm_shuffle_ps(v11, v11, 0)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v12, v12, 170), _mm_shuffle_ps(v12, v12, 85)),
                  _mm_shuffle_ps(v12, v12, 0))),
              v15));
    v17 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 170), _mm_shuffle_ps(v13, v13, 85)),
            _mm_shuffle_ps(v13, v13, 0));
    v18 = v26;
    v19 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v14, v14, 170), _mm_shuffle_ps(v14, v14, 85)),
                _mm_shuffle_ps(v14, v14, 0)),
              v17),
            v15);
    v20 = _mm_shuffle_ps((__m128)a4[9].m128_u32[1], (__m128)a4[9].m128_u32[1], 0);
    v21 = _mm_sub_ps(v16, v19);
    v22 = _mm_add_ps(v21, v26);
    v23 = _mm_cmplt_ps(v22, v20);
    v27 = _mm_or_ps(_mm_andnot_ps(v23, v22), _mm_and_ps(v23, v20));
    a4[6] = v27;
    v24 = _mm_or_ps(_mm_and_ps(_mm_sub_ps(v20, v18), v23), _mm_andnot_ps(v23, v21));
    v25 = _mm_mul_ps(v24, _mm_mul_ps(a3[39], a4[1]));
    a2[40] = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(a2[39], a4[1]), v24), a2[40]);
    a2[41] = _mm_add_ps(_mm_mul_ps(a4[3], v24), a2[41]);
    a3[40] = _mm_sub_ps(a3[40], v25);
    a3[41] = _mm_add_ps(_mm_mul_ps(a4[4], v24), a3[41]);
    return v27.m128_i32[3];
  }
  return result;
}
