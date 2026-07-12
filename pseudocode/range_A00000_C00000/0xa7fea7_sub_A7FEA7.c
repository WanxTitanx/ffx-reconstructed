// Function: sub_A7FEA7
// Address: 0xa7fea7
// Size: 0x13d
// Prototype: 

int __cdecl sub_A7FEA7(__m64 *a1, int a2, int a3, int a4, __m64 *a5)
{
  __m64 v6; // mm0
  __m64 *v7; // esi
  int v8; // edi
  __m64 v9; // mm5
  __m64 v10; // mm6
  __m64 v11; // mm7
  __m64 v12; // mm0
  __m64 v13; // mm1
  __m64 v14; // mm2
  __m64 v15; // mm3
  __m64 *v16; // esi
  int v17; // edi
  __m64 v18; // mm5
  __m64 v19; // mm6
  __m64 v20; // mm7
  __m64 v21; // mm0
  __m64 v22; // mm1
  __m64 v23; // mm2
  __m64 v24; // mm3
  __m64 *v25; // esi
  int v26; // edi
  __m64 v27; // mm5
  __m64 v28; // mm6
  __m64 v29; // mm7
  __m64 v30; // mm0
  __m64 v31; // mm7

  v6 = *(__m64 *)((char *)a1 + a2);
  v7 = (__m64 *)((char *)a1 + 2 * a2);
  v8 = a3 + 2 * a4;
  v9 = _m_paddw(
         _m_paddw(_m_psadbw(*(__m64 *)a3, (__m64)a1->m64_u64), _m_psadbw(*(__m64 *)(a3 + a4), v6)),
         _m_psadbw(*(__m64 *)v8, (__m64)v7->m64_u64));
  v10 = _m_paddw(
          _m_paddw(_m_psadbw(*(__m64 *)(a3 + 1), (__m64)a1->m64_u64), _m_psadbw(*(__m64 *)(a3 + a4 + 1), v6)),
          _m_psadbw(*(__m64 *)(v8 + 1), (__m64)v7->m64_u64));
  v11 = _m_paddw(
          _m_paddw(_m_psadbw(*(__m64 *)(a3 + 2), (__m64)a1->m64_u64), _m_psadbw(*(__m64 *)(a3 + a4 + 2), v6)),
          _m_psadbw(*(__m64 *)(v8 + 2), (__m64)v7->m64_u64));
  v12 = *(__m64 *)((char *)v7 + a2);
  v13 = *(__m64 *)(v8 + a4);
  v14 = *(__m64 *)(v8 + a4 + 1);
  v15 = *(__m64 *)(v8 + a4 + 2);
  v16 = (__m64 *)((char *)v7 + 2 * a2);
  v17 = v8 + 2 * a4;
  v18 = _m_paddw(_m_paddw(v9, _m_psadbw(v13, v12)), _m_psadbw(*(__m64 *)v17, (__m64)v16->m64_u64));
  v19 = _m_paddw(_m_paddw(v10, _m_psadbw(v14, v12)), _m_psadbw(*(__m64 *)(v17 + 1), (__m64)v16->m64_u64));
  v20 = _m_paddw(_m_paddw(v11, _m_psadbw(v15, v12)), _m_psadbw(*(__m64 *)(v17 + 2), (__m64)v16->m64_u64));
  v21 = *(__m64 *)((char *)v16 + a2);
  v22 = *(__m64 *)(v17 + a4);
  v23 = *(__m64 *)(v17 + a4 + 1);
  v24 = *(__m64 *)(v17 + a4 + 2);
  v25 = (__m64 *)((char *)v16 + 2 * a2);
  v26 = v17 + 2 * a4;
  v27 = _m_paddw(_m_paddw(v18, _m_psadbw(v22, v21)), _m_psadbw(*(__m64 *)v26, (__m64)v25->m64_u64));
  v28 = _m_paddw(_m_paddw(v19, _m_psadbw(v23, v21)), _m_psadbw(*(__m64 *)(v26 + 1), (__m64)v25->m64_u64));
  v29 = _m_paddw(_m_paddw(v20, _m_psadbw(v24, v21)), _m_psadbw(*(__m64 *)(v26 + 2), (__m64)v25->m64_u64));
  v30 = *(__m64 *)((char *)v25 + a2);
  v31 = _m_paddw(v29, _m_psadbw(*(__m64 *)(v26 + a4 + 2), v30));
  a5->m64_u64 = (unsigned __int64)_m_punpckldq(
                                    _m_paddw(v27, _m_psadbw(*(__m64 *)(v26 + a4), v30)),
                                    _m_paddw(v28, _m_psadbw(*(__m64 *)(v26 + a4 + 1), v30)));
  a5[1].m64_i32[0] = _mm_cvtsi64_si32(v31);
  return a2;
}

