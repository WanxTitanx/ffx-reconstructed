// Function: sub_9D15D0
// Address: 0x9d15d0
int __usercall sub_9D15D0@<eax>(int a1@<ecx>, float a2@<ebp>)
{
  double v3; // st7
  double v4; // st5
  double v5; // st3
  double v6; // st6
  double v7; // st4
  double v8; // st6
  double v9; // st7
  double v10; // st4
  double v11; // st5
  double v12; // st7
  double v13; // st6
  double v14; // st4
  double v15; // rtt
  double v16; // st3
  double v17; // st4
  double v18; // st2
  double v19; // st5
  double v20; // st6
  double v21; // st3
  double v23; // st6
  double v24; // st6
  double v25; // st6
  float v26; // [esp-B0h] [ebp-BCh]
  float v27; // [esp-ACh] [ebp-B8h]
  float v28; // [esp-A8h] [ebp-B4h]
  float v29; // [esp-98h] [ebp-A4h]
  float v30; // [esp-98h] [ebp-A4h]
  float v31; // [esp-94h] [ebp-A0h]
  float v32; // [esp-94h] [ebp-A0h]
  float v33; // [esp-90h] [ebp-9Ch]
  float v34; // [esp-90h] [ebp-9Ch]
  float v35; // [esp-8Ch] [ebp-98h]
  float v36; // [esp-8Ch] [ebp-98h]
  float v37; // [esp-88h] [ebp-94h]
  float v38; // [esp-88h] [ebp-94h]
  float v39; // [esp-84h] [ebp-90h]
  float v40; // [esp-84h] [ebp-90h]
  float v41; // [esp-80h] [ebp-8Ch]
  float v42; // [esp-80h] [ebp-8Ch]
  float v43; // [esp-80h] [ebp-8Ch]
  float v44; // [esp-80h] [ebp-8Ch]
  float v45; // [esp-7Ch] [ebp-88h]
  float v46; // [esp-7Ch] [ebp-88h]
  float v47; // [esp-7Ch] [ebp-88h]
  float v48; // [esp-7Ch] [ebp-88h]
  float v49; // [esp-78h] [ebp-84h]
  float v50; // [esp-78h] [ebp-84h]
  float v51; // [esp-78h] [ebp-84h]
  float v52; // [esp-78h] [ebp-84h]
  float v53; // [esp-6Ch] [ebp-78h]
  float v54; // [esp-6Ch] [ebp-78h]
  float v55; // [esp-68h] [ebp-74h]
  float v56; // [esp-68h] [ebp-74h]
  float v57; // [esp-64h] [ebp-70h]
  float v58; // [esp-64h] [ebp-70h]
  float v59; // [esp-60h] [ebp-6Ch]
  float v60; // [esp-60h] [ebp-6Ch]
  float v61; // [esp-5Ch] [ebp-68h]
  float v62; // [esp-5Ch] [ebp-68h]
  float v63; // [esp-58h] [ebp-64h]
  float v64; // [esp-58h] [ebp-64h]
  float v65; // [esp-58h] [ebp-64h]
  float v66; // [esp-58h] [ebp-64h]
  float v67; // [esp-54h] [ebp-60h]
  float v68; // [esp-54h] [ebp-60h]
  float v69; // [esp-54h] [ebp-60h]
  float v70; // [esp-54h] [ebp-60h]
  float v71; // [esp-54h] [ebp-60h]
  float v72; // [esp-54h] [ebp-60h]
  float v73; // [esp-54h] [ebp-60h]
  float v74; // [esp-50h] [ebp-5Ch]
  float v75; // [esp-50h] [ebp-5Ch]
  float v76; // [esp-50h] [ebp-5Ch]
  float v77; // [esp-50h] [ebp-5Ch]
  float v78; // [esp-50h] [ebp-5Ch]
  float v79; // [esp-4Ch] [ebp-58h]
  float v80; // [esp-4Ch] [ebp-58h]
  float v81; // [esp-4Ch] [ebp-58h]
  float v82; // [esp-4Ch] [ebp-58h]
  float v83; // [esp-4Ch] [ebp-58h]
  float v84; // [esp-48h] [ebp-54h]
  float v85; // [esp-48h] [ebp-54h]
  float v86; // [esp-48h] [ebp-54h]
  float v87; // [esp-44h] [ebp-50h]
  float v88; // [esp-44h] [ebp-50h]
  float v89; // [esp-44h] [ebp-50h]
  float v90; // [esp-44h] [ebp-50h]
  float v91; // [esp-44h] [ebp-50h]
  float v92; // [esp-44h] [ebp-50h]
  float v93; // [esp-44h] [ebp-50h]
  float v94; // [esp-44h] [ebp-50h]
  float v95; // [esp-44h] [ebp-50h]
  float v96; // [esp-44h] [ebp-50h]
  float v97; // [esp-44h] [ebp-50h]
  float v98[19]; // [esp-40h] [ebp-4Ch] BYREF
  float retaddr; // [esp+Ch] [ebp+0h]

  v98[16] = a2;
  v98[17] = retaddr;
  v61 = *(float *)(a1 + 1208);
  v53 = *(float *)(a1 + 1188);
  v79 = *(float *)(a1 + 1204);
  v74 = *(float *)(a1 + 1192);
  v41 = v53 * v61 - v74 * v79;
  v57 = *(float *)(a1 + 1200);
  v84 = *(float *)(a1 + 1184);
  v45 = v74 * v57 - v84 * v61;
  v3 = v84;
  v49 = v79 * v84 - v53 * v57;
  v55 = *(float *)(a1 + 1172);
  v85 = *(float *)(a1 + 1176);
  v4 = *(float *)(a1 + 1168);
  v63 = v45 * v55 + v41 * v4 + v49 * v85;
  v67 = 1.0 / v63;
  v64 = v4 * v53 - v55 * v3;
  v5 = v67;
  v39 = v64 * v67;
  v68 = v55 * v57 - v4 * v79;
  v37 = v68 * v5;
  v65 = v49 * v5;
  v69 = v3 * v85 - v4 * v74;
  v31 = v69 * v5;
  v70 = v4 * v61 - v85 * v57;
  v29 = v70 * v5;
  v35 = v45 * v5;
  v71 = v74 * v55 - v85 * v53;
  v59 = v71 * v5;
  v72 = v85 * v79 - v55 * v61;
  v33 = v72 * v5;
  v73 = v5 * v41;
  v54 = *(float *)(a1 + 1256);
  v80 = *(float *)(a1 + 1240);
  v56 = *(float *)(a1 + 1272);
  v6 = v65;
  v87 = v56 * v39 + v54 * v37 + v80 * v65;
  v62 = *(float *)(a1 + 1252);
  v58 = *(float *)(a1 + 1236);
  v75 = *(float *)(a1 + 1268);
  v66 = v58 * v65 + v62 * v37 + v75 * v39;
  v86 = *(float *)(a1 + 1232);
  v7 = v6 * v86;
  v8 = *(float *)(a1 + 1248);
  v9 = *(float *)(a1 + 1264);
  v38 = v39 * v9 + v37 * v8 + v7;
  v10 = v35;
  v40 = v56 * v31 + v54 * v29 + v80 * v35;
  v36 = v58 * v35 + v62 * v29 + v75 * v31;
  v30 = v29 * v8 + v10 * v86 + v31 * v9;
  v11 = v33;
  v98[3] = 0.0;
  v98[7] = 0.0;
  v98[11] = 0.0;
  v32 = v56 * v59 + v54 * v33 + v80 * v73;
  v98[2] = v32;
  v98[4] = v30;
  v98[5] = v36;
  v98[6] = v40;
  v98[8] = v38;
  v98[9] = v66;
  v98[10] = v87;
  v34 = v58 * v73 + v62 * v33 + v75 * v59;
  v60 = v11 * v8 + v73 * v86 + v59 * v9;
  v98[0] = v60;
  v98[1] = v34;
  sub_9D32F0(v98, a1 + 1296);
  v27 = *(float *)(a1 + 1248);
  v26 = *(float *)(a1 + 1232);
  v28 = *(float *)(a1 + 1264);
  v12 = *(float *)(a1 + 1192);
  v13 = *(float *)(a1 + 1208);
  v42 = v12 * v28 - v13 * v27;
  v14 = *(float *)(a1 + 1176);
  *(float *)(a1 + 1328) = v42;
  v46 = v13 * v26 - v28 * v14;
  *(float *)(a1 + 1332) = v46;
  v15 = v14;
  v50 = v14 * v27 - v26 * v12;
  *(float *)(a1 + 1336) = v50;
  *(_DWORD *)(a1 + 1340) = 0;
  v16 = *(float *)(a1 + 1332);
  v17 = *(float *)(a1 + 1336);
  v43 = v13 * v16 - v12 * v17;
  v18 = *(float *)(a1 + 1328);
  *(float *)(a1 + 1312) = v43;
  v88 = v18;
  v47 = v17 * v15 - v13 * v88;
  *(float *)(a1 + 1316) = v47;
  v51 = v12 * v88 - v16 * v15;
  *(float *)(a1 + 1320) = v51;
  *(_DWORD *)(a1 + 1324) = 0;
  v19 = *(float *)(a1 + 1336);
  v20 = *(float *)(a1 + 1332);
  v44 = v27 * v19 - v28 * v20;
  v21 = *(float *)(a1 + 1328);
  *(float *)(a1 + 1344) = v44;
  v48 = v28 * v21 - v19 * v26;
  *(float *)(a1 + 1348) = v48;
  v52 = v20 * v26 - v27 * v21;
  *(float *)(a1 + 1352) = v52;
  *(_DWORD *)(a1 + 1356) = 0;
  v76 = *(float *)(a1 + 1316);
  v23 = *(float *)(a1 + 1312);
  v81 = *(float *)(a1 + 1320);
  v89 = v23 * v23 + v76 * v76 + v81 * v81;
  v90 = sqrt(v89);
  v91 = 1.0 / v90;
  *(float *)(a1 + 1312) = v91 * v23;
  *(float *)(a1 + 1316) = v91 * v76;
  *(float *)(a1 + 1320) = v91 * v81;
  v77 = *(float *)(a1 + 1332);
  v24 = *(float *)(a1 + 1328);
  v82 = *(float *)(a1 + 1336);
  v92 = v24 * v24 + v77 * v77 + v82 * v82;
  v93 = sqrt(v92);
  v94 = 1.0 / v93;
  *(float *)(a1 + 1328) = v24 * v94;
  *(float *)(a1 + 1332) = v77 * v94;
  *(float *)(a1 + 1336) = v94 * v82;
  v78 = *(float *)(a1 + 1348);
  v25 = *(float *)(a1 + 1344);
  v83 = *(float *)(a1 + 1352);
  v95 = v25 * v25 + v78 * v78 + v83 * v83;
  v96 = sqrt(v95);
  v97 = 1.0 / v96;
  *(float *)(a1 + 1344) = v97 * v25;
  *(float *)(a1 + 1348) = v97 * v78;
  *(float *)(a1 + 1352) = v97 * v83;
  return 0;
}
