// Function: sub_A94A90
// Address: 0xa94a90
// Size: 0x86f
// Prototype: int __cdecl(int, int, int, int, void *Src, int, int)

int *__fastcall sub_A94A90(int a1, int a2, int *a3, int *n1000_8, int a5, int a6, void *Src, int a8, int a9)
{
  _DWORD *v9; // eax
  bool v10; // zf
  int v11; // esi
  float v12; // xmm0_4
  void *v13; // esp
  void *v14; // esp
  void *v15; // esp
  void *v16; // esp
  void *v17; // esp
  void *v18; // esp
  int size; // esi
  void *v20; // esp
  void *v21; // esp
  void *v22; // esp
  void *v23; // esp
  void **v24; // esi
  int v25; // edx
  char *v26; // edi
  _DWORD *v27; // edx
  int v28; // ecx
  int v29; // esi
  _DWORD *v30; // edi
  int n1000_9; // esi
  int i; // ecx
  int *n1000_1; // eax
  int n1000_7; // edi
  int n16_1; // edx
  int n1000_2; // ecx
  int n16_2; // eax
  char *v38; // esi
  char *v39; // esi
  char *v40; // ecx
  int v41; // edx
  int v42; // edi
  char *v43; // eax
  int Size_6; // edi
  signed int n16_5; // ecx
  signed int n16_4; // edx
  int v47; // eax
  int v48; // edx
  _DWORD *v49; // esi
  unsigned int v50; // edi
  int v51; // ecx
  int v52; // edi
  int v53; // edx
  int v54; // ecx
  int v55; // eax
  int v56; // edi
  int n16_6; // eax
  float *v58; // eax
  int v59; // ecx
  int v60; // edx
  _DWORD *v61; // esi
  float *v62; // ecx
  int n16_7; // edi
  int v64; // edx
  float v65; // xmm0_4
  float v66; // xmm0_4
  int n1000_10; // edi
  unsigned __int32 v68; // xmm0_4
  char *v69; // edi
  int v70; // ecx
  float *v71; // esi
  int v72; // edi
  int v73; // eax
  _DWORD *v74; // edi
  int v75; // eax
  int v76; // edx
  _DWORD *n1000_5; // ecx
  int v78; // edi
  float v79; // xmm0_4
  int v80; // edi
  bool v81; // cc
  float v82; // xmm0_4
  int v83; // edx
  float v84; // xmm1_4
  int v85; // eax
  float v86; // xmm0_4
  int v87; // edi
  int v88; // eax
  int v89; // edi
  int v90; // ecx
  int v91; // edi
  signed int v92; // ecx
  size_t Size_4; // edx
  float v94; // xmm0_4
  char *v95; // esi
  int v96; // edx
  _DWORD *v97; // ecx
  int v98; // esi
  size_t Size_1; // [esp+Ch] [ebp-98h]
  _DWORD v100[2]; // [esp+10h] [ebp-94h] BYREF
  int v101; // [esp+18h] [ebp-8Ch]
  float v102; // [esp+1Ch] [ebp-88h]
  int v103; // [esp+20h] [ebp-84h]
  int n1000_6; // [esp+24h] [ebp-80h]
  size_t Size_2; // [esp+28h] [ebp-7Ch]
  float v106; // [esp+2Ch] [ebp-78h]
  int Size_5; // [esp+30h] [ebp-74h]
  char *v108; // [esp+34h] [ebp-70h]
  size_t Size; // [esp+38h] [ebp-6Ch]
  int n1000; // [esp+3Ch] [ebp-68h]
  int v111; // [esp+40h] [ebp-64h]
  int n1000_3; // [esp+44h] [ebp-60h]
  void *v113; // [esp+48h] [ebp-5Ch]
  char *v114; // [esp+4Ch] [ebp-58h]
  int n16; // [esp+50h] [ebp-54h]
  size_t Size_3; // [esp+54h] [ebp-50h]
  char *v117; // [esp+58h] [ebp-4Ch]
  void **v118; // [esp+5Ch] [ebp-48h]
  int v119; // [esp+60h] [ebp-44h]
  char *v120; // [esp+64h] [ebp-40h]
  int v121; // [esp+68h] [ebp-3Ch]
  int n1000_11; // [esp+6Ch] [ebp-38h]
  int v123; // [esp+70h] [ebp-34h]
  int v124; // [esp+74h] [ebp-30h]
  _DWORD *v125; // [esp+78h] [ebp-2Ch]
  int n1000_4; // [esp+7Ch] [ebp-28h]
  int v127; // [esp+80h] [ebp-24h]
  char *v128; // [esp+84h] [ebp-20h]
  int v129; // [esp+88h] [ebp-1Ch]
  char *v130; // [esp+8Ch] [ebp-18h]
  int n16_8; // [esp+90h] [ebp-14h]
  char *v132; // [esp+94h] [ebp-10h]
  int v133; // [esp+98h] [ebp-Ch]
  int v134; // [esp+9Ch] [ebp-8h]
  int n16_3; // [esp+A0h] [ebp-4h]
  int v136; // [esp+C0h] [ebp+1Ch]

  v9 = (_DWORD *)a3[1];
  v10 = v9[125] == 0;
  n1000 = *a3;
  if ( v10 )
    n16 = 16;
  else
    n16 = v9[127];
  v111 = *(_DWORD *)(a2 + 4 * (a1 + 15 * *v9) + 132);
  v11 = *(_DWORD *)(a2 + 4 * a1 + 312);
  v12 = qword_B86FA8[*(_DWORD *)(a2 + 4 * a1 + 252)];
  v102 = v12;
  v106 = qword_B86FA8[v11];
  Size = 4 * a9;
  v13 = alloca(4 * a9);
  v120 = (char *)v100;
  v14 = alloca(4 * a9);
  v130 = (char *)v100;
  v15 = alloca(4 * a9);
  v128 = (char *)v100;
  v16 = alloca(4 * a9);
  v118 = (void **)v100;
  v17 = alloca(4 * a9);
  v113 = v100;
  v18 = alloca(4 * (a9 + n1000_8[289]));
  v108 = (char *)v100;
  if ( n1000 > 1000 )
    v106 = qword_B86FF0[v11];
  size = 4 * a9 * n16;
  Size_2 = size;
  v20 = alloca(size);
  *(_DWORD *)v120 = v100;
  v21 = alloca(size);
  *(_DWORD *)v130 = v100;
  v22 = alloca(size);
  v100[0] = v100;
  v23 = alloca(size);
  v24 = v118;
  v25 = a9;
  *v118 = v100;
  if ( a9 > 1 )
  {
    v26 = (char *)(v120 - v130);
    v27 = v130 + 4;
    v117 = (char *)((char *)v24 - v130);
    v28 = 4 * n16;
    v114 = (char *)(v120 - v130);
    v125 = (_DWORD *)(v128 - v130);
    v29 = a9 - 1;
    do
    {
      *(_DWORD *)((char *)++v27 + (_DWORD)v26 - 4) = v28 + *(_DWORD *)v120;
      v30 = v125;
      *(v27 - 1) = v28 + *(_DWORD *)v130;
      *(_DWORD *)((char *)v27 + (_DWORD)v30 - 4) = v28 + *(_DWORD *)v128;
      *(_DWORD *)((char *)v27 + (_DWORD)v117 - 4) = (char *)*v118 + v28;
      v26 = v114;
      v28 += 4 * n16;
      --v29;
    }
    while ( v29 );
    v25 = a9;
  }
  n1000_9 = (int)n1000_8;
  for ( i = 0; i < v25 + n1000_8[289]; *(_DWORD *)&v108[4 * i - 4] = 0 )
    ++i;
  n1000_1 = (int *)n1000;
  n1000_7 = 0;
  n1000_11 = 0;
  if ( n1000 > 0 )
  {
    n16_1 = n16;
    v136 = a8 - n1000;
    v101 = -n16;
    n1000_2 = n1000;
    n1000_3 = n1000;
    v103 = v111 - n1000;
    do
    {
      Size_1 = Size;
      n16_2 = n16_1;
      if ( n16_1 > n1000_2 )
        n16_2 = n1000_2;
      n16_3 = n16_2;
      v38 = 0;
      memcpy(v113, Src, Size_1);
      n1000_1 = (int *)memset(*v118, 0, Size_2);
      if ( a9 > 0 )
      {
        v39 = v128;
        v40 = (char *)v113 - a5;
        v123 = a5 - (_DWORD)v128;
        v133 = a6 - (_DWORD)v113;
        v129 = v130 - v128;
        v119 = (char *)v118 - v128;
        v41 = v120 - v128;
        v42 = a6 - (_DWORD)v113;
        n1000_4 = v108 - v128;
        v132 = v128;
        v117 = (char *)v113 - a5;
        v127 = v120 - v128;
        v124 = a9;
        v114 = (char *)a9;
        do
        {
          v43 = &v39[v123 + (_DWORD)v40];
          Size_6 = 4 * n1000_11 + *(_DWORD *)&v43[v42];
          n16_5 = 0;
          Size_3 = Size_6;
          if ( *(_DWORD *)v43 )
          {
            n16_4 = n16_3;
            n16_8 = 0;
            if ( n16_3 >= 4 )
            {
              v47 = *(_DWORD *)v39;
              v48 = Size_6 + 12;
              v125 = (_DWORD *)(Size_6 - *(_DWORD *)v39);
              v49 = v125;
              v50 = ((unsigned int)(n16_3 - 4) >> 2) + 1;
              v51 = v47 + 4;
              n16_8 = 4 * v50;
              do
              {
                v51 += 16;
                *(_DWORD *)(v51 - 20) = dword_C8AE20[*(_DWORD *)(v48 - 12)];
                v48 += 16;
                *(_DWORD *)(v51 - 16) = dword_C8AE20[*(_DWORD *)((char *)v49 + v51 - 16)];
                *(_DWORD *)(v51 - 12) = dword_C8AE20[*(_DWORD *)(v48 - 20)];
                *(_DWORD *)(v51 - 8) = dword_C8AE20[*(_DWORD *)(v48 - 16)];
                --v50;
              }
              while ( v50 );
              v39 = v132;
              n16_5 = n16_8;
              Size_6 = Size_3;
              n16_4 = n16_3;
            }
            if ( n16_5 < n16_4 )
            {
              v52 = Size_6 - *(_DWORD *)v39;
              v53 = n16_4 - n16_8;
              v54 = *(_DWORD *)v39 + 4 * n16_5;
              do
              {
                v55 = *(_DWORD *)(v54 + v52);
                v54 += 4;
                *(_DWORD *)(v54 - 4) = dword_C8AE20[v55];
                --v53;
              }
              while ( v53 );
              n16_4 = n16_3;
            }
            Size_1 = n16_4;
            v56 = 4 * n1000_11;
            sub_A95650(*(_DWORD *)v39, *(_DWORD *)&v39[v119], n1000_11, n16_4);
            n16_6 = n16_3;
            if ( n16_3 > 0 )
            {
              v58 = *(float **)&v39[v127];
              v59 = *(_DWORD *)&v39[v123];
              v125 = (_DWORD *)(*(_DWORD *)&v39[v129] - (_DWORD)v58);
              v60 = *(_DWORD *)v39;
              v61 = v125;
              v62 = (float *)(v56 + v59);
              n16_7 = n16_3;
              v64 = v60 - (_DWORD)v58;
              do
              {
                v65 = *v62 * *v62;
                *v58 = v65;
                *(float *)((char *)v61 + (_DWORD)v58) = v65;
                if ( *v62 < 0.0 )
                  *v58 = *v58 * -1.0;
                v66 = *(float *)((char *)v58 + v64) * *(float *)((char *)v58 + v64);
                ++v62;
                *(float *)((char *)++v58 + v64 - 4) = v66;
                --n16_7;
              }
              while ( n16_7 );
              v39 = v132;
              n16_6 = n16_3;
            }
            Size_1 = Size_3;
            n1000_10 = n1000_4;
            v68 = sub_A95300(
                    *(_DWORD *)&v39[v127],
                    *(_DWORD *)&v39[v129],
                    *(_DWORD *)v39,
                    0,
                    *(_DWORD *)&v39[n1000_4],
                    n1000_11,
                    n16_6,
                    Size_3).m128_u32[0];
            v41 = v127;
            *(_DWORD *)&v39[n1000_10] = v68;
          }
          else
          {
            if ( n16_3 > 0 )
            {
              do
              {
                ++n16_5;
                *(_DWORD *)(*(_DWORD *)v39 + 4 * n16_5 - 4) = 786163455;
                *(_DWORD *)(*(_DWORD *)&v39[v41] + 4 * n16_5 - 4) = 0;
                *(_DWORD *)(*(_DWORD *)&v39[v129] + 4 * n16_5 - 4) = 0;
                *(_DWORD *)(*(_DWORD *)&v39[v119] + 4 * n16_5 - 4) = 0;
                *(_DWORD *)(Size_6 + 4 * n16_5 - 4) = 0;
              }
              while ( n16_5 < n16_3 );
            }
            n1000_1 = (int *)n1000_4;
            *(_DWORD *)&v39[n1000_4] = 0;
          }
          v42 = v133;
          v40 = v117;
          v39 += 4;
          v10 = v124-- == 1;
          v132 = v39;
        }
        while ( !v10 );
        v38 = v114;
        n1000_7 = n1000_11;
      }
      v117 = 0;
      if ( n1000_8[289] <= 0 )
      {
        n1000_9 = (int)n1000_8;
      }
      else
      {
        v114 = &v108[4 * (_DWORD)v38];
        n1000_1 = n1000_8 + 546;
        v125 = n1000_8 + 546;
        do
        {
          v69 = (char *)*(n1000_1 - 256);
          v70 = *n1000_1;
          Size_5 = 4 * n1000_11 + *(_DWORD *)(a6 + 4 * (_DWORD)v69);
          v134 = 4 * n1000_11 + *(_DWORD *)(a6 + 4 * v70);
          v71 = *(float **)&v120[4 * (_DWORD)v69];
          v132 = v69;
          v72 = *(_DWORD *)&v130[4 * (_DWORD)v69];
          v73 = *(_DWORD *)&v120[4 * v70];
          v129 = *(_DWORD *)&v130[4 * v70];
          v121 = v72;
          Size_3 = *(_DWORD *)&v128[4 * (_DWORD)v132];
          n16_8 = *(_DWORD *)&v128[4 * v70];
          v127 = (int)v118[(_DWORD)v132];
          v74 = v113;
          v124 = (int)v118[v70];
          if ( *((_DWORD *)v113 + (_DWORD)v132) || *((_DWORD *)v113 + v70) )
          {
            *((_DWORD *)v113 + v70) = 1;
            v74[(_DWORD)v132] = 1;
            n1000_4 = 0;
            if ( n16_3 > 0 )
            {
              v129 -= (int)v71;
              v121 -= (int)v71;
              v124 -= (int)v71;
              v127 -= (int)v71;
              n16_8 -= (int)v71;
              v75 = v73 - (_DWORD)v71;
              v76 = v134 - (_DWORD)v71;
              Size_3 -= (unsigned int)v71;
              n1000_6 = v136 + n1000_3;
              n1000_5 = (_DWORD *)n1000_4;
              v123 = v75;
              v134 -= (int)v71;
              v133 = Size_5 - (_DWORD)v71;
              do
              {
                if ( (int)n1000_5 < n1000_6 )
                {
                  v78 = v133;
                  if ( *(_DWORD *)((char *)v71 + v127) || (v76 = v134, *(_DWORD *)((char *)v71 + v124)) )
                  {
                    v84 = *(float *)((char *)v71 + v75);
                    v85 = v129;
                    v86 = fabs(v84) + fabs(*v71);
                    *v71 = v86;
                    *(float *)((char *)v71 + v121) = *(float *)((char *)v71 + v85) + *(float *)((char *)v71 + v121);
                    *(_DWORD *)((char *)v71 + v124) = 1;
                    *(_DWORD *)((char *)v71 + v127) = 1;
                    v87 = *(_DWORD *)((char *)v71 + v78);
                    v119 = *(_DWORD *)((char *)v71 + v76);
                    if ( (int)abs32(v87) <= (int)abs32(v119) )
                    {
                      v90 = v119;
                      if ( v119 <= 0 )
                        v91 = v119 - v87;
                      else
                        v91 = v87 - v119;
                      v88 = v134;
                      *(_DWORD *)((char *)v71 + v134) = v91;
                      v89 = v133;
                      *(_DWORD *)((char *)v71 + v133) = v90;
                    }
                    else
                    {
                      v88 = v134;
                      if ( v87 <= 0 )
                        *(_DWORD *)((char *)v71 + v134) = v119 - v87;
                      else
                        *(_DWORD *)((char *)v71 + v134) = v87 - v119;
                      v89 = v133;
                    }
                    v92 = *(_DWORD *)((char *)v71 + v88);
                    if ( v92 >= (int)(2 * abs32(*(_DWORD *)((char *)v71 + v89))) )
                    {
                      *(_DWORD *)((char *)v71 + v134) = -v92;
                      *(_DWORD *)((char *)v71 + v89) = -*(_DWORD *)((char *)v71 + v89);
                    }
                    v75 = v123;
                    n1000_5 = (_DWORD *)n1000_4;
                  }
                  else
                  {
                    v75 = v123;
                    if ( (int)n1000_5 >= v103 + n1000_3 )
                    {
                      v81 = (float)(*(float *)((char *)v71 + v123) + *v71) >= 0.0;
                      v82 = fabs(*(float *)((char *)v71 + v123)) + fabs(*v71);
                      *(float *)((char *)v71 + v121) = v82;
                      if ( v81 )
                        n1000_5 = (_DWORD *)n1000_4;
                      else
                        v82 = -v82;
                      *v71 = v82;
                    }
                    else
                    {
                      v79 = *v71 + *(float *)((char *)v71 + v123);
                      v80 = v121;
                      *v71 = v79;
                      *(float *)((char *)v71 + v80) = fabs(v79);
                    }
                    *(float *)((char *)v71 + v129) = 0.0;
                    v83 = v124;
                    *(float *)((char *)v71 + v75) = 0.0;
                    *(_DWORD *)((char *)v71 + v83) = 1;
                    *(float *)((char *)v71 + v134) = 0.0;
                  }
                }
                Size_4 = Size_3;
                n1000_5 = (_DWORD *)((char *)n1000_5 + 1);
                v94 = *(float *)((char *)v71 + n16_8) + *(float *)((char *)v71 + Size_3);
                ++v71;
                n1000_4 = (int)n1000_5;
                *(float *)((char *)v71 + n16_8 - 4) = v94;
                *(float *)((char *)v71 + Size_4 - 4) = v94;
                v76 = v134;
              }
              while ( (int)n1000_5 < n16_3 );
            }
            Size_1 = Size_5;
            v95 = v114;
            *(_DWORD *)v95 = sub_A95300(
                               *(_DWORD *)&v120[4 * (_DWORD)v132],
                               *(_DWORD *)&v130[4 * (_DWORD)v132],
                               *(_DWORD *)&v128[4 * (_DWORD)v132],
                               v118[(_DWORD)v132],
                               *(_DWORD *)v114,
                               n1000_11,
                               n16_3,
                               Size_5).m128_u32[0];
            v114 = v95 + 4;
          }
          n1000_9 = (int)n1000_8;
          n1000_1 = v125 + 1;
          ++v117;
          ++v125;
        }
        while ( (int)v117 < n1000_8[289] );
        n1000_7 = n1000_11;
      }
      n16_1 = n16;
      n1000_2 = v101 + n1000_3;
      n1000_7 += n16;
      n1000_11 = n1000_7;
      n1000_3 += v101;
    }
    while ( n1000_7 < n1000 );
  }
  v96 = 0;
  if ( *(int *)(n1000_9 + 1156) > 0 )
  {
    v97 = (_DWORD *)(n1000_9 + 2184);
    do
    {
      v98 = *(v97 - 256);
      if ( *((_DWORD *)Src + v98) || *((_DWORD *)Src + *v97) )
      {
        *((_DWORD *)Src + v98) = 1;
        *((_DWORD *)Src + *v97) = 1;
      }
      n1000_1 = n1000_8;
      ++v96;
      ++v97;
    }
    while ( v96 < n1000_8[289] );
  }
  return n1000_1;
}

