// Function: sub_9B2DD0
// Address: 0x9b2dd0
char __stdcall sub_9B2DD0(float *a1, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  double v7; // st7
  double v8; // st6
  int v9; // eax
  double v10; // st7
  double v11; // st4
  double v12; // st3
  int v13; // eax
  double v14; // rt2
  double v15; // st4
  double v16; // st6
  double v17; // st4
  double v18; // st5
  double v19; // st7
  double v20; // st5
  double v21; // st6
  float v22; // [esp-80h] [ebp-8Ch]
  float v23; // [esp-7Ch] [ebp-88h]
  float v24; // [esp-78h] [ebp-84h]
  float v25; // [esp-70h] [ebp-7Ch]
  float v26; // [esp-70h] [ebp-7Ch]
  float v27; // [esp-70h] [ebp-7Ch]
  float v28; // [esp-70h] [ebp-7Ch]
  float v29; // [esp-70h] [ebp-7Ch]
  float v30; // [esp-70h] [ebp-7Ch]
  float v31; // [esp-70h] [ebp-7Ch]
  float v32; // [esp-6Ch] [ebp-78h]
  float v33; // [esp-6Ch] [ebp-78h]
  float v34; // [esp-6Ch] [ebp-78h]
  float v35; // [esp-6Ch] [ebp-78h]
  float v36; // [esp-6Ch] [ebp-78h]
  float v37; // [esp-6Ch] [ebp-78h]
  float v38; // [esp-6Ch] [ebp-78h]
  float v39; // [esp-68h] [ebp-74h]
  float v40; // [esp-68h] [ebp-74h]
  float v41; // [esp-68h] [ebp-74h]
  float v42; // [esp-68h] [ebp-74h]
  float v43; // [esp-68h] [ebp-74h]
  float v44; // [esp-68h] [ebp-74h]
  float v45; // [esp-68h] [ebp-74h]
  float v46; // [esp-60h] [ebp-6Ch]
  float v47; // [esp-60h] [ebp-6Ch]
  float v48; // [esp-60h] [ebp-6Ch]
  float v49; // [esp-60h] [ebp-6Ch]
  float v50; // [esp-60h] [ebp-6Ch]
  float v51; // [esp-5Ch] [ebp-68h]
  float v52; // [esp-5Ch] [ebp-68h]
  float v53; // [esp-5Ch] [ebp-68h]
  float v54; // [esp-5Ch] [ebp-68h]
  float v55; // [esp-5Ch] [ebp-68h]
  float v56; // [esp-58h] [ebp-64h]
  float v57; // [esp-58h] [ebp-64h]
  float v58; // [esp-58h] [ebp-64h]
  float v59; // [esp-58h] [ebp-64h]
  float v60; // [esp-58h] [ebp-64h]
  float v61; // [esp-50h] [ebp-5Ch]
  float v62; // [esp-50h] [ebp-5Ch]
  float v63; // [esp-50h] [ebp-5Ch]
  float v64; // [esp-4Ch] [ebp-58h]
  float v65; // [esp-4Ch] [ebp-58h]
  float v66; // [esp-4Ch] [ebp-58h]
  float v67; // [esp-48h] [ebp-54h]
  float v68; // [esp-48h] [ebp-54h]
  float v69; // [esp-48h] [ebp-54h]
  float v70; // [esp-40h] [ebp-4Ch]
  float v71; // [esp-40h] [ebp-4Ch]
  float v72; // [esp-40h] [ebp-4Ch]
  float v73; // [esp-40h] [ebp-4Ch]
  float v74; // [esp-3Ch] [ebp-48h]
  float v75; // [esp-3Ch] [ebp-48h]
  float v76; // [esp-3Ch] [ebp-48h]
  float v77; // [esp-3Ch] [ebp-48h]
  float v78; // [esp-3Ch] [ebp-48h]
  float v79; // [esp-38h] [ebp-44h]
  float v80; // [esp-34h] [ebp-40h]
  float v81; // [esp-30h] [ebp-3Ch]
  float v82; // [esp-2Ch] [ebp-38h]
  float v83; // [esp-28h] [ebp-34h]
  float v84; // [esp-24h] [ebp-30h]
  float v85; // [esp-20h] [ebp-2Ch]
  float v86; // [esp-20h] [ebp-2Ch]
  float v87; // [esp-20h] [ebp-2Ch]
  float v88; // [esp-1Ch] [ebp-28h]
  float v89; // [esp-1Ch] [ebp-28h]
  float v90; // [esp-18h] [ebp-24h]
  float v91; // [esp-14h] [ebp-20h]
  float v92; // [esp-10h] [ebp-1Ch]
  float v93; // [esp-Ch] [ebp-18h]
  float v94; // [esp-8h] [ebp-14h]
  float v95; // [esp-4h] [ebp-10h]

  *(_WORD *)(a5 + 16) &= 0xFFF0u;
  v83 = *(float *)a3;
  v93 = *(float *)a2;
  v46 = *(float *)a3 - *(float *)a2;
  v81 = *(float *)(a3 + 4);
  v92 = *(float *)(a2 + 4);
  v51 = v81 - v92;
  v79 = *(float *)(a3 + 8);
  v91 = *(float *)(a2 + 8);
  v56 = v79 - v91;
  v84 = *(float *)a4;
  v61 = *(float *)a4 - *(float *)a2;
  v82 = *(float *)(a4 + 4);
  v64 = v82 - v92;
  v80 = *(float *)(a4 + 8);
  v67 = v80 - v91;
  v90 = *a1;
  v25 = *a1 - *(float *)a2;
  v88 = a1[1];
  v32 = v88 - v92;
  v85 = a1[2];
  v39 = v85 - v91;
  v95 = v32 * v51 + v25 * v46 + v39 * v56;
  v94 = v39 * v67 + v32 * v64 + v25 * v61;
  if ( v95 <= 0.0 && v94 <= 0.0 )
  {
    *(_DWORD *)a5 = *(_DWORD *)a2;
    *(_DWORD *)(a5 + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(a5 + 8) = *(_DWORD *)(a2 + 8);
    v5 = *(_DWORD *)(a2 + 12);
    *(_WORD *)(a5 + 16) |= 1u;
    *(_DWORD *)(a5 + 12) = v5;
    *(_DWORD *)(a5 + 20) = 1065353216;
    *(_DWORD *)(a5 + 24) = 0;
    *(_DWORD *)(a5 + 28) = 0;
    *(_DWORD *)(a5 + 32) = 0;
    return 1;
  }
  v26 = v90 - v83;
  v33 = v88 - v81;
  v40 = v85 - v79;
  v74 = v51 * v33 + v26 * v46 + v40 * v56;
  v70 = v40 * v67 + v33 * v64 + v26 * v61;
  v7 = v74;
  v8 = v70;
  if ( v74 >= 0.0 )
  {
    if ( v74 >= (double)v70 )
    {
      *(_DWORD *)a5 = *(_DWORD *)a3;
      *(_DWORD *)(a5 + 4) = *(_DWORD *)(a3 + 4);
      *(_DWORD *)(a5 + 8) = *(_DWORD *)(a3 + 8);
      v9 = *(_DWORD *)(a3 + 12);
      *(_WORD *)(a5 + 16) |= 2u;
      *(_DWORD *)(a5 + 12) = v9;
      *(_DWORD *)(a5 + 20) = 0;
      *(_DWORD *)(a5 + 24) = 1065353216;
      *(_DWORD *)(a5 + 28) = 0;
      *(_DWORD *)(a5 + 32) = 0;
      return 1;
    }
    v8 = v70;
    v7 = v74;
  }
  v71 = v8 * v95 - v7 * v94;
  if ( v71 > 0.0 || v95 < 0.0 || v74 > 0.0 )
  {
    v28 = v90 - v84;
    v35 = v88 - v82;
    v42 = v85 - v80;
    v86 = v35 * v51 + v28 * v46 + v42 * v56;
    v76 = v35 * v64 + v28 * v61 + v42 * v67;
    v11 = v76;
    v12 = v86;
    if ( v76 >= 0.0 )
    {
      if ( v76 >= (double)v86 )
      {
        *(_DWORD *)a5 = *(_DWORD *)a4;
        *(_DWORD *)(a5 + 4) = *(_DWORD *)(a4 + 4);
        *(_DWORD *)(a5 + 8) = *(_DWORD *)(a4 + 8);
        v13 = *(_DWORD *)(a4 + 12);
        *(_WORD *)(a5 + 16) |= 4u;
        *(_DWORD *)(a5 + 12) = v13;
        *(_DWORD *)(a5 + 20) = 0;
        *(_DWORD *)(a5 + 24) = 0;
        *(_DWORD *)(a5 + 28) = 1065353216;
        *(_DWORD *)(a5 + 32) = 0;
        return 1;
      }
      v12 = v86;
      v11 = v76;
    }
    v89 = v12 * v94 - v11 * v95;
    if ( v89 > 0.0 || v94 < 0.0 || v76 > 0.0 )
    {
      v87 = v11 * v7 - v12 * v8;
      if ( v87 > 0.0 )
      {
        v19 = v87;
      }
      else
      {
        v14 = v11;
        v15 = v8;
        v16 = v14;
        v17 = v15 - v7;
        if ( v17 < 0.0 )
        {
          v19 = v87;
        }
        else
        {
          v18 = v12 - v16;
          if ( v18 >= 0.0 )
          {
            *(_WORD *)(a5 + 16) |= 6u;
            v78 = v17 / (v18 + v17);
            v30 = v84 - v83;
            v37 = v82 - v81;
            v44 = v80 - v79;
            v62 = v30 * v78;
            v65 = v37 * v78;
            v68 = v44 * v78;
            v49 = v83 + v62;
            *(float *)a5 = v49;
            v54 = v81 + v65;
            *(float *)(a5 + 4) = v54;
            v59 = v79 + v68;
            *(float *)(a5 + 8) = v59;
            *(_DWORD *)(a5 + 12) = 0;
            *(_DWORD *)(a5 + 20) = 0;
            *(float *)(a5 + 28) = v78;
            *(float *)(a5 + 24) = 1.0 - v78;
            *(_DWORD *)(a5 + 32) = 0;
            return 1;
          }
          v19 = v87;
        }
      }
      *(_WORD *)(a5 + 16) |= 7u;
      v20 = v71;
      v72 = 1.0 / (v19 + v89 + v71);
      v21 = v72;
      v73 = v89 * v72;
      v77 = v21 * v20;
      v22 = v61 * v77;
      v23 = v64 * v77;
      v24 = v67 * v77;
      v31 = v46 * v73;
      v38 = v51 * v73;
      v45 = v56 * v73;
      v63 = v31 + v93;
      v66 = v38 + v92;
      v69 = v45 + v91;
      v50 = v63 + v22;
      *(float *)a5 = v50;
      v55 = v66 + v23;
      *(float *)(a5 + 4) = v55;
      v60 = v69 + v24;
      *(float *)(a5 + 8) = v60;
      *(_DWORD *)(a5 + 12) = 0;
      *(float *)(a5 + 24) = v73;
      v10 = 1.0 - v73 - v77;
    }
    else
    {
      *(_WORD *)(a5 + 16) |= 5u;
      v77 = v94 / (v94 - v11);
      v29 = v61 * v77;
      v36 = v64 * v77;
      v43 = v67 * v77;
      v48 = v29 + v93;
      *(float *)a5 = v48;
      v53 = v36 + v92;
      *(float *)(a5 + 4) = v53;
      v58 = v43 + v91;
      *(float *)(a5 + 8) = v58;
      v10 = 1.0 - v77;
      *(_DWORD *)(a5 + 12) = 0;
      *(_DWORD *)(a5 + 24) = 0;
    }
    *(float *)(a5 + 28) = v77;
  }
  else
  {
    *(_WORD *)(a5 + 16) |= 3u;
    v75 = v95 / (v95 - v7);
    v27 = v46 * v75;
    v34 = v51 * v75;
    v41 = v56 * v75;
    v47 = v27 + v93;
    *(float *)a5 = v47;
    v52 = v34 + v92;
    *(float *)(a5 + 4) = v52;
    v57 = v41 + v91;
    *(float *)(a5 + 8) = v57;
    v10 = 1.0 - v75;
    *(_DWORD *)(a5 + 12) = 0;
    *(float *)(a5 + 24) = v75;
    *(_DWORD *)(a5 + 28) = 0;
  }
  *(float *)(a5 + 20) = v10;
  *(_DWORD *)(a5 + 32) = 0;
  return 1;
}
