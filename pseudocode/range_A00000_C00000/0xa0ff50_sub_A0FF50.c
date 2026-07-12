// Function: sub_A0FF50
// Address: 0xa0ff50
// Size: 0x634
// Prototype: int __stdcall(int, int, int, float)

int __thiscall sub_A0FF50(float *this, unsigned int a2, unsigned int a3, int n7, float a5)
{
  int v8; // eax
  int v9; // ecx
  double v10; // st7
  float *v11; // edi
  float *v12; // edx
  double v13; // st7
  double v14; // st5
  int v15; // ecx
  int v16; // edx
  double v17; // rt1
  double v18; // st5
  double v19; // st7
  double v20; // st6
  float *v21; // edx
  float *v22; // eax
  float *v23; // ecx
  double v24; // st7
  double v25; // st6
  double v26; // st5
  double n7_3; // st4
  float *v28; // edi
  float *v29; // ecx
  int n7_4; // esi
  double v31; // st3
  double v32; // st2
  double v33; // st2
  double v34; // st7
  float *this_1; // esi
  float *v36; // ecx
  float *v37; // edi
  float *v38; // esi
  float *v39; // eax
  int n7_7; // edx
  double v41; // st5
  double v42; // st4
  double v43; // st7
  double v44; // st6
  int v45; // eax
  int n7_8; // ecx
  float *v47; // edi
  int n7_10; // edx
  unsigned int v49; // ecx
  float *v50; // eax
  double v51; // st5
  float *v52; // eax
  int v53; // ecx
  float *v54; // ecx
  float *v55; // eax
  int n7_11; // edx
  double v57; // st5
  double v58; // rt2
  double v59; // st4
  double v60; // rtt
  double v61; // st5
  double v62; // st7
  int v63; // ebx
  unsigned int v64; // edi
  float *v65; // ecx
  float *v66; // edx
  int v67; // eax
  int v68; // eax
  float v69; // [esp+8h] [ebp-70h]
  float v70; // [esp+18h] [ebp-60h]
  float v71; // [esp+18h] [ebp-60h]
  float v72; // [esp+1Ch] [ebp-5Ch]
  float v73; // [esp+28h] [ebp-50h]
  float v74; // [esp+28h] [ebp-50h]
  float v75; // [esp+2Ch] [ebp-4Ch]
  float v76; // [esp+2Ch] [ebp-4Ch]
  float v77; // [esp+2Ch] [ebp-4Ch]
  float v78; // [esp+30h] [ebp-48h]
  double v79; // [esp+30h] [ebp-48h]
  float v80; // [esp+30h] [ebp-48h]
  float v81; // [esp+34h] [ebp-44h]
  float v82; // [esp+34h] [ebp-44h]
  float v83; // [esp+38h] [ebp-40h]
  float v84; // [esp+3Ch] [ebp-3Ch]
  double v85; // [esp+40h] [ebp-38h]
  float v86; // [esp+40h] [ebp-38h]
  float v87; // [esp+44h] [ebp-34h]
  float v88; // [esp+48h] [ebp-30h]
  float *v89; // [esp+4Ch] [ebp-2Ch]
  float *v91; // [esp+54h] [ebp-24h]
  float v92; // [esp+58h] [ebp-20h]
  float *v93; // [esp+58h] [ebp-20h]
  float v94; // [esp+58h] [ebp-20h]
  float n7_12; // [esp+5Ch] [ebp-1Ch]
  float v96; // [esp+5Ch] [ebp-1Ch]
  float *v97; // [esp+5Ch] [ebp-1Ch]
  float v98; // [esp+5Ch] [ebp-1Ch]
  float *v99; // [esp+60h] [ebp-18h]
  float v100; // [esp+60h] [ebp-18h]
  int v101; // [esp+64h] [ebp-14h]
  float v102; // [esp+64h] [ebp-14h]
  float v103; // [esp+64h] [ebp-14h]
  float *v104; // [esp+68h] [ebp-10h]
  int n7_9; // [esp+68h] [ebp-10h]
  float v106; // [esp+68h] [ebp-10h]
  float n7_2; // [esp+6Ch] [ebp-Ch]
  float v108; // [esp+6Ch] [ebp-Ch]
  float *v109; // [esp+70h] [ebp-8h]
  float v110; // [esp+74h] [ebp-4h]
  int n7_5; // [esp+74h] [ebp-4h]
  float n7_1; // [esp+88h] [ebp+10h]
  float v113; // [esp+88h] [ebp+10h]
  int n7_13; // [esp+88h] [ebp+10h]
  float n7_14; // [esp+88h] [ebp+10h]
  float v116; // [esp+88h] [ebp+10h]
  float v117; // [esp+88h] [ebp+10h]
  float v118; // [esp+88h] [ebp+10h]
  float v119; // [esp+88h] [ebp+10h]
  int v120; // [esp+88h] [ebp+10h]
  int v121; // [esp+88h] [ebp+10h]
  float v122; // [esp+88h] [ebp+10h]
  float v123; // [esp+88h] [ebp+10h]
  float v124; // [esp+8Ch] [ebp+14h]
  float v125; // [esp+8Ch] [ebp+14h]
  float v126; // [esp+8Ch] [ebp+14h]
  float v127; // [esp+8Ch] [ebp+14h]
  float v128; // [esp+8Ch] [ebp+14h]
  int n7_6; // [esp+8Ch] [ebp+14h]
  int v130; // [esp+8Ch] [ebp+14h]
  float v131; // [esp+8Ch] [ebp+14h]

  if ( (n7 & 1) == 0 || n7 > 7 || n7 < 3 )
    return 5;
  v8 = n7 / 2;
  v9 = n7 / -2;
  *(this + n7 / 2 + 8) = 4.0;
  v101 = n7 / -2;
  if ( n7 / -2 <= n7 / 2 )
  {
    v10 = a5;
    v11 = this + 15;
    v12 = this + 22;
    do
    {
      v124 = (float)v101;
      v125 = v124 * v10;
      *v12 = v125;
      if ( v9 )
        *v11++ = v125;
      ++v9;
      ++v12;
      v101 = v9;
    }
    while ( v9 <= v8 );
  }
  v126 = *(this + v8 + 8);
  v13 = v126;
  v110 = v126;
  if ( v8 >= 1 )
  {
    v14 = 0.6000000238418579;
    v15 = (int)(this + v8 + 9);
    v16 = (int)(this + v8 + 7);
    while ( 1 )
    {
      v15 += 4;
      v17 = v14;
      v18 = v13 * v14;
      v19 = v17;
      v16 -= 4;
      v127 = v18;
      *(float *)(v16 + 4) = v127;
      *(float *)(v15 - 4) = v127;
      v110 = v127 * 2.0 + v110;
      if ( !--v8 )
        break;
      v14 = v19;
      v13 = v127;
    }
  }
  v91 = this + 8;
  v20 = v110;
  n7_5 = 0;
  v73 = *(this + 8) / v20;
  v75 = *(this + 9) / v20;
  v78 = *(this + 10) / v20;
  v81 = *(this + 11) / v20;
  *(this + 323) = v73;
  *(this + 324) = v75;
  *(this + 325) = v78;
  *(this + 326) = v81;
  v128 = (float)(a2 >> 1);
  v92 = (float)(a3 >> 1);
  v102 = v92;
  n7_1 = (float)n7;
  n7_2 = n7_1;
  v113 = sqrt(1.799999952316284);
  v21 = this + 22;
  v89 = this + 22;
  v22 = this + 31;
  v23 = this + 225;
  v109 = this + 22;
  v104 = this + 31;
  v93 = this + 225;
  v24 = 1.0;
  v85 = 1.0 / v113;
  v25 = 0.5;
  v26 = v128;
  n7_3 = n7_2;
  while ( 1 )
  {
    v28 = v23;
    v29 = v89;
    n7_4 = 0;
    n7_12 = (float)n7_5;
    n7_13 = 0;
    v99 = v22;
    v31 = 2.0;
    v96 = (n7_12 + v25) / n7_3 * 2.0 - v24;
    v32 = v96;
    v97 = v89;
    v33 = v32 * v32;
    v79 = v33;
    while ( 1 )
    {
      v70 = *v29 / v26;
      v72 = *v21 / v102;
      *(v22 - 2) = v70;
      *(v22 - 1) = v72;
      *v22 = 0.0;
      v22[1] = 0.0;
      n7_14 = (float)n7_13;
      v116 = v31 * ((v25 + n7_14) / n7_3) - v24;
      v117 = v33 + v116 * v116;
      v118 = sqrt(v117);
      v119 = v118 * v85;
      v34 = v119;
      if ( v119 > 1.0 )
        v34 = (float)1.0;
      *v28 = v34;
      v21 = v109;
      ++n7_4;
      v22 = v99 + 4;
      v29 = v97 + 1;
      ++v28;
      n7_13 = n7_4;
      v99 += 4;
      ++v97;
      if ( n7_4 >= n7 )
        break;
      v26 = v128;
      v24 = 1.0;
      v25 = 0.5;
      v31 = 2.0;
      v33 = v79;
      n7_3 = n7_2;
    }
    v23 = &v93[n7];
    v104 += 4 * n7;
    v24 = 1.0;
    v25 = 0.5;
    v21 = v109 + 1;
    ++n7_5;
    v22 = v104;
    ++v109;
    v93 = v23;
    if ( n7_5 >= n7 )
      break;
    n7_3 = n7_2;
    v26 = v128;
  }
  this_1 = this;
  v36 = v91;
  *(float *)&v120 = 0.0;
  if ( n7 > 0 )
  {
    v37 = v91;
    n7_6 = n7;
    v38 = this + 274;
    do
    {
      v39 = v38;
      n7_7 = n7;
      v41 = *v37;
      do
      {
        v42 = *v36++;
        ++v39;
        v88 = v42 * v41;
        *(v39 - 1) = v88;
        *(float *)&v120 = v88 + *(float *)&v120;
        --n7_7;
      }
      while ( n7_7 );
      v36 = v91;
      ++v37;
      v38 += n7;
      --n7_6;
    }
    while ( n7_6 );
    this_1 = this;
  }
  v43 = 0.0;
  *(float *)&v121 = 1.0 / *(float *)&v120;
  if ( n7 > 0 )
  {
    v44 = *(float *)&v121;
    v45 = 0;
    n7_8 = n7;
    v130 = 0;
    v47 = this_1 + 275;
    n7_9 = n7;
    do
    {
      n7_10 = 0;
      if ( n7 >= 4 )
      {
        v49 = ((unsigned int)(n7 - 4) >> 2) + 1;
        v50 = v47;
        n7_10 = 4 * v49;
        do
        {
          v51 = *(v50 - 1);
          v50 += 4;
          *(v50 - 5) = v51 * v44;
          *(v50 - 4) = *(v50 - 4) * v44;
          *(v50 - 3) = *(v50 - 3) * v44;
          *(v50 - 2) = *(v50 - 2) * v44;
          --v49;
        }
        while ( v49 );
        v45 = v130;
        n7_8 = n7_9;
      }
      if ( n7_10 < n7 )
      {
        v52 = &this_1[n7_10 + 274 + v45];
        v53 = n7 - n7_10;
        do
        {
          ++v52;
          *(v52 - 1) = v44 * *(v52 - 1);
          --v53;
        }
        while ( v53 );
        v45 = v130;
        n7_8 = n7_9;
      }
      v45 += n7;
      v47 += n7;
      --n7_8;
      v130 = v45;
      n7_9 = n7_8;
    }
    while ( n7_8 );
    v122 = (float)(a2 >> 1);
    v131 = v122;
    v123 = (float)(a3 >> 1);
    v54 = this_1 + 22;
    v55 = this_1 + 329;
    n7_11 = n7;
    v57 = v123;
    while ( 1 )
    {
      v59 = *v54++;
      v55 += 4;
      v71 = v59 / v131;
      v76 = *(v54 - 1) / v57;
      *(v55 - 6) = v71;
      v60 = v57;
      v61 = v43;
      v62 = v60;
      *(v55 - 5) = v61;
      *(v55 - 4) = v61;
      *(v55 - 3) = v61;
      v55[22] = v61;
      v55[23] = v76;
      v55[24] = v61;
      v55[25] = v61;
      if ( !--n7_11 )
        break;
      v58 = v61;
      v57 = v62;
      v43 = v58;
    }
  }
  v63 = n7 * n7 - 1;
  v64 = 0;
  if ( v63 > 0 )
  {
    v65 = this_1 + 226;
    v66 = this_1 + 33;
    do
    {
      v100 = v66[1];
      v98 = *v66;
      v94 = *(v66 - 3);
      v108 = v66[9];
      v106 = v66[8];
      v103 = v66[5];
      v69 = v66[4];
      v74 = *(v65 - 1);
      v77 = *v65;
      v67 = 2 * (v64 >> 1);
      v80 = v65[1];
      v82 = v65[2];
      v83 = v65[48];
      v84 = v65[49];
      v86 = v65[50];
      v87 = v65[51];
      this_1[2 * v67 + 383] = *(v66 - 4);
      this_1[2 * v67 + 384] = v94;
      this_1[2 * v67 + 385] = v98;
      this_1[2 * v67 + 386] = v100;
      this_1[2 * v67 + 387] = v69;
      this_1[2 * v67 + 388] = v103;
      this_1[2 * v67 + 389] = v106;
      this_1[2 * v67 + 390] = v108;
      v68 = 2 * (v64 >> 2);
      this_1[2 * v68 + 775] = v74;
      this_1[2 * v68 + 776] = v77;
      this_1[2 * v68 + 777] = v80;
      this_1[2 * v68 + 778] = v82;
      this_1[2 * v68 + 579] = v83;
      this_1[2 * v68 + 580] = v84;
      v64 += 4;
      v65 += 4;
      this_1[2 * v68 + 581] = v86;
      v66 += 16;
      this_1[2 * v68 + 582] = v87;
    }
    while ( (int)v64 < v63 );
  }
  return 0;
}

