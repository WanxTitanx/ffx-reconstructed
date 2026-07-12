// Function: sub_993300
// Address: 0x993300
int __userpurge sub_993300@<eax>(float *a1@<ecx>, int a2@<ebp>, float *a3, int a4, int a5, int a6)
{
  int v6; // edx
  int result; // eax
  double v8; // st7
  double v9; // st6
  int v10; // esi
  int v11; // edi
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  unsigned __int16 *v15; // ecx
  int v16; // eax
  int v17; // eax
  double v18; // st5
  double v19; // st4
  double v20; // st4
  double v21; // st4
  double v22; // st3
  double v23; // st2
  double v24; // st3
  double v25; // st4
  double v26; // st2
  int v27; // eax
  int v28; // eax
  double v29; // st2
  double v30; // st2
  double v31; // st2
  double v32; // st2
  int v33; // eax
  int v34; // eax
  double v35; // st2
  double v36; // st5
  double v37; // st5
  double v38; // st6
  double v39; // st5
  double v40; // st4
  double v41; // st7
  double v42; // st3
  double v43; // st2
  double v44; // st4
  double v45; // st4
  int v46; // eax
  int v47; // ecx
  unsigned __int16 v48; // ax
  unsigned __int16 *v49; // ecx
  unsigned __int16 v50; // ax
  unsigned __int16 v51; // dx
  unsigned __int16 v52; // ax
  unsigned __int16 v53; // dx
  unsigned __int16 v54; // ax
  unsigned __int16 v55; // dx
  unsigned __int16 v56; // ax
  unsigned __int16 v57; // dx
  unsigned __int16 v58; // ax
  unsigned __int16 v59; // cx
  float v60; // [esp-110h] [ebp-11Ch]
  float v61; // [esp-10Ch] [ebp-118h]
  float v62; // [esp-108h] [ebp-114h]
  float v63; // [esp-100h] [ebp-10Ch]
  float v64; // [esp-FCh] [ebp-108h]
  float v65; // [esp-F8h] [ebp-104h]
  float v66; // [esp-F0h] [ebp-FCh]
  float v67; // [esp-ECh] [ebp-F8h]
  float v68; // [esp-E8h] [ebp-F4h]
  float v69; // [esp-E0h] [ebp-ECh]
  float v70; // [esp-DCh] [ebp-E8h]
  float v71; // [esp-D8h] [ebp-E4h]
  int v72; // [esp-C4h] [ebp-D0h] BYREF
  int v73; // [esp-C0h] [ebp-CCh] BYREF
  int v74; // [esp-BCh] [ebp-C8h] BYREF
  int v75; // [esp-B8h] [ebp-C4h] BYREF
  float *v76; // [esp-B4h] [ebp-C0h]
  int v77; // [esp-B0h] [ebp-BCh]
  int n2_1; // [esp-ACh] [ebp-B8h] BYREF
  int n2; // [esp-A8h] [ebp-B4h] BYREF
  int v80; // [esp-A4h] [ebp-B0h]
  float v81; // [esp-A0h] [ebp-ACh]
  float v82; // [esp-9Ch] [ebp-A8h]
  float v83; // [esp-98h] [ebp-A4h]
  float v84; // [esp-90h] [ebp-9Ch]
  float v85; // [esp-8Ch] [ebp-98h]
  float v86; // [esp-88h] [ebp-94h]
  float v87; // [esp-80h] [ebp-8Ch]
  float v88; // [esp-7Ch] [ebp-88h]
  float v89; // [esp-78h] [ebp-84h]
  int v90; // [esp-74h] [ebp-80h]
  float v91; // [esp-70h] [ebp-7Ch]
  float v92; // [esp-6Ch] [ebp-78h]
  float v93; // [esp-68h] [ebp-74h]
  int v94; // [esp-64h] [ebp-70h]
  int v95; // [esp-54h] [ebp-60h] BYREF
  float *v96; // [esp-50h] [ebp-5Ch]
  int v97; // [esp-4Ch] [ebp-58h] BYREF
  int v98; // [esp-48h] [ebp-54h]
  float v99; // [esp-44h] [ebp-50h]
  float v100; // [esp-40h] [ebp-4Ch]
  float v101; // [esp-3Ch] [ebp-48h]
  float v102; // [esp-38h] [ebp-44h]
  int v103; // [esp-34h] [ebp-40h]
  float v104; // [esp-30h] [ebp-3Ch]
  float v105; // [esp-2Ch] [ebp-38h]
  float v106; // [esp-28h] [ebp-34h]
  int v107; // [esp-24h] [ebp-30h]
  float v108; // [esp-20h] [ebp-2Ch]
  float v109; // [esp-1Ch] [ebp-28h]
  float v110; // [esp-18h] [ebp-24h]
  int v111; // [esp-14h] [ebp-20h]
  int v112; // [esp+0h] [ebp-Ch]
  void *v113; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v112 = a2;
  v113 = retaddr;
  v6 = 0;
  v96 = a3;
  result = a5 - 1;
  v76 = a1;
  v80 = -1;
  v95 = 0;
  v72 = 0;
  n2 = 2;
  v97 = 0;
  v74 = 0;
  v75 = 0;
  v73 = 0;
  n2_1 = 2;
  v77 = a5 - 1;
  if ( a5 - 1 >= a4 )
  {
    v8 = 9.999999843067494e17;
    v9 = -9.999999843067494e17;
    v10 = 16 * result;
    while ( 1 )
    {
      v11 = *((_DWORD *)a1 + 37);
      v12 = *(_DWORD *)(v11 + v10 + 12);
      if ( v12 < 0 )
      {
        v46 = *(_DWORD *)(v11 + v10 + 28);
        if ( v46 < 0 )
          v47 = 16 * (v77 - v46 + 1);
        else
          v47 = v10 + 32;
        v48 = *(_WORD *)(v11 + v10 + 16);
        v49 = (unsigned __int16 *)(v11 + v47);
        *(_WORD *)(v11 + v10) = v48;
        if ( v48 > *v49 )
          *(_WORD *)(v11 + v10) = *v49;
        v50 = *(_WORD *)(v11 + v10 + 22);
        *(_WORD *)(v11 + v10 + 6) = v50;
        v51 = v49[3];
        if ( v50 < v51 )
          *(_WORD *)(v11 + v10 + 6) = v51;
        v52 = *(_WORD *)(v11 + v10 + 18);
        *(_WORD *)(v11 + v10 + 2) = v52;
        v53 = v49[1];
        if ( v52 > v53 )
          *(_WORD *)(v11 + v10 + 2) = v53;
        v54 = *(_WORD *)(v11 + v10 + 24);
        *(_WORD *)(v11 + v10 + 8) = v54;
        v55 = v49[4];
        if ( v54 < v55 )
          *(_WORD *)(v11 + v10 + 8) = v55;
        v56 = *(_WORD *)(v11 + v10 + 20);
        *(_WORD *)(v11 + v10 + 4) = v56;
        v57 = v49[2];
        if ( v56 > v57 )
          *(_WORD *)(v11 + v10 + 4) = v57;
        v58 = *(_WORD *)(v11 + v10 + 26);
        *(_WORD *)(v11 + v10 + 10) = v58;
        v59 = v49[5];
        if ( v58 < v59 )
          *(_WORD *)(v11 + v10 + 10) = v59;
        a1 = v76;
      }
      else
      {
        v13 = v12 >> 21;
        v14 = v12 & 0x1FFFFF;
        v99 = *(float *)&v13;
        v98 = v14;
        if ( v13 != v80 )
        {
          if ( v80 >= 0 )
            (*(void (__thiscall **)(float *, int))(*(_DWORD *)v96 + 20))(v96, v80);
          (*(void (__thiscall **)(float *, int *, int *, int *, int *, int *, int *, int *, int *, float))(*(_DWORD *)v96 + 12))(
            v96,
            &v95,
            &v72,
            &n2,
            &v97,
            &v74,
            &v75,
            &v73,
            &n2_1,
            COERCE_FLOAT(LODWORD(v99)));
          v8 = 9.999999843067494e17;
          v9 = -9.999999843067494e17;
          v6 = v95;
          v14 = v98;
          v80 = LODWORD(v99);
        }
        v15 = (unsigned __int16 *)(v74 + v75 * v14);
        if ( n2_1 == 3 )
          v16 = v15[2];
        else
          v16 = *((_DWORD *)v15 + 2);
        v17 = v6 + v97 * v16;
        v99 = v96[4];
        v18 = v99;
        v19 = v99;
        if ( n2 )
        {
          v25 = v19 * *(double *)v17;
          v94 = 0;
          v91 = v25;
          v99 = v96[5];
          v21 = v99;
          v92 = v99 * *(double *)(v17 + 8);
          v99 = v96[6];
          v24 = v99;
          v26 = v99 * *(double *)(v17 + 16);
          v108 = v91;
          v109 = v92;
          v93 = v26;
          v110 = v93;
        }
        else
        {
          v20 = v19 * *(float *)v17;
          v90 = 0;
          v87 = v20;
          v99 = v96[5];
          v21 = v99;
          v88 = *(float *)(v17 + 4) * v99;
          v99 = v96[6];
          v22 = *(float *)(v17 + 8);
          v108 = v87;
          v109 = v88;
          v23 = v22 * v99;
          v24 = v99;
          v89 = v23;
          v110 = v89;
        }
        v111 = 0;
        if ( n2_1 == 3 )
          v27 = v15[1];
        else
          v27 = *((_DWORD *)v15 + 1);
        v28 = v97 * v27;
        if ( n2 )
        {
          v31 = v18 * *(double *)(v28 + v95);
          v94 = 0;
          v91 = v31;
          v92 = v21 * *(double *)(v28 + v95 + 8);
          v32 = v24 * *(double *)(v28 + v95 + 16);
          v104 = v91;
          v105 = v92;
          v93 = v32;
          v106 = v93;
        }
        else
        {
          v29 = v18 * *(float *)(v28 + v95);
          v90 = 0;
          v87 = v29;
          v88 = *(float *)(v28 + v95 + 4) * v21;
          v30 = *(float *)(v28 + v95 + 8);
          v104 = v87;
          v105 = v88;
          v89 = v30 * v24;
          v106 = v89;
        }
        v107 = 0;
        if ( n2_1 == 3 )
          v33 = *v15;
        else
          v33 = *(_DWORD *)v15;
        v34 = v97 * v33;
        if ( n2 )
        {
          v94 = 0;
          v91 = v18 * *(double *)(v34 + v95);
          v92 = v21 * *(double *)(v34 + v95 + 8);
          v37 = v24 * *(double *)(v34 + v95 + 16);
          v100 = v91;
          v101 = v92;
          v93 = v37;
          v102 = v93;
        }
        else
        {
          v35 = *(float *)(v34 + v95);
          v90 = 0;
          v87 = v18 * v35;
          v88 = v21 * *(float *)(v34 + v95 + 4);
          v36 = v24 * *(float *)(v34 + v95 + 8);
          v100 = v87;
          v101 = v88;
          v89 = v36;
          v102 = v89;
        }
        v103 = 0;
        v81 = 9.9999998e17;
        v82 = 9.9999998e17;
        v83 = 9.9999998e17;
        v84 = -9.9999998e17;
        v85 = -9.9999998e17;
        v86 = -9.9999998e17;
        if ( v8 > v100 )
          v81 = v100;
        if ( v8 > v101 )
          v82 = v101;
        if ( v8 > v102 )
          v83 = v102;
        if ( v100 > v9 )
          v84 = v100;
        if ( v101 > v9 )
          v85 = v101;
        if ( v102 > v9 )
          v86 = v102;
        v38 = v81;
        if ( v81 > (double)v104 )
        {
          v81 = v104;
          v38 = v104;
        }
        v39 = v82;
        if ( v82 > (double)v105 )
        {
          v82 = v105;
          v39 = v105;
        }
        v40 = v83;
        if ( v83 > (double)v106 )
        {
          v83 = v106;
          v40 = v106;
        }
        v41 = v84;
        if ( v104 > (double)v84 )
        {
          v84 = v104;
          v41 = v104;
        }
        v42 = v85;
        if ( v105 > (double)v85 )
        {
          v85 = v105;
          v42 = v105;
        }
        v43 = v86;
        if ( v106 > (double)v86 )
        {
          v86 = v106;
          v43 = v106;
        }
        if ( v38 > v108 )
        {
          v81 = v108;
          v38 = v108;
        }
        if ( v39 > v109 )
        {
          v82 = v109;
          v39 = v109;
        }
        if ( v40 > v110 )
        {
          v83 = v110;
          v40 = v110;
        }
        if ( v108 > v41 )
        {
          v84 = v108;
          v41 = v108;
        }
        if ( v109 > v42 )
        {
          v85 = v109;
          v42 = v109;
        }
        if ( v110 > v43 )
        {
          v86 = v110;
          v43 = v110;
        }
        a1 = v76;
        v63 = v38 - v76[4];
        v64 = v39 - v76[5];
        v65 = v40 - v76[6];
        v60 = v63 * v76[12];
        v61 = v76[13] * v64;
        v44 = v76[14] * v65;
        *(_WORD *)(v11 + v10) = (int)v60 & 0xFFFE;
        v62 = v44;
        *(_WORD *)(v11 + v10 + 2) = (int)v61 & 0xFFFE;
        *(_WORD *)(v11 + v10 + 4) = (int)v62 & 0xFFFE;
        v45 = a1[4];
        v98 = HIWORD(v99) | 0xC00;
        v69 = v41 - v45;
        v70 = v42 - a1[5];
        v71 = v43 - a1[6];
        v66 = v69 * a1[12];
        v67 = a1[13] * v70;
        v68 = a1[14] * v71;
        v98 = (int)(v66 + 1.0);
        *(_WORD *)(v11 + v10 + 6) = v98 | 1;
        v98 = (int)(v67 + 1.0);
        *(_WORD *)(v11 + v10 + 8) = v98 | 1;
        v98 = (int)(v68 + 1.0);
        *(_WORD *)(v11 + v10 + 10) = v98 | 1;
        v8 = 9.999999843067494e17;
        v9 = -9.999999843067494e17;
      }
      result = v77 - 1;
      v10 -= 16;
      v77 = result;
      if ( result < a4 )
        break;
      v6 = v95;
    }
    if ( v80 >= 0 )
      return (*(int (__thiscall **)(float *, int))(*(_DWORD *)v96 + 20))(v96, v80);
  }
  return result;
}
