// Function: sub_99C910
// Address: 0x99c910
// bad sp value at call has been detected, the output may be wrong!
int __userpurge sub_99C910@<eax>(
        int a1@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int a5,
        int a6,
        int a7,
        int a8,
        float a9)
{
  int v9; // edi
  int v10; // esi
  float *v11; // eax
  double v12; // st4
  double v13; // st7
  float *v14; // eax
  double v15; // st6
  double v16; // st7
  double v17; // st5
  double v18; // st4
  double v19; // st6
  double v20; // st4
  double v21; // st7
  double v22; // st4
  double v23; // st3
  float *v24; // esi
  int v25; // eax
  double v26; // st6
  double v27; // st7
  double v28; // st6
  double v29; // st6
  double v30; // st7
  double v31; // st4
  int v32; // ecx
  double v33; // st6
  float v34; // ecx
  float v35; // edx
  int result; // eax
  double v37; // st7
  double v38; // st7
  double v39; // st5
  int v40; // eax
  double v41; // st4
  float v44; // [esp+1Ch] [ebp-16Ch] BYREF
  float v45; // [esp+20h] [ebp-168h]
  float v46; // [esp+24h] [ebp-164h]
  float v47; // [esp+38h] [ebp-150h]
  float v48; // [esp+3Ch] [ebp-14Ch]
  float v49; // [esp+40h] [ebp-148h]
  float v50; // [esp+44h] [ebp-144h]
  float v51; // [esp+48h] [ebp-140h]
  float v52; // [esp+4Ch] [ebp-13Ch]
  float v53; // [esp+50h] [ebp-138h]
  int *v54; // [esp+54h] [ebp-134h]
  float v55; // [esp+58h] [ebp-130h]
  float v56; // [esp+5Ch] [ebp-12Ch]
  float *v57; // [esp+60h] [ebp-128h]
  float v58; // [esp+64h] [ebp-124h]
  int v59; // [esp+68h] [ebp-120h]
  float v60; // [esp+6Ch] [ebp-11Ch]
  float v61; // [esp+70h] [ebp-118h]
  float v62; // [esp+74h] [ebp-114h]
  float v63; // [esp+78h] [ebp-110h]
  float v64; // [esp+7Ch] [ebp-10Ch] BYREF
  float v65; // [esp+80h] [ebp-108h]
  float v66; // [esp+84h] [ebp-104h]
  int v67; // [esp+88h] [ebp-100h]
  float v68[2]; // [esp+8Ch] [ebp-FCh] BYREF
  double v69; // [esp+94h] [ebp-F4h]
  float v70; // [esp+A4h] [ebp-E4h]
  float v71; // [esp+A8h] [ebp-E0h]
  float v72; // [esp+ACh] [ebp-DCh] BYREF
  float v73; // [esp+B0h] [ebp-D8h]
  float v74; // [esp+B4h] [ebp-D4h]
  int v75; // [esp+B8h] [ebp-D0h]
  float v76; // [esp+C8h] [ebp-C0h]
  float v77; // [esp+CCh] [ebp-BCh]
  float v78; // [esp+D0h] [ebp-B8h]
  float v79; // [esp+D4h] [ebp-B4h]
  float v80; // [esp+D8h] [ebp-B0h]
  float v81; // [esp+DCh] [ebp-ACh]
  float v82; // [esp+E0h] [ebp-A8h]
  float v83; // [esp+E4h] [ebp-A4h]
  float v84; // [esp+E8h] [ebp-A0h]
  _BYTE v85[16]; // [esp+ECh] [ebp-9Ch] BYREF
  float v86; // [esp+FCh] [ebp-8Ch]
  float v87; // [esp+100h] [ebp-88h]
  float v88; // [esp+104h] [ebp-84h]
  float v89; // [esp+10Ch] [ebp-7Ch]
  float v90; // [esp+110h] [ebp-78h]
  float v91; // [esp+114h] [ebp-74h]
  float v92; // [esp+11Ch] [ebp-6Ch]
  float v93; // [esp+120h] [ebp-68h]
  float v94; // [esp+124h] [ebp-64h]
  float v95; // [esp+12Ch] [ebp-5Ch] BYREF
  float v96; // [esp+130h] [ebp-58h]
  float v97; // [esp+134h] [ebp-54h]
  int v98; // [esp+138h] [ebp-50h]
  float v99; // [esp+13Ch] [ebp-4Ch]
  float v100; // [esp+140h] [ebp-48h]
  float v101; // [esp+144h] [ebp-44h]
  int v102; // [esp+148h] [ebp-40h]
  float v103; // [esp+14Ch] [ebp-3Ch]
  float v104; // [esp+150h] [ebp-38h]
  float v105; // [esp+154h] [ebp-34h]
  int v106; // [esp+158h] [ebp-30h]
  float v107; // [esp+15Ch] [ebp-2Ch]
  float v108; // [esp+160h] [ebp-28h]
  float v109; // [esp+164h] [ebp-24h]
  int v110; // [esp+168h] [ebp-20h]
  float v111; // [esp+174h] [ebp-14h]
  int v112; // [esp+17Ch] [ebp-Ch]
  void *v113; // [esp+180h] [ebp-8h]
  void *retaddr; // [esp+188h] [ebp+0h]

  v112 = a2;
  v113 = retaddr;
  v59 = a1;
  v63 = a9;
  v9 = a7;
  v10 = a6;
  if ( *(_BYTE *)(a1 + 16) )
  {
    v10 = a7;
    v9 = a6;
  }
  v54 = *(int **)(v10 + 204);
  v57 = *(float **)(v9 + 204);
  v95 = *(float *)(v10 + 16);
  v96 = *(float *)(v10 + 20);
  v97 = *(float *)(v10 + 24);
  v98 = *(_DWORD *)(v10 + 28);
  v99 = *(float *)(v10 + 32);
  v100 = *(float *)(v10 + 36);
  v101 = *(float *)(v10 + 40);
  v102 = *(_DWORD *)(v10 + 44);
  v103 = *(float *)(v10 + 48);
  v104 = *(float *)(v10 + 52);
  v105 = *(float *)(v10 + 56);
  v106 = *(_DWORD *)(v10 + 60);
  v107 = *(float *)(v10 + 64);
  v108 = *(float *)(v10 + 68);
  v109 = *(float *)(v10 + 72);
  v110 = *(_DWORD *)(v10 + 76);
  v11 = (float *)sub_982990((float *)(v9 + 16), (int)v85);
  v79 = v11[1];
  v80 = *v11;
  v78 = v11[2];
  v84 = v78 * v109 + v79 * v108 + v80 * v107;
  v64 = v84 + v11[12];
  v81 = v11[5];
  v84 = v11[4];
  v12 = v11[6];
  v82 = v84 * v107 + v81 * v108 + v12 * v109;
  v65 = v82 + v11[13];
  v76 = v11[9];
  v82 = v11[8];
  v13 = v11[10];
  v83 = v109 * v13 + v108 * v76 + v107 * v82;
  v66 = v83 + v11[14];
  *((float *)&v69 + 1) = v82 * v97 + v76 * v101 + v13 * v105;
  v62 = v13 * v104 + v82 * v96 + v76 * v100;
  v70 = v13 * v103 + v76 * v99 + v82 * v95;
  v60 = v84 * v97 + v81 * v101 + v12 * v105;
  v55 = v84 * v96 + v81 * v100 + v12 * v104;
  v51 = v12 * v103 + v81 * v99 + v84 * v95;
  v61 = v80 * v97 + v79 * v101 + v78 * v105;
  v47 = v104 * v78 + v80 * v96 + v79 * v100;
  v52 = v99 * v79 + v80 * v95 + v103 * v78;
  sub_603C50(a5);
  v80 = v94 * v105 + v91 * v104 + v88 * v103;
  v76 = v105 * v93 + v104 * v90 + v87 * v103;
  v82 = v103 * v86 + v89 * v104 + v92 * v105;
  v78 = v88 * v99 + v91 * v100 + v94 * v101;
  v79 = v87 * v99 + v90 * v100 + v93 * v101;
  v81 = v86 * v99 + v89 * v100 + v92 * v101;
  v84 = v88 * v95 + v91 * v96 + v94 * v97;
  v83 = v93 * v97 + v90 * v96 + v87 * v95;
  v95 = v96 * v89 + v86 * v95 + v92 * v97;
  v97 = v84;
  v96 = v83;
  v99 = v81;
  v100 = v79;
  v101 = v78;
  v103 = v82;
  v104 = v76;
  v98 = 0;
  v102 = 0;
  v105 = v80;
  v106 = 0;
  v14 = (float *)sub_982990(&v95, (int)v85);
  v84 = v14[9];
  v76 = *(float *)(v9 + 40);
  v80 = *(float *)(v9 + 24);
  v83 = v14[8];
  v81 = v14[10];
  v82 = *(float *)(v9 + 56);
  v15 = v83;
  v16 = v84;
  v17 = v81;
  v56 = v82 * v81 + v76 * v84 + v80 * v83;
  v79 = *(float *)(v9 + 36);
  v78 = *(float *)(v9 + 20);
  v81 = *(float *)(v9 + 52);
  v49 = v78 * v83 + v79 * v84 + v81 * v17;
  v83 = *(float *)(v9 + 32);
  v84 = *(float *)(v9 + 16);
  v77 = *(float *)(v9 + 48);
  v18 = v15 * v84;
  v19 = v83;
  v20 = v16 * v83 + v18;
  v21 = v77;
  v58 = v17 * v77 + v20;
  v83 = v14[5];
  v77 = v14[4];
  v71 = v14[6];
  v53 = v82 * v71 + v76 * v83 + v80 * v77;
  v48 = v78 * v77 + v79 * v83 + v81 * v71;
  v50 = v83 * v19 + v77 * v84 + v71 * v21;
  v77 = v14[1];
  v71 = *v14;
  v83 = v14[2];
  v22 = v71;
  v23 = v83;
  v83 = v82 * v83 + v76 * v77 + v80 * v71;
  v71 = v78 * v71 + v79 * v77 + v81 * v23;
  v24 = v57;
  v25 = *v54;
  v75 = 0;
  v77 = v77 * v19 + v22 * v84 + v23 * v21;
  v72 = -v57[12];
  v73 = -v57[13];
  v74 = -v57[14];
  v26 = v73;
  v27 = v72;
  v72 = v83 * v74 + v77 * v72 + v71 * v73;
  v73 = v48 * v73 + v50 * v27 + v53 * v74;
  v74 = v27 * v58 + v26 * v49 + v74 * v56;
  (*(void (__cdecl **)(float *, float *, int, int))(v25 + 56))(&v44, &v72, a3, a4);
  v61 = v44 * v52 + v45 * v47 + v46 * v61;
  v72 = v61 + v64;
  v60 = v44 * v51 + v45 * v55 + v46 * v60;
  v73 = v60 + v65;
  *((float *)&v69 + 1) = v44 * v70 + v45 * v62 + v46 * *((float *)&v69 + 1);
  v74 = *((float *)&v69 + 1) + v66;
  v70 = v24[13];
  *((float *)&v69 + 1) = v24[12];
  v62 = v24[14];
  v28 = *((float *)&v69 + 1);
  *((float *)&v69 + 1) = v74 * v62 + v73 * v70 + v72 * *((float *)&v69 + 1);
  v84 = *((float *)&v69 + 1) - v24[16];
  v64 = v28 * v84;
  v65 = v70 * v84;
  v66 = v84 * v62;
  v72 = v72 - v64;
  v73 = v73 - v65;
  v74 = v74 - v66;
  v29 = v73;
  v30 = v72;
  *((float *)&v69 + 1) = *(float *)(v9 + 24) * v74 + *(float *)(v9 + 16) * v72 + *(float *)(v9 + 20) * v73;
  v31 = *((float *)&v69 + 1) + *(float *)(v9 + 64);
  v75 = 0;
  v32 = *(_DWORD *)(v59 + 12);
  v72 = v31;
  *((float *)&v69 + 1) = v73 * *(float *)(v9 + 36) + *(float *)(v9 + 32) * v30 + *(float *)(v9 + 40) * v74;
  v73 = *((float *)&v69 + 1) + *(float *)(v9 + 68);
  *((float *)&v69 + 1) = v30 * *(float *)(v9 + 48) + v29 * *(float *)(v9 + 52) + v74 * *(float *)(v9 + 56);
  v74 = *((float *)&v69 + 1) + *(float *)(v9 + 72);
  v69 = v84;
  v33 = sub_9A43D0(v32);
  LOBYTE(v34) = v33 > v69;
  v35 = v63;
  result = *(_DWORD *)(v59 + 12);
  *(_DWORD *)(LODWORD(v63) + 4) = result;
  if ( LOBYTE(v34) )
  {
    *((float *)&v69 + 1) = v24[13];
    v64 = v72;
    v63 = v24[12];
    v111 = v34;
    v37 = v24[14];
    v65 = v73;
    v70 = v37;
    v38 = *(float *)(v9 + 16);
    v66 = v74;
    v67 = v75;
    v39 = *(float *)(v9 + 20);
    v40 = *(_DWORD *)LODWORD(v35);
    v41 = *((float *)&v69 + 1);
    HIDWORD(v69) = 0;
    v68[0] = *(float *)(v9 + 24) * v70 + v39 * v41 + v38 * v63;
    v68[1] = *(float *)(v9 + 36) * v41 + *(float *)(v9 + 32) * v63 + *(float *)(v9 + 40) * v70;
    *(float *)&v69 = v41 * *(float *)(v9 + 52) + v63 * *(float *)(v9 + 48) + v70 * *(float *)(v9 + 56);
    return (*(int (__thiscall **)(float, float *, float *, float))(v40 + 12))(
             COERCE_FLOAT(LODWORD(v35)),
             v68,
             &v64,
             COERCE_FLOAT(LODWORD(v84)));
  }
  return result;
}
