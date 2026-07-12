// Function: FFX_BtlUI_DrawScanTargetInfoPanel
// Address: 0x8939a0
void __usercall FFX_BtlUI_DrawScanTargetInfoPanel(double a1@<st0>, int a2, int n179, int n240)
{
  double v4; // st7
  int v5; // ebx
  double v6; // st7
  int ActorCtbGaugeCurrent; // eax
  int ActorCtbTurns; // eax
  double v9; // st7
  double v10; // st6
  double v11; // st5
  double v12; // st4
  double v13; // st7
  double v14; // st7
  char v15; // al
  double v16; // st6
  double v17; // st5
  double v18; // st4
  double v19; // st3
  double v20; // st7
  double v21; // st6
  float v22; // [esp+4h] [ebp-54h]
  float v23; // [esp+4h] [ebp-54h]
  float v24; // [esp+4h] [ebp-54h]
  float v25; // [esp+4h] [ebp-54h]
  int v26; // [esp+8h] [ebp-50h]
  int v27; // [esp+8h] [ebp-50h]
  float v28; // [esp+Ch] [ebp-4Ch]
  float v29; // [esp+Ch] [ebp-4Ch]
  float v30; // [esp+10h] [ebp-48h]
  int v31; // [esp+10h] [ebp-48h]
  int v32; // [esp+10h] [ebp-48h]
  int v33; // [esp+10h] [ebp-48h]
  int v34; // [esp+10h] [ebp-48h]
  int v35; // [esp+10h] [ebp-48h]
  int v36; // [esp+10h] [ebp-48h]
  float v37; // [esp+10h] [ebp-48h]
  float v38; // [esp+10h] [ebp-48h]
  float v39; // [esp+14h] [ebp-44h]
  float v40; // [esp+14h] [ebp-44h]
  float v41; // [esp+14h] [ebp-44h]
  float v42; // [esp+14h] [ebp-44h]
  float v43; // [esp+14h] [ebp-44h]
  float v44; // [esp+14h] [ebp-44h]
  float v45; // [esp+14h] [ebp-44h]
  float v46; // [esp+14h] [ebp-44h]
  float v47; // [esp+14h] [ebp-44h]
  float v48; // [esp+14h] [ebp-44h]
  float v49; // [esp+14h] [ebp-44h]
  int v50; // [esp+14h] [ebp-44h]
  float v51; // [esp+18h] [ebp-40h]
  float v52; // [esp+18h] [ebp-40h]
  float v53; // [esp+18h] [ebp-40h]
  float v54; // [esp+18h] [ebp-40h]
  float v55; // [esp+18h] [ebp-40h]
  float v56; // [esp+18h] [ebp-40h]
  float v57; // [esp+18h] [ebp-40h]
  float v58; // [esp+18h] [ebp-40h]
  float v59; // [esp+18h] [ebp-40h]
  float v60; // [esp+18h] [ebp-40h]
  float v61; // [esp+18h] [ebp-40h]
  float v62; // [esp+18h] [ebp-40h]
  float v63; // [esp+18h] [ebp-40h]
  int v64; // [esp+1Ch] [ebp-3Ch]
  float v65; // [esp+1Ch] [ebp-3Ch]
  float v66; // [esp+1Ch] [ebp-3Ch]
  float v67; // [esp+1Ch] [ebp-3Ch]
  int v68; // [esp+1Ch] [ebp-3Ch]
  int v69; // [esp+1Ch] [ebp-3Ch]
  float v70; // [esp+20h] [ebp-38h]
  int v71; // [esp+20h] [ebp-38h]
  int v72; // [esp+20h] [ebp-38h]
  int v73; // [esp+24h] [ebp-34h]
  int v74; // [esp+24h] [ebp-34h]
  int v75; // [esp+24h] [ebp-34h]
  unsigned int v76; // [esp+24h] [ebp-34h]
  float v77; // [esp+28h] [ebp-30h]
  int v78; // [esp+28h] [ebp-30h]
  int v79; // [esp+28h] [ebp-30h]
  int v80; // [esp+28h] [ebp-30h]
  float v81; // [esp+28h] [ebp-30h]
  float v82; // [esp+28h] [ebp-30h]
  int v83; // [esp+3Ch] [ebp-1Ch]
  float v84; // [esp+3Ch] [ebp-1Ch]
  int v85; // [esp+3Ch] [ebp-1Ch]
  float v86; // [esp+3Ch] [ebp-1Ch]
  int v87; // [esp+3Ch] [ebp-1Ch]
  float v88; // [esp+3Ch] [ebp-1Ch]
  int v89; // [esp+3Ch] [ebp-1Ch]
  float v90; // [esp+3Ch] [ebp-1Ch]
  int v91; // [esp+3Ch] [ebp-1Ch]
  float v92; // [esp+3Ch] [ebp-1Ch]
  int v93; // [esp+3Ch] [ebp-1Ch]
  float v94; // [esp+3Ch] [ebp-1Ch]
  float v95; // [esp+3Ch] [ebp-1Ch]
  float v96; // [esp+3Ch] [ebp-1Ch]
  float v97; // [esp+3Ch] [ebp-1Ch]
  float v98; // [esp+3Ch] [ebp-1Ch]
  float v99; // [esp+3Ch] [ebp-1Ch]
  float v100; // [esp+3Ch] [ebp-1Ch]
  float v101; // [esp+3Ch] [ebp-1Ch]
  float v102; // [esp+3Ch] [ebp-1Ch]
  float v103; // [esp+40h] [ebp-18h]
  float v104; // [esp+40h] [ebp-18h]
  float v105; // [esp+44h] [ebp-14h]
  float v106; // [esp+44h] [ebp-14h]
  float v107; // [esp+44h] [ebp-14h]
  float v108; // [esp+44h] [ebp-14h]
  float v109; // [esp+44h] [ebp-14h]
  float v110; // [esp+44h] [ebp-14h]
  float v111; // [esp+44h] [ebp-14h]
  float v112; // [esp+44h] [ebp-14h]
  float v113; // [esp+44h] [ebp-14h]
  float v114; // [esp+44h] [ebp-14h]
  float v115; // [esp+44h] [ebp-14h]
  float v116; // [esp+44h] [ebp-14h]
  float v117; // [esp+44h] [ebp-14h]
  float v118; // [esp+44h] [ebp-14h]
  float v119; // [esp+44h] [ebp-14h]
  float v120; // [esp+44h] [ebp-14h]
  float v121; // [esp+48h] [ebp-10h]
  float v122; // [esp+48h] [ebp-10h]
  float n240_1; // [esp+4Ch] [ebp-Ch]
  int v124; // [esp+4Ch] [ebp-Ch]
  int v125; // [esp+4Ch] [ebp-Ch]
  float v126; // [esp+50h] [ebp-8h]
  char ActorElemResist_5DC; // [esp+53h] [ebp-5h]
  char ActorElemIgnore_5DB; // [esp+55h] [ebp-3h]
  char ActorElemAbsorb_5DA; // [esp+56h] [ebp-2h]
  char ActorElemWeak_5DD; // [esp+57h] [ebp-1h]
  char v131; // [esp+57h] [ebp-1h]

  if ( unk_133C8FE && unk_133D6A0 != 1 )
  {
    FFX_Engine_GetTime();
    v103 = a1 - unk_133C904;
    v104 = v103 / 0.2000000029802322;
    if ( v104 >= 0.0 )
    {
      if ( v104 <= 1.0 )
        v4 = v104;
      else
        v4 = (float)1.0;
    }
    else
    {
      v4 = (float)0.0;
    }
    v105 = (float)(n179 + 385);
    v5 = (int)(v4 * v105 - 385.0);
    v106 = FFX_Menu2D_ScaleY_1080to416(51.0) + 6.0;
    ActorElemWeak_5DD = FFX_GetActorElemWeak_5DD(a2);
    ActorElemAbsorb_5DA = FFX_GetActorElemAbsorb_5DA(a2);
    ActorElemIgnore_5DB = FFX_GetActorElemIgnore_5DB(a2);
    v6 = 43.0;
    ActorElemResist_5DC = FFX_GetActorElemResist_5DC(a2);
    if ( ActorElemWeak_5DD )
    {
      v106 = FFX_Menu2D_ScaleY_1080to416(43.0) + v106;
      v6 = 43.0;
    }
    if ( ActorElemAbsorb_5DA )
    {
      v77 = v6;
      v106 = FFX_Menu2D_ScaleY_1080to416(v77) + v106;
    }
    if ( ActorElemIgnore_5DB )
      v106 = FFX_Menu2D_ScaleY_1080to416(43.0) + v106;
    if ( ActorElemResist_5DC )
      v106 = FFX_Menu2D_ScaleY_1080to416(43.0) + v106;
    if ( unk_133F586 > 0 )
      v106 = FFX_Menu2D_ScaleY_1080to416(43.0) + v106;
    sub_8F9230(0, 0, 512, 416);
    v121 = (float)v5;
    v122 = FFX_Menu2D_ScaleX_1920to512(v121);
    n240_1 = (float)n240;
    *(float *)&v124 = FFX_Menu2D_ScaleY_1080to416(n240_1);
    v70 = FFX_Menu2D_ScaleX_1920to512(385.0);
    FFX_Menu2D_DrawRoundedPanel9Slice(v122, v124, v70, v106, 0);
    if ( FFX_Game_GetRegion() == 11 )
    {
      *(float *)&v78 = 0.041015625;
      *(float *)&v73 = 0.44433594;
      *(float *)&v71 = 0.01171875;
      *(float *)&v64 = 0.36132812;
      v51 = FFX_Menu2D_ScaleY_1080to416(30.0);
      v39 = FFX_Menu2D_ScaleX_1920to512(85.0);
      v107 = FFX_Menu2D_ScaleY_1080to416(18.0) + *(float *)&v124 - 3.0;
      v30 = v107;
      v108 = FFX_Menu2D_ScaleX_1920to512(24.0) + v122 + 0.0;
    }
    else
    {
      *(float *)&v78 = 0.040039062;
      *(float *)&v73 = 0.42578125;
      *(float *)&v71 = 0.014648438;
      *(float *)&v64 = 0.34765625;
      v51 = FFX_Menu2D_ScaleY_1080to416(23.0);
      v39 = FFX_Menu2D_ScaleX_1920to512(61.5);
      v109 = FFX_Menu2D_ScaleY_1080to416(18.0) + *(float *)&v124;
      v30 = v109;
      v108 = FFX_Menu2D_ScaleX_1920to512(24.0) + v122;
    }
    FFX_Menu2D_DrawTexQuadSolid(0xE9u, v108, SLODWORD(v30), v39, v51, v64, v71, v73, v78);
    v110 = FFX_Menu2D_ScaleY_1080to416(13.0) + *(float *)&v124;
    v65 = v110;
    v111 = FFX_Menu2D_ScaleX_1920to512(210.0) + v122;
    ActorCtbGaugeCurrent = FFX_Btl_GetActorCtbGaugeCurrent(a2);
    sub_9055C0(ActorCtbGaugeCurrent, v111, v65, 0, 0.60000002, 0.0);
    v112 = FFX_Menu2D_ScaleY_1080to416(22.0) + *(float *)&v124;
    v66 = v112;
    v113 = FFX_Menu2D_ScaleX_1920to512(215.0) + v122;
    FFX_Menu2D_DrawIconOrTimer((int)word_B8F87C, v113, v66, 0, 0.60000002, 0.0);
    v114 = FFX_Menu2D_ScaleY_1080to416(13.0) + *(float *)&v124;
    v67 = v114;
    v115 = FFX_Menu2D_ScaleX_1920to512(360.0) + v122;
    ActorCtbTurns = FFX_Btl_GetActorCtbTurns(a2);
    sub_9055C0(ActorCtbTurns, v115, v67, 0, 0.60000002, 0.0);
    *(float *)&v125 = FFX_Menu2D_ScaleY_1080to416(55.0) + *(float *)&v124;
    v9 = 50.0;
    v10 = 1680.0;
    v11 = 1330.0;
    v12 = 42.0;
    if ( ActorElemWeak_5DD )
    {
      v52 = FFX_Menu2D_ScaleY_1080to416(42.0);
      v40 = FFX_Menu2D_ScaleX_1920to512(380.0);
      v116 = FFX_Menu2D_ScaleX_1920to512(10.0) + v122;
      FFX_Menu2D_DrawTexQuadSolid(
        0xFFFFFFFF,
        v116,
        v125,
        v40,
        v52,
        COERCE_INT(1330.0),
        COERCE_INT(0.0),
        COERCE_INT(1680.0),
        COERCE_INT(50.0));
      FFX_BtlUI_DrawScanElementResistRow_4ElemHardcoded(a2, 0, (int)v122, (int)*(float *)&v125);
      *(float *)&v125 = FFX_Menu2D_ScaleY_1080to416(43.0) + *(float *)&v125;
      v9 = 50.0;
      v10 = 1680.0;
      v11 = 1330.0;
      v12 = 42.0;
    }
    if ( ActorElemAbsorb_5DA )
    {
      *(float *)&v79 = v9;
      *(float *)&v74 = v10;
      *(float *)&v68 = v11;
      v53 = v12;
      v54 = FFX_Menu2D_ScaleY_1080to416(v53);
      v41 = FFX_Menu2D_ScaleX_1920to512(380.0);
      v117 = FFX_Menu2D_ScaleX_1920to512(10.0) + v122;
      FFX_Menu2D_DrawTexQuadSolid(0xFFFFFFFF, v117, v125, v41, v54, v68, COERCE_INT(0.0), v74, v79);
      FFX_BtlUI_DrawScanElementResistRow_4ElemHardcoded(a2, 1, (int)v122, (int)*(float *)&v125);
      v13 = FFX_Menu2D_ScaleY_1080to416(43.0) + *(float *)&v125;
      *(float *)&v125 = v13;
    }
    else
    {
      v13 = v12;
    }
    if ( ActorElemIgnore_5DB )
    {
      v55 = FFX_Menu2D_ScaleY_1080to416(42.0);
      v42 = FFX_Menu2D_ScaleX_1920to512(380.0);
      v118 = FFX_Menu2D_ScaleX_1920to512(10.0) + v122;
      FFX_Menu2D_DrawTexQuadSolid(
        0xFFFFFFFF,
        v118,
        v125,
        v42,
        v55,
        COERCE_INT(1330.0),
        COERCE_INT(0.0),
        COERCE_INT(1680.0),
        COERCE_INT(50.0));
      FFX_BtlUI_DrawScanElementResistRow_4ElemHardcoded(a2, 2, (int)v122, (int)*(float *)&v125);
      v13 = FFX_Menu2D_ScaleY_1080to416(43.0) + *(float *)&v125;
      *(float *)&v125 = v13;
    }
    if ( ActorElemResist_5DC )
    {
      v56 = FFX_Menu2D_ScaleY_1080to416(42.0);
      v43 = FFX_Menu2D_ScaleX_1920to512(380.0);
      v119 = FFX_Menu2D_ScaleX_1920to512(10.0) + v122;
      FFX_Menu2D_DrawTexQuadSolid(
        0xFFFFFFFF,
        v119,
        v125,
        v43,
        v56,
        COERCE_INT(1330.0),
        COERCE_INT(0.0),
        COERCE_INT(1680.0),
        COERCE_INT(50.0));
      v131 = FFX_GetActorElemResist_5DC(a2);
      v120 = (float)(int)*(float *)&v125;
      v126 = (float)(int)v122;
      v57 = FFX_Menu2D_ScaleY_1080to416(26.0);
      v44 = FFX_Menu2D_ScaleX_1920to512(75.0);
      *(float *)&v83 = FFX_Menu2D_ScaleY_1080to416(6.0) + v120;
      v31 = v83;
      v84 = FFX_Menu2D_ScaleX_1920to512(25.0) + v126;
      FFX_Menu2D_DrawTexQuadSolid(
        0x1B2u,
        v84,
        v31,
        v44,
        v57,
        COERCE_INT(0.41894531),
        COERCE_INT(0.88671875),
        COERCE_INT(0.51269531),
        COERCE_INT(0.92578125));
      v58 = FFX_Menu2D_ScaleY_1080to416(35.700001);
      v45 = FFX_Menu2D_ScaleX_1920to512(225.0);
      *(float *)&v85 = FFX_Menu2D_ScaleY_1080to416(2.0) + v120;
      v32 = v85;
      v86 = FFX_Menu2D_ScaleX_1920to512(125.0) + v126;
      FFX_Menu2D_DrawTexQuadSolid(
        0x1AFu,
        v86,
        v32,
        v45,
        v58,
        COERCE_INT(0.22460938),
        COERCE_INT(0.94921875),
        COERCE_INT(0.46582031),
        COERCE_INT(0.98828125));
      v14 = 0.98632812;
      v15 = v131;
      v16 = 0.58007812;
      v17 = 0.95117188;
      v18 = 0.54394531;
      v19 = 32.700001;
      if ( (v131 & 1) == 0 )
      {
        v59 = FFX_Menu2D_ScaleY_1080to416(32.700001);
        v46 = FFX_Menu2D_ScaleX_1920to512(32.700001);
        *(float *)&v87 = FFX_Menu2D_ScaleY_1080to416(4.0) + v120;
        v33 = v87;
        v88 = FFX_Menu2D_ScaleX_1920to512(125.0) + v126;
        FFX_Menu2D_DrawTexQuadSolid(
          0x1AFu,
          v88,
          v33,
          v46,
          v59,
          COERCE_INT(0.54394531),
          COERCE_INT(0.95117188),
          COERCE_INT(0.58007812),
          COERCE_INT(0.98632812));
        v15 = v131;
        v14 = 0.98632812;
        v16 = 0.58007812;
        v18 = 0.54394531;
        v19 = 32.700001;
        v17 = 0.95117188;
      }
      if ( (v15 & 4) == 0 )
      {
        *(float *)&v80 = v14;
        *(float *)&v75 = v16;
        *(float *)&v72 = v17;
        *(float *)&v69 = v18;
        v60 = v19;
        v61 = FFX_Menu2D_ScaleY_1080to416(v60);
        v47 = FFX_Menu2D_ScaleX_1920to512(32.700001);
        *(float *)&v89 = FFX_Menu2D_ScaleY_1080to416(4.0) + v120;
        v34 = v89;
        v90 = FFX_Menu2D_ScaleX_1920to512(188.0) + v126;
        FFX_Menu2D_DrawTexQuadSolid(0x1AFu, v90, v34, v47, v61, v69, v72, v75, v80);
        v15 = v131;
      }
      if ( (v15 & 8) == 0 )
      {
        v62 = FFX_Menu2D_ScaleY_1080to416(32.700001);
        v48 = FFX_Menu2D_ScaleX_1920to512(32.700001);
        *(float *)&v91 = FFX_Menu2D_ScaleY_1080to416(4.0) + v120;
        v35 = v91;
        v92 = FFX_Menu2D_ScaleX_1920to512(251.0) + v126;
        FFX_Menu2D_DrawTexQuadSolid(
          0x1AFu,
          v92,
          v35,
          v48,
          v62,
          COERCE_INT(0.54394531),
          COERCE_INT(0.95117188),
          COERCE_INT(0.58007812),
          COERCE_INT(0.98632812));
        v15 = v131;
      }
      if ( (v15 & 2) == 0 )
      {
        v63 = FFX_Menu2D_ScaleY_1080to416(32.700001);
        v49 = FFX_Menu2D_ScaleX_1920to512(32.700001);
        *(float *)&v93 = FFX_Menu2D_ScaleY_1080to416(4.0) + v120;
        v36 = v93;
        v94 = FFX_Menu2D_ScaleX_1920to512(316.0) + v126;
        FFX_Menu2D_DrawTexQuadSolid(
          0x1AFu,
          v94,
          v36,
          v49,
          v63,
          COERCE_INT(0.54394531),
          COERCE_INT(0.95117188),
          COERCE_INT(0.58007812),
          COERCE_INT(0.98632812));
      }
      v13 = FFX_Menu2D_ScaleY_1080to416(43.0) + *(float *)&v125;
      *(float *)&v125 = v13;
    }
    if ( unk_133F586 > 0 )
    {
      v13 = *(float *)&v125 + 2.0;
      FFX_BtlUI_DrawScanStatusRow(a2, (int)v122, (int)v13);
    }
    FFX_Engine_GetTime();
    v81 = v13;
    v95 = (float)(n240 - 46);
    v22 = v95;
    v96 = (float)(v5 - 33);
    sub_902EF0(-1, v96, v22, 68.0, 68.0, 1.0, 53.0, 101.0, 153.0, -2139062144, -2139062144, v81);
    FFX_Engine_GetTime();
    v82 = -v96;
    v97 = (float)(n240 - 39);
    v23 = v97;
    v98 = (float)(v5 - 26);
    sub_902EF0(-1, v98, v23, 54.0, 54.0, 1759.0, 1.0, 1835.0, 77.0, -2139062144, -2139062144, v82);
    if ( v104 >= 0.0 )
    {
      if ( v104 <= 1.0 )
      {
        v21 = v104;
        v20 = 0.0;
      }
      else
      {
        v20 = 0.0;
        v21 = (float)1.0;
      }
    }
    else
    {
      v20 = 0.0;
      v21 = (float)0.0;
    }
    *(float *)&v50 = v20;
    v37 = FFX_Menu2D_ScaleY_1080to416(149.0);
    v28 = FFX_Menu2D_ScaleX_1920to512(477.0);
    v99 = (float)(n240 - 86);
    *(float *)&v26 = FFX_Menu2D_ScaleY_1080to416(v99);
    v100 = (float)(v5 - 73);
    v24 = FFX_Menu2D_ScaleX_1920to512(v100);
    FFX_Menu2D_DrawTexQuadTinted(
      0x190u,
      v24,
      v26,
      v28,
      v37,
      v50,
      COERCE_INT(0.69628906),
      COERCE_INT(0.46484375),
      COERCE_INT(0.84179688),
      ((unsigned int)(__int64)(v21 * 128.0) << 24) + 8421504,
      ((unsigned int)(__int64)(v21 * 128.0) << 24) + 8421504);
    v76 = ((unsigned int)(__int64)(v21 * 128.0) << 24) + 8421504;
    v38 = FFX_Menu2D_ScaleY_1080to416(25.0);
    v29 = FFX_Menu2D_ScaleX_1920to512(83.0);
    v101 = (float)(n240 - 25);
    *(float *)&v27 = FFX_Menu2D_ScaleY_1080to416(v101);
    v102 = (float)(v5 - 4);
    v25 = FFX_Menu2D_ScaleX_1920to512(v102);
    FFX_Menu2D_DrawTexQuadTinted(
      0x190u,
      v25,
      v27,
      v29,
      v38,
      COERCE_INT(0.46582031),
      COERCE_INT(0.21582031),
      COERCE_INT(0.56347656),
      COERCE_INT(0.24511719),
      v76,
      v76);
  }
}
