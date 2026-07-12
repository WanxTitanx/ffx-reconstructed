// Function: sub_994110
// Address: 0x994110
// bad sp value at call has been detected, the output may be wrong!
int __userpurge sub_994110@<eax>(
        int a1@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        float *a5,
        float *a6,
        float a7)
{
  double v8; // st6
  double v9; // st7
  float *v10; // eax
  double v11; // st7
  double v12; // st6
  double v13; // st3
  double v14; // st7
  double v15; // st5
  double v16; // st4
  double v17; // st6
  double v18; // st3
  double v19; // st7
  double v20; // st4
  double v21; // st5
  double v22; // st3
  double v23; // st4
  double v24; // st7
  double v25; // st5
  float *v26; // edx
  double v27; // st7
  float *v28; // eax
  double v29; // st6
  double v30; // st3
  double v31; // st6
  double v32; // st7
  double v33; // st5
  double v34; // st4
  double v35; // st2
  double v36; // st6
  double v37; // st3
  int v38; // ecx
  float v40; // [esp+0h] [ebp-120h]
  float v42; // [esp+14h] [ebp-10Ch]
  float v43; // [esp+18h] [ebp-108h]
  float v44; // [esp+1Ch] [ebp-104h]
  float v45; // [esp+28h] [ebp-F8h]
  float v46; // [esp+2Ch] [ebp-F4h]
  float v47; // [esp+34h] [ebp-ECh] BYREF
  float v48; // [esp+38h] [ebp-E8h]
  float v49; // [esp+3Ch] [ebp-E4h]
  int v50; // [esp+40h] [ebp-E0h]
  float v51; // [esp+4Ch] [ebp-D4h]
  float v52; // [esp+50h] [ebp-D0h]
  float v53; // [esp+54h] [ebp-CCh]
  float v54; // [esp+58h] [ebp-C8h]
  float v55; // [esp+5Ch] [ebp-C4h]
  float v56; // [esp+60h] [ebp-C0h]
  float v57; // [esp+64h] [ebp-BCh]
  float v58; // [esp+68h] [ebp-B8h]
  float v59; // [esp+6Ch] [ebp-B4h]
  int v60; // [esp+70h] [ebp-B0h]
  float v61; // [esp+7Ch] [ebp-A4h]
  float v62; // [esp+80h] [ebp-A0h]
  float v63; // [esp+84h] [ebp-9Ch]
  float v64; // [esp+88h] [ebp-98h]
  float v65; // [esp+8Ch] [ebp-94h]
  float v66; // [esp+94h] [ebp-8Ch]
  float v67; // [esp+98h] [ebp-88h]
  float v68; // [esp+9Ch] [ebp-84h]
  float v69; // [esp+A0h] [ebp-80h]
  float v70; // [esp+A4h] [ebp-7Ch]
  float v71; // [esp+A8h] [ebp-78h]
  float v72; // [esp+ACh] [ebp-74h]
  float v73; // [esp+B0h] [ebp-70h]
  float v74; // [esp+B4h] [ebp-6Ch]
  float v75; // [esp+B8h] [ebp-68h]
  float v76; // [esp+BCh] [ebp-64h]
  float v77; // [esp+C0h] [ebp-60h]
  _DWORD v78[23]; // [esp+C4h] [ebp-5Ch] BYREF
  _UNKNOWN *retaddr; // [esp+120h] [ebp+0h]

  v78[20] = a2;
  v78[21] = retaddr;
  v8 = *a5 * a7;
  v9 = a7;
  if ( *(_BYTE *)(a1 + 384) )
  {
    v47 = v8;
    v48 = a5[1] * v9;
    v49 = v9 * a5[2];
    v57 = v47 + *a6;
    v58 = v48 + a6[1];
    v59 = v49 + a6[2];
    v10 = (float *)sub_982990((float *)(a1 + 192), (int)v78);
    v69 = *(float *)(a1 + 324);
    v67 = v10[13];
    v72 = *(float *)(a1 + 320);
    v75 = v10[12];
    v62 = *(float *)(a1 + 328);
    v76 = v10[14];
    v11 = v75;
    v12 = v76;
    v75 = v75 * v72 + v67 * v69 + v76 * v62;
    v63 = v75 + *(float *)(a1 + 368);
    v61 = *(float *)(a1 + 340);
    v66 = *(float *)(a1 + 336);
    v71 = *(float *)(a1 + 344);
    v75 = v66 * v11 + v61 * v67 + v71 * v76;
    v64 = v75 + *(float *)(a1 + 372);
    v73 = *(float *)(a1 + 356);
    v76 = *(float *)(a1 + 352);
    v74 = *(float *)(a1 + 360);
    v13 = v11 * v76;
    v14 = v73;
    v15 = v74;
    v16 = v12 * v74 + v67 * v73 + v13;
    v17 = v76;
    v75 = v16;
    v65 = v75 + *(float *)(a1 + 376);
    v74 = v10[6];
    v55 = v10[2];
    v73 = v10[10];
    v77 = v55 * v76 + v74 * v14 + v73 * v15;
    v67 = v10[5];
    v76 = v10[1];
    v75 = v10[9];
    v70 = v76 * v17 + v67 * v14 + v75 * v15;
    v53 = v10[4];
    v54 = *v10;
    v18 = v14 * v53 + v17 * v54;
    v19 = v10[8];
    v20 = v15 * v19 + v18;
    v21 = v54;
    v68 = v20;
    v52 = v74 * v61 + v55 * v66 + v73 * v71;
    v22 = v67;
    v23 = v75;
    v75 = v61 * v67 + v66 * v76 + v75 * v71;
    v67 = v54 * v66 + v53 * v61 + v19 * v71;
    v54 = v55 * v72 + v74 * v69 + v73 * v62;
    v56 = v23 * v62 + v22 * v69 + v76 * v72;
    v53 = v19 * v62 + v53 * v69 + v21 * v72;
    v24 = v58;
    v25 = v57;
    v56 = v58 * v56 + v57 * v53 + v59 * v54;
    v57 = v56 + v63;
    v52 = v58 * v75 + v25 * v67 + v59 * v52;
    v58 = v52 + v64;
    v77 = v24 * v70 + v25 * v68 + v59 * v77;
    v59 = v77 + v65;
    v26 = a5;
    v63 = v57 - *a6;
    v64 = v58 - a6[1];
    v65 = v59 - a6[2];
    v68 = a5[1];
    v77 = *a5;
    v70 = a5[2];
    v76 = v77 * v63 + v68 * v64 + v70 * v65;
    v63 = v77 * v76;
    v64 = v68 * v76;
    v65 = v70 * v76;
    v57 = v63 + v57;
    v27 = v76;
    v58 = v58 + v64;
    v59 = v59 + v65;
  }
  else
  {
    v63 = v8;
    v64 = a5[1] * v9;
    v65 = v9 * a5[2];
    v42 = *a6 + v63;
    v43 = v64 + a6[1];
    v44 = a6[2] + v65;
    v28 = (float *)sub_982990((float *)(a1 + 256), (int)v78);
    v69 = *(float *)(a1 + 324);
    v68 = v28[13];
    v72 = *(float *)(a1 + 320);
    v77 = v28[12];
    v62 = *(float *)(a1 + 328);
    v70 = v28[14];
    v29 = v77;
    v77 = v62 * v70 + v69 * v68 + v72 * v77;
    v63 = v77 + *(float *)(a1 + 368);
    v61 = *(float *)(a1 + 340);
    v66 = *(float *)(a1 + 336);
    v71 = *(float *)(a1 + 344);
    v77 = v66 * v29 + v61 * v68 + v71 * v70;
    v64 = v77 + *(float *)(a1 + 372);
    v73 = *(float *)(a1 + 356);
    v76 = *(float *)(a1 + 352);
    v74 = *(float *)(a1 + 360);
    v30 = v29 * v76;
    v31 = v73;
    v32 = v74;
    v33 = v76;
    v77 = v70 * v74 + v68 * v73 + v30;
    v65 = v77 + *(float *)(a1 + 376);
    v73 = v28[6];
    v76 = v28[2];
    v74 = v28[10];
    v51 = v33 * v76 + v31 * v73 + v32 * v74;
    v75 = v28[5];
    v55 = v28[1];
    v77 = v28[9];
    v34 = v77;
    v45 = v32 * v77 + v33 * v55 + v31 * v75;
    v68 = v28[4];
    v77 = *v28;
    v35 = v31 * v68 + v33 * v77;
    v36 = v28[8];
    v46 = v32 * v36 + v35;
    v67 = v66 * v76 + v61 * v73 + v71 * v74;
    v37 = v75;
    v75 = v61 * v75 + v66 * v55 + v71 * v34;
    v54 = v66 * v77 + v61 * v68 + v71 * v36;
    v56 = v72 * v76 + v69 * v73 + v62 * v74;
    v70 = v34 * v62 + v37 * v69 + v72 * v55;
    v77 = v68 * v69 + v77 * v72 + v36 * v62;
    v52 = a6[1];
    v68 = *a6;
    v53 = a6[2];
    v77 = v56 * v53 + v70 * v52 + v77 * v68;
    v57 = v77 + v63;
    v26 = a5;
    v77 = v54 * v68 + v75 * v52 + v67 * v53;
    v58 = v77 + v64;
    v51 = v52 * v45 + v68 * v46 + v53 * v51;
    v59 = v51 + v65;
    v63 = v42 - v57;
    v64 = v43 - v58;
    v65 = v44 - v59;
    v76 = v26[1] * v64 + *v26 * v63 + v65 * a5[2];
    v27 = v76;
  }
  v38 = *(_DWORD *)(a1 + 176);
  v47 = v57;
  v48 = v58;
  v49 = v59;
  v40 = v27;
  v60 = 0;
  v50 = 0;
  return (*(int (__thiscall **)(int, float *, float *, _DWORD, int, int))(*(_DWORD *)v38 + 12))(
           v38,
           v26,
           &v47,
           LODWORD(v40),
           a3,
           a4);
}
