// Function: sub_9CC740
// Address: 0x9cc740
__int16 __userpurge sub_9CC740@<ax>(int a1@<ecx>, int a2@<ebp>, char a3@<efl>, float *a4, float *a5, float a6)
{
  float v6; // eax
  bool v7; // zf
  double v8; // st6
  float *v9; // edx
  double v10; // st6
  double v11; // st7
  double v12; // st6
  double v13; // st5
  float *v14; // edx
  double v15; // st7
  double v16; // st6
  double v17; // st5
  float *v18; // eax
  double v19; // st6
  float *v20; // eax
  float v21; // xmm0_4
  double v22; // st7
  double v23; // st6
  double v24; // st4
  float v25; // xmm0_4
  double v26; // st7
  float *v27; // ecx
  double v28; // st7
  double v29; // st7
  double v30; // st7
  double v31; // st7
  double v32; // st7
  double v33; // st7
  double v34; // st6
  float *v35; // eax
  double v36; // st6
  double v37; // st4
  double v38; // st3
  double v39; // st6
  double v40; // st4
  double v41; // st6
  double v42; // st5
  double v43; // rt1
  float *v44; // eax
  double v45; // st6
  double v46; // st6
  double v47; // st5
  double v48; // rt0
  double v49; // st4
  double v50; // st3
  double v51; // st7
  double v52; // st3
  double v53; // st2
  float v54; // xmm1_4
  double v55; // st7
  double v56; // st7
  double v57; // st6
  double v58; // st5
  double v59; // st4
  int v60; // eax
  double v61; // rt1
  double v62; // st4
  double v63; // st7
  float *v64; // eax
  float v65; // xmm0_4
  double v66; // st7
  double v67; // st5
  double v68; // st6
  double v69; // st4
  double v70; // st2
  double v71; // st3
  double v72; // st7
  double v73; // st3
  double v74; // st2
  float v75; // xmm0_4
  bool v76; // cf
  char v77; // sf
  char v78; // of
  char v79; // pf
  double v80; // st6
  double v81; // st7
  double v82; // st6
  float *v83; // eax
  double v84; // st5
  double v85; // st6
  double v86; // st4
  double v87; // st3
  float *v88; // eax
  double v89; // st5
  double v90; // st6
  float *v91; // eax
  double v92; // st7
  double v93; // st5
  double v94; // st6
  double v95; // st4
  float v96; // xmm0_4
  double v97; // st2
  double v98; // st3
  double v99; // st7
  double v100; // st3
  double v101; // st2
  float v102; // xmm0_4
  double v103; // st6
  double v104; // st7
  double v105; // st6
  double v106; // st5
  double v107; // st4
  double v108; // st5
  double v109; // st6
  float v110; // xmm0_4
  double v111; // st6
  float *v112; // eax
  double v113; // st7
  double v114; // st7
  double v115; // st7
  float v116; // xmm0_4
  float *v117; // eax
  double v118; // st5
  double v119; // st4
  double v120; // st6
  double v121; // st2
  double v122; // st3
  double v123; // st7
  double v124; // st3
  double v125; // st2
  float v126; // xmm0_4
  double v127; // st5
  double v128; // st4
  double v129; // st6
  double v130; // st5
  double v131; // st3
  double v132; // rt2
  double v133; // st3
  double v134; // st5
  double v135; // st4
  double v136; // st6
  double v137; // rt0
  double v138; // st5
  double v139; // st6
  float v140; // xmm0_4
  double v141; // st5
  float *v142; // eax
  bool v143; // cc
  double v144; // st7
  float v145; // xmm0_4
  float *v146; // eax
  float v147; // xmm0_4
  double v148; // st6
  double v149; // st5
  int v150; // eax
  double v151; // st6
  float v152; // xmm0_4
  double v153; // st3
  double v154; // st4
  double v155; // st5
  double v156; // st6
  double v157; // st7
  double v158; // st6
  float v160; // [esp+1Ch] [ebp-4FCh]
  float v161; // [esp+20h] [ebp-4F8h]
  float v162; // [esp+24h] [ebp-4F4h]
  float v163; // [esp+2Ch] [ebp-4ECh]
  float v164; // [esp+30h] [ebp-4E8h]
  float v165; // [esp+34h] [ebp-4E4h]
  float v166; // [esp+3Ch] [ebp-4DCh]
  float v167; // [esp+40h] [ebp-4D8h]
  float v168; // [esp+44h] [ebp-4D4h]
  float v169; // [esp+4Ch] [ebp-4CCh]
  float v170; // [esp+50h] [ebp-4C8h]
  float v171; // [esp+54h] [ebp-4C4h]
  float v172; // [esp+5Ch] [ebp-4BCh]
  float v173; // [esp+60h] [ebp-4B8h]
  float v174; // [esp+64h] [ebp-4B4h]
  float v175; // [esp+6Ch] [ebp-4ACh]
  float v176; // [esp+70h] [ebp-4A8h]
  float v177; // [esp+74h] [ebp-4A4h]
  int v178; // [esp+84h] [ebp-494h] BYREF
  int v179; // [esp+88h] [ebp-490h] BYREF
  float v180; // [esp+8Ch] [ebp-48Ch]
  float v181; // [esp+90h] [ebp-488h]
  float v182; // [esp+94h] [ebp-484h]
  float v183; // [esp+9Ch] [ebp-47Ch]
  float v184; // [esp+A0h] [ebp-478h]
  float v185; // [esp+A4h] [ebp-474h]
  float v186; // [esp+B0h] [ebp-468h] BYREF
  float v187; // [esp+B4h] [ebp-464h] BYREF
  float v188; // [esp+B8h] [ebp-460h] BYREF
  float v189; // [esp+BCh] [ebp-45Ch]
  float v190; // [esp+C0h] [ebp-458h]
  float v191; // [esp+C4h] [ebp-454h]
  int v192; // [esp+C8h] [ebp-450h]
  int v193; // [esp+D8h] [ebp-440h]
  float v194; // [esp+DCh] [ebp-43Ch] BYREF
  float v195; // [esp+E0h] [ebp-438h]
  float v196; // [esp+E4h] [ebp-434h]
  int v197; // [esp+E8h] [ebp-430h]
  float v198; // [esp+F8h] [ebp-420h] BYREF
  float v199; // [esp+FCh] [ebp-41Ch]
  float v200; // [esp+100h] [ebp-418h]
  float v201; // [esp+104h] [ebp-414h]
  float v202; // [esp+10Ch] [ebp-40Ch]
  float v203; // [esp+110h] [ebp-408h]
  float v204; // [esp+114h] [ebp-404h]
  int v205; // [esp+118h] [ebp-400h]
  float v206; // [esp+11Ch] [ebp-3FCh]
  float v207; // [esp+120h] [ebp-3F8h]
  float v208; // [esp+124h] [ebp-3F4h]
  int v209; // [esp+128h] [ebp-3F0h]
  float v210; // [esp+134h] [ebp-3E4h]
  float v211; // [esp+138h] [ebp-3E0h] BYREF
  float v212; // [esp+13Ch] [ebp-3DCh] BYREF
  float v213; // [esp+140h] [ebp-3D8h]
  float v214; // [esp+144h] [ebp-3D4h]
  int v215; // [esp+148h] [ebp-3D0h]
  float v216; // [esp+158h] [ebp-3C0h] BYREF
  float v217; // [esp+15Ch] [ebp-3BCh]
  float v218; // [esp+160h] [ebp-3B8h] BYREF
  float v219; // [esp+164h] [ebp-3B4h] BYREF
  float v220; // [esp+168h] [ebp-3B0h]
  float v221; // [esp+16Ch] [ebp-3ACh]
  float v222; // [esp+170h] [ebp-3A8h]
  float v223; // [esp+174h] [ebp-3A4h]
  int v224; // [esp+178h] [ebp-3A0h]
  float v225; // [esp+180h] [ebp-398h]
  float v226; // [esp+184h] [ebp-394h]
  float v227; // [esp+188h] [ebp-390h] BYREF
  float v228; // [esp+18Ch] [ebp-38Ch] BYREF
  float v229; // [esp+190h] [ebp-388h]
  float v230; // [esp+194h] [ebp-384h]
  int v231; // [esp+198h] [ebp-380h]
  float v232; // [esp+1A4h] [ebp-374h] BYREF
  float v233; // [esp+1A8h] [ebp-370h] BYREF
  int v234; // [esp+1ACh] [ebp-36Ch] BYREF
  int v235; // [esp+1ECh] [ebp-32Ch] BYREF
  float v236[16]; // [esp+22Ch] [ebp-2ECh] BYREF
  _DWORD v237[16]; // [esp+26Ch] [ebp-2ACh] BYREF
  _DWORD v238[16]; // [esp+2ACh] [ebp-26Ch] BYREF
  float v239[16]; // [esp+2ECh] [ebp-22Ch] BYREF
  float v240[16]; // [esp+32Ch] [ebp-1ECh] BYREF
  float v241; // [esp+36Ch] [ebp-1ACh]
  float v242; // [esp+370h] [ebp-1A8h]
  float v243; // [esp+374h] [ebp-1A4h]
  float v244; // [esp+37Ch] [ebp-19Ch]
  float v245; // [esp+380h] [ebp-198h]
  float v246; // [esp+384h] [ebp-194h]
  float v247; // [esp+38Ch] [ebp-18Ch]
  float v248; // [esp+390h] [ebp-188h]
  float v249; // [esp+394h] [ebp-184h]
  float v250; // [esp+39Ch] [ebp-17Ch]
  float v251; // [esp+3A0h] [ebp-178h]
  float v252; // [esp+3A4h] [ebp-174h]
  int v253; // [esp+3A8h] [ebp-170h]
  float v254; // [esp+3ACh] [ebp-16Ch] BYREF
  float v255; // [esp+3B0h] [ebp-168h]
  float v256; // [esp+3B4h] [ebp-164h]
  float v257; // [esp+3BCh] [ebp-15Ch]
  float v258; // [esp+3C0h] [ebp-158h]
  float v259; // [esp+3C4h] [ebp-154h]
  float v260; // [esp+3CCh] [ebp-14Ch]
  float v261; // [esp+3D0h] [ebp-148h]
  float v262; // [esp+3D4h] [ebp-144h]
  float v263; // [esp+3DCh] [ebp-13Ch]
  float v264; // [esp+3E0h] [ebp-138h]
  float v265; // [esp+3E4h] [ebp-134h]
  float v266; // [esp+3ECh] [ebp-12Ch] BYREF
  float v267; // [esp+3F0h] [ebp-128h]
  float v268; // [esp+3F4h] [ebp-124h]
  float v269; // [esp+3FCh] [ebp-11Ch]
  float v270; // [esp+400h] [ebp-118h]
  float v271; // [esp+404h] [ebp-114h]
  float v272; // [esp+40Ch] [ebp-10Ch]
  float v273; // [esp+410h] [ebp-108h]
  float v274; // [esp+414h] [ebp-104h]
  float v275; // [esp+41Ch] [ebp-FCh]
  float v276; // [esp+420h] [ebp-F8h]
  float v277; // [esp+424h] [ebp-F4h]
  float v278; // [esp+42Ch] [ebp-ECh]
  float v279; // [esp+430h] [ebp-E8h]
  float v280; // [esp+434h] [ebp-E4h]
  int v281; // [esp+438h] [ebp-E0h]
  float v282; // [esp+43Ch] [ebp-DCh]
  float v283; // [esp+440h] [ebp-D8h]
  float v284; // [esp+444h] [ebp-D4h]
  int v285; // [esp+448h] [ebp-D0h]
  float v286; // [esp+44Ch] [ebp-CCh]
  float v287; // [esp+450h] [ebp-C8h]
  float v288; // [esp+454h] [ebp-C4h]
  int v289; // [esp+458h] [ebp-C0h]
  float v290; // [esp+45Ch] [ebp-BCh]
  float v291; // [esp+460h] [ebp-B8h]
  float v292; // [esp+464h] [ebp-B4h]
  int v293; // [esp+468h] [ebp-B0h]
  float v294; // [esp+46Ch] [ebp-ACh]
  float v295; // [esp+470h] [ebp-A8h]
  float v296; // [esp+474h] [ebp-A4h]
  int v297; // [esp+478h] [ebp-A0h]
  float v298; // [esp+47Ch] [ebp-9Ch]
  float v299; // [esp+480h] [ebp-98h]
  float v300; // [esp+484h] [ebp-94h]
  int v301; // [esp+488h] [ebp-90h]
  int v302; // [esp+48Ch] [ebp-8Ch]
  int v303; // [esp+490h] [ebp-88h]
  int v304; // [esp+494h] [ebp-84h]
  int v305; // [esp+498h] [ebp-80h]
  int v306; // [esp+49Ch] [ebp-7Ch]
  int v307; // [esp+4A0h] [ebp-78h]
  int v308; // [esp+4A4h] [ebp-74h]
  int v309; // [esp+4A8h] [ebp-70h]
  int v310; // [esp+4ACh] [ebp-6Ch]
  int v311; // [esp+4B0h] [ebp-68h]
  int v312; // [esp+4B4h] [ebp-64h]
  int v313; // [esp+4B8h] [ebp-60h]
  float v314; // [esp+4BCh] [ebp-5Ch]
  float v315; // [esp+4C0h] [ebp-58h]
  float v316; // [esp+4C4h] [ebp-54h]
  int v317; // [esp+4C8h] [ebp-50h]
  float v318; // [esp+4CCh] [ebp-4Ch]
  float v319; // [esp+4D0h] [ebp-48h]
  float v320; // [esp+4D4h] [ebp-44h]
  int v321; // [esp+4D8h] [ebp-40h]
  float v322; // [esp+4DCh] [ebp-3Ch]
  float v323; // [esp+4E0h] [ebp-38h]
  float v324; // [esp+4E4h] [ebp-34h]
  int v325; // [esp+4E8h] [ebp-30h]
  float v326; // [esp+4ECh] [ebp-2Ch]
  float v327; // [esp+4F0h] [ebp-28h]
  float v328; // [esp+4F4h] [ebp-24h]
  int v329; // [esp+4F8h] [ebp-20h]
  _DWORD v330[3]; // [esp+50Ch] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+518h] [ebp+0h]

  v330[0] = a2;
  v330[1] = retaddr;
  LODWORD(v6) = (unsigned int)v330 ^ __security_cookie;
  v7 = *(_BYTE *)(a1 + 563) == 0;
  v193 = a1;
  if ( v7 )
    return LOWORD(v6);
  v6 = *(float *)(a1 + 20);
  v211 = *(float *)(a1 + 388);
  v217 = v6;
  v186 = *(float *)(a1 + 384);
  v218 = *(float *)(a1 + 392);
  v8 = v211;
  v211 = *(float *)(LODWORD(v6) + 24) * v218 + *(float *)(LODWORD(v6) + 20) * v211 + v186 * *(float *)(LODWORD(v6) + 16);
  v202 = v211 + *(float *)(LODWORD(v6) + 64);
  v211 = *(float *)(LODWORD(v6) + 36) * v8 + v186 * *(float *)(LODWORD(v6) + 32) + *(float *)(LODWORD(v6) + 40) * v218;
  v203 = v211 + *(float *)(LODWORD(v6) + 68);
  v211 = v218 * *(float *)(LODWORD(v6) + 56) + v8 * *(float *)(LODWORD(v6) + 52) + v186 * *(float *)(LODWORD(v6) + 48);
  v9 = *(float **)(a1 + 24);
  v218 = *(float *)&v9;
  v204 = v211 + *(float *)(LODWORD(v6) + 72);
  v211 = *(float *)(a1 + 452);
  v186 = *(float *)(a1 + 448);
  v219 = *(float *)(a1 + 456);
  v10 = v211;
  v211 = v9[6] * v219 + v9[5] * v211 + v186 * v9[4];
  v189 = v211 + v9[16];
  v211 = v9[9] * v10 + v186 * v9[8] + v9[10] * v219;
  v190 = v211 + v9[17];
  v211 = v219 * v9[14] + v10 * v9[13] + v186 * v9[12];
  v7 = *(_BYTE *)(a1 + 560) == 0;
  v191 = v211 + v9[18];
  if ( v7 )
  {
    v206 = v202 - *(float *)(LODWORD(v6) + 64);
    v207 = v203 - *(float *)(LODWORD(v6) + 68);
    v208 = v204 - *(float *)(LODWORD(v6) + 72);
    v11 = v189;
    v194 = v189 - v9[16];
    v12 = v190;
    v195 = v190 - v9[17];
    v13 = v191;
    v196 = v191 - v9[18];
    v189 = a4[84] + a4[148];
    v190 = a4[85] + a4[149];
    v191 = a4[86] + a4[150];
    v221 = v190 * v208 - v191 * v207;
    v222 = v191 * v206 - v189 * v208;
    v223 = v189 * v207 - v190 * v206;
    v189 = a4[80] + a4[144];
    v190 = a4[81] + a4[145];
    v191 = a4[82] + a4[146];
    v183 = v189 + v221;
    v184 = v190 + v222;
    v185 = v191 + v223;
    v189 = a5[84] + a5[148];
    v190 = a5[85] + a5[149];
    v191 = a5[86] + a5[150];
    LODWORD(v225) = a1 + 56;
    v14 = *(float **)(a1 + 24);
    LODWORD(v198) = 3;
    v221 = v190 * v196 - v191 * v195;
    v222 = v191 * v194 - v189 * v196;
    v223 = v189 * v195 - v190 * v194;
    v189 = a5[80] + a5[144];
    v190 = a5[81] + a5[145];
    v191 = a5[82] + a5[146];
    v180 = v189 + v221;
    v181 = v190 + v222;
    v182 = v191 + v223;
    v189 = v183 - v180;
    v190 = v184 - v181;
    v191 = v185 - v182;
    v221 = v202 - v11;
    v222 = v203 - v12;
    v223 = v204 - v13;
    v15 = v223;
    v16 = v222;
    v17 = v221;
    do
    {
      v18 = (float *)LODWORD(v225);
      v188 = 1.0 / *(float *)(LODWORD(v225) + 72);
      v226 = *(float *)(LODWORD(v225) - 4);
      v220 = *(float *)(LODWORD(v225) - 8);
      v210 = *(float *)LODWORD(v225);
      v219 = v15 * v210 + v16 * v226 + v17 * v220;
      v19 = -v219 * 0.300000011920929 / a6 * v188;
      v219 = v210 * v191 + v226 * v190 + v220 * v189;
      v232 = v19 - v188 * v219;
      *(float *)(a1 + 28) = *(float *)(a1 + 28) + v232;
      v210 = *v18;
      v226 = *(v18 - 1);
      v180 = v207 * v210 - v208 * v226;
      v220 = *(v18 - 2);
      v181 = v208 * v220 - v206 * v210;
      v20 = (float *)LODWORD(v217);
      v187 = *(float *)(LODWORD(v217) + 352);
      v21 = a4[88];
      v182 = v206 * v226 - v207 * v220;
      v166 = v195 * v210 - v196 * v226;
      v167 = v196 * v220 - v210 * v194;
      v168 = v194 * v226 - v195 * v220;
      v163 = v181 * v20[69] + v180 * v20[68] + v182 * v20[70];
      v164 = v181 * v20[73] + v180 * v20[72] + v182 * *(float *)(LODWORD(v217) + 296);
      v165 = v181 * *(float *)(LODWORD(v217) + 308)
           + v180 * *(float *)(LODWORD(v217) + 304)
           + v182 * *(float *)(LODWORD(v217) + 312);
      v183 = v220 * v187;
      v184 = v226 * v187;
      v185 = v187 * v210;
      if ( v21 != 0.0 )
      {
        v22 = v232;
        v202 = v183 * v232;
        v203 = v184 * v232;
        v204 = v185 * v232;
        a4[144] = v202 + a4[144];
        a4[145] = v203 + a4[145];
        a4[146] = v204 + a4[146];
        v175 = a4[152] * v22;
        v176 = a4[153] * v22;
        v177 = v22 * a4[154];
        v172 = v175 * v163;
        v173 = v176 * v164;
        v174 = v177 * v165;
        a4[148] = v172 + a4[148];
        a4[149] = v173 + a4[149];
        a4[150] = v174 + a4[150];
      }
      v23 = v167 * v14[69];
      v216 = v14[88];
      v24 = v166 * v14[68];
      LODWORD(v227) = LODWORD(v232) ^ 0x80000000;
      v25 = a5[88];
      v212 = v23 + v24 + v168 * v14[70];
      v213 = v167 * v14[73] + v166 * v14[72] + v168 * v14[74];
      v214 = v167 * v14[77] + v166 * v14[76] + v168 * v14[78];
      if ( v25 != 0.0 )
      {
        v26 = v227;
        v160 = *(float *)(LODWORD(v225) - 8) * v216;
        v169 = v160 * v227;
        v161 = *(float *)(LODWORD(v225) - 4) * v216;
        v170 = v161 * v227;
        v162 = v216 * *(float *)LODWORD(v225);
        v171 = v162 * v227;
        a5[144] = v169 + a5[144];
        a5[145] = v170 + a5[145];
        a5[146] = v171 + a5[146];
        v199 = v26 * a5[152];
        v200 = a5[153] * v26;
        v201 = v26 * a5[154];
        v228 = v199 * v212;
        v229 = v200 * v213;
        v230 = v201 * v214;
        a5[148] = v228 + a5[148];
        a5[149] = v229 + a5[149];
        a5[150] = v230 + a5[150];
      }
      LODWORD(v225) += 96;
      v15 = v223;
      v7 = LODWORD(v198)-- == 1;
      v16 = v222;
      v17 = v221;
    }
    while ( !v7 );
    v6 = v217;
  }
  if ( !*(_BYTE *)(a1 + 592) )
  {
    v227 = *(float *)(a1 + 476);
    if ( v227 <= 0.00000011920929 )
      goto LABEL_40;
    v212 = a4[84] + a4[148];
    v213 = a4[85] + a4[149];
    v214 = a4[86] + a4[150];
    v228 = a5[84] + a5[148];
    v229 = a5[85] + a5[149];
    v230 = a5[86] + a5[150];
    v221 = v228 - v212;
    v222 = v229 - v213;
    v223 = v230 - v214;
    v233 = v221 * v221 + v222 * v222 + v223 * v223;
    if ( v233 <= 0.00000011920929 )
      goto LABEL_40;
    v233 = sqrt(v233);
    v83 = (float *)LODWORD(v217);
    v233 = 1.0 / v233;
    v228 = v233 * v221;
    v229 = v233 * v222;
    v230 = v233 * v223;
    v84 = v229;
    v85 = v228;
    v86 = v230;
    v212 = v83[76] * v230 + v83[68] * v228 + v83[72] * v229;
    v213 = v83[73] * v229 + v83[69] * v228 + v83[77] * v230;
    v87 = v83[74] * v229 + v83[70] * v228;
    v88 = (float *)LODWORD(v218);
    v214 = v87 + *(float *)(LODWORD(v217) + 312) * v230;
    v228 = v88[72] * v229 + v88[68] * v228 + v88[76] * v230;
    v229 = v88[73] * v229 + v88[69] * v85 + v88[77] * v230;
    v230 = v88[74] * v84 + v88[70] * v85 + v88[78] * v230;
    v233 = v229 * v84 + v228 * v85 + v230 * v86;
    v89 = v85 * v212 + v84 * v213 + v86 * v214;
    v90 = v233;
    v233 = v89;
    v233 = 1.0 / (v90 + v233);
    v233 = v233 * v227;
    v202 = v233 * v221;
    v203 = v233 * v222;
    v204 = v233 * v223;
    v233 = v202 * v202 + v203 * v203 + v204 * v204;
    v233 = sqrt(v233);
    v91 = (float *)LODWORD(v217);
    v219 = v233;
    v92 = v233;
    v233 = 1.0 / v233;
    v228 = v233 * v202;
    v229 = v233 * v203;
    v230 = v233 * v204;
    v93 = v229;
    v94 = v228;
    v95 = v230;
    v212 = v91[70] * v230 + v91[68] * v228 + v91[69] * v229;
    v96 = a4[88];
    v213 = v91[73] * v229 + v228 * v91[72] + v91[74] * v230;
    v214 = v91[77] * v229 + v91[76] * v228 + *(float *)(LODWORD(v217) + 312) * v230;
    if ( v96 == 0.0 )
    {
      v99 = 0.0;
    }
    else
    {
      v233 = v92 * 0.0;
      v97 = v233;
      a4[144] = a4[144] + v233;
      a4[145] = a4[145] + v97;
      a4[146] = v97 + a4[146];
      v228 = a4[152] * v92;
      v229 = a4[153] * v92;
      v98 = v92 * a4[154];
      v99 = 0.0;
      v230 = v98;
      v199 = v228 * v212;
      v200 = v229 * v213;
      v201 = v230 * v214;
      a4[148] = a4[148] + v199;
      a4[149] = a4[149] + v200;
      a4[150] = v201 + a4[150];
    }
    v6 = v218;
    v100 = *(float *)(LODWORD(v218) + 276) * v93;
    v101 = *(float *)(LODWORD(v218) + 272);
    v233 = -v219;
    v102 = a5[88];
    v76 = v102 < 0.0;
    v79 = 0;
    v7 = v102 == 0.0;
    v77 = 0;
    v78 = 0;
    v212 = v100 + v101 * v94 + *(float *)(LODWORD(v218) + 280) * v95;
    v213 = *(float *)(LODWORD(v6) + 292) * v93
         + *(float *)(LODWORD(v6) + 288) * v94
         + *(float *)(LODWORD(v218) + 296) * v95;
    BYTE1(v6) = a3;
    v214 = v94 * *(float *)(LODWORD(v218) + 304)
         + v93 * *(float *)(LODWORD(v218) + 308)
         + v95 * *(float *)(LODWORD(v218) + 312);
    if ( v102 != 0.0 )
    {
      v103 = v99 * v233;
      v81 = v233;
      v233 = v103;
      v82 = v233;
      goto LABEL_31;
    }
LABEL_39:
    a1 = v193;
    goto LABEL_40;
  }
  v239[0] = *(float *)(LODWORD(v6) + 16);
  v239[1] = *(float *)(LODWORD(v217) + 20);
  v239[2] = *(float *)(LODWORD(v217) + 24);
  v239[3] = *(float *)(LODWORD(v217) + 28);
  v239[4] = *(float *)(LODWORD(v217) + 32);
  v239[5] = *(float *)(LODWORD(v217) + 36);
  v239[6] = *(float *)(LODWORD(v217) + 40);
  v239[7] = *(float *)(LODWORD(v217) + 44);
  v239[8] = *(float *)(LODWORD(v217) + 48);
  v239[9] = *(float *)(LODWORD(v217) + 52);
  v239[10] = *(float *)(LODWORD(v217) + 56);
  v239[11] = *(float *)(LODWORD(v217) + 60);
  v239[12] = *(float *)(LODWORD(v217) + 64);
  v239[13] = *(float *)(LODWORD(v217) + 68);
  v239[14] = *(float *)(LODWORD(v217) + 72);
  v239[15] = *(float *)(LODWORD(v217) + 76);
  v27 = *(float **)(a1 + 24);
  v209 = 0;
  v240[0] = v27[4];
  v240[1] = v27[5];
  v240[2] = v27[6];
  v240[3] = v27[7];
  v240[4] = v27[8];
  v240[5] = v27[9];
  v240[6] = v27[10];
  v240[7] = v27[11];
  v240[8] = v27[12];
  v240[9] = v27[13];
  v240[10] = v27[14];
  v240[11] = v27[15];
  v240[12] = v27[16];
  v240[13] = v27[17];
  v240[14] = v27[18];
  v240[15] = v27[19];
  v206 = a4[84] + a4[148];
  v28 = a4[85];
  v228 = v206;
  v207 = v28 + a4[149];
  v29 = a4[86];
  v229 = v207;
  v208 = v29 + a4[150];
  v30 = a5[84];
  v230 = v208;
  v31 = v30 + a5[148];
  v231 = 0;
  v205 = 0;
  v202 = v31;
  v32 = a5[85];
  v212 = v202;
  v203 = v32 + a5[149];
  v33 = a5[86];
  v213 = v203;
  v204 = v33 + a5[150];
  v214 = v204;
  v215 = 0;
  sub_6035C0(&v254);
  v194 = 0.0;
  v195 = 0.0;
  v196 = 0.0;
  v197 = 0;
  sub_9A7AC0((int)v330, v239, &v194, &v228, a6, (int)&v254);
  sub_6035C0(&v266);
  sub_9A7AC0((int)v330, v240, &v194, &v212, a6, (int)&v266);
  v221 = 0.0;
  v222 = 0.0;
  v223 = 0.0;
  v224 = 0;
  sub_603C50(v193 + 608);
  v250 = v221;
  v251 = v222;
  v252 = v223;
  v253 = v224;
  v226 = *(float *)(v193 + 404);
  v217 = *(float *)(v193 + 400);
  v220 = *(float *)(v193 + 408);
  v224 = 0;
  v227 = v217 * 0.0 + v226 * 0.0 + v220 * 0.0;
  v221 = v227 + *(float *)(v193 + 448);
  v225 = *(float *)(v193 + 420);
  v232 = *(float *)(v193 + 416);
  v210 = *(float *)(v193 + 424);
  v227 = v232 * 0.0 + v225 * 0.0 + v210 * 0.0;
  v222 = v227 + *(float *)(v193 + 452);
  v216 = *(float *)(v193 + 436);
  v227 = *(float *)(v193 + 432);
  v187 = *(float *)(v193 + 440);
  v34 = v227;
  v227 = 0.0 * v187 + v227 * 0.0 + v216 * 0.0;
  v223 = v227 + *(float *)(v193 + 456);
  v233 = v34 * v243 + v216 * v246 + v187 * v249;
  v198 = v187 * v248 + v34 * v242 + v216 * v245;
  v281 = 0;
  v285 = 0;
  v188 = v187 * v247 + v216 * v244 + v34 * v241;
  v219 = v232 * v243 + v225 * v246 + v210 * v249;
  v218 = v225 * v245 + v232 * v242 + v210 * v248;
  v187 = v232 * v241 + v225 * v244 + v210 * v247;
  v216 = v217 * v243 + v226 * v246 + v220 * v249;
  v280 = v216;
  v282 = v187;
  v283 = v218;
  v284 = v219;
  v227 = v248 * v220 + v245 * v226 + v217 * v242;
  v278 = v247 * v220 + v244 * v226 + v241 * v217;
  v279 = v227;
  v314 = v278;
  v315 = v227;
  v316 = v216;
  v317 = 0;
  v318 = v187;
  v319 = v218;
  v320 = v219;
  v321 = 0;
  v286 = v188;
  v322 = v188;
  v287 = v198;
  v323 = v198;
  v288 = v233;
  v324 = v233;
  v289 = 0;
  v325 = 0;
  v326 = v221;
  v327 = v222;
  v328 = v223;
  v329 = 0;
  v35 = (float *)sub_982990((float *)(v193 + 336), (int)&v235);
  v227 = v35[13];
  v233 = v35[12];
  v216 = v35[14];
  v36 = v233;
  v233 = v316 * v216 + v315 * v227 + v314 * v233;
  v221 = v233 + v326;
  v233 = v318 * v36 + v319 * v227 + v320 * v216;
  v222 = v233 + v327;
  v224 = 0;
  v233 = v216 * v324 + v227 * v323 + v36 * v322;
  v223 = v233 + v328;
  v220 = v35[6];
  v232 = v35[2];
  v226 = v35[10];
  v217 = v322 * v232 + v323 * v220 + v324 * v226;
  v198 = v35[5];
  v210 = v35[1];
  v233 = v35[9];
  v37 = v233;
  v188 = v324 * v233 + v322 * v210 + v323 * v198;
  v227 = v35[4];
  v233 = *v35;
  v216 = v35[8];
  v218 = v324 * v216 + v323 * v227 + v322 * v233;
  v293 = 0;
  v297 = 0;
  v301 = 0;
  v225 = v318 * v232 + v319 * v220 + v320 * v226;
  v38 = v198;
  v198 = v319 * v198 + v318 * v210 + v320 * v37;
  v219 = v318 * v233 + v319 * v227 + v320 * v216;
  v226 = v314 * v232 + v315 * v220 + v316 * v226;
  v292 = v226;
  v294 = v219;
  v295 = v198;
  v296 = v225;
  v298 = v218;
  v299 = v188;
  v300 = v217;
  v232 = v37 * v316 + v38 * v315 + v314 * v210;
  v210 = v227 * v315 + v233 * v314 + v216 * v316;
  v290 = v210;
  v236[0] = v210;
  v291 = v232;
  v236[1] = v232;
  v39 = v222;
  v236[2] = v226;
  v236[3] = 0.0;
  v40 = v221;
  v236[4] = v219;
  v236[5] = v198;
  v236[6] = v225;
  v236[7] = 0.0;
  v236[8] = v218;
  v236[9] = v188;
  v236[10] = v217;
  v233 = v222 * v267 + v221 * v266 + v223 * v268;
  v236[11] = 0.0;
  v236[12] = v221;
  v221 = v233 + v275;
  v236[13] = v222;
  v236[14] = v223;
  v236[15] = 0.0;
  v224 = 0;
  v233 = v222 * v270 + v40 * v269 + v223 * v271;
  v222 = v233 + v276;
  v233 = v223 * v274 + v40 * v272 + v39 * v273;
  v223 = v233 + v277;
  v233 = v272 * v226 + v273 * v225 + v274 * v217;
  v227 = v274 * v188 + v273 * v198 + v232 * v272;
  v41 = v219;
  v42 = v218;
  v43 = v188;
  v216 = v274 * v218 + v273 * v219 + v272 * v210;
  v187 = v271 * v217 + v269 * v226 + v270 * v225;
  v218 = v269 * v232 + v270 * v198 + v271 * v188;
  v219 = v269 * v210 + v270 * v219 + v271 * v42;
  v188 = v217 * v268 + v266 * v226 + v267 * v225;
  v198 = v43 * v268 + v198 * v267 + v266 * v232;
  v232 = v268 * v42 + v41 * v267 + v266 * v210;
  sub_5E10E0(&v232, &v198, &v188, &v219, &v218, &v187, &v216, &v227, &v233);
  v237[0] = v302;
  v237[1] = v303;
  v237[2] = v304;
  v237[3] = v305;
  v237[4] = v306;
  v237[5] = v307;
  v237[6] = v308;
  v237[7] = v309;
  v237[8] = v310;
  v237[9] = v311;
  v237[10] = v312;
  v237[11] = v313;
  *(float *)&v237[12] = v221;
  *(float *)&v237[13] = v222;
  *(float *)&v237[14] = v223;
  v237[15] = v224;
  v44 = (float *)sub_982990(v236, (int)&v234);
  v227 = v44[13];
  v233 = v44[12];
  v216 = v44[14];
  v45 = v233;
  v224 = 0;
  v233 = v256 * v216 + v255 * v227 + v254 * v233;
  v221 = v233 + v263;
  v233 = v257 * v45 + v258 * v227 + v259 * v216;
  v222 = v233 + v264;
  v233 = v216 * v262 + v227 * v261 + v45 * v260;
  v223 = v233 + v265;
  v220 = v44[6];
  v232 = v44[2];
  v226 = v44[10];
  v187 = v261 * v220 + v232 * v260 + v226 * v262;
  v225 = v44[5];
  v218 = v44[1];
  v219 = v44[9];
  v188 = v261 * v225 + v218 * v260 + v219 * v262;
  v233 = v44[4];
  v227 = *v44;
  v216 = v44[8];
  v46 = v227;
  v47 = v216;
  v48 = v233;
  v233 = v262 * v216 + v260 * v227 + v261 * v233;
  v227 = v257 * v232 + v258 * v220 + v259 * v226;
  v49 = v219;
  v50 = v218;
  v216 = v259 * v219 + v257 * v218 + v258 * v225;
  v218 = v257 * v46 + v258 * v48 + v259 * v47;
  v219 = v254 * v232 + v255 * v220 + v256 * v226;
  v198 = v49 * v256 + v50 * v254 + v255 * v225;
  v232 = v48 * v255 + v46 * v254 + v256 * v47;
  sub_5E10E0(&v232, &v198, &v219, &v218, &v216, &v227, &v233, &v188, &v187);
  v238[0] = v302;
  v238[1] = v303;
  v238[2] = v304;
  v238[3] = v305;
  v238[4] = v306;
  v238[5] = v307;
  v238[6] = v308;
  v238[7] = v309;
  v238[8] = v310;
  v238[9] = v311;
  v238[10] = v312;
  v238[11] = v313;
  *(float *)&v238[12] = v221;
  *(float *)&v238[13] = v222;
  *(float *)&v238[14] = v223;
  v238[15] = v224;
  sub_97D980(v239, v237, LODWORD(a6), &v194, &v228);
  LOWORD(v6) = sub_97D980(v240, v238, LODWORD(a6), &v194, &v212);
  v221 = v228 - v206;
  v222 = v229 - v207;
  v223 = v230 - v208;
  v225 = 0.0;
  v226 = 0.0;
  v194 = v212 - v202;
  v195 = v213 - v203;
  v196 = v214 - v204;
  v233 = v221 * v221 + v222 * v222 + v223 * v223;
  v51 = 0.00000011920929;
  if ( v233 <= 0.00000011920929 )
  {
    a1 = v193;
  }
  else
  {
    v233 = sqrt(v233);
    a1 = v193;
    v205 = 0;
    v233 = 1.0 / v233;
    v202 = v233 * v221;
    v189 = v202;
    v203 = v233 * v222;
    v190 = v203;
    v204 = v233 * v223;
    v191 = v204;
    v192 = 0;
    LODWORD(v6) = *(_DWORD *)(v193 + 20) + 272;
    v228 = *(float *)(*(_DWORD *)(v193 + 20) + 304) * v204
         + *(float *)LODWORD(v6) * v202
         + *(float *)(*(_DWORD *)(v193 + 20) + 288) * v203;
    v229 = *(float *)(LODWORD(v6) + 20) * v203
         + *(float *)(LODWORD(v6) + 4) * v202
         + *(float *)(LODWORD(v6) + 36) * v204;
    v230 = *(float *)(LODWORD(v6) + 24) * v203
         + *(float *)(LODWORD(v6) + 8) * v202
         + *(float *)(LODWORD(v6) + 40) * v204;
    v225 = v202 * v228 + v203 * v229 + v204 * v230;
    v51 = 0.00000011920929;
  }
  v233 = v194 * v194 + v195 * v195 + v196 * v196;
  if ( v233 > v51 )
  {
    v233 = sqrt(v233);
    a1 = v193;
    v205 = 0;
    v233 = 1.0 / v233;
    v202 = v233 * v194;
    v206 = v202;
    v203 = v233 * v195;
    v207 = v203;
    v204 = v233 * v196;
    v208 = v204;
    v209 = 0;
    LODWORD(v6) = *(_DWORD *)(v193 + 24) + 272;
    v228 = *(float *)(*(_DWORD *)(v193 + 24) + 304) * v204
         + *(float *)LODWORD(v6) * v202
         + *(float *)(*(_DWORD *)(v193 + 24) + 288) * v203;
    v229 = *(float *)(LODWORD(v6) + 20) * v203
         + *(float *)(LODWORD(v6) + 4) * v202
         + *(float *)(LODWORD(v6) + 36) * v204;
    v230 = *(float *)(LODWORD(v6) + 24) * v203
         + *(float *)(LODWORD(v6) + 8) * v202
         + *(float *)(LODWORD(v6) + 40) * v204;
    v226 = v202 * v228 + v203 * v229 + v204 * v230;
    v51 = 0.00000011920929;
  }
  v212 = v226 * v206;
  v213 = v226 * v207;
  v214 = v226 * v208;
  v228 = v225 * v189;
  v229 = v225 * v190;
  v230 = v225 * v191;
  v206 = v228 + v212;
  v207 = v229 + v213;
  v208 = v230 + v214;
  if ( !byte_C64B36 )
    goto LABEL_40;
  v233 = v206 * v206 + v207 * v207 + v208 * v208;
  if ( v233 <= v51 )
    goto LABEL_40;
  v233 = sqrt(v233);
  v227 = *(float *)(v193 + 20);
  v233 = 1.0 / v233;
  v206 = v233 * v206;
  v207 = v233 * v207;
  v208 = v233 * v208;
  v228 = *(float *)(LODWORD(v227) + 304) * v208
       + *(float *)(LODWORD(v227) + 272) * v206
       + *(float *)(LODWORD(v227) + 288) * v207;
  v229 = *(float *)(LODWORD(v227) + 292) * v207
       + *(float *)(LODWORD(v227) + 276) * v206
       + *(float *)(LODWORD(v227) + 308) * v208;
  v52 = *(float *)(LODWORD(v227) + 296) * v207 + *(float *)(LODWORD(v227) + 280) * v206;
  v53 = *(float *)(LODWORD(v227) + 312);
  v216 = *(float *)(v193 + 24);
  v230 = v52 + v53 * v208;
  v225 = v229 * v207 + v228 * v206 + v230 * v208;
  v228 = *(float *)(LODWORD(v216) + 288) * v207
       + *(float *)(LODWORD(v216) + 272) * v206
       + *(float *)(LODWORD(v216) + 304) * v208;
  v54 = *(float *)(v193 + 624);
  v229 = *(float *)(LODWORD(v216) + 292) * v207
       + *(float *)(LODWORD(v216) + 276) * v206
       + *(float *)(LODWORD(v216) + 308) * v208;
  v230 = *(float *)(LODWORD(v216) + 296) * v207
       + *(float *)(LODWORD(v216) + 280) * v206
       + *(float *)(LODWORD(v216) + 312) * v208;
  v226 = v206 * v228 + v207 * v229 + v208 * v230;
  v233 = v226 + v225;
  v212 = v226 * v194;
  v213 = v226 * v195;
  v214 = v226 * v196;
  v228 = v225 * v221;
  v229 = v225 * v222;
  v230 = v225 * v223;
  v199 = v228 - v212;
  v200 = v229 - v213;
  v201 = v230 - v214;
  v233 = v233 * v233;
  v233 = 1.0 / v233;
  v194 = v233 * v199;
  v195 = v233 * v200;
  v196 = v233 * v201;
  if ( v54 < 0.0 )
  {
    v63 = v194;
    v58 = v195;
    v57 = v196;
  }
  else
  {
    v7 = *(_BYTE *)(v193 + 593) == 0;
    v232 = v54;
    if ( !v7 )
      v232 = v232 / v225;
    v220 = *(float *)(v193 + 640);
    v206 = v220 + v194;
    v218 = *(float *)(v193 + 644);
    v207 = v218 + v195;
    v219 = *(float *)(v193 + 648);
    v208 = v219 + v196;
    v233 = v206 * v206 + v207 * v207 + v208 * v208;
    v233 = sqrt(v233);
    v55 = v232;
    if ( v233 <= (double)v232 )
    {
      v56 = v220;
      v57 = v196;
      v59 = v194;
      v58 = v195;
    }
    else
    {
      v205 = 0;
      v233 = 1.0 / v233;
      v206 = v233 * v206;
      v207 = v233 * v207;
      v208 = v233 * v208;
      v206 = v55 * v206;
      v207 = v55 * v207;
      v208 = v55 * v208;
      v56 = v220;
      v202 = v206 - v220;
      v194 = v202;
      v203 = v207 - v218;
      v195 = v203;
      v204 = v208 - v219;
      v196 = v204;
      v57 = v204;
      v58 = v203;
      v59 = v202;
      v197 = 0;
    }
    v60 = v193;
    v61 = v59;
    v62 = v56 + v59;
    v63 = v61;
    *(float *)(v193 + 640) = v62;
    *(float *)(v60 + 644) = v58 + *(float *)(v60 + 644);
    *(float *)(v60 + 648) = v57 + *(float *)(v60 + 648);
  }
  v233 = v58 * v58 + v63 * v63 + v57 * v57;
  v233 = sqrt(v233);
  v64 = (float *)LODWORD(v227);
  v218 = v233;
  v65 = a4[88];
  v66 = v233;
  v233 = 1.0 / v233;
  v228 = v233 * v194;
  v229 = v233 * v195;
  v230 = v233 * v196;
  v67 = v229;
  v68 = v228;
  v69 = v230;
  v212 = v64[70] * v230 + v64[68] * v228 + v64[69] * v229;
  v213 = v64[73] * v229 + v64[72] * v228 + v64[74] * v230;
  v214 = v64[77] * v229 + v64[76] * v228 + *(float *)(LODWORD(v227) + 312) * v230;
  if ( v65 == 0.0 )
  {
    v72 = 0.0;
  }
  else
  {
    v233 = v66 * 0.0;
    v70 = v233;
    a4[144] = v233 + a4[144];
    a4[145] = v70 + a4[145];
    a4[146] = v70 + a4[146];
    v228 = a4[152] * v66;
    v229 = a4[153] * v66;
    v71 = v66 * a4[154];
    v72 = 0.0;
    v230 = v71;
    v199 = v228 * v212;
    v200 = v229 * v213;
    v201 = v230 * v214;
    a4[148] = a4[148] + v199;
    a4[149] = a4[149] + v200;
    a4[150] = v201 + a4[150];
  }
  v6 = v216;
  v73 = *(float *)(LODWORD(v216) + 276) * v67;
  v74 = *(float *)(LODWORD(v216) + 272);
  v233 = -v218;
  v75 = a5[88];
  v76 = v75 < 0.0;
  v79 = 0;
  v7 = v75 == 0.0;
  v77 = 0;
  v78 = 0;
  v212 = v73 + v74 * v68 + *(float *)(LODWORD(v216) + 280) * v69;
  v213 = *(float *)(LODWORD(v6) + 292) * v67
       + *(float *)(LODWORD(v6) + 288) * v68
       + *(float *)(LODWORD(v216) + 296) * v69;
  BYTE1(v6) = a3;
  v214 = v68 * *(float *)(LODWORD(v216) + 304)
       + v67 * *(float *)(LODWORD(v216) + 308)
       + v69 * *(float *)(LODWORD(v216) + 312);
  if ( v75 == 0.0 )
    goto LABEL_39;
  v80 = v72 * v233;
  v81 = v233;
  v233 = v80;
  v82 = v233;
LABEL_31:
  a1 = v193;
  a5[144] = v82 + a5[144];
  a5[145] = v82 + a5[145];
  a5[146] = v82 + a5[146];
  v228 = v81 * a5[152];
  v229 = a5[153] * v81;
  v230 = v81 * a5[154];
  v199 = v228 * v212;
  v200 = v229 * v213;
  v201 = v230 * v214;
  a5[148] = v199 + a5[148];
  a5[149] = a5[149] + v200;
  a5[150] = a5[150] + v201;
LABEL_40:
  v7 = *(_BYTE *)(a1 + 562) == 0;
  v221 = a4[84] + a4[148];
  v222 = a4[85] + a4[149];
  v223 = a4[86] + a4[150];
  v206 = a5[84] + a5[148];
  v207 = a5[85] + a5[149];
  v208 = a5[86] + a5[150];
  v104 = 0.0;
  v105 = v223;
  v106 = v222;
  v107 = v221;
  if ( v7 )
  {
    v131 = 0.0;
  }
  else
  {
    v233 = *(float *)(a1 + 564);
    v232 = *(float *)(a1 + 540) * v233 * *(float *)(a1 + 468) / a6;
    v228 = v206 - v107;
    v229 = v207 - v106;
    v108 = v208 - v105;
    v109 = v233;
    v230 = v108;
    v233 = v229 * *(float *)(a1 + 500) + *(float *)(a1 + 496) * v228 + v230 * *(float *)(a1 + 504);
    if ( v233 > 0.0 )
      v232 = v109 * v233 * *(float *)(a1 + 472) + v232;
    v110 = *(float *)(a1 + 552);
    v111 = *(float *)(a1 + 528) * v232;
    v179 = 0;
    v227 = v110;
    v112 = &v186;
    v217 = v111;
    v186 = v217 + *(float *)(a1 + 552);
    if ( v186 <= 0.0 )
      v112 = (float *)&v179;
    v233 = *v112;
    v113 = v233 - v227;
    *(float *)(a1 + 552) = v233;
    v217 = v113;
    v189 = *(float *)(a1 + 496) * v217;
    v190 = v217 * *(float *)(a1 + 500);
    v191 = v217 * *(float *)(a1 + 504);
    v227 = *(float *)(a1 + 580);
    v233 = *(float *)(a1 + 576);
    v216 = *(float *)(a1 + 584);
    v114 = v233;
    v233 = v216 * v191 + v227 * v190 + v233 * v189;
    v228 = v114 * v233;
    v229 = v227 * v233;
    v230 = v233 * v216;
    v202 = v189 - v228;
    v203 = v190 - v229;
    v204 = v191 - v230;
    v233 = v202 * v202 + v203 * v203 + v204 * v204;
    v233 = sqrt(v233);
    v217 = v233;
    v115 = v233;
    v233 = 1.0 / v233;
    a1 = v193;
    v116 = a4[88];
    v117 = (float *)(*(_DWORD *)(v193 + 20) + 272);
    v228 = v202 * v233;
    v229 = v203 * v233;
    v230 = v233 * v204;
    v118 = v229;
    v119 = v228;
    v120 = v230;
    v212 = v117[2] * v230 + v117[1] * v229 + v228 * *v117;
    v213 = v117[5] * v229 + v117[4] * v228 + v117[6] * v230;
    v214 = v117[9] * v229 + v117[8] * v228 + v117[10] * v230;
    if ( v116 == 0.0 )
    {
      v123 = 0.0;
    }
    else
    {
      v233 = v115 * 0.0;
      v121 = v233;
      a4[144] = a4[144] + v233;
      a4[145] = a4[145] + v121;
      a4[146] = v121 + a4[146];
      v228 = v115 * a4[152];
      v229 = a4[153] * v115;
      v122 = v115 * a4[154];
      v123 = 0.0;
      v230 = v122;
      v199 = v228 * v212;
      v200 = v229 * v213;
      v201 = v230 * v214;
      a4[148] = a4[148] + v199;
      a4[149] = a4[149] + v200;
      a4[150] = v201 + a4[150];
    }
    LODWORD(v6) = *(_DWORD *)(a1 + 24) + 272;
    v124 = *(float *)(*(_DWORD *)(a1 + 24) + 276) * v118;
    v125 = *(float *)LODWORD(v6);
    v233 = -v217;
    v126 = a5[88];
    v76 = v126 < 0.0;
    v79 = 0;
    v7 = v126 == 0.0;
    v77 = 0;
    v78 = 0;
    v212 = v124 + v125 * v119 + *(float *)(LODWORD(v6) + 8) * v120;
    v213 = *(float *)(LODWORD(v6) + 20) * v118
         + *(float *)(LODWORD(v6) + 16) * v119
         + *(float *)(LODWORD(v6) + 24) * v120;
    v127 = v118 * *(float *)(LODWORD(v6) + 36) + v119 * *(float *)(LODWORD(v6) + 32);
    v128 = *(float *)(LODWORD(v6) + 40);
    BYTE1(v6) = a3;
    v214 = v120 * v128 + v127;
    if ( v126 != 0.0 )
    {
      v129 = v233;
      v233 = v233 * v123;
      v130 = v233;
      a5[144] = v233 + a5[144];
      a5[145] = v130 + a5[145];
      a5[146] = v130 + a5[146];
      v228 = v129 * a5[152];
      v229 = a5[153] * v129;
      v230 = v129 * a5[154];
      v199 = v228 * v212;
      v200 = v229 * v213;
      v201 = v230 * v214;
      a5[148] = v199 + a5[148];
      a5[149] = a5[149] + v200;
      a5[150] = a5[150] + v201;
    }
    v131 = v123;
    v104 = 0.0;
    v105 = v223;
    v107 = v221;
    v106 = v222;
  }
  if ( *(_BYTE *)(a1 + 561) )
  {
    v233 = *(float *)(a1 + 568);
    v232 = *(float *)(a1 + 544) * v233 * *(float *)(a1 + 468) / a6;
    v228 = v206 - v107;
    v132 = v131;
    v133 = v207 - v106;
    v134 = v132;
    v229 = v133;
    v135 = v208 - v105;
    v136 = v233;
    v230 = v135;
    v233 = *(float *)(a1 + 512) * v228 + *(float *)(a1 + 516) * v229 + *(float *)(a1 + 520) * v230;
    if ( v233 <= v104 )
    {
      v139 = v134;
    }
    else
    {
      v137 = v134;
      v138 = v136 * v233 * *(float *)(a1 + 472) + v232;
      v139 = v137;
      v232 = v138;
    }
    v140 = *(float *)(a1 + 556);
    v141 = *(float *)(a1 + 532) * v232;
    v178 = 0;
    v227 = v140;
    v142 = &v211;
    v226 = v141;
    v211 = v226 + *(float *)(a1 + 556);
    v143 = v211 <= v104;
    v144 = v139;
    if ( v143 )
      v142 = (float *)&v178;
    v145 = *v142;
    v146 = *(float **)(a1 + 20);
    *(float *)(a1 + 556) = v145;
    v233 = v145;
    v146 += 68;
    v147 = a4[88];
    v226 = v233 - v227;
    v232 = *(float *)(a1 + 516);
    v220 = *(float *)(a1 + 512);
    v225 = *(float *)(a1 + 520);
    v212 = v146[2] * v225 + *v146 * v220 + v146[1] * v232;
    v213 = v146[5] * v232 + v220 * v146[4] + v146[6] * v225;
    v214 = v220 * v146[8] + v232 * v146[9] + v225 * v146[10];
    if ( v147 != 0.0 )
    {
      v148 = v226;
      v233 = v226 * v144;
      v149 = v233;
      a4[144] = v233 + a4[144];
      a4[145] = v149 + a4[145];
      a4[146] = v149 + a4[146];
      v228 = v148 * a4[152];
      v229 = a4[153] * v148;
      v230 = v148 * a4[154];
      v199 = v228 * v212;
      v200 = v229 * v213;
      v201 = v230 * v214;
      a4[148] = a4[148] + v199;
      a4[149] = v200 + a4[149];
      a4[150] = v201 + a4[150];
    }
    v150 = *(_DWORD *)(a1 + 24);
    v232 = *(float *)(a1 + 516);
    LODWORD(v6) = v150 + 272;
    v220 = *(float *)(a1 + 512);
    v151 = *(float *)(a1 + 520);
    LODWORD(v233) = LODWORD(v226) ^ 0x80000000;
    v225 = v151;
    v152 = a5[88];
    v76 = v152 < 0.0;
    v79 = 0;
    v7 = v152 == 0.0;
    v77 = 0;
    v78 = 0;
    v212 = *(float *)(LODWORD(v6) + 8) * v225 + *(float *)LODWORD(v6) * v220 + *(float *)(LODWORD(v6) + 4) * v232;
    v213 = *(float *)(LODWORD(v6) + 20) * v232
         + *(float *)(LODWORD(v6) + 16) * v220
         + *(float *)(LODWORD(v6) + 24) * v225;
    v153 = *(float *)(LODWORD(v6) + 32);
    v154 = v232 * *(float *)(LODWORD(v6) + 36);
    v155 = v225 * *(float *)(LODWORD(v6) + 40);
    BYTE1(v6) = a3;
    v214 = v220 * v153 + v154 + v155;
    if ( v152 != 0.0 )
    {
      v156 = v144 * v233;
      v157 = v233;
      v233 = v156;
      v158 = v233;
      a5[144] = v233 + a5[144];
      a5[145] = v158 + a5[145];
      a5[146] = v158 + a5[146];
      v228 = v157 * a5[152];
      v229 = a5[153] * v157;
      v230 = v157 * a5[154];
      v199 = v228 * v212;
      v200 = v229 * v213;
      v201 = v230 * v214;
      a5[148] = v199 + a5[148];
      a5[149] = a5[149] + v200;
      a5[150] = a5[150] + v201;
    }
  }
  return LOWORD(v6);
}
