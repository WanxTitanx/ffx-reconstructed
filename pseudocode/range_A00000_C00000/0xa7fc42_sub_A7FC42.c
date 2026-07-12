// Function: sub_A7FC42
// Address: 0xa7fc42
// Size: 0x265
// Prototype: 

int __cdecl sub_A7FC42(__m64 *a1, int a2, int a3, int a4, __m64 *a5)
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
  __m64 v31; // mm1
  __m64 v32; // mm2
  __m64 v33; // mm3
  __m64 *v34; // esi
  int v35; // edi
  __m64 v36; // mm5
  __m64 v37; // mm6
  __m64 v38; // mm7
  __m64 v39; // mm0
  __m64 v40; // mm1
  __m64 v41; // mm2
  __m64 v42; // mm3
  __m64 *v43; // esi
  int v44; // edi
  __m64 v45; // mm5
  __m64 v46; // mm6
  __m64 v47; // mm7
  __m64 v48; // mm0
  __m64 v49; // mm1
  __m64 v50; // mm2
  __m64 v51; // mm3
  __m64 *v52; // esi
  int v53; // edi
  __m64 v54; // mm5
  __m64 v55; // mm6
  __m64 v56; // mm7
  __m64 v57; // mm0
  __m64 v58; // mm1
  __m64 v59; // mm2
  __m64 v60; // mm3
  __m64 *v61; // esi
  int v62; // edi
  __m64 v63; // mm5
  __m64 v64; // mm6
  __m64 v65; // mm7
  __m64 v66; // mm0
  __m64 v67; // mm7

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
  v31 = *(__m64 *)(v26 + a4);
  v32 = *(__m64 *)(v26 + a4 + 1);
  v33 = *(__m64 *)(v26 + a4 + 2);
  v34 = (__m64 *)((char *)v25 + 2 * a2);
  v35 = v26 + 2 * a4;
  v36 = _m_paddw(_m_paddw(v27, _m_psadbw(v31, v30)), _m_psadbw(*(__m64 *)v35, (__m64)v34->m64_u64));
  v37 = _m_paddw(_m_paddw(v28, _m_psadbw(v32, v30)), _m_psadbw(*(__m64 *)(v35 + 1), (__m64)v34->m64_u64));
  v38 = _m_paddw(_m_paddw(v29, _m_psadbw(v33, v30)), _m_psadbw(*(__m64 *)(v35 + 2), (__m64)v34->m64_u64));
  v39 = *(__m64 *)((char *)v34 + a2);
  v40 = *(__m64 *)(v35 + a4);
  v41 = *(__m64 *)(v35 + a4 + 1);
  v42 = *(__m64 *)(v35 + a4 + 2);
  v43 = (__m64 *)((char *)v34 + 2 * a2);
  v44 = v35 + 2 * a4;
  v45 = _m_paddw(_m_paddw(v36, _m_psadbw(v40, v39)), _m_psadbw(*(__m64 *)v44, (__m64)v43->m64_u64));
  v46 = _m_paddw(_m_paddw(v37, _m_psadbw(v41, v39)), _m_psadbw(*(__m64 *)(v44 + 1), (__m64)v43->m64_u64));
  v47 = _m_paddw(_m_paddw(v38, _m_psadbw(v42, v39)), _m_psadbw(*(__m64 *)(v44 + 2), (__m64)v43->m64_u64));
  v48 = *(__m64 *)((char *)v43 + a2);
  v49 = *(__m64 *)(v44 + a4);
  v50 = *(__m64 *)(v44 + a4 + 1);
  v51 = *(__m64 *)(v44 + a4 + 2);
  v52 = (__m64 *)((char *)v43 + 2 * a2);
  v53 = v44 + 2 * a4;
  v54 = _m_paddw(_m_paddw(v45, _m_psadbw(v49, v48)), _m_psadbw(*(__m64 *)v53, (__m64)v52->m64_u64));
  v55 = _m_paddw(_m_paddw(v46, _m_psadbw(v50, v48)), _m_psadbw(*(__m64 *)(v53 + 1), (__m64)v52->m64_u64));
  v56 = _m_paddw(_m_paddw(v47, _m_psadbw(v51, v48)), _m_psadbw(*(__m64 *)(v53 + 2), (__m64)v52->m64_u64));
  v57 = *(__m64 *)((char *)v52 + a2);
  v58 = *(__m64 *)(v53 + a4);
  v59 = *(__m64 *)(v53 + a4 + 1);
  v60 = *(__m64 *)(v53 + a4 + 2);
  v61 = (__m64 *)((char *)v52 + 2 * a2);
  v62 = v53 + 2 * a4;
  v63 = _m_paddw(_m_paddw(v54, _m_psadbw(v58, v57)), _m_psadbw(*(__m64 *)v62, (__m64)v61->m64_u64));
  v64 = _m_paddw(_m_paddw(v55, _m_psadbw(v59, v57)), _m_psadbw(*(__m64 *)(v62 + 1), (__m64)v61->m64_u64));
  v65 = _m_paddw(_m_paddw(v56, _m_psadbw(v60, v57)), _m_psadbw(*(__m64 *)(v62 + 2), (__m64)v61->m64_u64));
  v66 = *(__m64 *)((char *)v61 + a2);
  v67 = _m_paddw(v65, _m_psadbw(*(__m64 *)(v62 + a4 + 2), v66));
  a5->m64_u64 = (unsigned __int64)_m_punpckldq(
                                    _m_paddw(v63, _m_psadbw(*(__m64 *)(v62 + a4), v66)),
                                    _m_paddw(v64, _m_psadbw(*(__m64 *)(v62 + a4 + 1), v66)));
  a5[1].m64_i32[0] = _mm_cvtsi64_si32(v67);
  return a2;
}

