// Function: sub_98B190
// Address: 0x98b190
int __userpurge sub_98B190@<eax>(float *a1@<ecx>, int a2@<edi>, int a3@<esi>, float *a4, int a5, int a6)
{
  long double v7; // st7
  long double v8; // st6
  long double v9; // st5
  long double v10; // st4
  long double v11; // st3
  long double v12; // st1
  double v13; // st3
  long double v14; // st2
  double v15; // st5
  int v18; // [esp-78h] [ebp-84h]
  int v19; // [esp-74h] [ebp-80h]
  float v20; // [esp-74h] [ebp-80h]
  int v21; // [esp-70h] [ebp-7Ch]
  float v22; // [esp-70h] [ebp-7Ch]
  int v23; // [esp-6Ch] [ebp-78h]
  float v24; // [esp-6Ch] [ebp-78h]
  int v25; // [esp-68h] [ebp-74h]
  float v26; // [esp-68h] [ebp-74h]
  int v27; // [esp-64h] [ebp-70h]
  float v28; // [esp-64h] [ebp-70h]
  int v29; // [esp-60h] [ebp-6Ch]
  float v30; // [esp-60h] [ebp-6Ch]
  int v31; // [esp-5Ch] [ebp-68h]
  int v32; // [esp-58h] [ebp-64h]
  float v33; // [esp-58h] [ebp-64h]
  int v34; // [esp-54h] [ebp-60h]
  float v35; // [esp-54h] [ebp-60h]
  int v36; // [esp-50h] [ebp-5Ch]
  float v37; // [esp-50h] [ebp-5Ch]
  float v38; // [esp-50h] [ebp-5Ch]
  float v39; // [esp-50h] [ebp-5Ch]
  int v40; // [esp-4Ch] [ebp-58h]
  float v41; // [esp-4Ch] [ebp-58h]
  float v42; // [esp-4Ch] [ebp-58h]
  int v43; // [esp-48h] [ebp-54h]
  float v44; // [esp-48h] [ebp-54h]
  float v45; // [esp-48h] [ebp-54h]
  int v46; // [esp-44h] [ebp-50h]
  int v47; // [esp-40h] [ebp-4Ch]
  int v48; // [esp-3Ch] [ebp-48h]
  int v49; // [esp-38h] [ebp-44h]
  int v50; // [esp-34h] [ebp-40h]
  float v51; // [esp-34h] [ebp-40h]
  float v52; // [esp-34h] [ebp-40h]
  float v53; // [esp-30h] [ebp-3Ch]
  float v54; // [esp-30h] [ebp-3Ch]
  float v55; // [esp-30h] [ebp-3Ch]
  float v56; // [esp-2Ch] [ebp-38h]
  float v57; // [esp-2Ch] [ebp-38h]
  float v58; // [esp-2Ch] [ebp-38h]
  float v59; // [esp-28h] [ebp-34h]
  float v60; // [esp-28h] [ebp-34h]
  float v61; // [esp-28h] [ebp-34h]
  int v62; // [esp-24h] [ebp-30h]
  float v63; // [esp-20h] [ebp-2Ch]
  float v64; // [esp-20h] [ebp-2Ch]
  float v65; // [esp-20h] [ebp-2Ch]
  float v66; // [esp-20h] [ebp-2Ch]
  float v67; // [esp-20h] [ebp-2Ch]
  float v68; // [esp-1Ch] [ebp-28h]
  float v69; // [esp-1Ch] [ebp-28h]
  float v70; // [esp-1Ch] [ebp-28h]
  float v71; // [esp-1Ch] [ebp-28h]
  float v72; // [esp-1Ch] [ebp-28h]
  float v73; // [esp-18h] [ebp-24h]
  float v74; // [esp-18h] [ebp-24h]
  float v75; // [esp-18h] [ebp-24h]
  float v76; // [esp-18h] [ebp-24h]
  float v77; // [esp-18h] [ebp-24h]
  int v78; // [esp-14h] [ebp-20h]
  int v79; // [esp-10h] [ebp-1Ch]
  float v80; // [esp-4h] [ebp-10h]
  float v81; // [esp-4h] [ebp-10h]
  float v82; // [esp-4h] [ebp-10h]
  float v83; // [esp-4h] [ebp-10h]
  float v84; // [esp-4h] [ebp-10h]
  float v85; // [esp-4h] [ebp-10h]
  float v86; // [esp-4h] [ebp-10h]
  float v87; // [esp-4h] [ebp-10h]
  float v88; // [esp-4h] [ebp-10h]
  float v89; // [esp-4h] [ebp-10h]
  float v90; // [esp-4h] [ebp-10h]
  float v91; // [esp-4h] [ebp-10h]
  float v92; // [esp-4h] [ebp-10h]

  v53 = a1[8] - a1[4];
  v56 = a1[9] - a1[5];
  v59 = a1[10] - a1[6];
  v63 = v53 * 0.5;
  v68 = v56 * 0.5;
  v73 = 0.5 * v59;
  v80 = ((double (__stdcall *)(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, int, int))*(_DWORD *)(*(_DWORD *)a1 + 40))(
          a2,
          a3,
          v18,
          v19,
          v21,
          v23,
          v25,
          v27,
          v29,
          a6,
          v32,
          v34,
          v36,
          v40,
          v43,
          v46,
          v47,
          v48,
          v49,
          v50,
          LODWORD(v53),
          LODWORD(v56),
          LODWORD(v59),
          v62,
          LODWORD(v63),
          LODWORD(v68),
          LODWORD(v73),
          v78,
          v79);
  v51 = ((double (__thiscall *)(float *))*(_DWORD *)(*(_DWORD *)a1 + 40))(a1);
  v37 = ((double (__thiscall *)(float *))*(_DWORD *)(*(_DWORD *)a1 + 40))(a1);
  v65 = v37 + v64;
  v70 = v69 + v51;
  v75 = v74 + v80;
  v54 = a1[8] + a1[4];
  v57 = a1[5] + a1[9];
  v60 = a1[10] + a1[6];
  v38 = v54 * 0.5;
  v41 = v57 * 0.5;
  v44 = 0.5 * v60;
  v81 = fabs(a4[10]);
  v33 = v81;
  v82 = fabs(a4[9]);
  v30 = v82;
  v7 = a4[8];
  v83 = fabs(v7);
  v22 = v83;
  v84 = fabs(a4[6]);
  v35 = v84;
  v85 = fabs(a4[5]);
  v24 = v85;
  v8 = a4[4];
  v86 = fabs(v8);
  v20 = v86;
  v9 = a4[2];
  v87 = fabs(v9);
  v28 = v87;
  v10 = a4[1];
  v88 = fabs(v10);
  v26 = v88;
  v11 = *a4;
  v89 = fabs(v11);
  v52 = v89;
  v12 = v11 * v38;
  v13 = v41;
  v14 = v9 * v44 + v10 * v41 + v12;
  v15 = v38;
  v90 = v14;
  v39 = v90 + a4[12];
  v91 = v8 * v15 + a4[5] * v41 + a4[6] * v44;
  v42 = v91 + a4[13];
  v92 = v44 * a4[10] + v13 * a4[9] + v15 * v7;
  v45 = v92 + a4[14];
  v55 = v65 * v52 + v70 * v26 + v75 * v28;
  v58 = v70 * v24 + v65 * v20 + v75 * v35;
  v61 = v65 * v22 + v70 * v30 + v75 * v33;
  v66 = v39 - v55;
  *(float *)a5 = v66;
  v71 = v42 - v58;
  *(float *)(a5 + 4) = v71;
  v76 = v45 - v61;
  *(float *)(a5 + 8) = v76;
  *(_DWORD *)(a5 + 12) = 0;
  v67 = v39 + v55;
  *(float *)v31 = v67;
  v72 = v42 + v58;
  v77 = v45 + v61;
  *(float *)(v31 + 4) = v72;
  *(float *)(v31 + 8) = v77;
  *(_DWORD *)(v31 + 12) = 0;
  return 0;
}
