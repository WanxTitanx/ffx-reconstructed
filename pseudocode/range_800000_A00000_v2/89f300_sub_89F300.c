// Function: sub_89F300
// Address: 0x89f300
int __cdecl sub_89F300(int a1)
{
  double v1; // st7
  __int16 n2; // cx
  int v4; // eax
  int n2_1; // esi
  double v6; // st7
  int v7; // eax
  int v8; // ecx
  double v9; // st7
  __int16 v10; // si
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  float v15; // esi
  double v16; // st6
  float v17; // edi
  double v18; // st5
  double v19; // st4
  int v20; // edx
  float v21; // eax
  float v22; // ecx
  float v23; // eax
  int v24; // edx
  __int16 n255; // ax
  float v26; // edi
  float *v27; // eax
  int v28; // ecx
  double v29; // st7
  int v30; // esi
  double v31; // st7
  int v33; // eax
  double v34; // st7
  float v35; // [esp+0h] [ebp-80h]
  float v36; // [esp+0h] [ebp-80h]
  float v37; // [esp+4h] [ebp-7Ch]
  float v38; // [esp+4h] [ebp-7Ch]
  float v39; // [esp+4h] [ebp-7Ch]
  float v40; // [esp+4h] [ebp-7Ch]
  float v41; // [esp+4h] [ebp-7Ch]
  float v42; // [esp+4h] [ebp-7Ch]
  float v43; // [esp+4h] [ebp-7Ch]
  float v44; // [esp+4h] [ebp-7Ch]
  float v45; // [esp+8h] [ebp-78h]
  float v46; // [esp+8h] [ebp-78h]
  float v47; // [esp+8h] [ebp-78h]
  float v48; // [esp+8h] [ebp-78h]
  float v49; // [esp+8h] [ebp-78h]
  float v50; // [esp+8h] [ebp-78h]
  int v51; // [esp+Ch] [ebp-74h]
  int v52; // [esp+Ch] [ebp-74h]
  int v53; // [esp+Ch] [ebp-74h]
  int v54; // [esp+Ch] [ebp-74h]
  float v55; // [esp+Ch] [ebp-74h]
  float v56; // [esp+Ch] [ebp-74h]
  float v57; // [esp+Ch] [ebp-74h]
  float v58; // [esp+Ch] [ebp-74h]
  float v59; // [esp+Ch] [ebp-74h]
  float v60; // [esp+Ch] [ebp-74h]
  float v61; // [esp+Ch] [ebp-74h]
  float v62; // [esp+Ch] [ebp-74h]
  float v63; // [esp+10h] [ebp-70h]
  float v64; // [esp+10h] [ebp-70h]
  float v65; // [esp+10h] [ebp-70h]
  float v66; // [esp+10h] [ebp-70h]
  float v67; // [esp+10h] [ebp-70h]
  float v68; // [esp+10h] [ebp-70h]
  float v69; // [esp+14h] [ebp-6Ch]
  float v70; // [esp+14h] [ebp-6Ch]
  float v71; // [esp+14h] [ebp-6Ch]
  float v72; // [esp+14h] [ebp-6Ch]
  float v73; // [esp+14h] [ebp-6Ch]
  float v74; // [esp+14h] [ebp-6Ch]
  float v75; // [esp+14h] [ebp-6Ch]
  float v76; // [esp+14h] [ebp-6Ch]
  float v77; // [esp+18h] [ebp-68h]
  float v78; // [esp+18h] [ebp-68h]
  float v79; // [esp+18h] [ebp-68h]
  float v80; // [esp+18h] [ebp-68h]
  int v81; // [esp+1Ch] [ebp-64h]
  float v82; // [esp+1Ch] [ebp-64h]
  char v83; // [esp+1Ch] [ebp-64h]
  float v84; // [esp+20h] [ebp-60h]
  float v85; // [esp+20h] [ebp-60h]
  float v86; // [esp+20h] [ebp-60h]
  int v87; // [esp+24h] [ebp-5Ch]
  float v88; // [esp+24h] [ebp-5Ch]
  int v89; // [esp+24h] [ebp-5Ch]
  char v90; // [esp+24h] [ebp-5Ch]
  int v91; // [esp+28h] [ebp-58h]
  unsigned int v92; // [esp+2Ch] [ebp-54h]
  float v93; // [esp+2Ch] [ebp-54h]
  int v94; // [esp+2Ch] [ebp-54h]
  double v95; // [esp+3Ch] [ebp-44h]
  int v96; // [esp+40h] [ebp-40h]
  double v97; // [esp+44h] [ebp-3Ch]
  double v98; // [esp+44h] [ebp-3Ch]
  double v99; // [esp+44h] [ebp-3Ch]
  float v100; // [esp+48h] [ebp-38h]
  float v101; // [esp+48h] [ebp-38h]
  float v102; // [esp+48h] [ebp-38h]
  float v103; // [esp+48h] [ebp-38h]
  float v104; // [esp+48h] [ebp-38h]
  float v105; // [esp+48h] [ebp-38h]
  float v106; // [esp+48h] [ebp-38h]
  float v107; // [esp+48h] [ebp-38h]
  float v108; // [esp+4Ch] [ebp-34h]
  float v109; // [esp+4Ch] [ebp-34h]
  float v110; // [esp+4Ch] [ebp-34h]
  float v111; // [esp+4Ch] [ebp-34h]
  int v112; // [esp+4Ch] [ebp-34h]
  int v113; // [esp+4Ch] [ebp-34h]
  float v114; // [esp+4Ch] [ebp-34h]
  int v115; // [esp+4Ch] [ebp-34h]
  float v116; // [esp+4Ch] [ebp-34h]
  int v117; // [esp+4Ch] [ebp-34h]
  float v118; // [esp+4Ch] [ebp-34h]
  float v119; // [esp+4Ch] [ebp-34h]
  float v120; // [esp+4Ch] [ebp-34h]
  float v121; // [esp+4Ch] [ebp-34h]
  float v122; // [esp+4Ch] [ebp-34h]
  float v123; // [esp+4Ch] [ebp-34h]
  float v124; // [esp+4Ch] [ebp-34h]
  float v125; // [esp+4Ch] [ebp-34h]
  float v126; // [esp+4Ch] [ebp-34h]
  int v127; // [esp+4Ch] [ebp-34h]
  BOOL v128; // [esp+50h] [ebp-30h]
  float v129; // [esp+54h] [ebp-2Ch]
  float v130; // [esp+54h] [ebp-2Ch]
  float v131; // [esp+54h] [ebp-2Ch]
  float v132; // [esp+54h] [ebp-2Ch]
  float v133; // [esp+54h] [ebp-2Ch]
  float v134; // [esp+54h] [ebp-2Ch]
  float v135; // [esp+54h] [ebp-2Ch]
  int v136; // [esp+58h] [ebp-28h] BYREF
  float *v137; // [esp+5Ch] [ebp-24h]
  int v138; // [esp+60h] [ebp-20h]
  float v139; // [esp+64h] [ebp-1Ch]
  float v140; // [esp+68h] [ebp-18h]
  float v141; // [esp+6Ch] [ebp-14h]
  int v142; // [esp+70h] [ebp-10h]
  float v143; // [esp+74h] [ebp-Ch]
  float v144; // [esp+78h] [ebp-8h]
  int v145; // [esp+7Ch] [ebp-4h]
  float v146; // [esp+88h] [ebp+8h]
  float v147; // [esp+88h] [ebp+8h]
  float v148; // [esp+88h] [ebp+8h]
  float v149; // [esp+88h] [ebp+8h]
  float v150; // [esp+88h] [ebp+8h]
  float v151; // [esp+88h] [ebp+8h]
  float v152; // [esp+88h] [ebp+8h]
  float v153; // [esp+88h] [ebp+8h]
  float v154; // [esp+88h] [ebp+8h]
  float v155; // [esp+88h] [ebp+8h]
  float v156; // [esp+88h] [ebp+8h]
  float v157; // [esp+88h] [ebp+8h]
  float v158; // [esp+88h] [ebp+8h]
  float v159; // [esp+88h] [ebp+8h]
  float v160; // [esp+88h] [ebp+8h]
  float v161; // [esp+88h] [ebp+8h]
  float v162; // [esp+88h] [ebp+8h]
  float v163; // [esp+88h] [ebp+8h]
  float v164; // [esp+88h] [ebp+8h]
  float v165; // [esp+88h] [ebp+8h]
  float v166; // [esp+88h] [ebp+8h]
  int v167; // [esp+88h] [ebp+8h]

  v1 = 0.0;
  if ( *(float *)(a1 + 220) > 0.0 )
  {
    FFX_Engine_GetTime();
    v1 = 0.0 - *(float *)(a1 + 220);
  }
  n2 = *(_WORD *)(a1 + 56);
  *(float *)(a1 + 224) = v1;
  v4 = *(_DWORD *)(a1 + 36) - 1;
  v143 = *(float *)(a1 + 224);
  n2_1 = n2;
  v6 = 154.0;
  v7 = (unsigned __int16)((n2 + v4) / n2);
  v137 = (float *)v7;
  if ( n2 >= 2 )
  {
    v8 = *(__int16 *)(a1 + 66) - *(__int16 *)(a1 + 64);
    if ( v8 > -1 && v8 < 3 * n2_1 )
    {
      FFX_Engine_GetTime();
      v146 = cos(154.0 * 5.0);
      v92 = ((unsigned int)(__int64)(v146 * 32.0 + 96.0) << 24) + 8421504;
      v69 = FFX_Menu2D_ScaleY_1080to416(50.0);
      v147 = (float)*(__int16 *)(a1 + 98);
      v63 = v147;
      v148 = (float)(52 * ((*(__int16 *)(a1 + 66) - *(__int16 *)(a1 + 64)) / *(__int16 *)(a1 + 56)));
      v149 = v148 + 835.0;
      *(float *)&v51 = FFX_Menu2D_ScaleY_1080to416(v149);
      v9 = FFX_Menu2D_ScaleX_1920to512(154.0);
      v150 = (float)(*(__int16 *)(a1 + 98) * ((*(__int16 *)(a1 + 66) - *(__int16 *)(a1 + 64)) % *(__int16 *)(a1 + 56)));
      v151 = v9 + v150;
      FFX_Menu2D_DrawTexQuadTinted(
        0xFFFFFFFF,
        v151,
        v51,
        v63,
        v69,
        COERCE_INT(1619.0),
        COERCE_INT(105.0),
        COERCE_INT(1920.0),
        COERCE_INT(156.0),
        v92,
        v92);
      v6 = 154.0;
    }
    *(float *)&v145 = 0.0;
    v144 = 0.0;
    while ( 1 )
    {
      v10 = *(_WORD *)(a1 + 98);
      v93 = v6;
      v152 = (FFX_Menu2D_ScaleX_1920to512(v93) + (double)v10) * v143 / 0.1000000014901161 - (double)v10;
      v108 = (float)-v10;
      *(float *)&v142 = v108;
      if ( v108 <= (double)v152 )
      {
        if ( FFX_Menu2D_ScaleX_1920to512(154.0) >= v152 )
          goto LABEL_14;
        v11 = FFX_Menu2D_ScaleX_1920to512(154.0);
      }
      else
      {
        v11 = v108;
      }
      v152 = v11;
LABEL_14:
      v109 = (float)SLODWORD(v144);
      v139 = v109;
      v140 = v109 + 835.0;
      v70 = FFX_Menu2D_ScaleY_1080to416(50.0);
      v110 = (float)*(__int16 *)(a1 + 98);
      *(float *)&v52 = FFX_Menu2D_ScaleY_1080to416(v140);
      FFX_Menu2D_DrawTexQuadTinted(
        0xFFFFFFFF,
        v152,
        v52,
        v110,
        v70,
        COERCE_INT(0.0),
        COERCE_INT(0.0),
        COERCE_INT(438.0),
        COERCE_INT(50.0),
        0x60808080u,
        0x60808080u);
      v111 = (float)v145;
      v12 = v111 * 53.0;
      *(float *)&v112 = v12 + 315.0;
      v87 = v112;
      *(float *)&v113 = v12 + 270.0;
      v81 = v113;
      v71 = FFX_Menu2D_ScaleY_1080to416(44.0);
      v64 = FFX_Menu2D_ScaleX_1920to512(234.0);
      v114 = v139 + 838.0;
      *(float *)&v53 = FFX_Menu2D_ScaleY_1080to416(v114);
      FFX_Menu2D_DrawTexQuadTinted(
        0xFFFFFFFF,
        v152,
        v53,
        v64,
        v71,
        COERCE_INT(1553.0),
        v81,
        COERCE_INT(1788.0),
        v87,
        0x40808080u,
        0x40808080u);
      v115 = *(__int16 *)(a1 + 98);
      v153 = (float)(2 * v115);
      v154 = (FFX_Menu2D_ScaleX_1920to512(154.0) + v153) * v143 / 0.1000000014901161 - (double)v115;
      v116 = (float)-v115;
      *(float *)&v142 = v116;
      if ( v116 <= (double)v154 )
      {
        if ( FFX_Menu2D_ScaleX_1920to512(154.0) + (double)*(__int16 *)(a1 + 98) >= v154 )
          v13 = v154;
        else
          v13 = FFX_Menu2D_ScaleX_1920to512(154.0) + (double)*(__int16 *)(a1 + 98);
      }
      else
      {
        v13 = v116;
      }
      v95 = v13;
      v72 = FFX_Menu2D_ScaleY_1080to416(50.0);
      v155 = (float)*(__int16 *)(a1 + 98);
      v65 = v155;
      *(float *)&v54 = FFX_Menu2D_ScaleY_1080to416(v140);
      v156 = v95;
      FFX_Menu2D_DrawTexQuadTinted(
        0xFFFFFFFF,
        v156,
        v54,
        v65,
        v72,
        COERCE_INT(0.0),
        COERCE_INT(0.0),
        COERCE_INT(438.0),
        COERCE_INT(50.0),
        0x60808080u,
        0x60808080u);
      ++v145;
      v143 = v143 - 0.1000000014901161;
      LODWORD(v144) += 52;
      if ( SLODWORD(v144) >= 156 )
      {
        if ( *(float *)(a1 + 224) >= 0.30000001 )
        {
          v14 = 20.0;
          v15 = 0.0;
          v16 = 0.0;
          v17 = 0.0;
          v18 = 40.0;
          *(float *)&v145 = 0.0;
          v19 = 210.0;
          v140 = 0.0;
          while ( 1 )
          {
            ++LODWORD(v15);
            v157 = (float)SLODWORD(v15);
            v139 = v157;
            v158 = v14 * v157;
            *(float *)&v117 = (float)v145;
            v138 = v117;
            v97 = v16 * *(float *)&v117;
            v141 = v97;
            v118 = (float)SLODWORD(v140);
            v140 = v118;
            v143 = v118 + 835.0;
            v88 = v18;
            v77 = v19;
            v55 = FFX_Menu2D_ScaleY_1080to416(3.0);
            v119 = (double)*(__int16 *)(a1 + 98) * 0.5;
            v37 = FFX_Menu2D_ScaleY_1080to416(v143);
            v35 = FFX_Menu2D_ScaleX_1920to512(154.0);
            sub_8E7D30(v35, v37, v119, v55, v141, v158, v77, 3.0, v88, v88, 8421504, 1082163328);
            *(float *)&v142 = v97 + 210.0;
            v56 = FFX_Menu2D_ScaleY_1080to416(3.0);
            v120 = (double)*(__int16 *)(a1 + 98) * 0.5;
            v45 = v120;
            v38 = FFX_Menu2D_ScaleY_1080to416(v143);
            v121 = FFX_Menu2D_ScaleX_1920to512(154.0) + (double)*(__int16 *)(a1 + 98) * 0.5;
            sub_8E7D30(v121, v38, v45, v56, *(float *)&v142, v158, 210.0, 3.0, 40.0, 40.0, 1082163328, 8421504);
            v144 = v139 * 50.0;
            *(float *)&v145 = v140 + 880.0;
            v57 = FFX_Menu2D_ScaleY_1080to416(3.0);
            v122 = (double)*(__int16 *)(a1 + 98) * 0.5;
            v39 = FFX_Menu2D_ScaleY_1080to416(*(float *)&v145);
            v36 = FFX_Menu2D_ScaleX_1920to512(154.0);
            sub_8E7D30(v36, v39, v122, v57, v141, v144, 210.0, 3.0, 40.0, 40.0, 8421504, 1082163328);
            v58 = FFX_Menu2D_ScaleY_1080to416(3.0);
            v123 = (double)*(__int16 *)(a1 + 98) * 0.5;
            v46 = v123;
            v40 = FFX_Menu2D_ScaleY_1080to416(*(float *)&v145);
            v124 = FFX_Menu2D_ScaleX_1920to512(154.0) + (double)*(__int16 *)(a1 + 98) * 0.5;
            sub_8E7D30(v124, v40, v46, v58, *(float *)&v142, v144, 210.0, 3.0, 40.0, 40.0, 1082163328, 8421504);
            v98 = *(float *)&v138 * 20.0;
            *(float *)&v138 = v98;
            v59 = FFX_Menu2D_ScaleY_1080to416(3.0);
            v125 = (double)*(__int16 *)(a1 + 98) * 0.5;
            v47 = v125;
            v41 = FFX_Menu2D_ScaleY_1080to416(v143);
            v126 = FFX_Menu2D_ScaleX_1920to512(154.0) + (double)*(__int16 *)(a1 + 98);
            sub_8E7D30(v126, v41, v47, v59, *(float *)&v138, v158, 210.0, 3.0, 40.0, 40.0, 8421504, 1082163328);
            v139 = v98 + 210.0;
            v73 = v158;
            v60 = FFX_Menu2D_ScaleY_1080to416(3.0);
            v159 = (double)*(__int16 *)(a1 + 98) * 0.5;
            v48 = v159;
            v42 = FFX_Menu2D_ScaleY_1080to416(v143);
            v160 = FFX_Menu2D_ScaleX_1920to512(154.0) + (double)*(__int16 *)(a1 + 98) * 1.5;
            sub_8E7D30(v160, v42, v48, v60, v139, v73, 210.0, 3.0, 40.0, 40.0, 1082163328, 8421504);
            v61 = FFX_Menu2D_ScaleY_1080to416(3.0);
            v161 = (double)*(__int16 *)(a1 + 98) * 0.5;
            v49 = v161;
            v43 = FFX_Menu2D_ScaleY_1080to416(*(float *)&v145);
            v162 = FFX_Menu2D_ScaleX_1920to512(154.0) + (double)*(__int16 *)(a1 + 98);
            sub_8E7D30(v162, v43, v49, v61, *(float *)&v138, v144, 210.0, 3.0, 40.0, 40.0, 8421504, 1082163328);
            v62 = FFX_Menu2D_ScaleY_1080to416(3.0);
            v163 = (double)*(__int16 *)(a1 + 98) * 0.5;
            v50 = v163;
            v44 = FFX_Menu2D_ScaleY_1080to416(*(float *)&v145);
            v164 = FFX_Menu2D_ScaleX_1920to512(154.0) + (double)*(__int16 *)(a1 + 98) * 1.5;
            sub_8E7D30(v164, v44, v50, v62, v139, v144, 210.0, 3.0, 40.0, 40.0, 1082163328, 8421504);
            LODWORD(v17) += 52;
            *(float *)&v145 = v15;
            v140 = v17;
            if ( SLODWORD(v17) >= 156 )
              break;
            v14 = 20.0;
            v18 = 40.0;
            v19 = 210.0;
            v16 = 0.0;
          }
        }
        LOWORD(v7) = (_WORD)v137;
        v6 = 154.0;
        break;
      }
      v6 = 154.0;
    }
  }
  v94 = (__int16)v7;
  v91 = *(__int16 *)(a1 + 58);
  v89 = *(__int16 *)(a1 + 64) / *(__int16 *)(a1 + 56);
  v84 = v6;
  v85 = FFX_Menu2D_ScaleY_1080to416(v84);
  v82 = FFX_Menu2D_ScaleX_1920to512(8.0);
  v78 = FFX_Menu2D_ScaleY_1080to416(835.0);
  v165 = FFX_Menu2D_ScaleX_1920to512(150.0) + (double)*(__int16 *)(a1 + 98);
  sub_8E6CC0(v165, v78, v82, v85, v89, v91, v94);
  FFX_Menu2D_SetViewport(
    (int)*(float *)(a1 + 104),
    (int)*(float *)(a1 + 108),
    (int)*(float *)(a1 + 112),
    (int)*(float *)(a1 + 116));
  (*(void (__cdecl **)(int))(a1 + 136))(a1);
  v20 = *(__int16 *)(a1 + 64);
  v21 = *(float *)(a1 + 36);
  v139 = v21;
  if ( v20 <= SLODWORD(v21) )
    LODWORD(v22) = v20 < 0 ? 0 : v20;
  else
    v22 = v21;
  v23 = v139;
  v24 = LODWORD(v22) + *(__int16 *)(a1 + 58) * *(__int16 *)(a1 + 56);
  v143 = v22;
  if ( v24 <= SLODWORD(v139) )
  {
    LODWORD(v23) = v24 < 0 ? 0 : v24;
    v139 = v23;
  }
  if ( SLODWORD(v22) >= SLODWORD(v23) )
    JUMPOUT(0x8A03F2);
  n255 = *(_WORD *)(*(_DWORD *)(a1 + 32) + 2 * LODWORD(v22));
  if ( n255 == 255 )
    JUMPOUT(0x8A03E5);
  v96 = sub_89AC10(*(_WORD *)(a1 + 8), n255);
  if ( v96 == -4 )
    goto LABEL_55;
  v26 = v143;
  v27 = FFX_Btl_LookupCommandDataById(*(__int16 *)(*(_DWORD *)(a1 + 32) + 2 * LODWORD(v143)), &v136);
  v28 = *(__int16 *)(a1 + 66);
  v29 = *(float *)(a1 + 104);
  v30 = *(__int16 *)(a1 + 56);
  v137 = v27;
  v127 = v136 + *(unsigned __int16 *)v27;
  v128 = LODWORD(v26) == v28;
  v145 = *(__int16 *)(a1 + 98) * (SLODWORD(v26) % v30);
  v145 += (int)v29;
  v142 = v145;
  v166 = (float)(52 * ((LODWORD(v26) - *(__int16 *)(a1 + 64)) / v30));
  v167 = (int)(FFX_Menu2D_ScaleY_1080to416(v166) + *(float *)(a1 + 124));
  v141 = 0.0;
  if ( *(__int16 *)(a1 + 40) <= 0 )
LABEL_55:
    JUMPOUT(0x8A03DD);
  LODWORD(v140) = a1 + 44;
  switch ( *(_BYTE *)(a1 + 45) )
  {
    case 1:
      v83 = *((_BYTE *)v137 + 20);
      v79 = FFX_Menu2D_ScaleY_1080to416(36.0);
      v74 = FFX_Menu2D_ScaleX_1920to512(29.0);
      v129 = (float)v167;
      v130 = FFX_Menu2D_ScaleY_1080to416(3.0) + v129;
      v66 = v130;
      v31 = FFX_Menu2D_ScaleX_1920to512(37.0);
      v131 = (float)v142;
      v132 = v31 + v131;
      sub_8E6AF0(v132, v66, v74, v79, v83, 128, 128, 128, 128);
      goto LABEL_52;
    case 2:
      *(float *)&v138 = COERCE_FLOAT(FFX_Inventory_GetItemCount(*(__int16 *)(*(_DWORD *)(a1 + 32) + 2 * LODWORD(v26))));
      if ( v138 > 0 || *(_WORD *)(a1 + 42) == 1 )
        goto LABEL_44;
      goto LABEL_52;
    case 4:
      *(float *)&v138 = COERCE_FLOAT(FFX_Btl_Ctb_ComputeTurnWeight(*(_WORD *)(a1 + 8), (int)v137));
      if ( v138 > 0 || *(_WORD *)(a1 + 42) == 1 )
        goto LABEL_44;
      goto LABEL_52;
    case 5:
      *(float *)&v138 = COERCE_FLOAT(FFX_Btl_GetActorCtbGaugeCurrent(*(_WORD *)(*(_DWORD *)(a1 + 32) + 2 * LODWORD(v26))));
      if ( v138 > 0 || *(_WORD *)(a1 + 42) == 1 )
      {
LABEL_44:
        v133 = (float)(v145 + *(__int16 *)(a1 + 98));
        v99 = v133;
        v90 = LOBYTE(v144);
        v134 = (float)v167;
        v86 = v134;
        v135 = v99 - FFX_Menu2D_ScaleX_1920to512(28.0);
        sub_9055C0(v138, v135, v86, v90, 0.77999997, 1.0);
      }
      goto LABEL_52;
    case 6:
      *(float *)&v138 = COERCE_FLOAT(FFX_Btl_GetActorCtbGaugeTarget(*(_WORD *)(*(_DWORD *)(a1 + 32) + 2 * LODWORD(v26))));
      if ( v138 <= 0 && *(_WORD *)(a1 + 42) != 1 )
        goto LABEL_52;
      return sub_8A0236(v167);
    case 7:
      JUMPOUT(0x8A028F);
    case 0x10:
      v33 = *(__int16 *)(a1 + 102);
      LOBYTE(v144) = v96 < 0;
      if ( *(_DWORD *)(a1 + 228) )
      {
        v80 = v144;
        v100 = (float)v33;
        v75 = v100;
        v101 = (float)v167;
        v67 = v101;
        v34 = FFX_Menu2D_ScaleX_1920to512(72.0);
        v102 = (float)v142;
        v103 = v34 + v102;
        sub_904BA0(v127, LODWORD(v103), LODWORD(v67), LODWORD(v75), LODWORD(v80), 0.77999997, 1.0, 0, v128, 0);
      }
      else
      {
        v104 = (float)v33;
        v76 = v104;
        v105 = (float)v167;
        v68 = v105;
        v106 = (float)v142;
        v107 = (double)*(__int16 *)(a1 + 98) * 0.5 + v106;
        sub_904BA0(v127, LODWORD(v107), LODWORD(v68), LODWORD(v76), LODWORD(v144), 0.77999997, 1.0, 1, v128, 0);
      }
      goto LABEL_52;
    default:
LABEL_52:
      JUMPOUT(0x8A03C6);
  }
}
