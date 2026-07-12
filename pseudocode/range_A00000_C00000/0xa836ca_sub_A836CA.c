// Function: sub_A836CA
// Address: 0xa836ca
// Size: 0x14f
// Prototype: 

int __cdecl sub_A836CA(_QWORD *a1, int a2, _QWORD *a3, int a4)
{
  int result; // eax
  __int64 v6; // mm3
  __int64 v7; // mm1
  __int64 v8; // mm4
  __int64 v9; // mm2
  __int64 v10; // mm5
  __int64 *v11; // esi
  _QWORD *v12; // edi
  __int64 v13; // mm0
  __int64 v14; // mm3
  __int64 v15; // mm1
  __int64 v16; // mm4
  __int64 v17; // mm2
  __int64 v18; // mm5
  __int64 *v19; // esi
  _QWORD *v20; // edi
  __int64 v21; // mm0
  __int64 v22; // mm3
  __int64 v23; // mm1
  __int64 v24; // mm4
  __int64 v25; // mm2
  __int64 v26; // mm5
  __int64 *v27; // esi
  _QWORD *v28; // edi
  __int64 v29; // mm0
  __int64 v30; // mm3
  __int64 v31; // mm1
  __int64 v32; // mm4
  __int64 v33; // mm2
  __int64 v34; // mm5
  __int64 *v35; // esi
  _QWORD *v36; // edi
  __int64 v37; // mm0
  __int64 v38; // mm3
  __int64 v39; // mm1
  __int64 v40; // mm4
  __int64 v41; // mm2
  __int64 v42; // mm5
  _QWORD *v43; // esi
  _QWORD *v44; // edi
  __int64 v45; // mm3

  result = a2;
  v6 = a1[1];
  v7 = *(_QWORD *)((char *)a1 + a2);
  v8 = *(_QWORD *)((char *)a1 + a2 + 8);
  v9 = *(_QWORD *)((char *)a1 + 2 * a2);
  v10 = *(_QWORD *)((char *)a1 + 2 * a2 + 8);
  v11 = (_QWORD *)((char *)a1 + 2 * a2 + a2);
  *a3 = *a1;
  a3[1] = v6;
  *(_QWORD *)((char *)a3 + a4) = v7;
  *(_QWORD *)((char *)a3 + a4 + 8) = v8;
  *(_QWORD *)((char *)a3 + 2 * a4) = v9;
  *(_QWORD *)((char *)a3 + 2 * a4 + 8) = v10;
  v12 = (_QWORD *)((char *)a3 + 2 * a4 + a4);
  v13 = *v11;
  v14 = v11[1];
  v15 = *(__int64 *)((char *)v11 + a2);
  v16 = *(__int64 *)((char *)v11 + a2 + 8);
  v17 = *(__int64 *)((char *)v11 + 2 * a2);
  v18 = *(__int64 *)((char *)v11 + 2 * a2 + 8);
  v19 = (__int64 *)((char *)v11 + 2 * result + result);
  *v12 = v13;
  v12[1] = v14;
  *(_QWORD *)((char *)v12 + a4) = v15;
  *(_QWORD *)((char *)v12 + a4 + 8) = v16;
  *(_QWORD *)((char *)v12 + 2 * a4) = v17;
  *(_QWORD *)((char *)v12 + 2 * a4 + 8) = v18;
  v20 = (_QWORD *)((char *)v12 + 2 * a4 + a4);
  v21 = *v19;
  v22 = v19[1];
  v23 = *(__int64 *)((char *)v19 + a2);
  v24 = *(__int64 *)((char *)v19 + a2 + 8);
  v25 = *(__int64 *)((char *)v19 + 2 * a2);
  v26 = *(__int64 *)((char *)v19 + 2 * a2 + 8);
  v27 = (__int64 *)((char *)v19 + 2 * result + result);
  *v20 = v21;
  v20[1] = v22;
  *(_QWORD *)((char *)v20 + a4) = v23;
  *(_QWORD *)((char *)v20 + a4 + 8) = v24;
  *(_QWORD *)((char *)v20 + 2 * a4) = v25;
  *(_QWORD *)((char *)v20 + 2 * a4 + 8) = v26;
  v28 = (_QWORD *)((char *)v20 + 2 * a4 + a4);
  v29 = *v27;
  v30 = v27[1];
  v31 = *(__int64 *)((char *)v27 + a2);
  v32 = *(__int64 *)((char *)v27 + a2 + 8);
  v33 = *(__int64 *)((char *)v27 + 2 * a2);
  v34 = *(__int64 *)((char *)v27 + 2 * a2 + 8);
  v35 = (__int64 *)((char *)v27 + 2 * result + result);
  *v28 = v29;
  v28[1] = v30;
  *(_QWORD *)((char *)v28 + a4) = v31;
  *(_QWORD *)((char *)v28 + a4 + 8) = v32;
  *(_QWORD *)((char *)v28 + 2 * a4) = v33;
  *(_QWORD *)((char *)v28 + 2 * a4 + 8) = v34;
  v36 = (_QWORD *)((char *)v28 + 2 * a4 + a4);
  v37 = *v35;
  v38 = v35[1];
  v39 = *(__int64 *)((char *)v35 + a2);
  v40 = *(__int64 *)((char *)v35 + a2 + 8);
  v41 = *(__int64 *)((char *)v35 + 2 * a2);
  v42 = *(__int64 *)((char *)v35 + 2 * a2 + 8);
  v43 = (__int64 *)((char *)v35 + 2 * result + result);
  *v36 = v37;
  v36[1] = v38;
  *(_QWORD *)((char *)v36 + a4) = v39;
  *(_QWORD *)((char *)v36 + a4 + 8) = v40;
  *(_QWORD *)((char *)v36 + 2 * a4) = v41;
  *(_QWORD *)((char *)v36 + 2 * a4 + 8) = v42;
  v44 = (_QWORD *)((char *)v36 + 2 * a4 + a4);
  v45 = v43[1];
  *v44 = *v43;
  v44[1] = v45;
  return result;
}

