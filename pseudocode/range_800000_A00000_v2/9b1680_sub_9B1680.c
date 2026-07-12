// Function: sub_9B1680
// Address: 0x9b1680
int __userpurge sub_9B1680@<eax>(_DWORD *a1@<ecx>, int a2@<ebp>, float *a3, float *a4, float *a5, char a6)
{
  int v7; // esi
  int v8; // ecx
  int v9; // ecx
  int v10; // eax
  bool v11; // al
  double v12; // st7
  double v13; // st7
  double v14; // st6
  double v15; // st5
  float *v16; // ecx
  double v17; // st7
  float v18; // xmm0_4
  bool v19; // zf
  double v20; // st7
  int v22; // ecx
  int v23; // ecx
  int v24; // eax
  float v25; // [esp-70h] [ebp-7Ch]
  float v26; // [esp-70h] [ebp-7Ch]
  float v27; // [esp-70h] [ebp-7Ch]
  float v28; // [esp-70h] [ebp-7Ch]
  float v29; // [esp-6Ch] [ebp-78h]
  float v30; // [esp-6Ch] [ebp-78h]
  float v31; // [esp-6Ch] [ebp-78h]
  float v32; // [esp-6Ch] [ebp-78h]
  float v33; // [esp-68h] [ebp-74h]
  float v34; // [esp-68h] [ebp-74h]
  float v35; // [esp-68h] [ebp-74h]
  float v36; // [esp-68h] [ebp-74h]
  float v37; // [esp-60h] [ebp-6Ch]
  float v38; // [esp-60h] [ebp-6Ch]
  float v39; // [esp-60h] [ebp-6Ch]
  float v40; // [esp-60h] [ebp-6Ch]
  float v41; // [esp-5Ch] [ebp-68h]
  float v42; // [esp-5Ch] [ebp-68h]
  float v43; // [esp-5Ch] [ebp-68h]
  float v44; // [esp-5Ch] [ebp-68h]
  float v45; // [esp-58h] [ebp-64h]
  float v46; // [esp-58h] [ebp-64h]
  float v47; // [esp-58h] [ebp-64h]
  float v48; // [esp-58h] [ebp-64h]
  float v49; // [esp-50h] [ebp-5Ch]
  float v50; // [esp-4Ch] [ebp-58h]
  float v51; // [esp-48h] [ebp-54h]
  float v52; // [esp-34h] [ebp-40h]
  float v53; // [esp-34h] [ebp-40h]
  float v54; // [esp-30h] [ebp-3Ch] BYREF
  float v55; // [esp-2Ch] [ebp-38h] BYREF
  float v56; // [esp-28h] [ebp-34h] BYREF
  float v57; // [esp-24h] [ebp-30h]
  float v58; // [esp-20h] [ebp-2Ch]
  float v59; // [esp-1Ch] [ebp-28h]
  float v60; // [esp-18h] [ebp-24h]
  float v61; // [esp-14h] [ebp-20h]
  float v62; // [esp-10h] [ebp-1Ch]
  float v63; // [esp-Ch] [ebp-18h]
  float v64; // [esp-8h] [ebp-14h]
  bool v65; // [esp-1h] [ebp-Dh]
  int v66; // [esp+0h] [ebp-Ch]
  void *v67; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v66 = a2;
  v67 = retaddr;
  v7 = a1[2583];
  if ( v7 )
  {
    v8 = *(_DWORD *)(v7 + 52);
    if ( v8 )
      *(_DWORD *)(v8 + 48) = *(_DWORD *)(v7 + 48);
    v9 = *(_DWORD *)(v7 + 48);
    if ( v9 )
      *(_DWORD *)(v9 + 52) = *(_DWORD *)(v7 + 52);
    if ( v7 == a1[2583] )
      a1[2583] = *(_DWORD *)(v7 + 52);
    --a1[2584];
    *(_DWORD *)(v7 + 48) = 0;
    *(_DWORD *)(v7 + 52) = a1[2581];
    v10 = a1[2581];
    if ( v10 )
      *(_DWORD *)(v10 + 48) = v7;
    ++a1[2582];
    a1[2581] = v7;
    *(_DWORD *)(v7 + 24) = a3;
    *(_BYTE *)(v7 + 59) = 0;
    *(_DWORD *)(v7 + 28) = a4;
    *(_DWORD *)(v7 + 32) = a5;
    v61 = a3[4];
    v37 = a5[4] - v61;
    v62 = a3[5];
    v41 = a5[5] - v62;
    v60 = a3[6];
    v45 = a5[6] - v60;
    v25 = a4[4] - v61;
    v29 = a4[5] - v62;
    v33 = a4[6] - v60;
    v49 = v29 * v45 - v33 * v41;
    *(float *)v7 = v49;
    v50 = v33 * v37 - v45 * v25;
    *(float *)(v7 + 4) = v50;
    v51 = v41 * v25 - v29 * v37;
    *(float *)(v7 + 8) = v51;
    *(_DWORD *)(v7 + 12) = 0;
    v63 = *(float *)(v7 + 4);
    v64 = *(float *)v7;
    v59 = *(float *)(v7 + 8);
    v54 = v64 * v64 + v63 * v63 + v59 * v59;
    v54 = sqrt(v54);
    v58 = v54;
    v11 = v54 > 0.00009999999747378752;
    v12 = a5[4];
    v65 = v11;
    v57 = v12;
    v61 = a3[4];
    v26 = v57 - v61;
    v56 = a5[5];
    v62 = a3[5];
    v30 = v56 - v62;
    v55 = a5[6];
    v60 = a3[6];
    v34 = v55 - v60;
    v38 = v63 * v34 - v59 * v30;
    v42 = v59 * v26 - v34 * v64;
    v46 = v30 * v64 - v26 * v63;
    v13 = v57;
    v54 = v55 * v46 + v56 * v42 + v57 * v38;
    v57 = a4[4];
    v27 = v57 - v13;
    v14 = a4[5];
    v31 = v14 - v56;
    v15 = a4[6];
    v35 = v15 - v55;
    v39 = v63 * v35 - v59 * v31;
    v43 = v59 * v27 - v35 * v64;
    v47 = v31 * v64 - v27 * v63;
    v56 = v14 * v43 + v57 * v39 + v15 * v47;
    v28 = v61 - v57;
    v32 = v62 - v14;
    v36 = v60 - v15;
    v40 = v63 * v36 - v59 * v32;
    v44 = v59 * v28 - v36 * v64;
    v48 = v32 * v64 - v28 * v63;
    v55 = v60 * v48 + v62 * v44 + v61 * v40;
    if ( v11 )
      v57 = v58;
    else
      v57 = 1.0;
    v16 = &v55;
    if ( v56 <= (double)v55 )
      v16 = &v56;
    if ( v54 <= (double)*v16 )
      v16 = &v54;
    v54 = *v16 / v57;
    v17 = v54;
    *(float *)(v7 + 20) = v54;
    if ( v17 < -0.0099999998 )
      v18 = v54;
    else
      v18 = 0.0;
    v19 = !v65;
    *(float *)(v7 + 20) = v18;
    if ( v19 )
    {
      *a1 = 2;
    }
    else
    {
      v52 = a3[5] * *(float *)(v7 + 4) + *(float *)v7 * a3[4] + a3[6] * *(float *)(v7 + 8);
      v20 = v58;
      *(float *)(v7 + 16) = v52 / v58;
      v53 = 1.0 / v20;
      *(float *)v7 = *(float *)v7 * v53;
      *(float *)(v7 + 4) = v53 * *(float *)(v7 + 4);
      *(float *)(v7 + 8) = v53 * *(float *)(v7 + 8);
      if ( a6 || *(float *)(v7 + 16) >= -0.0000099999997 )
        return v7;
      *a1 = 3;
    }
    v22 = *(_DWORD *)(v7 + 52);
    if ( v22 )
      *(_DWORD *)(v22 + 48) = *(_DWORD *)(v7 + 48);
    v23 = *(_DWORD *)(v7 + 48);
    if ( v23 )
      *(_DWORD *)(v23 + 52) = *(_DWORD *)(v7 + 52);
    if ( v7 == a1[2581] )
      a1[2581] = *(_DWORD *)(v7 + 52);
    --a1[2582];
    *(_DWORD *)(v7 + 48) = 0;
    *(_DWORD *)(v7 + 52) = a1[2583];
    v24 = a1[2583];
    if ( v24 )
      *(_DWORD *)(v24 + 48) = v7;
    ++a1[2584];
    a1[2583] = v7;
    return 0;
  }
  else
  {
    *a1 = 5;
    return 0;
  }
}
