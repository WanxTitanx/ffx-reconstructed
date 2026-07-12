// Function: sub_A80B42
// Address: 0xa80b42
// Size: 0x1a2
// Prototype: 

int __cdecl sub_A80B42(__m64 *a1, int a2, __m64 **a3, int a4)
{
  __m64 *v4; // edx
  __m64 *v5; // edi
  __m64 *v7; // et0
  __m64 v8; // mm7
  __m64 v9; // mm0
  __m64 v10; // mm1
  __m64 v11; // mm5
  __m64 *v12; // esi
  __m64 *v13; // ecx
  __m64 *v14; // edx
  __m64 *v15; // ebx
  __m64 *v16; // edi
  __m64 v17; // mm4
  __m64 v18; // mm6
  __m64 v19; // mm7
  __m64 v20; // mm0
  __m64 v21; // mm4
  __m64 v22; // mm1
  __m64 v23; // mm5
  __m64 v24; // mm6
  __m64 *v25; // esi
  __m64 *v26; // ecx
  __m64 *v27; // edx
  __m64 *v28; // ebx
  __m64 *v29; // edi
  __m64 v30; // mm7
  __m64 v31; // mm0
  __m64 v32; // mm4
  __m64 v33; // mm1
  __m64 v34; // mm5
  __m64 v35; // mm6
  __m64 *v36; // esi
  __m64 *v37; // edi
  __m64 v38; // mm7
  __m64 v39; // mm0
  __m64 v40; // mm4
  __m64 *v41; // ecx
  __m64 v42; // mm6
  int v43; // [esp+0h] [ebp-10h]

  v4 = a3[1];
  v5 = a3[3];
  v7 = a3[2];
  v8 = _m_psadbw((__m64)v5->m64_u64, (__m64)a1->m64_u64);
  v9 = *(__m64 *)((char *)a1 + a2);
  v10 = *(__m64 *)((char *)v5 + a4);
  v11 = _m_paddw(_m_psadbw((__m64)v4->m64_u64, (__m64)a1->m64_u64), _m_psadbw(*(__m64 *)((char *)v4 + a4), v9));
  v12 = (__m64 *)((char *)a1 + 2 * a2);
  v13 = (__m64 *)((char *)*a3 + 2 * a4);
  v14 = (__m64 *)((char *)v4 + 2 * a4);
  v15 = (__m64 *)((char *)v7 + 2 * a4);
  v16 = (__m64 *)((char *)v5 + 2 * a4);
  v17 = _m_paddw(
          _m_paddw(_m_psadbw((__m64)(*a3)->m64_u64, (__m64)a1->m64_u64), _m_psadbw(*(__m64 *)((char *)*a3 + a4), v9)),
          _m_psadbw((__m64)v13->m64_u64, (__m64)v12->m64_u64));
  v18 = _m_paddw(
          _m_paddw(_m_psadbw((__m64)v7->m64_u64, (__m64)a1->m64_u64), _m_psadbw(*(__m64 *)((char *)v7 + a4), v9)),
          _m_psadbw((__m64)v15->m64_u64, (__m64)v12->m64_u64));
  v19 = _m_paddw(_m_paddw(v8, _m_psadbw(v10, v9)), _m_psadbw((__m64)v16->m64_u64, (__m64)v12->m64_u64));
  v20 = *(__m64 *)((char *)v12 + a2);
  v21 = _m_paddw(v17, _m_psadbw(*(__m64 *)((char *)v13 + a4), v20));
  v22 = *(__m64 *)((char *)v16 + a4);
  v23 = _m_paddw(
          _m_paddw(v11, _m_psadbw((__m64)v14->m64_u64, (__m64)v12->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v14 + a4), v20));
  v24 = _m_paddw(v18, _m_psadbw(*(__m64 *)((char *)v15 + a4), v20));
  v25 = (__m64 *)((char *)v12 + 2 * a2);
  v26 = (__m64 *)((char *)v13 + 2 * a4);
  v27 = (__m64 *)((char *)v14 + 2 * a4);
  v28 = (__m64 *)((char *)v15 + 2 * a4);
  v29 = (__m64 *)((char *)v16 + 2 * a4);
  v30 = _m_paddw(_m_paddw(v19, _m_psadbw(v22, v20)), _m_psadbw((__m64)v29->m64_u64, (__m64)v25->m64_u64));
  v31 = *(__m64 *)((char *)v25 + a2);
  v32 = _m_paddw(
          _m_paddw(v21, _m_psadbw((__m64)v26->m64_u64, (__m64)v25->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v26 + a4), v31));
  v33 = *(__m64 *)((char *)v29 + a4);
  v34 = _m_paddw(
          _m_paddw(v23, _m_psadbw((__m64)v27->m64_u64, (__m64)v25->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v27 + a4), v31));
  v35 = _m_paddw(
          _m_paddw(v24, _m_psadbw((__m64)v28->m64_u64, (__m64)v25->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v28 + a4), v31));
  v36 = (__m64 *)((char *)v25 + 2 * a2);
  v37 = (__m64 *)((char *)v29 + 2 * a4);
  v38 = _m_paddw(_m_paddw(v30, _m_psadbw(v33, v31)), _m_psadbw((__m64)v37->m64_u64, (__m64)v36->m64_u64));
  v39 = *(__m64 *)((char *)v36 + a2);
  v40 = _m_paddw(
          _m_paddw(v32, _m_psadbw(*(__m64 *)((char *)v26 + 2 * a4), (__m64)v36->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v26 + 2 * a4 + a4), v39));
  v41 = *(__m64 **)(v43 + 24);
  v42 = _m_punpckldq(
          _m_paddw(
            _m_paddw(v35, _m_psadbw(*(__m64 *)((char *)v28 + 2 * a4), (__m64)v36->m64_u64)),
            _m_psadbw(*(__m64 *)((char *)v28 + 2 * a4 + a4), v39)),
          _m_paddw(v38, _m_psadbw(*(__m64 *)((char *)v37 + a4), v39)));
  v41->m64_u64 = (unsigned __int64)_m_punpckldq(
                                     v40,
                                     _m_paddw(
                                       _m_paddw(v34, _m_psadbw(*(__m64 *)((char *)v27 + 2 * a4), (__m64)v36->m64_u64)),
                                       _m_psadbw(*(__m64 *)((char *)v27 + 2 * a4 + a4), v39)));
  v41[1].m64_u64 = (unsigned __int64)v42;
  return a2;
}

