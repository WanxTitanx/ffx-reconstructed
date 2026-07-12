// Function: sub_A657C0
// Address: 0xa657c0
// Size: 0x295e
// Prototype: _DWORD __cdecl(int, int *p_n4, int n3)

int __cdecl sub_A657C0(int a1, int *p_n4, int n3)
{
  int *p_n4_1; // esi
  int v4; // eax
  _DWORD *v5; // ebx
  int v6; // edx
  unsigned __int8 *v7; // edx
  int v8; // ecx
  float *v9; // eax
  unsigned __int8 *v10; // edi
  double v11; // st7
  double v12; // st7
  int v13; // eax
  double v14; // st6
  double v15; // st5
  float *v16; // ebx
  float *v17; // esi
  int v18; // edi
  bool v19; // zf
  double v20; // st7
  int v21; // edx
  double v22; // st7
  __int16 *v23; // ecx
  double v24; // st6
  double v25; // st5
  double v26; // st4
  double v27; // st3
  int v28; // edx
  int v29; // ecx
  int v30; // eax
  double v31; // st2
  double v32; // st4
  int v33; // eax
  double v34; // st2
  double v35; // st3
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  double v40; // st7
  float v41; // eax
  double v42; // st7
  float v43; // eax
  double v44; // st7
  float v45; // eax
  double v46; // st7
  float v47; // eax
  double v48; // st7
  double v49; // st7
  float v50; // eax
  double v51; // st7
  float v52; // eax
  double v53; // st7
  float v54; // eax
  double v55; // st7
  float v56; // eax
  double v57; // st7
  float v58; // eax
  double v59; // st7
  int v60; // eax
  int v61; // ecx
  int v62; // eax
  int v63; // eax
  int v64; // eax
  int v65; // eax
  int v66; // eax
  int v67; // eax
  int v68; // eax
  int v69; // eax
  int v70; // eax
  int v71; // eax
  int v72; // eax
  int v73; // edx
  int v74; // esi
  __int16 *v75; // eax
  int n3_2; // eax
  double v77; // st5
  double v78; // st4
  double v79; // rtt
  int v80; // edx
  int v81; // ecx
  int v82; // eax
  double v83; // st3
  double v84; // st5
  int v85; // eax
  double v86; // st2
  double v87; // st3
  int v88; // eax
  int v89; // eax
  int v90; // eax
  int v91; // eax
  double v92; // st7
  float v93; // eax
  double v94; // st7
  float v95; // eax
  double v96; // st7
  float v97; // eax
  double v98; // st7
  int v99; // eax
  double v100; // st7
  double v101; // st7
  int v102; // eax
  double v103; // st7
  float v104; // eax
  double v105; // st7
  float v106; // eax
  double v107; // st7
  float v108; // eax
  double v109; // st7
  int v110; // eax
  double v111; // st7
  int v112; // eax
  int v113; // eax
  int v114; // eax
  int v115; // eax
  int v116; // eax
  int v117; // eax
  int v118; // eax
  int n4; // esi
  int v120; // ecx
  int v121; // edx
  _BYTE *v122; // ebx
  float *n3_4; // eax
  float *v124; // edi
  double v125; // st6
  double v126; // st6
  double v127; // st5
  double v128; // st4
  double v129; // st3
  double v130; // st2
  double v131; // st1
  double v132; // st5
  double v133; // st3
  int n4_1; // eax
  float *v135; // ecx
  double v136; // st7
  double v137; // st7
  float *v138; // eax
  double v139; // st6
  float *v140; // ecx
  double v141; // st5
  int n3_5; // edx
  double v143; // st4
  double v144; // st3
  double v145; // st2
  double v146; // st2
  int *p_n4_3; // esi
  float v148; // ebx
  float *v149; // eax
  int i; // ecx
  double v151; // st7
  int j; // ecx
  double v153; // st6
  double v154; // st6
  int n48; // ebx
  int v156; // eax
  int v157; // ecx
  int v158; // eax
  int v159; // eax
  int v160; // eax
  int v161; // eax
  int v162; // eax
  int v163; // eax
  int v164; // eax
  int v165; // eax
  int v166; // eax
  int v167; // eax
  int v168; // eax
  int v169; // esi
  int v170; // edx
  double v171; // st6
  double v172; // st5
  double v173; // st4
  __int16 *v174; // eax
  int v175; // eax
  int v176; // eax
  int v177; // eax
  int v178; // eax
  int v179; // edx
  int v180; // ecx
  int v181; // eax
  double v182; // st2
  double v183; // st4
  int v184; // eax
  double v185; // st2
  double v186; // st3
  int v187; // eax
  int v188; // eax
  int v189; // eax
  int v190; // eax
  int v191; // eax
  int v192; // eax
  double v193; // st7
  int v194; // eax
  double v195; // st7
  int v196; // eax
  double v197; // st7
  int v198; // eax
  double v199; // st7
  int v200; // eax
  double v201; // st7
  int v202; // eax
  double v203; // st7
  int v204; // eax
  double v205; // st7
  int v206; // eax
  double v207; // st7
  int v208; // eax
  double v209; // st7
  int v210; // eax
  double v211; // st7
  int v212; // eax
  double v213; // st7
  int v214; // eax
  double v215; // st7
  int v216; // eax
  double v217; // st7
  int v218; // eax
  double v219; // st7
  int v220; // eax
  double v221; // st7
  int v222; // eax
  int v223; // ecx
  int v224; // eax
  int v225; // eax
  int v226; // eax
  int v227; // eax
  int v228; // eax
  int v229; // eax
  int v230; // eax
  int v231; // eax
  int v232; // eax
  int v233; // eax
  int v234; // eax
  int v235; // eax
  int v236; // eax
  int v237; // eax
  int v238; // eax
  int v239; // esi
  int v240; // edi
  __int16 *v241; // eax
  int v242; // eax
  double v243; // st5
  double v244; // st4
  double v245; // rtt
  int v246; // edx
  int v247; // ecx
  int v248; // eax
  double v249; // st3
  double v250; // st5
  int v251; // eax
  double v252; // st2
  double v253; // st3
  int v254; // eax
  int v255; // eax
  int v256; // eax
  int v257; // eax
  int v258; // eax
  int v259; // eax
  double v260; // st7
  int v261; // eax
  double v262; // st7
  int v263; // eax
  double v264; // st7
  int v265; // eax
  double v266; // st7
  int v267; // eax
  double v268; // st7
  int v269; // eax
  double v270; // st7
  int v271; // eax
  double v272; // st7
  int v273; // eax
  double v274; // st7
  int v275; // eax
  double v276; // st7
  int v277; // eax
  double v278; // st7
  int v279; // eax
  double v280; // st7
  int v281; // eax
  double v282; // st7
  int v283; // eax
  double v284; // st7
  int v285; // eax
  double v286; // st7
  int v287; // eax
  double v288; // st7
  int v289; // eax
  int v290; // eax
  int v291; // eax
  int v292; // eax
  int v293; // eax
  int v294; // eax
  int v295; // eax
  int v296; // eax
  int v297; // eax
  int n4_2; // esi
  int v299; // ecx
  int v300; // edx
  _BYTE *v301; // ebx
  float *n3_7; // eax
  float *v303; // edi
  double v304; // st6
  double v305; // st6
  double v306; // st5
  double v307; // st4
  double v308; // st3
  double v309; // st2
  double v310; // st1
  double v311; // st5
  double v312; // st3
  int n4_3; // eax
  float *v314; // ecx
  double v315; // st7
  double v316; // st7
  float *v317; // eax
  double v318; // st6
  float *v319; // ecx
  double v320; // st5
  int n3_8; // edx
  double v322; // st4
  double v323; // st3
  double v324; // st2
  double v325; // st2
  int *p_n4_4; // esi
  float v327; // ebx
  float *v328; // eax
  int k; // ecx
  double v330; // st7
  int m; // ecx
  double v332; // st6
  float v333; // ebx
  int v334; // eax
  int v335; // ecx
  int v336; // eax
  int v337; // eax
  int v338; // eax
  int v339; // eax
  int v340; // eax
  int v341; // eax
  int v342; // eax
  int v343; // eax
  int v344; // eax
  int v345; // eax
  int v346; // eax
  int v347; // eax
  int v348; // eax
  int v349; // eax
  int v350; // eax
  double v351; // st6
  int v352; // esi
  double v353; // st5
  int v354; // edi
  double v355; // st4
  __int16 v356; // dx
  __int16 *v357; // eax
  int v358; // eax
  int v359; // eax
  int v361; // [esp-14h] [ebp-45Ch]
  int v362; // [esp-14h] [ebp-45Ch]
  int v363; // [esp+0h] [ebp-448h] BYREF
  int v364; // [esp+4h] [ebp-444h] BYREF
  int v365; // [esp+8h] [ebp-440h]
  _DWORD *v366; // [esp+Ch] [ebp-43Ch]
  float v367; // [esp+10h] [ebp-438h]
  float v368; // [esp+14h] [ebp-434h]
  int v369; // [esp+18h] [ebp-430h]
  int v370; // [esp+1Ch] [ebp-42Ch]
  float v371; // [esp+20h] [ebp-428h]
  float v372; // [esp+24h] [ebp-424h]
  float v373; // [esp+28h] [ebp-420h]
  __int16 *v374; // [esp+2Ch] [ebp-41Ch]
  unsigned __int8 *v375; // [esp+30h] [ebp-418h]
  int *p_n4_2; // [esp+34h] [ebp-414h]
  float *n3_1; // [esp+38h] [ebp-410h]
  float v378; // [esp+3Ch] [ebp-40Ch]
  float v379; // [esp+40h] [ebp-408h]
  double v380; // [esp+44h] [ebp-404h]
  float v381; // [esp+4Ch] [ebp-3FCh]
  float v382; // [esp+50h] [ebp-3F8h]
  float v383; // [esp+54h] [ebp-3F4h]
  float v384; // [esp+58h] [ebp-3F0h]
  double v385[5]; // [esp+5Ch] [ebp-3ECh]
  char v386[4]; // [esp+84h] [ebp-3C4h] BYREF
  char v387; // [esp+88h] [ebp-3C0h] BYREF
  float v388; // [esp+B4h] [ebp-394h]
  float v389; // [esp+B8h] [ebp-390h]
  float v390; // [esp+BCh] [ebp-38Ch]
  float v391; // [esp+C0h] [ebp-388h]
  char v392[4]; // [esp+C4h] [ebp-384h] BYREF
  char v393; // [esp+C8h] [ebp-380h] BYREF
  float v394; // [esp+F4h] [ebp-354h]
  float v395; // [esp+F8h] [ebp-350h]
  float v396; // [esp+FCh] [ebp-34Ch]
  float v397; // [esp+100h] [ebp-348h]
  _BYTE v399[60]; // [esp+108h] [ebp-340h] BYREF
  _BYTE v401[60]; // [esp+148h] [ebp-300h] BYREF
  char v402; // [esp+184h] [ebp-2C4h] BYREF
  _BYTE v403[44]; // [esp+188h] [ebp-2C0h] BYREF
  float v404; // [esp+1B4h] [ebp-294h]
  float v405; // [esp+1B8h] [ebp-290h]
  float v406; // [esp+1BCh] [ebp-28Ch]
  float v407; // [esp+1C0h] [ebp-288h]
  float v408; // [esp+1C4h] [ebp-284h]
  float v409[16]; // [esp+1C8h] [ebp-280h] BYREF
  float v410[3]; // [esp+208h] [ebp-240h] BYREF
  float v411; // [esp+214h] [ebp-234h]
  float v412; // [esp+218h] [ebp-230h]
  float v413; // [esp+21Ch] [ebp-22Ch]
  float v414; // [esp+220h] [ebp-228h]
  float v415; // [esp+224h] [ebp-224h]
  float v416; // [esp+228h] [ebp-220h]
  float v417; // [esp+22Ch] [ebp-21Ch]
  float v418; // [esp+230h] [ebp-218h]
  float v419[16]; // [esp+244h] [ebp-204h] BYREF
  float v420[12]; // [esp+284h] [ebp-1C4h] BYREF
  float v421[4]; // [esp+2B4h] [ebp-194h] BYREF
  float v422; // [esp+2C4h] [ebp-184h] BYREF
  float n3_6[3]; // [esp+2C8h] [ebp-180h] BYREF
  float v424[4]; // [esp+2D4h] [ebp-174h] BYREF
  float v425[4]; // [esp+2E4h] [ebp-164h] BYREF
  float v426[4]; // [esp+2F4h] [ebp-154h] BYREF
  float v427; // [esp+304h] [ebp-144h] BYREF
  float n3_3[3]; // [esp+308h] [ebp-140h] BYREF
  float v429[4]; // [esp+314h] [ebp-134h] BYREF
  float v430[4]; // [esp+324h] [ebp-124h] BYREF
  float v431; // [esp+334h] [ebp-114h] BYREF
  float v432; // [esp+338h] [ebp-110h]
  float v433; // [esp+33Ch] [ebp-10Ch]
  float v434; // [esp+340h] [ebp-108h]
  float v435; // [esp+344h] [ebp-104h] BYREF
  float v436; // [esp+348h] [ebp-100h]
  float v437; // [esp+34Ch] [ebp-FCh]
  float v438; // [esp+350h] [ebp-F8h]
  float v439; // [esp+354h] [ebp-F4h] BYREF
  float v440; // [esp+358h] [ebp-F0h]
  float v441; // [esp+35Ch] [ebp-ECh]
  float v442; // [esp+360h] [ebp-E8h]
  float v443; // [esp+364h] [ebp-E4h] BYREF
  float v444; // [esp+368h] [ebp-E0h]
  float v445; // [esp+36Ch] [ebp-DCh]
  float v446; // [esp+370h] [ebp-D8h]
  float v447; // [esp+374h] [ebp-D4h] BYREF
  float v448; // [esp+378h] [ebp-D0h]
  float v449; // [esp+37Ch] [ebp-CCh]
  float v450; // [esp+380h] [ebp-C8h]
  float v451; // [esp+384h] [ebp-C4h] BYREF
  float v452; // [esp+388h] [ebp-C0h]
  float v453; // [esp+38Ch] [ebp-BCh]
  float v454; // [esp+390h] [ebp-B8h]
  float v455; // [esp+394h] [ebp-B4h] BYREF
  float v456; // [esp+398h] [ebp-B0h]
  float v457; // [esp+39Ch] [ebp-ACh]
  float v458; // [esp+3A0h] [ebp-A8h]
  float v459; // [esp+3A4h] [ebp-A4h] BYREF
  float v460; // [esp+3A8h] [ebp-A0h]
  float v461; // [esp+3ACh] [ebp-9Ch]
  float v462; // [esp+3B0h] [ebp-98h]
  float v463; // [esp+3B4h] [ebp-94h] BYREF
  float v464; // [esp+3B8h] [ebp-90h]
  float v465; // [esp+3BCh] [ebp-8Ch]
  float v466; // [esp+3C0h] [ebp-88h]
  float v467; // [esp+3C4h] [ebp-84h] BYREF
  float v468; // [esp+3C8h] [ebp-80h]
  float v469; // [esp+3CCh] [ebp-7Ch]
  float v470; // [esp+3D0h] [ebp-78h]
  float v471; // [esp+3D4h] [ebp-74h] BYREF
  float v472; // [esp+3D8h] [ebp-70h]
  float v473; // [esp+3DCh] [ebp-6Ch]
  float v474; // [esp+3E0h] [ebp-68h]
  float v475[4]; // [esp+3E4h] [ebp-64h] BYREF
  float v476; // [esp+3F4h] [ebp-54h] BYREF
  float v477; // [esp+3F8h] [ebp-50h]
  float v478[2]; // [esp+3FCh] [ebp-4Ch]
  float v479; // [esp+404h] [ebp-44h] BYREF
  float v480; // [esp+408h] [ebp-40h]
  float v481; // [esp+40Ch] [ebp-3Ch]
  float v482; // [esp+410h] [ebp-38h]
  float v483; // [esp+414h] [ebp-34h] BYREF
  float v484; // [esp+418h] [ebp-30h]
  float v485; // [esp+41Ch] [ebp-2Ch]
  float v486; // [esp+420h] [ebp-28h]
  float v487; // [esp+424h] [ebp-24h] BYREF
  float v488; // [esp+428h] [ebp-20h]
  float v489; // [esp+42Ch] [ebp-1Ch]
  float v490; // [esp+430h] [ebp-18h]
  float v491; // [esp+434h] [ebp-14h] BYREF
  float v492; // [esp+438h] [ebp-10h]
  float v493; // [esp+43Ch] [ebp-Ch]
  float v494; // [esp+440h] [ebp-8h]

  v491 = 1.0;
  v492 = 1.0;
  p_n4_1 = p_n4;
  v493 = 1.0;
  v494 = 1.0;
  p_n4_2 = p_n4;
  v4 = p_n4[17];
  v421[0] = 0.0078125;
  v421[1] = 0.0078125;
  v421[2] = 0.0078125;
  v421[3] = 0.0078125;
  v372 = *(float *)(v4 + 56);
  if ( !unk_12FB790 )
  {
    v5 = *(_DWORD **)(sub_639180("NoTexture", n3) + 148);
    v366 = v5;
    v6 = *(_DWORD *)(a1 + 4);
    v370 = *(__int16 *)(a1 + 16);
    v7 = (unsigned __int8 *)(a1 + v6);
    v369 = a1 + *(_DWORD *)(a1 + 8);
    v8 = a1 + *(_DWORD *)(a1 + 12);
    v9 = (float *)p_n4[8];
    v10 = v7 + 16;
    v374 = (__int16 *)v7;
    v365 = v8;
    v11 = v9[12];
    v375 = v7 + 16;
    v373 = v11 / v9[15] - 2048.0 + 256.0;
    v378 = v9[13] / v9[15] - 2048.0 + 208.0;
    sub_640F60(&v364, &v363);
    v384 = (float)v364;
    v12 = v384;
    v368 = 0.001953125 * v384;
    v384 = (float)v363;
    v13 = p_n4[8];
    v14 = v384;
    v367 = v384 / 416.0;
    v371 = *(float *)(v13 + 44);
    v15 = v371;
    if ( 0.0 == v371 )
    {
      v371 = 1.0;
      v15 = (float)1.0;
    }
    LODWORD(v384) = *((unsigned __int8 *)p_n4 + 24);
    v381 = v15 * (v367 * 4.0) / (v368 * 3.0);
    v382 = v12 * 0.5;
    v379 = 0.5 * v14;
    v385[0] = (double)SLODWORD(v384);
    LODWORD(v384) = *((unsigned __int8 *)p_n4 + 25);
    v491 = v385[0] * v491;
    v385[0] = (double)SLODWORD(v384);
    LODWORD(v384) = *((unsigned __int8 *)p_n4 + 26);
    v492 = v385[0] * v492;
    v385[0] = (double)SLODWORD(v384);
    LODWORD(v384) = *((unsigned __int8 *)p_n4 + 27);
    v493 = v385[0] * v493;
    v385[0] = (double)SLODWORD(v384);
    v494 = v385[0] * v494;
    sub_6ED710(&v491, v421, &v491);
    if ( (*(_BYTE *)p_n4 & 0x40) != 0 )
    {
      v16 = (float *)v403;
      v383 = *((float *)p_n4 + 11);
      v17 = (float *)(LODWORD(v383) + 8);
      v18 = LODWORD(v383) - (_DWORD)v403;
      n3_1 = (float *)3;
      do
      {
        v384 = sqrt(*(float *)((char *)v16 + v18) * *(float *)((char *)v16 + v18) + *(v17 - 1) * *(v17 - 1) + *v17 * *v17);
        v16 += 4;
        v17 += 4;
        v19 = n3_1 == (float *)1;
        n3_1 = (float *)((char *)n3_1 - 1);
        v384 = 1.0 / v384;
        v20 = v384;
        *(v16 - 5) = *(float *)((char *)v16 + v18 - 16) * v384;
        *(v16 - 4) = v20 * *(v17 - 5);
        *(v16 - 3) = v20 * *(v17 - 4);
        *(v16 - 2) = *(v17 - 3);
      }
      while ( !v19 );
      v5 = v366;
      v10 = v375;
      p_n4_1 = p_n4_2;
      v404 = *(float *)(LODWORD(v383) + 48);
      v405 = *(float *)(LODWORD(v383) + 52);
      v406 = *(float *)(LODWORD(v383) + 56);
      v407 = *(float *)(LODWORD(v383) + 60);
    }
    v21 = v370;
    if ( v370 > 0 )
    {
      v22 = v372;
      v23 = v374;
      v24 = v373;
      v25 = v378;
      v26 = v381;
      v27 = v382;
      do
      {
        switch ( *((_BYTE *)v23 + 1) )
        {
          case 0:
            n3_1 = 0;
            if ( v23[1] > 0 )
            {
              do
              {
                v28 = v369;
                v29 = 3 * v5[1];
                LODWORD(v384) = *(__int16 *)(v369 + 6 * *((unsigned __int16 *)v10 + 6));
                v385[0] = (double)SLODWORD(v384);
                v30 = v5[3];
                v31 = (v26 * v385[0] + v24) * v368;
                v32 = v368;
                v384 = v31 - v27;
                *(float *)(v30 + 4 * v29) = v384;
                LODWORD(v384) = *(__int16 *)(v28 + 6 * *((unsigned __int16 *)v10 + 6) + 2);
                v385[0] = (double)SLODWORD(v384);
                v33 = v5[3];
                v34 = v371;
                v35 = v367;
                v384 = (v385[0] * v371 + v25) * v367 - v379;
                *(float *)(v33 + 4 * v29 + 4) = v384;
                *(float *)(v5[3] + 4 * v29 + 8) = v22;
                LODWORD(v384) = *(__int16 *)(v28 + 6 * *((unsigned __int16 *)v10 + 7));
                v385[0] = (double)SLODWORD(v384);
                v36 = v5[3];
                v384 = (v385[0] * v381 + v24) * v32 - v382;
                *(float *)(v36 + 4 * v29 + 12) = v384;
                LODWORD(v384) = *(__int16 *)(v28 + 6 * *((unsigned __int16 *)v10 + 7) + 2);
                v385[0] = (double)SLODWORD(v384);
                v37 = v5[3];
                v384 = (v385[0] * v34 + v25) * v35 - v379;
                *(float *)(v37 + 4 * v29 + 16) = v384;
                *(float *)(v5[3] + 4 * v29 + 20) = v22;
                LODWORD(v384) = *(__int16 *)(v28 + 6 * *((unsigned __int16 *)v10 + 8));
                v385[0] = (double)SLODWORD(v384);
                v38 = v5[3];
                v384 = v32 * (v24 + v385[0] * v381) - v382;
                *(float *)(v38 + 4 * v29 + 24) = v384;
                LODWORD(v384) = *(__int16 *)(v28 + 6 * *((unsigned __int16 *)v10 + 8) + 2);
                v385[0] = (double)SLODWORD(v384);
                v39 = v5[3];
                v384 = v35 * (v25 + v34 * v385[0]) - v379;
                *(float *)(v39 + 4 * v29 + 28) = v384;
                *(float *)(v5[3] + 4 * v29 + 32) = v22;
                *(float *)(v5[4] + 4 * v29) = 0.0;
                *(float *)(v5[4] + 4 * v29 + 4) = 0.0;
                *(float *)(v5[4] + 4 * v29 + 8) = 1.0;
                *(float *)(v5[4] + 4 * v29 + 12) = 0.0;
                *(float *)(v5[4] + 4 * v29 + 16) = 0.0;
                *(float *)(v5[4] + 4 * v29 + 20) = 1.0;
                *(float *)(v5[4] + 4 * v29 + 24) = 0.0;
                *(float *)(v5[4] + 4 * v29 + 28) = 0.0;
                *(float *)(v5[4] + 4 * v29 + 32) = 1.0;
                LODWORD(v384) = *v10;
                v40 = (double)SLODWORD(v384);
                LODWORD(v384) = v10[1];
                LODWORD(v41) = v10[2];
                v447 = v40;
                v42 = (double)SLODWORD(v384);
                v384 = v41;
                LODWORD(v43) = v10[3];
                v448 = v42;
                v44 = (double)SLODWORD(v384);
                v384 = v43;
                LODWORD(v45) = v10[4];
                v449 = v44;
                v46 = (double)SLODWORD(v384);
                v384 = v45;
                LODWORD(v47) = v10[5];
                v450 = v46;
                v48 = (double)SLODWORD(v384);
                v384 = v47;
                v451 = v48;
                v49 = (double)SLODWORD(v47);
                LODWORD(v384) = v10[6];
                LODWORD(v50) = v10[7];
                v452 = v49;
                v51 = (double)SLODWORD(v384);
                v384 = v50;
                LODWORD(v52) = v10[8];
                v453 = v51;
                v53 = (double)SLODWORD(v384);
                v384 = v52;
                LODWORD(v54) = v10[9];
                v454 = v53;
                v55 = (double)SLODWORD(v384);
                v384 = v54;
                LODWORD(v56) = v10[10];
                v455 = v55;
                v57 = (double)SLODWORD(v384);
                v384 = v56;
                LODWORD(v58) = v10[11];
                v456 = v57;
                v59 = (double)SLODWORD(v384);
                v384 = v58;
                v457 = v59;
                v458 = (float)SLODWORD(v58);
                sub_6ED710(&v447, &v491, &v447);
                sub_6ED710(&v451, &v491, &v451);
                sub_6ED710(&v455, &v491, &v455);
                v60 = v5[5];
                v61 = 4 * v5[1];
                v384 = v447 / 255.0;
                *(float *)(v60 + 4 * v61) = v384;
                v62 = v5[5];
                v384 = v448 / 255.0;
                *(float *)(v62 + 4 * v61 + 4) = v384;
                v63 = v5[5];
                v384 = v449 / 255.0;
                *(float *)(v63 + 4 * v61 + 8) = v384;
                v64 = v5[5];
                v384 = v450 / 255.0;
                *(float *)(v64 + 4 * v61 + 12) = v384;
                v65 = v5[5];
                v384 = v451 / 255.0;
                *(float *)(v65 + 4 * v61 + 16) = v384;
                v66 = v5[5];
                v10 += 20;
                v384 = v452 / 255.0;
                *(float *)(v66 + 4 * v61 + 20) = v384;
                v67 = v5[5];
                v384 = v453 / 255.0;
                *(float *)(v67 + 4 * v61 + 24) = v384;
                v68 = v5[5];
                v384 = v454 / 255.0;
                *(float *)(v68 + 4 * v61 + 28) = v384;
                v69 = v5[5];
                v384 = v455 / 255.0;
                *(float *)(v69 + 4 * v61 + 32) = v384;
                v70 = v5[5];
                v384 = v456 / 255.0;
                *(float *)(v70 + 4 * v61 + 36) = v384;
                v71 = v5[5];
                v384 = v457 / 255.0;
                *(float *)(v71 + 4 * v61 + 40) = v384;
                v72 = v5[5];
                v384 = v458 / 255.0;
                *(float *)(v72 + 4 * v61 + 44) = v384;
                v22 = v372;
                v73 = v5[1];
                v24 = v373;
                v74 = v5[2];
                v25 = v378;
                v26 = v381;
                v27 = v382;
                *(_WORD *)(v5[7] + 2 * v74) = v73;
                *(_WORD *)(v5[7] + 2 * v74 + 2) = v73 + 1;
                *(_WORD *)(v5[7] + 2 * v74 + 4) = v73 + 2;
                v75 = v374;
                v5[1] += 3;
                v5[2] += 3;
                n3_2 = v75[1];
                n3_1 = (float *)((char *)n3_1 + 1);
              }
              while ( (int)n3_1 < n3_2 );
              goto LABEL_13;
            }
            break;
          case 1:
            v375 = v10;
            v384 = 0.0;
            if ( v23[1] > 0 )
            {
              v77 = v26;
              v78 = 0.0;
              while ( 1 )
              {
                v80 = v369;
                v81 = 3 * v5[1];
                LODWORD(v383) = *(__int16 *)(v369 + 6 * *((unsigned __int16 *)v10 + 6));
                v385[0] = (double)SLODWORD(v383);
                v82 = v5[3];
                v83 = (v77 * v385[0] + v24) * v368 - v382;
                v84 = v368;
                v383 = v83;
                *(float *)(v82 + 4 * v81) = v383;
                LODWORD(v383) = *(__int16 *)(v80 + 6 * *((unsigned __int16 *)v10 + 6) + 2);
                v385[0] = (double)SLODWORD(v383);
                v85 = v5[3];
                v86 = v371;
                v87 = v367;
                v383 = (v385[0] * v371 + v378) * v367 - v379;
                *(float *)(v85 + 4 * v81 + 4) = v383;
                *(float *)(v5[3] + 4 * v81 + 8) = v22;
                LODWORD(v383) = *(__int16 *)(v80 + 6 * *((unsigned __int16 *)v10 + 7));
                v385[0] = (double)SLODWORD(v383);
                v88 = v5[3];
                v383 = (v385[0] * v381 + v24) * v84 - v382;
                *(float *)(v88 + 4 * v81 + 12) = v383;
                LODWORD(v383) = *(__int16 *)(v80 + 6 * *((unsigned __int16 *)v10 + 7) + 2);
                v385[0] = (double)SLODWORD(v383);
                v89 = v5[3];
                v383 = (v385[0] * v86 + v378) * v87 - v379;
                *(float *)(v89 + 4 * v81 + 16) = v383;
                *(float *)(v5[3] + 4 * v81 + 20) = v22;
                LODWORD(v383) = *(__int16 *)(v80 + 6 * *((unsigned __int16 *)v10 + 8));
                v385[0] = (double)SLODWORD(v383);
                v90 = v5[3];
                v383 = v84 * (v24 + v385[0] * v381) - v382;
                *(float *)(v90 + 4 * v81 + 24) = v383;
                LODWORD(v383) = *(__int16 *)(v80 + 6 * *((unsigned __int16 *)v10 + 8) + 2);
                v385[0] = (double)SLODWORD(v383);
                v91 = v5[3];
                v383 = v87 * (v86 * v385[0] + v378) - v379;
                *(float *)(v91 + 4 * v81 + 28) = v383;
                *(float *)(v5[3] + 4 * v81 + 32) = v22;
                *(float *)(v5[4] + 4 * v81) = v78;
                *(float *)(v5[4] + 4 * v81 + 4) = v78;
                *(float *)(v5[4] + 4 * v81 + 8) = 1.0;
                *(float *)(v5[4] + 4 * v81 + 12) = v78;
                *(float *)(v5[4] + 4 * v81 + 16) = v78;
                *(float *)(v5[4] + 4 * v81 + 20) = 1.0;
                *(float *)(v5[4] + 4 * v81 + 24) = v78;
                *(float *)(v5[4] + 4 * v81 + 28) = v78;
                *(float *)(v5[4] + 4 * v81 + 32) = 1.0;
                LODWORD(v383) = *v10;
                v92 = (double)SLODWORD(v383);
                LODWORD(v383) = v10[1];
                LODWORD(v93) = v10[2];
                v479 = v92;
                v94 = (double)SLODWORD(v383);
                v383 = v93;
                LODWORD(v95) = v10[3];
                v480 = v94;
                v96 = (double)SLODWORD(v383);
                v383 = v95;
                LODWORD(v97) = v10[4];
                v481 = v96;
                v98 = (double)SLODWORD(v383);
                v383 = v97;
                v99 = v10[5];
                v482 = v98;
                v100 = (double)SLODWORD(v383);
                v383 = *(float *)&v99;
                v483 = v100;
                v101 = (double)v99;
                v102 = v10[6];
                v484 = v101;
                v383 = *(float *)&v102;
                v103 = (double)v102;
                LODWORD(v383) = v10[7];
                LODWORD(v104) = v10[8];
                v485 = v103;
                v105 = (double)SLODWORD(v383);
                v383 = v104;
                LODWORD(v106) = v10[9];
                v486 = v105;
                v107 = (double)SLODWORD(v383);
                v383 = v106;
                LODWORD(v108) = v10[10];
                v487 = v107;
                v109 = (double)SLODWORD(v383);
                v383 = v108;
                v110 = v10[11];
                v488 = v109;
                v111 = (double)SLODWORD(v383);
                v383 = *(float *)&v110;
                v489 = v111;
                v490 = (float)v110;
                sub_6ED710(&v479, &v491, &v479);
                sub_6ED710(&v483, &v491, &v483);
                sub_6ED710(&v487, &v491, &v487);
                if ( (*(_BYTE *)p_n4_1 & 0x40) != 0 )
                {
                  LODWORD(v383) = *((unsigned __int8 *)p_n4_1 + 77);
                  v385[0] = (double)SLODWORD(v383);
                  v112 = *((unsigned __int16 *)v10 + 6);
                  *((float *)v385 + 1) = v385[0] * 0.0078125;
                  LODWORD(v383) = *(__int16 *)(v369 + 6 * v112);
                  v427 = (float)SLODWORD(v383);
                  LODWORD(v383) = *(__int16 *)(v369 + 6 * v112 + 2);
                  n3_3[0] = (float)SLODWORD(v383);
                  LODWORD(v383) = *(__int16 *)(v369 + 6 * v112 + 4);
                  v113 = *((unsigned __int16 *)v10 + 7);
                  n3_3[1] = (float)SLODWORD(v383);
                  n3_3[2] = 1.0;
                  LODWORD(v383) = *(__int16 *)(v369 + 6 * v113);
                  v429[0] = (float)SLODWORD(v383);
                  LODWORD(v383) = *(__int16 *)(v369 + 6 * v113 + 2);
                  v429[1] = (float)SLODWORD(v383);
                  LODWORD(v383) = *(__int16 *)(v369 + 6 * v113 + 4);
                  v114 = *((unsigned __int16 *)v10 + 8);
                  v429[2] = (float)SLODWORD(v383);
                  v429[3] = 1.0;
                  LODWORD(v383) = *(__int16 *)(v369 + 6 * v114);
                  v430[0] = (float)SLODWORD(v383);
                  LODWORD(v383) = *(__int16 *)(v369 + 6 * v114 + 2);
                  v430[1] = (float)SLODWORD(v383);
                  LODWORD(v383) = *(__int16 *)(v369 + 6 * v114 + 4);
                  v115 = *((unsigned __int16 *)v10 + 10);
                  v430[2] = (float)SLODWORD(v383);
                  v430[3] = 1.0;
                  LODWORD(v383) = *(__int16 *)(v365 + 6 * v115);
                  v380 = (double)SLODWORD(v383);
                  v420[0] = v380 * 0.000244140625;
                  LODWORD(v383) = *(__int16 *)(v365 + 6 * v115 + 2);
                  v380 = (double)SLODWORD(v383);
                  v420[1] = v380 * 0.000244140625;
                  LODWORD(v383) = *(__int16 *)(v365 + 6 * v115 + 4);
                  v380 = (double)SLODWORD(v383);
                  v420[2] = v380 * 0.000244140625;
                  v116 = *((unsigned __int16 *)v10 + 11);
                  v420[3] = 0.0;
                  LODWORD(v383) = *(__int16 *)(v365 + 6 * v116);
                  v380 = (double)SLODWORD(v383);
                  v420[4] = v380 * 0.000244140625;
                  LODWORD(v383) = *(__int16 *)(v365 + 6 * v116 + 2);
                  v380 = (double)SLODWORD(v383);
                  v420[5] = v380 * 0.000244140625;
                  LODWORD(v383) = *(__int16 *)(v365 + 6 * v116 + 4);
                  v380 = (double)SLODWORD(v383);
                  v117 = *((unsigned __int16 *)v10 + 12);
                  v420[6] = v380 * 0.000244140625;
                  v420[7] = 0.0;
                  LODWORD(v383) = *(__int16 *)(v365 + 6 * v117);
                  v380 = (double)SLODWORD(v383);
                  v420[8] = v380 * 0.000244140625;
                  LODWORD(v383) = *(__int16 *)(v365 + 6 * v117 + 2);
                  v380 = (double)SLODWORD(v383);
                  v420[9] = v380 * 0.000244140625;
                  LODWORD(v383) = *(__int16 *)(v365 + 6 * v117 + 4);
                  v380 = (double)SLODWORD(v383);
                  v361 = p_n4_1[11];
                  v420[10] = 0.000244140625 * v380;
                  v420[11] = 0.0;
                  sub_6ED420(&v427, v361, &v427);
                  sub_6ED420(v429, p_n4_1[11], v429);
                  sub_6ED420(v430, p_n4_1[11], v430);
                  n3_1 = n3_3;
                  v383 = 0.0;
                  do
                  {
                    v118 = p_n4_2[10];
                    n4 = 0;
                    v120 = v118 + 12;
                    v121 = v118 + 8;
                    v122 = &v399[-v118 - 4];
                    n3_4 = n3_1;
                    v124 = (float *)v399;
                    do
                    {
                      ++n4;
                      v125 = *(float *)(v121 - 8) - *(n3_4 - 1);
                      v121 += 16;
                      v124 += 4;
                      v120 += 16;
                      *((float *)&v380 + 1) = v125;
                      v126 = *((float *)&v380 + 1);
                      v127 = *((float *)&v380 + 1);
                      *((float *)&v380 + 1) = *(float *)(v121 - 20) - *n3_4;
                      v128 = *((float *)&v380 + 1);
                      v129 = *((float *)&v380 + 1);
                      *((float *)&v380 + 1) = *(float *)(v121 - 16) - n3_4[1];
                      v130 = *((float *)&v380 + 1);
                      v131 = v127;
                      v132 = *((float *)&v380 + 1);
                      *((float *)&v380 + 1) = v131 * v131 + 0.0;
                      *((float *)&v380 + 1) = *((float *)&v380 + 1) + v129 * v129;
                      *((float *)&v380 + 1) = *((float *)&v380 + 1) + v132 * v132;
                      v133 = *((float *)&v380 + 1);
                      *((float *)&v385[2] + n4 + 1) = *((float *)&v380 + 1);
                      *((float *)&v380 + 1) = v126 * *(float *)(v120 - 16);
                      *(v124 - 5) = *((float *)&v380 + 1) / v133;
                      *((float *)&v380 + 1) = v128 * *(float *)(v120 - 16);
                      *(v124 - 4) = *((float *)&v380 + 1) / v133;
                      *((float *)&v380 + 1) = v130 * *(float *)(v120 - 16);
                      *(float *)&v122[v121 - 16] = *((float *)&v380 + 1) / v133;
                      *(float *)&v122[v120 - 16] = 0.0;
                    }
                    while ( n4 < 4 );
                    n4_1 = 0;
                    v135 = v410;
                    do
                    {
                      v136 = *(float *)&v399[4 * n4_1++ - 4];
                      *(v135 - 1) = v136;
                      v135 += 4;
                      *(v135 - 4) = *(float *)&v399[4 * n4_1 + 8];
                      *(v135 - 3) = *(float *)&v399[4 * n4_1 + 24];
                      *(v135 - 2) = *(float *)&v399[4 * n4_1 + 40];
                    }
                    while ( n4_1 < 4 );
                    v137 = v418;
                    v138 = (float *)&v402;
                    v139 = v417;
                    v140 = (float *)&v387;
                    v141 = v416;
                    n3_5 = 3;
                    v143 = v415;
                    v144 = v414;
                    v145 = v411;
                    do
                    {
                      v146 = v145 * v138[1];
                      v138 += 4;
                      v140 += 4;
                      *(v140 - 5) = v146 + v409[15] * *(v138 - 4) + v143 * *(v138 - 2);
                      *(v140 - 4) = v412 * *(v138 - 3) + v410[0] * *(v138 - 4) + v141 * *(v138 - 2);
                      *(v140 - 3) = v413 * *(v138 - 3) + v410[1] * *(v138 - 4) + v139 * *(v138 - 2);
                      *(v140 - 2) = v144 * *(v138 - 3) + v410[2] * *(v138 - 4) + v137 * *(v138 - 2);
                      v145 = v411;
                      --n3_5;
                    }
                    while ( n3_5 );
                    p_n4_3 = p_n4_2;
                    v148 = v383;
                    v149 = (float *)p_n4_2[11];
                    v388 = v149[12];
                    v389 = v149[13];
                    v390 = v149[14];
                    v391 = v149[15];
                    sub_6ED420(&v476, v386, (char *)v420 + LODWORD(v383));
                    for ( i = 0; i < 4; ++i )
                    {
                      if ( *(&v476 + i) < 0.0 )
                        *(&v476 + i) = 0.0;
                    }
                    sub_6ED420(&v476, p_n4_3[9], &v476);
                    v151 = 0.0;
                    for ( j = 0; j < 4; v475[j + 3] = v153 * *((float *)v385 + 1) )
                    {
                      if ( *(&v476 + j) < 0.0 )
                        *(&v476 + j) = 0.0;
                      v153 = *(&v476 + j++);
                    }
                    n3_1 += 4;
                    v154 = v476 * *(float *)((char *)&v479 + LODWORD(v148));
                    n48 = LODWORD(v148) + 16;
                    v383 = *(float *)&n48;
                    *(float *)((char *)&v476 + n48) = v154;
                    *(float *)((char *)&v478[-1] + n48) = v477 * *(float *)((char *)&v478[-1] + n48);
                    *(float *)((char *)v478 + n48) = v478[0] * *(float *)((char *)v478 + n48);
                  }
                  while ( n48 < 48 );
                  v5 = v366;
                  v10 = v375;
                }
                else
                {
                  v151 = 0.0;
                }
                v156 = v5[5];
                v157 = 4 * v5[1];
                *((float *)v385 + 1) = v479 / 255.0;
                *(float *)(v156 + 4 * v157) = *((float *)v385 + 1);
                v158 = v5[5];
                *((float *)v385 + 1) = v480 / 255.0;
                *(float *)(v158 + 4 * v157 + 4) = *((float *)v385 + 1);
                v159 = v5[5];
                *((float *)v385 + 1) = v481 / 255.0;
                *(float *)(v159 + 4 * v157 + 8) = *((float *)v385 + 1);
                v160 = v5[5];
                *((float *)v385 + 1) = v482 / 255.0;
                *(float *)(v160 + 4 * v157 + 12) = *((float *)v385 + 1);
                v161 = v5[5];
                *((float *)v385 + 1) = v483 / 255.0;
                *(float *)(v161 + 4 * v157 + 16) = *((float *)v385 + 1);
                v162 = v5[5];
                *((float *)v385 + 1) = v484 / 255.0;
                *(float *)(v162 + 4 * v157 + 20) = *((float *)v385 + 1);
                v163 = v5[5];
                *((float *)v385 + 1) = v485 / 255.0;
                *(float *)(v163 + 4 * v157 + 24) = *((float *)v385 + 1);
                v164 = v5[5];
                *((float *)v385 + 1) = v486 / 255.0;
                *(float *)(v164 + 4 * v157 + 28) = *((float *)v385 + 1);
                v165 = v5[5];
                *((float *)v385 + 1) = v487 / 255.0;
                *(float *)(v165 + 4 * v157 + 32) = *((float *)v385 + 1);
                v166 = v5[5];
                *((float *)v385 + 1) = v488 / 255.0;
                *(float *)(v166 + 4 * v157 + 36) = *((float *)v385 + 1);
                v167 = v5[5];
                *((float *)v385 + 1) = v489 / 255.0;
                *(float *)(v167 + 4 * v157 + 40) = *((float *)v385 + 1);
                v168 = v5[5];
                *((float *)v385 + 1) = v490 / 255.0;
                *(float *)(v168 + 4 * v157 + 44) = *((float *)v385 + 1);
                v169 = v5[2];
                v170 = v5[1];
                *(_WORD *)(v5[7] + 2 * v169) = v170;
                v171 = v372;
                *(_WORD *)(v5[7] + 2 * v169 + 2) = v170 + 1;
                v172 = v373;
                v173 = v381;
                *(_WORD *)(v5[7] + 2 * v169 + 4) = v170 + 2;
                v174 = v374;
                v5[1] += 3;
                v5[2] += 3;
                v175 = v174[1];
                p_n4_1 = p_n4_2;
                v10 += 28;
                ++LODWORD(v384);
                v375 = v10;
                if ( SLODWORD(v384) >= v175 )
                  break;
                v79 = v173;
                v78 = v151;
                v22 = v171;
                v24 = v172;
                v77 = v79;
              }
              v23 = v374;
              v21 = v370;
              v22 = v372;
              v24 = v373;
              v25 = v378;
              v26 = v381;
              v27 = v382;
            }
            break;
          case 2:
            v176 = v23[1];
            if ( v176 > 0 )
            {
              v177 = 32 * v176;
              goto LABEL_72;
            }
            break;
          case 3:
          case 6:
            v178 = v23[1];
            if ( v178 > 0 )
              v10 += 40 * v178;
            break;
          case 4:
            v375 = v10;
            v384 = 0.0;
            if ( v23[1] > 0 )
            {
              do
              {
                v179 = v369;
                v180 = 3 * v5[1];
                HIDWORD(v385[0]) = *(__int16 *)(v369 + 6 * *((unsigned __int16 *)v10 + 8));
                v385[0] = (double)SHIDWORD(v385[0]);
                v181 = v5[3];
                v182 = (v26 * v385[0] + v24) * v368;
                v183 = v368;
                *((float *)v385 + 1) = v182 - v27;
                *(float *)(v181 + 4 * v180) = *((float *)v385 + 1);
                HIDWORD(v385[0]) = *(__int16 *)(v179 + 6 * *((unsigned __int16 *)v10 + 8) + 2);
                v385[0] = (double)SHIDWORD(v385[0]);
                v184 = v5[3];
                v185 = v371;
                v186 = v367;
                *((float *)v385 + 1) = (v385[0] * v371 + v25) * v367 - v379;
                *(float *)(v184 + 4 * v180 + 4) = *((float *)v385 + 1);
                *(float *)(v5[3] + 4 * v180 + 8) = v22;
                HIDWORD(v385[0]) = *(__int16 *)(v179 + 6 * *((unsigned __int16 *)v10 + 9));
                v385[0] = (double)SHIDWORD(v385[0]);
                v187 = v5[3];
                *((float *)v385 + 1) = (v385[0] * v381 + v24) * v183 - v382;
                *(float *)(v187 + 4 * v180 + 12) = *((float *)v385 + 1);
                HIDWORD(v385[0]) = *(__int16 *)(v179 + 6 * *((unsigned __int16 *)v10 + 9) + 2);
                v385[0] = (double)SHIDWORD(v385[0]);
                v188 = v5[3];
                *((float *)v385 + 1) = (v385[0] * v185 + v25) * v186 - v379;
                *(float *)(v188 + 4 * v180 + 16) = *((float *)v385 + 1);
                *(float *)(v5[3] + 4 * v180 + 20) = v22;
                HIDWORD(v385[0]) = *(__int16 *)(v179 + 6 * *((unsigned __int16 *)v10 + 10));
                v385[0] = (double)SHIDWORD(v385[0]);
                v189 = v5[3];
                *((float *)v385 + 1) = (v385[0] * v381 + v24) * v183 - v382;
                *(float *)(v189 + 4 * v180 + 24) = *((float *)v385 + 1);
                HIDWORD(v385[0]) = *(__int16 *)(v179 + 6 * *((unsigned __int16 *)v10 + 10) + 2);
                v385[0] = (double)SHIDWORD(v385[0]);
                v190 = v5[3];
                *((float *)v385 + 1) = (v385[0] * v185 + v25) * v186 - v379;
                *(float *)(v190 + 4 * v180 + 28) = *((float *)v385 + 1);
                *(float *)(v5[3] + 4 * v180 + 32) = v22;
                HIDWORD(v385[0]) = *(__int16 *)(v179 + 6 * *((unsigned __int16 *)v10 + 11));
                v385[0] = (double)SHIDWORD(v385[0]);
                v191 = v5[3];
                *((float *)v385 + 1) = v183 * (v24 + v385[0] * v381) - v382;
                *(float *)(v191 + 4 * v180 + 36) = *((float *)v385 + 1);
                HIDWORD(v385[0]) = *(__int16 *)(v179 + 6 * *((unsigned __int16 *)v10 + 11) + 2);
                v385[0] = (double)SHIDWORD(v385[0]);
                v192 = v5[3];
                *((float *)v385 + 1) = v186 * (v25 + v185 * v385[0]) - v379;
                *(float *)(v192 + 4 * v180 + 40) = *((float *)v385 + 1);
                *(float *)(v5[3] + 4 * v180 + 44) = v22;
                *(float *)(v5[4] + 4 * v180) = 0.0;
                *(float *)(v5[4] + 4 * v180 + 4) = 0.0;
                *(float *)(v5[4] + 4 * v180 + 8) = 1.0;
                *(float *)(v5[4] + 4 * v180 + 12) = 0.0;
                *(float *)(v5[4] + 4 * v180 + 16) = 0.0;
                *(float *)(v5[4] + 4 * v180 + 20) = 1.0;
                *(float *)(v5[4] + 4 * v180 + 24) = 0.0;
                *(float *)(v5[4] + 4 * v180 + 28) = 0.0;
                *(float *)(v5[4] + 4 * v180 + 32) = 1.0;
                *(float *)(v5[4] + 4 * v180 + 36) = 0.0;
                *(float *)(v5[4] + 4 * v180 + 40) = 0.0;
                *(float *)(v5[4] + 4 * v180 + 44) = 1.0;
                HIDWORD(v385[0]) = *v10;
                v193 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v10[1];
                v194 = v10[2];
                v431 = v193;
                v195 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v194;
                v196 = v10[3];
                v432 = v195;
                v197 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v196;
                v198 = v10[4];
                v433 = v197;
                v199 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v198;
                v200 = v10[5];
                v434 = v199;
                v201 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v200;
                v202 = v10[6];
                v435 = v201;
                v203 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v202;
                v204 = v10[7];
                v436 = v203;
                v205 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v204;
                v206 = v10[8];
                v437 = v205;
                v207 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v206;
                v208 = v10[9];
                v438 = v207;
                v209 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v208;
                v210 = v10[10];
                v439 = v209;
                v211 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v210;
                v212 = v10[11];
                v440 = v211;
                v213 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v212;
                v214 = v10[12];
                v441 = v213;
                v215 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v214;
                v216 = v10[13];
                v442 = v215;
                v217 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v216;
                v218 = v10[14];
                v443 = v217;
                v219 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v218;
                v220 = v10[15];
                v444 = v219;
                v221 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v220;
                v445 = v221;
                v446 = (float)v220;
                sub_6ED710(&v431, &v491, &v431);
                sub_6ED710(&v435, &v491, &v435);
                sub_6ED710(&v439, &v491, &v439);
                sub_6ED710(&v443, &v491, &v443);
                v222 = v5[5];
                v223 = 4 * v5[1];
                *((float *)v385 + 1) = v431 / 255.0;
                *(float *)(v222 + 4 * v223) = *((float *)v385 + 1);
                v224 = v5[5];
                *((float *)v385 + 1) = v432 / 255.0;
                *(float *)(v224 + 4 * v223 + 4) = *((float *)v385 + 1);
                v225 = v5[5];
                *((float *)v385 + 1) = v433 / 255.0;
                *(float *)(v225 + 4 * v223 + 8) = *((float *)v385 + 1);
                v226 = v5[5];
                *((float *)v385 + 1) = v434 / 255.0;
                *(float *)(v226 + 4 * v223 + 12) = *((float *)v385 + 1);
                v227 = v5[5];
                *((float *)v385 + 1) = v435 / 255.0;
                *(float *)(v227 + 4 * v223 + 16) = *((float *)v385 + 1);
                v228 = v5[5];
                *((float *)v385 + 1) = v436 / 255.0;
                *(float *)(v228 + 4 * v223 + 20) = *((float *)v385 + 1);
                v229 = v5[5];
                *((float *)v385 + 1) = v437 / 255.0;
                *(float *)(v229 + 4 * v223 + 24) = *((float *)v385 + 1);
                v230 = v5[5];
                *((float *)v385 + 1) = v438 / 255.0;
                *(float *)(v230 + 4 * v223 + 28) = *((float *)v385 + 1);
                v231 = v5[5];
                *((float *)v385 + 1) = v439 / 255.0;
                *(float *)(v231 + 4 * v223 + 32) = *((float *)v385 + 1);
                v232 = v5[5];
                *((float *)v385 + 1) = v440 / 255.0;
                *(float *)(v232 + 4 * v223 + 36) = *((float *)v385 + 1);
                v233 = v5[5];
                *((float *)v385 + 1) = v441 / 255.0;
                *(float *)(v233 + 4 * v223 + 40) = *((float *)v385 + 1);
                v234 = v5[5];
                *((float *)v385 + 1) = v442 / 255.0;
                *(float *)(v234 + 4 * v223 + 44) = *((float *)v385 + 1);
                v235 = v5[5];
                *((float *)v385 + 1) = v443 / 255.0;
                *(float *)(v235 + 4 * v223 + 48) = *((float *)v385 + 1);
                v236 = v5[5];
                *((float *)v385 + 1) = v444 / 255.0;
                *(float *)(v236 + 4 * v223 + 52) = *((float *)v385 + 1);
                v237 = v5[5];
                *((float *)v385 + 1) = v445 / 255.0;
                *(float *)(v237 + 4 * v223 + 56) = *((float *)v385 + 1);
                v238 = v5[5];
                *((float *)v385 + 1) = v446 / 255.0;
                *(float *)(v238 + 4 * v223 + 60) = *((float *)v385 + 1);
                v22 = v372;
                v239 = v5[1];
                v24 = v373;
                v240 = v5[2];
                v25 = v378;
                v26 = v381;
                v27 = v382;
                *(_WORD *)(v5[7] + 2 * v240) = v239;
                *(_WORD *)(v5[7] + 2 * v240 + 2) = v239 + 1;
                *(_WORD *)(v5[7] + 2 * v240 + 4) = v239 + 2;
                *(_WORD *)(v5[7] + 2 * v240 + 6) = v239 + 2;
                *(_WORD *)(v5[7] + 2 * v240 + 8) = v239 + 1;
                *(_WORD *)(v5[7] + 2 * v240 + 10) = v239 + 3;
                v241 = v374;
                v5[1] += 4;
                v5[2] += 6;
                v242 = v241[1];
                v10 = v375 + 24;
                ++LODWORD(v384);
                v375 += 24;
              }
              while ( SLODWORD(v384) < v242 );
LABEL_13:
              p_n4_1 = p_n4_2;
              goto LABEL_14;
            }
            break;
          case 5:
            v375 = v10;
            v383 = 0.0;
            if ( v23[1] > 0 )
            {
              v243 = v26;
              v244 = 0.0;
              while ( 1 )
              {
                v246 = v369;
                v247 = 3 * v5[1];
                HIDWORD(v385[0]) = *(__int16 *)(v369 + 6 * *((unsigned __int16 *)v10 + 8));
                v385[0] = (double)SHIDWORD(v385[0]);
                v248 = v5[3];
                v249 = (v243 * v385[0] + v24) * v368 - v382;
                v250 = v368;
                *((float *)v385 + 1) = v249;
                *(float *)(v248 + 4 * v247) = *((float *)v385 + 1);
                HIDWORD(v385[0]) = *(__int16 *)(v246 + 6 * *((unsigned __int16 *)v10 + 8) + 2);
                v385[0] = (double)SHIDWORD(v385[0]);
                v251 = v5[3];
                v252 = v371;
                v253 = v367;
                *((float *)v385 + 1) = (v385[0] * v371 + v378) * v367 - v379;
                *(float *)(v251 + 4 * v247 + 4) = *((float *)v385 + 1);
                *(float *)(v5[3] + 4 * v247 + 8) = v22;
                HIDWORD(v385[0]) = *(__int16 *)(v246 + 6 * *((unsigned __int16 *)v10 + 9));
                v385[0] = (double)SHIDWORD(v385[0]);
                v254 = v5[3];
                *((float *)v385 + 1) = (v385[0] * v381 + v24) * v250 - v382;
                *(float *)(v254 + 4 * v247 + 12) = *((float *)v385 + 1);
                HIDWORD(v385[0]) = *(__int16 *)(v246 + 6 * *((unsigned __int16 *)v10 + 9) + 2);
                v385[0] = (double)SHIDWORD(v385[0]);
                v255 = v5[3];
                *((float *)v385 + 1) = (v385[0] * v252 + v378) * v253 - v379;
                *(float *)(v255 + 4 * v247 + 16) = *((float *)v385 + 1);
                *(float *)(v5[3] + 4 * v247 + 20) = v22;
                HIDWORD(v385[0]) = *(__int16 *)(v246 + 6 * *((unsigned __int16 *)v10 + 10));
                v385[0] = (double)SHIDWORD(v385[0]);
                v256 = v5[3];
                *((float *)v385 + 1) = (v385[0] * v381 + v24) * v250 - v382;
                *(float *)(v256 + 4 * v247 + 24) = *((float *)v385 + 1);
                HIDWORD(v385[0]) = *(__int16 *)(v246 + 6 * *((unsigned __int16 *)v10 + 10) + 2);
                v385[0] = (double)SHIDWORD(v385[0]);
                v257 = v5[3];
                *((float *)v385 + 1) = (v385[0] * v252 + v378) * v253 - v379;
                *(float *)(v257 + 4 * v247 + 28) = *((float *)v385 + 1);
                *(float *)(v5[3] + 4 * v247 + 32) = v22;
                HIDWORD(v385[0]) = *(__int16 *)(v246 + 6 * *((unsigned __int16 *)v10 + 11));
                v385[0] = (double)SHIDWORD(v385[0]);
                v258 = v5[3];
                *((float *)v385 + 1) = v250 * (v24 + v385[0] * v381) - v382;
                *(float *)(v258 + 4 * v247 + 36) = *((float *)v385 + 1);
                HIDWORD(v385[0]) = *(__int16 *)(v246 + 6 * *((unsigned __int16 *)v10 + 11) + 2);
                v385[0] = (double)SHIDWORD(v385[0]);
                v259 = v5[3];
                *((float *)v385 + 1) = v253 * (v252 * v385[0] + v378) - v379;
                *(float *)(v259 + 4 * v247 + 40) = *((float *)v385 + 1);
                *(float *)(v5[3] + 4 * v247 + 44) = v22;
                *(float *)(v5[4] + 4 * v247) = v244;
                *(float *)(v5[4] + 4 * v247 + 4) = v244;
                *(float *)(v5[4] + 4 * v247 + 8) = 1.0;
                *(float *)(v5[4] + 4 * v247 + 12) = v244;
                *(float *)(v5[4] + 4 * v247 + 16) = v244;
                *(float *)(v5[4] + 4 * v247 + 20) = 1.0;
                *(float *)(v5[4] + 4 * v247 + 24) = v244;
                *(float *)(v5[4] + 4 * v247 + 28) = v244;
                *(float *)(v5[4] + 4 * v247 + 32) = 1.0;
                *(float *)(v5[4] + 4 * v247 + 36) = v244;
                *(float *)(v5[4] + 4 * v247 + 40) = v244;
                *(float *)(v5[4] + 4 * v247 + 44) = 1.0;
                HIDWORD(v385[0]) = *v10;
                v260 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v10[1];
                v261 = v10[2];
                v459 = v260;
                v262 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v261;
                v263 = v10[3];
                v460 = v262;
                v264 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v263;
                v265 = v10[4];
                v461 = v264;
                v266 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v265;
                v267 = v10[5];
                v462 = v266;
                v268 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v267;
                v269 = v10[6];
                v463 = v268;
                v270 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v269;
                v271 = v10[7];
                v464 = v270;
                v272 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v271;
                v273 = v10[8];
                v465 = v272;
                v274 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v273;
                v275 = v10[9];
                v466 = v274;
                v276 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v275;
                v277 = v10[10];
                v467 = v276;
                v278 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v277;
                v279 = v10[11];
                v468 = v278;
                v280 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v279;
                v281 = v10[12];
                v469 = v280;
                v282 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v281;
                v283 = v10[13];
                v470 = v282;
                v284 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v283;
                v285 = v10[14];
                v471 = v284;
                v286 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v285;
                v287 = v10[15];
                v472 = v286;
                v288 = (double)SHIDWORD(v385[0]);
                HIDWORD(v385[0]) = v287;
                v473 = v288;
                v474 = (float)v287;
                sub_6ED710(&v459, &v491, &v459);
                sub_6ED710(&v463, &v491, &v463);
                sub_6ED710(&v467, &v491, &v467);
                sub_6ED710(&v471, &v491, &v471);
                if ( (*(_BYTE *)p_n4_1 & 0x40) != 0 )
                {
                  HIDWORD(v385[0]) = *((unsigned __int8 *)p_n4_1 + 77);
                  v385[0] = (double)SHIDWORD(v385[0]);
                  v289 = *((unsigned __int16 *)v10 + 8);
                  *((float *)&v380 + 1) = v385[0] * 0.0078125;
                  HIDWORD(v385[0]) = *(__int16 *)(v369 + 6 * v289);
                  v422 = (float)SHIDWORD(v385[0]);
                  HIDWORD(v385[0]) = *(__int16 *)(v369 + 6 * v289 + 2);
                  n3_6[0] = (float)SHIDWORD(v385[0]);
                  HIDWORD(v385[0]) = *(__int16 *)(v369 + 6 * v289 + 4);
                  v290 = *((unsigned __int16 *)v10 + 9);
                  n3_6[1] = (float)SHIDWORD(v385[0]);
                  n3_6[2] = 1.0;
                  HIDWORD(v385[0]) = *(__int16 *)(v369 + 6 * v290);
                  v424[0] = (float)SHIDWORD(v385[0]);
                  HIDWORD(v385[0]) = *(__int16 *)(v369 + 6 * v290 + 2);
                  v424[1] = (float)SHIDWORD(v385[0]);
                  HIDWORD(v385[0]) = *(__int16 *)(v369 + 6 * v290 + 4);
                  v291 = *((unsigned __int16 *)v10 + 10);
                  v424[2] = (float)SHIDWORD(v385[0]);
                  v424[3] = 1.0;
                  HIDWORD(v385[0]) = *(__int16 *)(v369 + 6 * v291);
                  v425[0] = (float)SHIDWORD(v385[0]);
                  HIDWORD(v385[0]) = *(__int16 *)(v369 + 6 * v291 + 2);
                  v425[1] = (float)SHIDWORD(v385[0]);
                  HIDWORD(v385[0]) = *(__int16 *)(v369 + 6 * v291 + 4);
                  v292 = *((unsigned __int16 *)v10 + 11);
                  v425[2] = (float)SHIDWORD(v385[0]);
                  v425[3] = 1.0;
                  HIDWORD(v385[0]) = *(__int16 *)(v369 + 6 * v292);
                  v426[0] = (float)SHIDWORD(v385[0]);
                  HIDWORD(v385[0]) = *(__int16 *)(v369 + 6 * v292 + 2);
                  v426[1] = (float)SHIDWORD(v385[0]);
                  HIDWORD(v385[0]) = *(__int16 *)(v369 + 6 * v292 + 4);
                  v293 = *((unsigned __int16 *)v10 + 12);
                  v426[2] = (float)SHIDWORD(v385[0]);
                  v426[3] = 1.0;
                  HIDWORD(v385[0]) = *(__int16 *)(v365 + 6 * v293);
                  *((float *)v385 + 1) = (float)SHIDWORD(v385[0]);
                  v419[0] = *((float *)v385 + 1) * 0.000244140625;
                  HIDWORD(v385[0]) = *(__int16 *)(v365 + 6 * v293 + 2);
                  *((float *)v385 + 1) = (float)SHIDWORD(v385[0]);
                  v419[1] = *((float *)v385 + 1) * 0.000244140625;
                  HIDWORD(v385[0]) = *(__int16 *)(v365 + 6 * v293 + 4);
                  *((float *)v385 + 1) = (float)SHIDWORD(v385[0]);
                  v294 = *((unsigned __int16 *)v10 + 13);
                  v419[2] = *((float *)v385 + 1) * 0.000244140625;
                  v419[3] = 0.0;
                  HIDWORD(v385[0]) = *(__int16 *)(v365 + 6 * v294);
                  *((float *)v385 + 1) = (float)SHIDWORD(v385[0]);
                  v419[4] = *((float *)v385 + 1) * 0.000244140625;
                  HIDWORD(v385[0]) = *(__int16 *)(v365 + 6 * v294 + 2);
                  *((float *)v385 + 1) = (float)SHIDWORD(v385[0]);
                  v419[5] = *((float *)v385 + 1) * 0.000244140625;
                  HIDWORD(v385[0]) = *(__int16 *)(v365 + 6 * v294 + 4);
                  *((float *)v385 + 1) = (float)SHIDWORD(v385[0]);
                  v295 = *((unsigned __int16 *)v10 + 14);
                  v419[6] = *((float *)v385 + 1) * 0.000244140625;
                  v419[7] = 0.0;
                  HIDWORD(v385[0]) = *(__int16 *)(v365 + 6 * v295);
                  *((float *)v385 + 1) = (float)SHIDWORD(v385[0]);
                  v419[8] = *((float *)v385 + 1) * 0.000244140625;
                  HIDWORD(v385[0]) = *(__int16 *)(v365 + 6 * v295 + 2);
                  *((float *)v385 + 1) = (float)SHIDWORD(v385[0]);
                  v419[9] = *((float *)v385 + 1) * 0.000244140625;
                  HIDWORD(v385[0]) = *(__int16 *)(v365 + 6 * v295 + 4);
                  *((float *)v385 + 1) = (float)SHIDWORD(v385[0]);
                  v296 = *((unsigned __int16 *)v10 + 15);
                  v419[10] = *((float *)v385 + 1) * 0.000244140625;
                  v419[11] = 0.0;
                  HIDWORD(v385[0]) = *(__int16 *)(v365 + 6 * v296);
                  *((float *)v385 + 1) = (float)SHIDWORD(v385[0]);
                  v419[12] = *((float *)v385 + 1) * 0.000244140625;
                  HIDWORD(v385[0]) = *(__int16 *)(v365 + 6 * v296 + 2);
                  *((float *)v385 + 1) = (float)SHIDWORD(v385[0]);
                  v419[13] = *((float *)v385 + 1) * 0.000244140625;
                  HIDWORD(v385[0]) = *(__int16 *)(v365 + 6 * v296 + 4);
                  *((float *)v385 + 1) = (float)SHIDWORD(v385[0]);
                  v362 = p_n4_1[11];
                  v419[14] = 0.000244140625 * *((float *)v385 + 1);
                  v419[15] = 0.0;
                  sub_6ED420(&v422, v362, &v422);
                  sub_6ED420(v424, p_n4_1[11], v424);
                  sub_6ED420(v425, p_n4_1[11], v425);
                  sub_6ED420(v426, p_n4_1[11], v426);
                  n3_1 = n3_6;
                  v384 = 0.0;
                  do
                  {
                    v297 = p_n4_2[10];
                    n4_2 = 0;
                    v299 = v297 + 12;
                    v300 = v297 + 8;
                    v301 = &v401[-v297 - 4];
                    n3_7 = n3_1;
                    v303 = (float *)v401;
                    do
                    {
                      ++n4_2;
                      v304 = *(float *)(v300 - 8) - *(n3_7 - 1);
                      v300 += 16;
                      v303 += 4;
                      v299 += 16;
                      *((float *)v385 + 1) = v304;
                      v305 = *((float *)v385 + 1);
                      v306 = *((float *)v385 + 1);
                      *((float *)v385 + 1) = *(float *)(v300 - 20) - *n3_7;
                      v307 = *((float *)v385 + 1);
                      v308 = *((float *)v385 + 1);
                      *((float *)v385 + 1) = *(float *)(v300 - 16) - n3_7[1];
                      v309 = *((float *)v385 + 1);
                      v310 = v306;
                      v311 = *((float *)v385 + 1);
                      *((float *)v385 + 1) = v310 * v310 + 0.0;
                      *((float *)v385 + 1) = *((float *)v385 + 1) + v308 * v308;
                      *((float *)v385 + 1) = *((float *)v385 + 1) + v311 * v311;
                      v312 = *((float *)v385 + 1);
                      *((float *)v385 + n4_2 + 1) = *((float *)v385 + 1);
                      *((float *)v385 + 1) = v305 * *(float *)(v299 - 16);
                      *(v303 - 5) = *((float *)v385 + 1) / v312;
                      *((float *)v385 + 1) = v307 * *(float *)(v299 - 16);
                      *(v303 - 4) = *((float *)v385 + 1) / v312;
                      *((float *)v385 + 1) = v309 * *(float *)(v299 - 16);
                      *(float *)&v301[v300 - 16] = *((float *)v385 + 1) / v312;
                      *(float *)&v301[v299 - 16] = 0.0;
                    }
                    while ( n4_2 < 4 );
                    n4_3 = 0;
                    v314 = v409;
                    do
                    {
                      v315 = *(float *)&v401[4 * n4_3++ - 4];
                      *(v314 - 1) = v315;
                      v314 += 4;
                      *(v314 - 4) = *(float *)&v401[4 * n4_3 + 8];
                      *(v314 - 3) = *(float *)&v401[4 * n4_3 + 24];
                      *(v314 - 2) = *(float *)&v401[4 * n4_3 + 40];
                    }
                    while ( n4_3 < 4 );
                    v316 = v409[10];
                    v317 = (float *)&v402;
                    v318 = v409[9];
                    v319 = (float *)&v393;
                    v320 = v409[8];
                    n3_8 = 3;
                    v322 = v409[7];
                    v323 = v409[6];
                    v324 = v408;
                    do
                    {
                      v325 = v324 * *v317;
                      v317 += 4;
                      v319 += 4;
                      *(v319 - 5) = v325 + v409[3] * *(v317 - 3) + v322 * *(v317 - 2);
                      *(v319 - 4) = v409[0] * *(v317 - 4) + v409[4] * *(v317 - 3) + v320 * *(v317 - 2);
                      *(v319 - 3) = v409[1] * *(v317 - 4) + v409[5] * *(v317 - 3) + v318 * *(v317 - 2);
                      *(v319 - 2) = v409[2] * *(v317 - 4) + v323 * *(v317 - 3) + v316 * *(v317 - 2);
                      v324 = v408;
                      --n3_8;
                    }
                    while ( n3_8 );
                    p_n4_4 = p_n4_2;
                    v327 = v384;
                    v328 = (float *)p_n4_2[11];
                    v394 = v328[12];
                    v395 = v328[13];
                    v396 = v328[14];
                    v397 = v328[15];
                    sub_6ED420(v475, v392, (char *)v419 + LODWORD(v384));
                    for ( k = 0; k < 4; ++k )
                    {
                      if ( v475[k] < 0.0 )
                        v475[k] = 0.0;
                    }
                    sub_6ED420(v475, p_n4_4[9], v475);
                    v330 = 0.0;
                    for ( m = 0; m < 4; v475[m - 1] = *((float *)&v380 + 1) * v475[m - 1] )
                    {
                      if ( v475[m] < 0.0 )
                        v475[m] = 0.0;
                      ++m;
                    }
                    n3_1 += 4;
                    v332 = v475[0] * *(float *)((char *)&v459 + LODWORD(v327));
                    LODWORD(v333) = LODWORD(v327) + 16;
                    v384 = v333;
                    *(float *)((char *)&v455 + LODWORD(v333)) = v332;
                    *(float *)((char *)&v456 + LODWORD(v333)) = v475[1] * *(float *)((char *)&v456 + LODWORD(v333));
                    *(float *)((char *)&v457 + LODWORD(v333)) = v475[2] * *(float *)((char *)&v457 + LODWORD(v333));
                  }
                  while ( SLODWORD(v333) < 64 );
                  v5 = v366;
                }
                else
                {
                  v330 = 0.0;
                }
                v334 = v5[5];
                v335 = 4 * v5[1];
                *((float *)v385 + 1) = v459 / 255.0;
                *(float *)(v334 + 4 * v335) = *((float *)v385 + 1);
                v336 = v5[5];
                *((float *)v385 + 1) = v460 / 255.0;
                *(float *)(v336 + 4 * v335 + 4) = *((float *)v385 + 1);
                v337 = v5[5];
                *((float *)v385 + 1) = v461 / 255.0;
                *(float *)(v337 + 4 * v335 + 8) = *((float *)v385 + 1);
                v338 = v5[5];
                *((float *)v385 + 1) = v462 / 255.0;
                *(float *)(v338 + 4 * v335 + 12) = *((float *)v385 + 1);
                v339 = v5[5];
                *((float *)v385 + 1) = v463 / 255.0;
                *(float *)(v339 + 4 * v335 + 16) = *((float *)v385 + 1);
                v340 = v5[5];
                *((float *)v385 + 1) = v464 / 255.0;
                *(float *)(v340 + 4 * v335 + 20) = *((float *)v385 + 1);
                v341 = v5[5];
                *((float *)v385 + 1) = v465 / 255.0;
                *(float *)(v341 + 4 * v335 + 24) = *((float *)v385 + 1);
                v342 = v5[5];
                *((float *)v385 + 1) = v466 / 255.0;
                *(float *)(v342 + 4 * v335 + 28) = *((float *)v385 + 1);
                v343 = v5[5];
                *((float *)v385 + 1) = v467 / 255.0;
                *(float *)(v343 + 4 * v335 + 32) = *((float *)v385 + 1);
                v344 = v5[5];
                *((float *)v385 + 1) = v468 / 255.0;
                *(float *)(v344 + 4 * v335 + 36) = *((float *)v385 + 1);
                v345 = v5[5];
                *((float *)v385 + 1) = v469 / 255.0;
                *(float *)(v345 + 4 * v335 + 40) = *((float *)v385 + 1);
                v346 = v5[5];
                *((float *)v385 + 1) = v470 / 255.0;
                *(float *)(v346 + 4 * v335 + 44) = *((float *)v385 + 1);
                v347 = v5[5];
                *((float *)v385 + 1) = v471 / 255.0;
                *(float *)(v347 + 4 * v335 + 48) = *((float *)v385 + 1);
                v348 = v5[5];
                *((float *)v385 + 1) = v472 / 255.0;
                *(float *)(v348 + 4 * v335 + 52) = *((float *)v385 + 1);
                v349 = v5[5];
                *((float *)v385 + 1) = v473 / 255.0;
                *(float *)(v349 + 4 * v335 + 56) = *((float *)v385 + 1);
                v350 = v5[5];
                *((float *)v385 + 1) = v474 / 255.0;
                *(float *)(v350 + 4 * v335 + 60) = *((float *)v385 + 1);
                v351 = v372;
                v352 = v5[1];
                v353 = v373;
                v354 = v5[2];
                v355 = v381;
                v356 = v352 + 1;
                *(_WORD *)(v5[7] + 2 * v354) = v352;
                *(_WORD *)(v5[7] + 2 * v354 + 2) = v352 + 1;
                *(_WORD *)(v5[7] + 2 * v354 + 4) = v352 + 2;
                *(_WORD *)(v5[7] + 2 * v354 + 6) = v352 + 2;
                LOWORD(v335) = v352 + 3;
                p_n4_1 = p_n4_2;
                *(_WORD *)(v5[7] + 2 * v354 + 8) = v356;
                *(_WORD *)(v5[7] + 2 * v354 + 10) = v335;
                v357 = v374;
                v5[1] += 4;
                v5[2] += 6;
                v358 = v357[1];
                v10 = v375 + 32;
                ++LODWORD(v383);
                v375 += 32;
                if ( SLODWORD(v383) >= v358 )
                  break;
                v245 = v355;
                v244 = v330;
                v22 = v351;
                v24 = v353;
                v243 = v245;
              }
LABEL_14:
              v23 = v374;
              v22 = v372;
              v21 = v370;
              v24 = v373;
              v25 = v378;
              v26 = v381;
              v27 = v382;
            }
            break;
          case 7:
            v359 = v23[1];
            if ( v359 > 0 )
            {
              v177 = 48 * v359;
LABEL_72:
              v10 += v177;
            }
            break;
          default:
            break;
        }
        v21 -= v23[1];
        v23 = (__int16 *)v10;
        v10 += 16;
        v370 = v21;
        v374 = v23;
      }
      while ( v21 > 0 );
    }
  }
  return 0;
}

