// Function: sub_9954B0
// Address: 0x9954b0
// bad sp value at call has been detected, the output may be wrong!
__int16 __userpurge sub_9954B0@<ax>(float a1@<ecx>, int a2@<ebp>, _DWORD *a3, int a4, float a5, _DWORD *a6)
{
  bool v6; // zf
  int v7; // eax
  _DWORD *v8; // edx
  float v9; // eax
  int v10; // esi
  int v11; // ecx
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v16; // xmm0_4
  float v17; // eax
  float v18; // xmm0_4
  float v19; // xmm0_4
  double v20; // st5
  bool v21; // cf
  char v22; // pf
  double v23; // st4
  char v24; // fl
  float v25; // eax
  double v26; // st3
  double v27; // st2
  double v28; // rt2
  double v29; // st2
  double v30; // st3
  double v31; // st3
  double v32; // st5
  double v33; // st4
  bool v34; // cc
  double v35; // st5
  double v36; // st4
  double v37; // rt2
  double v38; // st7
  _DWORD *v39; // esi
  int v40; // eax
  int v41; // ecx
  _DWORD *v42; // eax
  int v43; // eax
  double v44; // st7
  double v45; // st7
  int v46; // ecx
  float v47; // eax
  float v48; // eax
  float v49; // ecx
  _DWORD *v50; // edx
  double v51; // st7
  double v52; // st7
  char v53; // cl
  int v54; // eax
  float v55; // xmm0_4
  double v56; // st7
  double v57; // st4
  double v58; // st3
  double v59; // st5
  double v60; // st6
  double v61; // st0
  double v62; // st7
  double v63; // st6
  float v64; // eax
  double v65; // st4
  double v66; // st3
  double v67; // st7
  double v68; // st3
  double v69; // st6
  double v70; // st7
  double v71; // st6
  int v72; // ecx
  int v74; // [esp+4h] [ebp-5E8h]
  int v75; // [esp+8h] [ebp-5E4h]
  float v76; // [esp+20h] [ebp-5CCh]
  float v77; // [esp+30h] [ebp-5BCh]
  float v78; // [esp+40h] [ebp-5ACh]
  float v79; // [esp+60h] [ebp-58Ch]
  float v80; // [esp+64h] [ebp-588h]
  float v81; // [esp+68h] [ebp-584h]
  float v82; // [esp+B0h] [ebp-53Ch]
  _DWORD v83[4]; // [esp+C0h] [ebp-52Ch] BYREF
  _DWORD v84[4]; // [esp+D0h] [ebp-51Ch] BYREF
  float v85[4]; // [esp+E0h] [ebp-50Ch] BYREF
  float v86[4]; // [esp+F0h] [ebp-4FCh] BYREF
  float v87; // [esp+100h] [ebp-4ECh]
  float v88; // [esp+104h] [ebp-4E8h]
  float v89; // [esp+108h] [ebp-4E4h]
  float v90; // [esp+110h] [ebp-4DCh]
  float v91; // [esp+114h] [ebp-4D8h]
  float v92; // [esp+118h] [ebp-4D4h]
  float v93; // [esp+120h] [ebp-4CCh]
  float v94; // [esp+124h] [ebp-4C8h]
  float v95; // [esp+128h] [ebp-4C4h]
  float v96; // [esp+130h] [ebp-4BCh]
  float v97; // [esp+134h] [ebp-4B8h]
  float v98; // [esp+138h] [ebp-4B4h]
  float v99; // [esp+140h] [ebp-4ACh]
  float v100; // [esp+144h] [ebp-4A8h]
  float v101; // [esp+148h] [ebp-4A4h]
  float v102; // [esp+14Ch] [ebp-4A0h]
  float v103; // [esp+150h] [ebp-49Ch]
  float v104; // [esp+154h] [ebp-498h]
  float v105; // [esp+158h] [ebp-494h]
  int v106; // [esp+15Ch] [ebp-490h]
  float v107; // [esp+160h] [ebp-48Ch]
  float v108; // [esp+164h] [ebp-488h]
  float v109; // [esp+168h] [ebp-484h]
  int v110; // [esp+16Ch] [ebp-480h]
  float v111; // [esp+17Ch] [ebp-470h] BYREF
  float v112; // [esp+180h] [ebp-46Ch]
  float v113; // [esp+184h] [ebp-468h]
  float v114; // [esp+188h] [ebp-464h]
  int v115; // [esp+18Ch] [ebp-460h]
  float v116; // [esp+190h] [ebp-45Ch]
  float v117; // [esp+194h] [ebp-458h]
  float v118; // [esp+198h] [ebp-454h]
  float v119; // [esp+1A0h] [ebp-44Ch]
  float v120; // [esp+1A4h] [ebp-448h]
  float v121; // [esp+1A8h] [ebp-444h]
  float v122; // [esp+1B0h] [ebp-43Ch] BYREF
  float v123; // [esp+1B4h] [ebp-438h]
  float v124; // [esp+1B8h] [ebp-434h]
  float v125; // [esp+1C0h] [ebp-42Ch]
  float v126; // [esp+1C4h] [ebp-428h]
  float v127; // [esp+1C8h] [ebp-424h]
  int v128; // [esp+1CCh] [ebp-420h]
  float v129; // [esp+1D0h] [ebp-41Ch]
  float v130; // [esp+1D4h] [ebp-418h]
  float v131; // [esp+1D8h] [ebp-414h]
  float v132; // [esp+1E0h] [ebp-40Ch]
  float v133; // [esp+1E4h] [ebp-408h]
  float v134; // [esp+1E8h] [ebp-404h]
  float v135; // [esp+1F0h] [ebp-3FCh] BYREF
  float v136; // [esp+1F4h] [ebp-3F8h]
  float v137; // [esp+1F8h] [ebp-3F4h]
  int v138; // [esp+1FCh] [ebp-3F0h]
  float v139; // [esp+200h] [ebp-3ECh]
  float v140; // [esp+204h] [ebp-3E8h]
  float v141; // [esp+208h] [ebp-3E4h]
  float v142; // [esp+214h] [ebp-3D8h]
  float v143; // [esp+218h] [ebp-3D4h]
  float v144; // [esp+21Ch] [ebp-3D0h]
  float v145; // [esp+220h] [ebp-3CCh]
  float v146; // [esp+224h] [ebp-3C8h]
  float v147; // [esp+228h] [ebp-3C4h]
  float v148; // [esp+22Ch] [ebp-3C0h]
  float v149; // [esp+234h] [ebp-3B8h]
  float v150; // [esp+238h] [ebp-3B4h]
  float v151; // [esp+23Ch] [ebp-3B0h]
  float v152; // [esp+240h] [ebp-3ACh]
  float v153; // [esp+244h] [ebp-3A8h]
  double v154; // [esp+248h] [ebp-3A4h]
  float v155; // [esp+254h] [ebp-398h]
  float v156; // [esp+258h] [ebp-394h]
  _DWORD *v157; // [esp+25Ch] [ebp-390h]
  float v158; // [esp+260h] [ebp-38Ch]
  float v159; // [esp+264h] [ebp-388h]
  float v160; // [esp+268h] [ebp-384h]
  float v161; // [esp+26Ch] [ebp-380h]
  float v162; // [esp+278h] [ebp-374h]
  float v163; // [esp+27Ch] [ebp-370h]
  float v164; // [esp+280h] [ebp-36Ch]
  float v165; // [esp+284h] [ebp-368h]
  float v166; // [esp+288h] [ebp-364h]
  float v167; // [esp+28Ch] [ebp-360h] BYREF
  float v168; // [esp+290h] [ebp-35Ch]
  float v169; // [esp+294h] [ebp-358h]
  float v170; // [esp+298h] [ebp-354h]
  float v171; // [esp+29Ch] [ebp-350h]
  float v172; // [esp+2A0h] [ebp-34Ch] BYREF
  float v173; // [esp+2A4h] [ebp-348h]
  float v174; // [esp+2A8h] [ebp-344h]
  int v175; // [esp+2ACh] [ebp-340h]
  float v176; // [esp+2B0h] [ebp-33Ch]
  float v177; // [esp+2B4h] [ebp-338h]
  float v178; // [esp+2B8h] [ebp-334h]
  int v179; // [esp+2BCh] [ebp-330h]
  float v180; // [esp+2C0h] [ebp-32Ch]
  float v181; // [esp+2C4h] [ebp-328h]
  float v182; // [esp+2C8h] [ebp-324h]
  int v183; // [esp+2CCh] [ebp-320h]
  int v184; // [esp+2D0h] [ebp-31Ch]
  int v185; // [esp+2D4h] [ebp-318h]
  int v186; // [esp+2D8h] [ebp-314h]
  int v187; // [esp+2DCh] [ebp-310h]
  float v188; // [esp+2E0h] [ebp-30Ch] BYREF
  float v189; // [esp+2E4h] [ebp-308h]
  float v190; // [esp+2E8h] [ebp-304h]
  int v191; // [esp+2ECh] [ebp-300h]
  float v192; // [esp+2F0h] [ebp-2FCh]
  float v193; // [esp+2F4h] [ebp-2F8h]
  float v194; // [esp+2F8h] [ebp-2F4h]
  int v195; // [esp+2FCh] [ebp-2F0h]
  float v196; // [esp+300h] [ebp-2ECh]
  float v197; // [esp+304h] [ebp-2E8h]
  float v198; // [esp+308h] [ebp-2E4h]
  int v199; // [esp+30Ch] [ebp-2E0h]
  int v200; // [esp+310h] [ebp-2DCh]
  int v201; // [esp+314h] [ebp-2D8h]
  int v202; // [esp+318h] [ebp-2D4h]
  int v203; // [esp+31Ch] [ebp-2D0h]
  float v204; // [esp+320h] [ebp-2CCh]
  int v205; // [esp+324h] [ebp-2C8h]
  void **p_??_7Result@btDiscreteCollisionDetectorInterface@@6B@; // [esp+330h] [ebp-2BCh] BYREF
  float v207; // [esp+4C0h] [ebp-12Ch]
  float v208; // [esp+4C4h] [ebp-128h]
  float v209; // [esp+4C8h] [ebp-124h]
  float v210; // [esp+4D0h] [ebp-11Ch]
  float v211; // [esp+4D4h] [ebp-118h]
  float v212; // [esp+4D8h] [ebp-114h]
  float v213; // [esp+4E0h] [ebp-10Ch]
  float v214; // [esp+4E4h] [ebp-108h]
  float v215; // [esp+4E8h] [ebp-104h]
  float v216; // [esp+4F0h] [ebp-FCh]
  float v217; // [esp+4F4h] [ebp-F8h]
  float v218; // [esp+4F8h] [ebp-F4h]
  float v219; // [esp+500h] [ebp-ECh]
  float v220; // [esp+504h] [ebp-E8h]
  float v221; // [esp+508h] [ebp-E4h]
  float v222; // [esp+510h] [ebp-DCh]
  float v223; // [esp+514h] [ebp-D8h]
  float v224; // [esp+518h] [ebp-D4h]
  float v225; // [esp+520h] [ebp-CCh]
  float v226; // [esp+524h] [ebp-C8h]
  float v227; // [esp+528h] [ebp-C4h]
  int v228; // [esp+52Ch] [ebp-C0h]
  float v229; // [esp+530h] [ebp-BCh]
  float v230; // [esp+534h] [ebp-B8h]
  float v231; // [esp+538h] [ebp-B4h]
  int v232; // [esp+53Ch] [ebp-B0h]
  float v233; // [esp+540h] [ebp-ACh]
  float v234; // [esp+544h] [ebp-A8h]
  float v235; // [esp+548h] [ebp-A4h]
  int v236; // [esp+54Ch] [ebp-A0h]
  float v237; // [esp+550h] [ebp-9Ch]
  float v238; // [esp+554h] [ebp-98h]
  float v239; // [esp+558h] [ebp-94h]
  int v240; // [esp+55Ch] [ebp-90h]
  float v241; // [esp+560h] [ebp-8Ch]
  float v242; // [esp+564h] [ebp-88h]
  float v243; // [esp+568h] [ebp-84h]
  int v244; // [esp+56Ch] [ebp-80h]
  float v245; // [esp+570h] [ebp-7Ch]
  float v246; // [esp+574h] [ebp-78h]
  int v247; // [esp+578h] [ebp-74h]
  int v248; // [esp+57Ch] [ebp-70h]
  float v249; // [esp+580h] [ebp-6Ch] BYREF
  float v250; // [esp+584h] [ebp-68h]
  float v251; // [esp+588h] [ebp-64h]
  int v252; // [esp+58Ch] [ebp-60h]
  float v253; // [esp+590h] [ebp-5Ch]
  float v254; // [esp+594h] [ebp-58h]
  float v255; // [esp+598h] [ebp-54h]
  int v256; // [esp+59Ch] [ebp-50h]
  float v257; // [esp+5A0h] [ebp-4Ch]
  float v258; // [esp+5A4h] [ebp-48h]
  float v259; // [esp+5A8h] [ebp-44h]
  int v260; // [esp+5ACh] [ebp-40h]
  int v261; // [esp+5B0h] [ebp-3Ch]
  int v262; // [esp+5B4h] [ebp-38h]
  int v263; // [esp+5B8h] [ebp-34h]
  int v264; // [esp+5BCh] [ebp-30h]
  _DWORD *v265; // [esp+5CCh] [ebp-20h]
  int *v266; // [esp+5D0h] [ebp-1Ch]
  float v267; // [esp+5D4h] [ebp-18h]
  void *v268; // [esp+5D8h] [ebp-14h]
  int v269; // [esp+5DCh] [ebp-10h]
  int v270; // [esp+5E0h] [ebp-Ch]
  void *v271; // [esp+5E4h] [ebp-8h]
  int v272; // [esp+5E8h] [ebp-4h] BYREF
  void *retaddr; // [esp+5ECh] [ebp+0h]

  v270 = a2;
  v271 = retaddr;
  v269 = -1;
  v268 = &loc_AD90F6;
  v267 = *(float *)&NtCurrentTeb()->NtTib.ExceptionList;
  v266 = &v272;
  v166 = a1;
  v6 = *(_DWORD *)(LODWORD(a1) + 20) == 0;
  v155 = a5;
  v171 = *(float *)&a3;
  v157 = a6;
  if ( v6 )
  {
    v7 = (*(int (__thiscall **)(_DWORD, _DWORD *, int))(**(_DWORD **)(LODWORD(a1) + 4) + 8))(
           *(_DWORD *)(LODWORD(a1) + 4),
           a3,
           a4);
    a1 = v166;
    *(_DWORD *)(LODWORD(v166) + 20) = v7;
    *(_BYTE *)(LODWORD(a1) + 16) = 1;
  }
  v157[1] = *(_DWORD *)(LODWORD(a1) + 20);
  v8 = *((_DWORD **)a3 + 51);
  v9 = *(float *)(a4 + 204);
  v6 = v8[1] == 10;
  v170 = *(float *)&v8;
  v167 = v9;
  if ( v6 && *(_DWORD *)(LODWORD(v9) + 4) == 10 )
  {
    (*(void (__thiscall **)(_DWORD *))(*v8 + 24))(v8);
    (*(void (__thiscall **)(float, void *))(*(_DWORD *)LODWORD(v167) + 24))(COERCE_FLOAT(LODWORD(v167)), v268);
    v165 = sub_9A43D0(*(_DWORD *)(LODWORD(v166) + 20));
    v10 = *(_DWORD *)(LODWORD(v167) + 64);
    v11 = *(_DWORD *)(LODWORD(v170) + 64);
    v12 = *(float *)(LODWORD(v167) + 4 * v10 + 32);
    LODWORD(v168) = 3;
    v155 = v12;
    v13 = *(float *)(LODWORD(v170) + 4 * v11 + 32);
    v169 = v13;
    v156 = *(float *)(LODWORD(v170) + 4 * ((v11 + 2) % 3) + 32);
    v151 = *(float *)(LODWORD(v167) + 4 * ((v10 + 2) % 3) + 32);
    v16 = *(float *)(LODWORD(v171) + 4 * v11 + 16);
    v103 = *(float *)(LODWORD(v171) + 64);
    v104 = *(float *)(LODWORD(v171) + 68);
    v105 = *(float *)(LODWORD(v171) + 72);
    v106 = *(_DWORD *)(LODWORD(v171) + 76);
    v99 = *(float *)(a4 + 64);
    v100 = *(float *)(a4 + 68);
    v17 = *(float *)(a4 + 72);
    v132 = v99 - v103;
    v139 = v16;
    v140 = *(float *)(LODWORD(v171) + 4 * v11 + 32);
    v18 = *(float *)(LODWORD(v171) + 4 * v11 + 48);
    v101 = v17;
    v133 = v100 - v104;
    v25 = *(float *)(a4 + 76);
    v141 = v18;
    v129 = *(float *)(a4 + 4 * v10 + 16);
    v19 = *(float *)(a4 + 4 * v10 + 32);
    v134 = v101 - v105;
    v130 = v19;
    v131 = *(float *)(a4 + 4 * v10 + 48);
    v102 = v25;
    v171 = v131 * v141 + v19 * v140 + v129 * v139;
    v164 = v139 * v132 + v133 * v140 + v134 * v141;
    v163 = v129 * v132 + v19 * v133 + v134 * v131;
    v20 = v171;
    v168 = 1.0 - v20 * v20;
    v21 = v168 < 0.0;
    v22 = 0;
    v6 = v168 == 0.0;
    v23 = v13;
    BYTE1(v25) = v24;
    if ( v168 == 0.0 )
    {
      v26 = v163;
      v170 = 0.0;
    }
    else
    {
      v26 = v163;
      v170 = (v164 - v163 * v20) / v168;
      v166 = -v23;
      v27 = v170;
      if ( v166 <= (double)v170 )
      {
        if ( v27 <= v23 )
          goto LABEL_12;
        v170 = v13;
      }
      else
      {
        v170 = v166;
      }
    }
    v27 = v170;
LABEL_12:
    v28 = v27;
    v29 = v20 * v27 - v26;
    v30 = v28;
    v167 = v29;
    v168 = -v155;
    if ( v168 <= (double)v167 )
    {
      if ( v167 <= (double)v155 )
      {
        v36 = v167;
        v35 = v30;
      }
      else
      {
        v167 = v12;
        v170 = v20 * v155 + v164;
        v166 = -v169;
        if ( v166 > (double)v170 )
        {
          v170 = v166;
          v32 = v167;
          v33 = v166;
          goto LABEL_25;
        }
        v35 = v170;
        if ( v170 > (double)v169 )
        {
          v170 = v13;
          v32 = v167;
          v33 = v13;
          goto LABEL_25;
        }
        v36 = v167;
      }
      v37 = v36;
      v33 = v35;
      v32 = v37;
    }
    else
    {
      v167 = v168;
      v31 = v20 * v168 + v164;
      v32 = v168;
      v170 = v31;
      v166 = -v23;
      if ( v166 <= (double)v170 )
      {
        v34 = v170 <= v23;
        v33 = v170;
        if ( !v34 )
        {
          v170 = v13;
          v33 = v13;
        }
      }
      else
      {
        v170 = v166;
        v33 = v166;
      }
    }
LABEL_25:
    v96 = v33 * v139;
    v97 = v140 * v33;
    v98 = v33 * v141;
    v119 = v129 * v32;
    v120 = v130 * v32;
    v121 = v32 * v131;
    v93 = v132 - v96;
    v94 = v133 - v97;
    v95 = v134 - v98;
    v116 = v93 + v119;
    v117 = v94 + v120;
    v118 = v95 + v121;
    v168 = v116 * v116 + v117 * v117 + v118 * v118;
    v171 = sqrt(v168);
    v169 = v171 - v156 - v151;
    v38 = v169;
    if ( v169 <= (double)v165 )
    {
      v171 = v168;
      if ( v168 > 1.4210855e-14 )
      {
        v171 = sqrt(v171);
        v110 = 0;
        v171 = 1.0 / v171;
        v171 = -v171;
        v107 = v116 * v171;
        v135 = v107;
        v108 = v117 * v171;
        v136 = v108;
        v109 = v171 * v118;
        v137 = v109;
        v138 = 0;
      }
      else
      {
        v171 = fabs(v141);
        if ( v171 <= 0.70710677 )
        {
          v171 = v140 * v140 + v139 * v139;
          v171 = sqrt(v171);
          v137 = 0.0;
          v171 = 1.0 / v171;
          v135 = -v140 * v171;
          v136 = v171 * v139;
        }
        else
        {
          v171 = v141 * v141 + v140 * v140;
          v171 = sqrt(v171);
          v135 = 0.0;
          v171 = 1.0 / v171;
          v136 = -v141 * v171;
          v137 = v171 * v140;
        }
      }
      v115 = 0;
      v90 = v135 * v151;
      v91 = v136 * v151;
      v92 = v151 * v137;
      v87 = v119 + *(float *)(a4 + 64);
      v88 = *(float *)(a4 + 68) + v120;
      v89 = *(float *)(a4 + 72) + v121;
      v112 = v87 + v90;
      *(float *)v84 = v112;
      v113 = v88 + v91;
      *(float *)&v84[1] = v113;
      v114 = v89 + v92;
      v38 = v169;
      *(float *)&v84[2] = v114;
      LOWORD(v25) = 0;
      v84[3] = 0;
    }
    v39 = v157;
    if ( v165 > v38 )
    {
      v40 = *v157;
      v267 = v38;
      LOWORD(v25) = (*(int (__thiscall **)(_DWORD *, float *, _DWORD *, float))(v40 + 12))(
                      v157,
                      &v135,
                      v84,
                      COERCE_FLOAT(LODWORD(v267)));
    }
    v41 = v39[1];
    if ( *(_DWORD *)(v41 + 1176) )
    {
      if ( *(_DWORD *)(v41 + 1168) == v39[36] )
      {
        LODWORD(v267) = v39 + 20;
        v42 = v39 + 4;
      }
      else
      {
        LODWORD(v267) = v39 + 4;
        v42 = v39 + 20;
      }
LABEL_68:
      LOWORD(v25) = sub_9A4470(v42, LODWORD(v267));
      return LOWORD(v25);
    }
    return LOWORD(v25);
  }
  v75 = *(_DWORD *)(LODWORD(a1) + 12);
  v204 = 9.9999998e17;
  v74 = *(_DWORD *)(LODWORD(a1) + 8);
  v205 = 0;
  sub_9A8350(v8, LODWORD(v9), v74, v75);
  v269 = 0;
  if ( *(_BYTE *)(LODWORD(v155) + 40) )
  {
    v43 = *(_DWORD *)LODWORD(v170);
    v171 = *(float *)(*(_DWORD *)(LODWORD(v166) + 20) + 1184);
    v154 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(v43 + 40))(LODWORD(v170));
    v44 = ((double (__thiscall *)(_DWORD, void *, int))*(_DWORD *)(*(_DWORD *)LODWORD(v167) + 40))(
            LODWORD(v167),
            v268,
            v269)
        + v154
        + v171;
  }
  else
  {
    v154 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)LODWORD(v170) + 40))(LODWORD(v170));
    v45 = ((double (__thiscall *)(_DWORD, void *, int))*(_DWORD *)(*(_DWORD *)LODWORD(v167) + 40))(
            LODWORD(v167),
            v268,
            v269);
    v46 = *(_DWORD *)(LODWORD(v166) + 20);
    v154 = v45 + v154;
    v44 = sub_9A43D0(v46) + v154;
  }
  v204 = v44;
  v267 = 0.0;
  v205 = *(_DWORD *)(LODWORD(v155) + 44);
  v172 = *((float *)a3 + 4);
  v204 = v204 * v204;
  v173 = *((float *)a3 + 5);
  v174 = *((float *)a3 + 6);
  v175 = a3[7];
  v176 = *((float *)a3 + 8);
  v177 = *((float *)a3 + 9);
  v178 = *((float *)a3 + 10);
  v179 = a3[11];
  v180 = *((float *)a3 + 12);
  v181 = *((float *)a3 + 13);
  v182 = *((float *)a3 + 14);
  v183 = a3[15];
  v184 = a3[16];
  v185 = a3[17];
  v186 = a3[18];
  v187 = a3[19];
  v188 = *(float *)(a4 + 16);
  v189 = *(float *)(a4 + 20);
  v190 = *(float *)(a4 + 24);
  v191 = *(_DWORD *)(a4 + 28);
  v192 = *(float *)(a4 + 32);
  v193 = *(float *)(a4 + 36);
  v47 = *(float *)(a4 + 40);
  v266 = *(int **)(LODWORD(v155) + 20);
  v194 = v47;
  v195 = *(_DWORD *)(a4 + 44);
  v48 = *(float *)(a4 + 48);
  v265 = v157;
  v196 = v48;
  v197 = *(float *)(a4 + 52);
  v198 = *(float *)(a4 + 56);
  v199 = *(_DWORD *)(a4 + 60);
  v200 = *(_DWORD *)(a4 + 64);
  v201 = *(_DWORD *)(a4 + 68);
  v202 = *(_DWORD *)(a4 + 72);
  v203 = *(_DWORD *)(a4 + 76);
  LOWORD(v25) = sub_9A8450(&v172, v157, v266, 0);
  v49 = v166;
  v50 = v157;
  if ( *(_DWORD *)(LODWORD(v166) + 28) )
  {
    v25 = *(float *)(v157[1] + 1176);
    if ( SLODWORD(v25) < *(_DWORD *)(LODWORD(v166) + 32) )
    {
      v171 = v79 * v79 + v80 * v80 + v81 * v81;
      v171 = sqrt(v171);
      v128 = 0;
      v171 = 1.0 / v171;
      v168 = v171 * v81;
      v164 = v171 * v80;
      v125 = v171 * v79;
      v51 = v164;
      *(float *)v83 = v125;
      v126 = v164;
      *(float *)&v83[1] = v164;
      v127 = v168;
      *(float *)&v83[2] = v168;
      v171 = fabs(v168);
      v83[3] = 0;
      if ( v171 <= 0.70710677 )
      {
        v171 = v125 * v125 + v51 * v51;
        v171 = sqrt(v171);
        v124 = 0.0;
        v171 = 1.0 / v171;
        v122 = -v164 * v171;
        v123 = v171 * v125;
      }
      else
      {
        v171 = v168 * v168 + v51 * v51;
        v171 = sqrt(v171);
        v122 = 0.0;
        v171 = 1.0 / v171;
        v123 = -v168 * v171;
        v124 = v171 * v164;
      }
      v171 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)LODWORD(v170) + 12))(LODWORD(v170));
      v168 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)LODWORD(v167) + 12))(LODWORD(v167));
      v52 = v171;
      if ( v168 <= (double)v171 )
      {
        v52 = v168;
        v53 = 0;
      }
      else
      {
        v53 = 1;
      }
      LOBYTE(v151) = v53;
      v167 = flt_C64838 / v52;
      if ( v167 > 0.3926990926265717 )
        v167 = 0.39269909;
      if ( v53 )
      {
        v249 = v172;
        v250 = v173;
        v251 = v174;
        v252 = v175;
        v253 = v176;
        v254 = v177;
        v255 = v178;
        v256 = v179;
        v257 = v180;
        v258 = v181;
        v259 = v182;
        v260 = v183;
        v261 = v184;
        v262 = v185;
        v263 = v186;
        v54 = v187;
      }
      else
      {
        v249 = v188;
        v250 = v189;
        v251 = v190;
        v252 = v191;
        v253 = v192;
        v254 = v193;
        v255 = v194;
        v256 = v195;
        v257 = v196;
        v258 = v197;
        v259 = v198;
        v260 = v199;
        v261 = v200;
        v262 = v201;
        v263 = v202;
        v54 = v203;
      }
      v49 = v166;
      v264 = v54;
      v25 = 0.0;
      v168 = 0.0;
      if ( *(int *)(LODWORD(v166) + 28) > 0 )
      {
        v171 = v122 * v122 + v123 * v123 + v124 * v124;
        v55 = v171;
        do
        {
          if ( v55 > 0.00000011920929 )
          {
            sub_997300(&v122, &v167);
            v169 = (float)*(int *)(LODWORD(v166) + 28);
            v56 = 6.283185482025146 / v169;
            v169 = (float)SLODWORD(v168);
            v111 = v56 * v169;
            sub_997300(v83, &v111);
            if ( LOBYTE(v151) )
            {
              v165 = -v160;
              v169 = -v159;
              v82 = -v158;
              v57 = v169;
              v58 = v165;
              v169 = v148 * v161 - v145 * v82 - v169 * v146 - v165 * v147;
              v163 = v165 * v148 + v147 * v161 + v146 * v82 - v57 * v145;
              v165 = v57 * v148 + v146 * v161 + v165 * v145 - v147 * v82;
              v76 = v82 * v148 + v145 * v161 + v147 * v57 - v58 * v146;
              v59 = v169;
              v60 = v165;
              v61 = v163;
              v163 = v161 * v169 - v76 * v158 - v159 * v165 - v160 * v163;
              v165 = v161 * v61 + v160 * v169 + v76 * v159 - v158 * v165;
              v86[2] = v165;
              v86[3] = v163;
              v169 = v161 * v60 + v159 * v169 + v158 * v61 - v76 * v160;
              v86[0] = v60 * v160 + v161 * v76 + v59 * v158 - v61 * v159;
              v86[1] = v169;
              sub_603C50(v86);
              v170 = *((float *)a3 + 10);
              v164 = *((float *)a3 + 6);
              v152 = *((float *)a3 + 14);
              *((float *)&v154 + 1) = v213 * v164 + v214 * v170 + v215 * v152;
              v163 = *((float *)a3 + 9);
              v156 = *((float *)a3 + 5);
              v165 = *((float *)a3 + 13);
              v162 = v213 * v156 + v214 * v163 + v215 * v165;
              v150 = *((float *)a3 + 8);
              v169 = *((float *)a3 + 4);
              v149 = *((float *)a3 + 12);
              v62 = v150;
              v63 = v149;
              v153 = v215 * v149 + v214 * v150 + v213 * v169;
              v142 = v211 * v170 + v210 * v164 + v212 * v152;
              v143 = v211 * v163 + v210 * v156 + v212 * v165;
              v144 = v211 * v150 + v210 * v169 + v212 * v149;
              v150 = v207 * v164 + v208 * v170 + v209 * v152;
              v149 = v207 * v156 + v208 * v163 + v209 * v165;
              v239 = v150;
              v241 = v144;
              v240 = 0;
              v242 = v143;
              v243 = v142;
              v237 = v62 * v208 + v207 * v169 + v63 * v209;
              v172 = v237;
              v238 = v149;
              v173 = v149;
              v174 = v150;
              v175 = 0;
              v176 = v144;
              v177 = v143;
              v178 = v142;
              v244 = 0;
              v179 = 0;
              v245 = v153;
              v180 = v153;
              v246 = v162;
              v181 = v162;
              v247 = HIDWORD(v154);
              v182 = *((float *)&v154 + 1);
              v248 = 0;
              v183 = 0;
              v188 = *(float *)(a4 + 16);
              v189 = *(float *)(a4 + 20);
              v190 = *(float *)(a4 + 24);
              v191 = *(_DWORD *)(a4 + 28);
              v192 = *(float *)(a4 + 32);
              v193 = *(float *)(a4 + 36);
              v194 = *(float *)(a4 + 40);
              v195 = *(_DWORD *)(a4 + 44);
              v196 = *(float *)(a4 + 48);
              v197 = *(float *)(a4 + 52);
              v198 = *(float *)(a4 + 56);
              v199 = *(_DWORD *)(a4 + 60);
              v200 = *(_DWORD *)(a4 + 64);
              v201 = *(_DWORD *)(a4 + 68);
              v202 = *(_DWORD *)(a4 + 72);
              v203 = *(_DWORD *)(a4 + 76);
            }
            else
            {
              v172 = *((float *)a3 + 4);
              v162 = -v160;
              v173 = *((float *)a3 + 5);
              v64 = *((float *)a3 + 6);
              *((float *)&v154 + 1) = -v159;
              v174 = v64;
              v175 = a3[7];
              v77 = -v158;
              v176 = *((float *)a3 + 8);
              v177 = *((float *)a3 + 9);
              v178 = *((float *)a3 + 10);
              v179 = a3[11];
              v180 = *((float *)a3 + 12);
              v65 = *((float *)&v154 + 1);
              v181 = *((float *)a3 + 13);
              v182 = *((float *)a3 + 14);
              v183 = a3[15];
              v66 = v162;
              v184 = a3[16];
              v185 = a3[17];
              v186 = a3[18];
              v187 = a3[19];
              *((float *)&v154 + 1) = v148 * v161 - v77 * v145 - *((float *)&v154 + 1) * v146 - v162 * v147;
              v153 = v162 * v148 + v147 * v161 + v77 * v146 - v65 * v145;
              v162 = v65 * v148 + v146 * v161 + v162 * v145 - v77 * v147;
              v78 = v145 * v161 + v77 * v148 + v147 * v65 - v66 * v146;
              v67 = *((float *)&v154 + 1);
              v68 = v162;
              v69 = v153;
              v153 = *((float *)&v154 + 1) * v161 - v78 * v158 - v162 * v159 - v153 * v160;
              v162 = v69 * v161 + *((float *)&v154 + 1) * v160 + v78 * v159 - v162 * v158;
              v85[2] = v162;
              v85[3] = v153;
              *((float *)&v154 + 1) = v68 * v161 + *((float *)&v154 + 1) * v159 + v69 * v158 - v78 * v160;
              v85[0] = v68 * v160 + v161 * v78 + v67 * v158 - v69 * v159;
              v85[1] = *((float *)&v154 + 1);
              sub_603C50(v85);
              v165 = *(float *)(a4 + 40);
              v169 = *(float *)(a4 + 24);
              v163 = *(float *)(a4 + 56);
              v150 = v222 * v169 + v223 * v165 + v224 * v163;
              v152 = *(float *)(a4 + 36);
              v156 = *(float *)(a4 + 20);
              v164 = *(float *)(a4 + 52);
              v149 = v222 * v156 + v223 * v152 + v224 * v164;
              *((float *)&v154 + 1) = *(float *)(a4 + 32);
              v170 = *(float *)(a4 + 16);
              v162 = *(float *)(a4 + 48);
              v70 = *((float *)&v154 + 1);
              v71 = v162;
              v144 = v224 * v162 + v223 * *((float *)&v154 + 1) + v222 * v170;
              v143 = v219 * v169 + v220 * v165 + v221 * v163;
              v142 = v219 * v156 + v220 * v152 + v221 * v164;
              v228 = 0;
              v232 = 0;
              v236 = 0;
              v153 = v219 * v170 + v220 * *((float *)&v154 + 1) + v221 * v162;
              v162 = v216 * v169 + v217 * v165 + v218 * v163;
              v227 = v162;
              v229 = v153;
              v230 = v142;
              v231 = v143;
              v233 = v144;
              v234 = v149;
              v235 = v150;
              *((float *)&v154 + 1) = v216 * v156 + v217 * v152 + v218 * v164;
              v225 = v70 * v217 + v216 * v170 + v71 * v218;
              v188 = v225;
              v226 = *((float *)&v154 + 1);
              v189 = *((float *)&v154 + 1);
              v190 = v162;
              v191 = 0;
              v192 = v153;
              v193 = v142;
              v194 = v143;
              v195 = 0;
              v196 = v144;
              v197 = v149;
              v198 = v150;
              v199 = 0;
            }
            sub_993BA0(v157, &v172, &v188, &v249, SLOBYTE(v151), *(_DWORD *)(LODWORD(v155) + 20));
            v267 = 0.0;
            v266 = *(int **)(LODWORD(v155) + 20);
            LOBYTE(v269) = 1;
            sub_9A8450(&v172, &p_??_7Result@btDiscreteCollisionDetectorInterface@@6B@, v266, 0);
            v55 = v171;
            v49 = v166;
            v25 = v168;
            p_??_7Result@btDiscreteCollisionDetectorInterface@@6B@ = &btDiscreteCollisionDetectorInterface::Result::`vftable';
          }
          ++LODWORD(v25);
          v168 = v25;
        }
        while ( SLODWORD(v25) < *(_DWORD *)(LODWORD(v49) + 28) );
      }
      v50 = v157;
    }
  }
  v6 = *(_BYTE *)(LODWORD(v49) + 16) == 0;
  v269 = -1;
  if ( !v6 )
  {
    v72 = v50[1];
    if ( *(_DWORD *)(v72 + 1176) )
    {
      if ( *(_DWORD *)(v72 + 1168) == v50[36] )
      {
        LODWORD(v267) = v50 + 20;
        v42 = v50 + 4;
      }
      else
      {
        LODWORD(v267) = v50 + 4;
        v42 = v50 + 20;
      }
      goto LABEL_68;
    }
  }
  return LOWORD(v25);
}
