// Function: sub_8135E0
// Address: 0x8135e0
__int16 __cdecl sub_8135E0(int a1, int a2, int a3)
{
  int v4; // esi
  int v5; // esi
  int v6; // eax
  __int16 v7; // dx
  __int16 v8; // si
  int v9; // ecx
  int v10; // ebx
  __int16 v11; // ax
  __int16 v12; // dx
  __int16 v13; // bx
  __int16 v14; // bx
  int v15; // esi
  __int16 v16; // si
  int v17; // eax
  int v18; // ecx
  int v19; // esi
  int v20; // edx
  int v21; // ecx
  int v22; // ebx
  double v23; // st6
  int v24; // eax
  double v25; // st6
  __int16 v26; // cx
  __int16 v27; // dx
  int v28; // esi
  int v29; // edx
  __int16 v30; // bx
  __int16 v31; // si
  int v32; // eax
  int v33; // ecx
  int v34; // edx
  int v35; // esi
  double v36; // st6
  int v37; // eax
  int v38; // ebx
  __int16 v39; // cx
  __int16 result; // ax
  __int16 v41; // si
  int v42; // [esp+1Ch] [ebp-14h]
  __int16 v43; // [esp+24h] [ebp-Ch]
  int v44; // [esp+24h] [ebp-Ch]
  int v45; // [esp+28h] [ebp-8h]
  int v46; // [esp+2Ch] [ebp-4h]
  int v47; // [esp+38h] [ebp+8h]
  float v48; // [esp+38h] [ebp+8h]
  float v49; // [esp+38h] [ebp+8h]
  __int16 v50; // [esp+38h] [ebp+8h]
  float v51; // [esp+38h] [ebp+8h]
  int v52; // [esp+38h] [ebp+8h]
  float v53; // [esp+38h] [ebp+8h]
  int v54; // [esp+3Ch] [ebp+Ch]
  float v55; // [esp+3Ch] [ebp+Ch]
  float v56; // [esp+3Ch] [ebp+Ch]
  int v57; // [esp+3Ch] [ebp+Ch]
  float v58; // [esp+3Ch] [ebp+Ch]
  float v59; // [esp+3Ch] [ebp+Ch]
  int v60; // [esp+40h] [ebp+10h]

  v4 = *(__int16 *)a1 % *(_WORD *)(a1 + 2);
  *(_QWORD *)&n1065353216 = *(_QWORD *)a2;
  n1065353216_2 = *(_DWORD *)(a2 + 8);
  n1065353216_3 = *(_DWORD *)(a2 + 12);
  v5 = a1 + 32 * (v4 + 1);
  *(_QWORD *)v5 = *(_QWORD *)&n1065353216;
  *(_DWORD *)(v5 + 8) = n1065353216_2;
  *(_DWORD *)(v5 + 12) = n1065353216_3;
  *(_QWORD *)&n1065353216 = *(_QWORD *)a3;
  n1065353216_2 = *(_DWORD *)(a3 + 8);
  n1065353216_3 = *(_DWORD *)(a3 + 12);
  *(_QWORD *)(v5 + 16) = *(_QWORD *)&n1065353216;
  *(_DWORD *)(v5 + 24) = n1065353216_2;
  *(float *)(v5 + 28) = 1.0;
  *(float *)(v5 + 12) = 1.0;
  *(_WORD *)(a1 + 8) = 0;
  if ( *(_WORD *)a1 )
  {
    v42 = 32 * *(__int16 *)(a1 + 2);
    v6 = sub_7E6910(v42);
    v7 = *(_WORD *)(a1 + 2);
    v8 = *(_WORD *)a1;
    v9 = v7;
    v10 = v6;
    v45 = v6;
    v46 = v6 + 16 * v7;
    if ( *(__int16 *)a1 < v7 )
      v60 = v8 + 1;
    else
      v60 = v7;
    v11 = *(_WORD *)(a1 + 6);
    if ( v8 < v11 )
    {
      v12 = 1;
    }
    else
    {
      v9 = v7;
      v12 = v8 % v11 + 1;
    }
    *(_WORD *)(a1 + 10) = v12 * *(_WORD *)(a1 + 4);
    v47 = v10;
    v54 = 0;
    v13 = (__int16)(v8 - *(_WORD *)(a1 + 2) + 1) < 0 ? 0 : v8 - *(_WORD *)(a1 + 2) + 1;
    if ( v9 > 0 )
    {
      do
      {
        v14 = v13 % *(_WORD *)(a1 + 2);
        v15 = unknown_libname_741(*(_DWORD *)(a1 + 24)) + 32 * v14;
        *(_QWORD *)&n1065353216 = *(_QWORD *)v15;
        n1065353216_2 = *(_DWORD *)(v15 + 8);
        n1065353216_3 = *(_DWORD *)(v15 + 12);
        *(_QWORD *)v47 = *(_QWORD *)&n1065353216;
        *(_DWORD *)(v47 + 8) = n1065353216_2;
        *(_DWORD *)(v47 + 12) = n1065353216_3;
        v47 += 16;
        v13 = v14 + 1;
        ++v54;
      }
      while ( v54 < *(__int16 *)(a1 + 2) );
    }
    sub_7EA1E0(v46, v45, v60);
    v43 = *(_WORD *)(a1 + 4);
    v16 = *(__int16 *)a1 % *(_WORD *)(a1 + 6);
    v17 = unknown_libname_741(*(_DWORD *)(a1 + 28));
    v18 = v16;
    v19 = v46;
    v20 = v18 * v43;
    v21 = v60;
    v22 = 32 * v20 + v17;
    v55 = *(float *)(v46 + 4 * v60 - 8);
    v48 = 1.0 - v55;
    v23 = v48;
    if ( 0.0 == v48 )
      v23 = (float)1.0e-11;
    v24 = v43;
    v25 = v23 / (double)v43;
    v44 = 1;
    v49 = v25;
    v56 = v55 + v49;
    if ( v24 >= 1 )
    {
      do
      {
        sub_7EA030(v22, v56, v45, v46, v21);
        *(float *)(v22 + 12) = 1.0;
        v22 += 32;
        ++v44;
        v56 = v49 + v56;
        v21 = v60;
      }
      while ( v44 <= *(__int16 *)(a1 + 4) );
    }
    v26 = *(_WORD *)(a1 + 2);
    v57 = 0;
    v27 = (__int16)(*(_WORD *)a1 - v26 + 1) < 0 ? 0 : *(_WORD *)a1 - v26 + 1;
    if ( v26 > 0 )
    {
      v28 = v45;
      do
      {
        v50 = v27 % *(_WORD *)(a1 + 2);
        v29 = 32 * v50 + unknown_libname_741(*(_DWORD *)(a1 + 24));
        *(_QWORD *)&n1065353216 = *(_QWORD *)(v29 + 16);
        n1065353216_2 = *(_DWORD *)(v29 + 24);
        n1065353216_3 = *(_DWORD *)(v29 + 28);
        *(_QWORD *)v28 = *(_QWORD *)&n1065353216;
        *(_DWORD *)(v28 + 8) = n1065353216_2;
        *(_DWORD *)(v28 + 12) = n1065353216_3;
        v27 = v50 + 1;
        v28 += 16;
        ++v57;
      }
      while ( v57 < *(__int16 *)(a1 + 2) );
      v19 = v46;
    }
    sub_7EA1E0(v19, v45, v60);
    v30 = *(_WORD *)(a1 + 4);
    v31 = *(__int16 *)a1 % *(_WORD *)(a1 + 6);
    v32 = unknown_libname_741(*(_DWORD *)(a1 + 28));
    v33 = v46;
    v34 = v60;
    v35 = v32 + 32 * v30 * v31 + 16;
    v58 = *(float *)(v46 + 4 * v60 - 8);
    v51 = 1.0 - v58;
    v36 = v51;
    if ( 0.0 == v51 )
      v36 = (float)1.0e-11;
    v37 = v30;
    v52 = v30;
    v38 = 1;
    v53 = v36 / (double)v52;
    v59 = v58 + v53;
    if ( v37 >= 1 )
    {
      do
      {
        sub_7EA030(v35, v59, v45, v33, v34);
        v33 = v46;
        *(float *)(v35 + 12) = 1.0;
        v34 = v60;
        ++v38;
        v35 += 32;
        v59 = v53 + v59;
      }
      while ( v38 <= *(__int16 *)(a1 + 4) );
    }
    v39 = *(_WORD *)(a1 + 6);
    if ( *(__int16 *)a1 < v39 )
      v39 = *(_WORD *)a1;
    *(_WORD *)(a1 + 8) = v39 * *(_WORD *)(a1 + 4);
    sub_7E6970(v42);
  }
  result = ++*(_WORD *)a1;
  if ( *(__int16 *)a1 >= 4096 )
  {
    v41 = *(_WORD *)(a1 + 2);
    *(_WORD *)a1 = v41 + result % v41;
    result /= v41;
  }
  return result;
}
