// Function: sub_AA0790
// Address: 0xaa0790
// Size: 0xe0c
// Prototype: 

int __cdecl sub_AA0790(_DWORD *a1)
{
  _DWORD *v1; // edi
  int v2; // eax
  int v3; // ebx
  int size; // esi
  int v5; // ecx
  void *v6; // esp
  size_t Size; // esi
  signed int v8; // eax
  _DWORD *v9; // eax
  int v10; // eax
  int v11; // edx
  size_t v12; // ecx
  size_t Size_1; // esi
  _DWORD *v14; // eax
  int v15; // eax
  int v16; // edx
  size_t v17; // ecx
  size_t Size_2; // esi
  _DWORD *v19; // eax
  int v20; // eax
  _DWORD *Size_10; // ecx
  int size_1; // eax
  void *v23; // esp
  int v24; // edx
  int n1000_2; // esi
  _DWORD *v26; // ecx
  int v27; // eax
  bool v28; // cc
  size_t Size_3; // edx
  float *Src_3; // esi
  _DWORD *v31; // eax
  void *v32; // eax
  int v33; // eax
  int v34; // ebx
  int v35; // ecx
  _DWORD *v36; // eax
  void *v37; // eax
  int v38; // eax
  int v39; // ecx
  int v40; // edx
  int n4; // ecx
  int v42; // edx
  float *buf_1; // edx
  float v44; // xmm2_4
  int n4_6; // ecx
  float v46; // xmm0_4
  int n4_5; // ebx
  float v48; // xmm0_4
  int v49; // ecx
  float *buf_2; // edx
  _DWORD *v51; // eax
  void *v52; // eax
  int v53; // eax
  int v54; // ecx
  int Src_7; // esi
  char *v56; // eax
  int n1000_1; // esi
  _DWORD *v58; // eax
  void *v59; // eax
  int v60; // eax
  int v61; // ecx
  int Size_8; // edx
  _DWORD *v63; // eax
  void *v64; // eax
  int v65; // eax
  void *v66; // ecx
  int n4_7; // ecx
  int n4_8; // eax
  int v69; // edi
  int v70; // ecx
  float v71; // eax
  int v72; // edx
  unsigned int v73; // ecx
  float v74; // xmm0_4
  float v75; // xmm0_4
  float v76; // xmm0_4
  float v77; // xmm0_4
  float v78; // xmm0_4
  float v79; // xmm0_4
  int v80; // edx
  int v81; // ecx
  int v82; // ebx
  int v83; // edx
  int v84; // eax
  _DWORD **Size_9; // edx
  int v86; // edx
  int v87; // eax
  float v88; // xmm2_4
  float *v89; // edi
  _BYTE *v90; // esi
  float *n7_2; // ecx
  int v92; // ebx
  float v93; // xmm0_4
  int v94; // eax
  int v95; // eax
  int v96; // edx
  int v97; // eax
  float v98; // xmm2_4
  float *v99; // esi
  _BYTE *v100; // edi
  float *n7_3; // ecx
  int v102; // ebx
  float v103; // xmm0_4
  int v104; // eax
  int v105; // eax
  _DWORD *v106; // ecx
  int i; // esi
  int v108; // eax
  int n4_3; // ebx
  int v110; // ecx
  int n32; // ebx
  int j; // esi
  int v113; // eax
  int size_2; // esi
  void *v115; // esp
  void *v116; // esp
  int v117; // eax
  _DWORD *v118; // eax
  BOOL v119; // eax
  int n7; // edx
  BOOL v122; // eax
  int v123; // edx
  _BYTE *Src_5; // esi
  _DWORD *Size_11; // esi
  int n1000_3; // edx
  float v127; // eax
  float *v128; // ecx
  int v129; // eax
  int *n1000_4; // esi
  int *v131; // ebx
  int v132; // esi
  float *buf_3; // edx
  int v134; // ebx
  _DWORD *v135; // edx
  float v136; // ecx
  _DWORD *Size_5; // eax
  _DWORD *v138; // esi
  float v139; // edi
  int v140; // eax
  float v141; // edi
  int v142; // eax
  _DWORD *Size_6; // ebx
  int v144; // eax
  int v145; // ecx
  int v146; // edx
  int Src_6; // edi
  _DWORD *v148; // esi
  BOOL v149; // eax
  int v150; // [esp-8h] [ebp-80h]
  int v151; // [esp-4h] [ebp-7Ch]
  int v152; // [esp+0h] [ebp-78h]
  _BYTE Src_1[12]; // [esp+4h] [ebp-74h] BYREF
  float v154; // [esp+10h] [ebp-68h]
  float v155; // [esp+14h] [ebp-64h]
  int n4_9; // [esp+18h] [ebp-60h]
  float *v157; // [esp+1Ch] [ebp-5Ch]
  int v158; // [esp+20h] [ebp-58h]
  int v159; // [esp+24h] [ebp-54h]
  void *Src; // [esp+28h] [ebp-50h]
  int n4_2; // [esp+2Ch] [ebp-4Ch]
  int v162; // [esp+30h] [ebp-48h]
  int Size_7; // [esp+34h] [ebp-44h]
  int v164; // [esp+38h] [ebp-40h]
  float v165; // [esp+3Ch] [ebp-3Ch]
  _BYTE *Src_4; // [esp+40h] [ebp-38h]
  int n7_1; // [esp+44h] [ebp-34h]
  float *buf; // [esp+48h] [ebp-30h]
  _BYTE *Src_2; // [esp+4Ch] [ebp-2Ch]
  int v170; // [esp+50h] [ebp-28h]
  int v171; // [esp+54h] [ebp-24h]
  _DWORD *Size_4; // [esp+58h] [ebp-20h]
  int v173; // [esp+5Ch] [ebp-1Ch]
  int v174; // [esp+60h] [ebp-18h]
  int n4_1; // [esp+64h] [ebp-14h]
  int n4_4; // [esp+68h] [ebp-10h]
  _DWORD *v177; // [esp+6Ch] [ebp-Ch]
  int n1000; // [esp+70h] [ebp-8h]
  int v179; // [esp+74h] [ebp-4h]

  v1 = a1;
  v2 = a1[16];
  v3 = *(_DWORD *)(v2 + 4);
  size = *(_DWORD *)(v3 + 4);
  v5 = *(_DWORD *)(v3 + 28);
  v177 = *(_DWORD **)(v2 + 104);
  v164 = a1[26];
  v173 = a1[9];
  size *= 4;
  v179 = v3;
  v170 = v5;
  v6 = alloca(size);
  Size = (size + 7) & 0xFFFFFFF8;
  v8 = Size + a1[18];
  Src = Src_1;
  if ( v8 > a1[19] )
  {
    if ( a1[17] )
    {
      v9 = malloc_0(8u);
      a1[20] += a1[18];
      v9[1] = a1[21];
      *v9 = a1[17];
      a1[21] = v9;
    }
    a1[19] = Size;
    a1[17] = malloc_0(Size);
    a1[18] = 0;
  }
  v10 = a1[18];
  v11 = a1[17];
  v162 = v11 + v10;
  v12 = v10 + Size;
  a1[18] = v10 + Size;
  Size_1 = (4 * *(_DWORD *)(v3 + 4) + 7) & 0xFFFFFFF8;
  if ( (signed int)(v12 + Size_1) > a1[19] )
  {
    if ( v11 )
    {
      v14 = malloc_0(8u);
      a1[20] += a1[18];
      v14[1] = a1[21];
      *v14 = a1[17];
      a1[21] = v14;
    }
    a1[19] = Size_1;
    a1[17] = malloc_0(Size_1);
    a1[18] = 0;
  }
  v15 = a1[18];
  v16 = a1[17];
  v171 = v16 + v15;
  v17 = v15 + Size_1;
  a1[18] = v15 + Size_1;
  Size_2 = (4 * *(_DWORD *)(v3 + 4) + 7) & 0xFFFFFFF8;
  if ( (signed int)(v17 + Size_2) > a1[19] )
  {
    if ( v16 )
    {
      v19 = malloc_0(8u);
      a1[20] += a1[18];
      v19[1] = a1[21];
      *v19 = a1[17];
      a1[21] = v19;
    }
    a1[19] = Size_2;
    a1[17] = malloc_0(Size_2);
    a1[18] = 0;
  }
  v20 = a1[18];
  Size_10 = (_DWORD *)(v20 + a1[17]);
  a1[18] = Size_2 + v20;
  Size_7 = (int)Size_10;
  size_1 = 4 * *(_DWORD *)(v3 + 4);
  v165 = *(float *)(v164 + 4);
  v23 = alloca(size_1);
  v24 = a1[7];
  n1000_2 = *(_DWORD *)(v170 + 4 * v24 + 544);
  v26 = v177;
  v27 = v177[14] + 52 * (*(_DWORD *)(v164 + 8) + (v24 != 0 ? 2 : 0));
  a1[10] = v24;
  v28 = *(_DWORD *)(v3 + 4) <= 0;
  Src_2 = Src_1;
  v158 = v24;
  n1000 = n1000_2;
  v174 = v27;
  n7_1 = 0;
  if ( !v28 )
  {
    *(float *)&n4_1 = 4.0 / (float)v173;
    v157 = (float *)(v26 + 1);
    n4_2 = v173 - 1;
    Size_3 = (4 * (v173 / 2) + 7) & 0xFFFFFFF8;
    v159 = v171 - v162;
    Size_4 = (_DWORD *)Size_3;
    Src_3 = (float *)Src_1;
    Src_4 = (_BYTE *)(v162 - (_DWORD)Src_1);
    do
    {
      buf = *(float **)(*a1 + 4 * n7_1);
      if ( (signed int)(Size_3 + a1[18]) > a1[19] )
      {
        if ( a1[17] )
        {
          v31 = malloc_0(8u);
          Size_3 = (size_t)Size_4;
          a1[20] += a1[18];
          v31[1] = a1[21];
          *v31 = a1[17];
          a1[21] = v31;
        }
        a1[19] = Size_3;
        v32 = malloc_0(Size_3);
        Size_3 = (size_t)Size_4;
        a1[17] = v32;
        a1[18] = 0;
      }
      v33 = a1[18];
      v34 = v159;
      v35 = v33 + a1[17];
      a1[18] = Size_3 + v33;
      *(_DWORD *)&Src_4[(_DWORD)Src_3 + v34] = v35;
      v3 = v179;
      if ( (signed int)(Size_3 + a1[18]) > a1[19] )
      {
        if ( a1[17] )
        {
          v36 = malloc_0(8u);
          Size_3 = (size_t)Size_4;
          a1[20] += a1[18];
          v36[1] = a1[21];
          *v36 = a1[17];
          a1[21] = v36;
        }
        a1[19] = Size_3;
        v37 = malloc_0(Size_3);
        Size_3 = (size_t)Size_4;
        a1[17] = v37;
        a1[18] = 0;
      }
      v38 = a1[18];
      v39 = v38 + a1[17];
      n4_4 = n4_1;
      a1[18] = Size_3 + v38;
      v40 = (int)v157;
      *(_DWORD *)((char *)Src_3 + (_DWORD)Src_4) = v39;
      v152 = a1[8];
      v151 = a1[7];
      v150 = a1[6];
      v155 = (float)((float)((float)((double)(n4_4 & 0x7FFFFFFF) + 0.0) * 0.00000071771143) - 764.61621) + 0.345;
      sub_A9E680(buf, v40, v170, v150, v151, v152);
      sub_A9D3E0(*(int **)v177[a1[7] + 3], (int)buf, *(_DWORD *)((char *)Src_3 + (_DWORD)Src_4));
      n4 = v177[3 * a1[7] + 5];
      if ( n4 != 1 )
      {
        v42 = v177[3 * a1[7] + 6];
        sub_A997D0(n4, (int)buf, v42, v42 + 4 * n4, v177[3 * a1[7] + 7]);
        v3 = v179;
      }
      buf_1 = buf;
      n4_9 = *(_DWORD *)buf;
      v44 = v155;
      n4_6 = 1;
      v46 = (float)((float)((float)((float)((double)(n4_9 & 0x7FFFFFFF) + 0.0) * 0.00000071771143) - 764.61621) + v155)
          + 0.345;
      *buf = v46;
      *Src_3 = v46;
      if ( n4_2 > 1 )
      {
        n4_5 = n4_2;
        do
        {
          v154 = (float)(buf_1[n4_6] * buf_1[n4_6]) + (float)(buf_1[n4_6 + 1] * buf_1[n4_6 + 1]);
          v48 = (float)((float)((float)((float)((float)((double)(LODWORD(v154) & 0x7FFFFFFF) + 0.0) * 0.00000071771143)
                                      - 764.61621)
                              * 0.5)
                      + v44)
              + 0.345;
          buf_1[(n4_6 + 1) >> 1] = v48;
          if ( v48 > *Src_3 )
            *Src_3 = v48;
          n4_6 += 2;
        }
        while ( n4_6 < n4_5 );
        v3 = v179;
      }
      if ( *Src_3 > 0.0 )
        *Src_3 = 0.0;
      if ( *Src_3 > v165 )
        v165 = *Src_3;
      Size_3 = (size_t)Size_4;
      ++Src_3;
      ++n7_1;
    }
    while ( n7_1 < *(_DWORD *)(v3 + 4) );
  }
  v49 = a1[18];
  n4_1 = v173 / 2;
  buf_2 = (float *)((4 * (v173 / 2) + 7) & 0xFFFFFFF8);
  buf = buf_2;
  if ( (int)buf_2 + v49 > a1[19] )
  {
    if ( a1[17] )
    {
      v51 = malloc_0(8u);
      buf_2 = buf;
      a1[20] += a1[18];
      v51[1] = a1[21];
      *v51 = a1[17];
      a1[21] = v51;
    }
    a1[19] = buf_2;
    v52 = malloc_0((size_t)buf_2);
    buf_2 = buf;
    a1[17] = v52;
    a1[18] = 0;
  }
  v53 = a1[18];
  v54 = a1[17];
  Src_7 = v54 + v53;
  v56 = (char *)buf_2 + v53;
  a1[18] = v56;
  Src_4 = (_BYTE *)Src_7;
  n1000_1 = n1000;
  if ( (int)&v56[(int)buf_2] > a1[19] )
  {
    if ( v54 )
    {
      v58 = malloc_0(8u);
      buf_2 = buf;
      a1[20] += a1[18];
      v58[1] = a1[21];
      *v58 = a1[17];
      a1[21] = v58;
    }
    a1[19] = buf_2;
    v59 = malloc_0((size_t)buf_2);
    buf_2 = buf;
    a1[17] = v59;
    a1[18] = 0;
  }
  v60 = a1[18];
  n7_1 = v60 + a1[17];
  v61 = 0;
  a1[18] = (char *)buf_2 + v60;
  v159 = 0;
  if ( *(int *)(v3 + 4) <= 0 )
  {
LABEL_83:
    *(float *)(v164 + 4) = v165;
    size_2 = 4 * *(_DWORD *)(v3 + 4);
    v115 = alloca(size_2);
    Src_4 = Src_1;
    v116 = alloca(size_2);
    v117 = v1[16];
    v165 = COERCE_FLOAT(Src_1);
    v118 = (_DWORD *)(*(_DWORD *)(v117 + 104) + 80);
    v119 = v118 && *v118;
    n7 = 7;
    if ( v119 )
      n7 = 0;
    n7_1 = n7;
    v122 = sub_A9DED0(v1);
    if ( v123 <= (v122 ? 14 : 7) )
    {
      do
      {
        Src_2 = *(_BYTE **)(v164 + 4 * v123 + 12);
        Src_5 = Src_2;
        sub_42E350(Src_2, 0, 1);
        sub_42E350(Src_5, v158, v177[11]);
        if ( v1[7] )
        {
          sub_42E350(Src_5, v1[6], 1);
          sub_42E350(Src_5, v1[8], 1);
        }
        v28 = *(_DWORD *)(v3 + 4) <= 0;
        v159 = 0;
        if ( !v28 )
        {
          Size_11 = (_DWORD *)Size_7;
          n1000_3 = n1000;
          LODWORD(v127) = v171 - Size_7;
          n4_2 = (int)Src - Size_7;
          v1 = a1;
          v128 = (float *)(n1000 + 4);
          buf = (float *)(n1000 + 4);
          LODWORD(v154) = v171 - Size_7;
          do
          {
            v129 = sub_AA3640(
                     *(_DWORD *)(v177[12] + 4 * *(_DWORD *)(n1000_3 + 4 * *(_DWORD *)v128 + 1028)),
                     *(_DWORD *)(*Size_11 + 4 * n7_1),
                     *(void **)((char *)Size_11 + LODWORD(v127)));
            v3 = v179;
            n1000_3 = n1000;
            *(_DWORD *)((char *)Size_11 + n4_2) = v129;
            v128 = buf + 1;
            v28 = ++v159 < *(_DWORD *)(v3 + 4);
            v127 = v154;
            ++buf;
            ++Size_11;
          }
          while ( v28 );
        }
        n1000_4 = (int *)n1000;
        sub_A94A90(
          n7_1,
          v170 + 2868,
          (int *)v174,
          (int *)n1000,
          v162,
          v171,
          Src,
          *(_DWORD *)(v170 + 4 * (n7_1 + 15 * (v1[7] + 54))),
          *(_DWORD *)(v3 + 4));
        Size_4 = 0;
        if ( *n1000_4 > 0 )
        {
          v131 = n1000_4 + 273;
          n4_2 = (int)(n1000_4 + 273);
          do
          {
            v132 = *v131;
            buf_3 = 0;
            v134 = 0;
            buf = 0;
            v159 = v132;
            if ( *(int *)(v179 + 4) > 0 )
            {
              v135 = (_DWORD *)v171;
              v136 = v165;
              Size_5 = Size_4;
              LODWORD(v154) = (char *)Src - v171;
              v138 = (_DWORD *)(n1000 + 4);
              LODWORD(v155) = &Src_4[-LODWORD(v165)];
              do
              {
                if ( (_DWORD *)*v138 == Size_5 )
                {
                  v139 = v154;
                  *(_DWORD *)LODWORD(v136) = 0;
                  v140 = *(_DWORD *)LODWORD(v136);
                  if ( *(_DWORD *)((char *)v135 + LODWORD(v139)) )
                    v140 = 1;
                  v141 = v155;
                  buf = (float *)((char *)buf + 1);
                  *(_DWORD *)LODWORD(v136) = v140;
                  *(_DWORD *)(LODWORD(v141) + LODWORD(v136)) = *v135;
                  Size_5 = Size_4;
                  LODWORD(v136) += 4;
                }
                ++v134;
                ++v138;
                ++v135;
              }
              while ( v134 < *(_DWORD *)(v179 + 4) );
              v1 = a1;
              buf_3 = buf;
              v132 = v159;
            }
            *(float *)&v142 = COERCE_FLOAT(
                                (*((int (__cdecl **)(_DWORD *, _DWORD, _BYTE *, float, float *))*(&off_B814F0
                                                                                                + *(_DWORD *)(v170 + 4 * v132 + 1312))
                                 + 5))(
                                  v1,
                                  *(_DWORD *)(v177[13] + 4 * v132),
                                  Src_4,
                                  COERCE_FLOAT(LODWORD(v165)),
                                  buf_3));
            Size_6 = Size_4;
            v154 = *(float *)&v142;
            v144 = v179;
            v145 = 0;
            v146 = 0;
            if ( *(int *)(v179 + 4) > 0 )
            {
              Src_6 = (int)Src_4;
              v148 = (_DWORD *)(n1000 + 4);
              do
              {
                if ( (_DWORD *)*v148 == Size_6 )
                {
                  ++v146;
                  *(_DWORD *)(Src_6 + 4 * v146 - 4) = *(_DWORD *)(v171 + 4 * v145);
                  v144 = v179;
                }
                ++v145;
                ++v148;
              }
              while ( v145 < *(_DWORD *)(v144 + 4) );
              v1 = a1;
              v132 = v159;
            }
            (*((void (__cdecl **)(_BYTE *, _DWORD *, _DWORD, _BYTE *, float, int, float, _DWORD *))*(&off_B814F0 + *(_DWORD *)(v170 + 4 * v132 + 1312))
             + 6))(
              Src_2,
              v1,
              *(_DWORD *)(v177[13] + 4 * v132),
              Src_4,
              COERCE_FLOAT(LODWORD(v165)),
              v146,
              COERCE_FLOAT(LODWORD(v154)),
              Size_6);
            v131 = (int *)(n4_2 + 4);
            Size_4 = (_DWORD *)((char *)Size_4 + 1);
            n4_2 += 4;
          }
          while ( (int)Size_4 < *(_DWORD *)n1000 );
          v3 = v179;
        }
        ++n7_1;
        v149 = sub_A9DED0(v1);
      }
      while ( v123 <= (v149 ? 14 : 7) );
    }
    return 0;
  }
  else
  {
    Size_8 = Size_7;
    LODWORD(v154) = v162 - (_DWORD)Src_2;
    Src_2 -= Size_7;
    Size_4 = (_DWORD *)Size_7;
    while ( 1 )
    {
      buf = *(float **)(n1000_1 + 4 * v61 + 4);
      v157 = (float *)&Src_2[Size_8];
      v3 = v179;
      n4_2 = *(_DWORD *)&Src_2[Size_8 + LODWORD(v154)];
      n4_4 = *(_DWORD *)(*v1 + 4 * v61);
      v1[10] = v158;
      if ( v1[18] + 64 > v1[19] )
      {
        if ( v1[17] )
        {
          v63 = malloc_0(8u);
          v1[20] += v1[18];
          v63[1] = v1[21];
          *v63 = v1[17];
          v1[21] = v63;
        }
        v1[19] = 64;
        v64 = malloc_0(0x40u);
        Size_8 = (int)Size_4;
        v1[17] = v64;
        v1[18] = 0;
      }
      v65 = v1[18];
      v66 = (void *)(v65 + v1[17]);
      v1[18] = v65 + 64;
      *(_DWORD *)Size_8 = v66;
      memset(v66, 0, 0x3Cu);
      n4_7 = n4_1;
      n4_8 = 0;
      if ( n4_1 >= 4 )
      {
        v69 = n4_2 + 12;
        v70 = n4_4 + 4 * n4_1;
        LODWORD(v71) = n4_2 - v70;
        v72 = v70 + 4;
        v73 = ((unsigned int)(n4_1 - 4) >> 2) + 1;
        v155 = v71;
        n4_9 = 4 * v73;
        do
        {
          v173 = *(_DWORD *)(v69 - 12);
          v72 += 16;
          v69 += 16;
          v74 = (double)(v173 & 0x7FFFFFFF) + 0.0;
          v75 = (float)((float)(v74 * 0.00000071771143) - 764.61621) + 0.345;
          *(float *)(v72 - 20) = v75;
          v173 = *(_DWORD *)(LODWORD(v71) + v72 - 16);
          v76 = (double)(v173 & 0x7FFFFFFF) + 0.0;
          v77 = (float)((float)(v76 * 0.00000071771143) - 764.61621) + 0.345;
          *(float *)(v72 - 16) = v77;
          v173 = *(_DWORD *)(v69 - 20);
          v78 = (double)(v173 & 0x7FFFFFFF) + 0.0;
          v79 = (float)((float)(v78 * 0.00000071771143) - 764.61621) + 0.345;
          *(float *)(v72 - 12) = v79;
          v173 = *(_DWORD *)(v69 - 16);
          *(float *)(v72 - 8) = (float)((float)((float)((double)(v173 & 0x7FFFFFFF) + 0.0) * 0.00000071771143)
                                      - 764.61621)
                              + 0.345;
          --v73;
        }
        while ( v73 );
        n1000_1 = n1000;
        n4_8 = n4_9;
        n4_7 = n4_1;
      }
      if ( n4_8 < n4_7 )
      {
        v80 = n4_4 + 4 * n4_1;
        v81 = v80 + 4 * n4_8;
        v82 = n4_2 - v80;
        v83 = n4_1 - n4_8;
        do
        {
          v173 = *(_DWORD *)(v81 + v82);
          v81 += 4;
          *(float *)(v81 - 4) = (float)((float)((float)((double)(v173 & 0x7FFFFFFF) + 0.0) * 0.00000071771143)
                                      - 764.61621)
                              + 0.345;
          --v83;
        }
        while ( v83 );
        v3 = v179;
      }
      sub_A95990((int *)v174, n4_4 + 4 * n4_1, (unsigned int)Src_4);
      sub_A95830(n4_4, (int *)v174, SLODWORD(v165), n7_1, *v157);
      sub_A95710(v174, (int)Src_4, (float *)n7_1, 1, n4_4, n4_2, n4_4 + 4 * n4_1);
      if ( *(_DWORD *)(v170 + 4 * *(_DWORD *)(n1000_1 + 4 * (_DWORD)buf + 1028) + 800) != 1 )
        return -1;
      v1 = a1;
      v84 = sub_AA2FA0(n4_4 + 4 * n4_1, n4_4);
      *(_DWORD *)(*Size_4 + 28) = v84;
      if ( sub_A9DED0(a1) && (*Size_9)[7] )
      {
        v86 = 0;
        v87 = *(_DWORD *)(v174 + 4);
        v157 = *(float **)v174;
        v88 = *(float *)(v87 + 20);
        if ( (int)v157 > 0 )
        {
          v89 = v157;
          n4_9 = (int)&Src_4[-n7_1];
          v90 = &Src_4[-n7_1];
          n7_2 = (float *)n7_1;
          LODWORD(v155) = n4_4 - n7_1;
          v92 = n4_4 - n7_1;
          do
          {
            v93 = *(float *)(*(_DWORD *)(*(_DWORD *)(v174 + 12) + 8) + 4 * v86) + *(float *)((char *)n7_2 + (_DWORD)v90);
            v94 = *(_DWORD *)(v174 + 4);
            if ( v93 > *(float *)(v94 + 108) )
              v93 = *(float *)(v94 + 108);
            if ( v93 <= (float)(*n7_2 + v88) )
              v93 = *n7_2 + v88;
            *(float *)((char *)n7_2 + v92) = v93;
            ++v86;
            ++n7_2;
          }
          while ( v86 < (int)v89 );
          v1 = a1;
        }
        v95 = sub_AA2FA0(n4_4 + 4 * n4_1, n4_4);
        v96 = 0;
        *(_DWORD *)(*Size_4 + 56) = v95;
        v97 = *(_DWORD *)(v174 + 4);
        v157 = *(float **)v174;
        v98 = *(float *)(v97 + 12);
        if ( (int)v157 > 0 )
        {
          v99 = v157;
          n4_9 = (int)&Src_4[-n7_1];
          v100 = &Src_4[-n7_1];
          n7_3 = (float *)n7_1;
          LODWORD(v155) = n4_4 - n7_1;
          v102 = n4_4 - n7_1;
          do
          {
            v103 = *(float *)(**(_DWORD **)(v174 + 12) + 4 * v96) + *(float *)&v100[(_DWORD)n7_3];
            v104 = *(_DWORD *)(v174 + 4);
            if ( v103 > *(float *)(v104 + 108) )
              v103 = *(float *)(v104 + 108);
            if ( v103 <= (float)(v98 + *n7_3) )
              v103 = v98 + *n7_3;
            *(float *)((char *)n7_3 + v102) = v103;
            ++v96;
            ++n7_3;
          }
          while ( v96 < (int)v99 );
          v1 = a1;
        }
        v105 = sub_AA2FA0(n4_4 + 4 * n4_1, n4_4);
        Size_9 = (_DWORD **)Size_4;
        v106 = (_DWORD *)*Size_4;
        n4_2 = 4;
        *v106 = v105;
        for ( i = 0x10000; i < 458752; i += 0x10000 )
        {
          v108 = sub_AA3590(**Size_9, (*Size_9)[7], i / 7);
          Size_9 = (_DWORD **)Size_4;
          n4_3 = n4_2;
          v110 = *Size_4;
          n4_2 += 4;
          *(_DWORD *)(n4_3 + v110) = v108;
        }
        n32 = 32;
        for ( j = 0x10000; j < 458752; j += 0x10000 )
        {
          v113 = sub_AA3590((*Size_9)[7], (*Size_9)[14], j / 7);
          Size_9 = (_DWORD **)Size_4;
          *(_DWORD *)(n32 + *Size_4) = v113;
          n32 += 4;
        }
        v3 = v179;
        n1000_1 = n1000;
      }
      v61 = v159 + 1;
      Size_8 = (int)(Size_9 + 1);
      v159 = v61;
      Size_4 = (_DWORD *)Size_8;
      if ( v61 >= *(_DWORD *)(v3 + 4) )
        goto LABEL_83;
    }
  }
}

