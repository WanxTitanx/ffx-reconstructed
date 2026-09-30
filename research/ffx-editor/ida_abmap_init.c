// FFX Abmap: Init and enter menu
// ABMAP menu init and enter (5KB). Initializes Sphere Grid menu, loads ABMAP resources, sets up camera, populates node data from save block (m_sphereGridRuntime @ 0x21EC in FFX_SaveRamBlock).
int *__thiscall FFX_Abmap_InitAndEnterMenu(int this)
{
  int CurrentId; // eax
  int n7; // esi
  double v4; // st7
  double v5; // st6
  unsigned int lpamng; // edx
  double v7; // st5
  int v8; // edi
  int n560; // esi
  double v10; // rt0
  double v11; // rt1
  double v12; // st5
  double v13; // st7
  int v14; // eax
  unsigned int lpamng_1; // esi
  int v16; // eax
  _DWORD *lpamng_2; // ecx
  int lpamng_3; // eax
  char SaveFlagBit3; // al
  int v20; // eax
  int lpamng_4; // edi
  __int16 n64; // dx
  int n64_17; // eax
  __int16 v24; // dx
  int v25; // esi
  char v26; // al
  int v27; // eax
  int lpamng_5; // edi
  __int16 n64_1; // dx
  int n64_18; // eax
  __int16 v31; // dx
  int v32; // esi
  int lpamng_6; // eax
  char v34; // al
  int v35; // eax
  int lpamng_7; // edi
  __int16 n64_2; // dx
  int n64_19; // eax
  __int16 v39; // dx
  int v40; // esi
  char v41; // al
  int v42; // eax
  int lpamng_8; // edi
  __int16 n64_3; // dx
  int n64_20; // eax
  __int16 v46; // dx
  int v47; // esi
  char v48; // al
  int v49; // eax
  int lpamng_9; // edi
  __int16 n64_4; // dx
  int n64_21; // eax
  __int16 v53; // dx
  int v54; // esi
  char v55; // al
  int v56; // eax
  int lpamng_10; // edi
  __int16 n64_5; // dx
  int n64_22; // eax
  __int16 v60; // dx
  int v61; // esi
  char v62; // al
  int v63; // eax
  int lpamng_11; // edi
  __int16 n64_6; // dx
  int n64_23; // eax
  __int16 v67; // dx
  int v68; // esi
  char v69; // al
  int v70; // eax
  int lpamng_12; // edi
  __int16 n64_7; // dx
  int n64_24; // eax
  __int16 v74; // dx
  int v75; // esi
  char v76; // al
  int v77; // eax
  int lpamng_13; // edi
  __int16 n64_8; // dx
  int n64_25; // eax
  __int16 v81; // dx
  int v82; // esi
  char v83; // al
  int v84; // eax
  int lpamng_14; // edi
  __int16 n64_9; // dx
  int n64_26; // eax
  __int16 v88; // dx
  int v89; // esi
  char v90; // al
  int v91; // eax
  int lpamng_15; // edi
  __int16 n64_10; // dx
  int n64_27; // eax
  __int16 v95; // dx
  int v96; // esi
  char v97; // al
  int v98; // eax
  int lpamng_16; // edi
  __int16 n64_11; // dx
  int n64_28; // eax
  __int16 v102; // dx
  int v103; // esi
  char v104; // al
  int v105; // eax
  int lpamng_17; // edi
  __int16 n64_12; // dx
  int n64_29; // eax
  __int16 v109; // dx
  int v110; // esi
  int lpamng_18; // eax
  int lpamng_19; // eax
  int lpamng_20; // eax
  int lpamng_21; // eax
  char v115; // al
  int v116; // eax
  int lpamng_22; // edi
  __int16 n64_13; // dx
  int n64_30; // eax
  __int16 v120; // dx
  int v121; // esi
  char v122; // al
  int v123; // eax
  int lpamng_23; // edi
  __int16 n64_14; // dx
  int v126; // ebx
  int n64_31; // eax
  __int16 v128; // dx
  int v129; // esi
  int v130; // ecx
  char v131; // al
  int v132; // eax
  int lpamng_24; // edi
  __int16 n64_15; // dx
  int v135; // ebx
  int n64_32; // eax
  __int16 v137; // dx
  int v138; // esi
  int v139; // ecx
  char v140; // al
  int v141; // eax
  int lpamng_25; // edi
  __int16 n64_16; // dx
  int v144; // ebx
  int n64_33; // eax
  __int16 v146; // dx
  int v147; // esi
  int v148; // ecx
  int *result; // eax
  double v150; // [esp+1Ch] [ebp-8h]
  int v151; // [esp+20h] [ebp-4h]
  int v152; // [esp+20h] [ebp-4h]
  int v153; // [esp+20h] [ebp-4h]
  int v154; // [esp+20h] [ebp-4h]
  int v155; // [esp+20h] [ebp-4h]
  int v156; // [esp+20h] [ebp-4h]
  int v157; // [esp+20h] [ebp-4h]
  int v158; // [esp+20h] [ebp-4h]
  int v159; // [esp+20h] [ebp-4h]
  int v160; // [esp+20h] [ebp-4h]
  int v161; // [esp+20h] [ebp-4h]
  int v162; // [esp+20h] [ebp-4h]
  int v163; // [esp+20h] [ebp-4h]
  int v164; // [esp+20h] [ebp-4h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  IsOpen = 0; /*0xa54b46*/
  CurrentId = FFX_Locale_GetCurrentId(this); /*0xa54b50*/
  unk_1A85F74 = !CurrentId || CurrentId > 8 && CurrentId <= 11; /*0xa54b63*/
  FFX_Abmap_InitStaticMenuStateBuffers(); /*0xa54b7c*/
  FFX_Abmap_InitRenderContextForMagicHost((int)&savedregs); /*0xa54b81*/
  FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells(); /*0xa54b86*/
  FFX_BtlUI_CreateDrawBuffer_512x256(); /*0xa54b8b*/
  n7 = 0; /*0xa54b95*/
  *(_BYTE *)(lpamng + 71113) = 0; /*0xa54b97*/
  do /*0xa54be8*/
  {
    if ( FFX_Chr_GetSlotFlagBit4(n7) == 1 ) /*0xa54bac*/
    {
      *(_BYTE *)(lpamng + 71113) |= 1 << n7; /*0xa54bd6*/
      FFX_Abmap_InitNodePlacementSlot(n7, 0, 2.0, -2143272896, -2143272896, -2139062144); /*0xa54bdc*/
    }
    ++n7; /*0xa54be4*/
  }
  while ( n7 < 7 ); /*0xa54be8*/
  FFX_Abmap_ApplyMenuSnapshot(); /*0xa54bea*/
  v4 = 0.0; /*0xa54bef*/
  v5 = 1.0; /*0xa54bf1*/
  lpamng = lpamng; /*0xa54bf3*/
  v7 = 3.0; /*0xa54bf9*/
  v8 = 0; /*0xa54bff*/
  n560 = 0; /*0xa54c01*/
  while ( 1 ) /*0xa54c07*/
  {
    v11 = v7; /*0xa54c07*/
    v12 = v4; /*0xa54c07*/
    v13 = v11; /*0xa54c07*/
    if ( v12 < *(float *)(n560 + lpamng + 69828) ) /*0xa54c15*/
    {
      v14 = *(unsigned __int16 *)(n560 + lpamng + 69836); /*0xa54c1b*/
      *(float *)(n560 + lpamng + 69768) = (float)*(__int16 *)(lpamng + 40 * v14 + 2056); /*0xa54c35*/
      *(float *)(n560 + lpamng + 69772) = (float)*(__int16 *)(lpamng + 40 * v14 + 2058); /*0xa54c4a*/
      *(float *)(n560 + lpamng + 69776) = v12; /*0xa54c51*/
      *(float *)(n560 + lpamng + 69780) = v5; /*0xa54c58*/
      *(float *)(n560 + lpamng + 69828) = v13 /*0xa54c95*/
                                        + (double)(*(__int16 *)(lpamng
                                                              + 48
                                                              * *(unsigned __int16 *)(lpamng
                                                                                    + 40
                                                                                    * *(unsigned __int16 *)(n560 + lpamng + 69836)
                                                                                    + 2062)
                                                              + 63540) >> 1);
      FFX_Abmap_UpdatePlacementSlotTransform(v8); /*0xa54c9c*/
      lpamng = lpamng; /*0xa54ca3*/
      v5 = 1.0; /*0xa54ca9*/
      v12 = 0.0; /*0xa54cb4*/
      v13 = 3.0; /*0xa54cb4*/
    }
    n560 += 80; /*0xa54cb6*/
    ++v8; /*0xa54cb9*/
    if ( n560 >= 560 ) /*0xa54cc0*/
      break; /*0xa54cc0*/
    v10 = v12; /*0xa54c05*/
    v7 = v13; /*0xa54c05*/
    v4 = v10; /*0xa54c05*/
  }
  *(_BYTE *)(lpamng + 71111) = 1; /*0xa54cc6*/
  lpamng_1 = lpamng; /*0xa54ccd*/
  v16 = *(unsigned __int16 *)(lpamng + 80 * *(unsigned __int8 *)(lpamng + 71100) + 69836); /*0xa54cdf*/
  *(_WORD *)(lpamng + 70396) = v16; /*0xa54ce7*/
  *(float *)(lpamng_1 + 70328) = (float)*(__int16 *)(lpamng_1 + 40 * v16 + 2056); /*0xa54cff*/
  *(float *)(lpamng_1 + 70332) = (float)*(__int16 *)(lpamng_1 + 40 * v16 + 2058); /*0xa54d13*/
  *(float *)(lpamng_1 + 70336) = v12; /*0xa54d19*/
  *(float *)(lpamng_1 + 70340) = v5; /*0xa54d1f*/
  v150 = (double)(*(__int16 *)(lpamng + 48 * *(unsigned __int16 *)(lpamng + 40 * v16 + 2062) + 63540) >> 1); /*0xa54d4a*/
  *(_BYTE *)(lpamng_1 + 70406) = 0; /*0xa54d50*/
  *(_DWORD *)(lpamng_1 + 70360) = -2139062144; /*0xa54d57*/
  *(_DWORD *)(lpamng_1 + 70364) = -2139062144; /*0xa54d61*/
  *(float *)(lpamng_1 + 70388) = v13 + v150; /*0xa54d6b*/
  *(_DWORD *)(lpamng_1 + 70368) = -2130706433; /*0xa54d71*/
  *(float *)(lpamng_1 + 70392) = 2.0; /*0xa54d81*/
  lpamng_2 = (_DWORD *)lpamng; /*0xa54d87*/
  *(_DWORD *)(lpamng + 70408) = *(_DWORD *)(lpamng + 70328); /*0xa54d93*/
  lpamng_2[17603] = lpamng_2[17583]; /*0xa54d9f*/
  lpamng_2[17604] = lpamng_2[17584]; /*0xa54dab*/
  lpamng_2[17605] = lpamng_2[17585]; /*0xa54db7*/
  *(_DWORD *)(lpamng + 71272) = &unk_1693160; /*0xa54dc2*/
  FFX_Abmap_UpdateRuntimeLinkGeometry(); /*0xa54dcc*/
  FFX_Abmap_ClearNodeTransforms(); /*0xa54dd1*/
  FFX_Abmap_InitCharacterView(); /*0xa54dd6*/
  FFX_MagicHost_AttachPppResourceBuffer( /*0xa54df0*/
    _Jarvis_naming_goal_2026_06_17__proved_navigation_name_from_agg_4,
    MEMORY[0x2305800],
    &FFX_SphereGrid_LpAbilityMapEngineBuffer.node_type_ui[24504],
    512000);
  lpamng_3 = lpamng_0; /*0xa54df5*/
  *(_DWORD *)(lpamng_0 + 8) = 2293808; /*0xa54dfd*/
  *(_DWORD *)(lpamng_3 + 12) = 1311136; /*0xa54e04*/
  *(_DWORD *)lpamng_3 = 2293808; /*0xa54e0b*/
  *(_DWORD *)(lpamng_3 + 4) = 1311136; /*0xa54e11*/
  *(_DWORD *)(lpamng_3 + 20) = 65562; /*0xa54e18*/
  *(_DWORD *)(lpamng_3 + 16) = 65562; /*0xa54e1f*/
  *(_DWORD *)(lpamng_3 + 30) = 983040; /*0xa54e26*/
  *(_WORD *)(lpamng_3 + 34) = 257; /*0xa54e2d*/
  *(_DWORD *)(lpamng_3 + 56) = FFX_Abmap_DrawItemReqQuad; /*0xa54e33*/
  *(_DWORD *)(lpamng_3 + 60) = FFX_Abmap_DispatchPlacementSfxByTextId; /*0xa54e3a*/
  *(_DWORD *)(lpamng_3 + 24) = 0; /*0xa54e43*/
  *(_WORD *)(lpamng_3 + 37) = 0; /*0xa54e46*/
  *(_BYTE *)(lpamng_3 + 36) = 0; /*0xa54e4a*/
  *(_BYTE *)(lpamng_3 + 40) = 0; /*0xa54e4d*/
  *(_DWORD *)(lpamng_3 + 52) = 0; /*0xa54e50*/
  *(_DWORD *)(lpamng_3 + 5832) = &unk_CD0030; /*0xa54e53*/
  *(_DWORD *)(lpamng_3 + 5836) = 2621520; /*0xa54e5d*/
  *(_DWORD *)(lpamng_3 + 5824) = &unk_CD0030; /*0xa54e67*/
  *(_DWORD *)(lpamng_3 + 5828) = 2621520; /*0xa54e71*/
  *(_DWORD *)(lpamng_3 + 5844) = 131077; /*0xa54e7b*/
  *(_DWORD *)(lpamng_3 + 5840) = 131077; /*0xa54e85*/
  *(_WORD *)(lpamng_3 + 5858) = 1; /*0xa54e8f*/
  *(_DWORD *)(lpamng_3 + 5880) = FFX_Abmap_DrawItemReqQuad; /*0xa54e98*/
  *(_DWORD *)(lpamng_3 + 5884) = FFX_Abmap_DispatchPlacementSfxByTextId; /*0xa54ea2*/
  if ( unk_1A85F74 ) /*0xa54eb2*/
    *(_DWORD *)(lpamng_3 + 5854) = 1179648; /*0xa54eb4*/
  else
    *(_DWORD *)(lpamng_3 + 5854) = 655360; /*0xa54ec0*/
  *(_DWORD *)(lpamng_3 + 5876) = 0; /*0xa54ecc*/
  *(_BYTE *)(lpamng_3 + 5864) = 0; /*0xa54ed2*/
  *(_BYTE *)(lpamng_3 + 5860) = 0; /*0xa54ed8*/
  *(_WORD *)(lpamng_3 + 5861) = 0; /*0xa54ede*/
  *(_DWORD *)(lpamng_3 + 5848) = 0; /*0xa54ee5*/
  SaveFlagBit3 = FFX_GetSaveFlagBit3(); /*0xa54eeb*/
  v20 = FFX_Text_LookupStringById(9, 31, SaveFlagBit3 & 1); /*0xa54ef8*/
  lpamng_4 = lpamng_0; /*0xa54efd*/
  n64 = *(_WORD *)(lpamng_0 + 5854); /*0xa54f06*/
  v151 = v20; /*0xa54f0d*/
  if ( n64 < 64 ) /*0xa54f14*/
  {
    n64_17 = n64; /*0xa54f35*/
    v24 = n64 + 1; /*0xa54f38*/
    v25 = 3 * n64_17; /*0xa54f39*/
    *(_BYTE *)(lpamng_0 + 5864) = v24 > *(__int16 *)(lpamng_0 + 5846) * *(unsigned __int8 *)(lpamng_0 + 5858); /*0xa54f4e*/
    *(_WORD *)(lpamng_4 + 5854) = v24; /*0xa54f57*/
    *(_DWORD *)(lpamng_4 + 4 * v25 + 5888) = v151; /*0xa54f5e*/
    *(_DWORD *)(lpamng_4 + 4 * v25 + 5896) = 31; /*0xa54f65*/
    *(_BYTE *)(lpamng_4 + 4 * v25 + 5892) = 0; /*0xa54f70*/
  }
  else
  {
    dbgPrintf(); /*0xa54f1d*/
    debug_exit_trace(); /*0xa54f24*/
  }
  v26 = FFX_GetSaveFlagBit3(); /*0xa54f78*/
  v27 = FFX_Text_LookupStringById(9, 30, v26 & 1); /*0xa54f85*/
  lpamng_5 = lpamng_0; /*0xa54f8a*/
  n64_1 = *(_WORD *)(lpamng_0 + 5854); /*0xa54f93*/
  v152 = v27; /*0xa54f9a*/
  if ( n64_1 < 64 ) /*0xa54fa1*/
  {
    n64_18 = n64_1; /*0xa54fc8*/
    v31 = n64_1 + 1; /*0xa54fcb*/
    v32 = 3 * n64_18; /*0xa54fcc*/
    *(_BYTE *)(lpamng_0 + 5864) = v31 > *(__int16 *)(lpamng_0 + 5846) * *(unsigned __int8 *)(lpamng_0 + 5858); /*0xa54fe1*/
    *(_WORD *)(lpamng_5 + 5854) = v31; /*0xa54fea*/
    *(_DWORD *)(lpamng_5 + 4 * v32 + 5888) = v152; /*0xa54ff1*/
    *(_DWORD *)(lpamng_5 + 4 * v32 + 5896) = 30; /*0xa54ff8*/
    *(_BYTE *)(lpamng_5 + 4 * v32 + 5892) = 0; /*0xa55003*/
  }
  else
  {
    dbgPrintf(); /*0xa54faa*/
    debug_exit_trace(); /*0xa54fb1*/
    lpamng_5 = lpamng_0; /*0xa54fb6*/
  }
  *(_DWORD *)(lpamng_5 + 6664) = &unk_CD0030; /*0xa5500d*/
  *(_DWORD *)(lpamng_5 + 6656) = &unk_CD0030; /*0xa55017*/
  *(_DWORD *)(lpamng_5 + 6686) = 0x80000; /*0xa55021*/
  *(_WORD *)(lpamng_5 + 6690) = 1; /*0xa5502b*/
  *(_DWORD *)(lpamng_5 + 6712) = FFX_Abmap_DrawNodeItemRequirementPanel; /*0xa55034*/
  *(_DWORD *)(lpamng_5 + 6716) = FFX_Abmap_DispatchPlacementSfxByCmdTable; /*0xa5503e*/
  *(_DWORD *)(lpamng_5 + 6680) = 0; /*0xa55048*/
  *(_WORD *)(lpamng_5 + 6693) = 0; /*0xa5504e*/
  *(_BYTE *)(lpamng_5 + 6692) = 0; /*0xa55055*/
  *(_BYTE *)(lpamng_5 + 6696) = 0; /*0xa5505b*/
  *(_DWORD *)(lpamng_5 + 6708) = 0; /*0xa55061*/
  if ( unk_1A85F74 ) /*0xa5506d*/
  {
    *(_DWORD *)(lpamng_5 + 6668) = 5243024; /*0xa5506f*/
    *(_DWORD *)(lpamng_5 + 6660) = 5243024; /*0xa55079*/
    *(_DWORD *)(lpamng_5 + 6676) = 262153; /*0xa55083*/
    *(_DWORD *)(lpamng_5 + 6672) = 262153; /*0xa5508d*/
  }
  else
  {
    *(_DWORD *)(lpamng_5 + 6668) = 5243056; /*0xa55099*/
    *(_DWORD *)(lpamng_5 + 6660) = 5243056; /*0xa550a3*/
    *(_DWORD *)(lpamng_5 + 6676) = 262155; /*0xa550ad*/
    *(_DWORD *)(lpamng_5 + 6672) = 262155; /*0xa550b7*/
  }
  *(_WORD *)(lpamng_5 + 6686) = 0; /*0xa550c7*/
  FFX_Abmap_PopulateOwnedItemMenuPrims(8, 3); /*0xa550ce*/
  lpamng_6 = lpamng_0; /*0xa550d3*/
  *(_DWORD *)(lpamng_0 + 5000) = &unk_1640030; /*0xa550dd*/
  *(_DWORD *)(lpamng_6 + 4992) = &unk_1640030; /*0xa550e7*/
  *(_DWORD *)(lpamng_6 + 5022) = 1310720; /*0xa550f1*/
  *(_WORD *)(lpamng_6 + 5026) = 1; /*0xa550fb*/
  *(_DWORD *)(lpamng_6 + 5048) = FFX_SphereGrid_DrawStatNumber_WithType7; /*0xa55104*/
  *(_DWORD *)(lpamng_6 + 5016) = 0; /*0xa5510e*/
  *(_WORD *)(lpamng_6 + 5029) = 0; /*0xa55114*/
  *(_BYTE *)(lpamng_6 + 5028) = 0; /*0xa5511b*/
  *(_BYTE *)(lpamng_6 + 5032) = 0; /*0xa55121*/
  *(_DWORD *)(lpamng_6 + 5052) = 0; /*0xa55127*/
  *(_DWORD *)(lpamng_6 + 5044) = 0; /*0xa5512d*/
  if ( unk_1A85F74 ) /*0xa55139*/
  {
    *(_DWORD *)(lpamng_6 + 5004) = 1310848; /*0xa5513b*/
    *(_DWORD *)(lpamng_6 + 4996) = 1310848; /*0xa55145*/
    *(_DWORD *)(lpamng_6 + 5012) = 65544; /*0xa5514f*/
    *(_DWORD *)(lpamng_6 + 5008) = 65544; /*0xa55159*/
  }
  else
  {
    *(_DWORD *)(lpamng_6 + 5004) = 1310896; /*0xa55165*/
    *(_DWORD *)(lpamng_6 + 4996) = 1310896; /*0xa5516f*/
    *(_DWORD *)(lpamng_6 + 5012) = 65547; /*0xa55179*/
    *(_DWORD *)(lpamng_6 + 5008) = 65547; /*0xa55183*/
  }
  v34 = FFX_GetSaveFlagBit3(); /*0xa5518d*/
  v35 = FFX_Text_LookupStringById(9, 35, v34 & 1); /*0xa5519a*/
  lpamng_7 = lpamng_0; /*0xa5519f*/
  n64_2 = *(_WORD *)(lpamng_0 + 5022); /*0xa551a8*/
  v153 = v35; /*0xa551af*/
  if ( n64_2 < 64 ) /*0xa551b6*/
  {
    n64_19 = n64_2; /*0xa551dd*/
    v39 = n64_2 + 1; /*0xa551e0*/
    v40 = 3 * n64_19; /*0xa551e1*/
    *(_BYTE *)(lpamng_0 + 5032) = v39 > *(__int16 *)(lpamng_0 + 5014) * *(unsigned __int8 *)(lpamng_0 + 5026); /*0xa551f6*/
    *(_WORD *)(lpamng_7 + 5022) = v39; /*0xa551ff*/
    *(_DWORD *)(lpamng_7 + 4 * v40 + 5056) = v153; /*0xa55206*/
    *(_DWORD *)(lpamng_7 + 4 * v40 + 5064) = 35; /*0xa5520d*/
    *(_BYTE *)(lpamng_7 + 4 * v40 + 5060) = 0; /*0xa55218*/
  }
  else
  {
    dbgPrintf(); /*0xa551bf*/
    debug_exit_trace(); /*0xa551c6*/
    lpamng_7 = lpamng_0; /*0xa551cb*/
  }
  *(_DWORD *)(lpamng_7 + 862) = 0x200000; /*0xa55222*/
  *(_WORD *)(lpamng_7 + 866) = 2; /*0xa5522c*/
  *(_DWORD *)(lpamng_7 + 888) = FFX_SphereGrid_DrawStatNumber; /*0xa55235*/
  *(_DWORD *)(lpamng_7 + 856) = 0; /*0xa5523f*/
  *(_WORD *)(lpamng_7 + 869) = 0; /*0xa55245*/
  *(_BYTE *)(lpamng_7 + 868) = 0; /*0xa5524c*/
  *(_BYTE *)(lpamng_7 + 872) = 0; /*0xa55252*/
  *(_DWORD *)(lpamng_7 + 892) = 0; /*0xa55258*/
  *(_DWORD *)(lpamng_7 + 884) = 0; /*0xa5525e*/
  if ( unk_1A85F74 ) /*0xa5526a*/
  {
    *(_DWORD *)(lpamng_7 + 840) = &unk_11400A0; /*0xa5526c*/
    *(_DWORD *)(lpamng_7 + 844) = &loc_6400C0; /*0xa55276*/
    *(_DWORD *)(lpamng_7 + 832) = &unk_11400A0; /*0xa55280*/
    *(_DWORD *)(lpamng_7 + 836) = &loc_6400C0; /*0xa5528a*/
    *(_DWORD *)(lpamng_7 + 852) = 327692; /*0xa55294*/
    *(_DWORD *)(lpamng_7 + 848) = 327692; /*0xa5529e*/
  }
  else
  {
    *(_DWORD *)(lpamng_7 + 840) = &unk_1140088; /*0xa552aa*/
    *(_DWORD *)(lpamng_7 + 844) = 6553840; /*0xa552b4*/
    *(_DWORD *)(lpamng_7 + 832) = &unk_1140088; /*0xa552be*/
    *(_DWORD *)(lpamng_7 + 836) = 6553840; /*0xa552c8*/
    *(_DWORD *)(lpamng_7 + 852) = 327695; /*0xa552d2*/
    *(_DWORD *)(lpamng_7 + 848) = 327695; /*0xa552dc*/
  }
  v41 = FFX_GetSaveFlagBit3(); /*0xa552e6*/
  v42 = FFX_Text_LookupStringById(11, 0, v41 & 1); /*0xa552f3*/
  lpamng_8 = lpamng_0; /*0xa552f8*/
  n64_3 = *(_WORD *)(lpamng_0 + 862); /*0xa55301*/
  v154 = v42; /*0xa55308*/
  if ( n64_3 < 64 ) /*0xa5530f*/
  {
    n64_20 = n64_3; /*0xa55330*/
    v46 = n64_3 + 1; /*0xa55333*/
    v47 = 3 * n64_20; /*0xa55334*/
    *(_BYTE *)(lpamng_0 + 872) = v46 > *(__int16 *)(lpamng_0 + 854) * *(unsigned __int8 *)(lpamng_0 + 866); /*0xa55349*/
    *(_WORD *)(lpamng_8 + 862) = v46; /*0xa55352*/
    *(_DWORD *)(lpamng_8 + 4 * v47 + 896) = v154; /*0xa55359*/
    *(_DWORD *)(lpamng_8 + 4 * v47 + 904) = 0; /*0xa55360*/
    *(_BYTE *)(lpamng_8 + 4 * v47 + 900) = 0; /*0xa5536b*/
  }
  else
  {
    dbgPrintf(); /*0xa55318*/
    debug_exit_trace(); /*0xa5531f*/
  }
  v48 = FFX_GetSaveFlagBit3(); /*0xa55373*/
  v49 = FFX_Text_LookupStringById(11, 1, v48 & 1); /*0xa55380*/
  lpamng_9 = lpamng_0; /*0xa55385*/
  n64_4 = *(_WORD *)(lpamng_0 + 862); /*0xa5538e*/
  v155 = v49; /*0xa55395*/
  if ( n64_4 < 64 ) /*0xa5539c*/
  {
    n64_21 = n64_4; /*0xa553bd*/
    v53 = n64_4 + 1; /*0xa553c0*/
    v54 = 3 * n64_21; /*0xa553c1*/
    *(_BYTE *)(lpamng_0 + 872) = v53 > *(__int16 *)(lpamng_0 + 854) * *(unsigned __int8 *)(lpamng_0 + 866); /*0xa553d6*/
    *(_WORD *)(lpamng_9 + 862) = v53; /*0xa553df*/
    *(_DWORD *)(lpamng_9 + 4 * v54 + 896) = v155; /*0xa553e6*/
    *(_DWORD *)(lpamng_9 + 4 * v54 + 904) = 1; /*0xa553ed*/
    *(_BYTE *)(lpamng_9 + 4 * v54 + 900) = 0; /*0xa553f8*/
  }
  else
  {
    dbgPrintf(); /*0xa553a5*/
    debug_exit_trace(); /*0xa553ac*/
  }
  v55 = FFX_GetSaveFlagBit3(); /*0xa55400*/
  v56 = FFX_Text_LookupStringById(11, 7, v55 & 1); /*0xa5540d*/
  lpamng_10 = lpamng_0; /*0xa55412*/
  n64_5 = *(_WORD *)(lpamng_0 + 862); /*0xa5541b*/
  v156 = v56; /*0xa55422*/
  if ( n64_5 < 64 ) /*0xa55429*/
  {
    n64_22 = n64_5; /*0xa5544a*/
    v60 = n64_5 + 1; /*0xa5544d*/
    v61 = 3 * n64_22; /*0xa5544e*/
    *(_BYTE *)(lpamng_0 + 872) = v60 > *(__int16 *)(lpamng_0 + 854) * *(unsigned __int8 *)(lpamng_0 + 866); /*0xa55463*/
    *(_WORD *)(lpamng_10 + 862) = v60; /*0xa5546c*/
    *(_DWORD *)(lpamng_10 + 4 * v61 + 896) = v156; /*0xa55473*/
    *(_DWORD *)(lpamng_10 + 4 * v61 + 904) = 2; /*0xa5547a*/
    *(_BYTE *)(lpamng_10 + 4 * v61 + 900) = 0; /*0xa55485*/
  }
  else
  {
    dbgPrintf(); /*0xa55432*/
    debug_exit_trace(); /*0xa55439*/
  }
  v62 = FFX_GetSaveFlagBit3(); /*0xa5548d*/
  v63 = FFX_Text_LookupStringById(11, 11, v62 & 1); /*0xa5549a*/
  lpamng_11 = lpamng_0; /*0xa5549f*/
  n64_6 = *(_WORD *)(lpamng_0 + 862); /*0xa554a8*/
  v157 = v63; /*0xa554af*/
  if ( n64_6 < 64 ) /*0xa554b6*/
  {
    n64_23 = n64_6; /*0xa554d7*/
    v67 = n64_6 + 1; /*0xa554da*/
    v68 = 3 * n64_23; /*0xa554db*/
    *(_BYTE *)(lpamng_0 + 872) = v67 > *(__int16 *)(lpamng_0 + 854) * *(unsigned __int8 *)(lpamng_0 + 866); /*0xa554f0*/
    *(_WORD *)(lpamng_11 + 862) = v67; /*0xa554f9*/
    *(_DWORD *)(lpamng_11 + 4 * v68 + 896) = v157; /*0xa55500*/
    *(_DWORD *)(lpamng_11 + 4 * v68 + 904) = 3; /*0xa55507*/
    *(_BYTE *)(lpamng_11 + 4 * v68 + 900) = 0; /*0xa55512*/
  }
  else
  {
    dbgPrintf(); /*0xa554bf*/
    debug_exit_trace(); /*0xa554c6*/
  }
  v69 = FFX_GetSaveFlagBit3(); /*0xa5551a*/
  v70 = FFX_Text_LookupStringById(11, 8, v69 & 1); /*0xa55527*/
  lpamng_12 = lpamng_0; /*0xa5552c*/
  n64_7 = *(_WORD *)(lpamng_0 + 862); /*0xa55535*/
  v158 = v70; /*0xa5553c*/
  if ( n64_7 < 64 ) /*0xa55543*/
  {
    n64_24 = n64_7; /*0xa55564*/
    v74 = n64_7 + 1; /*0xa55567*/
    v75 = 3 * n64_24; /*0xa55568*/
    *(_BYTE *)(lpamng_0 + 872) = v74 > *(__int16 *)(lpamng_0 + 854) * *(unsigned __int8 *)(lpamng_0 + 866); /*0xa5557d*/
    *(_WORD *)(lpamng_12 + 862) = v74; /*0xa55586*/
    *(_DWORD *)(lpamng_12 + 4 * v75 + 896) = v158; /*0xa5558d*/
    *(_DWORD *)(lpamng_12 + 4 * v75 + 904) = 4; /*0xa55594*/
    *(_BYTE *)(lpamng_12 + 4 * v75 + 900) = 0; /*0xa5559f*/
  }
  else
  {
    dbgPrintf(); /*0xa5554c*/
    debug_exit_trace(); /*0xa55553*/
  }
  v76 = FFX_GetSaveFlagBit3(); /*0xa555a7*/
  v77 = FFX_Text_LookupStringById(11, 12, v76 & 1); /*0xa555b4*/
  lpamng_13 = lpamng_0; /*0xa555b9*/
  n64_8 = *(_WORD *)(lpamng_0 + 862); /*0xa555c2*/
  v159 = v77; /*0xa555c9*/
  if ( n64_8 < 64 ) /*0xa555d0*/
  {
    n64_25 = n64_8; /*0xa555f1*/
    v81 = n64_8 + 1; /*0xa555f4*/
    v82 = 3 * n64_25; /*0xa555f5*/
    *(_BYTE *)(lpamng_0 + 872) = v81 > *(__int16 *)(lpamng_0 + 854) * *(unsigned __int8 *)(lpamng_0 + 866); /*0xa5560a*/
    *(_WORD *)(lpamng_13 + 862) = v81; /*0xa55613*/
    *(_DWORD *)(lpamng_13 + 4 * v82 + 896) = v159; /*0xa5561a*/
    *(_DWORD *)(lpamng_13 + 4 * v82 + 904) = 5; /*0xa55621*/
    *(_BYTE *)(lpamng_13 + 4 * v82 + 900) = 0; /*0xa5562c*/
  }
  else
  {
    dbgPrintf(); /*0xa555d9*/
    debug_exit_trace(); /*0xa555e0*/
  }
  v83 = FFX_GetSaveFlagBit3(); /*0xa55634*/
  v84 = FFX_Text_LookupStringById(11, 9, v83 & 1); /*0xa55641*/
  lpamng_14 = lpamng_0; /*0xa55646*/
  n64_9 = *(_WORD *)(lpamng_0 + 862); /*0xa5564f*/
  v160 = v84; /*0xa55656*/
  if ( n64_9 < 64 ) /*0xa5565d*/
  {
    n64_26 = n64_9; /*0xa5567e*/
    v88 = n64_9 + 1; /*0xa55681*/
    v89 = 3 * n64_26; /*0xa55682*/
    *(_BYTE *)(lpamng_0 + 872) = v88 > *(__int16 *)(lpamng_0 + 854) * *(unsigned __int8 *)(lpamng_0 + 866); /*0xa55697*/
    *(_WORD *)(lpamng_14 + 862) = v88; /*0xa556a0*/
    *(_DWORD *)(lpamng_14 + 4 * v89 + 896) = v160; /*0xa556a7*/
    *(_DWORD *)(lpamng_14 + 4 * v89 + 904) = 6; /*0xa556ae*/
    *(_BYTE *)(lpamng_14 + 4 * v89 + 900) = 0; /*0xa556b9*/
  }
  else
  {
    dbgPrintf(); /*0xa55666*/
    debug_exit_trace(); /*0xa5566d*/
  }
  v90 = FFX_GetSaveFlagBit3(); /*0xa556c1*/
  v91 = FFX_Text_LookupStringById(11, 13, v90 & 1); /*0xa556ce*/
  lpamng_15 = lpamng_0; /*0xa556d3*/
  n64_10 = *(_WORD *)(lpamng_0 + 862); /*0xa556dc*/
  v161 = v91; /*0xa556e3*/
  if ( n64_10 < 64 ) /*0xa556ea*/
  {
    n64_27 = n64_10; /*0xa5570b*/
    v95 = n64_10 + 1; /*0xa5570e*/
    v96 = 3 * n64_27; /*0xa5570f*/
    *(_BYTE *)(lpamng_0 + 872) = v95 > *(__int16 *)(lpamng_0 + 854) * *(unsigned __int8 *)(lpamng_0 + 866); /*0xa55724*/
    *(_WORD *)(lpamng_15 + 862) = v95; /*0xa5572d*/
    *(_DWORD *)(lpamng_15 + 4 * v96 + 896) = v161; /*0xa55734*/
    *(_DWORD *)(lpamng_15 + 4 * v96 + 904) = 7; /*0xa5573b*/
    *(_BYTE *)(lpamng_15 + 4 * v96 + 900) = 0; /*0xa55746*/
  }
  else
  {
    dbgPrintf(); /*0xa556f3*/
    debug_exit_trace(); /*0xa556fa*/
  }
  v97 = FFX_GetSaveFlagBit3(); /*0xa5574e*/
  v98 = FFX_Text_LookupStringById(11, 10, v97 & 1); /*0xa5575b*/
  lpamng_16 = lpamng_0; /*0xa55760*/
  n64_11 = *(_WORD *)(lpamng_0 + 862); /*0xa55769*/
  v162 = v98; /*0xa55770*/
  if ( n64_11 < 64 ) /*0xa55777*/
  {
    n64_28 = n64_11; /*0xa55798*/
    v102 = n64_11 + 1; /*0xa5579b*/
    v103 = 3 * n64_28; /*0xa5579c*/
    *(_BYTE *)(lpamng_0 + 872) = v102 > *(__int16 *)(lpamng_0 + 854) * *(unsigned __int8 *)(lpamng_0 + 866); /*0xa557b1*/
    *(_WORD *)(lpamng_16 + 862) = v102; /*0xa557ba*/
    *(_DWORD *)(lpamng_16 + 4 * v103 + 896) = v162; /*0xa557c1*/
    *(_DWORD *)(lpamng_16 + 4 * v103 + 904) = 8; /*0xa557c8*/
    *(_BYTE *)(lpamng_16 + 4 * v103 + 900) = 0; /*0xa557d3*/
  }
  else
  {
    dbgPrintf(); /*0xa55780*/
    debug_exit_trace(); /*0xa55787*/
  }
  v104 = FFX_GetSaveFlagBit3(); /*0xa557db*/
  v105 = FFX_Text_LookupStringById(11, 14, v104 & 1); /*0xa557e8*/
  lpamng_17 = lpamng_0; /*0xa557ed*/
  n64_12 = *(_WORD *)(lpamng_0 + 862); /*0xa557f6*/
  v163 = v105; /*0xa557fd*/
  if ( n64_12 < 64 ) /*0xa55804*/
  {
    n64_29 = n64_12; /*0xa5582b*/
    v109 = n64_12 + 1; /*0xa5582e*/
    v110 = 3 * n64_29; /*0xa5582f*/
    *(_BYTE *)(lpamng_0 + 872) = v109 > *(__int16 *)(lpamng_0 + 854) * *(unsigned __int8 *)(lpamng_0 + 866); /*0xa55844*/
    *(_WORD *)(lpamng_17 + 862) = v109; /*0xa5584d*/
    *(_DWORD *)(lpamng_17 + 4 * v110 + 896) = v163; /*0xa55854*/
    *(_DWORD *)(lpamng_17 + 4 * v110 + 904) = 9; /*0xa5585b*/
    *(_BYTE *)(lpamng_17 + 4 * v110 + 900) = 0; /*0xa55866*/
  }
  else
  {
    dbgPrintf(); /*0xa5580d*/
    debug_exit_trace(); /*0xa55814*/
    lpamng_17 = lpamng_0; /*0xa55819*/
  }
  *(_DWORD *)(lpamng_17 + 2526) = 0x200000; /*0xa55870*/
  *(_WORD *)(lpamng_17 + 2530) = 3; /*0xa5587a*/
  *(_DWORD *)(lpamng_17 + 2552) = FFX_SphereGrid_DrawStatNumber_Helper; /*0xa55883*/
  *(_DWORD *)(lpamng_17 + 2520) = 0; /*0xa5588d*/
  *(_WORD *)(lpamng_17 + 2533) = 0; /*0xa55893*/
  *(_BYTE *)(lpamng_17 + 2532) = 0; /*0xa5589a*/
  *(_BYTE *)(lpamng_17 + 2536) = 0; /*0xa558a0*/
  *(_DWORD *)(lpamng_17 + 2556) = 0; /*0xa558a6*/
  *(_DWORD *)(lpamng_17 + 2548) = 0; /*0xa558ac*/
  if ( unk_1A85F74 ) /*0xa558b8*/
  {
    *(_DWORD *)(lpamng_17 + 2504) = &unk_D8005F; /*0xa558ba*/
    *(_DWORD *)(lpamng_17 + 2508) = Phyre_PMLAA_WrapperCopy; /*0xa558c4*/
    *(_DWORD *)(lpamng_17 + 2496) = &unk_D8005F; /*0xa558ce*/
    *(_DWORD *)(lpamng_17 + 2500) = Phyre_PMLAA_WrapperCopy; /*0xa558d8*/
    *(_DWORD *)(lpamng_17 + 2516) = 524308; /*0xa558e2*/
    *(_DWORD *)(lpamng_17 + 2512) = 524308; /*0xa558ec*/
  }
  else
  {
    *(_DWORD *)(lpamng_17 + 2504) = &unk_D80048; /*0xa558f8*/
    *(_DWORD *)(lpamng_17 + 2508) = &loc_A00170; /*0xa55902*/
    *(_DWORD *)(lpamng_17 + 2496) = &unk_D80048; /*0xa5590c*/
    *(_DWORD *)(lpamng_17 + 2500) = &loc_A00170; /*0xa55916*/
    *(_DWORD *)(lpamng_17 + 2516) = 524311; /*0xa55920*/
    *(_DWORD *)(lpamng_17 + 2512) = 524311; /*0xa5592a*/
  }
  FFX_Abmap_BuildPanelPrimsFromMenuEntries(3, 64); /*0xa55938*/
  lpamng_18 = lpamng_0; /*0xa5593d*/
  *(_DWORD *)(lpamng_0 + 1694) = 0x200000; /*0xa55947*/
  *(_DWORD *)(lpamng_18 + 1720) = FFX_SphereGrid_DrawStatNumber_Helper_B; /*0xa55951*/
  *(_DWORD *)(lpamng_18 + 1688) = 0; /*0xa5595b*/
  *(_WORD *)(lpamng_18 + 1701) = 0; /*0xa55961*/
  *(_BYTE *)(lpamng_18 + 1700) = 0; /*0xa55968*/
  *(_BYTE *)(lpamng_18 + 1704) = 0; /*0xa5596e*/
  *(_DWORD *)(lpamng_18 + 1724) = 0; /*0xa55974*/
  *(_DWORD *)(lpamng_18 + 1716) = 0; /*0xa5597a*/
  if ( unk_1A85F74 ) /*0xa55986*/
  {
    *(_DWORD *)(lpamng_18 + 1672) = &unk_1000060; /*0xa55988*/
    *(_DWORD *)(lpamng_18 + 1676) = &loc_780140; /*0xa55992*/
    *(_DWORD *)(lpamng_18 + 1664) = &unk_1000060; /*0xa5599c*/
    *(_DWORD *)(lpamng_18 + 1668) = &loc_780140; /*0xa559a6*/
    *(_DWORD *)(lpamng_18 + 1684) = 393236; /*0xa559b0*/
    *(_DWORD *)(lpamng_18 + 1680) = 393236; /*0xa559ba*/
    *(_WORD *)(lpamng_18 + 1698) = 4; /*0xa559c4*/
  }
  else
  {
    *(_DWORD *)(lpamng_18 + 1672) = &unk_D80048; /*0xa559cf*/
    *(_DWORD *)(lpamng_18 + 1676) = &loc_A00170; /*0xa559d9*/
    *(_DWORD *)(lpamng_18 + 1664) = &unk_D80048; /*0xa559e3*/
    *(_DWORD *)(lpamng_18 + 1668) = &loc_A00170; /*0xa559ed*/
    *(_DWORD *)(lpamng_18 + 1684) = 524311; /*0xa559f7*/
    *(_DWORD *)(lpamng_18 + 1680) = 524311; /*0xa55a01*/
    *(_WORD *)(lpamng_18 + 1698) = 3; /*0xa55a0b*/
  }
  FFX_Abmap_BuildPanelPrimsFromMenuEntries(2, 65); /*0xa55a18*/
  lpamng_19 = lpamng_0; /*0xa55a1d*/
  *(_DWORD *)(lpamng_0 + 3358) = 0x200000; /*0xa55a27*/
  *(_WORD *)(lpamng_19 + 3362) = 4; /*0xa55a31*/
  *(_DWORD *)(lpamng_19 + 3384) = FFX_SphereGrid_DrawStatNumber_Helper; /*0xa55a3a*/
  *(_DWORD *)(lpamng_19 + 3352) = 0; /*0xa55a44*/
  *(_WORD *)(lpamng_19 + 3365) = 0; /*0xa55a4a*/
  *(_BYTE *)(lpamng_19 + 3364) = 0; /*0xa55a51*/
  *(_BYTE *)(lpamng_19 + 3368) = 0; /*0xa55a57*/
  *(_DWORD *)(lpamng_19 + 3388) = 0; /*0xa55a5d*/
  *(_DWORD *)(lpamng_19 + 3380) = 0; /*0xa55a63*/
  if ( unk_1A85F74 ) /*0xa55a6f*/
  {
    *(_DWORD *)(lpamng_19 + 3336) = &unk_1000060; /*0xa55a71*/
    *(_DWORD *)(lpamng_19 + 3340) = &loc_780140; /*0xa55a7b*/
    *(_DWORD *)(lpamng_19 + 3328) = &unk_1000060; /*0xa55a85*/
    *(_DWORD *)(lpamng_19 + 3332) = &loc_780140; /*0xa55a8f*/
    *(_DWORD *)(lpamng_19 + 3348) = 393236; /*0xa55a99*/
    *(_DWORD *)(lpamng_19 + 3344) = 393236; /*0xa55aa3*/
  }
  else
  {
    *(_DWORD *)(lpamng_19 + 3336) = &unk_1000040; /*0xa55aaf*/
    *(_DWORD *)(lpamng_19 + 3340) = &loc_780180; /*0xa55ab9*/
    *(_DWORD *)(lpamng_19 + 3328) = &unk_1000040; /*0xa55ac3*/
    *(_DWORD *)(lpamng_19 + 3332) = &loc_780180; /*0xa55acd*/
    *(_DWORD *)(lpamng_19 + 3348) = 393240; /*0xa55ad7*/
    *(_DWORD *)(lpamng_19 + 3344) = 393240; /*0xa55ae1*/
  }
  FFX_Abmap_BuildPanelPrimsFromMenuEntries(4, 69); /*0xa55aef*/
  lpamng_20 = lpamng_0; /*0xa55af4*/
  *(_DWORD *)(lpamng_0 + 4190) = 0x200000; /*0xa55afe*/
  *(_WORD *)(lpamng_20 + 4194) = 4; /*0xa55b08*/
  *(_DWORD *)(lpamng_20 + 4216) = FFX_SphereGrid_DrawStatNumber_Helper; /*0xa55b11*/
  *(_DWORD *)(lpamng_20 + 4184) = 0; /*0xa55b1b*/
  *(_WORD *)(lpamng_20 + 4197) = 0; /*0xa55b21*/
  *(_BYTE *)(lpamng_20 + 4196) = 0; /*0xa55b28*/
  *(_BYTE *)(lpamng_20 + 4200) = 0; /*0xa55b2e*/
  *(_DWORD *)(lpamng_20 + 4220) = 0; /*0xa55b34*/
  *(_DWORD *)(lpamng_20 + 4212) = 0; /*0xa55b3a*/
  if ( unk_1A85F74 ) /*0xa55b46*/
  {
    *(_DWORD *)(lpamng_20 + 4168) = &unk_1140060; /*0xa55b48*/
    *(_DWORD *)(lpamng_20 + 4172) = 6553920; /*0xa55b52*/
    *(_DWORD *)(lpamng_20 + 4160) = &unk_1140060; /*0xa55b5c*/
    *(_DWORD *)(lpamng_20 + 4164) = 6553920; /*0xa55b66*/
    *(_DWORD *)(lpamng_20 + 4180) = 327700; /*0xa55b70*/
    *(_DWORD *)(lpamng_20 + 4176) = 327700; /*0xa55b7a*/
  }
  else
  {
    *(_DWORD *)(lpamng_20 + 4168) = &unk_1140040; /*0xa55b86*/
    *(_DWORD *)(lpamng_20 + 4172) = 6553984; /*0xa55b90*/
    *(_DWORD *)(lpamng_20 + 4160) = &unk_1140040; /*0xa55b9a*/
    *(_DWORD *)(lpamng_20 + 4164) = 6553984; /*0xa55ba4*/
    *(_DWORD *)(lpamng_20 + 4180) = 327704; /*0xa55bae*/
    *(_DWORD *)(lpamng_20 + 4176) = 327704; /*0xa55bb8*/
  }
  FFX_Abmap_BuildPanelPrimsFromMenuEntries(5, 68); /*0xa55bc6*/
  lpamng_21 = lpamng_0; /*0xa55bcb*/
  *(_DWORD *)(lpamng_0 + 7496) = &unk_CD0030; /*0xa55bd5*/
  *(_DWORD *)(lpamng_21 + 7488) = &unk_CD0030; /*0xa55bdf*/
  *(_DWORD *)(lpamng_21 + 7518) = 655360; /*0xa55be9*/
  *(_WORD *)(lpamng_21 + 7522) = 1; /*0xa55bf3*/
  *(_DWORD *)(lpamng_21 + 7544) = FFX_Abmap_ButtonAnim_DrawQuad; /*0xa55bfc*/
  *(_DWORD *)(lpamng_21 + 7512) = 0; /*0xa55c06*/
  *(_WORD *)(lpamng_21 + 7525) = 0; /*0xa55c0c*/
  *(_BYTE *)(lpamng_21 + 7524) = 0; /*0xa55c13*/
  *(_BYTE *)(lpamng_21 + 7528) = 0; /*0xa55c19*/
  *(_DWORD *)(lpamng_21 + 7548) = 0; /*0xa55c1f*/
  *(_DWORD *)(lpamng_21 + 7540) = 0; /*0xa55c25*/
  if ( unk_1A85F74 ) /*0xa55c31*/
  {
    *(_DWORD *)(lpamng_21 + 7500) = 1310816; /*0xa55c33*/
    *(_DWORD *)(lpamng_21 + 7492) = 1310816; /*0xa55c3d*/
    *(_DWORD *)(lpamng_21 + 7508) = 65542; /*0xa55c47*/
    *(_DWORD *)(lpamng_21 + 7504) = 65542; /*0xa55c51*/
  }
  else
  {
    *(_DWORD *)(lpamng_21 + 7500) = 1310864; /*0xa55c5d*/
    *(_DWORD *)(lpamng_21 + 7492) = 1310864; /*0xa55c67*/
    *(_DWORD *)(lpamng_21 + 7508) = 65545; /*0xa55c71*/
    *(_DWORD *)(lpamng_21 + 7504) = 65545; /*0xa55c7b*/
  }
  v115 = FFX_GetSaveFlagBit3(); /*0xa55c85*/
  v116 = FFX_Text_LookupStringById(9, 43, v115 & 1); /*0xa55c92*/
  lpamng_22 = lpamng_0; /*0xa55c97*/
  n64_13 = *(_WORD *)(lpamng_0 + 7518); /*0xa55ca0*/
  v164 = v116; /*0xa55ca7*/
  if ( n64_13 < 64 ) /*0xa55cae*/
  {
    n64_30 = n64_13; /*0xa55cd5*/
    v120 = n64_13 + 1; /*0xa55cd8*/
    v121 = 3 * n64_30; /*0xa55cd9*/
    *(_BYTE *)(lpamng_0 + 7528) = v120 > *(__int16 *)(lpamng_0 + 7510) * *(unsigned __int8 *)(lpamng_0 + 7522); /*0xa55cee*/
    *(_WORD *)(lpamng_22 + 7518) = v120; /*0xa55cf7*/
    *(_DWORD *)(lpamng_22 + 4 * v121 + 7552) = v164; /*0xa55cfe*/
    *(_DWORD *)(lpamng_22 + 4 * v121 + 7560) = 43; /*0xa55d05*/
    *(_BYTE *)(lpamng_22 + 4 * v121 + 7556) = 0; /*0xa55d10*/
  }
  else
  {
    dbgPrintf(); /*0xa55cb7*/
    debug_exit_trace(); /*0xa55cbe*/
    lpamng_22 = lpamng_0; /*0xa55cc3*/
  }
  *(_DWORD *)(lpamng_22 + 8328) = &unk_CD0030; /*0xa55d1a*/
  *(_DWORD *)(lpamng_22 + 8320) = &unk_CD0030; /*0xa55d24*/
  *(_DWORD *)(lpamng_22 + 8350) = 655360; /*0xa55d2e*/
  *(_WORD *)(lpamng_22 + 8354) = 1; /*0xa55d38*/
  *(_DWORD *)(lpamng_22 + 8376) = FFX_Abmap_ButtonAnim_DrawQuad; /*0xa55d41*/
  *(_DWORD *)(lpamng_22 + 8344) = 0; /*0xa55d4b*/
  *(_WORD *)(lpamng_22 + 8357) = 0; /*0xa55d51*/
  *(_BYTE *)(lpamng_22 + 8356) = 0; /*0xa55d58*/
  *(_BYTE *)(lpamng_22 + 8360) = 0; /*0xa55d5e*/
  *(_DWORD *)(lpamng_22 + 8380) = 0; /*0xa55d64*/
  *(_DWORD *)(lpamng_22 + 8372) = 0; /*0xa55d6a*/
  if ( unk_1A85F74 ) /*0xa55d76*/
  {
    *(_DWORD *)(lpamng_22 + 8332) = 1310832; /*0xa55d78*/
    *(_DWORD *)(lpamng_22 + 8324) = 1310832; /*0xa55d82*/
    *(_DWORD *)(lpamng_22 + 8340) = 65543; /*0xa55d8c*/
    *(_DWORD *)(lpamng_22 + 8336) = 65543; /*0xa55d96*/
  }
  else
  {
    *(_DWORD *)(lpamng_22 + 8332) = 1310864; /*0xa55da2*/
    *(_DWORD *)(lpamng_22 + 8324) = 1310864; /*0xa55dac*/
    *(_DWORD *)(lpamng_22 + 8340) = 65545; /*0xa55db6*/
    *(_DWORD *)(lpamng_22 + 8336) = 65545; /*0xa55dc0*/
  }
  v122 = FFX_GetSaveFlagBit3(); /*0xa55dca*/
  v123 = FFX_Text_LookupStringById(9, 46, v122 & 1); /*0xa55dd7*/
  lpamng_23 = lpamng_0; /*0xa55ddc*/
  n64_14 = *(_WORD *)(lpamng_0 + 8350); /*0xa55de5*/
  v126 = v123; /*0xa55dec*/
  if ( n64_14 < 64 ) /*0xa55df2*/
  {
    n64_31 = n64_14; /*0xa55e19*/
    v128 = n64_14 + 1; /*0xa55e1c*/
    v129 = 3 * n64_31; /*0xa55e1d*/
    v130 = *(__int16 *)(lpamng_0 + 8342) * *(unsigned __int8 *)(lpamng_0 + 8354); /*0xa55e27*/
    *(_WORD *)(lpamng_0 + 8350) = v128; /*0xa55e2f*/
    *(_BYTE *)(lpamng_23 + 8360) = v128 > v130; /*0xa55e39*/
    *(_DWORD *)(lpamng_23 + 4 * v129 + 8384) = v126; /*0xa55e3f*/
    *(_DWORD *)(lpamng_23 + 4 * v129 + 8392) = 46; /*0xa55e46*/
    *(_BYTE *)(lpamng_23 + 4 * v129 + 8388) = 0; /*0xa55e51*/
  }
  else
  {
    dbgPrintf(); /*0xa55dfb*/
    debug_exit_trace(); /*0xa55e02*/
    lpamng_23 = lpamng_0; /*0xa55e07*/
  }
  *(_DWORD *)(lpamng_23 + 9160) = &unk_F50030; /*0xa55e5b*/
  *(_DWORD *)(lpamng_23 + 9164) = 2621520; /*0xa55e65*/
  *(_DWORD *)(lpamng_23 + 9152) = &unk_F50030; /*0xa55e6f*/
  *(_DWORD *)(lpamng_23 + 9156) = 2621520; /*0xa55e79*/
  *(_DWORD *)(lpamng_23 + 9172) = 131077; /*0xa55e83*/
  *(_DWORD *)(lpamng_23 + 9168) = 131077; /*0xa55e8d*/
  *(_DWORD *)(lpamng_23 + 9182) = 983040; /*0xa55e97*/
  *(_DWORD *)(lpamng_23 + 9176) = 0; /*0xa55ea1*/
  *(_WORD *)(lpamng_23 + 9186) = 1; /*0xa55ea7*/
  *(_WORD *)(lpamng_23 + 9189) = 0; /*0xa55eb0*/
  *(_BYTE *)(lpamng_23 + 9188) = 0; /*0xa55eb7*/
  *(_BYTE *)(lpamng_23 + 9192) = 0; /*0xa55ebd*/
  *(_DWORD *)(lpamng_23 + 9208) = FFX_Abmap_DrawItemReqQuad; /*0xa55ec3*/
  *(_DWORD *)(lpamng_23 + 9212) = 0; /*0xa55ecd*/
  *(_DWORD *)(lpamng_23 + 9204) = 0; /*0xa55ed3*/
  v131 = FFX_GetSaveFlagBit3(); /*0xa55ed9*/
  v132 = FFX_Text_LookupStringById(9, 44, v131 & 1); /*0xa55ee6*/
  lpamng_24 = lpamng_0; /*0xa55eeb*/
  n64_15 = *(_WORD *)(lpamng_0 + 9182); /*0xa55ef4*/
  v135 = v132; /*0xa55efb*/
  if ( n64_15 < 64 ) /*0xa55f01*/
  {
    n64_32 = n64_15; /*0xa55f22*/
    v137 = n64_15 + 1; /*0xa55f25*/
    v138 = 3 * n64_32; /*0xa55f26*/
    v139 = *(__int16 *)(lpamng_0 + 9174) * *(unsigned __int8 *)(lpamng_0 + 9186); /*0xa55f30*/
    *(_WORD *)(lpamng_0 + 9182) = v137; /*0xa55f38*/
    *(_BYTE *)(lpamng_24 + 9192) = v137 > v139; /*0xa55f42*/
    *(_DWORD *)(lpamng_24 + 4 * v138 + 9216) = v135; /*0xa55f48*/
    *(_DWORD *)(lpamng_24 + 4 * v138 + 9224) = 44; /*0xa55f4f*/
    *(_BYTE *)(lpamng_24 + 4 * v138 + 9220) = 0; /*0xa55f5a*/
  }
  else
  {
    dbgPrintf(); /*0xa55f0a*/
    debug_exit_trace(); /*0xa55f11*/
  }
  v140 = FFX_GetSaveFlagBit3(); /*0xa55f62*/
  v141 = FFX_Text_LookupStringById(9, 45, v140 & 1); /*0xa55f6f*/
  lpamng_25 = lpamng_0; /*0xa55f74*/
  n64_16 = *(_WORD *)(lpamng_0 + 9182); /*0xa55f7d*/
  v144 = v141; /*0xa55f84*/
  if ( n64_16 < 64 ) /*0xa55f8a*/
  {
    n64_33 = n64_16; /*0xa55fab*/
    v146 = n64_16 + 1; /*0xa55fae*/
    v147 = 3 * n64_33; /*0xa55faf*/
    v148 = *(__int16 *)(lpamng_0 + 9174) * *(unsigned __int8 *)(lpamng_0 + 9186); /*0xa55fb9*/
    *(_WORD *)(lpamng_0 + 9182) = v146; /*0xa55fc1*/
    *(_BYTE *)(lpamng_25 + 9192) = v146 > v148; /*0xa55fcb*/
    *(_DWORD *)(lpamng_25 + 4 * v147 + 9216) = v144; /*0xa55fd1*/
    *(_DWORD *)(lpamng_25 + 4 * v147 + 9224) = 45; /*0xa55fd8*/
    *(_BYTE *)(lpamng_25 + 4 * v147 + 9220) = 0; /*0xa55fe3*/
  }
  else
  {
    dbgPrintf(); /*0xa55f93*/
    debug_exit_trace(); /*0xa55f9a*/
  }
  FFX_Abmap_PostProfileAndLazyInitMenu(*(_DWORD *)(lpamng + 71332)); /*0xa55ff6*/
  FFX_Scene_ClearPendingTransitionFlag(); /*0xa55ffb*/
  FFX_Field_ClampInput(2u); /*0xa56002*/
  unk_1A860EC = FFX_Heap_AllocGameArenaDebugFill_wrapper(0x200u); /*0xa56016*/
  result = FFX_Heap_AllocGameArenaDebugFill_wrapper(0x200u); /*0xa5601b*/
  unk_1A860F0 = result; /*0xa56023*/
  return result; /*0xa5602b*/
}
