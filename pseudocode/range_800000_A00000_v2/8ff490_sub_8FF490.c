// Function: sub_8FF490
// Address: 0x8ff490
int __cdecl sub_8FF490(int n8, float a2, int a3)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  double v7; // st7
  int v8; // eax
  unsigned int v9; // esi
  int v10; // eax
  float v12; // [esp+8h] [ebp-74h]
  float v13; // [esp+8h] [ebp-74h]
  float v14; // [esp+8h] [ebp-74h]
  float v15; // [esp+8h] [ebp-74h]
  float v16; // [esp+8h] [ebp-74h]
  float v17; // [esp+8h] [ebp-74h]
  float v18; // [esp+8h] [ebp-74h]
  float v19; // [esp+8h] [ebp-74h]
  int v20; // [esp+8h] [ebp-74h]
  int v21; // [esp+8h] [ebp-74h]
  float v22; // [esp+Ch] [ebp-70h]
  float v23; // [esp+Ch] [ebp-70h]
  float v24; // [esp+Ch] [ebp-70h]
  float v25; // [esp+Ch] [ebp-70h]
  float v26; // [esp+Ch] [ebp-70h]
  float v27; // [esp+Ch] [ebp-70h]
  float v28; // [esp+Ch] [ebp-70h]
  float v29; // [esp+Ch] [ebp-70h]
  float v30; // [esp+Ch] [ebp-70h]
  float v31; // [esp+Ch] [ebp-70h]
  int v32; // [esp+10h] [ebp-6Ch]
  int v33; // [esp+10h] [ebp-6Ch]
  int v34; // [esp+10h] [ebp-6Ch]
  int v35; // [esp+10h] [ebp-6Ch]
  int v36; // [esp+10h] [ebp-6Ch]
  int v37; // [esp+10h] [ebp-6Ch]
  int v38; // [esp+10h] [ebp-6Ch]
  float v39; // [esp+10h] [ebp-6Ch]
  float v40; // [esp+10h] [ebp-6Ch]
  float v41; // [esp+14h] [ebp-68h]
  float v42; // [esp+14h] [ebp-68h]
  float v43; // [esp+14h] [ebp-68h]
  float v44; // [esp+14h] [ebp-68h]
  float v45; // [esp+14h] [ebp-68h]
  float v46; // [esp+14h] [ebp-68h]
  float v47; // [esp+14h] [ebp-68h]
  int v48; // [esp+14h] [ebp-68h]
  int v49; // [esp+14h] [ebp-68h]
  int v50; // [esp+14h] [ebp-68h]
  int v51; // [esp+14h] [ebp-68h]
  int v52; // [esp+14h] [ebp-68h]
  int v53; // [esp+14h] [ebp-68h]
  int v54; // [esp+14h] [ebp-68h]
  float v55; // [esp+18h] [ebp-64h]
  float v56; // [esp+18h] [ebp-64h]
  float v57; // [esp+18h] [ebp-64h]
  float v58; // [esp+18h] [ebp-64h]
  float v59; // [esp+18h] [ebp-64h]
  float v60; // [esp+18h] [ebp-64h]
  float v61; // [esp+18h] [ebp-64h]
  float v62; // [esp+18h] [ebp-64h]
  float v63; // [esp+18h] [ebp-64h]
  float v64; // [esp+18h] [ebp-64h]
  float v65; // [esp+18h] [ebp-64h]
  float v66; // [esp+18h] [ebp-64h]
  float v67; // [esp+18h] [ebp-64h]
  float v68; // [esp+18h] [ebp-64h]
  float v69; // [esp+18h] [ebp-64h]
  float v70; // [esp+18h] [ebp-64h]
  float v71; // [esp+18h] [ebp-64h]
  float v72; // [esp+18h] [ebp-64h]
  float v73; // [esp+18h] [ebp-64h]
  float v74; // [esp+18h] [ebp-64h]
  float v75; // [esp+18h] [ebp-64h]
  float v76; // [esp+18h] [ebp-64h]
  float v77; // [esp+1Ch] [ebp-60h]
  float v78; // [esp+1Ch] [ebp-60h]
  float v79; // [esp+1Ch] [ebp-60h]
  float v80; // [esp+1Ch] [ebp-60h]
  float v81; // [esp+1Ch] [ebp-60h]
  float v82; // [esp+1Ch] [ebp-60h]
  float v83; // [esp+1Ch] [ebp-60h]
  float v84; // [esp+1Ch] [ebp-60h]
  int v85; // [esp+1Ch] [ebp-60h]
  float v86; // [esp+1Ch] [ebp-60h]
  float v87; // [esp+1Ch] [ebp-60h]
  float v88; // [esp+1Ch] [ebp-60h]
  float v89; // [esp+1Ch] [ebp-60h]
  float v90; // [esp+1Ch] [ebp-60h]
  float v91; // [esp+1Ch] [ebp-60h]
  float v92; // [esp+1Ch] [ebp-60h]
  float v93; // [esp+1Ch] [ebp-60h]
  float v94; // [esp+1Ch] [ebp-60h]
  float v95; // [esp+1Ch] [ebp-60h]
  char v96; // [esp+20h] [ebp-5Ch]
  float v97; // [esp+20h] [ebp-5Ch]
  int v98; // [esp+20h] [ebp-5Ch]
  int v99; // [esp+24h] [ebp-58h]
  int v100; // [esp+24h] [ebp-58h]
  int v101; // [esp+24h] [ebp-58h]
  int v102; // [esp+24h] [ebp-58h]
  int v103; // [esp+24h] [ebp-58h]
  int v104; // [esp+28h] [ebp-54h]
  int v105; // [esp+28h] [ebp-54h]
  int v106; // [esp+28h] [ebp-54h]
  int v107; // [esp+28h] [ebp-54h]
  int v108; // [esp+28h] [ebp-54h]
  int v109; // [esp+28h] [ebp-54h]
  int v110; // [esp+28h] [ebp-54h]
  int v111; // [esp+28h] [ebp-54h]
  int v112; // [esp+2Ch] [ebp-50h]
  float v113; // [esp+34h] [ebp-48h]
  float v114; // [esp+38h] [ebp-44h]
  float v115; // [esp+3Ch] [ebp-40h]
  float v116; // [esp+40h] [ebp-3Ch]
  float v117; // [esp+44h] [ebp-38h]
  int v118; // [esp+48h] [ebp-34h] BYREF
  float v119; // [esp+4Ch] [ebp-30h]
  double v120; // [esp+50h] [ebp-2Ch]
  char Buffer[32]; // [esp+58h] [ebp-24h] BYREF

  v119 = 0.0;
  v113 = 0.0;
  *(float *)&v118 = 0.0;
  v115 = 0.0;
  v116 = 0.0;
  v114 = 0.0;
  v117 = 0.0;
  if ( n8 >= 8 )
  {
    v80 = FFX_Menu2D_ScaleY_1080to416(70.0);
    v58 = FFX_Menu2D_ScaleX_1920to512(1110.0);
    FFX_Menu2D_DrawTexQuadSolid(
      0xFFFFFFFA,
      a2,
      a3,
      v58,
      v80,
      COERCE_INT(0.0),
      COERCE_INT(0.0),
      COERCE_INT(1024.0),
      COERCE_INT(71.0));
    v81 = FFX_Menu2D_ScaleY_1080to416(70.0);
    v59 = FFX_Menu2D_ScaleX_1920to512(415.0);
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(1090.0) + a2;
    FFX_Menu2D_DrawTexQuadSolid(
      0xFFFFFFFD,
      *((float *)&v120 + 1),
      a3,
      v59,
      v81,
      COERCE_INT(689.0),
      COERCE_INT(618.0),
      COERCE_INT(1104.0),
      COERCE_INT(688.0));
    v26 = FFX_Menu2D_ScaleY_1080to416(64.0);
    v16 = FFX_Menu2D_ScaleX_1920to512(250.0);
    sub_8E7D30(a2, *(float *)&a3, v16, v26, 0.0, 64.0, 250.0, 64.0, 50.0, -20.0, (int)&unk_C56870, 449144944);
    v27 = FFX_Menu2D_ScaleY_1080to416(64.0);
    v17 = FFX_Menu2D_ScaleX_1920to512(250.0);
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(250.0) + a2;
    sub_8E7D30(
      *((float *)&v120 + 1),
      *(float *)&a3,
      v17,
      v27,
      250.0,
      64.0,
      250.0,
      64.0,
      50.0,
      -20.0,
      449144944,
      (int)&unk_C56870);
    v28 = FFX_Menu2D_ScaleY_1080to416(64.0);
    v18 = FFX_Menu2D_ScaleX_1920to512(250.0);
    sub_8E7D30(a2, *(float *)&a3, v18, v28, 300.0, 64.0, 250.0, 64.0, -80.0, -10.0, (int)&unk_C56870, 868575344);
    v29 = FFX_Menu2D_ScaleY_1080to416(64.0);
    v19 = FFX_Menu2D_ScaleX_1920to512(250.0);
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(250.0) + a2;
    sub_8E7D30(
      *((float *)&v120 + 1),
      *(float *)&a3,
      v19,
      v29,
      550.0,
      64.0,
      250.0,
      64.0,
      -80.0,
      -10.0,
      868575344,
      (int)&unk_C56870);
  }
  else
  {
    if ( (sub_8A9B10() & (1 << n8)) != 0 )
    {
      v77 = FFX_Menu2D_ScaleY_1080to416(72.0);
      v55 = FFX_Menu2D_ScaleX_1920to512(1110.0);
      FFX_Menu2D_DrawTexQuadSolid(
        0xFFFFFFFD,
        a2,
        a3,
        v55,
        v77,
        COERCE_INT(0.0),
        COERCE_INT(0.0),
        COERCE_INT(1110.0),
        COERCE_INT(72.0));
      v22 = FFX_Menu2D_ScaleY_1080to416(64.0);
      v12 = FFX_Menu2D_ScaleX_1920to512(250.0);
      sub_8E7D30(a2, *(float *)&a3, v12, v22, 0.0, 64.0, 250.0, 64.0, 50.0, -20.0, (int)&unk_C56870, 449144944);
      v23 = FFX_Menu2D_ScaleY_1080to416(64.0);
      v13 = FFX_Menu2D_ScaleX_1920to512(250.0);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(250.0) + a2;
      sub_8E7D30(
        *((float *)&v120 + 1),
        *(float *)&a3,
        v13,
        v23,
        250.0,
        64.0,
        250.0,
        64.0,
        50.0,
        -20.0,
        449144944,
        (int)&unk_C56870);
      v24 = FFX_Menu2D_ScaleY_1080to416(64.0);
      v14 = FFX_Menu2D_ScaleX_1920to512(250.0);
      sub_8E7D30(a2, *(float *)&a3, v14, v24, 300.0, 64.0, 250.0, 64.0, -80.0, -10.0, (int)&unk_C56870, 868575344);
      v25 = FFX_Menu2D_ScaleY_1080to416(64.0);
      v15 = FFX_Menu2D_ScaleX_1920to512(250.0);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(250.0) + a2;
      sub_8E7D30(
        *((float *)&v120 + 1),
        *(float *)&a3,
        v15,
        v25,
        550.0,
        64.0,
        250.0,
        64.0,
        -80.0,
        -10.0,
        868575344,
        (int)&unk_C56870);
    }
    else
    {
      v78 = FFX_Menu2D_ScaleY_1080to416(72.0);
      v56 = FFX_Menu2D_ScaleX_1920to512(1110.0);
      FFX_Menu2D_DrawTexQuadSolid(
        0xFFFFFFFD,
        a2,
        a3,
        v56,
        v78,
        COERCE_INT(0.0),
        COERCE_INT(700.0),
        COERCE_INT(1110.0),
        COERCE_INT(772.0));
    }
    v79 = FFX_Menu2D_ScaleY_1080to416(70.0);
    v57 = FFX_Menu2D_ScaleX_1920to512(415.0);
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(1090.0) + a2;
    FFX_Menu2D_DrawTexQuadSolid(
      0xFFFFFFFD,
      *((float *)&v120 + 1),
      a3,
      v57,
      v79,
      COERCE_INT(689.0),
      COERCE_INT(618.0),
      COERCE_INT(1104.0),
      COERCE_INT(688.0));
  }
  if ( (unsigned int)n8 > 0x11 )
  {
    if ( FFX_Game_GetRegion() == 11 )
    {
      v119 = 22.0;
      v113 = 1.0;
    }
    *((float *)&v120 + 1) = (v113 + 41.0) * 0.0009765625;
    v112 = SHIDWORD(v120);
    *((float *)&v120 + 1) = 0.0009765625 * (v119 + 436.0);
    v108 = SHIDWORD(v120);
    *((float *)&v120 + 1) = v113 + 23.0;
    v89 = FFX_Menu2D_ScaleY_1080to416(*((float *)&v120 + 1));
    *((float *)&v120 + 1) = v119 + 61.5;
    v70 = FFX_Menu2D_ScaleX_1920to512(*((float *)&v120 + 1));
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(7.0) + *(float *)&a3;
    v48 = SHIDWORD(v120);
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(490.0) + a2;
    FFX_Menu2D_DrawTexQuadSolid(
      0x21u,
      *((float *)&v120 + 1),
      v48,
      v70,
      v89,
      COERCE_INT(0.34765625),
      COERCE_INT(0.014648438),
      v108,
      v112);
    *((float *)&v120 + 1) = (v119 + 570.0) * 0.0009765625;
    v109 = SHIDWORD(v120);
    v90 = FFX_Menu2D_ScaleY_1080to416(23.0);
    *((float *)&v120 + 1) = v119 + 49.0;
    v71 = FFX_Menu2D_ScaleX_1920to512(*((float *)&v120 + 1));
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(34.0) + *(float *)&a3;
    v49 = SHIDWORD(v120);
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(540.0) + a2;
    FFX_Menu2D_DrawTexQuadSolid(
      0x22u,
      *((float *)&v120 + 1),
      v49,
      v71,
      v90,
      COERCE_INT(0.49804688),
      COERCE_INT(0.014648438),
      v109,
      COERCE_INT(0.040039062));
    v91 = FFX_Menu2D_ScaleY_1080to416(28.0);
    v72 = FFX_Menu2D_ScaleX_1920to512(384.0);
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(2.0) + *(float *)&a3;
    v50 = SHIDWORD(v120);
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(1096.0) + a2;
    FFX_Menu2D_DrawTexQuadSolid(
      0xC8u,
      *((float *)&v120 + 1),
      v50,
      v72,
      v91,
      COERCE_INT(0.3671875),
      COERCE_INT(0.12402344),
      COERCE_INT(0.7421875),
      COERCE_INT(0.15234375));
    v92 = FFX_Menu2D_ScaleY_1080to416(33.0);
    v73 = FFX_Menu2D_ScaleX_1920to512(208.0);
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(28.0) + *(float *)&a3;
    v51 = SHIDWORD(v120);
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(842.0) + a2;
    FFX_Menu2D_DrawTexQuadSolid(
      0xFFFFFFFF,
      *((float *)&v120 + 1),
      v51,
      v73,
      v92,
      COERCE_INT(0.0),
      COERCE_INT(603.0),
      COERCE_INT(208.0),
      COERCE_INT(636.0));
    v93 = FFX_Menu2D_ScaleY_1080to416(75.0);
    v74 = FFX_Menu2D_ScaleX_1920to512(75.0);
    *((float *)&v120 + 1) = *(float *)&a3 - FFX_Menu2D_ScaleY_1080to416(5.0);
    v52 = SHIDWORD(v120);
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(1034.0) + a2;
    FFX_Menu2D_DrawTexQuadSolid(
      0x3Du,
      *((float *)&v120 + 1),
      v52,
      v74,
      v93,
      COERCE_INT(0.48632812),
      COERCE_INT(0.58886719),
      COERCE_INT(0.55957031),
      COERCE_INT(0.66210938));
    if ( FFX_Game_GetRegion() == 11 )
    {
      v115 = -35.0;
      v116 = 20.0;
      v114 = -10.0;
      v117 = 20.0;
    }
    *((float *)&v120 + 1) = (v116 + 978.0) * 0.0009765625;
    v110 = SHIDWORD(v120);
    *((float *)&v120 + 1) = 0.0009765625 * (v115 + 834.0);
    v98 = SHIDWORD(v120);
    v94 = FFX_Menu2D_ScaleY_1080to416(26.0);
    *((float *)&v120 + 1) = v117 + 117.0;
    v75 = FFX_Menu2D_ScaleX_1920to512(*((float *)&v120 + 1));
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(35.0) + *(float *)&a3;
    v53 = SHIDWORD(v120);
    *((float *)&v120 + 1) = v114 + 948.0;
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(*((float *)&v120 + 1)) + a2;
    FFX_Menu2D_DrawTexQuadSolid(
      0x3Du,
      *((float *)&v120 + 1),
      v53,
      v75,
      v94,
      v98,
      COERCE_INT(0.08203125),
      v110,
      COERCE_INT(0.11328125));
    *((float *)&v120 + 1) = (v119 + 434.0) * 0.0009765625;
    v111 = SHIDWORD(v120);
    v95 = FFX_Menu2D_ScaleY_1080to416(28.0);
    *((float *)&v120 + 1) = v119 + 55.0;
    v76 = FFX_Menu2D_ScaleX_1920to512(*((float *)&v120 + 1));
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(34.0) + *(float *)&a3;
    v54 = SHIDWORD(v120);
    *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(1348.0) + a2;
    return FFX_Menu2D_DrawTexQuadSolid(
             0xC8u,
             *((float *)&v120 + 1),
             v54,
             v76,
             v95,
             COERCE_INT(0.37304688),
             COERCE_INT(0.075195312),
             v111,
             COERCE_INT(0.10253906));
  }
  else
  {
    if ( n8 < 8 || (int)sub_8A9870(n8) > 0 )
    {
      v96 = sub_8A9A20(n8);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(9.0) + *(float *)&a3;
      v82 = *((float *)&v120 + 1);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(160.0) + a2;
      v3 = sub_8AC800(n8);
      FFX_Menu2D_DrawStatusEffectTimerBar(v3, *((float *)&v120 + 1), v82, v96, 0.81999999, COERCE_INT(1.0));
      if ( FFX_Game_GetRegion() == 11 )
      {
        v119 = 22.0;
        v113 = 1.0;
        *(float *)&v118 = 11.0;
      }
      *((float *)&v120 + 1) = (v113 + 41.0) * 0.0009765625;
      v104 = SHIDWORD(v120);
      *((float *)&v120 + 1) = 0.0009765625 * (v119 + 436.0);
      v99 = SHIDWORD(v120);
      *((float *)&v120 + 1) = v113 + 23.0;
      v60 = FFX_Menu2D_ScaleY_1080to416(*((float *)&v120 + 1));
      *((float *)&v120 + 1) = v119 + 61.5;
      v41 = FFX_Menu2D_ScaleX_1920to512(*((float *)&v120 + 1));
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(7.0) + *(float *)&a3;
      v32 = SHIDWORD(v120);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(490.0) + a2;
      FFX_Menu2D_DrawTexQuadSolid(
        0x21u,
        *((float *)&v120 + 1),
        v32,
        v41,
        v60,
        COERCE_INT(0.34765625),
        COERCE_INT(0.014648438),
        v99,
        v104);
      v105 = sub_8A9940(n8);
      v4 = sub_8A9870(n8);
      sprintf(Buffer, "%5d/%5d", v4, v105);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(8.0) + *(float *)&a3;
      v83 = *((float *)&v120 + 1);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(604.0) + a2 + *(float *)&v118;
      FFX_Menu2D_DrawIconOrTimer((int)Buffer, *((float *)&v120 + 1), v83, 37, 0.68000001, 0.0);
      *((float *)&v120 + 1) = (v119 + 570.0) * 0.0009765625;
      v100 = SHIDWORD(v120);
      v61 = FFX_Menu2D_ScaleY_1080to416(23.0);
      *((float *)&v120 + 1) = v119 + 49.0;
      v42 = FFX_Menu2D_ScaleX_1920to512(*((float *)&v120 + 1));
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(34.0) + *(float *)&a3;
      v33 = SHIDWORD(v120);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(540.0) + a2;
      FFX_Menu2D_DrawTexQuadSolid(
        0x22u,
        *((float *)&v120 + 1),
        v33,
        v42,
        v61,
        COERCE_INT(0.49804688),
        COERCE_INT(0.014648438),
        v100,
        COERCE_INT(0.040039062));
      v106 = sub_8A9960(n8);
      v5 = sub_8A9920(n8);
      sprintf(Buffer, "%4d/%4d", v5, v106);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(36.0) + *(float *)&a3;
      v84 = *((float *)&v120 + 1);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(625.0) + a2 + *(float *)&v118;
      FFX_Menu2D_DrawIconOrTimer((int)Buffer, *((float *)&v120 + 1), v84, 37, 0.68000001, 0.0);
    }
    else
    {
      sub_8CEAD0((int)a2, (int)*(float *)&a3, n8);
    }
    if ( n8 >= 8 )
    {
      v39 = FFX_Menu2D_ScaleY_1080to416(32.0);
      v30 = FFX_Menu2D_ScaleX_1920to512(332.0);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(4.0) + *(float *)&a3;
      v20 = SHIDWORD(v120);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(1102.0) + a2;
      FFX_Menu2D_DrawTexQuadTinted(
        0xFFFFFFFF,
        *((float *)&v120 + 1),
        v20,
        v30,
        v39,
        COERCE_INT(274.0),
        COERCE_INT(61.0),
        COERCE_INT(606.0),
        COERCE_INT(93.0),
        0x80808080,
        0x80808080);
      v40 = FFX_Menu2D_ScaleY_1080to416(24.0);
      v31 = FFX_Menu2D_ScaleX_1920to512(201.0);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(8.0) + *(float *)&a3;
      v21 = SHIDWORD(v120);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(1136.0) + a2;
      FFX_Menu2D_DrawTexQuadTinted(
        0x190u,
        *((float *)&v120 + 1),
        v21,
        v31,
        v40,
        COERCE_INT(0.0625),
        COERCE_INT(0.45605469),
        COERCE_INT(0.33496094),
        COERCE_INT(0.4921875),
        0x80808080,
        0x80808080);
      v107 = sub_8A9900(n8);
      v103 = sub_8A98E0(n8);
      v97 = FFX_Menu2D_ScaleY_1080to416(8.0);
      v88 = FFX_Menu2D_ScaleX_1920to512(350.0);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(40.0) + *(float *)&a3;
      v69 = *((float *)&v120 + 1);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(1130.0) + a2;
      return sub_8D3660(*((float *)&v120 + 1), v69, v88, v97, v103, v107);
    }
    else
    {
      v62 = FFX_Menu2D_ScaleY_1080to416(28.0);
      v43 = FFX_Menu2D_ScaleX_1920to512(384.0);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(2.0) + *(float *)&a3;
      v34 = SHIDWORD(v120);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(1096.0) + a2;
      FFX_Menu2D_DrawTexQuadSolid(
        0xC8u,
        *((float *)&v120 + 1),
        v34,
        v43,
        v62,
        COERCE_INT(0.3671875),
        COERCE_INT(0.12402344),
        COERCE_INT(0.7421875),
        COERCE_INT(0.15234375));
      v63 = FFX_Menu2D_ScaleY_1080to416(33.0);
      v44 = FFX_Menu2D_ScaleX_1920to512(208.0);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(28.0) + *(float *)&a3;
      v35 = SHIDWORD(v120);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(844.0) + a2;
      FFX_Menu2D_DrawTexQuadSolid(
        0xFFFFFFFF,
        *((float *)&v120 + 1),
        v35,
        v44,
        v63,
        COERCE_INT(0.0),
        COERCE_INT(603.0),
        COERCE_INT(208.0),
        COERCE_INT(636.0));
      v64 = FFX_Menu2D_ScaleY_1080to416(75.0);
      v45 = FFX_Menu2D_ScaleX_1920to512(75.0);
      v120 = *(float *)&a3;
      *((float *)&v120 + 1) = *(float *)&a3 - FFX_Menu2D_ScaleY_1080to416(3.0);
      v36 = SHIDWORD(v120);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(1038.0) + a2;
      FFX_Menu2D_DrawTexQuadSolid(
        0x3Du,
        *((float *)&v120 + 1),
        v36,
        v45,
        v64,
        COERCE_INT(0.48632812),
        COERCE_INT(0.58886719),
        COERCE_INT(0.55957031),
        COERCE_INT(0.66210938));
      if ( FFX_Game_GetRegion() == 11 )
      {
        v115 = -35.0;
        v116 = 20.0;
        v114 = -10.0;
        v117 = 25.0;
      }
      *((float *)&v120 + 1) = (v116 + 978.0) * 0.0009765625;
      v101 = SHIDWORD(v120);
      *((float *)&v120 + 1) = 0.0009765625 * (v115 + 834.0);
      v85 = SHIDWORD(v120);
      v65 = FFX_Menu2D_ScaleY_1080to416(26.0);
      *((float *)&v120 + 1) = v117 + 117.0;
      v46 = FFX_Menu2D_ScaleX_1920to512(*((float *)&v120 + 1));
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(35.0) + *(float *)&a3;
      v37 = SHIDWORD(v120);
      *((float *)&v120 + 1) = v114 + 952.0;
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(*((float *)&v120 + 1)) + a2;
      FFX_Menu2D_DrawTexQuadSolid(
        0x3Du,
        *((float *)&v120 + 1),
        v37,
        v46,
        v65,
        v85,
        COERCE_INT(0.08203125),
        v101,
        COERCE_INT(0.11328125));
      v6 = sub_8A9B30(n8);
      sub_905230(v6, (int)&v118, 0.68000001, 0.0);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(16.0) + *(float *)&a3;
      v86 = *((float *)&v120 + 1);
      v7 = FFX_Menu2D_ScaleX_1920to512(1076.0);
      *((float *)&v120 + 1) = v7 + a2 - *(float *)&v118 * 0.5;
      v66 = *((float *)&v120 + 1);
      v8 = sub_8A9B30(n8);
      sub_905820(v8, v66, v86, 0, 0.68000001, 0.0);
      *((float *)&v120 + 1) = (v119 + 434.0) * 0.0009765625;
      v102 = SHIDWORD(v120);
      v67 = FFX_Menu2D_ScaleY_1080to416(28.0);
      *((float *)&v120 + 1) = v119 + 55.0;
      v47 = FFX_Menu2D_ScaleX_1920to512(*((float *)&v120 + 1));
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(34.0) + *(float *)&a3;
      v38 = SHIDWORD(v120);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(1348.0) + a2;
      FFX_Menu2D_DrawTexQuadSolid(
        0xC8u,
        *((float *)&v120 + 1),
        v38,
        v47,
        v67,
        COERCE_INT(0.37304688),
        COERCE_INT(0.075195312),
        v102,
        COERCE_INT(0.10253906));
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleY_1080to416(28.0) + *(float *)&a3;
      v87 = *((float *)&v120 + 1);
      *((float *)&v120 + 1) = FFX_Menu2D_ScaleX_1920to512(1333.0) + a2;
      v68 = *((float *)&v120 + 1);
      v9 = FFX_Btl_Od_ComputeChargeLevelThreshold(n8);
      v10 = sub_785370(n8);
      return sub_9055C0(v9 - v10, v68, v87, 37, 0.68000001, 0.0);
    }
  }
}
