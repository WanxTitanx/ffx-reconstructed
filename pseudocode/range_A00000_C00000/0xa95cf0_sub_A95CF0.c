// Function: sub_A95CF0
// Address: 0xa95cf0
// Size: 0x635
// Prototype: _DWORD __cdecl(unsigned int, unsigned int, int n1124859904, int)

int __fastcall sub_A95CF0(int a1, int *a2, float *a3, unsigned int a4, float n1124859904, int a6)
{
  int v6; // edi
  void *v7; // esp
  int *v8; // ebx
  void *v9; // esp
  void *v10; // esp
  void *v11; // esp
  void *v12; // esp
  float v13; // xmm5_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float *v18; // ecx
  char *v19; // edx
  float *v20; // esi
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm5_4
  float n1124859904_1; // xmm2_4
  float *v26; // eax
  float v27; // xmm6_4
  float v28; // xmm7_4
  float v29; // xmm5_4
  bool v30; // zf
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  unsigned int v37; // esi
  int v38; // eax
  int v39; // edx
  int v40; // ecx
  float v41; // xmm5_4
  int *v42; // edi
  int v43; // ebx
  int v44; // edx
  float v45; // xmm3_4
  float v46; // xmm7_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  float v49; // xmm6_4
  float v50; // xmm4_4
  float v51; // xmm0_4
  float v52; // xmm0_4
  int *v53; // eax
  int v54; // edx
  int result; // eax
  int i; // edx
  float v57; // xmm3_4
  float v58; // xmm2_4
  float v59; // xmm7_4
  float v60; // xmm1_4
  float v61; // xmm6_4
  float v62; // xmm4_4
  float v63; // xmm0_4
  float v64; // xmm0_4
  int *v65; // eax
  int v66; // edx
  float v67; // xmm0_4
  int v68; // ebx
  int v69; // ecx
  int v70; // ebx
  int v71; // edi
  int v72; // eax
  int v73; // edx
  int v74; // ebx
  float v75; // xmm2_4
  float v76; // xmm3_4
  float v77; // xmm7_4
  float v78; // xmm5_4
  float v79; // xmm0_4
  float v80; // xmm5_4
  float v81; // xmm7_4
  float v82; // xmm1_4
  bool v83; // sf
  int v84; // edx
  int v85; // ebx
  float v86; // xmm2_4
  float v87; // xmm3_4
  float v88; // xmm7_4
  float v89; // xmm5_4
  float v90; // xmm0_4
  float v91; // xmm7_4
  float v92; // xmm1_4
  float v93; // xmm1_4
  int v94; // [esp+0h] [ebp-5Ch] BYREF
  int v95; // [esp+4h] [ebp-58h] BYREF
  float v96; // [esp+Ch] [ebp-50h]
  int v97; // [esp+10h] [ebp-4Ch]
  int v98; // [esp+14h] [ebp-48h]
  int v99; // [esp+18h] [ebp-44h]
  int v100; // [esp+1Ch] [ebp-40h]
  float v101; // [esp+24h] [ebp-38h]
  int v102; // [esp+28h] [ebp-34h]
  float v103; // [esp+2Ch] [ebp-30h]
  float v104; // [esp+30h] [ebp-2Ch]
  float v105; // [esp+34h] [ebp-28h]
  int *v106; // [esp+38h] [ebp-24h]
  float v107; // [esp+3Ch] [ebp-20h]
  int v108; // [esp+40h] [ebp-1Ch]
  float *v109; // [esp+48h] [ebp-14h]
  char *v110; // [esp+4Ch] [ebp-10h]
  float *v111; // [esp+50h] [ebp-Ch]
  int *v112; // [esp+54h] [ebp-8h]
  float v113; // [esp+58h] [ebp-4h]
  unsigned int v114; // [esp+64h] [ebp+8h]
  unsigned int v115; // [esp+64h] [ebp+8h]

  v6 = a1;
  v106 = a2;
  v108 = a1;
  v7 = alloca(4 * a1);
  v8 = &v94;
  v112 = &v94;
  v9 = alloca(4 * a1);
  v111 = (float *)&v94;
  v10 = alloca(4 * a1);
  v110 = (char *)&v94;
  v11 = alloca(4 * a1);
  v109 = (float *)&v94;
  v12 = alloca(4 * a1);
  v13 = *a3 + n1124859904;
  v14 = 0.0;
  v15 = 0.0;
  v16 = 0.0;
  v113 = 0.0;
  v96 = 0.0;
  v17 = 1.0;
  v103 = 0.0;
  if ( v13 < 1.0 )
    v13 = 1.0;
  v18 = v111;
  v19 = v110;
  v20 = v109;
  v107 = 1.0;
  v21 = (float)(v13 * v13) * 0.5;
  v22 = v21 + 0.0;
  v23 = (float)(v21 * v13) + 0.0;
  v24 = v22;
  *v111 = v22;
  *(_DWORD *)v19 = 0;
  v105 = v22;
  v101 = v22;
  n1124859904_1 = n1124859904;
  *v20 = v23;
  v104 = v23;
  v94 = 0;
  if ( v6 > 1 )
  {
    v100 = (char *)v18 - (char *)&v94;
    v97 = 0;
    v99 = v19 - (char *)&v94;
    v98 = (char *)v20 - (char *)&v94;
    v26 = (float *)&v95;
    v102 = v6 - 1;
    v27 = v24;
    v28 = v24;
    do
    {
      v29 = *(float *)((char *)v26 + (char *)a3 - (char *)&v94) + n1124859904_1;
      if ( v29 < 1.0 )
        v29 = 1.0;
      ++v26;
      v30 = v102-- == 1;
      v31 = v107 * (float)(v29 * v29);
      v27 = v27 + (float)(v29 * v29);
      v28 = v28 + v31;
      v32 = v31 * v107;
      v33 = (float)((float)(v29 * v29) * v29) + v104;
      *(v26 - 1) = v27;
      v14 = v14 + v32;
      *(float *)((char *)v26 + (char *)v18 - (char *)&v94 - 4) = v28;
      v34 = (float)(v31 * v29) + v103;
      *(float *)((char *)v26 + v19 - (char *)&v94 - 4) = v14;
      v35 = v33;
      n1124859904_1 = n1124859904;
      *(float *)((char *)v26 + (char *)v20 - (char *)&v94 - 4) = v35;
      v104 = v35;
      v36 = v107 + 1.0;
      *(v26 - 1) = v34;
      v103 = v34;
      v107 = v36;
    }
    while ( !v30 );
    v16 = v96;
    v6 = v108;
    v8 = v112;
    v14 = 0.0;
    v17 = 1.0;
    v15 = v96;
  }
  v37 = a4;
  v38 = *v106;
  v39 = *v106 >> 16;
  v40 = 0;
  v41 = 0.0;
  if ( v39 < 0 )
  {
    v42 = v112;
    v43 = 0;
    do
    {
      v44 = -v39;
      v45 = v111[(unsigned __int16)v38] - v111[v44];
      v46 = *(float *)&v110[4 * v44] + *(float *)&v110[4 * (unsigned __int16)v38];
      v47 = *(float *)&v42[v44] + *(float *)&v42[(unsigned __int16)v38];
      v48 = v109[v44] + v109[(unsigned __int16)v38];
      v49 = *((float *)&v94 + (unsigned __int16)v38) - *((float *)&v94 + v44);
      v50 = (float)(v48 * v46) - (float)(v49 * v45);
      v16 = (float)(v49 * v47) - (float)(v48 * v45);
      v15 = v50;
      v17 = (float)(v46 * v47) - (float)(v45 * v45);
      v51 = (float)(v41 * v16) + v50;
      v37 = a4;
      v113 = v50;
      v14 = 0.0;
      v52 = v51 / v17;
      if ( v52 < 0.0 )
        v52 = 0.0;
      n1124859904_1 = n1124859904;
      v53 = v106;
      ++v40;
      v41 = v41 + 1.0;
      *(float *)(v43 + a4) = v52 - n1124859904;
      v43 = 4 * v40;
      v38 = v53[v40];
      v39 = v38 >> 16;
    }
    while ( v38 >> 16 < 0 );
    v6 = v108;
    v8 = v112;
  }
  v54 = v106[v40];
  result = (unsigned __int16)v54;
  for ( i = v54 >> 16; result < v6; i = v66 >> 16 )
  {
    v57 = v111[result] - v111[i];
    v58 = *(float *)&v8[result] - *(float *)&v8[i];
    v59 = *(float *)&v110[4 * result] - *(float *)&v110[4 * i];
    v60 = v109[result] - v109[i];
    v61 = *((float *)&v94 + result) - *((float *)&v94 + i);
    v62 = (float)(v60 * v59) - (float)(v61 * v57);
    v16 = (float)(v61 * v58) - (float)(v60 * v57);
    v15 = v62;
    v17 = (float)(v59 * v58) - (float)(v57 * v57);
    v63 = (float)(v41 * v16) + v62;
    v6 = v108;
    v113 = v62;
    v14 = 0.0;
    v64 = v63 / v17;
    if ( v64 < 0.0 )
      v64 = 0.0;
    n1124859904_1 = n1124859904;
    v65 = v106;
    ++v40;
    v41 = v41 + 1.0;
    *(float *)(v37 + 4 * v40 - 4) = v64 - n1124859904;
    v66 = v65[v40];
    result = (unsigned __int16)v66;
  }
  for ( ; v40 < v6; *(float *)(v37 + 4 * v40 - 4) = v67 - n1124859904_1 )
  {
    v67 = (float)((float)(v41 * v16) + v15) / v17;
    if ( v67 < 0.0 )
      v67 = 0.0;
    ++v40;
    v41 = v41 + 1.0;
  }
  v68 = a6;
  if ( a6 > 0 )
  {
    result = a6 / 2;
    v69 = 0;
    v97 = a6 / 2;
    if ( a6 / 2 - a6 >= 0 )
    {
      v80 = v113;
    }
    else
    {
      LODWORD(v96) = 4 * result;
      v70 = a6 - result;
      v114 = result - a6;
      v71 = 4 * result;
      v72 = 4 * result;
      v73 = -4 * (a6 / 2 - a6);
      v74 = 4 * v70;
      do
      {
        v75 = *(float *)((char *)v112 + v73) + *(float *)((char *)v112 + v72);
        v76 = *(float *)((char *)v111 + v72) - *(float *)((char *)v111 + v73);
        v77 = *(float *)&v110[v73] + *(float *)&v110[v72];
        v78 = *(float *)((char *)v109 + v73) + *(float *)((char *)v109 + v72);
        v79 = *(float *)((char *)&v94 + v72) - *(float *)((char *)&v94 + v73);
        v16 = (float)(v79 * v75) - (float)(v78 * v76);
        v80 = (float)(v78 * v77) - (float)(v79 * v76);
        v81 = v77 * v75;
        n1124859904_1 = n1124859904;
        v17 = v81 - (float)(v76 * v76);
        v37 = a4;
        v82 = (float)((float)((float)(v14 * v16) + v80) / v17) - n1124859904;
        if ( *(float *)(a4 + 4 * v69) > v82 )
          *(float *)(a4 + 4 * v69) = v82;
        v74 -= 4;
        v71 += 4;
        ++v69;
        v83 = (++v114 & 0x80000000) != 0;
        v14 = v14 + 1.0;
        v72 = v71;
        v73 = v74;
      }
      while ( v83 );
      result = v97;
      v6 = v108;
      v68 = a6;
    }
    v84 = result + v69;
    if ( result + v69 < v6 )
    {
      v102 = 4 * v84;
      v85 = 4 * (result + v69 - v68);
      v115 = 4 * v84;
      result = 4 * (v69 + result - a6);
      do
      {
        v86 = *(float *)((char *)v112 + v102) - *(float *)((char *)v112 + v85);
        v87 = *(float *)((char *)v111 + v102) - *(float *)((char *)v111 + v85);
        v88 = *(float *)&v110[v102] - *(float *)&v110[v85];
        v89 = *(float *)((char *)v109 + v102) - *(float *)((char *)v109 + v85);
        v90 = *(float *)((char *)&v94 + v102) - *(float *)((char *)&v94 + v85);
        v16 = (float)(v90 * v86) - (float)(v89 * v87);
        v80 = (float)(v89 * v88) - (float)(v90 * v87);
        v91 = v88 * v86;
        n1124859904_1 = n1124859904;
        v17 = v91 - (float)(v87 * v87);
        v37 = a4;
        v6 = v108;
        v92 = (float)((float)((float)(v14 * v16) + v80) / v17) - n1124859904;
        if ( *(float *)(a4 + 4 * v69) > v92 )
          *(float *)(a4 + 4 * v69) = v92;
        result += 4;
        ++v84;
        ++v69;
        v115 += 4;
        v102 = v115;
        v14 = v14 + 1.0;
        v85 = result;
      }
      while ( v84 < v6 );
    }
    for ( ; v69 < v6; v14 = v14 + 1.0 )
    {
      v93 = (float)((float)((float)(v14 * v16) + v80) / v17) - n1124859904_1;
      if ( *(float *)(v37 + 4 * v69) > v93 )
        *(float *)(v37 + 4 * v69) = v93;
      ++v69;
    }
  }
  return result;
}

