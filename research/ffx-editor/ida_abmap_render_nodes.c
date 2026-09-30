// FFX Abmap: Sphere grid render nodes
void __usercall FFX_Abmap_SphereGridRenderNodes(
        int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg@<ebp>)
{
  int v1; // edi
  int v2; // eax
  double v3; // st6
  double v4; // st7
  double v5; // st5
  double v6; // st4
  double v7; // st3
  int n7; // esi
  double v9; // st2
  unsigned int v10; // edi
  double v11; // rt1
  double v12; // rt0
  double v13; // st2
  double v14; // st7
  unsigned int lpamng_1; // ecx
  unsigned __int8 v16; // dl
  int v17; // [esp-154h] [ebp-160h]
  float v18; // [esp-150h] [ebp-15Ch]
  __int16 v19; // [esp-150h] [ebp-15Ch]
  unsigned int lpamng; // [esp-14Ch] [ebp-158h]
  float v21; // [esp-144h] [ebp-150h]
  int n4; // [esp-140h] [ebp-14Ch] BYREF
  _BYTE *v23; // [esp-13Ch] [ebp-148h]
  __int16 n72; // [esp-138h] [ebp-144h]
  char v25; // [esp-136h] [ebp-142h]
  int v26; // [esp-134h] [ebp-140h]
  int v27; // [esp-130h] [ebp-13Ch]
  int v28; // [esp-12Ch] [ebp-138h]
  int v29; // [esp-128h] [ebp-134h]
  int v30; // [esp-124h] [ebp-130h]
  _BYTE *v31; // [esp-120h] [ebp-12Ch]
  int v32; // [esp-11Ch] [ebp-128h]
  int v33; // [esp-118h] [ebp-124h]
  int v34; // [esp-114h] [ebp-120h]
  int v35; // [esp-108h] [ebp-114h]
  int v36; // [esp-104h] [ebp-110h]
  int v37; // [esp-100h] [ebp-10Ch]
  __int64 *p_n1006632960; // [esp-FCh] [ebp-108h]
  _BYTE v39[64]; // [esp-C8h] [ebp-D4h] BYREF
  __int64 n1006632960; // [esp-88h] [ebp-94h] BYREF
  FFX_CharacterId FFX_Render_SharedTransformContext; // [esp-80h] [ebp-8Ch]
  float v42; // [esp-7Ch] [ebp-88h]
  __int64 n1006632960_1; // [esp-78h] [ebp-84h]
  FFX_CharacterId FFX_Render_SharedTransformContext_1; // [esp-70h] [ebp-7Ch]
  float v45; // [esp-6Ch] [ebp-78h]
  __int64 n1006632960_2; // [esp-68h] [ebp-74h]
  FFX_CharacterId FFX_Render_SharedTransformContext_2; // [esp-60h] [ebp-6Ch]
  float v48; // [esp-5Ch] [ebp-68h]
  __int64 n1006632960_3; // [esp-58h] [ebp-64h]
  float v50; // [esp-50h] [ebp-5Ch]
  float v51; // [esp-4Ch] [ebp-58h]
  __int64 n1006632960_4; // [esp-48h] [ebp-54h] BYREF
  FFX_CharacterId FFX_Render_SharedTransformContext_3; // [esp-40h] [ebp-4Ch]
  float v54; // [esp-3Ch] [ebp-48h]
  __int64 n1006632960_5; // [esp-38h] [ebp-44h]
  FFX_CharacterId FFX_Render_SharedTransformContext_4; // [esp-30h] [ebp-3Ch]
  float v57; // [esp-2Ch] [ebp-38h]
  __int64 n1006632960_6; // [esp-28h] [ebp-34h]
  float v59; // [esp-20h] [ebp-2Ch]
  float v60; // [esp-1Ch] [ebp-28h]
  __int64 n1006632960_7; // [esp-18h] [ebp-24h]
  FFX_CharacterId FFX_Render_SharedTransformContext_5; // [esp-10h] [ebp-1Ch]
  float v63; // [esp-Ch] [ebp-18h]
  int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1; // [esp+0h] [ebp-Ch]
  void *v65; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; /*0xa4c8dc*/
  v65 = retaddr; /*0xa4c8e0*/
  n4 = 4; /*0xa4c904*/
  lpamng = lpamng; /*0xa4c915*/
  v29 = FFX_Abmap_Global_C86580[*(unsigned __int8 *)(lpamng + 71100)]; /*0xa4c922*/
  HIBYTE(v29) = *(char *)(lpamng + 71109) / 3; /*0xa4c949*/
  n72 = 72; /*0xa4c954*/
  v31 = v39; /*0xa4c961*/
  p_n1006632960 = &n1006632960; /*0xa4c970*/
  v50 = 4.0; /*0xa4c97b*/
  FFX_Render_SharedTransformContext = FFX_Render_SharedTransformContext; /*0xa4c986*/
  FFX_Render_SharedTransformContext_1 = FFX_Render_SharedTransformContext; /*0xa4c989*/
  FFX_Render_SharedTransformContext_2 = FFX_Render_SharedTransformContext; /*0xa4c98c*/
  FFX_Render_SharedTransformContext_3 = FFX_Render_SharedTransformContext; /*0xa4c98f*/
  FFX_Render_SharedTransformContext_4 = FFX_Render_SharedTransformContext; /*0xa4c992*/
  v59 = *(float *)&FFX_Render_SharedTransformContext; /*0xa4c995*/
  FFX_Render_SharedTransformContext_5 = FFX_Render_SharedTransformContext; /*0xa4c998*/
  v30 = 0; /*0xa4c9a4*/
  v51 = 1.0; /*0xa4c9ae*/
  v25 = 0; /*0xa4c9b1*/
  v36 = 0; /*0xa4c9b8*/
  v35 = 0; /*0xa4c9c2*/
  v23 = byte_1740830; /*0xa4c9cc*/
  v26 = 0; /*0xa4c9d6*/
  v27 = 0; /*0xa4c9e0*/
  v28 = 0; /*0xa4c9ea*/
  v37 = 0; /*0xa4c9f4*/
  v34 = 0; /*0xa4c9fe*/
  v33 = 0; /*0xa4ca08*/
  v32 = 0; /*0xa4ca12*/
  n1006632960 = n1006632960_1; /*0xa4ca1c*/
  v42 = MEMORY[0xC8F514][0]; /*0xa4ca28*/
  n1006632960_1 = n1006632960_1; /*0xa4ca2b*/
  v45 = MEMORY[0xC8F514][0]; /*0xa4ca31*/
  n1006632960_2 = n1006632960_1; /*0xa4ca34*/
  v48 = MEMORY[0xC8F514][0]; /*0xa4ca3a*/
  n1006632960_3 = n1006632960_1; /*0xa4ca3d*/
  n1006632960_4 = n1006632960_1; /*0xa4ca43*/
  v54 = MEMORY[0xC8F514][0]; /*0xa4ca49*/
  n1006632960_5 = n1006632960_1; /*0xa4ca4c*/
  v57 = MEMORY[0xC8F514][0]; /*0xa4ca52*/
  n1006632960_6 = n1006632960_1; /*0xa4ca55*/
  v60 = MEMORY[0xC8F514][0]; /*0xa4ca5b*/
  n1006632960_7 = n1006632960_1; /*0xa4ca5e*/
  v63 = MEMORY[0xC8F514][0]; /*0xa4ca64*/
  v1 = unk_23057FC; /*0xa4ca6d*/
  v18 = (*(float *)(lpamng + 71076) * 3.0 + 125.0) * 0.0007812500116415322; /*0xa4ca85*/
  v59 = v18; /*0xa4ca97*/
  *((float *)&n1006632960_5 + 1) = v18; /*0xa4caa0*/
  *(float *)&n1006632960_4 = v18; /*0xa4caa3*/
  LODWORD(n1006632960_7) = *(_DWORD *)(lpamng + 70944); /*0xa4caae*/
  v2 = *(_DWORD *)(lpamng + 70948); /*0xa4cab1*/
  *(float *)&FFX_Render_SharedTransformContext_5 = 0.0; /*0xa4cab7*/
  HIDWORD(n1006632960_7) = v2; /*0xa4caba*/
  v63 = 1.0; /*0xa4cac1*/
  FFX_Menu2D_ProjectNodeCoords_structural((int)v39, lpamng + 70624, (int)&n1006632960_4); /*0xa4cad2*/
  FFX_Menu2D_RenderCaptureNoTexture(v1, (int)&n4); /*0xa4caec*/
  v17 = (unsigned __int16)(*(_WORD *)(lpamng + 71320) << 11); /*0xa4cb17*/
  v19 = *(_WORD *)(lpamng + 80 * *(unsigned __int8 *)(lpamng + 71100) + 69836); /*0xa4cb3a*/
  n72 = 72; /*0xa4cb45*/
  v31 = v39; /*0xa4cb52*/
  p_n1006632960 = &n1006632960; /*0xa4cb61*/
  v50 = 3.0; /*0xa4cb6c*/
  v51 = 1.0; /*0xa4cb74*/
  v30 = 0; /*0xa4cb77*/
  v25 = 0; /*0xa4cb81*/
  v36 = 0; /*0xa4cb88*/
  v35 = 0; /*0xa4cb92*/
  v23 = byte_1740830; /*0xa4cb9c*/
  v26 = 0; /*0xa4cba6*/
  v27 = 0; /*0xa4cbb0*/
  v28 = 0; /*0xa4cbba*/
  v37 = 0; /*0xa4cbc4*/
  v34 = 0; /*0xa4cbce*/
  v33 = 0; /*0xa4cbd8*/
  v32 = 0; /*0xa4cbe2*/
  n1006632960 = n1006632960_1; /*0xa4cbec*/
  FFX_Render_SharedTransformContext = FFX_Render_SharedTransformContext; /*0xa4cbf8*/
  v42 = MEMORY[0xC8F514][0]; /*0xa4cbfb*/
  n1006632960_1 = n1006632960_1; /*0xa4cbfe*/
  FFX_Render_SharedTransformContext_1 = FFX_Render_SharedTransformContext; /*0xa4cc04*/
  v45 = MEMORY[0xC8F514][0]; /*0xa4cc07*/
  n1006632960_2 = n1006632960_1; /*0xa4cc0a*/
  FFX_Render_SharedTransformContext_2 = FFX_Render_SharedTransformContext; /*0xa4cc10*/
  v48 = MEMORY[0xC8F514][0]; /*0xa4cc13*/
  n1006632960_3 = n1006632960_1; /*0xa4cc16*/
  n1006632960_4 = n1006632960_1; /*0xa4cc1c*/
  *(float *)&FFX_Render_SharedTransformContext_5 = 0.0; /*0xa4cc2d*/
  v3 = 1.0; /*0xa4cc30*/
  v4 = 0.0; /*0xa4cc30*/
  v63 = 1.0; /*0xa4cc35*/
  n1006632960_5 = n1006632960_1; /*0xa4cc38*/
  v5 = 2.0; /*0xa4cc3b*/
  n1006632960_6 = n1006632960_1; /*0xa4cc41*/
  v6 = 1.0; /*0xa4cc44*/
  n1006632960_7 = n1006632960_1; /*0xa4cc46*/
  v7 = 16.0; /*0xa4cc49*/
  n7 = 0; /*0xa4cc4f*/
  v9 = 0.001249999972060323; /*0xa4cc51*/
  FFX_Render_SharedTransformContext_3 = FFX_Render_SharedTransformContext; /*0xa4cc57*/
  v54 = MEMORY[0xC8F514][0]; /*0xa4cc5a*/
  FFX_Render_SharedTransformContext_4 = FFX_Render_SharedTransformContext; /*0xa4cc60*/
  v57 = MEMORY[0xC8F514][0]; /*0xa4cc63*/
  v59 = *(float *)&FFX_Render_SharedTransformContext; /*0xa4cc69*/
  v60 = MEMORY[0xC8F514][0]; /*0xa4cc6c*/
  n4 = 36; /*0xa4cc72*/
  v10 = lpamng + 69828; /*0xa4cc7c*/
  while ( 1 ) /*0xa4cc86*/
  {
    if ( n7 == 7 ) /*0xa4cc89*/
      v50 = v5; /*0xa4cc8d*/
    v12 = v9; /*0xa4cc92*/
    v13 = v4; /*0xa4cc92*/
    v14 = v12; /*0xa4cc92*/
    if ( v13 < *(float *)v10 ) /*0xa4cc9b*/
    {
      lpamng_1 = lpamng; /*0xa4cca7*/
      if ( v19 != *(_WORD *)(v10 + 8) || n7 == *(unsigned __int8 *)(lpamng + 71100) || n7 == 7 ) /*0xa4ccc1*/
      {
        v29 = FFX_Abmap_Global_C86660[n7]; /*0xa4ccd0*/
        v16 = (int)(v7 * (v6 + eff_sin_t[((v17 + (n7 << 13)) >> 4) & 0xFFF])) + 96; /*0xa4cd1e*/
        HIBYTE(v29) = v16; /*0xa4cd21*/
        if ( v3 > *(float *)(lpamng + 71156) ) /*0xa4cd38*/
        {
          lpamng_1 = lpamng; /*0xa4cd60*/
          HIBYTE(v29) = (int)(*(float *)(lpamng + 71156) * (double)v16); /*0xa4cd66*/
        }
        v21 = v14 * *(float *)v10; /*0xa4cd6e*/
        v59 = v21; /*0xa4cd80*/
        *((float *)&n1006632960_5 + 1) = v21; /*0xa4cd89*/
        *(float *)&n1006632960_4 = v21; /*0xa4cd8c*/
        n1006632960_7 = *(_QWORD *)(v10 - 60); /*0xa4cd92*/
        FFX_Menu2D_ProjectNodeCoords_structural((int)v39, lpamng_1 + 70624, (int)&n1006632960_4); /*0xa4cdad*/
        FFX_Menu2D_RenderCaptureNoTexture(unk_23057F8, (int)&n4); /*0xa4cdcc*/
        v6 = 1.0; /*0xa4cdde*/
        v7 = 16.0; /*0xa4cde0*/
        v14 = 0.001249999972060323; /*0xa4cdec*/
        v3 = 1.0; /*0xa4cdf0*/
        v13 = 0.0; /*0xa4cdf2*/
        v5 = 2.0; /*0xa4cdf2*/
      }
    }
    ++n7; /*0xa4cdf4*/
    v10 += 80; /*0xa4cdf5*/
    if ( n7 >= 8 ) /*0xa4cdfb*/
      break; /*0xa4cdfb*/
    v11 = v13; /*0xa4cc84*/
    v9 = v14; /*0xa4cc84*/
    v4 = v11; /*0xa4cc84*/
  }
}
