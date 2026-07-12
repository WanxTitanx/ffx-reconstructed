// Function: sub_A80818
// Address: 0xa80818
// Size: 0x32a
// Prototype: 

int __cdecl sub_A80818(__m64 *a1, int a2, __m64 **a3, int a4)
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
  __m64 *v37; // ecx
  __m64 *v38; // edx
  __m64 *v39; // ebx
  __m64 *v40; // edi
  __m64 v41; // mm7
  __m64 v42; // mm0
  __m64 v43; // mm4
  __m64 v44; // mm1
  __m64 v45; // mm5
  __m64 v46; // mm6
  __m64 *v47; // esi
  __m64 *v48; // ecx
  __m64 *v49; // edx
  __m64 *v50; // ebx
  __m64 *v51; // edi
  __m64 v52; // mm7
  __m64 v53; // mm0
  __m64 v54; // mm4
  __m64 v55; // mm1
  __m64 v56; // mm5
  __m64 v57; // mm6
  __m64 *v58; // esi
  __m64 *v59; // ecx
  __m64 *v60; // edx
  __m64 *v61; // ebx
  __m64 *v62; // edi
  __m64 v63; // mm7
  __m64 v64; // mm0
  __m64 v65; // mm4
  __m64 v66; // mm1
  __m64 v67; // mm5
  __m64 v68; // mm6
  __m64 *v69; // esi
  __m64 *v70; // ecx
  __m64 *v71; // edx
  __m64 *v72; // ebx
  __m64 *v73; // edi
  __m64 v74; // mm7
  __m64 v75; // mm0
  __m64 v76; // mm4
  __m64 v77; // mm1
  __m64 v78; // mm5
  __m64 v79; // mm6
  __m64 *v80; // esi
  __m64 *v81; // edi
  __m64 v82; // mm7
  __m64 v83; // mm0
  __m64 v84; // mm4
  __m64 *v85; // ecx
  __m64 v86; // mm6
  int v87; // [esp+0h] [ebp-10h]

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
  v37 = (__m64 *)((char *)v26 + 2 * a4);
  v38 = (__m64 *)((char *)v27 + 2 * a4);
  v39 = (__m64 *)((char *)v28 + 2 * a4);
  v40 = (__m64 *)((char *)v29 + 2 * a4);
  v41 = _m_paddw(_m_paddw(v30, _m_psadbw(v33, v31)), _m_psadbw((__m64)v40->m64_u64, (__m64)v36->m64_u64));
  v42 = *(__m64 *)((char *)v36 + a2);
  v43 = _m_paddw(
          _m_paddw(v32, _m_psadbw((__m64)v37->m64_u64, (__m64)v36->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v37 + a4), v42));
  v44 = *(__m64 *)((char *)v40 + a4);
  v45 = _m_paddw(
          _m_paddw(v34, _m_psadbw((__m64)v38->m64_u64, (__m64)v36->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v38 + a4), v42));
  v46 = _m_paddw(
          _m_paddw(v35, _m_psadbw((__m64)v39->m64_u64, (__m64)v36->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v39 + a4), v42));
  v47 = (__m64 *)((char *)v36 + 2 * a2);
  v48 = (__m64 *)((char *)v37 + 2 * a4);
  v49 = (__m64 *)((char *)v38 + 2 * a4);
  v50 = (__m64 *)((char *)v39 + 2 * a4);
  v51 = (__m64 *)((char *)v40 + 2 * a4);
  v52 = _m_paddw(_m_paddw(v41, _m_psadbw(v44, v42)), _m_psadbw((__m64)v51->m64_u64, (__m64)v47->m64_u64));
  v53 = *(__m64 *)((char *)v47 + a2);
  v54 = _m_paddw(
          _m_paddw(v43, _m_psadbw((__m64)v48->m64_u64, (__m64)v47->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v48 + a4), v53));
  v55 = *(__m64 *)((char *)v51 + a4);
  v56 = _m_paddw(
          _m_paddw(v45, _m_psadbw((__m64)v49->m64_u64, (__m64)v47->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v49 + a4), v53));
  v57 = _m_paddw(
          _m_paddw(v46, _m_psadbw((__m64)v50->m64_u64, (__m64)v47->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v50 + a4), v53));
  v58 = (__m64 *)((char *)v47 + 2 * a2);
  v59 = (__m64 *)((char *)v48 + 2 * a4);
  v60 = (__m64 *)((char *)v49 + 2 * a4);
  v61 = (__m64 *)((char *)v50 + 2 * a4);
  v62 = (__m64 *)((char *)v51 + 2 * a4);
  v63 = _m_paddw(_m_paddw(v52, _m_psadbw(v55, v53)), _m_psadbw((__m64)v62->m64_u64, (__m64)v58->m64_u64));
  v64 = *(__m64 *)((char *)v58 + a2);
  v65 = _m_paddw(
          _m_paddw(v54, _m_psadbw((__m64)v59->m64_u64, (__m64)v58->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v59 + a4), v64));
  v66 = *(__m64 *)((char *)v62 + a4);
  v67 = _m_paddw(
          _m_paddw(v56, _m_psadbw((__m64)v60->m64_u64, (__m64)v58->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v60 + a4), v64));
  v68 = _m_paddw(
          _m_paddw(v57, _m_psadbw((__m64)v61->m64_u64, (__m64)v58->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v61 + a4), v64));
  v69 = (__m64 *)((char *)v58 + 2 * a2);
  v70 = (__m64 *)((char *)v59 + 2 * a4);
  v71 = (__m64 *)((char *)v60 + 2 * a4);
  v72 = (__m64 *)((char *)v61 + 2 * a4);
  v73 = (__m64 *)((char *)v62 + 2 * a4);
  v74 = _m_paddw(_m_paddw(v63, _m_psadbw(v66, v64)), _m_psadbw((__m64)v73->m64_u64, (__m64)v69->m64_u64));
  v75 = *(__m64 *)((char *)v69 + a2);
  v76 = _m_paddw(
          _m_paddw(v65, _m_psadbw((__m64)v70->m64_u64, (__m64)v69->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v70 + a4), v75));
  v77 = *(__m64 *)((char *)v73 + a4);
  v78 = _m_paddw(
          _m_paddw(v67, _m_psadbw((__m64)v71->m64_u64, (__m64)v69->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v71 + a4), v75));
  v79 = _m_paddw(
          _m_paddw(v68, _m_psadbw((__m64)v72->m64_u64, (__m64)v69->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v72 + a4), v75));
  v80 = (__m64 *)((char *)v69 + 2 * a2);
  v81 = (__m64 *)((char *)v73 + 2 * a4);
  v82 = _m_paddw(_m_paddw(v74, _m_psadbw(v77, v75)), _m_psadbw((__m64)v81->m64_u64, (__m64)v80->m64_u64));
  v83 = *(__m64 *)((char *)v80 + a2);
  v84 = _m_paddw(
          _m_paddw(v76, _m_psadbw(*(__m64 *)((char *)v70 + 2 * a4), (__m64)v80->m64_u64)),
          _m_psadbw(*(__m64 *)((char *)v70 + 2 * a4 + a4), v83));
  v85 = *(__m64 **)(v87 + 24);
  v86 = _m_punpckldq(
          _m_paddw(
            _m_paddw(v79, _m_psadbw(*(__m64 *)((char *)v72 + 2 * a4), (__m64)v80->m64_u64)),
            _m_psadbw(*(__m64 *)((char *)v72 + 2 * a4 + a4), v83)),
          _m_paddw(v82, _m_psadbw(*(__m64 *)((char *)v81 + a4), v83)));
  v85->m64_u64 = (unsigned __int64)_m_punpckldq(
                                     v84,
                                     _m_paddw(
                                       _m_paddw(v78, _m_psadbw(*(__m64 *)((char *)v71 + 2 * a4), (__m64)v80->m64_u64)),
                                       _m_psadbw(*(__m64 *)((char *)v71 + 2 * a4 + a4), v83)));
  v85[1].m64_u64 = (unsigned __int64)v86;
  return a2;
}

