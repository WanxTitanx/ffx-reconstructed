// Function: sub_A54B40
// Address: 0xa54b40
// Size: 0x14ef
// Prototype: 

int __usercall sub_A54B40@<eax>(int a1@<ebx>, int a2@<edi>, int a3@<esi>)
{
  int Region; // eax
  int n7; // esi
  double v5; // st7
  double v6; // st6
  int v7; // edx
  double v8; // st5
  int v9; // edi
  int n560; // esi
  double v11; // rt0
  double v12; // rt1
  double v13; // st5
  double v14; // st7
  int v15; // eax
  int v16; // esi
  int v17; // eax
  _DWORD *v18; // ecx
  int v19; // eax
  char v20; // al
  int KernelString; // eax
  int v22; // edi
  __int16 n64; // dx
  int n64_17; // eax
  __int16 v25; // dx
  int v26; // esi
  char v27; // al
  int v28; // eax
  int v29; // edi
  __int16 n64_1; // dx
  int n64_18; // eax
  __int16 v32; // dx
  int v33; // esi
  int v34; // eax
  char v35; // al
  int v36; // eax
  int v37; // edi
  __int16 n64_2; // dx
  int n64_19; // eax
  __int16 v40; // dx
  int v41; // esi
  char v42; // al
  int v43; // eax
  int v44; // edi
  __int16 n64_3; // dx
  int n64_20; // eax
  __int16 v47; // dx
  int v48; // esi
  char v49; // al
  int v50; // eax
  int v51; // edi
  __int16 n64_4; // dx
  int n64_21; // eax
  __int16 v54; // dx
  int v55; // esi
  char v56; // al
  int v57; // eax
  int v58; // edi
  __int16 n64_5; // dx
  int n64_22; // eax
  __int16 v61; // dx
  int v62; // esi
  char v63; // al
  int v64; // eax
  int v65; // edi
  __int16 n64_6; // dx
  int n64_23; // eax
  __int16 v68; // dx
  int v69; // esi
  char v70; // al
  int v71; // eax
  int v72; // edi
  __int16 n64_7; // dx
  int n64_24; // eax
  __int16 v75; // dx
  int v76; // esi
  char v77; // al
  int v78; // eax
  int v79; // edi
  __int16 n64_8; // dx
  int n64_25; // eax
  __int16 v82; // dx
  int v83; // esi
  char v84; // al
  int v85; // eax
  int v86; // edi
  __int16 n64_9; // dx
  int n64_26; // eax
  __int16 v89; // dx
  int v90; // esi
  char v91; // al
  int v92; // eax
  int v93; // edi
  __int16 n64_10; // dx
  int n64_27; // eax
  __int16 v96; // dx
  int v97; // esi
  char v98; // al
  int v99; // eax
  int v100; // edi
  __int16 n64_11; // dx
  int n64_28; // eax
  __int16 v103; // dx
  int v104; // esi
  char v105; // al
  int v106; // eax
  int v107; // edi
  __int16 n64_12; // dx
  int n64_29; // eax
  __int16 v110; // dx
  int v111; // esi
  int v112; // eax
  int v113; // eax
  int v114; // eax
  int v115; // eax
  char v116; // al
  int v117; // eax
  int v118; // edi
  __int16 n64_13; // dx
  int n64_30; // eax
  __int16 v121; // dx
  int v122; // esi
  char v123; // al
  int v124; // eax
  int v125; // edi
  __int16 n64_14; // dx
  int v127; // ebx
  int n64_31; // eax
  __int16 v129; // dx
  int v130; // esi
  int v131; // ecx
  char v132; // al
  int v133; // eax
  int v134; // edi
  __int16 n64_15; // dx
  int v136; // ebx
  int n64_32; // eax
  __int16 v138; // dx
  int v139; // esi
  int v140; // ecx
  char v141; // al
  int v142; // eax
  int v143; // edi
  __int16 n64_16; // dx
  int v145; // ebx
  int n64_33; // eax
  __int16 v147; // dx
  int v148; // esi
  int v149; // ecx
  int result; // eax
  int v151; // [esp+Ch] [ebp-18h]
  int v152; // [esp+10h] [ebp-14h]
  int v153; // [esp+10h] [ebp-14h]
  int v154; // [esp+14h] [ebp-10h]
  double v155; // [esp+1Ch] [ebp-8h]
  int KernelString_1; // [esp+20h] [ebp-4h]
  int v157; // [esp+20h] [ebp-4h]
  int v158; // [esp+20h] [ebp-4h]
  int v159; // [esp+20h] [ebp-4h]
  int v160; // [esp+20h] [ebp-4h]
  int v161; // [esp+20h] [ebp-4h]
  int v162; // [esp+20h] [ebp-4h]
  int v163; // [esp+20h] [ebp-4h]
  int v164; // [esp+20h] [ebp-4h]
  int v165; // [esp+20h] [ebp-4h]
  int v166; // [esp+20h] [ebp-4h]
  int v167; // [esp+20h] [ebp-4h]
  int v168; // [esp+20h] [ebp-4h]
  int v169; // [esp+20h] [ebp-4h]

  unk_1A85F70 = 0;
  Region = FFX_Game_GetRegion();
  unk_1A85F74 = !Region || Region > 8 && Region <= 11;
  sub_A572E0(a2, a3, a1);
  sub_A57620(v152, v154);
  FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells();
  sub_901100();
  n7 = 0;
  *(_BYTE *)(dword_2305834[0] + 71113) = 0;
  do
  {
    if ( FFX_Party_IsMemberActive(n7) == 1 )
    {
      *(_BYTE *)(dword_2305834[0] + 71113) |= 1 << n7;
      sub_A57F80(n7, 0, 2.0, -2143272896, -2143272896, -2139062144);
    }
    ++n7;
  }
  while ( n7 < 7 );
  FFX_Abmap_ApplySphereGridStateToMenuRuntime();
  v5 = 0.0;
  v6 = 1.0;
  v7 = dword_2305834[0];
  v8 = 3.0;
  v9 = 0;
  n560 = 0;
  while ( 1 )
  {
    v12 = v8;
    v13 = v5;
    v14 = v12;
    if ( v13 < *(float *)(n560 + v7 + 69828) )
    {
      v15 = *(unsigned __int16 *)(n560 + v7 + 69836);
      *(float *)(n560 + v7 + 69768) = (float)*(__int16 *)(v7 + 40 * v15 + 2056);
      *(float *)(n560 + v7 + 69772) = (float)*(__int16 *)(v7 + 40 * v15 + 2058);
      *(float *)(n560 + v7 + 69776) = v13;
      *(float *)(n560 + v7 + 69780) = v6;
      *(float *)(n560 + v7 + 69828) = v14
                                    + (double)(*(__int16 *)(dword_2305834[0]
                                                          + 48
                                                          * *(unsigned __int16 *)(dword_2305834[0]
                                                                                + 40
                                                                                * *(unsigned __int16 *)(n560 + v7 + 69836)
                                                                                + 2062)
                                                          + 63540) >> 1);
      sub_A58080(v9);
      v7 = dword_2305834[0];
      v6 = 1.0;
      v13 = 0.0;
      v14 = 3.0;
    }
    n560 += 80;
    ++v9;
    if ( n560 >= 560 )
      break;
    v11 = v13;
    v8 = v14;
    v5 = v11;
  }
  *(_BYTE *)(v7 + 71111) = 1;
  v16 = dword_2305834[0];
  v17 = *(unsigned __int16 *)(dword_2305834[0] + 80 * *(unsigned __int8 *)(dword_2305834[0] + 71100) + 69836);
  *(_WORD *)(dword_2305834[0] + 70396) = v17;
  *(float *)(v16 + 70328) = (float)*(__int16 *)(v16 + 40 * v17 + 2056);
  *(float *)(v16 + 70332) = (float)*(__int16 *)(v16 + 40 * v17 + 2058);
  *(float *)(v16 + 70336) = v13;
  *(float *)(v16 + 70340) = v6;
  v155 = (double)(*(__int16 *)(dword_2305834[0] + 48 * *(unsigned __int16 *)(dword_2305834[0] + 40 * v17 + 2062) + 63540) >> 1);
  *(_BYTE *)(v16 + 70406) = 0;
  *(_DWORD *)(v16 + 70360) = -2139062144;
  *(_DWORD *)(v16 + 70364) = -2139062144;
  *(float *)(v16 + 70388) = v14 + v155;
  *(_DWORD *)(v16 + 70368) = -2130706433;
  *(float *)(v16 + 70392) = 2.0;
  v18 = (_DWORD *)dword_2305834[0];
  *(_DWORD *)(dword_2305834[0] + 70408) = *(_DWORD *)(dword_2305834[0] + 70328);
  v18[17603] = v18[17583];
  v18[17604] = v18[17584];
  v18[17605] = v18[17585];
  *(_DWORD *)(dword_2305834[0] + 71272) = &unk_1693160;
  FFX_Abmap_UpdateRuntimeLinkGeometry();
  sub_A57120();
  sub_A5B030();
  FFX_MagicHost_AttachPppResourceBuffer(dword_1A86034, dword_2305800, (int)dword_16C1830, 512000);
  v19 = unk_1A86108;
  *(_DWORD *)(unk_1A86108 + 8) = 2293808;
  *(_DWORD *)(v19 + 12) = 1311136;
  *(_DWORD *)v19 = 2293808;
  *(_DWORD *)(v19 + 4) = 1311136;
  *(_DWORD *)(v19 + 20) = 65562;
  *(_DWORD *)(v19 + 16) = 65562;
  *(_DWORD *)(v19 + 30) = 983040;
  *(_WORD *)(v19 + 34) = 257;
  *(_DWORD *)(v19 + 56) = sub_A4F930;
  *(_DWORD *)(v19 + 60) = sub_A570A0;
  *(_DWORD *)(v19 + 24) = 0;
  *(_WORD *)(v19 + 37) = 0;
  *(_BYTE *)(v19 + 36) = 0;
  *(_BYTE *)(v19 + 40) = 0;
  *(_DWORD *)(v19 + 52) = 0;
  *(_DWORD *)(v19 + 5832) = &unk_CD0030;
  *(_DWORD *)(v19 + 5836) = 2621520;
  *(_DWORD *)(v19 + 5824) = &unk_CD0030;
  *(_DWORD *)(v19 + 5828) = 2621520;
  *(_DWORD *)(v19 + 5844) = 131077;
  *(_DWORD *)(v19 + 5840) = 131077;
  *(_WORD *)(v19 + 5858) = 1;
  *(_DWORD *)(v19 + 5880) = sub_A4F930;
  *(_DWORD *)(v19 + 5884) = sub_A570A0;
  if ( unk_1A85F74 )
    *(_DWORD *)(v19 + 5854) = 1179648;
  else
    *(_DWORD *)(v19 + 5854) = 655360;
  *(_DWORD *)(v19 + 5876) = 0;
  *(_BYTE *)(v19 + 5864) = 0;
  *(_BYTE *)(v19 + 5860) = 0;
  *(_WORD *)(v19 + 5861) = 0;
  *(_DWORD *)(v19 + 5848) = 0;
  v20 = sub_7852B0();
  KernelString = FFX_Table_GetKernelString(9, 31, v20 & 1);
  v22 = unk_1A86108;
  n64 = *(_WORD *)(unk_1A86108 + 5854);
  KernelString_1 = KernelString;
  if ( n64 < 64 )
  {
    n64_17 = n64;
    v25 = n64 + 1;
    v26 = 3 * n64_17;
    *(_BYTE *)(unk_1A86108 + 5864) = v25 > *(__int16 *)(unk_1A86108 + 5846) * *(unsigned __int8 *)(unk_1A86108 + 5858);
    *(_WORD *)(v22 + 5854) = v25;
    *(_DWORD *)(v22 + 4 * v26 + 5888) = KernelString_1;
    *(_DWORD *)(v22 + 4 * v26 + 5896) = 31;
    *(_BYTE *)(v22 + 4 * v26 + 5892) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
  }
  v27 = sub_7852B0();
  v28 = FFX_Table_GetKernelString(9, 30, v27 & 1);
  v29 = unk_1A86108;
  n64_1 = *(_WORD *)(unk_1A86108 + 5854);
  v157 = v28;
  if ( n64_1 < 64 )
  {
    n64_18 = n64_1;
    v32 = n64_1 + 1;
    v33 = 3 * n64_18;
    *(_BYTE *)(unk_1A86108 + 5864) = v32 > *(__int16 *)(unk_1A86108 + 5846) * *(unsigned __int8 *)(unk_1A86108 + 5858);
    *(_WORD *)(v29 + 5854) = v32;
    *(_DWORD *)(v29 + 4 * v33 + 5888) = v157;
    *(_DWORD *)(v29 + 4 * v33 + 5896) = 30;
    *(_BYTE *)(v29 + 4 * v33 + 5892) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
    v29 = unk_1A86108;
  }
  *(_DWORD *)(v29 + 6664) = &unk_CD0030;
  *(_DWORD *)(v29 + 6656) = &unk_CD0030;
  *(_DWORD *)(v29 + 6686) = 0x80000;
  *(_WORD *)(v29 + 6690) = 1;
  *(_DWORD *)(v29 + 6712) = sub_A4F630;
  *(_DWORD *)(v29 + 6716) = sub_A57040;
  *(_DWORD *)(v29 + 6680) = 0;
  *(_WORD *)(v29 + 6693) = 0;
  *(_BYTE *)(v29 + 6692) = 0;
  *(_BYTE *)(v29 + 6696) = 0;
  *(_DWORD *)(v29 + 6708) = 0;
  if ( unk_1A85F74 )
  {
    *(_DWORD *)(v29 + 6668) = 5243024;
    *(_DWORD *)(v29 + 6660) = 5243024;
    *(_DWORD *)(v29 + 6676) = 262153;
    *(_DWORD *)(v29 + 6672) = 262153;
  }
  else
  {
    *(_DWORD *)(v29 + 6668) = 5243056;
    *(_DWORD *)(v29 + 6660) = 5243056;
    *(_DWORD *)(v29 + 6676) = 262155;
    *(_DWORD *)(v29 + 6672) = 262155;
  }
  *(_WORD *)(v29 + 6686) = 0;
  sub_A45FD0(8, 3);
  v34 = unk_1A86108;
  *(_DWORD *)(unk_1A86108 + 5000) = &unk_1640030;
  *(_DWORD *)(v34 + 4992) = &unk_1640030;
  *(_DWORD *)(v34 + 5022) = 1310720;
  *(_WORD *)(v34 + 5026) = 1;
  *(_DWORD *)(v34 + 5048) = sub_A4F9E0;
  *(_DWORD *)(v34 + 5016) = 0;
  *(_WORD *)(v34 + 5029) = 0;
  *(_BYTE *)(v34 + 5028) = 0;
  *(_BYTE *)(v34 + 5032) = 0;
  *(_DWORD *)(v34 + 5052) = 0;
  *(_DWORD *)(v34 + 5044) = 0;
  if ( unk_1A85F74 )
  {
    *(_DWORD *)(v34 + 5004) = 1310848;
    *(_DWORD *)(v34 + 4996) = 1310848;
    *(_DWORD *)(v34 + 5012) = 65544;
    *(_DWORD *)(v34 + 5008) = 65544;
  }
  else
  {
    *(_DWORD *)(v34 + 5004) = 1310896;
    *(_DWORD *)(v34 + 4996) = 1310896;
    *(_DWORD *)(v34 + 5012) = 65547;
    *(_DWORD *)(v34 + 5008) = 65547;
  }
  v35 = sub_7852B0();
  v36 = FFX_Table_GetKernelString(9, 35, v35 & 1);
  v37 = unk_1A86108;
  n64_2 = *(_WORD *)(unk_1A86108 + 5022);
  v158 = v36;
  if ( n64_2 < 64 )
  {
    n64_19 = n64_2;
    v40 = n64_2 + 1;
    v41 = 3 * n64_19;
    *(_BYTE *)(unk_1A86108 + 5032) = v40 > *(__int16 *)(unk_1A86108 + 5014) * *(unsigned __int8 *)(unk_1A86108 + 5026);
    *(_WORD *)(v37 + 5022) = v40;
    *(_DWORD *)(v37 + 4 * v41 + 5056) = v158;
    *(_DWORD *)(v37 + 4 * v41 + 5064) = 35;
    *(_BYTE *)(v37 + 4 * v41 + 5060) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
    v37 = unk_1A86108;
  }
  *(_DWORD *)(v37 + 862) = 0x200000;
  *(_WORD *)(v37 + 866) = 2;
  *(_DWORD *)(v37 + 888) = sub_A4FA30;
  *(_DWORD *)(v37 + 856) = 0;
  *(_WORD *)(v37 + 869) = 0;
  *(_BYTE *)(v37 + 868) = 0;
  *(_BYTE *)(v37 + 872) = 0;
  *(_DWORD *)(v37 + 892) = 0;
  *(_DWORD *)(v37 + 884) = 0;
  if ( unk_1A85F74 )
  {
    *(_DWORD *)(v37 + 840) = &unk_11400A0;
    *(_DWORD *)(v37 + 844) = &loc_6400C0;
    *(_DWORD *)(v37 + 832) = &unk_11400A0;
    *(_DWORD *)(v37 + 836) = &loc_6400C0;
    *(_DWORD *)(v37 + 852) = 327692;
    *(_DWORD *)(v37 + 848) = 327692;
  }
  else
  {
    *(_DWORD *)(v37 + 840) = &unk_1140088;
    *(_DWORD *)(v37 + 844) = 6553840;
    *(_DWORD *)(v37 + 832) = &unk_1140088;
    *(_DWORD *)(v37 + 836) = 6553840;
    *(_DWORD *)(v37 + 852) = 327695;
    *(_DWORD *)(v37 + 848) = 327695;
  }
  v42 = sub_7852B0();
  v43 = FFX_Table_GetKernelString(11, 0, v42 & 1);
  v44 = unk_1A86108;
  n64_3 = *(_WORD *)(unk_1A86108 + 862);
  v159 = v43;
  if ( n64_3 < 64 )
  {
    n64_20 = n64_3;
    v47 = n64_3 + 1;
    v48 = 3 * n64_20;
    *(_BYTE *)(unk_1A86108 + 872) = v47 > *(__int16 *)(unk_1A86108 + 854) * *(unsigned __int8 *)(unk_1A86108 + 866);
    *(_WORD *)(v44 + 862) = v47;
    *(_DWORD *)(v44 + 4 * v48 + 896) = v159;
    *(_DWORD *)(v44 + 4 * v48 + 904) = 0;
    *(_BYTE *)(v44 + 4 * v48 + 900) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
  }
  v49 = sub_7852B0();
  v50 = FFX_Table_GetKernelString(11, 1, v49 & 1);
  v51 = unk_1A86108;
  n64_4 = *(_WORD *)(unk_1A86108 + 862);
  v160 = v50;
  if ( n64_4 < 64 )
  {
    n64_21 = n64_4;
    v54 = n64_4 + 1;
    v55 = 3 * n64_21;
    *(_BYTE *)(unk_1A86108 + 872) = v54 > *(__int16 *)(unk_1A86108 + 854) * *(unsigned __int8 *)(unk_1A86108 + 866);
    *(_WORD *)(v51 + 862) = v54;
    *(_DWORD *)(v51 + 4 * v55 + 896) = v160;
    *(_DWORD *)(v51 + 4 * v55 + 904) = 1;
    *(_BYTE *)(v51 + 4 * v55 + 900) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
  }
  v56 = sub_7852B0();
  v57 = FFX_Table_GetKernelString(11, 7, v56 & 1);
  v58 = unk_1A86108;
  n64_5 = *(_WORD *)(unk_1A86108 + 862);
  v161 = v57;
  if ( n64_5 < 64 )
  {
    n64_22 = n64_5;
    v61 = n64_5 + 1;
    v62 = 3 * n64_22;
    *(_BYTE *)(unk_1A86108 + 872) = v61 > *(__int16 *)(unk_1A86108 + 854) * *(unsigned __int8 *)(unk_1A86108 + 866);
    *(_WORD *)(v58 + 862) = v61;
    *(_DWORD *)(v58 + 4 * v62 + 896) = v161;
    *(_DWORD *)(v58 + 4 * v62 + 904) = 2;
    *(_BYTE *)(v58 + 4 * v62 + 900) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
  }
  v63 = sub_7852B0();
  v64 = FFX_Table_GetKernelString(11, 11, v63 & 1);
  v65 = unk_1A86108;
  n64_6 = *(_WORD *)(unk_1A86108 + 862);
  v162 = v64;
  if ( n64_6 < 64 )
  {
    n64_23 = n64_6;
    v68 = n64_6 + 1;
    v69 = 3 * n64_23;
    *(_BYTE *)(unk_1A86108 + 872) = v68 > *(__int16 *)(unk_1A86108 + 854) * *(unsigned __int8 *)(unk_1A86108 + 866);
    *(_WORD *)(v65 + 862) = v68;
    *(_DWORD *)(v65 + 4 * v69 + 896) = v162;
    *(_DWORD *)(v65 + 4 * v69 + 904) = 3;
    *(_BYTE *)(v65 + 4 * v69 + 900) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
  }
  v70 = sub_7852B0();
  v71 = FFX_Table_GetKernelString(11, 8, v70 & 1);
  v72 = unk_1A86108;
  n64_7 = *(_WORD *)(unk_1A86108 + 862);
  v163 = v71;
  if ( n64_7 < 64 )
  {
    n64_24 = n64_7;
    v75 = n64_7 + 1;
    v76 = 3 * n64_24;
    *(_BYTE *)(unk_1A86108 + 872) = v75 > *(__int16 *)(unk_1A86108 + 854) * *(unsigned __int8 *)(unk_1A86108 + 866);
    *(_WORD *)(v72 + 862) = v75;
    *(_DWORD *)(v72 + 4 * v76 + 896) = v163;
    *(_DWORD *)(v72 + 4 * v76 + 904) = 4;
    *(_BYTE *)(v72 + 4 * v76 + 900) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
  }
  v77 = sub_7852B0();
  v78 = FFX_Table_GetKernelString(11, 12, v77 & 1);
  v79 = unk_1A86108;
  n64_8 = *(_WORD *)(unk_1A86108 + 862);
  v164 = v78;
  if ( n64_8 < 64 )
  {
    n64_25 = n64_8;
    v82 = n64_8 + 1;
    v83 = 3 * n64_25;
    *(_BYTE *)(unk_1A86108 + 872) = v82 > *(__int16 *)(unk_1A86108 + 854) * *(unsigned __int8 *)(unk_1A86108 + 866);
    *(_WORD *)(v79 + 862) = v82;
    *(_DWORD *)(v79 + 4 * v83 + 896) = v164;
    *(_DWORD *)(v79 + 4 * v83 + 904) = 5;
    *(_BYTE *)(v79 + 4 * v83 + 900) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
  }
  v84 = sub_7852B0();
  v85 = FFX_Table_GetKernelString(11, 9, v84 & 1);
  v86 = unk_1A86108;
  n64_9 = *(_WORD *)(unk_1A86108 + 862);
  v165 = v85;
  if ( n64_9 < 64 )
  {
    n64_26 = n64_9;
    v89 = n64_9 + 1;
    v90 = 3 * n64_26;
    *(_BYTE *)(unk_1A86108 + 872) = v89 > *(__int16 *)(unk_1A86108 + 854) * *(unsigned __int8 *)(unk_1A86108 + 866);
    *(_WORD *)(v86 + 862) = v89;
    *(_DWORD *)(v86 + 4 * v90 + 896) = v165;
    *(_DWORD *)(v86 + 4 * v90 + 904) = 6;
    *(_BYTE *)(v86 + 4 * v90 + 900) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
  }
  v91 = sub_7852B0();
  v92 = FFX_Table_GetKernelString(11, 13, v91 & 1);
  v93 = unk_1A86108;
  n64_10 = *(_WORD *)(unk_1A86108 + 862);
  v166 = v92;
  if ( n64_10 < 64 )
  {
    n64_27 = n64_10;
    v96 = n64_10 + 1;
    v97 = 3 * n64_27;
    *(_BYTE *)(unk_1A86108 + 872) = v96 > *(__int16 *)(unk_1A86108 + 854) * *(unsigned __int8 *)(unk_1A86108 + 866);
    *(_WORD *)(v93 + 862) = v96;
    *(_DWORD *)(v93 + 4 * v97 + 896) = v166;
    *(_DWORD *)(v93 + 4 * v97 + 904) = 7;
    *(_BYTE *)(v93 + 4 * v97 + 900) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
  }
  v98 = sub_7852B0();
  v99 = FFX_Table_GetKernelString(11, 10, v98 & 1);
  v100 = unk_1A86108;
  n64_11 = *(_WORD *)(unk_1A86108 + 862);
  v167 = v99;
  if ( n64_11 < 64 )
  {
    n64_28 = n64_11;
    v103 = n64_11 + 1;
    v104 = 3 * n64_28;
    *(_BYTE *)(unk_1A86108 + 872) = v103 > *(__int16 *)(unk_1A86108 + 854) * *(unsigned __int8 *)(unk_1A86108 + 866);
    *(_WORD *)(v100 + 862) = v103;
    *(_DWORD *)(v100 + 4 * v104 + 896) = v167;
    *(_DWORD *)(v100 + 4 * v104 + 904) = 8;
    *(_BYTE *)(v100 + 4 * v104 + 900) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
  }
  v105 = sub_7852B0();
  v106 = FFX_Table_GetKernelString(11, 14, v105 & 1);
  v107 = unk_1A86108;
  n64_12 = *(_WORD *)(unk_1A86108 + 862);
  v168 = v106;
  if ( n64_12 < 64 )
  {
    n64_29 = n64_12;
    v110 = n64_12 + 1;
    v111 = 3 * n64_29;
    *(_BYTE *)(unk_1A86108 + 872) = v110 > *(__int16 *)(unk_1A86108 + 854) * *(unsigned __int8 *)(unk_1A86108 + 866);
    *(_WORD *)(v107 + 862) = v110;
    *(_DWORD *)(v107 + 4 * v111 + 896) = v168;
    *(_DWORD *)(v107 + 4 * v111 + 904) = 9;
    *(_BYTE *)(v107 + 4 * v111 + 900) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
    v107 = unk_1A86108;
  }
  *(_DWORD *)(v107 + 2526) = 0x200000;
  *(_WORD *)(v107 + 2530) = 3;
  *(_DWORD *)(v107 + 2552) = sub_A4F250;
  *(_DWORD *)(v107 + 2520) = 0;
  *(_WORD *)(v107 + 2533) = 0;
  *(_BYTE *)(v107 + 2532) = 0;
  *(_BYTE *)(v107 + 2536) = 0;
  *(_DWORD *)(v107 + 2556) = 0;
  *(_DWORD *)(v107 + 2548) = 0;
  if ( unk_1A85F74 )
  {
    *(_DWORD *)(v107 + 2504) = &unk_D8005F;
    *(_DWORD *)(v107 + 2508) = sub_A00140;
    *(_DWORD *)(v107 + 2496) = &unk_D8005F;
    *(_DWORD *)(v107 + 2500) = sub_A00140;
    *(_DWORD *)(v107 + 2516) = 524308;
    *(_DWORD *)(v107 + 2512) = 524308;
  }
  else
  {
    *(_DWORD *)(v107 + 2504) = &unk_D80048;
    *(_DWORD *)(v107 + 2508) = &loc_A00170;
    *(_DWORD *)(v107 + 2496) = &unk_D80048;
    *(_DWORD *)(v107 + 2500) = &loc_A00170;
    *(_DWORD *)(v107 + 2516) = 524311;
    *(_DWORD *)(v107 + 2512) = 524311;
  }
  sub_A459E0(3, 64);
  v112 = unk_1A86108;
  *(_DWORD *)(unk_1A86108 + 1694) = 0x200000;
  *(_DWORD *)(v112 + 1720) = sub_A4F9A0;
  *(_DWORD *)(v112 + 1688) = 0;
  *(_WORD *)(v112 + 1701) = 0;
  *(_BYTE *)(v112 + 1700) = 0;
  *(_BYTE *)(v112 + 1704) = 0;
  *(_DWORD *)(v112 + 1724) = 0;
  *(_DWORD *)(v112 + 1716) = 0;
  if ( unk_1A85F74 )
  {
    *(_DWORD *)(v112 + 1672) = &unk_1000060;
    *(_DWORD *)(v112 + 1676) = &loc_780140;
    *(_DWORD *)(v112 + 1664) = &unk_1000060;
    *(_DWORD *)(v112 + 1668) = &loc_780140;
    *(_DWORD *)(v112 + 1684) = 393236;
    *(_DWORD *)(v112 + 1680) = 393236;
    *(_WORD *)(v112 + 1698) = 4;
  }
  else
  {
    *(_DWORD *)(v112 + 1672) = &unk_D80048;
    *(_DWORD *)(v112 + 1676) = &loc_A00170;
    *(_DWORD *)(v112 + 1664) = &unk_D80048;
    *(_DWORD *)(v112 + 1668) = &loc_A00170;
    *(_DWORD *)(v112 + 1684) = 524311;
    *(_DWORD *)(v112 + 1680) = 524311;
    *(_WORD *)(v112 + 1698) = 3;
  }
  sub_A459E0(2, 65);
  v113 = unk_1A86108;
  *(_DWORD *)(unk_1A86108 + 3358) = 0x200000;
  *(_WORD *)(v113 + 3362) = 4;
  *(_DWORD *)(v113 + 3384) = sub_A4F250;
  *(_DWORD *)(v113 + 3352) = 0;
  *(_WORD *)(v113 + 3365) = 0;
  *(_BYTE *)(v113 + 3364) = 0;
  *(_BYTE *)(v113 + 3368) = 0;
  *(_DWORD *)(v113 + 3388) = 0;
  *(_DWORD *)(v113 + 3380) = 0;
  if ( unk_1A85F74 )
  {
    *(_DWORD *)(v113 + 3336) = &unk_1000060;
    *(_DWORD *)(v113 + 3340) = &loc_780140;
    *(_DWORD *)(v113 + 3328) = &unk_1000060;
    *(_DWORD *)(v113 + 3332) = &loc_780140;
    *(_DWORD *)(v113 + 3348) = 393236;
    *(_DWORD *)(v113 + 3344) = 393236;
  }
  else
  {
    *(_DWORD *)(v113 + 3336) = &unk_1000040;
    *(_DWORD *)(v113 + 3340) = &loc_780180;
    *(_DWORD *)(v113 + 3328) = &unk_1000040;
    *(_DWORD *)(v113 + 3332) = &loc_780180;
    *(_DWORD *)(v113 + 3348) = 393240;
    *(_DWORD *)(v113 + 3344) = 393240;
  }
  sub_A459E0(4, 69);
  v114 = unk_1A86108;
  *(_DWORD *)(unk_1A86108 + 4190) = 0x200000;
  *(_WORD *)(v114 + 4194) = 4;
  *(_DWORD *)(v114 + 4216) = sub_A4F250;
  *(_DWORD *)(v114 + 4184) = 0;
  *(_WORD *)(v114 + 4197) = 0;
  *(_BYTE *)(v114 + 4196) = 0;
  *(_BYTE *)(v114 + 4200) = 0;
  *(_DWORD *)(v114 + 4220) = 0;
  *(_DWORD *)(v114 + 4212) = 0;
  if ( unk_1A85F74 )
  {
    *(_DWORD *)(v114 + 4168) = &unk_1140060;
    *(_DWORD *)(v114 + 4172) = 6553920;
    *(_DWORD *)(v114 + 4160) = &unk_1140060;
    *(_DWORD *)(v114 + 4164) = 6553920;
    *(_DWORD *)(v114 + 4180) = 327700;
    *(_DWORD *)(v114 + 4176) = 327700;
  }
  else
  {
    *(_DWORD *)(v114 + 4168) = &unk_1140040;
    *(_DWORD *)(v114 + 4172) = 6553984;
    *(_DWORD *)(v114 + 4160) = &unk_1140040;
    *(_DWORD *)(v114 + 4164) = 6553984;
    *(_DWORD *)(v114 + 4180) = 327704;
    *(_DWORD *)(v114 + 4176) = 327704;
  }
  sub_A459E0(5, 68);
  v115 = unk_1A86108;
  *(_DWORD *)(unk_1A86108 + 7496) = &unk_CD0030;
  *(_DWORD *)(v115 + 7488) = &unk_CD0030;
  *(_DWORD *)(v115 + 7518) = 655360;
  *(_WORD *)(v115 + 7522) = 1;
  *(_DWORD *)(v115 + 7544) = sub_A4FB70;
  *(_DWORD *)(v115 + 7512) = 0;
  *(_WORD *)(v115 + 7525) = 0;
  *(_BYTE *)(v115 + 7524) = 0;
  *(_BYTE *)(v115 + 7528) = 0;
  *(_DWORD *)(v115 + 7548) = 0;
  *(_DWORD *)(v115 + 7540) = 0;
  if ( unk_1A85F74 )
  {
    *(_DWORD *)(v115 + 7500) = 1310816;
    *(_DWORD *)(v115 + 7492) = 1310816;
    *(_DWORD *)(v115 + 7508) = 65542;
    *(_DWORD *)(v115 + 7504) = 65542;
  }
  else
  {
    *(_DWORD *)(v115 + 7500) = 1310864;
    *(_DWORD *)(v115 + 7492) = 1310864;
    *(_DWORD *)(v115 + 7508) = 65545;
    *(_DWORD *)(v115 + 7504) = 65545;
  }
  v116 = sub_7852B0();
  v117 = FFX_Table_GetKernelString(9, 43, v116 & 1);
  v118 = unk_1A86108;
  n64_13 = *(_WORD *)(unk_1A86108 + 7518);
  v169 = v117;
  if ( n64_13 < 64 )
  {
    n64_30 = n64_13;
    v121 = n64_13 + 1;
    v122 = 3 * n64_30;
    *(_BYTE *)(unk_1A86108 + 7528) = v121 > *(__int16 *)(unk_1A86108 + 7510) * *(unsigned __int8 *)(unk_1A86108 + 7522);
    *(_WORD *)(v118 + 7518) = v121;
    *(_DWORD *)(v118 + 4 * v122 + 7552) = v169;
    *(_DWORD *)(v118 + 4 * v122 + 7560) = 43;
    *(_BYTE *)(v118 + 4 * v122 + 7556) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
    v118 = unk_1A86108;
  }
  *(_DWORD *)(v118 + 8328) = &unk_CD0030;
  *(_DWORD *)(v118 + 8320) = &unk_CD0030;
  *(_DWORD *)(v118 + 8350) = 655360;
  *(_WORD *)(v118 + 8354) = 1;
  *(_DWORD *)(v118 + 8376) = sub_A4FB70;
  *(_DWORD *)(v118 + 8344) = 0;
  *(_WORD *)(v118 + 8357) = 0;
  *(_BYTE *)(v118 + 8356) = 0;
  *(_BYTE *)(v118 + 8360) = 0;
  *(_DWORD *)(v118 + 8380) = 0;
  *(_DWORD *)(v118 + 8372) = 0;
  if ( unk_1A85F74 )
  {
    *(_DWORD *)(v118 + 8332) = 1310832;
    *(_DWORD *)(v118 + 8324) = 1310832;
    *(_DWORD *)(v118 + 8340) = 65543;
    *(_DWORD *)(v118 + 8336) = 65543;
  }
  else
  {
    *(_DWORD *)(v118 + 8332) = 1310864;
    *(_DWORD *)(v118 + 8324) = 1310864;
    *(_DWORD *)(v118 + 8340) = 65545;
    *(_DWORD *)(v118 + 8336) = 65545;
  }
  v123 = sub_7852B0();
  v124 = FFX_Table_GetKernelString(9, 46, v123 & 1);
  v125 = unk_1A86108;
  n64_14 = *(_WORD *)(unk_1A86108 + 8350);
  v127 = v124;
  if ( n64_14 < 64 )
  {
    n64_31 = n64_14;
    v129 = n64_14 + 1;
    v130 = 3 * n64_31;
    v131 = *(__int16 *)(unk_1A86108 + 8342) * *(unsigned __int8 *)(unk_1A86108 + 8354);
    *(_WORD *)(unk_1A86108 + 8350) = v129;
    *(_BYTE *)(v125 + 8360) = v129 > v131;
    *(_DWORD *)(v125 + 4 * v130 + 8384) = v127;
    *(_DWORD *)(v125 + 4 * v130 + 8392) = 46;
    *(_BYTE *)(v125 + 4 * v130 + 8388) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
    v125 = unk_1A86108;
  }
  *(_DWORD *)(v125 + 9160) = &unk_F50030;
  *(_DWORD *)(v125 + 9164) = 2621520;
  *(_DWORD *)(v125 + 9152) = &unk_F50030;
  *(_DWORD *)(v125 + 9156) = 2621520;
  *(_DWORD *)(v125 + 9172) = 131077;
  *(_DWORD *)(v125 + 9168) = 131077;
  *(_DWORD *)(v125 + 9182) = 983040;
  *(_DWORD *)(v125 + 9176) = 0;
  *(_WORD *)(v125 + 9186) = 1;
  *(_WORD *)(v125 + 9189) = 0;
  *(_BYTE *)(v125 + 9188) = 0;
  *(_BYTE *)(v125 + 9192) = 0;
  *(_DWORD *)(v125 + 9208) = sub_A4F930;
  *(_DWORD *)(v125 + 9212) = 0;
  *(_DWORD *)(v125 + 9204) = 0;
  v132 = sub_7852B0();
  v133 = FFX_Table_GetKernelString(9, 44, v132 & 1);
  v134 = unk_1A86108;
  n64_15 = *(_WORD *)(unk_1A86108 + 9182);
  v136 = v133;
  if ( n64_15 < 64 )
  {
    n64_32 = n64_15;
    v138 = n64_15 + 1;
    v139 = 3 * n64_32;
    v140 = *(__int16 *)(unk_1A86108 + 9174) * *(unsigned __int8 *)(unk_1A86108 + 9186);
    *(_WORD *)(unk_1A86108 + 9182) = v138;
    *(_BYTE *)(v134 + 9192) = v138 > v140;
    *(_DWORD *)(v134 + 4 * v139 + 9216) = v136;
    *(_DWORD *)(v134 + 4 * v139 + 9224) = 44;
    *(_BYTE *)(v134 + 4 * v139 + 9220) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
  }
  v141 = sub_7852B0();
  v142 = FFX_Table_GetKernelString(9, 45, v141 & 1);
  v143 = unk_1A86108;
  n64_16 = *(_WORD *)(unk_1A86108 + 9182);
  v145 = v142;
  if ( n64_16 < 64 )
  {
    n64_33 = n64_16;
    v147 = n64_16 + 1;
    v148 = 3 * n64_33;
    v149 = *(__int16 *)(unk_1A86108 + 9174) * *(unsigned __int8 *)(unk_1A86108 + 9186);
    *(_WORD *)(unk_1A86108 + 9182) = v147;
    *(_BYTE *)(v143 + 9192) = v147 > v149;
    *(_DWORD *)(v143 + 4 * v148 + 9216) = v145;
    *(_DWORD *)(v143 + 4 * v148 + 9224) = 45;
    *(_BYTE *)(v143 + 4 * v148 + 9220) = 0;
  }
  else
  {
    nullsub_34();
    nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
  }
  sub_639140(*(_DWORD *)(dword_2305834[0] + 71332));
  sub_63DFF0();
  TimerSpeed_ClampSpeed(2);
  dword_1A860EC = (_DWORD *)FFX_Memory_Alloc(0x200u, v153);
  result = FFX_Memory_Alloc(0x200u, v151);
  unk_1A860F0 = result;
  return result;
}

