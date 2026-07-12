// Function: sub_9CA0F0
// Address: 0x9ca0f0
int __userpurge sub_9CA0F0@<eax>(int a1@<ecx>, int a2@<ebp>, int a3, float *a4, float *a5, float *a6, float *a7)
{
  int v9; // ecx
  int v10; // eax
  double v11; // st7
  double v12; // st6
  double v13; // st5
  double v14; // rt2
  double v15; // st6
  double v16; // st5
  int v18; // ecx
  double v19; // st6
  double v20; // st5
  double v21; // st7
  double v22; // st6
  double v23; // st5
  int v24; // eax
  float v25; // xmm0_4
  double v26; // st5
  int result; // eax
  int v28; // edx
  int v29; // ecx
  int v30; // eax
  double v31; // st6
  double v32; // st7
  double v33; // st6
  double v34; // st4
  double v35; // st7
  double v36; // st5
  double v37; // st6
  double v38; // st5
  double v39; // st3
  double v40; // st4
  double v41; // st5
  double v42; // st3
  int v43; // ecx
  int v44; // ecx
  double v45; // st7
  double v46; // st7
  int v47; // eax
  int v48; // ecx
  double v49; // st7
  int v50; // eax
  float v51; // [esp-68h] [ebp-74h]
  float v52; // [esp-60h] [ebp-6Ch]
  float v53; // [esp-60h] [ebp-6Ch]
  float v54; // [esp-60h] [ebp-6Ch]
  float v55; // [esp-5Ch] [ebp-68h]
  float v56; // [esp-5Ch] [ebp-68h]
  float v57; // [esp-5Ch] [ebp-68h]
  float v58; // [esp-58h] [ebp-64h]
  float v59; // [esp-58h] [ebp-64h]
  float v60; // [esp-58h] [ebp-64h]
  float v61; // [esp-44h] [ebp-50h]
  float v62; // [esp-40h] [ebp-4Ch]
  float v63; // [esp-40h] [ebp-4Ch]
  float v64; // [esp-40h] [ebp-4Ch]
  float v65; // [esp-3Ch] [ebp-48h]
  float v66; // [esp-3Ch] [ebp-48h]
  float v67; // [esp-3Ch] [ebp-48h]
  float v68; // [esp-38h] [ebp-44h]
  float v69; // [esp-38h] [ebp-44h]
  float v70; // [esp-38h] [ebp-44h]
  float v71; // [esp-24h] [ebp-30h]
  float v72; // [esp-24h] [ebp-30h]
  float v73; // [esp-24h] [ebp-30h]
  float v74; // [esp-20h] [ebp-2Ch]
  float v75; // [esp-20h] [ebp-2Ch]
  float v76; // [esp-1Ch] [ebp-28h]
  float v77; // [esp-18h] [ebp-24h]
  float v78; // [esp-18h] [ebp-24h]
  float v79; // [esp-14h] [ebp-20h]
  float v80; // [esp-10h] [ebp-1Ch]
  float v81; // [esp-Ch] [ebp-18h]
  float v82; // [esp-Ch] [ebp-18h]
  float v83; // [esp-8h] [ebp-14h]
  float v84; // [esp-8h] [ebp-14h]
  float v85; // [esp-8h] [ebp-14h]
  float v86; // [esp-8h] [ebp-14h]
  int v87; // [esp-4h] [ebp-10h]
  float v88; // [esp-4h] [ebp-10h]
  float v89; // [esp-4h] [ebp-10h]
  float v90; // [esp-4h] [ebp-10h]
  float v91; // [esp-4h] [ebp-10h]
  float v92; // [esp-4h] [ebp-10h]
  float v93; // [esp-4h] [ebp-10h]
  float v94; // [esp-4h] [ebp-10h]
  float v95; // [esp-4h] [ebp-10h]
  _DWORD v96[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v96[0] = a2;
  v96[1] = retaddr;
  sub_9C65C0(a1, (int)v96, a4, a5, a6, a7);
  **(_DWORD **)(a3 + 8) = 1065353216;
  *(_DWORD *)(*(_DWORD *)(a3 + 8) + 4 * *(_DWORD *)(a3 + 24) + 4) = 1065353216;
  *(_DWORD *)(*(_DWORD *)(a3 + 8) + 8 * *(_DWORD *)(a3 + 24) + 8) = 1065353216;
  v9 = *(_DWORD *)(a3 + 12);
  v10 = *(_DWORD *)(a3 + 24);
  v11 = *(float *)(a1 + 384);
  v12 = *(float *)(a1 + 388);
  v13 = *(float *)(a1 + 392);
  v62 = a4[1] * v12 + v11 * *a4 + v13 * a4[2];
  v65 = v11 * a4[4] + v12 * a4[5] + v13 * a4[6];
  v14 = v13;
  v15 = v12 * a4[9] + v11 * a4[8];
  v16 = a4[10];
  *(_DWORD *)v9 = 0;
  *(float *)(v9 + 8) = -v65;
  *(_DWORD *)(v9 + 12) = 0;
  v68 = v14 * v16 + v15;
  *(float *)(v9 + 4) = -(float)-v68;
  *(float *)(v9 + 4 * v10) = -v68;
  *(_DWORD *)(v9 + 4 * v10 + 4) = 0;
  *(_DWORD *)(v9 + 4 * v10 + 12) = 0;
  *(float *)(v9 + 4 * v10 + 8) = -(float)-v62;
  *(float *)(v9 + 8 * v10 + 4) = -v62;
  *(_DWORD *)(v9 + 8 * v10 + 8) = 0;
  *(_DWORD *)(v9 + 8 * v10 + 12) = 0;
  *(float *)(v9 + 8 * v10) = -(float)-v65;
  v18 = *(_DWORD *)(a3 + 20);
  v19 = *(float *)(a1 + 452);
  v20 = *(float *)(a1 + 448);
  v21 = *(float *)(a1 + 456);
  v52 = a5[2] * v21 + a5[1] * v19 + v20 * *a5;
  v55 = a5[5] * v19 + v20 * a5[4] + a5[6] * v21;
  v22 = v19 * a5[9] + v20 * a5[8];
  v23 = a5[10];
  v24 = *(_DWORD *)(a3 + 24);
  *(_DWORD *)v18 = 0;
  *(_DWORD *)(v18 + 12) = 0;
  v58 = v21 * v23 + v22;
  *(float *)(v18 + 4) = -v58;
  *(float *)(v18 + 8) = v55;
  *(float *)(v18 + 4 * v24 + 8) = -v52;
  *(float *)(v18 + 4 * v24) = v58;
  *(_DWORD *)(v18 + 4 * v24 + 4) = 0;
  *(_DWORD *)(v18 + 4 * v24 + 12) = 0;
  *(float *)(v18 + 8 * v24) = -v55;
  *(_QWORD *)(v18 + 8 * v24 + 4) = LODWORD(v52);
  *(_DWORD *)(v18 + 8 * v24 + 12) = 0;
  if ( (*(_BYTE *)(a1 + 656) & 2) != 0 )
    v25 = *(float *)(a1 + 664);
  else
    v25 = *(float *)(a3 + 4);
  v83 = *(float *)a3 * v25;
  v26 = v83;
  v84 = (a5[12] + v52 - v62 - a4[12]) * v83;
  **(float **)(a3 + 28) = v84;
  **(_DWORD **)(a3 + 36) = -8388609;
  **(_DWORD **)(a3 + 40) = 2139095039;
  if ( (*(_BYTE *)(a1 + 656) & 1) != 0 )
    **(float **)(a3 + 32) = *(float *)(a1 + 660);
  v85 = (v55 + a5[13] - v65 - a4[13]) * v26;
  *(float *)(*(_DWORD *)(a3 + 28) + 4 * *(_DWORD *)(a3 + 24)) = v85;
  *(_DWORD *)(*(_DWORD *)(a3 + 36) + 4 * *(_DWORD *)(a3 + 24)) = -8388609;
  *(_DWORD *)(*(_DWORD *)(a3 + 40) + 4 * *(_DWORD *)(a3 + 24)) = 2139095039;
  if ( (*(_BYTE *)(a1 + 656) & 1) != 0 )
    *(float *)(*(_DWORD *)(a3 + 32) + 4 * *(_DWORD *)(a3 + 24)) = *(float *)(a1 + 660);
  v86 = v26 * (v58 + a5[14] - v68 - a4[14]);
  *(float *)(*(_DWORD *)(a3 + 28) + 8 * *(_DWORD *)(a3 + 24)) = v86;
  *(_DWORD *)(*(_DWORD *)(a3 + 36) + 8 * *(_DWORD *)(a3 + 24)) = -8388609;
  *(_DWORD *)(*(_DWORD *)(a3 + 40) + 8 * *(_DWORD *)(a3 + 24)) = 2139095039;
  if ( (*(_BYTE *)(a1 + 656) & 1) != 0 )
    *(float *)(*(_DWORD *)(a3 + 32) + 8 * *(_DWORD *)(a3 + 24)) = *(float *)(a1 + 660);
  result = *(_DWORD *)(a3 + 24);
  v28 = 3 * result;
  if ( *(_BYTE *)(a1 + 562) )
  {
    v29 = *(_DWORD *)(a3 + 12);
    v30 = *(_DWORD *)(a3 + 20);
    v87 = v29;
    v31 = *(float *)(a1 + 492);
    if ( v31 <= *(float *)(a1 + 480) || v31 <= *(float *)(a1 + 484) )
    {
      v46 = *(float *)(a1 + 472);
      v53 = v46 * *(float *)(a1 + 496);
      v56 = *(float *)(a1 + 500) * v46;
      v59 = *(float *)(a1 + 504) * v46;
      v63 = v46 * v53;
      v66 = v46 * v56;
      v69 = v46 * v59;
      *(float *)(v29 + 4 * v28) = v63;
      *(float *)(v29 + 4 * v28 + 4) = v66;
      *(float *)(v29 + 4 * v28 + 8) = v69;
      *(float *)(v30 + 4 * v28) = -v63;
      *(float *)(v30 + 4 * v28 + 4) = -v66;
      *(float *)(v30 + 4 * v28 + 8) = -v69;
      v92 = *(float *)(a1 + 468) * *(float *)a3;
      v93 = v92 * *(float *)(a1 + 540);
      *(float *)(*(_DWORD *)(a3 + 28) + 4 * v28) = v93;
      if ( (*(_BYTE *)(a1 + 656) & 4) != 0 )
        *(float *)(*(_DWORD *)(a3 + 32) + 4 * v28) = *(float *)(a1 + 668);
      *(_DWORD *)(*(_DWORD *)(a3 + 36) + 4 * v28) = 0;
      result = *(_DWORD *)(a3 + 40);
      *(_DWORD *)(result + 4 * v28) = 2139095039;
      v28 += *(_DWORD *)(a3 + 24);
    }
    else
    {
      v81 = a4[9];
      v76 = *(float *)(a1 + 360);
      v51 = *(float *)(a1 + 344);
      v77 = *(float *)(a1 + 376);
      v32 = a4[8];
      v33 = a4[10];
      v80 = v32 * v51 + v81 * v76 + v33 * v77;
      v79 = *(float *)(a1 + 340);
      v74 = *(float *)(a1 + 372);
      v34 = v32 * v79;
      v35 = *(float *)(a1 + 356);
      v36 = v33 * v74 + v81 * v35 + v34;
      v37 = v74;
      v75 = v36;
      v38 = a4[4];
      v39 = a4[5];
      v40 = a4[6];
      v82 = v38 * v51 + v39 * v76 + v40 * v77;
      v61 = v38 * v79 + v39 * v35 + v40 * v37;
      v71 = a4[2];
      v41 = a4[1];
      v42 = *a4;
      v43 = *(_DWORD *)(a3 + 24);
      *(float *)(v87 + 4 * v28 + 4) = v61;
      *(float *)(v87 + 4 * v28 + 8) = v75;
      v44 = v28 + v43;
      v78 = v41 * v76 + v42 * v51 + v71 * v77;
      v72 = v35 * v41 + v42 * v79 + v37 * v71;
      v45 = v72;
      *(float *)(v87 + 4 * v28) = v72;
      *(float *)(v87 + 4 * v44) = v78;
      *(float *)(v87 + 4 * v44 + 4) = v82;
      *(float *)(v87 + 4 * v44 + 8) = v80;
      *(float *)(v30 + 4 * v28) = -v72;
      *(float *)(v30 + 4 * v28 + 4) = -v61;
      *(float *)(v30 + 4 * v28 + 8) = -v75;
      *(float *)(v30 + 4 * v44) = -v78;
      *(float *)(v30 + 4 * v44 + 4) = -v82;
      *(float *)(v30 + 4 * v44 + 8) = -v80;
      v73 = *(float *)(a1 + 472) * *(float *)a3;
      v88 = v45 * *(float *)(a1 + 496) + *(float *)(a1 + 500) * v61 + *(float *)(a1 + 504) * v75;
      v89 = v88 * v73;
      *(float *)(*(_DWORD *)(a3 + 28) + 4 * v28) = v89;
      v90 = *(float *)(a1 + 500) * v82 + v78 * *(float *)(a1 + 496) + *(float *)(a1 + 504) * v80;
      v91 = v73 * v90;
      *(float *)(*(_DWORD *)(a3 + 28) + 4 * v44) = v91;
      *(_DWORD *)(*(_DWORD *)(a3 + 36) + 4 * v28) = -8388609;
      *(_DWORD *)(*(_DWORD *)(a3 + 40) + 4 * v28) = 2139095039;
      *(_DWORD *)(*(_DWORD *)(a3 + 36) + 4 * v44) = -8388609;
      result = *(_DWORD *)(a3 + 40);
      *(_DWORD *)(result + 4 * v44) = 2139095039;
      v28 = v44 + *(_DWORD *)(a3 + 24);
    }
  }
  if ( *(_BYTE *)(a1 + 561) )
  {
    v47 = *(_DWORD *)(a3 + 12);
    v48 = *(_DWORD *)(a3 + 20);
    v49 = *(float *)(a1 + 472);
    v54 = v49 * *(float *)(a1 + 512);
    v57 = *(float *)(a1 + 516) * v49;
    v60 = *(float *)(a1 + 520) * v49;
    v64 = v49 * v54;
    v67 = v49 * v57;
    v70 = v49 * v60;
    *(float *)(v47 + 4 * v28) = v64;
    *(float *)(v47 + 4 * v28 + 4) = v67;
    *(float *)(v47 + 4 * v28 + 8) = v70;
    *(float *)(v48 + 4 * v28) = -v64;
    *(float *)(v48 + 4 * v28 + 4) = -v67;
    *(float *)(v48 + 4 * v28 + 8) = -v70;
    v94 = *(float *)(a1 + 468) * *(float *)a3;
    v95 = v94 * *(float *)(a1 + 544);
    *(float *)(*(_DWORD *)(a3 + 28) + 4 * v28) = v95;
    if ( (*(_BYTE *)(a1 + 656) & 4) != 0 )
      *(float *)(*(_DWORD *)(a3 + 32) + 4 * v28) = *(float *)(a1 + 668);
    v50 = *(_DWORD *)(a3 + 36);
    if ( *(float *)(a1 + 488) <= 0.0 )
    {
      *(_DWORD *)(v50 + 4 * v28) = -8388609;
    }
    else
    {
      if ( *(float *)(a1 + 544) <= 0.0 )
      {
        *(_DWORD *)(v50 + 4 * v28) = -8388609;
        result = *(_DWORD *)(a3 + 40);
        *(_DWORD *)(result + 4 * v28) = 0;
        return result;
      }
      *(_DWORD *)(v50 + 4 * v28) = 0;
    }
    result = *(_DWORD *)(a3 + 40);
    *(_DWORD *)(result + 4 * v28) = 2139095039;
  }
  return result;
}
