// Function: FFX_BtlUI_RenderPartyStatusDetail
// Address: 0x8963c0
int FFX_BtlUI_RenderPartyStatusDetail()
{
  double v0; // st7
  int n835; // ebx
  unsigned __int16 *p_i; // edi
  char *v3; // esi
  int result; // eax
  float *v5; // eax
  double v6; // st7
  float *DurationFloatPtr; // eax
  int ActorCtbTurns; // eax
  double v9; // st7
  float *v10; // eax
  int ActorCtbSpeed; // eax
  double v12; // st7
  float *v13; // eax
  __int16 v14; // dx
  __int16 v15; // cx
  char *KernelString; // eax
  int v17; // [esp+4h] [ebp-3Ch]
  float v18; // [esp+4h] [ebp-3Ch]
  float v19; // [esp+4h] [ebp-3Ch]
  int v20; // [esp+4h] [ebp-3Ch]
  float v21; // [esp+4h] [ebp-3Ch]
  int v22; // [esp+4h] [ebp-3Ch]
  float v23; // [esp+4h] [ebp-3Ch]
  int v24; // [esp+4h] [ebp-3Ch]
  float v25; // [esp+8h] [ebp-38h]
  float v26; // [esp+8h] [ebp-38h]
  float v27; // [esp+8h] [ebp-38h]
  float v28; // [esp+8h] [ebp-38h]
  float v29; // [esp+8h] [ebp-38h]
  float v30; // [esp+8h] [ebp-38h]
  float v31; // [esp+8h] [ebp-38h]
  float v32; // [esp+8h] [ebp-38h]
  float v33; // [esp+Ch] [ebp-34h]
  float v34; // [esp+Ch] [ebp-34h]
  float v35; // [esp+Ch] [ebp-34h]
  float v36; // [esp+Ch] [ebp-34h]
  float v37; // [esp+Ch] [ebp-34h]
  float v38; // [esp+Ch] [ebp-34h]
  float v39; // [esp+Ch] [ebp-34h]
  float v40; // [esp+Ch] [ebp-34h]
  float v41; // [esp+10h] [ebp-30h]
  int v42; // [esp+10h] [ebp-30h]
  float v43; // [esp+10h] [ebp-30h]
  int v44; // [esp+10h] [ebp-30h]
  float v45; // [esp+10h] [ebp-30h]
  float v46; // [esp+10h] [ebp-30h]
  int v47; // [esp+10h] [ebp-30h]
  float v48; // [esp+10h] [ebp-30h]
  float v49; // [esp+10h] [ebp-30h]
  float v50; // [esp+10h] [ebp-30h]
  float v51; // [esp+10h] [ebp-30h]
  int v52; // [esp+10h] [ebp-30h]
  float v53; // [esp+10h] [ebp-30h]
  float v54; // [esp+10h] [ebp-30h]
  float v55; // [esp+10h] [ebp-30h]
  float v56; // [esp+10h] [ebp-30h]
  float v57; // [esp+10h] [ebp-30h]
  float v58; // [esp+14h] [ebp-2Ch]
  char v59; // [esp+14h] [ebp-2Ch]
  int v60; // [esp+14h] [ebp-2Ch]
  char v61; // [esp+14h] [ebp-2Ch]
  int v62; // [esp+14h] [ebp-2Ch]
  char v63; // [esp+14h] [ebp-2Ch]
  char v64; // [esp+14h] [ebp-2Ch]
  int v65; // [esp+14h] [ebp-2Ch]
  char v66; // [esp+14h] [ebp-2Ch]
  char v67; // [esp+14h] [ebp-2Ch]
  int v68; // [esp+14h] [ebp-2Ch]
  char v69; // [esp+14h] [ebp-2Ch]
  char v70; // [esp+14h] [ebp-2Ch]
  float v71; // [esp+18h] [ebp-28h]
  int v72; // [esp+18h] [ebp-28h]
  int v73; // [esp+18h] [ebp-28h]
  int v74; // [esp+18h] [ebp-28h]
  int v75; // [esp+18h] [ebp-28h]
  float v76; // [esp+1Ch] [ebp-24h]
  float v77; // [esp+1Ch] [ebp-24h]
  int v78; // [esp+1Ch] [ebp-24h]
  int v79; // [esp+1Ch] [ebp-24h]
  int v80; // [esp+1Ch] [ebp-24h]
  int v81; // [esp+1Ch] [ebp-24h]
  int v82; // [esp+30h] [ebp-10h]
  float v83; // [esp+30h] [ebp-10h]
  float v84; // [esp+30h] [ebp-10h]
  float v85; // [esp+30h] [ebp-10h]
  float v86; // [esp+30h] [ebp-10h]
  float v87; // [esp+30h] [ebp-10h]
  float v88; // [esp+30h] [ebp-10h]
  float v89; // [esp+30h] [ebp-10h]
  float v90; // [esp+30h] [ebp-10h]
  float v91; // [esp+30h] [ebp-10h]
  float v92; // [esp+30h] [ebp-10h]
  float v93; // [esp+30h] [ebp-10h]
  float v94; // [esp+30h] [ebp-10h]
  float v95; // [esp+30h] [ebp-10h]
  float v96; // [esp+30h] [ebp-10h]
  float v97; // [esp+30h] [ebp-10h]
  int v98; // [esp+30h] [ebp-10h]
  float v99; // [esp+30h] [ebp-10h]
  float v100; // [esp+30h] [ebp-10h]
  float v101; // [esp+30h] [ebp-10h]
  float v102; // [esp+30h] [ebp-10h]
  float v103; // [esp+30h] [ebp-10h]
  float v104; // [esp+30h] [ebp-10h]
  float v105; // [esp+30h] [ebp-10h]
  float v106; // [esp+30h] [ebp-10h]
  float v107; // [esp+30h] [ebp-10h]
  float v108; // [esp+30h] [ebp-10h]
  float v109; // [esp+30h] [ebp-10h]
  float v110; // [esp+30h] [ebp-10h]
  int v111; // [esp+30h] [ebp-10h]
  float v112; // [esp+30h] [ebp-10h]
  float v113; // [esp+30h] [ebp-10h]
  float v114; // [esp+30h] [ebp-10h]
  float v115; // [esp+30h] [ebp-10h]
  float v116; // [esp+30h] [ebp-10h]
  float v117; // [esp+30h] [ebp-10h]
  float v118; // [esp+30h] [ebp-10h]
  float v119; // [esp+30h] [ebp-10h]
  float v120; // [esp+30h] [ebp-10h]
  float v121; // [esp+30h] [ebp-10h]
  float v122; // [esp+30h] [ebp-10h]
  float v123; // [esp+30h] [ebp-10h]
  int v124; // [esp+30h] [ebp-10h]
  float v125; // [esp+30h] [ebp-10h]
  float v126; // [esp+30h] [ebp-10h]
  float v127; // [esp+30h] [ebp-10h]
  float v128; // [esp+30h] [ebp-10h]
  float v129; // [esp+30h] [ebp-10h]
  int v130; // [esp+34h] [ebp-Ch]
  float v131; // [esp+38h] [ebp-8h]
  int n835_1; // [esp+3Ch] [ebp-4h]
  float n835_2; // [esp+3Ch] [ebp-4h]
  float v134; // [esp+3Ch] [ebp-4h]

  FFX_Menu2D_SetViewport(0, 0, 512, 416);
  v0 = 1231.0;
  n835 = 835;
  v130 = 0;
  p_i = p_i;
  v3 = (char *)&unk_133F7B1;
  n835_1 = 835;
  result = 0;
  do
  {
    if ( *p_i != 255 )
    {
      v76 = v0;
      v131 = FFX_Menu2D_ScaleX_1920to512(v76);
      n835_2 = (float)n835_1;
      v134 = FFX_Menu2D_ScaleY_1080to416(n835_2);
      switch ( n3_3 )
      {
        case 0:
          v6 = v134;
          if ( ((1 << *(_BYTE *)p_i) & unk_133D138) != 0 )
          {
            v36 = FFX_Menu2D_ScaleY_1080to416(52.0);
            v28 = FFX_Menu2D_ScaleX_1920to512(680.0);
            *(float *)&v98 = v134 - FFX_Menu2D_ScaleY_1080to416(2.0);
            v20 = v98;
            v99 = v131 - FFX_Menu2D_ScaleX_1920to512(65.0);
            FFX_Menu2D_DrawTexQuadSolid(
              0xFFFFFFFF,
              v99,
              v20,
              v28,
              v36,
              COERCE_INT(1536.0),
              COERCE_INT(458.0),
              COERCE_INT(2047.0),
              COERCE_INT(510.0));
            v6 = v134;
          }
          v64 = *v3;
          v100 = v6 - FFX_Menu2D_ScaleY_1080to416(4.0);
          v46 = v100;
          v101 = FFX_Menu2D_ScaleX_1920to512(21.0) + v131;
          DurationFloatPtr = FFX_StatusEffect_GetDurationFloatPtr(*p_i);
          FFX_Menu2D_DrawStatusEffectTimerBar((int)DurationFloatPtr, v101, v46, v64, 0.68000001, COERCE_INT(1.0));
          if ( FFX_Game_GetRegion() == 11 )
          {
            *(float *)&v80 = 0.041015625;
            *(float *)&v74 = 0.44433594;
            *(float *)&v65 = 0.01171875;
            *(float *)&v47 = 0.36132812;
            v37 = FFX_Menu2D_ScaleY_1080to416(24.0);
            v29 = FFX_Menu2D_ScaleX_1920to512(68.0);
            v102 = FFX_Menu2D_ScaleY_1080to416(5.0) + v134 - 2.0;
            v21 = v102;
            v103 = FFX_Menu2D_ScaleX_1920to512(240.0) + v131 - 3.0;
          }
          else
          {
            *(float *)&v80 = 0.040039062;
            *(float *)&v74 = 0.42578125;
            *(float *)&v65 = 0.014648438;
            *(float *)&v47 = 0.34765625;
            v37 = FFX_Menu2D_ScaleY_1080to416(23.0);
            v29 = FFX_Menu2D_ScaleX_1920to512(61.5);
            v104 = FFX_Menu2D_ScaleY_1080to416(5.0) + v134;
            v21 = v104;
            v103 = FFX_Menu2D_ScaleX_1920to512(240.0) + v131;
          }
          FFX_Menu2D_DrawTexQuadSolid(0xE9u, v103, SLODWORD(v21), v29, v37, v47, v65, v74, v80);
          v66 = *v3;
          v105 = FFX_Menu2D_ScaleY_1080to416(-2.0) + v134;
          v48 = v105;
          v106 = FFX_Menu2D_ScaleX_1920to512(395.0) + v131;
          FFX_Menu2D_DrawNumberWithAlignment(*(_DWORD *)(v3 - 9), v106, v48, v66, 0.64999998, 0.0);
          v107 = FFX_Menu2D_ScaleY_1080to416(6.0) + v134;
          v49 = v107;
          v108 = FFX_Menu2D_ScaleX_1920to512(420.0) + v131;
          FFX_Menu2D_DrawIconOrTimer((int)word_B8F87C, v108, v49, 0, 0.64999998, 0.0);
          v109 = FFX_Menu2D_ScaleY_1080to416(-2.0) + v134;
          v50 = v109;
          v110 = FFX_Menu2D_ScaleX_1920to512(540.0) + v131;
          ActorCtbTurns = FFX_Btl_GetActorCtbTurns(*p_i);
          FFX_Menu2D_DrawNumberWithAlignment(ActorCtbTurns, v110, v50, 0, 0.64999998, 0.0);
          break;
        case 1:
          v9 = v134;
          if ( ((1 << *(_BYTE *)p_i) & unk_133D138) != 0 )
          {
            v38 = FFX_Menu2D_ScaleY_1080to416(52.0);
            v30 = FFX_Menu2D_ScaleX_1920to512(680.0);
            *(float *)&v111 = v134 - FFX_Menu2D_ScaleY_1080to416(2.0);
            v22 = v111;
            v112 = v131 - FFX_Menu2D_ScaleX_1920to512(65.0);
            FFX_Menu2D_DrawTexQuadSolid(
              0xFFFFFFFF,
              v112,
              v22,
              v30,
              v38,
              COERCE_INT(1536.0),
              COERCE_INT(458.0),
              COERCE_INT(2047.0),
              COERCE_INT(510.0));
            v9 = v134;
          }
          v67 = *v3;
          v113 = v9 - FFX_Menu2D_ScaleY_1080to416(4.0);
          v51 = v113;
          v114 = FFX_Menu2D_ScaleX_1920to512(21.0) + v131;
          v10 = FFX_StatusEffect_GetDurationFloatPtr(*p_i);
          FFX_Menu2D_DrawStatusEffectTimerBar((int)v10, v114, v51, v67, 0.68000001, COERCE_INT(1.0));
          if ( FFX_Game_GetRegion() == 11 )
          {
            *(float *)&v81 = 0.041015625;
            *(float *)&v75 = 0.56933594;
            *(float *)&v68 = 0.01171875;
            *(float *)&v52 = 0.48828125;
            v39 = FFX_Menu2D_ScaleY_1080to416(24.0);
            v31 = FFX_Menu2D_ScaleX_1920to512(66.400002);
            v115 = FFX_Menu2D_ScaleY_1080to416(5.0) + v134 - 2.0;
            v23 = v115;
            v116 = FFX_Menu2D_ScaleX_1920to512(240.0) + v131 - 5.0;
          }
          else
          {
            *(float *)&v81 = 0.040039062;
            *(float *)&v75 = 0.55664062;
            *(float *)&v68 = 0.014648438;
            *(float *)&v52 = 0.49804688;
            v39 = FFX_Menu2D_ScaleY_1080to416(23.0);
            v31 = FFX_Menu2D_ScaleX_1920to512(49.0);
            v117 = FFX_Menu2D_ScaleY_1080to416(5.0) + v134;
            v23 = v117;
            v116 = FFX_Menu2D_ScaleX_1920to512(240.0) + v131;
          }
          FFX_Menu2D_DrawTexQuadSolid(0xEAu, v116, SLODWORD(v23), v31, v39, v52, v68, v75, v81);
          v69 = *v3;
          v118 = FFX_Menu2D_ScaleY_1080to416(-2.0) + v134;
          v53 = v118;
          v119 = FFX_Menu2D_ScaleX_1920to512(395.0) + v131;
          FFX_Menu2D_DrawNumberWithAlignment(*(_DWORD *)(v3 + 15), v119, v53, v69, 0.64999998, 0.0);
          v120 = FFX_Menu2D_ScaleY_1080to416(6.0) + v134;
          v54 = v120;
          v121 = FFX_Menu2D_ScaleX_1920to512(420.0) + v131;
          FFX_Menu2D_DrawIconOrTimer((int)word_B8F87C, v121, v54, 0, 0.64999998, 0.0);
          v122 = FFX_Menu2D_ScaleY_1080to416(-2.0) + v134;
          v55 = v122;
          v123 = FFX_Menu2D_ScaleX_1920to512(540.0) + v131;
          ActorCtbSpeed = FFX_Btl_GetActorCtbSpeed(*p_i);
          FFX_Menu2D_DrawNumberWithAlignment(ActorCtbSpeed, v123, v55, 0, 0.64999998, 0.0);
          break;
        case 2:
          v12 = v134;
          if ( ((1 << *(_BYTE *)p_i) & unk_133D138) != 0 )
          {
            v40 = FFX_Menu2D_ScaleY_1080to416(52.0);
            v32 = FFX_Menu2D_ScaleX_1920to512(680.0);
            *(float *)&v124 = v134 - FFX_Menu2D_ScaleY_1080to416(2.0);
            v24 = v124;
            v125 = v131 - FFX_Menu2D_ScaleX_1920to512(65.0);
            FFX_Menu2D_DrawTexQuadSolid(
              0xFFFFFFFF,
              v125,
              v24,
              v32,
              v40,
              COERCE_INT(1536.0),
              COERCE_INT(458.0),
              COERCE_INT(2047.0),
              COERCE_INT(510.0));
            v12 = v134;
          }
          v70 = *v3;
          v126 = v12 - FFX_Menu2D_ScaleY_1080to416(4.0);
          v56 = v126;
          v127 = FFX_Menu2D_ScaleX_1920to512(21.0) + v131;
          v13 = FFX_StatusEffect_GetDurationFloatPtr(*p_i);
          FFX_Menu2D_DrawStatusEffectTimerBar((int)v13, v127, v56, v70, 0.68000001, COERCE_INT(1.0));
          v14 = *(_WORD *)(v3 + 39);
          if ( v14 )
          {
            v15 = *(_WORD *)(v3 + 35);
            *(_WORD *)(v3 + 35) = v15 - 1;
            if ( v15 <= 0 )
            {
              ++*(_WORD *)(v3 + 37);
              *(_WORD *)(v3 + 35) = 20;
              if ( *(__int16 *)(v3 + 37) >= v14 )
                *(_WORD *)(v3 + 37) = 0;
            }
            v128 = FFX_Menu2D_ScaleY_1080to416(4.0) + v134;
            v57 = v128;
            v129 = FFX_Menu2D_ScaleX_1920to512(279.0) + v131;
            KernelString = (char *)FFX_Table_GetKernelString(1, unk_133F7DA[v130 + *(__int16 *)(v3 + 37)], 1);
            FFX_Menu2D_DrawKernelString(KernelString, v129, v57, 0.0, 0.77999997);
          }
          break;
        case 3:
          if ( unk_23CC088[0] == *p_i )
          {
            v33 = FFX_Menu2D_ScaleY_1080to416(52.0);
            v25 = FFX_Menu2D_ScaleX_1920to512(680.0);
            *(float *)&v82 = v134 - FFX_Menu2D_ScaleY_1080to416(2.0);
            v17 = v82;
            v83 = v131 - FFX_Menu2D_ScaleX_1920to512(65.0);
            FFX_Menu2D_DrawTexQuadSolid(
              0xFFFFFFFF,
              v83,
              v17,
              v25,
              v33,
              COERCE_INT(983.0),
              COERCE_INT(95.0),
              COERCE_INT(1584.0),
              COERCE_INT(147.0));
          }
          v77 = FFX_Menu2D_ScaleY_1080to416(8.0);
          v71 = FFX_Menu2D_ScaleX_1920to512(520.0);
          v84 = FFX_Menu2D_ScaleY_1080to416(35.0) + v134;
          v58 = v84;
          v85 = FFX_Menu2D_ScaleX_1920to512(21.0) + v131;
          FFX_Menu2D_DrawProgressBar(*(_DWORD *)(v3 + 31), v85, v58, v71, v77);
          v59 = *v3;
          v86 = v134 - FFX_Menu2D_ScaleY_1080to416(4.0);
          v41 = v86;
          v87 = FFX_Menu2D_ScaleX_1920to512(21.0) + v131;
          v5 = FFX_StatusEffect_GetDurationFloatPtr(*p_i);
          FFX_Menu2D_DrawStatusEffectTimerBar((int)v5, v87, v41, v59, 0.68000001, COERCE_INT(1.0));
          if ( FFX_Game_GetRegion() == 11 )
          {
            *(float *)&v78 = 0.041015625;
            *(float *)&v72 = 0.44433594;
            *(float *)&v60 = 0.01171875;
            *(float *)&v42 = 0.36132812;
            v34 = FFX_Menu2D_ScaleY_1080to416(24.0);
            v26 = FFX_Menu2D_ScaleX_1920to512(68.0);
            v88 = FFX_Menu2D_ScaleY_1080to416(5.0) + v134 - 2.0;
            v18 = v88;
            v89 = FFX_Menu2D_ScaleX_1920to512(240.0) + v131 - 3.0;
          }
          else
          {
            *(float *)&v78 = 0.040039062;
            *(float *)&v72 = 0.42578125;
            *(float *)&v60 = 0.014648438;
            *(float *)&v42 = 0.34765625;
            v34 = FFX_Menu2D_ScaleY_1080to416(23.0);
            v26 = FFX_Menu2D_ScaleX_1920to512(61.5);
            v90 = FFX_Menu2D_ScaleY_1080to416(5.0) + v134;
            v18 = v90;
            v89 = FFX_Menu2D_ScaleX_1920to512(240.0) + v131;
          }
          FFX_Menu2D_DrawTexQuadSolid(0xE9u, v89, SLODWORD(v18), v26, v34, v42, v60, v72, v78);
          v61 = *v3;
          v91 = FFX_Menu2D_ScaleY_1080to416(-2.0) + v134;
          v43 = v91;
          v92 = FFX_Menu2D_ScaleX_1920to512(395.0) + v131;
          FFX_Menu2D_DrawNumberWithAlignment(*(_DWORD *)(v3 - 9), v92, v43, v61, 0.64999998, 0.0);
          if ( FFX_Game_GetRegion() == 11 )
          {
            *(float *)&v79 = 0.041015625;
            *(float *)&v73 = 0.56933594;
            *(float *)&v62 = 0.01171875;
            *(float *)&v44 = 0.48828125;
            v35 = FFX_Menu2D_ScaleY_1080to416(24.0);
            v27 = FFX_Menu2D_ScaleX_1920to512(66.400002);
            v93 = FFX_Menu2D_ScaleY_1080to416(5.0) + v134 - 2.0;
            v19 = v93;
            v94 = FFX_Menu2D_ScaleX_1920to512(420.0) + v131 - 5.0;
          }
          else
          {
            *(float *)&v79 = 0.040039062;
            *(float *)&v73 = 0.55664062;
            *(float *)&v62 = 0.014648438;
            *(float *)&v44 = 0.49804688;
            v35 = FFX_Menu2D_ScaleY_1080to416(23.0);
            v27 = FFX_Menu2D_ScaleX_1920to512(49.0);
            v95 = FFX_Menu2D_ScaleY_1080to416(5.0) + v134;
            v19 = v95;
            v94 = FFX_Menu2D_ScaleX_1920to512(420.0) + v131;
          }
          FFX_Menu2D_DrawTexQuadSolid(0xEAu, v94, SLODWORD(v19), v27, v35, v44, v62, v73, v79);
          v63 = v3[24];
          v96 = FFX_Menu2D_ScaleY_1080to416(-2.0) + v134;
          v45 = v96;
          v97 = FFX_Menu2D_ScaleX_1920to512(540.0) + v131;
          FFX_Menu2D_DrawNumberWithAlignment(*(_DWORD *)(v3 + 15), v97, v45, v63, 0.64999998, 0.0);
          break;
        default:
          break;
      }
      v0 = 1231.0;
      result = v130;
    }
    n835 += 52;
    result += 72;
    ++p_i;
    v3 += 144;
    n835_1 = n835;
    v130 = result;
  }
  while ( n835 < 991 );
  return result;
}
