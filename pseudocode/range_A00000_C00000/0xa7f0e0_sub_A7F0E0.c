// Function: sub_A7F0E0
// Address: 0xa7f0e0
// Size: 0x28f
// Prototype: 

int __cdecl sub_A7F0E0(const __m128i *a1, __m128i *a2, int a3, int a4, int a5, const __m128i *a6, int a7)
{
  const __m128i *v7; // ebx
  int result; // eax
  int v12; // edx
  __m128i v13; // xmm0
  __m128i v14; // xmm1
  __m128i v15; // xmm3
  __m128i v16; // xmm5
  __m128i v17; // xmm7
  __m128i v18; // xmm7
  int v19; // eax
  __m128i v20; // xmm3
  __m128i v21; // xmm2
  __m128i v22; // xmm4
  __m128i v23; // xmm5
  __m128i v24; // xmm3
  __m128i v25; // xmm7
  const __m128i *v26; // esi
  __m64 *v27; // edi
  const __m128i *v28; // ebx
  __m64 v29; // mm1
  __m64 v30; // mm1
  __m64 v31; // mm1
  __m64 v32; // mm1
  unsigned int v33; // edx
  __m64 v34; // mm0
  __m64 v35; // mm1
  __m128i v36; // xmm0
  __m128i v37; // xmm1
  __m128i v38; // xmm3
  __m128i v39; // xmm5
  __m128i v40; // xmm7
  __m128i v41; // xmm7
  __m128i v42; // xmm3
  __m128i v43; // xmm2
  __m128i v44; // xmm4
  __m128i v45; // xmm5
  __m128i v46; // xmm3
  __m128i v47; // xmm7
  __m128i v48; // xmm0
  __m128i si128; // [esp+0h] [ebp-2Ch] BYREF
  int *v50; // [esp+10h] [ebp-1Ch]
  int v51; // [esp+20h] [ebp-Ch] BYREF

  v50 = &v51;
  si128 = _mm_load_si128(a6);
  v7 = a6 + 1;
  result = a3;
  do
  {
    v12 = 0;
    while ( 1 )
    {
      v13 = _mm_loadu_si128(a1);
      v14 = _mm_loadu_si128((const __m128i *)((char *)a1 + result));
      v15 = _mm_loadu_si128((const __m128i *)((char *)a1 + 2 * result));
      v16 = _mm_avg_epu8(v14, v15);
      v17 = _mm_load_si128(&si128);
      v18 = _mm_or_si128(
              _mm_cmpeq_epi8(
                _mm_subs_epu8(v17, _mm_adds_epu8(_mm_subs_epu8(v13, v15), _mm_subs_epu8(v15, v13))),
                (__m128i)0LL),
              _mm_cmpeq_epi8(
                _mm_subs_epu8(v17, _mm_adds_epu8(_mm_subs_epu8(v13, v14), _mm_subs_epu8(v14, v13))),
                (__m128i)0LL));
      v19 = -result;
      v20 = _mm_loadu_si128((const __m128i *)((char *)a1 + v19));
      v21 = _mm_loadu_si128((const __m128i *)((char *)a1 + 2 * v19));
      v22 = _mm_adds_epu8(_mm_subs_epu8(v13, v20), _mm_subs_epu8(v20, v13));
      v23 = _mm_avg_epu8(v16, _mm_avg_epu8(v21, v20));
      v24 = _mm_load_si128(&si128);
      v25 = _mm_or_si128(
              _mm_or_si128(
                v18,
                _mm_cmpeq_epi8(
                  _mm_subs_epu8(v24, _mm_adds_epu8(_mm_subs_epu8(v13, v21), _mm_subs_epu8(v21, v13))),
                  (__m128i)0LL)),
              _mm_cmpeq_epi8(_mm_subs_epu8(v24, v22), (__m128i)0LL));
      *a2 = _mm_adds_epu8(_mm_and_si128(v13, v25), _mm_andnot_si128(v25, _mm_avg_epu8(v23, v13)));
      result = -v19;
      ++a1;
      ++a2;
      v12 += 16;
      if ( v12 >= a5 )
        break;
      si128 = _mm_load_si128(v7++);
    }
    v26 = &a1[v12 / 0xFFFFFFF0];
    v27 = (__m64 *)&a2[v12 / 0xFFFFFFF0];
    si128 = _mm_load_si128(a6);
    v28 = a6 + 1;
    v29 = _m_punpcklbw((__m64)v27->m64_u64, (__m64)v27->m64_u64);
    v30 = _m_punpcklwd(v29, v29);
    v27[-1].m64_u64 = (unsigned __int64)_m_punpckldq(v30, v30);
    v31 = _m_punpcklbw(*(__m64 *)((char *)v27 + a5 - 1), *(__m64 *)((char *)v27 + a5 - 1));
    v32 = _m_punpcklwd(v31, v31);
    *(__m64 *)((char *)v27 + a5) = _m_punpckldq(v32, v32);
    v33 = 0;
    v34 = v27[-2];
    v35 = v27[-1];
    while ( 1 )
    {
      v36 = _mm_loadu_si128((const __m128i *)&v27[v33 / 8]);
      v37 = _mm_loadu_si128((const __m128i *)((char *)&v27[v33 / 8 - 1].m64_i64 + 6));
      v38 = _mm_loadu_si128((const __m128i *)&v27[v33 / 8 - 1].m64_u8[7]);
      v39 = _mm_avg_epu8(v37, v38);
      v40 = _mm_load_si128(&si128);
      v41 = _mm_or_si128(
              _mm_cmpeq_epi8(
                _mm_subs_epu8(v40, _mm_adds_epu8(_mm_subs_epu8(v36, v38), _mm_subs_epu8(v38, v36))),
                (__m128i)0LL),
              _mm_cmpeq_epi8(
                _mm_subs_epu8(v40, _mm_adds_epu8(_mm_subs_epu8(v36, v37), _mm_subs_epu8(v37, v36))),
                (__m128i)0LL));
      v42 = _mm_loadu_si128((const __m128i *)((char *)v27[v33 / 8].m64_f32 + 2));
      v43 = _mm_loadu_si128((const __m128i *)((char *)&v27[v33 / 8].m64_u64 + 1));
      v44 = _mm_adds_epu8(_mm_subs_epu8(v36, v42), _mm_subs_epu8(v42, v36));
      v45 = _mm_avg_epu8(v39, _mm_avg_epu8(v43, v42));
      v46 = _mm_load_si128(&si128);
      v47 = _mm_or_si128(
              _mm_or_si128(
                v41,
                _mm_cmpeq_epi8(
                  _mm_subs_epu8(v46, _mm_adds_epu8(_mm_subs_epu8(v36, v43), _mm_subs_epu8(v43, v36))),
                  (__m128i)0LL)),
              _mm_cmpeq_epi8(_mm_subs_epu8(v46, v44), (__m128i)0LL));
      v48 = _mm_adds_epu8(_mm_and_si128(v36, v47), _mm_andnot_si128(v47, _mm_avg_epu8(v45, v36)));
      v27[v33 / 8 - 2] = v34;
      v27[v33 / 8 - 1] = v35;
      v34 = _mm_movepi64_pi64(v48);
      v35 = _mm_movepi64_pi64(_mm_srli_si128(v48, 8));
      v33 += 16;
      if ( (int)v33 >= a5 )
        break;
      si128 = _mm_load_si128(v28++);
    }
    v27[v33 / 8 - 2] = v34;
    if ( v33 == a5 )
      v27[v33 / 8 - 1] = v35;
    a1 = (const __m128i *)((char *)v26 + result);
    a2 = (__m128i *)((char *)v27 + a4);
    result = a3;
    si128 = _mm_load_si128(a6);
    v7 = a6 + 1;
    --a7;
  }
  while ( a7 );
  return result;
}

