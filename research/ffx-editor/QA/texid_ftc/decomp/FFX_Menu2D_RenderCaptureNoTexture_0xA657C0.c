// FFX Menu2D: Render capture no texture
// Menu2D render capture without texture. Part of the 2D UI rendering pipeline. Uses FFX_BattleContext batch arrays (m_batchRenderArray1-4) and texture name arrays.
int __cdecl FFX_Menu2D_RenderCaptureNoTexture(int a1, int p_n4)
{
  int p_n4_1; // esi
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // edx
  unsigned __int8 *v6; // edx
  int v7; // ecx
  float *v8; // eax
  unsigned __int8 *v9; // edi
  double v10; // st7
  void *hudContext_1; // edx
  FFX_CharacterId charId; // ecx
  double b_16; // st7
  int v14; // eax
  double b_2; // st6
  double v16; // st5
  float *v17; // ebx
  float *v18; // esi
  int v19; // edi
  bool v20; // zf
  double b_3; // st7
  int v22; // edx
  double v23; // st7
  __int16 *v24; // ecx
  double v25; // st6
  double v26; // st5
  double v27; // st4
  double v28; // st3
  __int16 *hudContext_2; // edx
  FFX_CharacterId charId_1; // ecx
  int v31; // eax
  double v32; // st2
  double v33; // st4
  int v34; // eax
  double v35; // st2
  double v36; // st3
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  double v41; // st7
  float b_4; // eax
  double v43; // st7
  float b_5; // eax
  double v45; // st7
  float b_6; // eax
  double v47; // st7
  float b_7; // eax
  double v49; // st7
  double v50; // st7
  float b_8; // eax
  double v52; // st7
  float b_9; // eax
  double v54; // st7
  float b_10; // eax
  double v56; // st7
  float b_11; // eax
  double v58; // st7
  float b_12; // eax
  double v60; // st7
  void *hudContext_3; // edx
  FFX_CharacterId charId_2; // ecx
  void *hudContext_4; // edx
  FFX_CharacterId charId_3; // ecx
  int v65; // eax
  int v66; // ecx
  int v67; // eax
  int v68; // eax
  int v69; // eax
  int v70; // eax
  int v71; // eax
  int v72; // eax
  int v73; // eax
  int v74; // eax
  int v75; // eax
  int v76; // eax
  int v77; // eax
  int v78; // edx
  int v79; // esi
  __int16 *v80; // eax
  int n3_1; // eax
  double v82; // st5
  double v83; // st4
  double v84; // rtt
  __int16 *hudContext_5; // edx
  FFX_CharacterId charId_4; // ecx
  int v87; // eax
  double v88; // st3
  double v89; // st5
  int v90; // eax
  double v91; // st2
  double v92; // st3
  int v93; // eax
  int v94; // eax
  int v95; // eax
  int v96; // eax
  double v97; // st7
  float v98; // eax
  double v99; // st7
  float v100; // eax
  double v101; // st7
  float v102; // eax
  double v103; // st7
  int v104; // eax
  double v105; // st7
  double v106; // st7
  int v107; // eax
  double v108; // st7
  float v109; // eax
  double v110; // st7
  float v111; // eax
  double v112; // st7
  float v113; // eax
  double v114; // st7
  int v115; // eax
  double v116; // st7
  void *hudContext_6; // edx
  FFX_CharacterId charId_5; // ecx
  void *hudContext_7; // edx
  FFX_CharacterId charId_6; // ecx
  int v121; // eax
  int v122; // eax
  int v123; // eax
  int v124; // eax
  int v125; // eax
  int v126; // eax
  int v127; // eax
  int n4; // esi
  int v129; // ecx
  int v130; // edx
  _BYTE *v131; // ebx
  float *n3_3; // eax
  float *v133; // edi
  double v134; // st6
  double v135; // st6
  double v136; // st5
  double v137; // st4
  double v138; // st3
  double v139; // st2
  double v140; // st1
  double v141; // st5
  double v142; // st3
  int n4_1; // eax
  float *v144; // ecx
  double v145; // st7
  double v146; // st7
  float *v147; // eax
  double v148; // st6
  float *v149; // ecx
  double v150; // st5
  int n3_4; // edx
  double v152; // st4
  double v153; // st3
  double v154; // st2
  double v155; // st2
  int p_n4_3; // esi
  float v157; // ebx
  float *v158; // eax
  int i; // ecx
  double v160; // st7
  int j; // ecx
  double v162; // st6
  double v163; // st6
  int n48; // ebx
  int v165; // eax
  int v166; // ecx
  int v167; // eax
  int v168; // eax
  int v169; // eax
  int v170; // eax
  int v171; // eax
  int v172; // eax
  int v173; // eax
  int v174; // eax
  int v175; // eax
  int v176; // eax
  int v177; // eax
  int v178; // esi
  int v179; // edx
  double v180; // st6
  double v181; // st5
  double v182; // st4
  __int16 *v183; // eax
  int v184; // eax
  int v185; // eax
  int v186; // eax
  int v187; // eax
  __int16 *hudContext_8; // edx
  FFX_CharacterId charId_7; // ecx
  int v190; // eax
  double v191; // st2
  double v192; // st4
  int v193; // eax
  double v194; // st2
  double v195; // st3
  int v196; // eax
  int v197; // eax
  int v198; // eax
  int v199; // eax
  int v200; // eax
  int v201; // eax
  double v202; // st7
  int v203; // eax
  double v204; // st7
  int v205; // eax
  double v206; // st7
  int v207; // eax
  double v208; // st7
  int v209; // eax
  double v210; // st7
  int v211; // eax
  double v212; // st7
  int v213; // eax
  double v214; // st7
  int v215; // eax
  double v216; // st7
  int v217; // eax
  double v218; // st7
  int v219; // eax
  double v220; // st7
  int v221; // eax
  double v222; // st7
  int v223; // eax
  double v224; // st7
  int v225; // eax
  double v226; // st7
  int v227; // eax
  double v228; // st7
  int v229; // eax
  double v230; // st7
  void *hudContext_9; // edx
  FFX_CharacterId charId_8; // ecx
  void *hudContext_10; // edx
  FFX_CharacterId charId_9; // ecx
  void *hudContext_11; // edx
  FFX_CharacterId charId_10; // ecx
  int v237; // eax
  int v238; // ecx
  int v239; // eax
  int v240; // eax
  int v241; // eax
  int v242; // eax
  int v243; // eax
  int v244; // eax
  int v245; // eax
  int v246; // eax
  int v247; // eax
  int v248; // eax
  int v249; // eax
  int v250; // eax
  int v251; // eax
  int v252; // eax
  int v253; // eax
  int v254; // esi
  int v255; // edi
  __int16 *v256; // eax
  int v257; // eax
  double v258; // st5
  double v259; // st4
  double v260; // rtt
  __int16 *hudContext_12; // edx
  FFX_CharacterId charId_11; // ecx
  int v263; // eax
  double v264; // st3
  double v265; // st5
  int v266; // eax
  double v267; // st2
  double v268; // st3
  int v269; // eax
  int v270; // eax
  int v271; // eax
  int v272; // eax
  int v273; // eax
  int v274; // eax
  double v275; // st7
  int v276; // eax
  double v277; // st7
  int v278; // eax
  double v279; // st7
  int v280; // eax
  double v281; // st7
  int v282; // eax
  double v283; // st7
  int v284; // eax
  double v285; // st7
  int v286; // eax
  double v287; // st7
  int v288; // eax
  double v289; // st7
  int v290; // eax
  double v291; // st7
  int v292; // eax
  double v293; // st7
  int v294; // eax
  double v295; // st7
  int v296; // eax
  double v297; // st7
  int v298; // eax
  double v299; // st7
  int v300; // eax
  double v301; // st7
  int v302; // eax
  double v303; // st7
  void *hudContext_13; // edx
  FFX_CharacterId charId_12; // ecx
  void *hudContext_14; // edx
  FFX_CharacterId charId_13; // ecx
  void *hudContext_15; // edx
  FFX_CharacterId charId_14; // ecx
  int v310; // eax
  int v311; // eax
  int v312; // eax
  int v313; // eax
  int v314; // eax
  int v315; // eax
  int v316; // eax
  int v317; // eax
  int v318; // eax
  int n4_2; // esi
  int v320; // ecx
  int v321; // edx
  _BYTE *v322; // ebx
  float *n3_6; // eax
  float *v324; // edi
  double v325; // st6
  double v326; // st6
  double v327; // st5
  double v328; // st4
  double v329; // st3
  double v330; // st2
  double v331; // st1
  double v332; // st5
  double v333; // st3
  int n4_3; // eax
  float *v335; // ecx
  double v336; // st7
  double v337; // st7
  float *v338; // eax
  double v339; // st6
  float *v340; // ecx
  double v341; // st5
  int n3_7; // edx
  double v343; // st4
  double v344; // st3
  double v345; // st2
  double v346; // st2
  int p_n4_4; // esi
  float b_13; // ebx
  float *v349; // eax
  int k; // ecx
  double v351; // st7
  int m; // ecx
  double v353; // st6
  float b_14; // ebx
  int v355; // eax
  int v356; // ecx
  int v357; // eax
  int v358; // eax
  int v359; // eax
  int v360; // eax
  int v361; // eax
  int v362; // eax
  int v363; // eax
  int v364; // eax
  int v365; // eax
  int v366; // eax
  int v367; // eax
  int v368; // eax
  int v369; // eax
  int v370; // eax
  int v371; // eax
  double v372; // st6
  int v373; // esi
  double v374; // st5
  int v375; // edi
  double v376; // st4
  __int16 v377; // dx
  __int16 *v378; // eax
  int v379; // eax
  int v380; // eax
  float *v382; // [esp-14h] [ebp-45Ch]
  float *v383; // [esp-14h] [ebp-45Ch]
  int b; // [esp+0h] [ebp-448h] BYREF
  int b_15; // [esp+4h] [ebp-444h] BYREF
  int v386; // [esp+8h] [ebp-440h]
  _DWORD *v387; // [esp+Ch] [ebp-43Ch]
  float v388; // [esp+10h] [ebp-438h]
  float v389; // [esp+14h] [ebp-434h]
  void *hudContext; // [esp+18h] [ebp-430h]
  int v391; // [esp+1Ch] [ebp-42Ch]
  float v392; // [esp+20h] [ebp-428h]
  float v393; // [esp+24h] [ebp-424h]
  float v394; // [esp+28h] [ebp-420h]
  __int16 *v395; // [esp+2Ch] [ebp-41Ch]
  unsigned __int8 *v396; // [esp+30h] [ebp-418h]
  int p_n4_2; // [esp+34h] [ebp-414h]
  float *n3; // [esp+38h] [ebp-410h]
  float v399; // [esp+3Ch] [ebp-40Ch]
  float v400; // [esp+40h] [ebp-408h]
  double v401; // [esp+44h] [ebp-404h]
  float v402; // [esp+4Ch] [ebp-3FCh]
  float v403; // [esp+50h] [ebp-3F8h]
  float v404; // [esp+54h] [ebp-3F4h]
  float b_1; // [esp+58h] [ebp-3F0h]
  double v406[5]; // [esp+5Ch] [ebp-3ECh]
  char v407[4]; // [esp+84h] [ebp-3C4h] BYREF
  char v408; // [esp+88h] [ebp-3C0h] BYREF
  float v409; // [esp+B4h] [ebp-394h]
  float v410; // [esp+B8h] [ebp-390h]
  float v411; // [esp+BCh] [ebp-38Ch]
  float v412; // [esp+C0h] [ebp-388h]
  char v413[4]; // [esp+C4h] [ebp-384h] BYREF
  char v414; // [esp+C8h] [ebp-380h] BYREF
  float v415; // [esp+F4h] [ebp-354h]
  float v416; // [esp+F8h] [ebp-350h]
  float v417; // [esp+FCh] [ebp-34Ch]
  float v418; // [esp+100h] [ebp-348h]
  _BYTE v420[60]; // [esp+108h] [ebp-340h] BYREF
  _BYTE v422[60]; // [esp+148h] [ebp-300h] BYREF
  char v423; // [esp+184h] [ebp-2C4h] BYREF
  _BYTE v424[44]; // [esp+188h] [ebp-2C0h] BYREF
  float v425; // [esp+1B4h] [ebp-294h]
  float v426; // [esp+1B8h] [ebp-290h]
  float v427; // [esp+1BCh] [ebp-28Ch]
  float v428; // [esp+1C0h] [ebp-288h]
  float v429; // [esp+1C4h] [ebp-284h]
  float v430[16]; // [esp+1C8h] [ebp-280h] BYREF
  float v431[3]; // [esp+208h] [ebp-240h] BYREF
  float v432; // [esp+214h] [ebp-234h]
  float v433; // [esp+218h] [ebp-230h]
  float v434; // [esp+21Ch] [ebp-22Ch]
  float v435; // [esp+220h] [ebp-228h]
  float v436; // [esp+224h] [ebp-224h]
  float v437; // [esp+228h] [ebp-220h]
  float v438; // [esp+22Ch] [ebp-21Ch]
  float v439; // [esp+230h] [ebp-218h]
  float v440[16]; // [esp+244h] [ebp-204h] BYREF
  float v441[16]; // [esp+284h] [ebp-1C4h] BYREF
  float v442; // [esp+2C4h] [ebp-184h] BYREF
  float n3_5[3]; // [esp+2C8h] [ebp-180h] BYREF
  float v444[4]; // [esp+2D4h] [ebp-174h] BYREF
  float v445[4]; // [esp+2E4h] [ebp-164h] BYREF
  float v446[4]; // [esp+2F4h] [ebp-154h] BYREF
  float v447; // [esp+304h] [ebp-144h] BYREF
  float n3_2[3]; // [esp+308h] [ebp-140h] BYREF
  float v449[4]; // [esp+314h] [ebp-134h] BYREF
  float v450[4]; // [esp+324h] [ebp-124h] BYREF
  float v451; // [esp+334h] [ebp-114h]
  float v452; // [esp+338h] [ebp-110h]
  float v453; // [esp+33Ch] [ebp-10Ch]
  float v454; // [esp+340h] [ebp-108h]
  float v455; // [esp+344h] [ebp-104h]
  float v456; // [esp+348h] [ebp-100h]
  float v457; // [esp+34Ch] [ebp-FCh]
  float v458; // [esp+350h] [ebp-F8h]
  float v459; // [esp+354h] [ebp-F4h]
  float v460; // [esp+358h] [ebp-F0h]
  float v461; // [esp+35Ch] [ebp-ECh]
  float v462; // [esp+360h] [ebp-E8h]
  float v463; // [esp+364h] [ebp-E4h]
  float v464; // [esp+368h] [ebp-E0h]
  float v465; // [esp+36Ch] [ebp-DCh]
  float v466; // [esp+370h] [ebp-D8h]
  float v467; // [esp+374h] [ebp-D4h]
  float v468; // [esp+378h] [ebp-D0h]
  float v469; // [esp+37Ch] [ebp-CCh]
  float v470; // [esp+380h] [ebp-C8h]
  float v471; // [esp+384h] [ebp-C4h]
  float v472; // [esp+388h] [ebp-C0h]
  float v473; // [esp+38Ch] [ebp-BCh]
  float v474; // [esp+390h] [ebp-B8h]
  float v475; // [esp+394h] [ebp-B4h]
  float v476; // [esp+398h] [ebp-B0h]
  float v477; // [esp+39Ch] [ebp-ACh]
  float v478; // [esp+3A0h] [ebp-A8h]
  float v479; // [esp+3A4h] [ebp-A4h]
  float v480; // [esp+3A8h] [ebp-A0h]
  float v481; // [esp+3ACh] [ebp-9Ch]
  float v482; // [esp+3B0h] [ebp-98h]
  float v483; // [esp+3B4h] [ebp-94h]
  float v484; // [esp+3B8h] [ebp-90h]
  float v485; // [esp+3BCh] [ebp-8Ch]
  float v486; // [esp+3C0h] [ebp-88h]
  float v487; // [esp+3C4h] [ebp-84h]
  float v488; // [esp+3C8h] [ebp-80h]
  float v489; // [esp+3CCh] [ebp-7Ch]
  float v490; // [esp+3D0h] [ebp-78h]
  float v491; // [esp+3D4h] [ebp-74h]
  float v492; // [esp+3D8h] [ebp-70h]
  float v493; // [esp+3DCh] [ebp-6Ch]
  float v494; // [esp+3E0h] [ebp-68h]
  float v495[4]; // [esp+3E4h] [ebp-64h] BYREF
  float v496; // [esp+3F4h] [ebp-54h] BYREF
  float v497; // [esp+3F8h] [ebp-50h]
  float v498[2]; // [esp+3FCh] [ebp-4Ch]
  float v499; // [esp+404h] [ebp-44h]
  float v500; // [esp+408h] [ebp-40h]
  float v501; // [esp+40Ch] [ebp-3Ch]
  float v502; // [esp+410h] [ebp-38h]
  float v503; // [esp+414h] [ebp-34h]
  float v504; // [esp+418h] [ebp-30h]
  float v505; // [esp+41Ch] [ebp-2Ch]
  float v506; // [esp+420h] [ebp-28h]
  float v507; // [esp+424h] [ebp-24h]
  float v508; // [esp+428h] [ebp-20h]
  float v509; // [esp+42Ch] [ebp-1Ch]
  float v510; // [esp+430h] [ebp-18h]
  float v511; // [esp+434h] [ebp-14h]
  float v512; // [esp+438h] [ebp-10h]
  float v513; // [esp+43Ch] [ebp-Ch]
  float v514; // [esp+440h] [ebp-8h]

  v511 = 1.0; /*0xa657df*/
  v512 = 1.0; /*0xa657e2*/
  p_n4_1 = p_n4; /*0xa657e6*/
  v513 = 1.0; /*0xa657e9*/
  v514 = 1.0; /*0xa657ec*/
  p_n4_2 = p_n4; /*0xa657ef*/
  v3 = *(_DWORD *)(p_n4 + 68); /*0xa657fb*/
  v441[12] = 0.0078125; /*0xa657fe*/
  v441[13] = 0.0078125; /*0xa65804*/
  v441[14] = 0.0078125; /*0xa6580a*/
  v441[15] = 0.0078125; /*0xa65810*/
  v393 = *(float *)(v3 + 56); /*0xa65819*/
  if ( !gParticleDoNotRender ) /*0xa6581f*/
  {
    v4 = (_DWORD *)*((_DWORD *)FFX_Menu2D_ResolveCaptureCtx((int)"NoTexture") + 37); /*0xa65832*/
    v387 = v4; /*0xa6583b*/
    v5 = *(_DWORD *)(a1 + 4); /*0xa65845*/
    v391 = *(__int16 *)(a1 + 16); /*0xa65848*/
    v6 = (unsigned __int8 *)(a1 + v5); /*0xa65853*/
    hudContext = (void *)(a1 + *(_DWORD *)(a1 + 8)); /*0xa65855*/
    v7 = a1 + *(_DWORD *)(a1 + 12); /*0xa6585e*/
    v8 = *(float **)(p_n4 + 32); /*0xa65860*/
    v9 = v6 + 16; /*0xa65863*/
    v395 = (__int16 *)v6; /*0xa65866*/
    v386 = v7; /*0xa6586c*/
    v10 = v8[12]; /*0xa65872*/
    v396 = v6 + 16; /*0xa65875*/
    v394 = v10 / v8[15] - 2048.0 + 256.0; /*0xa6588e*/
    v399 = v8[13] / v8[15] - 2048.0 + 208.0; /*0xa658b0*/
    FFX_Menu2D_GetNativeViewportSize1920x1080_structural(&b_15, &b); /*0xa658b6*/
    b_1 = (float)b_15; /*0xa658c4*/
    b_16 = b_1; /*0xa658d6*/
    v389 = 0.001953125 * b_1; /*0xa658e4*/
    b_1 = (float)b; /*0xa658f0*/
    v14 = *(_DWORD *)(p_n4 + 32); /*0xa658fc*/
    b_2 = b_1; /*0xa65905*/
    v388 = b_1 / 416.0; /*0xa65913*/
    v392 = *(float *)(v14 + 44); /*0xa6591c*/
    v16 = v392; /*0xa65922*/
    if ( 0.0 == v392 ) /*0xa65931*/
    {
      v392 = 1.0; /*0xa65937*/
      v16 = (float)1.0; /*0xa6593d*/
    }
    LODWORD(b_1) = *(unsigned __int8 *)(p_n4 + 24); /*0xa65953*/
    v402 = v16 * (v388 * 4.0) / (v389 * 3.0); /*0xa65969*/
    v403 = b_16 * 0.5; /*0xa65979*/
    v400 = 0.5 * b_2; /*0xa65981*/
    v406[0] = (double)SLODWORD(b_1); /*0xa6598d*/
    LODWORD(b_1) = *(unsigned __int8 *)(p_n4 + 25); /*0xa659a0*/
    v511 = v406[0] * v511; /*0xa659a6*/
    v406[0] = (double)SLODWORD(b_1); /*0xa659af*/
    LODWORD(b_1) = *(unsigned __int8 *)(p_n4 + 26); /*0xa659c2*/
    v512 = v406[0] * v512; /*0xa659c8*/
    v406[0] = (double)SLODWORD(b_1); /*0xa659d1*/
    LODWORD(b_1) = *(unsigned __int8 *)(p_n4 + 27); /*0xa659e4*/
    v513 = v406[0] * v513; /*0xa659ee*/
    v406[0] = (double)SLODWORD(b_1); /*0xa65a02*/
    v514 = v406[0] * v514; /*0xa65a11*/
    FFX_Math_Vec4Mul_Ppp(charId, hudContext_1); /*0xa65a14*/
    if ( (*(_BYTE *)p_n4 & 0x40) != 0 ) /*0xa65a1f*/
    {
      v17 = (float *)v424; /*0xa65a28*/
      v404 = *(float *)(p_n4 + 44); /*0xa65a30*/
      v18 = (float *)(LODWORD(v404) + 8); /*0xa65a36*/
      v19 = LODWORD(v404) - (_DWORD)v424; /*0xa65a39*/
      n3 = (float *)3; /*0xa65a3b*/
      do /*0xa65aa7*/
      {
        b_1 = sqrt(*(float *)((char *)v17 + v19) * *(float *)((char *)v17 + v19) + *(v18 - 1) * *(v18 - 1) + *v18 * *v18); /*0xa65a5e*/
        v17 += 4; /*0xa65a6a*/
        v18 += 4; /*0xa65a6f*/
        v20 = n3 == (float *)1; /*0xa65a72*/
        n3 = (float *)((char *)n3 - 1); /*0xa65a72*/
        b_1 = 1.0 / b_1; /*0xa65a7a*/
        b_3 = b_1; /*0xa65a8e*/
        *(v17 - 5) = *(float *)((char *)v17 + v19 - 16) * b_1; /*0xa65a90*/
        *(v17 - 4) = b_3 * *(v18 - 5); /*0xa65a98*/
        *(v17 - 3) = b_3 * *(v18 - 4); /*0xa65a9e*/
        *(v17 - 2) = *(v18 - 3); /*0xa65aa4*/
      }
      while ( !v20 ); /*0xa65aa7*/
      v4 = v387; /*0xa65aaf*/
      v9 = v396; /*0xa65ab8*/
      p_n4_1 = p_n4_2; /*0xa65abe*/
      v425 = *(float *)(LODWORD(v404) + 48); /*0xa65ac4*/
      v426 = *(float *)(LODWORD(v404) + 52); /*0xa65acd*/
      v427 = *(float *)(LODWORD(v404) + 56); /*0xa65ad6*/
      v428 = *(float *)(LODWORD(v404) + 60); /*0xa65adf*/
    }
    v22 = v391; /*0xa65ae5*/
    if ( v391 > 0 ) /*0xa65aed*/
    {
      v23 = v393; /*0xa65af3*/
      v24 = v395; /*0xa65af9*/
      v25 = v394; /*0xa65aff*/
      v26 = v399; /*0xa65b05*/
      v27 = v402; /*0xa65b0b*/
      v28 = v403; /*0xa65b11*/
      do /*0xa680fb*/
      {
        switch ( *((_BYTE *)v24 + 1) ) /*0xa65b24*/
        {
          case 0: /*0xa65b24*/
            n3 = 0; /*0xa65b2d*/
            if ( v24[1] > 0 ) /*0xa65b3b*/
            {
              do /*0xa6606f*/
              {
                hudContext_2 = (__int16 *)hudContext; /*0xa65b44*/
                charId_1 = 3 * v4[1]; /*0xa65b4a*/
                LODWORD(b_1) = *((__int16 *)hudContext + 3 * *((unsigned __int16 *)v9 + 6)); /*0xa65b58*/
                v406[0] = (double)SLODWORD(b_1); /*0xa65b64*/
                v31 = v4[3]; /*0xa65b70*/
                v32 = (v27 * v406[0] + v25) * v389; /*0xa65b83*/
                v33 = v389; /*0xa65b83*/
                b_1 = v32 - v28; /*0xa65b87*/
                *(float *)(v31 + 4 * charId_1) = b_1; /*0xa65b93*/
                LODWORD(b_1) = hudContext_2[3 * *((unsigned __int16 *)v9 + 6) + 1]; /*0xa65ba2*/
                v406[0] = (double)SLODWORD(b_1); /*0xa65bae*/
                v34 = v4[3]; /*0xa65bba*/
                v35 = v392; /*0xa65bbd*/
                v36 = v388; /*0xa65bdd*/
                b_1 = (v406[0] * v392 + v26) * v388 - v400; /*0xa65bdf*/
                *(float *)(v34 + 4 * charId_1 + 4) = b_1; /*0xa65beb*/
                *(float *)(v4[3] + 4 * charId_1 + 8) = v23; /*0xa65bf4*/
                LODWORD(b_1) = hudContext_2[3 * *((unsigned __int16 *)v9 + 7)]; /*0xa65c03*/
                v406[0] = (double)SLODWORD(b_1); /*0xa65c0f*/
                v37 = v4[3]; /*0xa65c1b*/
                b_1 = (v406[0] * v402 + v25) * v33 - v403; /*0xa65c2e*/
                *(float *)(v37 + 4 * charId_1 + 12) = b_1; /*0xa65c3a*/
                LODWORD(b_1) = hudContext_2[3 * *((unsigned __int16 *)v9 + 7) + 1]; /*0xa65c4a*/
                v406[0] = (double)SLODWORD(b_1); /*0xa65c56*/
                v38 = v4[3]; /*0xa65c62*/
                b_1 = (v406[0] * v35 + v26) * v36 - v400; /*0xa65c71*/
                *(float *)(v38 + 4 * charId_1 + 16) = b_1; /*0xa65c7d*/
                *(float *)(v4[3] + 4 * charId_1 + 20) = v23; /*0xa65c84*/
                LODWORD(b_1) = hudContext_2[3 * *((unsigned __int16 *)v9 + 8)]; /*0xa65c93*/
                v406[0] = (double)SLODWORD(b_1); /*0xa65c9f*/
                v39 = v4[3]; /*0xa65cab*/
                b_1 = v33 * (v25 + v406[0] * v402) - v403; /*0xa65cc4*/
                *(float *)(v39 + 4 * charId_1 + 24) = b_1; /*0xa65cd0*/
                LODWORD(b_1) = hudContext_2[3 * *((unsigned __int16 *)v9 + 8) + 1]; /*0xa65ce0*/
                v406[0] = (double)SLODWORD(b_1); /*0xa65cec*/
                v40 = v4[3]; /*0xa65cf8*/
                b_1 = v36 * (v26 + v35 * v406[0]) - v400; /*0xa65d0d*/
                *(float *)(v40 + 4 * charId_1 + 28) = b_1; /*0xa65d19*/
                *(float *)(v4[3] + 4 * charId_1 + 32) = v23; /*0xa65d20*/
                *(float *)(v4[4] + 4 * charId_1) = 0.0; /*0xa65d29*/
                *(float *)(v4[4] + 4 * charId_1 + 4) = 0.0; /*0xa65d2f*/
                *(float *)(v4[4] + 4 * charId_1 + 8) = 1.0; /*0xa65d38*/
                *(float *)(v4[4] + 4 * charId_1 + 12) = 0.0; /*0xa65d41*/
                *(float *)(v4[4] + 4 * charId_1 + 16) = 0.0; /*0xa65d48*/
                *(float *)(v4[4] + 4 * charId_1 + 20) = 1.0; /*0xa65d51*/
                *(float *)(v4[4] + 4 * charId_1 + 24) = 0.0; /*0xa65d5a*/
                *(float *)(v4[4] + 4 * charId_1 + 28) = 0.0; /*0xa65d61*/
                *(float *)(v4[4] + 4 * charId_1 + 32) = 1.0; /*0xa65d68*/
                LODWORD(b_1) = *v9; /*0xa65d6f*/
                v41 = (double)SLODWORD(b_1); /*0xa65d79*/
                LODWORD(b_1) = v9[1]; /*0xa65d7f*/
                LODWORD(b_4) = v9[2]; /*0xa65d85*/
                v467 = v41; /*0xa65d89*/
                v43 = (double)SLODWORD(b_1); /*0xa65d8f*/
                b_1 = b_4; /*0xa65d95*/
                LODWORD(b_5) = v9[3]; /*0xa65d9b*/
                v468 = v43; /*0xa65d9f*/
                v45 = (double)SLODWORD(b_1); /*0xa65da5*/
                b_1 = b_5; /*0xa65dab*/
                LODWORD(b_6) = v9[4]; /*0xa65db1*/
                v469 = v45; /*0xa65db5*/
                v47 = (double)SLODWORD(b_1); /*0xa65dbb*/
                b_1 = b_6; /*0xa65dc1*/
                LODWORD(b_7) = v9[5]; /*0xa65dc7*/
                v470 = v47; /*0xa65dcb*/
                v49 = (double)SLODWORD(b_1); /*0xa65dd1*/
                b_1 = b_7; /*0xa65dd7*/
                v471 = v49; /*0xa65ddd*/
                v50 = (double)SLODWORD(b_7); /*0xa65de3*/
                LODWORD(b_1) = v9[6]; /*0xa65ded*/
                LODWORD(b_8) = v9[7]; /*0xa65df3*/
                v472 = v50; /*0xa65df7*/
                v52 = (double)SLODWORD(b_1); /*0xa65dfd*/
                b_1 = b_8; /*0xa65e03*/
                LODWORD(b_9) = v9[8]; /*0xa65e09*/
                v473 = v52; /*0xa65e0d*/
                v54 = (double)SLODWORD(b_1); /*0xa65e13*/
                b_1 = b_9; /*0xa65e19*/
                LODWORD(b_10) = v9[9]; /*0xa65e1f*/
                v474 = v54; /*0xa65e23*/
                v56 = (double)SLODWORD(b_1); /*0xa65e29*/
                b_1 = b_10; /*0xa65e2f*/
                LODWORD(b_11) = v9[10]; /*0xa65e35*/
                v475 = v56; /*0xa65e39*/
                v58 = (double)SLODWORD(b_1); /*0xa65e3f*/
                b_1 = b_11; /*0xa65e45*/
                LODWORD(b_12) = v9[11]; /*0xa65e4b*/
                v476 = v58; /*0xa65e4f*/
                v60 = (double)SLODWORD(b_1); /*0xa65e55*/
                b_1 = b_12; /*0xa65e5b*/
                v477 = v60; /*0xa65e68*/
                v478 = (float)SLODWORD(b_12); /*0xa65e7f*/
                FFX_Math_Vec4Mul_Ppp(charId_1, hudContext_2); /*0xa65e85*/
                FFX_Math_Vec4Mul_Ppp(charId_2, hudContext_3); /*0xa65e9c*/
                FFX_Math_Vec4Mul_Ppp(charId_3, hudContext_4); /*0xa65eb3*/
                v65 = v4[5]; /*0xa65ec9*/
                v66 = 4 * v4[1]; /*0xa65ecf*/
                b_1 = v467 / 255.0; /*0xa65ed4*/
                *(float *)(v65 + 4 * v66) = b_1; /*0xa65ee0*/
                v67 = v4[5]; /*0xa65eeb*/
                b_1 = v468 / 255.0; /*0xa65eee*/
                *(float *)(v67 + 4 * v66 + 4) = b_1; /*0xa65efa*/
                v68 = v4[5]; /*0xa65f06*/
                b_1 = v469 / 255.0; /*0xa65f09*/
                *(float *)(v68 + 4 * v66 + 8) = b_1; /*0xa65f15*/
                v69 = v4[5]; /*0xa65f21*/
                b_1 = v470 / 255.0; /*0xa65f24*/
                *(float *)(v69 + 4 * v66 + 12) = b_1; /*0xa65f30*/
                v70 = v4[5]; /*0xa65f3c*/
                b_1 = v471 / 255.0; /*0xa65f3f*/
                *(float *)(v70 + 4 * v66 + 16) = b_1; /*0xa65f4b*/
                v71 = v4[5]; /*0xa65f4f*/
                v9 += 20; /*0xa65f58*/
                b_1 = v472 / 255.0; /*0xa65f5d*/
                *(float *)(v71 + 4 * v66 + 20) = b_1; /*0xa65f69*/
                v72 = v4[5]; /*0xa65f75*/
                b_1 = v473 / 255.0; /*0xa65f78*/
                *(float *)(v72 + 4 * v66 + 24) = b_1; /*0xa65f84*/
                v73 = v4[5]; /*0xa65f90*/
                b_1 = v474 / 255.0; /*0xa65f93*/
                *(float *)(v73 + 4 * v66 + 28) = b_1; /*0xa65f9f*/
                v74 = v4[5]; /*0xa65fab*/
                b_1 = v475 / 255.0; /*0xa65fae*/
                *(float *)(v74 + 4 * v66 + 32) = b_1; /*0xa65fba*/
                v75 = v4[5]; /*0xa65fc6*/
                b_1 = v476 / 255.0; /*0xa65fc9*/
                *(float *)(v75 + 4 * v66 + 36) = b_1; /*0xa65fd5*/
                v76 = v4[5]; /*0xa65fe1*/
                b_1 = v477 / 255.0; /*0xa65fe4*/
                *(float *)(v76 + 4 * v66 + 40) = b_1; /*0xa65ff0*/
                v77 = v4[5]; /*0xa65ff4*/
                b_1 = v478 / 255.0; /*0xa65ffd*/
                *(float *)(v77 + 4 * v66 + 44) = b_1; /*0xa66009*/
                v23 = v393; /*0xa6600d*/
                v78 = v4[1]; /*0xa66013*/
                v25 = v394; /*0xa66016*/
                v79 = v4[2]; /*0xa6601c*/
                v26 = v399; /*0xa6601f*/
                v27 = v402; /*0xa66028*/
                v28 = v403; /*0xa6602e*/
                *(_WORD *)(v4[7] + 2 * v79) = v78; /*0xa66037*/
                *(_WORD *)(v4[7] + 2 * v79 + 2) = v78 + 1; /*0xa6603e*/
                *(_WORD *)(v4[7] + 2 * v79 + 4) = v78 + 2; /*0xa66049*/
                v80 = v395; /*0xa6604e*/
                v4[1] += 3; /*0xa66054*/
                v4[2] += 3; /*0xa66058*/
                n3_1 = v80[1]; /*0xa66062*/
                n3 = (float *)((char *)n3 + 1); /*0xa66067*/
              }
              while ( (int)n3 < n3_1 ); /*0xa6606f*/
              goto LABEL_13; /*0xa6606f*/
            }
            break; /*0xa6606f*/
          case 1: /*0xa65b24*/
            v396 = v9; /*0xa660b6*/
            b_1 = 0.0; /*0xa660bc*/
            if ( v24[1] > 0 ) /*0xa660ca*/
            {
              v82 = v27; /*0xa660d2*/
              v83 = 0.0; /*0xa660d4*/
              while ( 1 ) /*0xa660e5*/
              {
                hudContext_5 = (__int16 *)hudContext; /*0xa660e5*/
                charId_4 = 3 * v4[1]; /*0xa660eb*/
                LODWORD(v404) = *((__int16 *)hudContext + 3 * *((unsigned __int16 *)v9 + 6)); /*0xa660f9*/
                v406[0] = (double)SLODWORD(v404); /*0xa66105*/
                v87 = v4[3]; /*0xa66111*/
                v88 = (v82 * v406[0] + v25) * v389 - v403; /*0xa6612c*/
                v89 = v389; /*0xa6612c*/
                v404 = v88; /*0xa6612e*/
                *(float *)(v87 + 4 * charId_4) = v404; /*0xa6613a*/
                LODWORD(v404) = hudContext_5[3 * *((unsigned __int16 *)v9 + 6) + 1]; /*0xa66149*/
                v406[0] = (double)SLODWORD(v404); /*0xa66155*/
                v90 = v4[3]; /*0xa66161*/
                v91 = v392; /*0xa66164*/
                v92 = v388; /*0xa66188*/
                v404 = (v406[0] * v392 + v399) * v388 - v400; /*0xa6618a*/
                *(float *)(v90 + 4 * charId_4 + 4) = v404; /*0xa66196*/
                *(float *)(v4[3] + 4 * charId_4 + 8) = v23; /*0xa6619f*/
                LODWORD(v404) = hudContext_5[3 * *((unsigned __int16 *)v9 + 7)]; /*0xa661ae*/
                v406[0] = (double)SLODWORD(v404); /*0xa661ba*/
                v93 = v4[3]; /*0xa661c6*/
                v404 = (v406[0] * v402 + v25) * v89 - v403; /*0xa661d9*/
                *(float *)(v93 + 4 * charId_4 + 12) = v404; /*0xa661e5*/
                LODWORD(v404) = hudContext_5[3 * *((unsigned __int16 *)v9 + 7) + 1]; /*0xa661f5*/
                v406[0] = (double)SLODWORD(v404); /*0xa66201*/
                v94 = v4[3]; /*0xa6620d*/
                v404 = (v406[0] * v91 + v399) * v92 - v400; /*0xa66220*/
                *(float *)(v94 + 4 * charId_4 + 16) = v404; /*0xa6622c*/
                *(float *)(v4[3] + 4 * charId_4 + 20) = v23; /*0xa66233*/
                LODWORD(v404) = hudContext_5[3 * *((unsigned __int16 *)v9 + 8)]; /*0xa66242*/
                v406[0] = (double)SLODWORD(v404); /*0xa6624e*/
                v95 = v4[3]; /*0xa6625a*/
                v404 = v89 * (v25 + v406[0] * v402) - v403; /*0xa66273*/
                *(float *)(v95 + 4 * charId_4 + 24) = v404; /*0xa6627f*/
                LODWORD(v404) = hudContext_5[3 * *((unsigned __int16 *)v9 + 8) + 1]; /*0xa6628f*/
                v406[0] = (double)SLODWORD(v404); /*0xa6629b*/
                v96 = v4[3]; /*0xa662a7*/
                v404 = v92 * (v91 * v406[0] + v399) - v400; /*0xa662be*/
                *(float *)(v96 + 4 * charId_4 + 28) = v404; /*0xa662ca*/
                *(float *)(v4[3] + 4 * charId_4 + 32) = v23; /*0xa662d1*/
                *(float *)(v4[4] + 4 * charId_4) = v83; /*0xa662d8*/
                *(float *)(v4[4] + 4 * charId_4 + 4) = v83; /*0xa662de*/
                *(float *)(v4[4] + 4 * charId_4 + 8) = 1.0; /*0xa662e7*/
                *(float *)(v4[4] + 4 * charId_4 + 12) = v83; /*0xa662f0*/
                *(float *)(v4[4] + 4 * charId_4 + 16) = v83; /*0xa662f7*/
                *(float *)(v4[4] + 4 * charId_4 + 20) = 1.0; /*0xa66300*/
                *(float *)(v4[4] + 4 * charId_4 + 24) = v83; /*0xa66309*/
                *(float *)(v4[4] + 4 * charId_4 + 28) = v83; /*0xa66310*/
                *(float *)(v4[4] + 4 * charId_4 + 32) = 1.0; /*0xa66317*/
                LODWORD(v404) = *v9; /*0xa6631e*/
                v97 = (double)SLODWORD(v404); /*0xa66328*/
                LODWORD(v404) = v9[1]; /*0xa6632e*/
                LODWORD(v98) = v9[2]; /*0xa66334*/
                v499 = v97; /*0xa66338*/
                v99 = (double)SLODWORD(v404); /*0xa6633b*/
                v404 = v98; /*0xa66341*/
                LODWORD(v100) = v9[3]; /*0xa66347*/
                v500 = v99; /*0xa6634b*/
                v101 = (double)SLODWORD(v404); /*0xa6634e*/
                v404 = v100; /*0xa66354*/
                LODWORD(v102) = v9[4]; /*0xa6635a*/
                v501 = v101; /*0xa6635e*/
                v103 = (double)SLODWORD(v404); /*0xa66361*/
                v404 = v102; /*0xa66367*/
                v104 = v9[5]; /*0xa6636d*/
                v502 = v103; /*0xa66371*/
                v105 = (double)SLODWORD(v404); /*0xa66374*/
                v404 = *(float *)&v104; /*0xa6637a*/
                v503 = v105; /*0xa66380*/
                v106 = (double)v104; /*0xa66383*/
                v107 = v9[6]; /*0xa66389*/
                v504 = v106; /*0xa6638d*/
                v404 = *(float *)&v107; /*0xa66390*/
                v108 = (double)v107; /*0xa6639a*/
                LODWORD(v404) = v9[7]; /*0xa663a0*/
                LODWORD(v109) = v9[8]; /*0xa663a6*/
                v505 = v108; /*0xa663aa*/
                v110 = (double)SLODWORD(v404); /*0xa663ad*/
                v404 = v109; /*0xa663b3*/
                LODWORD(v111) = v9[9]; /*0xa663b9*/
                v506 = v110; /*0xa663bd*/
                v112 = (double)SLODWORD(v404); /*0xa663c0*/
                v404 = v111; /*0xa663c6*/
                LODWORD(v113) = v9[10]; /*0xa663cc*/
                v507 = v112; /*0xa663d0*/
                v114 = (double)SLODWORD(v404); /*0xa663d3*/
                v404 = v113; /*0xa663d9*/
                v115 = v9[11]; /*0xa663df*/
                v508 = v114; /*0xa663e3*/
                v116 = (double)SLODWORD(v404); /*0xa663e6*/
                v404 = *(float *)&v115; /*0xa663ec*/
                v509 = v116; /*0xa663f6*/
                v510 = (float)v115; /*0xa66407*/
                FFX_Math_Vec4Mul_Ppp(charId_4, hudContext_5); /*0xa6640a*/
                FFX_Math_Vec4Mul_Ppp(charId_5, hudContext_6); /*0xa6641b*/
                FFX_Math_Vec4Mul_Ppp(charId_6, hudContext_7); /*0xa6642c*/
                if ( (*(_BYTE *)p_n4_1 & 0x40) != 0 ) /*0xa66437*/
                {
                  LODWORD(v404) = *(unsigned __int8 *)(p_n4_1 + 77); /*0xa66447*/
                  v406[0] = (double)SLODWORD(v404); /*0xa66453*/
                  v121 = *((unsigned __int16 *)v9 + 6); /*0xa6645f*/
                  *((float *)v406 + 1) = v406[0] * 0.0078125; /*0xa66469*/
                  LODWORD(v404) = *((__int16 *)hudContext + 3 * v121); /*0xa66476*/
                  v447 = (float)SLODWORD(v404); /*0xa66482*/
                  LODWORD(v404) = *((__int16 *)hudContext + 3 * v121 + 1); /*0xa6648d*/
                  n3_2[0] = (float)SLODWORD(v404); /*0xa66499*/
                  LODWORD(v404) = *((__int16 *)hudContext + 3 * v121 + 2); /*0xa664a4*/
                  v122 = *((unsigned __int16 *)v9 + 7); /*0xa664aa*/
                  n3_2[1] = (float)SLODWORD(v404); /*0xa664b4*/
                  n3_2[2] = 1.0; /*0xa664bf*/
                  LODWORD(v404) = *((__int16 *)hudContext + 3 * v122); /*0xa664c9*/
                  v449[0] = (float)SLODWORD(v404); /*0xa664d5*/
                  LODWORD(v404) = *((__int16 *)hudContext + 3 * v122 + 1); /*0xa664e0*/
                  v449[1] = (float)SLODWORD(v404); /*0xa664ec*/
                  LODWORD(v404) = *((__int16 *)hudContext + 3 * v122 + 2); /*0xa664f7*/
                  v123 = *((unsigned __int16 *)v9 + 8); /*0xa664fd*/
                  v449[2] = (float)SLODWORD(v404); /*0xa66507*/
                  v449[3] = 1.0; /*0xa66510*/
                  LODWORD(v404) = *((__int16 *)hudContext + 3 * v123); /*0xa6651a*/
                  v450[0] = (float)SLODWORD(v404); /*0xa66526*/
                  LODWORD(v404) = *((__int16 *)hudContext + 3 * v123 + 1); /*0xa66531*/
                  v450[1] = (float)SLODWORD(v404); /*0xa6653d*/
                  LODWORD(v404) = *((__int16 *)hudContext + 3 * v123 + 2); /*0xa6654e*/
                  v124 = *((unsigned __int16 *)v9 + 10); /*0xa66554*/
                  v450[2] = (float)SLODWORD(v404); /*0xa6655e*/
                  v450[3] = 1.0; /*0xa66567*/
                  LODWORD(v404) = *(__int16 *)(v386 + 6 * v124); /*0xa66571*/
                  v401 = (double)SLODWORD(v404); /*0xa6657d*/
                  v441[0] = v401 * 0.000244140625; /*0xa66593*/
                  LODWORD(v404) = *(__int16 *)(v386 + 6 * v124 + 2); /*0xa6659e*/
                  v401 = (double)SLODWORD(v404); /*0xa665aa*/
                  v441[1] = v401 * 0.000244140625; /*0xa665b8*/
                  LODWORD(v404) = *(__int16 *)(v386 + 6 * v124 + 4); /*0xa665c3*/
                  v401 = (double)SLODWORD(v404); /*0xa665cf*/
                  v441[2] = v401 * 0.000244140625; /*0xa665dd*/
                  v125 = *((unsigned __int16 *)v9 + 11); /*0xa665e5*/
                  v441[3] = 0.0; /*0xa665e9*/
                  LODWORD(v404) = *(__int16 *)(v386 + 6 * v125); /*0xa665f6*/
                  v401 = (double)SLODWORD(v404); /*0xa66602*/
                  v441[4] = v401 * 0.000244140625; /*0xa66610*/
                  LODWORD(v404) = *(__int16 *)(v386 + 6 * v125 + 2); /*0xa6661b*/
                  v401 = (double)SLODWORD(v404); /*0xa66627*/
                  v441[5] = v401 * 0.000244140625; /*0xa66635*/
                  LODWORD(v404) = *(__int16 *)(v386 + 6 * v125 + 4); /*0xa66640*/
                  v401 = (double)SLODWORD(v404); /*0xa6664c*/
                  v126 = *((unsigned __int16 *)v9 + 12); /*0xa66658*/
                  v441[6] = v401 * 0.000244140625; /*0xa6665e*/
                  v441[7] = 0.0; /*0xa66667*/
                  LODWORD(v404) = *(__int16 *)(v386 + 6 * v126); /*0xa66671*/
                  v401 = (double)SLODWORD(v404); /*0xa6667d*/
                  v441[8] = v401 * 0.000244140625; /*0xa6668b*/
                  LODWORD(v404) = *(__int16 *)(v386 + 6 * v126 + 2); /*0xa66696*/
                  v401 = (double)SLODWORD(v404); /*0xa666a2*/
                  v441[9] = v401 * 0.000244140625; /*0xa666b0*/
                  LODWORD(v404) = *(__int16 *)(v386 + 6 * v126 + 4); /*0xa666bb*/
                  v401 = (double)SLODWORD(v404); /*0xa666ce*/
                  v382 = *(float **)(p_n4_1 + 44); /*0xa666da*/
                  v441[10] = 0.000244140625 * v401; /*0xa666e2*/
                  v441[11] = 0.0; /*0xa666e8*/
                  FFX_Math_Mat4x4MulVec4_Copy(&v447, v382, &v447); /*0xa666ee*/
                  FFX_Math_Mat4x4MulVec4_Copy(v449, *(float **)(p_n4_1 + 44), v449); /*0xa666fe*/
                  FFX_Math_Mat4x4MulVec4_Copy(v450, *(float **)(p_n4_1 + 44), v450); /*0xa6670e*/
                  n3 = n3_2; /*0xa6671c*/
                  v404 = 0.0; /*0xa66722*/
                  do /*0xa66a04*/
                  {
                    v127 = *(_DWORD *)(p_n4_2 + 40); /*0xa66740*/
                    n4 = 0; /*0xa66743*/
                    v129 = v127 + 12; /*0xa66745*/
                    v130 = v127 + 8; /*0xa66748*/
                    v131 = &v420[-v127 - 4]; /*0xa6674b*/
                    n3_3 = n3; /*0xa6674d*/
                    v133 = (float *)v420; /*0xa66753*/
                    do /*0xa66827*/
                    {
                      ++n4; /*0xa6675c*/
                      v134 = *(float *)(v130 - 8) - *(n3_3 - 1); /*0xa6675d*/
                      v130 += 16; /*0xa66760*/
                      v133 += 4; /*0xa66763*/
                      v129 += 16; /*0xa66766*/
                      *((float *)&v401 + 1) = v134; /*0xa66769*/
                      v135 = *((float *)&v401 + 1); /*0xa6676f*/
                      v136 = *((float *)&v401 + 1); /*0xa66775*/
                      *((float *)&v401 + 1) = *(float *)(v130 - 20) - *n3_3; /*0xa6677c*/
                      v137 = *((float *)&v401 + 1); /*0xa66782*/
                      v138 = *((float *)&v401 + 1); /*0xa66788*/
                      *((float *)&v401 + 1) = *(float *)(v130 - 16) - n3_3[1]; /*0xa66790*/
                      v139 = *((float *)&v401 + 1); /*0xa66796*/
                      v140 = v136; /*0xa6679e*/
                      v141 = *((float *)&v401 + 1); /*0xa6679e*/
                      *((float *)&v401 + 1) = v140 * v140 + 0.0; /*0xa667a6*/
                      *((float *)&v401 + 1) = *((float *)&v401 + 1) + v138 * v138; /*0xa667ba*/
                      *((float *)&v401 + 1) = *((float *)&v401 + 1) + v141 * v141; /*0xa667ce*/
                      v142 = *((float *)&v401 + 1); /*0xa667d4*/
                      *((float *)&v406[2] + n4 + 1) = *((float *)&v401 + 1); /*0xa667da*/
                      *((float *)&v401 + 1) = v135 * *(float *)(v129 - 16); /*0xa667e8*/
                      *(v133 - 5) = *((float *)&v401 + 1) / v142; /*0xa667f6*/
                      *((float *)&v401 + 1) = v137 * *(float *)(v129 - 16); /*0xa667fc*/
                      *(v133 - 4) = *((float *)&v401 + 1) / v142; /*0xa6680a*/
                      *((float *)&v401 + 1) = v139 * *(float *)(v129 - 16); /*0xa66810*/
                      *(float *)&v131[v130 - 16] = *((float *)&v401 + 1) / v142; /*0xa6681c*/
                      *(float *)&v131[v129 - 16] = 0.0; /*0xa66820*/
                    }
                    while ( n4 < 4 ); /*0xa66827*/
                    n4_1 = 0; /*0xa6682f*/
                    v144 = v431; /*0xa66831*/
                    do /*0xa6686f*/
                    {
                      v145 = *(float *)&v420[4 * n4_1++ - 4]; /*0xa66840*/
                      *(v144 - 1) = v145; /*0xa66848*/
                      v144 += 4; /*0xa6684b*/
                      *(v144 - 4) = *(float *)&v420[4 * n4_1 + 8]; /*0xa66855*/
                      *(v144 - 3) = *(float *)&v420[4 * n4_1 + 24]; /*0xa6685f*/
                      *(v144 - 2) = *(float *)&v420[4 * n4_1 + 40]; /*0xa66869*/
                    }
                    while ( n4_1 < 4 ); /*0xa6686f*/
                    v146 = v439; /*0xa66871*/
                    v147 = (float *)&v423; /*0xa66877*/
                    v148 = v438; /*0xa6687d*/
                    v149 = (float *)&v408; /*0xa66883*/
                    v150 = v437; /*0xa66889*/
                    n3_4 = 3; /*0xa6688f*/
                    v152 = v436; /*0xa66894*/
                    v153 = v435; /*0xa6689a*/
                    v154 = v432; /*0xa668a0*/
                    do /*0xa66921*/
                    {
                      v155 = v154 * v147[1]; /*0xa668a6*/
                      v147 += 4; /*0xa668a9*/
                      v149 += 4; /*0xa668b2*/
                      *(v149 - 5) = v155 + v430[15] * *(v147 - 4) + v152 * *(v147 - 2); /*0xa668c1*/
                      *(v149 - 4) = v433 * *(v147 - 3) + v431[0] * *(v147 - 4) + v150 * *(v147 - 2); /*0xa668df*/
                      *(v149 - 3) = v434 * *(v147 - 3) + v431[1] * *(v147 - 4) + v148 * *(v147 - 2); /*0xa668fd*/
                      *(v149 - 2) = v153 * *(v147 - 3) + v431[2] * *(v147 - 4) + v146 * *(v147 - 2); /*0xa66917*/
                      v154 = v432; /*0xa6691a*/
                      --n3_4; /*0xa66920*/
                    }
                    while ( n3_4 ); /*0xa66921*/
                    p_n4_3 = p_n4_2; /*0xa66923*/
                    v157 = v404; /*0xa6692b*/
                    v158 = *(float **)(p_n4_2 + 44); /*0xa66933*/
                    v409 = v158[12]; /*0xa66941*/
                    v410 = v158[13]; /*0xa6694a*/
                    v411 = v158[14]; /*0xa66953*/
                    v412 = v158[15]; /*0xa66964*/
                    FFX_Math_Mat4x4MulVec4_Copy(&v496, (float *)v407, (float *)((char *)v441 + LODWORD(v404))); /*0xa66976*/
                    for ( i = 0; i < 4; ++i ) /*0xa66980*/
                    {
                      if ( *(&v496 + i) < 0.0 ) /*0xa6698b*/
                        *(&v496 + i) = 0.0; /*0xa6698d*/
                    }
                    FFX_Math_Mat4x4MulVec4_Copy(&v496, *(float **)(p_n4_3 + 36), &v496); /*0xa669a1*/
                    v160 = 0.0; /*0xa669a6*/
                    for ( j = 0; j < 4; v495[j + 3] = v162 * *((float *)v406 + 1) ) /*0xa669ab*/
                    {
                      if ( *(&v496 + j) < 0.0 ) /*0xa669b6*/
                        *(&v496 + j) = 0.0; /*0xa669b8*/
                      v162 = *(&v496 + j++); /*0xa669bc*/
                    }
                    n3 += 4; /*0xa669d3*/
                    v163 = v496 * *(float *)((char *)&v499 + LODWORD(v157)); /*0xa669da*/
                    n48 = LODWORD(v157) + 16; /*0xa669de*/
                    v404 = *(float *)&n48; /*0xa669e1*/
                    *(float *)((char *)&v496 + n48) = v163; /*0xa669e7*/
                    *(float *)((char *)&v498[-1] + n48) = v497 * *(float *)((char *)&v498[-1] + n48); /*0xa669f2*/
                    *(float *)((char *)v498 + n48) = v498[0] * *(float *)((char *)v498 + n48); /*0xa669fd*/
                  }
                  while ( n48 < 48 ); /*0xa66a04*/
                  v4 = v387; /*0xa66a0a*/
                  v9 = v396; /*0xa66a10*/
                }
                else
                {
                  v160 = 0.0; /*0xa66a18*/
                }
                v165 = v4[5]; /*0xa66a26*/
                v166 = 4 * v4[1]; /*0xa66a2b*/
                *((float *)v406 + 1) = v499 / 255.0; /*0xa66a30*/
                *(float *)(v165 + 4 * v166) = *((float *)v406 + 1); /*0xa66a3c*/
                v167 = v4[5]; /*0xa66a44*/
                *((float *)v406 + 1) = v500 / 255.0; /*0xa66a47*/
                *(float *)(v167 + 4 * v166 + 4) = *((float *)v406 + 1); /*0xa66a53*/
                v168 = v4[5]; /*0xa66a5c*/
                *((float *)v406 + 1) = v501 / 255.0; /*0xa66a5f*/
                *(float *)(v168 + 4 * v166 + 8) = *((float *)v406 + 1); /*0xa66a6b*/
                v169 = v4[5]; /*0xa66a74*/
                *((float *)v406 + 1) = v502 / 255.0; /*0xa66a77*/
                *(float *)(v169 + 4 * v166 + 12) = *((float *)v406 + 1); /*0xa66a83*/
                v170 = v4[5]; /*0xa66a8c*/
                *((float *)v406 + 1) = v503 / 255.0; /*0xa66a8f*/
                *(float *)(v170 + 4 * v166 + 16) = *((float *)v406 + 1); /*0xa66a9b*/
                v171 = v4[5]; /*0xa66aa4*/
                *((float *)v406 + 1) = v504 / 255.0; /*0xa66aa7*/
                *(float *)(v171 + 4 * v166 + 20) = *((float *)v406 + 1); /*0xa66ab3*/
                v172 = v4[5]; /*0xa66abc*/
                *((float *)v406 + 1) = v505 / 255.0; /*0xa66abf*/
                *(float *)(v172 + 4 * v166 + 24) = *((float *)v406 + 1); /*0xa66acb*/
                v173 = v4[5]; /*0xa66ad4*/
                *((float *)v406 + 1) = v506 / 255.0; /*0xa66ad7*/
                *(float *)(v173 + 4 * v166 + 28) = *((float *)v406 + 1); /*0xa66ae3*/
                v174 = v4[5]; /*0xa66aec*/
                *((float *)v406 + 1) = v507 / 255.0; /*0xa66aef*/
                *(float *)(v174 + 4 * v166 + 32) = *((float *)v406 + 1); /*0xa66afb*/
                v175 = v4[5]; /*0xa66b04*/
                *((float *)v406 + 1) = v508 / 255.0; /*0xa66b07*/
                *(float *)(v175 + 4 * v166 + 36) = *((float *)v406 + 1); /*0xa66b13*/
                v176 = v4[5]; /*0xa66b1c*/
                *((float *)v406 + 1) = v509 / 255.0; /*0xa66b1f*/
                *(float *)(v176 + 4 * v166 + 40) = *((float *)v406 + 1); /*0xa66b2b*/
                v177 = v4[5]; /*0xa66b2f*/
                *((float *)v406 + 1) = v510 / 255.0; /*0xa66b35*/
                *(float *)(v177 + 4 * v166 + 44) = *((float *)v406 + 1); /*0xa66b41*/
                v178 = v4[2]; /*0xa66b48*/
                v179 = v4[1]; /*0xa66b4b*/
                *(_WORD *)(v4[7] + 2 * v178) = v179; /*0xa66b4e*/
                v180 = v393; /*0xa66b58*/
                *(_WORD *)(v4[7] + 2 * v178 + 2) = v179 + 1; /*0xa66b5e*/
                v181 = v394; /*0xa66b66*/
                v182 = v402; /*0xa66b6c*/
                *(_WORD *)(v4[7] + 2 * v178 + 4) = v179 + 2; /*0xa66b75*/
                v183 = v395; /*0xa66b7a*/
                v4[1] += 3; /*0xa66b80*/
                v4[2] += 3; /*0xa66b84*/
                v184 = v183[1]; /*0xa66b8e*/
                p_n4_1 = p_n4_2; /*0xa66b92*/
                v9 += 28; /*0xa66b99*/
                ++LODWORD(b_1); /*0xa66b9c*/
                v396 = v9; /*0xa66ba2*/
                if ( SLODWORD(b_1) >= v184 ) /*0xa66baa*/
                  break; /*0xa66baa*/
                v84 = v182; /*0xa660d8*/
                v83 = v160; /*0xa660da*/
                v23 = v180; /*0xa660da*/
                v25 = v181; /*0xa660de*/
                v82 = v84; /*0xa660e0*/
              }
              v24 = v395; /*0xa66bb0*/
              v22 = v391; /*0xa66bb8*/
              v23 = v393; /*0xa66bc4*/
              v25 = v394; /*0xa66bca*/
              v26 = v399; /*0xa66bd0*/
              v27 = v402; /*0xa66bd6*/
              v28 = v403; /*0xa66bdc*/
            }
            break; /*0xa66be2*/
          case 2: /*0xa65b24*/
            v185 = v24[1]; /*0xa66be7*/
            if ( v185 > 0 ) /*0xa66bed*/
            {
              v186 = 32 * v185; /*0xa66bf3*/
              goto LABEL_72; /*0xa66bf6*/
            }
            break; /*0xa66bf6*/
          case 3: /*0xa65b24*/
          case 6: /*0xa65b24*/
            v187 = v24[1]; /*0xa66bfb*/
            if ( v187 > 0 ) /*0xa66c01*/
              v9 += 40 * v187; /*0xa66c0a*/
            break; /*0xa66c0d*/
          case 4: /*0xa65b24*/
            v396 = v9; /*0xa66c14*/
            b_1 = 0.0; /*0xa66c1a*/
            if ( v24[1] > 0 ) /*0xa66c28*/
            {
              do /*0xa67307*/
              {
                hudContext_8 = (__int16 *)hudContext; /*0xa66c31*/
                charId_7 = 3 * v4[1]; /*0xa66c37*/
                HIDWORD(v406[0]) = *((__int16 *)hudContext + 3 * *((unsigned __int16 *)v9 + 8)); /*0xa66c45*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa66c51*/
                v190 = v4[3]; /*0xa66c5d*/
                v191 = (v27 * v406[0] + v25) * v389; /*0xa66c70*/
                v192 = v389; /*0xa66c70*/
                *((float *)v406 + 1) = v191 - v28; /*0xa66c74*/
                *(float *)(v190 + 4 * charId_7) = *((float *)v406 + 1); /*0xa66c80*/
                HIDWORD(v406[0]) = hudContext_8[3 * *((unsigned __int16 *)v9 + 8) + 1]; /*0xa66c8f*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa66c9b*/
                v193 = v4[3]; /*0xa66ca7*/
                v194 = v392; /*0xa66caa*/
                v195 = v388; /*0xa66cca*/
                *((float *)v406 + 1) = (v406[0] * v392 + v26) * v388 - v400; /*0xa66ccc*/
                *(float *)(v193 + 4 * charId_7 + 4) = *((float *)v406 + 1); /*0xa66cd8*/
                *(float *)(v4[3] + 4 * charId_7 + 8) = v23; /*0xa66ce1*/
                HIDWORD(v406[0]) = hudContext_8[3 * *((unsigned __int16 *)v9 + 9)]; /*0xa66cf0*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa66cfc*/
                v196 = v4[3]; /*0xa66d08*/
                *((float *)v406 + 1) = (v406[0] * v402 + v25) * v192 - v403; /*0xa66d1b*/
                *(float *)(v196 + 4 * charId_7 + 12) = *((float *)v406 + 1); /*0xa66d27*/
                HIDWORD(v406[0]) = hudContext_8[3 * *((unsigned __int16 *)v9 + 9) + 1]; /*0xa66d37*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa66d43*/
                v197 = v4[3]; /*0xa66d4f*/
                *((float *)v406 + 1) = (v406[0] * v194 + v26) * v195 - v400; /*0xa66d5e*/
                *(float *)(v197 + 4 * charId_7 + 16) = *((float *)v406 + 1); /*0xa66d6a*/
                *(float *)(v4[3] + 4 * charId_7 + 20) = v23; /*0xa66d71*/
                HIDWORD(v406[0]) = hudContext_8[3 * *((unsigned __int16 *)v9 + 10)]; /*0xa66d80*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa66d8c*/
                v198 = v4[3]; /*0xa66d98*/
                *((float *)v406 + 1) = (v406[0] * v402 + v25) * v192 - v403; /*0xa66dab*/
                *(float *)(v198 + 4 * charId_7 + 24) = *((float *)v406 + 1); /*0xa66db7*/
                HIDWORD(v406[0]) = hudContext_8[3 * *((unsigned __int16 *)v9 + 10) + 1]; /*0xa66dc7*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa66dd3*/
                v199 = v4[3]; /*0xa66ddf*/
                *((float *)v406 + 1) = (v406[0] * v194 + v26) * v195 - v400; /*0xa66dee*/
                *(float *)(v199 + 4 * charId_7 + 28) = *((float *)v406 + 1); /*0xa66dfa*/
                *(float *)(v4[3] + 4 * charId_7 + 32) = v23; /*0xa66e01*/
                HIDWORD(v406[0]) = hudContext_8[3 * *((unsigned __int16 *)v9 + 11)]; /*0xa66e10*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa66e1c*/
                v200 = v4[3]; /*0xa66e28*/
                *((float *)v406 + 1) = v192 * (v25 + v406[0] * v402) - v403; /*0xa66e41*/
                *(float *)(v200 + 4 * charId_7 + 36) = *((float *)v406 + 1); /*0xa66e4d*/
                HIDWORD(v406[0]) = hudContext_8[3 * *((unsigned __int16 *)v9 + 11) + 1]; /*0xa66e5d*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa66e69*/
                v201 = v4[3]; /*0xa66e75*/
                *((float *)v406 + 1) = v195 * (v26 + v194 * v406[0]) - v400; /*0xa66e8a*/
                *(float *)(v201 + 4 * charId_7 + 40) = *((float *)v406 + 1); /*0xa66e96*/
                *(float *)(v4[3] + 4 * charId_7 + 44) = v23; /*0xa66e9d*/
                *(float *)(v4[4] + 4 * charId_7) = 0.0; /*0xa66ea6*/
                *(float *)(v4[4] + 4 * charId_7 + 4) = 0.0; /*0xa66eac*/
                *(float *)(v4[4] + 4 * charId_7 + 8) = 1.0; /*0xa66eb5*/
                *(float *)(v4[4] + 4 * charId_7 + 12) = 0.0; /*0xa66ebe*/
                *(float *)(v4[4] + 4 * charId_7 + 16) = 0.0; /*0xa66ec5*/
                *(float *)(v4[4] + 4 * charId_7 + 20) = 1.0; /*0xa66ece*/
                *(float *)(v4[4] + 4 * charId_7 + 24) = 0.0; /*0xa66ed7*/
                *(float *)(v4[4] + 4 * charId_7 + 28) = 0.0; /*0xa66ede*/
                *(float *)(v4[4] + 4 * charId_7 + 32) = 1.0; /*0xa66ee7*/
                *(float *)(v4[4] + 4 * charId_7 + 36) = 0.0; /*0xa66ef0*/
                *(float *)(v4[4] + 4 * charId_7 + 40) = 0.0; /*0xa66ef7*/
                *(float *)(v4[4] + 4 * charId_7 + 44) = 1.0; /*0xa66efe*/
                HIDWORD(v406[0]) = *v9; /*0xa66f05*/
                v202 = (double)SHIDWORD(v406[0]); /*0xa66f0f*/
                HIDWORD(v406[0]) = v9[1]; /*0xa66f15*/
                v203 = v9[2]; /*0xa66f1b*/
                v451 = v202; /*0xa66f1f*/
                v204 = (double)SHIDWORD(v406[0]); /*0xa66f25*/
                HIDWORD(v406[0]) = v203; /*0xa66f2b*/
                v205 = v9[3]; /*0xa66f31*/
                v452 = v204; /*0xa66f35*/
                v206 = (double)SHIDWORD(v406[0]); /*0xa66f3b*/
                HIDWORD(v406[0]) = v205; /*0xa66f41*/
                v207 = v9[4]; /*0xa66f47*/
                v453 = v206; /*0xa66f4b*/
                v208 = (double)SHIDWORD(v406[0]); /*0xa66f51*/
                HIDWORD(v406[0]) = v207; /*0xa66f57*/
                v209 = v9[5]; /*0xa66f5d*/
                v454 = v208; /*0xa66f61*/
                v210 = (double)SHIDWORD(v406[0]); /*0xa66f67*/
                HIDWORD(v406[0]) = v209; /*0xa66f6d*/
                v211 = v9[6]; /*0xa66f73*/
                v455 = v210; /*0xa66f77*/
                v212 = (double)SHIDWORD(v406[0]); /*0xa66f7d*/
                HIDWORD(v406[0]) = v211; /*0xa66f83*/
                v213 = v9[7]; /*0xa66f89*/
                v456 = v212; /*0xa66f8d*/
                v214 = (double)SHIDWORD(v406[0]); /*0xa66f93*/
                HIDWORD(v406[0]) = v213; /*0xa66f99*/
                v215 = v9[8]; /*0xa66f9f*/
                v457 = v214; /*0xa66fa3*/
                v216 = (double)SHIDWORD(v406[0]); /*0xa66fa9*/
                HIDWORD(v406[0]) = v215; /*0xa66faf*/
                v217 = v9[9]; /*0xa66fb5*/
                v458 = v216; /*0xa66fb9*/
                v218 = (double)SHIDWORD(v406[0]); /*0xa66fbf*/
                HIDWORD(v406[0]) = v217; /*0xa66fc5*/
                v219 = v9[10]; /*0xa66fcb*/
                v459 = v218; /*0xa66fcf*/
                v220 = (double)SHIDWORD(v406[0]); /*0xa66fd5*/
                HIDWORD(v406[0]) = v219; /*0xa66fdb*/
                v221 = v9[11]; /*0xa66fe1*/
                v460 = v220; /*0xa66fe5*/
                v222 = (double)SHIDWORD(v406[0]); /*0xa66feb*/
                HIDWORD(v406[0]) = v221; /*0xa66ff1*/
                v223 = v9[12]; /*0xa66ff7*/
                v461 = v222; /*0xa66ffb*/
                v224 = (double)SHIDWORD(v406[0]); /*0xa67001*/
                HIDWORD(v406[0]) = v223; /*0xa67007*/
                v225 = v9[13]; /*0xa6700d*/
                v462 = v224; /*0xa67011*/
                v226 = (double)SHIDWORD(v406[0]); /*0xa67017*/
                HIDWORD(v406[0]) = v225; /*0xa6701d*/
                v227 = v9[14]; /*0xa67023*/
                v463 = v226; /*0xa67027*/
                v228 = (double)SHIDWORD(v406[0]); /*0xa6702d*/
                HIDWORD(v406[0]) = v227; /*0xa67033*/
                v229 = v9[15]; /*0xa67039*/
                v464 = v228; /*0xa6703d*/
                v230 = (double)SHIDWORD(v406[0]); /*0xa67043*/
                HIDWORD(v406[0]) = v229; /*0xa67049*/
                v465 = v230; /*0xa6704f*/
                v466 = (float)v229; /*0xa67061*/
                FFX_Math_Vec4Mul_Ppp(charId_7, hudContext_8); /*0xa67073*/
                FFX_Math_Vec4Mul_Ppp(charId_8, hudContext_9); /*0xa6708a*/
                FFX_Math_Vec4Mul_Ppp(charId_9, hudContext_10); /*0xa670a1*/
                FFX_Math_Vec4Mul_Ppp(charId_10, hudContext_11); /*0xa670b8*/
                v237 = v4[5]; /*0xa670ce*/
                v238 = 4 * v4[1]; /*0xa670d4*/
                *((float *)v406 + 1) = v451 / 255.0; /*0xa670d9*/
                *(float *)(v237 + 4 * v238) = *((float *)v406 + 1); /*0xa670e5*/
                v239 = v4[5]; /*0xa670f0*/
                *((float *)v406 + 1) = v452 / 255.0; /*0xa670f3*/
                *(float *)(v239 + 4 * v238 + 4) = *((float *)v406 + 1); /*0xa670ff*/
                v240 = v4[5]; /*0xa6710b*/
                *((float *)v406 + 1) = v453 / 255.0; /*0xa6710e*/
                *(float *)(v240 + 4 * v238 + 8) = *((float *)v406 + 1); /*0xa6711a*/
                v241 = v4[5]; /*0xa67126*/
                *((float *)v406 + 1) = v454 / 255.0; /*0xa67129*/
                *(float *)(v241 + 4 * v238 + 12) = *((float *)v406 + 1); /*0xa67135*/
                v242 = v4[5]; /*0xa67141*/
                *((float *)v406 + 1) = v455 / 255.0; /*0xa67144*/
                *(float *)(v242 + 4 * v238 + 16) = *((float *)v406 + 1); /*0xa67150*/
                v243 = v4[5]; /*0xa6715c*/
                *((float *)v406 + 1) = v456 / 255.0; /*0xa6715f*/
                *(float *)(v243 + 4 * v238 + 20) = *((float *)v406 + 1); /*0xa6716b*/
                v244 = v4[5]; /*0xa67177*/
                *((float *)v406 + 1) = v457 / 255.0; /*0xa6717a*/
                *(float *)(v244 + 4 * v238 + 24) = *((float *)v406 + 1); /*0xa67186*/
                v245 = v4[5]; /*0xa67192*/
                *((float *)v406 + 1) = v458 / 255.0; /*0xa67195*/
                *(float *)(v245 + 4 * v238 + 28) = *((float *)v406 + 1); /*0xa671a1*/
                v246 = v4[5]; /*0xa671a5*/
                *((float *)v406 + 1) = v459 / 255.0; /*0xa671b0*/
                *(float *)(v246 + 4 * v238 + 32) = *((float *)v406 + 1); /*0xa671bc*/
                v247 = v4[5]; /*0xa671c8*/
                *((float *)v406 + 1) = v460 / 255.0; /*0xa671cb*/
                *(float *)(v247 + 4 * v238 + 36) = *((float *)v406 + 1); /*0xa671d7*/
                v248 = v4[5]; /*0xa671e3*/
                *((float *)v406 + 1) = v461 / 255.0; /*0xa671e6*/
                *(float *)(v248 + 4 * v238 + 40) = *((float *)v406 + 1); /*0xa671f2*/
                v249 = v4[5]; /*0xa671fe*/
                *((float *)v406 + 1) = v462 / 255.0; /*0xa67201*/
                *(float *)(v249 + 4 * v238 + 44) = *((float *)v406 + 1); /*0xa6720d*/
                v250 = v4[5]; /*0xa67219*/
                *((float *)v406 + 1) = v463 / 255.0; /*0xa6721c*/
                *(float *)(v250 + 4 * v238 + 48) = *((float *)v406 + 1); /*0xa67228*/
                v251 = v4[5]; /*0xa67234*/
                *((float *)v406 + 1) = v464 / 255.0; /*0xa67237*/
                *(float *)(v251 + 4 * v238 + 52) = *((float *)v406 + 1); /*0xa67243*/
                v252 = v4[5]; /*0xa6724f*/
                *((float *)v406 + 1) = v465 / 255.0; /*0xa67252*/
                *(float *)(v252 + 4 * v238 + 56) = *((float *)v406 + 1); /*0xa6725e*/
                v253 = v4[5]; /*0xa67262*/
                *((float *)v406 + 1) = v466 / 255.0; /*0xa6726b*/
                *(float *)(v253 + 4 * v238 + 60) = *((float *)v406 + 1); /*0xa67277*/
                v23 = v393; /*0xa6727b*/
                v254 = v4[1]; /*0xa67281*/
                v25 = v394; /*0xa67284*/
                v255 = v4[2]; /*0xa6728a*/
                v26 = v399; /*0xa6728d*/
                v27 = v402; /*0xa67296*/
                v28 = v403; /*0xa6729c*/
                *(_WORD *)(v4[7] + 2 * v255) = v254; /*0xa672a5*/
                *(_WORD *)(v4[7] + 2 * v255 + 2) = v254 + 1; /*0xa672af*/
                *(_WORD *)(v4[7] + 2 * v255 + 4) = v254 + 2; /*0xa672b7*/
                *(_WORD *)(v4[7] + 2 * v255 + 6) = v254 + 2; /*0xa672bf*/
                *(_WORD *)(v4[7] + 2 * v255 + 8) = v254 + 1; /*0xa672ca*/
                *(_WORD *)(v4[7] + 2 * v255 + 10) = v254 + 3; /*0xa672d2*/
                v256 = v395; /*0xa672d7*/
                v4[1] += 4; /*0xa672dd*/
                v4[2] += 6; /*0xa672e1*/
                v257 = v256[1]; /*0xa672f1*/
                v9 = v396 + 24; /*0xa672f6*/
                ++LODWORD(b_1); /*0xa672f9*/
                v396 += 24; /*0xa672ff*/
              }
              while ( SLODWORD(b_1) < v257 ); /*0xa67307*/
LABEL_13:
              p_n4_1 = p_n4_2; /*0xa66075*/
              goto LABEL_14; /*0xa66075*/
            }
            break; /*0xa66075*/
          case 5: /*0xa65b24*/
            v396 = v9; /*0xa67314*/
            v404 = 0.0; /*0xa6731a*/
            if ( v24[1] > 0 ) /*0xa67328*/
            {
              v258 = v27; /*0xa67330*/
              v259 = 0.0; /*0xa67332*/
              while ( 1 ) /*0xa67343*/
              {
                hudContext_12 = (__int16 *)hudContext; /*0xa67343*/
                charId_11 = 3 * v4[1]; /*0xa67349*/
                HIDWORD(v406[0]) = *((__int16 *)hudContext + 3 * *((unsigned __int16 *)v9 + 8)); /*0xa67357*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa67363*/
                v263 = v4[3]; /*0xa6736f*/
                v264 = (v258 * v406[0] + v25) * v389 - v403; /*0xa6738a*/
                v265 = v389; /*0xa6738a*/
                *((float *)v406 + 1) = v264; /*0xa6738c*/
                *(float *)(v263 + 4 * charId_11) = *((float *)v406 + 1); /*0xa67398*/
                HIDWORD(v406[0]) = hudContext_12[3 * *((unsigned __int16 *)v9 + 8) + 1]; /*0xa673a7*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa673b3*/
                v266 = v4[3]; /*0xa673bf*/
                v267 = v392; /*0xa673c2*/
                v268 = v388; /*0xa673e6*/
                *((float *)v406 + 1) = (v406[0] * v392 + v399) * v388 - v400; /*0xa673e8*/
                *(float *)(v266 + 4 * charId_11 + 4) = *((float *)v406 + 1); /*0xa673f4*/
                *(float *)(v4[3] + 4 * charId_11 + 8) = v23; /*0xa673fd*/
                HIDWORD(v406[0]) = hudContext_12[3 * *((unsigned __int16 *)v9 + 9)]; /*0xa6740c*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa67418*/
                v269 = v4[3]; /*0xa67424*/
                *((float *)v406 + 1) = (v406[0] * v402 + v25) * v265 - v403; /*0xa67437*/
                *(float *)(v269 + 4 * charId_11 + 12) = *((float *)v406 + 1); /*0xa67443*/
                HIDWORD(v406[0]) = hudContext_12[3 * *((unsigned __int16 *)v9 + 9) + 1]; /*0xa67453*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa6745f*/
                v270 = v4[3]; /*0xa6746b*/
                *((float *)v406 + 1) = (v406[0] * v267 + v399) * v268 - v400; /*0xa6747e*/
                *(float *)(v270 + 4 * charId_11 + 16) = *((float *)v406 + 1); /*0xa6748a*/
                *(float *)(v4[3] + 4 * charId_11 + 20) = v23; /*0xa67491*/
                HIDWORD(v406[0]) = hudContext_12[3 * *((unsigned __int16 *)v9 + 10)]; /*0xa674a0*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa674ac*/
                v271 = v4[3]; /*0xa674b8*/
                *((float *)v406 + 1) = (v406[0] * v402 + v25) * v265 - v403; /*0xa674cb*/
                *(float *)(v271 + 4 * charId_11 + 24) = *((float *)v406 + 1); /*0xa674d7*/
                HIDWORD(v406[0]) = hudContext_12[3 * *((unsigned __int16 *)v9 + 10) + 1]; /*0xa674e7*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa674f3*/
                v272 = v4[3]; /*0xa674ff*/
                *((float *)v406 + 1) = (v406[0] * v267 + v399) * v268 - v400; /*0xa67512*/
                *(float *)(v272 + 4 * charId_11 + 28) = *((float *)v406 + 1); /*0xa6751e*/
                *(float *)(v4[3] + 4 * charId_11 + 32) = v23; /*0xa67525*/
                HIDWORD(v406[0]) = hudContext_12[3 * *((unsigned __int16 *)v9 + 11)]; /*0xa67534*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa67540*/
                v273 = v4[3]; /*0xa6754c*/
                *((float *)v406 + 1) = v265 * (v25 + v406[0] * v402) - v403; /*0xa67565*/
                *(float *)(v273 + 4 * charId_11 + 36) = *((float *)v406 + 1); /*0xa67571*/
                HIDWORD(v406[0]) = hudContext_12[3 * *((unsigned __int16 *)v9 + 11) + 1]; /*0xa67581*/
                v406[0] = (double)SHIDWORD(v406[0]); /*0xa6758d*/
                v274 = v4[3]; /*0xa67599*/
                *((float *)v406 + 1) = v268 * (v267 * v406[0] + v399) - v400; /*0xa675b0*/
                *(float *)(v274 + 4 * charId_11 + 40) = *((float *)v406 + 1); /*0xa675bc*/
                *(float *)(v4[3] + 4 * charId_11 + 44) = v23; /*0xa675c3*/
                *(float *)(v4[4] + 4 * charId_11) = v259; /*0xa675ca*/
                *(float *)(v4[4] + 4 * charId_11 + 4) = v259; /*0xa675d0*/
                *(float *)(v4[4] + 4 * charId_11 + 8) = 1.0; /*0xa675d9*/
                *(float *)(v4[4] + 4 * charId_11 + 12) = v259; /*0xa675e2*/
                *(float *)(v4[4] + 4 * charId_11 + 16) = v259; /*0xa675e9*/
                *(float *)(v4[4] + 4 * charId_11 + 20) = 1.0; /*0xa675f2*/
                *(float *)(v4[4] + 4 * charId_11 + 24) = v259; /*0xa675fb*/
                *(float *)(v4[4] + 4 * charId_11 + 28) = v259; /*0xa67602*/
                *(float *)(v4[4] + 4 * charId_11 + 32) = 1.0; /*0xa6760b*/
                *(float *)(v4[4] + 4 * charId_11 + 36) = v259; /*0xa67614*/
                *(float *)(v4[4] + 4 * charId_11 + 40) = v259; /*0xa6761b*/
                *(float *)(v4[4] + 4 * charId_11 + 44) = 1.0; /*0xa67622*/
                HIDWORD(v406[0]) = *v9; /*0xa67629*/
                v275 = (double)SHIDWORD(v406[0]); /*0xa67633*/
                HIDWORD(v406[0]) = v9[1]; /*0xa67639*/
                v276 = v9[2]; /*0xa6763f*/
                v479 = v275; /*0xa67643*/
                v277 = (double)SHIDWORD(v406[0]); /*0xa67649*/
                HIDWORD(v406[0]) = v276; /*0xa6764f*/
                v278 = v9[3]; /*0xa67655*/
                v480 = v277; /*0xa67659*/
                v279 = (double)SHIDWORD(v406[0]); /*0xa6765f*/
                HIDWORD(v406[0]) = v278; /*0xa67665*/
                v280 = v9[4]; /*0xa6766b*/
                v481 = v279; /*0xa6766f*/
                v281 = (double)SHIDWORD(v406[0]); /*0xa67675*/
                HIDWORD(v406[0]) = v280; /*0xa6767b*/
                v282 = v9[5]; /*0xa67681*/
                v482 = v281; /*0xa67685*/
                v283 = (double)SHIDWORD(v406[0]); /*0xa6768b*/
                HIDWORD(v406[0]) = v282; /*0xa67691*/
                v284 = v9[6]; /*0xa67697*/
                v483 = v283; /*0xa6769b*/
                v285 = (double)SHIDWORD(v406[0]); /*0xa676a1*/
                HIDWORD(v406[0]) = v284; /*0xa676a7*/
                v286 = v9[7]; /*0xa676ad*/
                v484 = v285; /*0xa676b1*/
                v287 = (double)SHIDWORD(v406[0]); /*0xa676b7*/
                HIDWORD(v406[0]) = v286; /*0xa676bd*/
                v288 = v9[8]; /*0xa676c3*/
                v485 = v287; /*0xa676c7*/
                v289 = (double)SHIDWORD(v406[0]); /*0xa676cd*/
                HIDWORD(v406[0]) = v288; /*0xa676d3*/
                v290 = v9[9]; /*0xa676d9*/
                v486 = v289; /*0xa676dd*/
                v291 = (double)SHIDWORD(v406[0]); /*0xa676e3*/
                HIDWORD(v406[0]) = v290; /*0xa676e9*/
                v292 = v9[10]; /*0xa676ef*/
                v487 = v291; /*0xa676f3*/
                v293 = (double)SHIDWORD(v406[0]); /*0xa676f9*/
                HIDWORD(v406[0]) = v292; /*0xa676ff*/
                v294 = v9[11]; /*0xa67705*/
                v488 = v293; /*0xa67709*/
                v295 = (double)SHIDWORD(v406[0]); /*0xa6770c*/
                HIDWORD(v406[0]) = v294; /*0xa67712*/
                v296 = v9[12]; /*0xa67718*/
                v489 = v295; /*0xa6771c*/
                v297 = (double)SHIDWORD(v406[0]); /*0xa6771f*/
                HIDWORD(v406[0]) = v296; /*0xa67725*/
                v298 = v9[13]; /*0xa6772b*/
                v490 = v297; /*0xa6772f*/
                v299 = (double)SHIDWORD(v406[0]); /*0xa67732*/
                HIDWORD(v406[0]) = v298; /*0xa67738*/
                v300 = v9[14]; /*0xa6773e*/
                v491 = v299; /*0xa67742*/
                v301 = (double)SHIDWORD(v406[0]); /*0xa67745*/
                HIDWORD(v406[0]) = v300; /*0xa6774b*/
                v302 = v9[15]; /*0xa67751*/
                v492 = v301; /*0xa67755*/
                v303 = (double)SHIDWORD(v406[0]); /*0xa67758*/
                HIDWORD(v406[0]) = v302; /*0xa6775e*/
                v493 = v303; /*0xa67764*/
                v494 = (float)v302; /*0xa6776d*/
                FFX_Math_Vec4Mul_Ppp(charId_11, hudContext_12); /*0xa67782*/
                FFX_Math_Vec4Mul_Ppp(charId_12, hudContext_13); /*0xa67799*/
                FFX_Math_Vec4Mul_Ppp(charId_13, hudContext_14); /*0xa677b0*/
                FFX_Math_Vec4Mul_Ppp(charId_14, hudContext_15); /*0xa677c1*/
                if ( (*(_BYTE *)p_n4_1 & 0x40) != 0 ) /*0xa677cc*/
                {
                  HIDWORD(v406[0]) = *(unsigned __int8 *)(p_n4_1 + 77); /*0xa677dc*/
                  v406[0] = (double)SHIDWORD(v406[0]); /*0xa677e8*/
                  v310 = *((unsigned __int16 *)v9 + 8); /*0xa677f4*/
                  *((float *)&v401 + 1) = v406[0] * 0.0078125; /*0xa677fe*/
                  HIDWORD(v406[0]) = *((__int16 *)hudContext + 3 * v310); /*0xa6780b*/
                  v442 = (float)SHIDWORD(v406[0]); /*0xa67817*/
                  HIDWORD(v406[0]) = *((__int16 *)hudContext + 3 * v310 + 1); /*0xa67822*/
                  n3_5[0] = (float)SHIDWORD(v406[0]); /*0xa6782e*/
                  HIDWORD(v406[0]) = *((__int16 *)hudContext + 3 * v310 + 2); /*0xa67839*/
                  v311 = *((unsigned __int16 *)v9 + 9); /*0xa6783f*/
                  n3_5[1] = (float)SHIDWORD(v406[0]); /*0xa67849*/
                  n3_5[2] = 1.0; /*0xa67854*/
                  HIDWORD(v406[0]) = *((__int16 *)hudContext + 3 * v311); /*0xa6785e*/
                  v444[0] = (float)SHIDWORD(v406[0]); /*0xa6786a*/
                  HIDWORD(v406[0]) = *((__int16 *)hudContext + 3 * v311 + 1); /*0xa67875*/
                  v444[1] = (float)SHIDWORD(v406[0]); /*0xa67881*/
                  HIDWORD(v406[0]) = *((__int16 *)hudContext + 3 * v311 + 2); /*0xa6788c*/
                  v312 = *((unsigned __int16 *)v9 + 10); /*0xa67892*/
                  v444[2] = (float)SHIDWORD(v406[0]); /*0xa6789c*/
                  v444[3] = 1.0; /*0xa678a5*/
                  HIDWORD(v406[0]) = *((__int16 *)hudContext + 3 * v312); /*0xa678af*/
                  v445[0] = (float)SHIDWORD(v406[0]); /*0xa678bb*/
                  HIDWORD(v406[0]) = *((__int16 *)hudContext + 3 * v312 + 1); /*0xa678c6*/
                  v445[1] = (float)SHIDWORD(v406[0]); /*0xa678d2*/
                  HIDWORD(v406[0]) = *((__int16 *)hudContext + 3 * v312 + 2); /*0xa678dd*/
                  v313 = *((unsigned __int16 *)v9 + 11); /*0xa678e3*/
                  v445[2] = (float)SHIDWORD(v406[0]); /*0xa678ed*/
                  v445[3] = 1.0; /*0xa678f6*/
                  HIDWORD(v406[0]) = *((__int16 *)hudContext + 3 * v313); /*0xa67900*/
                  v446[0] = (float)SHIDWORD(v406[0]); /*0xa6790c*/
                  HIDWORD(v406[0]) = *((__int16 *)hudContext + 3 * v313 + 1); /*0xa67917*/
                  v446[1] = (float)SHIDWORD(v406[0]); /*0xa67923*/
                  HIDWORD(v406[0]) = *((__int16 *)hudContext + 3 * v313 + 2); /*0xa67934*/
                  v314 = *((unsigned __int16 *)v9 + 12); /*0xa6793a*/
                  v446[2] = (float)SHIDWORD(v406[0]); /*0xa67944*/
                  v446[3] = 1.0; /*0xa6794d*/
                  HIDWORD(v406[0]) = *(__int16 *)(v386 + 6 * v314); /*0xa67957*/
                  *((float *)v406 + 1) = (float)SHIDWORD(v406[0]); /*0xa67963*/
                  v440[0] = *((float *)v406 + 1) * 0.000244140625; /*0xa67979*/
                  HIDWORD(v406[0]) = *(__int16 *)(v386 + 6 * v314 + 2); /*0xa67984*/
                  *((float *)v406 + 1) = (float)SHIDWORD(v406[0]); /*0xa67990*/
                  v440[1] = *((float *)v406 + 1) * 0.000244140625; /*0xa6799e*/
                  HIDWORD(v406[0]) = *(__int16 *)(v386 + 6 * v314 + 4); /*0xa679a9*/
                  *((float *)v406 + 1) = (float)SHIDWORD(v406[0]); /*0xa679b5*/
                  v315 = *((unsigned __int16 *)v9 + 13); /*0xa679c1*/
                  v440[2] = *((float *)v406 + 1) * 0.000244140625; /*0xa679c7*/
                  v440[3] = 0.0; /*0xa679d2*/
                  HIDWORD(v406[0]) = *(__int16 *)(v386 + 6 * v315); /*0xa679dc*/
                  *((float *)v406 + 1) = (float)SHIDWORD(v406[0]); /*0xa679e8*/
                  v440[4] = *((float *)v406 + 1) * 0.000244140625; /*0xa679f6*/
                  HIDWORD(v406[0]) = *(__int16 *)(v386 + 6 * v315 + 2); /*0xa67a01*/
                  *((float *)v406 + 1) = (float)SHIDWORD(v406[0]); /*0xa67a0d*/
                  v440[5] = *((float *)v406 + 1) * 0.000244140625; /*0xa67a1b*/
                  HIDWORD(v406[0]) = *(__int16 *)(v386 + 6 * v315 + 4); /*0xa67a26*/
                  *((float *)v406 + 1) = (float)SHIDWORD(v406[0]); /*0xa67a32*/
                  v316 = *((unsigned __int16 *)v9 + 14); /*0xa67a3e*/
                  v440[6] = *((float *)v406 + 1) * 0.000244140625; /*0xa67a44*/
                  v440[7] = 0.0; /*0xa67a4d*/
                  HIDWORD(v406[0]) = *(__int16 *)(v386 + 6 * v316); /*0xa67a57*/
                  *((float *)v406 + 1) = (float)SHIDWORD(v406[0]); /*0xa67a63*/
                  v440[8] = *((float *)v406 + 1) * 0.000244140625; /*0xa67a71*/
                  HIDWORD(v406[0]) = *(__int16 *)(v386 + 6 * v316 + 2); /*0xa67a7c*/
                  *((float *)v406 + 1) = (float)SHIDWORD(v406[0]); /*0xa67a88*/
                  v440[9] = *((float *)v406 + 1) * 0.000244140625; /*0xa67a96*/
                  HIDWORD(v406[0]) = *(__int16 *)(v386 + 6 * v316 + 4); /*0xa67aa1*/
                  *((float *)v406 + 1) = (float)SHIDWORD(v406[0]); /*0xa67aad*/
                  v317 = *((unsigned __int16 *)v9 + 15); /*0xa67ab9*/
                  v440[10] = *((float *)v406 + 1) * 0.000244140625; /*0xa67abf*/
                  v440[11] = 0.0; /*0xa67ac8*/
                  HIDWORD(v406[0]) = *(__int16 *)(v386 + 6 * v317); /*0xa67ad2*/
                  *((float *)v406 + 1) = (float)SHIDWORD(v406[0]); /*0xa67ade*/
                  v440[12] = *((float *)v406 + 1) * 0.000244140625; /*0xa67aec*/
                  HIDWORD(v406[0]) = *(__int16 *)(v386 + 6 * v317 + 2); /*0xa67af7*/
                  *((float *)v406 + 1) = (float)SHIDWORD(v406[0]); /*0xa67b03*/
                  v440[13] = *((float *)v406 + 1) * 0.000244140625; /*0xa67b11*/
                  HIDWORD(v406[0]) = *(__int16 *)(v386 + 6 * v317 + 4); /*0xa67b1c*/
                  *((float *)v406 + 1) = (float)SHIDWORD(v406[0]); /*0xa67b2f*/
                  v383 = *(float **)(p_n4_1 + 44); /*0xa67b3b*/
                  v440[14] = 0.000244140625 * *((float *)v406 + 1); /*0xa67b43*/
                  v440[15] = 0.0; /*0xa67b49*/
                  FFX_Math_Mat4x4MulVec4_Copy(&v442, v383, &v442); /*0xa67b4f*/
                  FFX_Math_Mat4x4MulVec4_Copy(v444, *(float **)(p_n4_1 + 44), v444); /*0xa67b5f*/
                  FFX_Math_Mat4x4MulVec4_Copy(v445, *(float **)(p_n4_1 + 44), v445); /*0xa67b6f*/
                  FFX_Math_Mat4x4MulVec4_Copy(v446, *(float **)(p_n4_1 + 44), v446); /*0xa67b7f*/
                  n3 = n3_5; /*0xa67b8d*/
                  b_1 = 0.0; /*0xa67b93*/
                  do /*0xa67e85*/
                  {
                    v318 = *(_DWORD *)(p_n4_2 + 40); /*0xa67bb0*/
                    n4_2 = 0; /*0xa67bb3*/
                    v320 = v318 + 12; /*0xa67bb5*/
                    v321 = v318 + 8; /*0xa67bb8*/
                    v322 = &v422[-v318 - 4]; /*0xa67bbb*/
                    n3_6 = n3; /*0xa67bbd*/
                    v324 = (float *)v422; /*0xa67bc3*/
                    do /*0xa67c97*/
                    {
                      ++n4_2; /*0xa67bcc*/
                      v325 = *(float *)(v321 - 8) - *(n3_6 - 1); /*0xa67bcd*/
                      v321 += 16; /*0xa67bd0*/
                      v324 += 4; /*0xa67bd3*/
                      v320 += 16; /*0xa67bd6*/
                      *((float *)v406 + 1) = v325; /*0xa67bd9*/
                      v326 = *((float *)v406 + 1); /*0xa67bdf*/
                      v327 = *((float *)v406 + 1); /*0xa67be5*/
                      *((float *)v406 + 1) = *(float *)(v321 - 20) - *n3_6; /*0xa67bec*/
                      v328 = *((float *)v406 + 1); /*0xa67bf2*/
                      v329 = *((float *)v406 + 1); /*0xa67bf8*/
                      *((float *)v406 + 1) = *(float *)(v321 - 16) - n3_6[1]; /*0xa67c00*/
                      v330 = *((float *)v406 + 1); /*0xa67c06*/
                      v331 = v327; /*0xa67c0e*/
                      v332 = *((float *)v406 + 1); /*0xa67c0e*/
                      *((float *)v406 + 1) = v331 * v331 + 0.0; /*0xa67c16*/
                      *((float *)v406 + 1) = *((float *)v406 + 1) + v329 * v329; /*0xa67c2a*/
                      *((float *)v406 + 1) = *((float *)v406 + 1) + v332 * v332; /*0xa67c3e*/
                      v333 = *((float *)v406 + 1); /*0xa67c44*/
                      *((float *)v406 + n4_2 + 1) = *((float *)v406 + 1); /*0xa67c4a*/
                      *((float *)v406 + 1) = v326 * *(float *)(v320 - 16); /*0xa67c58*/
                      *(v324 - 5) = *((float *)v406 + 1) / v333; /*0xa67c66*/
                      *((float *)v406 + 1) = v328 * *(float *)(v320 - 16); /*0xa67c6c*/
                      *(v324 - 4) = *((float *)v406 + 1) / v333; /*0xa67c7a*/
                      *((float *)v406 + 1) = v330 * *(float *)(v320 - 16); /*0xa67c80*/
                      *(float *)&v322[v321 - 16] = *((float *)v406 + 1) / v333; /*0xa67c8c*/
                      *(float *)&v322[v320 - 16] = 0.0; /*0xa67c90*/
                    }
                    while ( n4_2 < 4 ); /*0xa67c97*/
                    n4_3 = 0; /*0xa67c9f*/
                    v335 = v430; /*0xa67ca1*/
                    do /*0xa67cdf*/
                    {
                      v336 = *(float *)&v422[4 * n4_3++ - 4]; /*0xa67cb0*/
                      *(v335 - 1) = v336; /*0xa67cb8*/
                      v335 += 4; /*0xa67cbb*/
                      *(v335 - 4) = *(float *)&v422[4 * n4_3 + 8]; /*0xa67cc5*/
                      *(v335 - 3) = *(float *)&v422[4 * n4_3 + 24]; /*0xa67ccf*/
                      *(v335 - 2) = *(float *)&v422[4 * n4_3 + 40]; /*0xa67cd9*/
                    }
                    while ( n4_3 < 4 ); /*0xa67cdf*/
                    v337 = v430[10]; /*0xa67ce1*/
                    v338 = (float *)&v423; /*0xa67ce7*/
                    v339 = v430[9]; /*0xa67ced*/
                    v340 = (float *)&v414; /*0xa67cf3*/
                    v341 = v430[8]; /*0xa67cf9*/
                    n3_7 = 3; /*0xa67cff*/
                    v343 = v430[7]; /*0xa67d04*/
                    v344 = v430[6]; /*0xa67d0a*/
                    v345 = v429; /*0xa67d10*/
                    do /*0xa67d90*/
                    {
                      v346 = v345 * *v338; /*0xa67d16*/
                      v338 += 4; /*0xa67d18*/
                      v340 += 4; /*0xa67d21*/
                      *(v340 - 5) = v346 + v430[3] * *(v338 - 3) + v343 * *(v338 - 2); /*0xa67d30*/
                      *(v340 - 4) = v430[0] * *(v338 - 4) + v430[4] * *(v338 - 3) + v341 * *(v338 - 2); /*0xa67d4e*/
                      *(v340 - 3) = v430[1] * *(v338 - 4) + v430[5] * *(v338 - 3) + v339 * *(v338 - 2); /*0xa67d6c*/
                      *(v340 - 2) = v430[2] * *(v338 - 4) + v344 * *(v338 - 3) + v337 * *(v338 - 2); /*0xa67d86*/
                      v345 = v429; /*0xa67d89*/
                      --n3_7; /*0xa67d8f*/
                    }
                    while ( n3_7 ); /*0xa67d90*/
                    p_n4_4 = p_n4_2; /*0xa67d92*/
                    b_13 = b_1; /*0xa67d9a*/
                    v349 = *(float **)(p_n4_2 + 44); /*0xa67da2*/
                    v415 = v349[12]; /*0xa67db0*/
                    v416 = v349[13]; /*0xa67db9*/
                    v417 = v349[14]; /*0xa67dc2*/
                    v418 = v349[15]; /*0xa67dd3*/
                    FFX_Math_Mat4x4MulVec4_Copy(v495, (float *)v413, (float *)((char *)v440 + LODWORD(b_1))); /*0xa67de5*/
                    for ( k = 0; k < 4; ++k ) /*0xa67def*/
                    {
                      if ( v495[k] < 0.0 ) /*0xa67dfa*/
                        v495[k] = 0.0; /*0xa67dfc*/
                    }
                    FFX_Math_Mat4x4MulVec4_Copy(v495, *(float **)(p_n4_4 + 36), v495); /*0xa67e10*/
                    v351 = 0.0; /*0xa67e15*/
                    for ( m = 0; m < 4; v495[m - 1] = *((float *)&v401 + 1) * v495[m - 1] ) /*0xa67e1a*/
                    {
                      if ( v495[m] < 0.0 ) /*0xa67e25*/
                        v495[m] = 0.0; /*0xa67e27*/
                      ++m; /*0xa67e31*/
                    }
                    n3 += 4; /*0xa67e42*/
                    v353 = v495[0] * *(float *)((char *)&v479 + LODWORD(b_13)); /*0xa67e49*/
                    LODWORD(b_14) = LODWORD(b_13) + 16; /*0xa67e50*/
                    b_1 = b_14; /*0xa67e53*/
                    *(float *)((char *)&v475 + LODWORD(b_14)) = v353; /*0xa67e59*/
                    *(float *)((char *)&v476 + LODWORD(b_14)) = v495[1] * *(float *)((char *)&v476 + LODWORD(b_14)); /*0xa67e6a*/
                    *(float *)((char *)&v477 + LODWORD(b_14)) = v495[2] * *(float *)((char *)&v477 + LODWORD(b_14)); /*0xa67e7b*/
                  }
                  while ( SLODWORD(b_14) < 64 ); /*0xa67e85*/
                  v4 = v387; /*0xa67e8b*/
                }
                else
                {
                  v351 = 0.0; /*0xa67e93*/
                }
                v355 = v4[5]; /*0xa67ea4*/
                v356 = 4 * v4[1]; /*0xa67ea9*/
                *((float *)v406 + 1) = v479 / 255.0; /*0xa67eae*/
                *(float *)(v355 + 4 * v356) = *((float *)v406 + 1); /*0xa67eba*/
                v357 = v4[5]; /*0xa67ec5*/
                *((float *)v406 + 1) = v480 / 255.0; /*0xa67ec8*/
                *(float *)(v357 + 4 * v356 + 4) = *((float *)v406 + 1); /*0xa67ed4*/
                v358 = v4[5]; /*0xa67ee0*/
                *((float *)v406 + 1) = v481 / 255.0; /*0xa67ee3*/
                *(float *)(v358 + 4 * v356 + 8) = *((float *)v406 + 1); /*0xa67eef*/
                v359 = v4[5]; /*0xa67efb*/
                *((float *)v406 + 1) = v482 / 255.0; /*0xa67efe*/
                *(float *)(v359 + 4 * v356 + 12) = *((float *)v406 + 1); /*0xa67f0a*/
                v360 = v4[5]; /*0xa67f16*/
                *((float *)v406 + 1) = v483 / 255.0; /*0xa67f19*/
                *(float *)(v360 + 4 * v356 + 16) = *((float *)v406 + 1); /*0xa67f25*/
                v361 = v4[5]; /*0xa67f31*/
                *((float *)v406 + 1) = v484 / 255.0; /*0xa67f34*/
                *(float *)(v361 + 4 * v356 + 20) = *((float *)v406 + 1); /*0xa67f40*/
                v362 = v4[5]; /*0xa67f4c*/
                *((float *)v406 + 1) = v485 / 255.0; /*0xa67f4f*/
                *(float *)(v362 + 4 * v356 + 24) = *((float *)v406 + 1); /*0xa67f5b*/
                v363 = v4[5]; /*0xa67f67*/
                *((float *)v406 + 1) = v486 / 255.0; /*0xa67f6a*/
                *(float *)(v363 + 4 * v356 + 28) = *((float *)v406 + 1); /*0xa67f76*/
                v364 = v4[5]; /*0xa67f82*/
                *((float *)v406 + 1) = v487 / 255.0; /*0xa67f85*/
                *(float *)(v364 + 4 * v356 + 32) = *((float *)v406 + 1); /*0xa67f91*/
                v365 = v4[5]; /*0xa67f9a*/
                *((float *)v406 + 1) = v488 / 255.0; /*0xa67f9d*/
                *(float *)(v365 + 4 * v356 + 36) = *((float *)v406 + 1); /*0xa67fa9*/
                v366 = v4[5]; /*0xa67fb2*/
                *((float *)v406 + 1) = v489 / 255.0; /*0xa67fb5*/
                *(float *)(v366 + 4 * v356 + 40) = *((float *)v406 + 1); /*0xa67fc1*/
                v367 = v4[5]; /*0xa67fca*/
                *((float *)v406 + 1) = v490 / 255.0; /*0xa67fcd*/
                *(float *)(v367 + 4 * v356 + 44) = *((float *)v406 + 1); /*0xa67fd9*/
                v368 = v4[5]; /*0xa67fe2*/
                *((float *)v406 + 1) = v491 / 255.0; /*0xa67fe5*/
                *(float *)(v368 + 4 * v356 + 48) = *((float *)v406 + 1); /*0xa67ff1*/
                v369 = v4[5]; /*0xa67ff5*/
                *((float *)v406 + 1) = v492 / 255.0; /*0xa67ffd*/
                *(float *)(v369 + 4 * v356 + 52) = *((float *)v406 + 1); /*0xa68009*/
                v370 = v4[5]; /*0xa68012*/
                *((float *)v406 + 1) = v493 / 255.0; /*0xa68015*/
                *(float *)(v370 + 4 * v356 + 56) = *((float *)v406 + 1); /*0xa68021*/
                v371 = v4[5]; /*0xa68025*/
                *((float *)v406 + 1) = v494 / 255.0; /*0xa6802b*/
                *(float *)(v371 + 4 * v356 + 60) = *((float *)v406 + 1); /*0xa68037*/
                v372 = v393; /*0xa6803b*/
                v373 = v4[1]; /*0xa68041*/
                v374 = v394; /*0xa68044*/
                v375 = v4[2]; /*0xa6804a*/
                v376 = v402; /*0xa6804d*/
                v377 = v373 + 1; /*0xa68056*/
                *(_WORD *)(v4[7] + 2 * v375) = v373; /*0xa68059*/
                *(_WORD *)(v4[7] + 2 * v375 + 2) = v373 + 1; /*0xa68063*/
                *(_WORD *)(v4[7] + 2 * v375 + 4) = v373 + 2; /*0xa6806b*/
                *(_WORD *)(v4[7] + 2 * v375 + 6) = v373 + 2; /*0xa68073*/
                LOWORD(v356) = v373 + 3; /*0xa6807b*/
                p_n4_1 = p_n4_2; /*0xa6807e*/
                *(_WORD *)(v4[7] + 2 * v375 + 8) = v377; /*0xa68084*/
                *(_WORD *)(v4[7] + 2 * v375 + 10) = v356; /*0xa6808c*/
                v378 = v395; /*0xa68091*/
                v4[1] += 4; /*0xa68097*/
                v4[2] += 6; /*0xa6809b*/
                v379 = v378[1]; /*0xa680ab*/
                v9 = v396 + 32; /*0xa680b0*/
                ++LODWORD(v404); /*0xa680b3*/
                v396 += 32; /*0xa680b9*/
                if ( SLODWORD(v404) >= v379 ) /*0xa680c1*/
                  break; /*0xa680c1*/
                v260 = v376; /*0xa67336*/
                v259 = v351; /*0xa67338*/
                v23 = v372; /*0xa67338*/
                v25 = v374; /*0xa6733c*/
                v258 = v260; /*0xa6733e*/
              }
LABEL_14:
              v24 = v395; /*0xa66083*/
              v23 = v393; /*0xa6608b*/
              v22 = v391; /*0xa66091*/
              v25 = v394; /*0xa66097*/
              v26 = v399; /*0xa6609d*/
              v27 = v402; /*0xa660a3*/
              v28 = v403; /*0xa660a9*/
            }
            break; /*0xa660af*/
          case 7: /*0xa65b24*/
            v380 = v24[1]; /*0xa680d2*/
            if ( v380 > 0 ) /*0xa680d8*/
            {
              v186 = 48 * v380; /*0xa680dd*/
LABEL_72:
              v9 += v186; /*0xa680e0*/
            }
            break; /*0xa680e0*/
          default:
            break;
        }
        v22 -= v24[1]; /*0xa680e2*/
        v24 = (__int16 *)v9; /*0xa680e8*/
        v9 += 16; /*0xa680ea*/
        v391 = v22; /*0xa680ed*/
        v395 = v24; /*0xa680f3*/
      }
      while ( v22 > 0 ); /*0xa680fb*/
    }
  }
  return 0; /*0xa68115*/
}