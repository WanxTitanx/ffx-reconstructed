// Function: sub_A8BD24
// Address: 0xa8bd24
// Size: 0x1fe
// Prototype: 

int __cdecl sub_A8BD24(__m64 *a1, int a2, __m64 *a3, int a4, _DWORD *a5, _DWORD *a6)
{
  __m64 v6; // mm0
  __m64 v7; // mm2
  __m64 v8; // mm5
  __m64 v9; // mm7
  __m64 v10; // mm2
  __m64 v11; // mm3
  __m64 v12; // mm0
  __m64 v13; // mm2
  __m64 v14; // mm5
  __m64 *v15; // ebx
  __m64 *v16; // eax
  __m64 v17; // mm7
  __m64 v18; // mm0
  __m64 v19; // mm2
  __m64 v20; // mm5
  __m64 *v21; // ebx
  __m64 *v22; // eax
  __m64 v23; // mm7
  __m64 v24; // mm0
  __m64 v25; // mm2
  __m64 v26; // mm5
  __m64 *v27; // ebx
  __m64 *v28; // eax
  __m64 v29; // mm7
  __m64 v30; // mm0
  __m64 v31; // mm2
  __m64 v32; // mm5
  __m64 *v33; // ebx
  __m64 *v34; // eax
  __m64 v35; // mm7
  __m64 v36; // mm0
  __m64 v37; // mm2
  __m64 v38; // mm5
  __m64 *v39; // ebx
  __m64 *v40; // eax
  __m64 v41; // mm7
  __m64 v42; // mm0
  __m64 v43; // mm2
  __m64 v44; // mm5
  __m64 v45; // mm7
  __m64 v46; // mm2
  __m64 v47; // mm3
  __m64 v48; // mm0
  __m64 v49; // mm2
  __m64 v50; // kr00_8
  __m64 v52; // [esp+8h] [ebp-14h]

  v6 = _m_psubsw(_m_punpcklbw((__m64)a1->m64_u64, 0), _m_punpcklbw((__m64)a3->m64_u64, 0));
  v7 = _m_psubsw(_m_punpckhbw((__m64)a1->m64_u64, 0), _m_punpckhbw((__m64)a3->m64_u64, 0));
  v8 = _m_paddw(_m_paddw(0, v6), v7);
  v9 = _m_paddd(_m_paddd(0, _m_pmaddwd(v6, v6)), _m_pmaddwd(v7, v7));
  v10 = *(__m64 *)((char *)a1 + a2);
  v11 = *(__m64 *)((char *)a3 + a4);
  v12 = _m_psubsw(_m_punpcklbw(v10, 0), _m_punpcklbw(v11, 0));
  v13 = _m_psubsw(_m_punpckhbw(v10, 0), _m_punpckhbw(v11, 0));
  v14 = _m_paddw(_m_paddw(v8, v12), v13);
  v15 = (__m64 *)((char *)a3 + a4 + a4);
  v16 = (__m64 *)((char *)a1 + a2 + a2);
  v17 = _m_paddd(_m_paddd(v9, _m_pmaddwd(v12, v12)), _m_pmaddwd(v13, v13));
  v18 = _m_psubsw(_m_punpcklbw((__m64)v16->m64_u64, 0), _m_punpcklbw((__m64)v15->m64_u64, 0));
  v19 = _m_psubsw(_m_punpckhbw((__m64)v16->m64_u64, 0), _m_punpckhbw((__m64)v15->m64_u64, 0));
  v20 = _m_paddw(_m_paddw(v14, v18), v19);
  v21 = (__m64 *)((char *)v15 + a4);
  v22 = (__m64 *)((char *)v16 + a2);
  v23 = _m_paddd(_m_paddd(v17, _m_pmaddwd(v18, v18)), _m_pmaddwd(v19, v19));
  v24 = _m_psubsw(_m_punpcklbw((__m64)v22->m64_u64, 0), _m_punpcklbw((__m64)v21->m64_u64, 0));
  v25 = _m_psubsw(_m_punpckhbw((__m64)v22->m64_u64, 0), _m_punpckhbw((__m64)v21->m64_u64, 0));
  v26 = _m_paddw(_m_paddw(v20, v24), v25);
  v27 = (__m64 *)((char *)v21 + a4);
  v28 = (__m64 *)((char *)v22 + a2);
  v29 = _m_paddd(_m_paddd(v23, _m_pmaddwd(v24, v24)), _m_pmaddwd(v25, v25));
  v30 = _m_psubsw(_m_punpcklbw((__m64)v28->m64_u64, 0), _m_punpcklbw((__m64)v27->m64_u64, 0));
  v31 = _m_psubsw(_m_punpckhbw((__m64)v28->m64_u64, 0), _m_punpckhbw((__m64)v27->m64_u64, 0));
  v32 = _m_paddw(_m_paddw(v26, v30), v31);
  v33 = (__m64 *)((char *)v27 + a4);
  v34 = (__m64 *)((char *)v28 + a2);
  v35 = _m_paddd(_m_paddd(v29, _m_pmaddwd(v30, v30)), _m_pmaddwd(v31, v31));
  v36 = _m_psubsw(_m_punpcklbw((__m64)v34->m64_u64, 0), _m_punpcklbw((__m64)v33->m64_u64, 0));
  v37 = _m_psubsw(_m_punpckhbw((__m64)v34->m64_u64, 0), _m_punpckhbw((__m64)v33->m64_u64, 0));
  v38 = _m_paddw(_m_paddw(v32, v36), v37);
  v39 = (__m64 *)((char *)v33 + a4);
  v40 = (__m64 *)((char *)v34 + a2);
  v41 = _m_paddd(_m_paddd(v35, _m_pmaddwd(v36, v36)), _m_pmaddwd(v37, v37));
  v42 = _m_psubsw(_m_punpcklbw((__m64)v40->m64_u64, 0), _m_punpcklbw((__m64)v39->m64_u64, 0));
  v43 = _m_psubsw(_m_punpckhbw((__m64)v40->m64_u64, 0), _m_punpckhbw((__m64)v39->m64_u64, 0));
  v44 = _m_paddw(_m_paddw(v38, v42), v43);
  v45 = _m_paddd(_m_paddd(v41, _m_pmaddwd(v42, v42)), _m_pmaddwd(v43, v43));
  v46 = *(__m64 *)((char *)v40 + a2);
  v47 = *(__m64 *)((char *)v39 + a4);
  v48 = _m_psubsw(_m_punpcklbw(v46, 0), _m_punpcklbw(v47, 0));
  v49 = _m_psubsw(_m_punpckhbw(v46, 0), _m_punpckhbw(v47, 0));
  v52 = _m_paddw(_m_paddw(v44, v48), v49);
  v50 = _m_paddd(_m_paddd(v45, _m_pmaddwd(v48, v48)), _m_pmaddwd(v49, v49));
  *a5 = v50.m64_i32[1] + v50.m64_i32[0];
  *a6 = v52.m64_i16[3] + v52.m64_i16[2] + v52.m64_i16[1] + v52.m64_i16[0];
  return 0;
}

