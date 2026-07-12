// Function: sub_A127C0
// Address: 0xa127c0
// Size: 0xc39
// Prototype: 

int __thiscall sub_A127C0(int this, int a2, int a3)
{
  int n3; // esi
  float *v5; // esi
  double v6; // st7
  int v7; // ecx
  float v8; // edx
  float *v9; // esi
  int v10; // edi
  float *v11; // eax
  double v12; // st7
  bool v13; // zf
  int v14; // ecx
  int v15; // edi
  float v16; // eax
  float v17; // ecx
  int v18; // edi
  float *v19; // esi
  int v20; // eax
  float *v21; // eax
  float *v22; // eax
  double v23; // st7
  int v24; // ecx
  int v25; // edi
  float v26; // eax
  int v27; // ecx
  int v28; // eax
  _DWORD *v29; // edi
  int n74; // eax
  float *v31; // eax
  float *v32; // eax
  unsigned int n4; // edx
  size_t Size; // ecx
  int v35; // ecx
  int v36; // eax
  _DWORD *v37; // edi
  int n74_1; // eax
  unsigned int n4_1; // edx
  size_t Size_1; // ecx
  int v41; // ecx
  unsigned int n4_2; // edx
  _DWORD *v43; // esi
  size_t Size_2; // ecx
  int v45; // ecx
  unsigned int n4_3; // edx
  _DWORD *v47; // esi
  size_t Size_3; // ecx
  int v49; // ecx
  _DWORD *v50; // esi
  unsigned int n4_5; // edi
  size_t Size_5; // ecx
  int v53; // ecx
  int v54; // edx
  _DWORD *v55; // edi
  int n73; // eax
  unsigned int n4_4; // edx
  size_t Size_4; // ecx
  int v59; // ecx
  int v60; // edx
  int n73_1; // eax
  int *v62; // eax
  int v63; // edx
  unsigned int v64; // edx
  int v65; // eax
  unsigned int v66; // eax
  int v67; // ecx
  _BYTE v69[64]; // [esp+10h] [ebp-1E4h] BYREF
  _BYTE v70[64]; // [esp+50h] [ebp-1A4h] BYREF
  _BYTE dst[64]; // [esp+90h] [ebp-164h] BYREF
  _DWORD v72[5]; // [esp+D0h] [ebp-124h] BYREF
  _DWORD v73[5]; // [esp+E4h] [ebp-110h] BYREF
  _DWORD v74[3]; // [esp+F8h] [ebp-FCh] BYREF
  int v75; // [esp+104h] [ebp-F0h]
  _DWORD Src[3]; // [esp+108h] [ebp-ECh] BYREF
  int v77; // [esp+114h] [ebp-E0h]
  float v78[4]; // [esp+118h] [ebp-DCh] BYREF
  int n72; // [esp+128h] [ebp-CCh] BYREF
  _DWORD v80[4]; // [esp+12Ch] [ebp-C8h] BYREF
  float v81[4]; // [esp+13Ch] [ebp-B8h] BYREF
  int v82; // [esp+14Ch] [ebp-A8h]
  float src[16]; // [esp+150h] [ebp-A4h] BYREF
  float v84; // [esp+190h] [ebp-64h] BYREF
  float v85; // [esp+194h] [ebp-60h]
  float v86; // [esp+198h] [ebp-5Ch]
  float v87; // [esp+19Ch] [ebp-58h]
  int v88; // [esp+1A0h] [ebp-54h] BYREF
  float v89; // [esp+1A4h] [ebp-50h] BYREF
  float v90; // [esp+1A8h] [ebp-4Ch]
  float v91; // [esp+1ACh] [ebp-48h]
  float v92; // [esp+1B0h] [ebp-44h]
  int v93; // [esp+1B4h] [ebp-40h] BYREF
  int v94; // [esp+1B8h] [ebp-3Ch] BYREF
  float *v95; // [esp+1BCh] [ebp-38h] BYREF
  float v96; // [esp+1C0h] [ebp-34h]
  float v97; // [esp+1C4h] [ebp-30h]
  float v98; // [esp+1C8h] [ebp-2Ch]
  float v99; // [esp+1CCh] [ebp-28h]
  float v100; // [esp+1D0h] [ebp-24h]
  float v101; // [esp+1D4h] [ebp-20h] BYREF
  float v102; // [esp+1D8h] [ebp-1Ch]
  float v103; // [esp+1DCh] [ebp-18h]
  float v104; // [esp+1E0h] [ebp-14h]
  int v105; // [esp+1F0h] [ebp-4h]

  v82 = a2;
  sub_451160(a3);
  qmemcpy(dst, src, sizeof(dst));
  v88 = 0;
  v93 = 0;
  sub_584670(&v95);
  v105 = 0;
  n3 = sub_4F85D0(&v95);
  if ( n3 )
    goto LABEL_100;
  v5 = v95;
  v99 = *(float *)(this + 15940);
  if ( v99 > 0.00009999999747378752 || (v99 = *(float *)(this + 15944), v99 > 0.00009999999747378752) )
  {
    v6 = 0.0;
  }
  else
  {
    v99 = *(float *)(this + 15948);
    v6 = 0.0;
    if ( v99 <= 0.00009999999747378752 )
    {
      v7 = 0;
      goto LABEL_6;
    }
  }
  v99 = *(float *)(this + 15908);
  v98 = *(float *)(this + 15912);
  v97 = *(float *)(this + 15916);
  v89 = v99;
  v90 = v98;
  v91 = v97;
  v92 = v6;
  v31 = (float *)sub_4C9D40(v81, &v89);
  v99 = *v31;
  v98 = v31[1];
  v97 = v31[2];
  v101 = v99;
  v102 = v98;
  v103 = v97;
  v32 = (float *)sub_452680(v81, &v101);
  v101 = *v32;
  v102 = v32[1];
  v103 = v32[2];
  v5[8] = v101;
  v5[9] = v102;
  v5[10] = v103;
  *v5 = *(float *)(this + 15940);
  v99 = *(float *)(this + 15944);
  v5[1] = v99;
  v99 = *(float *)(this + 15948);
  v5[2] = v99;
  v99 = *(float *)(this + 15952);
  v5[3] = v99;
  v13 = *(_DWORD *)(this + 15992) == 0;
  v6 = 0.0;
  v101 = 0.0;
  v102 = 0.0;
  v103 = 0.0;
  v104 = 0.0;
  if ( !v13 )
    *(&v101 + *(_DWORD *)(this + 15996)) = 1.0;
  v7 = 1;
  v5[4] = v101;
  v93 = 1;
  v5[5] = v102;
  v5[6] = v103;
  v5[7] = v104;
LABEL_6:
  v8 = 0.0;
  v99 = 0.0;
  if ( *(_DWORD *)(this + 16080) )
  {
    v9 = &v5[12 * v7 + 9];
    v10 = this + 44;
    do
    {
      if ( *(_DWORD *)(v10 + 56) == 1 )
      {
        v98 = *(float *)(v10 - 8);
        v97 = *(float *)(v10 - 4);
        v96 = *(float *)v10;
        v84 = v98;
        v85 = v97;
        v86 = v96;
        v87 = v6;
        v11 = (float *)sub_4C9D40(v81, &v84);
        v96 = *v11;
        v97 = v11[1];
        v98 = v11[2];
        v100 = v96 * v96;
        v100 = v100 + v97 * v97;
        v100 = v98 * v98 + v100;
        v100 = sqrt(v100);
        v100 = 1.0 / v100;
        v12 = v100;
        v100 = v100 * v96;
        v97 = v12 * v97;
        v98 = v12 * v98;
        v89 = v100;
        v90 = v97;
        v91 = v98;
        *(v9 - 1) = v100;
        *v9 = v90;
        v9[1] = v91;
        *(v9 - 9) = *(float *)(v10 + 24);
        *(v9 - 8) = *(float *)(v10 + 28);
        *(v9 - 7) = *(float *)(v10 + 32);
        *(v9 - 6) = *(float *)(v10 + 36);
        v13 = *(_DWORD *)(v10 + 76) == 0;
        v6 = 0.0;
        v101 = 0.0;
        v102 = 0.0;
        v103 = 0.0;
        v104 = 0.0;
        if ( !v13 )
          *(&v101 + *(_DWORD *)(v10 + 80)) = 1.0;
        ++v93;
        v8 = v99;
        *(v9 - 5) = v101;
        v9 += 12;
        *(v9 - 16) = v102;
        *(v9 - 15) = v103;
        *(v9 - 14) = v104;
      }
      ++LODWORD(v8);
      v10 += 124;
      v99 = v8;
    }
    while ( LODWORD(v8) < *(_DWORD *)(this + 16080) );
  }
  v100 = *(float *)(this + 16332);
  v14 = *(_DWORD *)(LODWORD(v100) + 12) & 0x7FFFFFFF;
  if ( !v14 )
    v14 = 1;
  v15 = v14 != *(_DWORD *)(LODWORD(v100) + 4) + 1 ? *(_DWORD *)(LODWORD(v100) + 4) + 1 : 0;
  n3 = sub_59D4B0(v15, &v95);
  if ( !n3 )
  {
    v16 = v100;
    *(_DWORD *)(LODWORD(v100) + 4) = v15;
    *(_BYTE *)(LODWORD(v16) + 8) = 0;
    sub_584670(&v94);
    LOBYTE(v105) = 1;
    n3 = sub_4F85D0(&v94);
    if ( n3 )
      goto LABEL_99;
    v17 = 0.0;
    v96 = 0.0;
    if ( *(_DWORD *)(this + 16080) )
    {
      v18 = this + 60;
      v19 = (float *)(v94 + 24);
      do
      {
        if ( *(_DWORD *)(v18 + 40) != 1 )
        {
          sub_451160(v18 - 40);
          v20 = sub_4CA480(v69, dst, v70);
          sub_573E70(src, v20);
          v21 = (float *)sub_4F9560(v69, src);
          src[0] = *v21;
          src[1] = v21[1];
          src[2] = v21[2];
          src[3] = v21[3];
          src[4] = v21[4];
          src[5] = v21[5];
          src[6] = v21[6];
          src[7] = v21[7];
          src[8] = v21[8];
          src[9] = v21[9];
          src[10] = v21[10];
          src[11] = v21[11];
          src[12] = v21[12];
          src[13] = v21[13];
          src[14] = v21[14];
          src[15] = v21[15];
          *(v19 - 6) = src[0];
          *(v19 - 5) = src[1];
          *(v19 - 4) = src[2];
          *(v19 - 3) = src[3];
          *(v19 - 2) = src[4];
          *(v19 - 1) = src[5];
          *v19 = src[6];
          v19[1] = src[7];
          v19[2] = src[8];
          v19[3] = src[9];
          v19[4] = src[10];
          v19[5] = src[11];
          v19[6] = src[12];
          v19[7] = src[13];
          v19[8] = src[14];
          v19[9] = src[15];
          v100 = *(float *)(v18 - 8);
          v99 = *(float *)(v18 - 4);
          v98 = *(float *)v18;
          v84 = v100;
          v85 = v99;
          v86 = v98;
          v87 = 1.0;
          sub_4C9D40(v81, &v84);
          v100 = *(float *)(v18 - 24);
          v99 = *(float *)(v18 - 20);
          v98 = *(float *)(v18 - 16);
          v78[0] = v100;
          v78[1] = v99;
          v78[2] = v98;
          v78[3] = 0.0;
          v22 = (float *)sub_4C9D40(v80, v78);
          v99 = *v22;
          v98 = v22[1];
          v97 = v22[2];
          v100 = v99 * v99;
          v100 = v100 + v98 * v98;
          v100 = v97 * v97 + v100;
          v100 = sqrt(v100);
          v100 = 1.0 / v100;
          v23 = v100;
          v100 = v100 * v99;
          v99 = v23 * v98;
          v98 = v23 * v97;
          v89 = v100;
          v90 = v99;
          v91 = v98;
          v19[18] = v81[0];
          v19[19] = v81[1];
          v19[20] = v81[2];
          v19[22] = v89;
          v19[23] = v90;
          v19[24] = v91;
          v19[28] = *(float *)(v18 + 44);
          v19[29] = *(float *)(v18 + 48);
          v100 = *(float *)(v18 + 56);
          v100 = tan(v100);
          v19[21] = *(float *)(v18 + 48) * v100;
          v100 = *(float *)(v18 + 52) - 0.0000009999999974752427;
          v100 = cos(v100);
          v19[26] = v100;
          v100 = *(float *)(v18 + 56) - 0.0000009999999974752427;
          v100 = cos(v100);
          v19[27] = v100;
          v100 = *(float *)(v18 + 56);
          v100 = tan(v100);
          v19[30] = v100;
          v19[14] = *(float *)(v18 + 8);
          v19[15] = *(float *)(v18 + 12);
          v19[16] = *(float *)(v18 + 16);
          v19[17] = *(float *)(v18 + 20);
          v13 = *(_DWORD *)(v18 + 60) == 0;
          v101 = 0.0;
          v102 = 0.0;
          v103 = 0.0;
          v104 = 0.0;
          if ( !v13 )
            *(&v101 + *(_DWORD *)(v18 + 64)) = 1.0;
          ++v88;
          v17 = v96;
          v19[10] = v101;
          v19 += 40;
          *(v19 - 29) = v102;
          *(v19 - 28) = v103;
          *(v19 - 27) = v104;
          *(v19 - 9) = *(float *)(v18 + 40);
          *(v19 - 15) = *(float *)(v18 + 76);
        }
        ++LODWORD(v17);
        v18 += 124;
        v96 = v17;
      }
      while ( LODWORD(v17) < *(_DWORD *)(this + 16080) );
    }
    v100 = *(float *)(this + 16328);
    v24 = *(_DWORD *)(LODWORD(v100) + 12) & 0x7FFFFFFF;
    if ( !v24 )
      v24 = 1;
    v25 = v24 != *(_DWORD *)(LODWORD(v100) + 4) + 1 ? *(_DWORD *)(LODWORD(v100) + 4) + 1 : 0;
    n3 = sub_59D4B0(v25, &v94);
    if ( n3 )
      goto LABEL_99;
    v26 = v100;
    *(_DWORD *)(LODWORD(v100) + 4) = v25;
    *(_BYTE *)(LODWORD(v26) + 8) = 0;
    v27 = *(_DWORD *)(this + 0x4000);
    if ( v27 )
    {
      v77 = *(_DWORD *)(this + 16328);
      Src[1] = *(_DWORD *)(v77 + 4);
      v28 = *(_DWORD *)(this + 16088);
      Src[0] = 74;
      v29 = *(_DWORD **)(v28 + 4);
      n74 = *(unsigned __int8 *)(v27 + 2);
      Src[2] = 0;
      if ( n74 != 74 && n74 != 19 && n74 != 144 && n74 != 145 )
        goto LABEL_32;
      n4 = *(unsigned __int16 *)(v27 + 8);
      Size = *(_WORD *)(v27 + 10) & 0x1FFF;
      if ( n4 + Size <= *v29 )
      {
        if ( n4 >= 4 )
        {
          memcpy((char *)v29 + n4, Src, Size);
          n3 = 0;
        }
        else
        {
          n3 = 3;
        }
      }
      else
      {
        n3 = 3;
      }
      if ( n3 )
        goto LABEL_99;
    }
    v35 = *(_DWORD *)(this + 16388);
    if ( v35 )
    {
      v75 = *(_DWORD *)(this + 16332);
      v74[1] = *(_DWORD *)(v75 + 4);
      v36 = *(_DWORD *)(this + 16088);
      v74[0] = 74;
      v37 = *(_DWORD **)(v36 + 4);
      n74_1 = *(unsigned __int8 *)(v35 + 2);
      v74[2] = 0;
      if ( n74_1 != 74 && n74_1 != 19 && n74_1 != 144 && n74_1 != 145 )
        goto LABEL_32;
      n4_1 = *(unsigned __int16 *)(v35 + 8);
      Size_1 = *(_WORD *)(v35 + 10) & 0x1FFF;
      if ( n4_1 + Size_1 <= *v37 )
      {
        if ( n4_1 >= 4 )
        {
          memcpy((char *)v37 + n4_1, v74, Size_1);
          n3 = 0;
        }
        else
        {
          n3 = 3;
        }
      }
      else
      {
        n3 = 3;
      }
      if ( n3 )
        goto LABEL_99;
    }
    v41 = *(_DWORD *)(this + 16392);
    if ( v41 )
    {
      n4_2 = *(unsigned __int16 *)(v41 + 8);
      v43 = *(_DWORD **)(*(_DWORD *)(this + 16088) + 4);
      Size_2 = *(_WORD *)(v41 + 10) & 0x1FFF;
      if ( n4_2 + Size_2 > *v43 || n4_2 < 4 )
        goto LABEL_65;
      memcpy((char *)v43 + n4_2, &v88, Size_2);
    }
    v45 = *(_DWORD *)(this + 16396);
    if ( v45 )
    {
      n4_3 = *(unsigned __int16 *)(v45 + 8);
      v47 = *(_DWORD **)(*(_DWORD *)(this + 16088) + 4);
      Size_3 = *(_WORD *)(v45 + 10) & 0x1FFF;
      if ( n4_3 + Size_3 > *v47 || n4_3 < 4 )
        goto LABEL_65;
      memcpy((char *)v47 + n4_3, &v93, Size_3);
    }
    v49 = *(_DWORD *)(this + 16380);
    if ( !v49 )
    {
LABEL_69:
      v53 = *(_DWORD *)(this + 16404);
      if ( v53 )
      {
        v54 = *(_DWORD *)(this + 16336);
        v55 = *(_DWORD **)(*(_DWORD *)(this + 16088) + 4);
        n73 = *(unsigned __int8 *)(v53 + 2);
        v72[0] = 73;
        v72[2] = 0;
        v72[4] = 0;
        v72[3] = v54;
        v72[1] = 0;
        if ( n73 != 73 && n73 != 20 && n73 != 21 || v54 && (*(_BYTE *)(v54 + 8) & 8) == 0 )
          goto LABEL_32;
        n4_4 = *(unsigned __int16 *)(v53 + 8);
        Size_4 = *(_WORD *)(v53 + 10) & 0x1FFF;
        if ( n4_4 + Size_4 <= *v55 )
        {
          if ( n4_4 >= 4 )
          {
            memcpy((char *)v55 + n4_4, v72, Size_4);
            n3 = 0;
          }
          else
          {
            n3 = 3;
          }
        }
        else
        {
          n3 = 3;
        }
        if ( n3 )
          goto LABEL_99;
      }
      v59 = *(_DWORD *)(this + 16424);
      if ( v59 )
      {
        v60 = *(_DWORD *)(this + 16340);
        n73_1 = *(unsigned __int8 *)(v59 + 2);
        v73[0] = 73;
        v73[2] = 0;
        v73[4] = 0;
        v73[3] = v60;
        v73[1] = 0;
        if ( n73_1 != 73 && n73_1 != 20 && n73_1 != 21 || v60 && (*(_BYTE *)(v60 + 8) & 8) == 0 )
          goto LABEL_32;
        n3 = sub_4D5910(v59, v73);
        if ( n3 )
          goto LABEL_99;
      }
      v62 = *(int **)(this + 16324);
      if ( *((_BYTE *)v62 + 4) )
        v63 = 0;
      else
        v63 = *v62;
      v64 = *(_DWORD *)(v63 + 28);
      if ( *((_BYTE *)v62 + 4) )
        v65 = 0;
      else
        v65 = *v62;
      v66 = *(_DWORD *)(v65 + 32);
      *(_DWORD *)(v82 + 72) = &unk_1944C1C;
      n3 = sub_5B67C0(
             **(_DWORD **)(this + 16088),
             *(void **)(*(_DWORD *)(this + 16088) + 4),
             (v64 >> 3) + ((v64 & 7) != 0),
             (v66 >> 3) + ((v66 & 7) != 0),
             1);
      if ( n3 )
        goto LABEL_99;
      v67 = *(_DWORD *)(this + 16400);
      if ( !v67 )
      {
LABEL_98:
        n3 = 0;
        goto LABEL_99;
      }
      v13 = *(_BYTE *)(v67 + 2) == 72;
      v80[1] = 0;
      v80[3] = 0;
      v80[2] = *(_DWORD *)(this + 16336);
      n72 = 72;
      v80[0] = 0;
      if ( v13 )
      {
        n3 = sub_4D5910(v67, &n72);
        if ( n3 )
          goto LABEL_99;
        goto LABEL_98;
      }
LABEL_32:
      n3 = 5;
LABEL_99:
      LOBYTE(v105) = 0;
      nullsub_23(&v94);
      goto LABEL_100;
    }
    v50 = *(_DWORD **)(*(_DWORD *)(this + 16088) + 4);
    if ( this == -16016 )
    {
      n3 = 1;
      goto LABEL_99;
    }
    n4_5 = *(unsigned __int16 *)(v49 + 8);
    Size_5 = *(_WORD *)(v49 + 10) & 0x1FFF;
    if ( Size_5 + n4_5 <= *v50 && n4_5 >= 4 )
    {
      memcpy((char *)v50 + n4_5, (const void *)(this + 16016), Size_5);
      goto LABEL_69;
    }
LABEL_65:
    n3 = 3;
    goto LABEL_99;
  }
LABEL_100:
  v105 = -1;
  nullsub_23(&v95);
  return n3;
}

