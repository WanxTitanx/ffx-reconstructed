// Function: sub_A49F10
// Address: 0xa49f10
// Size: 0xce1
// Prototype: 

int __usercall sub_A49F10@<eax>(int a1@<ebp>)
{
  char *v1; // ecx
  double v2; // rt1
  double v3; // st7
  int result; // eax
  double v5; // st6
  double v6; // st5
  double v7; // st4
  double v8; // st3
  float *v9; // edx
  int n20; // esi
  char v11; // al
  float *v12; // edi
  _DWORD *v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  double v22; // rt0
  double v23; // st3
  float v24; // eax
  double v25; // st7
  bool v26; // zf
  char *v27; // [esp-254h] [ebp-260h]
  float v28; // [esp-230h] [ebp-23Ch]
  float v29; // [esp-21Ch] [ebp-228h]
  float v30; // [esp-210h] [ebp-21Ch]
  float v31; // [esp-20Ch] [ebp-218h]
  float v32; // [esp-200h] [ebp-20Ch]
  float v33; // [esp-1FCh] [ebp-208h]
  float v34; // [esp-1F0h] [ebp-1FCh]
  float v35; // [esp-1DCh] [ebp-1E8h]
  float v36; // [esp-1D0h] [ebp-1DCh]
  float v37; // [esp-1CCh] [ebp-1D8h]
  float v38; // [esp-1B8h] [ebp-1C4h]
  float *v39; // [esp-1B4h] [ebp-1C0h]
  int n20_1; // [esp-1B0h] [ebp-1BCh]
  int v41; // [esp-1ACh] [ebp-1B8h]
  float v42; // [esp-1A8h] [ebp-1B4h]
  float v43; // [esp-1A8h] [ebp-1B4h]
  float v44; // [esp-1A8h] [ebp-1B4h]
  float v45; // [esp-1A8h] [ebp-1B4h]
  float v46; // [esp-1A8h] [ebp-1B4h]
  int n17; // [esp-1A8h] [ebp-1B4h]
  float v48; // [esp-1A4h] [ebp-1B0h]
  float v49; // [esp-1A4h] [ebp-1B0h]
  float v50; // [esp-1A4h] [ebp-1B0h]
  float v51; // [esp-1A4h] [ebp-1B0h]
  float v52; // [esp-1A4h] [ebp-1B0h]
  float v53; // [esp-1A4h] [ebp-1B0h]
  float v54; // [esp-1A4h] [ebp-1B0h]
  float v55; // [esp-1A4h] [ebp-1B0h]
  float v56; // [esp-1A4h] [ebp-1B0h]
  float v57; // [esp-1A4h] [ebp-1B0h]
  float v58; // [esp-1A4h] [ebp-1B0h]
  float v59; // [esp-1A4h] [ebp-1B0h]
  float v60; // [esp-1A4h] [ebp-1B0h]
  float v61; // [esp-1A4h] [ebp-1B0h]
  float v62; // [esp-1A4h] [ebp-1B0h]
  float v63; // [esp-1A4h] [ebp-1B0h]
  float v64; // [esp-1A0h] [ebp-1ACh] BYREF
  float v65; // [esp-19Ch] [ebp-1A8h]
  float v66; // [esp-198h] [ebp-1A4h]
  float v67; // [esp-194h] [ebp-1A0h]
  int n128; // [esp-190h] [ebp-19Ch]
  int n128_1; // [esp-18Ch] [ebp-198h]
  int n128_2; // [esp-188h] [ebp-194h]
  int n128_3; // [esp-184h] [ebp-190h]
  float v72; // [esp-180h] [ebp-18Ch]
  float v73; // [esp-17Ch] [ebp-188h]
  float v74; // [esp-178h] [ebp-184h]
  float v75; // [esp-174h] [ebp-180h]
  int n128_4; // [esp-170h] [ebp-17Ch]
  int n128_5; // [esp-16Ch] [ebp-178h]
  int n128_6; // [esp-168h] [ebp-174h]
  int n128_7; // [esp-164h] [ebp-170h]
  float v80; // [esp-160h] [ebp-16Ch]
  float v81; // [esp-15Ch] [ebp-168h]
  float v82; // [esp-158h] [ebp-164h]
  float v83; // [esp-154h] [ebp-160h]
  int n128_8; // [esp-150h] [ebp-15Ch]
  int n128_9; // [esp-14Ch] [ebp-158h]
  int n128_10; // [esp-148h] [ebp-154h]
  int n128_11; // [esp-144h] [ebp-150h]
  float v88; // [esp-140h] [ebp-14Ch]
  float v89; // [esp-13Ch] [ebp-148h]
  float v90; // [esp-138h] [ebp-144h]
  float v91; // [esp-134h] [ebp-140h]
  int n128_12; // [esp-130h] [ebp-13Ch]
  int n128_13; // [esp-12Ch] [ebp-138h]
  int n128_14; // [esp-128h] [ebp-134h]
  int n128_15; // [esp-124h] [ebp-130h]
  int v96; // [esp-110h] [ebp-11Ch]
  int v97; // [esp-10Ch] [ebp-118h]
  char v98[264]; // [esp-108h] [ebp-114h] BYREF
  int v99; // [esp+0h] [ebp-Ch]
  void *v100; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v99 = a1;
  v100 = retaddr;
  v96 = 0;
  v1 = (char *)(dword_2305834[0] + 77408);
  v97 = 0;
  v42 = (float)(*(_DWORD *)(dword_2305834[0] + 71320) & 0x1FF);
  v38 = v42 * 0.00390625 - 1.0;
  v43 = v38 + 2.0;
  v28 = v43;
  v29 = v43;
  v30 = v43;
  v31 = v43;
  v44 = 1.0 - v38;
  v32 = v44;
  v33 = v44 + 0.5;
  v45 = v44 + 2.0;
  v34 = v45;
  v2 = v45;
  v46 = v33 + 2.0;
  v35 = v46;
  v37 = v46;
  v36 = v2;
  v3 = v38;
  result = dword_2305834[0] + 71724;
  v41 = dword_2305834[0] + 71724;
  n17 = 17;
  v5 = 0.0625;
  v6 = 2048.0;
  v7 = 256.0;
  v8 = 512.0;
  do
  {
    v9 = (float *)result;
    n20 = 20;
    v39 = (float *)result;
    n20_1 = 20;
    do
    {
      v11 = *v1++;
      v27 = v1;
      if ( v11 )
      {
        v12 = (float *)dword_1A860EC;
        *dword_1A860EC = 4;
        v13 = dword_1A860EC;
        *((_DWORD *)v12 + 2) = 1298;
        v13[1] = 808075264;
        v12[3] = 0.0;
        *((_DWORD *)v12 + 52) = 32772;
        v12[53] = 6.1936589e-10;
        *((_DWORD *)v12 + 54) = 1298;
        v12[55] = 0.0;
        v14 = *((_DWORD *)v9 - 91);
        *((_DWORD *)v12 + 64) = v14;
        *((_DWORD *)v12 + 12) = v14;
        v15 = *((_DWORD *)v9 - 90);
        *((_DWORD *)v12 + 65) = v15;
        *((_DWORD *)v12 + 13) = v15;
        *((_DWORD *)v12 + 66) = 0x2000;
        *((_DWORD *)v12 + 14) = 0x2000;
        v12[67] = 0.0;
        v12[15] = 0.0;
        v16 = *((_DWORD *)v9 - 87);
        *((_DWORD *)v12 + 76) = v16;
        *((_DWORD *)v12 + 24) = v16;
        v17 = *((_DWORD *)v9 - 86);
        *((_DWORD *)v12 + 77) = v17;
        *((_DWORD *)v12 + 25) = v17;
        *((_DWORD *)v12 + 78) = 0x2000;
        *((_DWORD *)v12 + 26) = 0x2000;
        v12[79] = 0.0;
        v12[27] = 0.0;
        v18 = *((_DWORD *)v9 - 7);
        *((_DWORD *)v12 + 88) = v18;
        *((_DWORD *)v12 + 36) = v18;
        v19 = *((_DWORD *)v9 - 6);
        *((_DWORD *)v12 + 89) = v19;
        *((_DWORD *)v12 + 37) = v19;
        *((_DWORD *)v12 + 90) = 0x2000;
        *((_DWORD *)v12 + 38) = 0x2000;
        v12[91] = 0.0;
        v12[39] = 0.0;
        v20 = *((_DWORD *)v9 - 3);
        *((_DWORD *)v12 + 100) = v20;
        *((_DWORD *)v12 + 48) = v20;
        v21 = *((_DWORD *)v9 - 2);
        *((_DWORD *)v12 + 101) = v21;
        *((_DWORD *)v12 + 49) = v21;
        *((_DWORD *)v12 + 102) = 0x2000;
        *((_DWORD *)v12 + 50) = 0x2000;
        v12[103] = 0.0;
        v12[51] = 0.0;
        unk_C8F7D0 = v38;
        unk_C8F7D4 = v38;
        unk_C8F7D8 = 1.0;
        flt_C8F7DC = 0.0;
        unk_C8F7E0 = *(v9 - 88);
        unk_C8F7D0 = unk_C8F7E0 * v3;
        unk_C8F7D4 = v38 * unk_C8F7E0;
        unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
        v12[4] = unk_C8F7D0;
        v12[5] = unk_C8F7D4;
        v12[6] = unk_C8F7D8;
        v12[7] = flt_C8F7DC;
        unk_C8F7D0 = v28;
        unk_C8F7D4 = v38;
        unk_C8F7D8 = 1.0;
        flt_C8F7DC = 0.0;
        unk_C8F7E0 = *(v9 - 84);
        unk_C8F7D0 = v28 * unk_C8F7E0;
        unk_C8F7D4 = v38 * unk_C8F7E0;
        unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
        v12[16] = unk_C8F7D0;
        v12[17] = unk_C8F7D4;
        v12[18] = unk_C8F7D8;
        v12[19] = flt_C8F7DC;
        unk_C8F7D0 = v38;
        unk_C8F7D4 = v29;
        unk_C8F7D8 = 1.0;
        flt_C8F7DC = 0.0;
        unk_C8F7E0 = *(v9 - 4);
        unk_C8F7D0 = v3 * unk_C8F7E0;
        unk_C8F7D4 = v29 * unk_C8F7E0;
        v22 = v8;
        unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
        v12[28] = unk_C8F7D0;
        v12[29] = unk_C8F7D4;
        v12[30] = unk_C8F7D8;
        v12[31] = flt_C8F7DC;
        unk_C8F7D0 = v30;
        unk_C8F7D4 = v31;
        unk_C8F7D8 = 1.0;
        flt_C8F7DC = 0.0;
        unk_C8F7E0 = *v9;
        unk_C8F7D0 = v30 * unk_C8F7E0;
        unk_C8F7D4 = v31 * unk_C8F7E0;
        unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
        v12[40] = unk_C8F7D0;
        v12[41] = unk_C8F7D4;
        v12[42] = unk_C8F7D8;
        v12[43] = flt_C8F7DC;
        unk_C8F7D0 = v32;
        unk_C8F7D4 = v33;
        unk_C8F7D8 = 1.0;
        flt_C8F7DC = 0.0;
        unk_C8F7E0 = *(v9 - 88);
        unk_C8F7D0 = v32 * unk_C8F7E0;
        unk_C8F7D4 = v33 * unk_C8F7E0;
        unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
        v12[56] = unk_C8F7D0;
        v12[57] = unk_C8F7D4;
        v12[58] = unk_C8F7D8;
        v12[59] = flt_C8F7DC;
        unk_C8F7D0 = v34;
        unk_C8F7D4 = v33;
        unk_C8F7D8 = 1.0;
        flt_C8F7DC = 0.0;
        unk_C8F7E0 = *(v9 - 84);
        unk_C8F7D0 = v34 * unk_C8F7E0;
        unk_C8F7D4 = v33 * unk_C8F7E0;
        unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
        v12[68] = unk_C8F7D0;
        v12[69] = unk_C8F7D4;
        v12[70] = unk_C8F7D8;
        v12[71] = flt_C8F7DC;
        unk_C8F7D0 = v32;
        unk_C8F7D4 = v35;
        unk_C8F7D8 = 1.0;
        flt_C8F7DC = 0.0;
        unk_C8F7E0 = *(v9 - 4);
        unk_C8F7D0 = v32 * unk_C8F7E0;
        unk_C8F7D4 = v35 * unk_C8F7E0;
        unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
        v12[80] = unk_C8F7D0;
        v12[81] = unk_C8F7D4;
        v12[82] = unk_C8F7D8;
        v12[83] = flt_C8F7DC;
        unk_C8F7D0 = v36;
        unk_C8F7D4 = v37;
        unk_C8F7D8 = 1.0;
        flt_C8F7DC = 0.0;
        unk_C8F7E0 = *v9;
        unk_C8F7D0 = v36 * unk_C8F7E0;
        unk_C8F7D4 = v37 * unk_C8F7E0;
        unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
        v12[92] = unk_C8F7D0;
        v23 = (double)*((int *)v12 + 12);
        v12[93] = unk_C8F7D4;
        v12[94] = unk_C8F7D8;
        v24 = flt_C8F7DC;
        *((_DWORD *)v12 + 96) = 64;
        *((_DWORD *)v12 + 84) = 64;
        *((_DWORD *)v12 + 72) = 64;
        *((_DWORD *)v12 + 60) = 64;
        *((_DWORD *)v12 + 44) = 64;
        *((_DWORD *)v12 + 32) = 64;
        *((_DWORD *)v12 + 20) = 64;
        *((_DWORD *)v12 + 8) = 64;
        v12[95] = v24;
        *((_DWORD *)v12 + 97) = 64;
        *((_DWORD *)v12 + 85) = 64;
        *((_DWORD *)v12 + 73) = 64;
        *((_DWORD *)v12 + 61) = 64;
        *((_DWORD *)v12 + 45) = 64;
        *((_DWORD *)v12 + 33) = 64;
        *((_DWORD *)v12 + 21) = 64;
        *((_DWORD *)v12 + 9) = 64;
        *((_DWORD *)v12 + 98) = 64;
        *((_DWORD *)v12 + 86) = 64;
        *((_DWORD *)v12 + 74) = 64;
        *((_DWORD *)v12 + 62) = 64;
        *((_DWORD *)v12 + 46) = 64;
        *((_DWORD *)v12 + 34) = 64;
        *((_DWORD *)v12 + 22) = 64;
        *((_DWORD *)v12 + 10) = 64;
        *((_DWORD *)v12 + 99) = 64;
        *((_DWORD *)v12 + 87) = 64;
        *((_DWORD *)v12 + 75) = 64;
        *((_DWORD *)v12 + 63) = 64;
        *((_DWORD *)v12 + 47) = 64;
        *((_DWORD *)v12 + 35) = 64;
        *((_DWORD *)v12 + 23) = 64;
        *((_DWORD *)v12 + 11) = 64;
        v48 = v23;
        v64 = v48 * v5 - v6 + v7;
        v49 = (float)*((int *)v12 + 13);
        v65 = v49 * v5 - v6 + 208.0;
        v50 = (float)*((int *)v12 + 24);
        v72 = v50 * v5 - v6 + v7;
        v51 = (float)*((int *)v12 + 25);
        v73 = v51 * v5 - v6 + 208.0;
        v52 = (float)*((int *)v12 + 36);
        v80 = v52 * v5 - v6 + v7;
        v53 = (float)*((int *)v12 + 37);
        v81 = v53 * v5 - v6 + 208.0;
        v54 = (float)*((int *)v12 + 48);
        v88 = v7 + v54 * v5 - v6;
        v55 = (float)*((int *)v12 + 49);
        v89 = v5 * v55 - v6 + 208.0;
        v66 = v12[4] * v22;
        v67 = v12[5] * v22;
        v74 = v12[16] * v22;
        v75 = v12[17] * v22;
        v82 = v12[28] * v22;
        v83 = v12[29] * v22;
        v90 = v12[40] * v22;
        v25 = v22 * v12[41];
        n128 = 128;
        n128_1 = 128;
        n128_2 = 128;
        v91 = v25;
        n128_3 = 128;
        n128_4 = 128;
        n128_5 = 128;
        n128_6 = 128;
        n128_7 = 128;
        n128_8 = 128;
        n128_9 = 128;
        n128_10 = 128;
        n128_11 = 128;
        n128_12 = 128;
        n128_13 = 128;
        n128_14 = 128;
        n128_15 = 128;
        sub_63EAE0((int)&v64, v98, 10);
        v56 = (float)*((int *)v12 + 64);
        v64 = v56 * 0.0625 - 2048.0 + 256.0;
        v57 = (float)*((int *)v12 + 65);
        v65 = v57 * 0.0625 - 2048.0 + 208.0;
        v58 = (float)*((int *)v12 + 76);
        v72 = v58 * 0.0625 - 2048.0 + 256.0;
        v59 = (float)*((int *)v12 + 77);
        v73 = v59 * 0.0625 - 2048.0 + 208.0;
        v60 = (float)*((int *)v12 + 88);
        v80 = v60 * 0.0625 - 2048.0 + 256.0;
        v61 = (float)*((int *)v12 + 89);
        v81 = v61 * 0.0625 - 2048.0 + 208.0;
        v62 = (float)*((int *)v12 + 100);
        v88 = v62 * 0.0625 - 2048.0 + 256.0;
        v63 = (float)*((int *)v12 + 101);
        v89 = 0.0625 * v63 - 2048.0 + 208.0;
        v66 = v12[56] * 512.0;
        v67 = v12[57] * 512.0;
        v74 = v12[68] * 512.0;
        v75 = v12[69] * 512.0;
        v82 = v12[80] * 512.0;
        v83 = v12[81] * 512.0;
        v90 = v12[92] * 512.0;
        v91 = 512.0 * v12[93];
        sub_63EAE0((int)&v64, v98, 10);
        v3 = v38;
        v1 = v27;
        v5 = 0.0625;
        v9 = v39;
        v6 = 2048.0;
        n20 = n20_1;
        v8 = 512.0;
        v7 = 256.0;
      }
      v9 += 4;
      --n20;
      v39 = v9;
      n20_1 = n20;
    }
    while ( n20 );
    result = v41 + 336;
    v26 = n17-- == 1;
    v41 += 336;
  }
  while ( !v26 );
  return result;
}

