// Function: sub_98A060
// Address: 0x98a060
int __usercall sub_98A060@<eax>(int a1@<ebp>, int a2, int a3, int a4)
{
  int v4; // eax
  float v5; // edx
  int i_1; // edi
  int v7; // ecx
  double v8; // st7
  float **v9; // edx
  double v10; // st6
  float v11; // esi
  double v12; // st5
  double v13; // st4
  double v14; // st3
  double v15; // st2
  float *v16; // eax
  double v17; // rt2
  double v18; // st2
  double v19; // st7
  double v20; // rtt
  double v21; // st3
  double v22; // st6
  double v23; // st2
  double v24; // st5
  int i; // esi
  int v26; // eax
  int v27; // ecx
  int v28; // eax
  int v29; // eax
  int v30; // esi
  int v31; // edx
  _DWORD *v32; // ecx
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // esi
  int v37; // edx
  _DWORD *v38; // ecx
  int v39; // eax
  float v40; // kr00_4
  int v41; // edi
  float v42; // eax
  int v43; // esi
  int v44; // edx
  float v45; // ecx
  int v46; // esi
  float v47; // eax
  int v48; // edi
  int v49; // edx
  float v50; // ecx
  int v51; // eax
  float v52; // edx
  int v53; // ecx
  float v54; // edi
  int v55; // esi
  int v56; // eax
  int v57; // ecx
  int v58; // eax
  float v59; // eax
  int v60; // edi
  int v61; // edx
  float v62; // ecx
  int v63; // eax
  _DWORD *v64; // ecx
  float v65; // eax
  int v66; // edi
  int v67; // eax
  float v68; // esi
  float v70; // [esp-E0h] [ebp-ECh]
  float v71; // [esp-D0h] [ebp-DCh]
  float v72; // [esp-C0h] [ebp-CCh]
  float dst[9]; // [esp-B0h] [ebp-BCh] BYREF
  int v74; // [esp-8Ch] [ebp-98h]
  int v75; // [esp-88h] [ebp-94h]
  int v76; // [esp-84h] [ebp-90h]
  float v77; // [esp-80h] [ebp-8Ch] BYREF
  float v78; // [esp-7Ch] [ebp-88h]
  int v79; // [esp-78h] [ebp-84h]
  int v80; // [esp-74h] [ebp-80h]
  int v81; // [esp-68h] [ebp-74h]
  int v82; // [esp-64h] [ebp-70h] BYREF
  int v83; // [esp-60h] [ebp-6Ch]
  int v84; // [esp-5Ch] [ebp-68h]
  float v85; // [esp-58h] [ebp-64h]
  char v86; // [esp-54h] [ebp-60h]
  int v87; // [esp-50h] [ebp-5Ch] BYREF
  int v88; // [esp-4Ch] [ebp-58h]
  int v89; // [esp-48h] [ebp-54h]
  float v90; // [esp-44h] [ebp-50h]
  char v91; // [esp-40h] [ebp-4Ch]
  int v92; // [esp-3Ch] [ebp-48h]
  float v93; // [esp-38h] [ebp-44h]
  float v94; // [esp-34h] [ebp-40h]
  float v95; // [esp-30h] [ebp-3Ch]
  int v96; // [esp-2Ch] [ebp-38h]
  int v97; // [esp-28h] [ebp-34h]
  _DWORD v98[2]; // [esp-24h] [ebp-30h]
  _DWORD v99[6]; // [esp-1Ch] [ebp-28h]
  int v100; // [esp-4h] [ebp-10h]
  _DWORD v101[2]; // [esp+0h] [ebp-Ch] BYREF
  int v102; // [esp+8h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v101[0] = a1;
  v101[1] = retaddr;
  v100 = -1;
  v99[5] = &loc_AD8E63;
  v99[4] = NtCurrentTeb()->NtTib.ExceptionList;
  v99[3] = &v102;
  v76 = a2;
  v81 = a3;
  v75 = a4;
  if ( (dword_193F240 & 1) == 0 )
  {
    dword_193F240 |= 1u;
    n1065353216_7 = 1065353216;
    flt_193F214 = 0.0;
    flt_193F218 = 0.0;
    unk_193F21C = 0;
    flt_193F220 = 0.0;
    flt_193F224 = 1.0;
    flt_193F228 = 0.0;
    unk_193F22C = 0;
    flt_193F230 = 0.0;
    flt_193F234 = 0.0;
    flt_193F238 = 1.0;
    unk_193F23C = 0;
  }
  v4 = *(_DWORD *)(a3 + 4);
  if ( v4 <= 1 )
    return **(_DWORD **)(a3 + 12);
  if ( v4 <= a4 )
  {
    sub_987F10(a2, a3);
    return **(_DWORD **)(a3 + 12);
  }
  sub_9880E0((int)v101, dst, a3);
  v94 = dst[6] + dst[2];
  v80 = 0;
  v93 = dst[5] + dst[1];
  v77 = dst[4] + dst[0];
  *(float *)&v92 = v94 * 0.5;
  v94 = v93 * 0.5;
  v77 = 0.5 * v77;
  v78 = v94;
  v79 = v92;
  `eh vector constructor iterator'(
    &v82,
    0x14u,
    2,
    (void (__thiscall *)(void *))sub_9876F0,
    (void (__thiscall *)(void *))sub_987800);
  v5 = *(float *)(a3 + 4);
  i_1 = -1;
  v7 = 0;
  v100 = 0;
  v93 = v5;
  *(float *)&v92 = v5;
  v96 = 0;
  v97 = 0;
  v98[0] = 0;
  v98[1] = 0;
  v99[0] = 0;
  v99[1] = 0;
  if ( SLODWORD(v5) > 0 )
  {
    v8 = *(float *)&v79;
    v9 = *(float ***)(a3 + 12);
    v10 = v78;
    v11 = v93;
    v12 = v77;
    v13 = flt_193F238;
    v14 = flt_193F214;
    v15 = 0.0;
    while ( 1 )
    {
      v16 = *v9;
      v94 = (*v9)[6] + (*v9)[2];
      v95 = v16[5] + v16[1];
      v72 = v16[4] + *v16;
      v94 = v94 * 0.5;
      v95 = v95 * 0.5;
      v70 = 0.5 * v72;
      v17 = v15;
      v18 = v94 - v8;
      v19 = v17;
      v94 = v18;
      v20 = v14;
      v95 = v95 - v10;
      v71 = v70 - v12;
      v21 = v95;
      v22 = v94;
      v95 = v20 * v95 + v71 * n1065353216_7 + v94 * flt_193F218;
      ++*(&v96 + (v95 > v17));
      v95 = v71 * flt_193F220 + v21 * flt_193F224 + v22 * flt_193F228;
      v23 = flt_193F230;
      ++v98[v95 > v17];
      v95 = v22 * v13 + v71 * v23 + v21 * flt_193F234;
      v24 = *(float *)&v79;
      ++v99[v95 > v17];
      ++v7;
      ++v9;
      if ( v7 >= SLODWORD(v11) )
        break;
      v15 = v19;
      v8 = v24;
      v10 = v78;
      v12 = v77;
      v14 = flt_193F214;
    }
  }
  for ( i = 0; i < 3; ++i )
  {
    v26 = *(&v96 + 2 * i);
    if ( v26 > 0 )
    {
      v27 = v98[2 * i - 1];
      if ( v27 > 0 )
      {
        v95 = (float)(v26 - v27);
        v95 = fabs(v95);
        if ( (int)v95 < v92 )
        {
          i_1 = i;
          v92 = (int)v95;
        }
      }
    }
  }
  if ( i_1 < 0 )
  {
    v40 = v93;
    v41 = SLODWORD(v93) / 2 + 1;
    if ( v84 < v41 )
    {
      if ( SLODWORD(v93) / 2 == -1 )
        v42 = 0.0;
      else
        v42 = COERCE_FLOAT(sub_9D4CE0(4 * v41, 16));
      v43 = v83;
      v44 = 0;
      v93 = v42;
      if ( v83 > 0 )
      {
        v45 = v42;
        do
        {
          if ( v45 != 0.0 )
            *(_DWORD *)LODWORD(v45) = *(_DWORD *)(LODWORD(v85) + 4 * v44);
          ++v44;
          LODWORD(v45) += 4;
        }
        while ( v44 < v43 );
      }
      if ( v85 != 0.0 && v86 )
        sub_9D4D50(LODWORD(v85));
      v86 = 1;
      v85 = v93;
      v84 = SLODWORD(v40) / 2 + 1;
    }
    v46 = *(_DWORD *)(v81 + 4) / 2;
    if ( v89 < v46 )
    {
      if ( v46 )
        v47 = COERCE_FLOAT(sub_9D4CE0(4 * v46, 16));
      else
        v47 = 0.0;
      v48 = v88;
      v49 = 0;
      v93 = v47;
      if ( v88 > 0 )
      {
        v50 = v47;
        do
        {
          if ( v50 != 0.0 )
            *(_DWORD *)LODWORD(v50) = *(_DWORD *)(LODWORD(v90) + 4 * v49);
          ++v49;
          LODWORD(v50) += 4;
        }
        while ( v49 < v48 );
      }
      if ( v90 != 0.0 && v91 )
        sub_9D4D50(LODWORD(v90));
      v91 = 1;
      v90 = v93;
      v89 = v46;
    }
    v51 = v81;
    v52 = 0.0;
    v53 = *(_DWORD *)(v81 + 4);
    v94 = 0.0;
    v74 = v53;
    if ( v53 > 0 )
    {
      do
      {
        v54 = *(float *)(v51 + 12);
        v95 = v54;
        v55 = 5 * (LOBYTE(v52) & 1);
        v56 = *(&v83 + 5 * (LOBYTE(v52) & 1));
        v57 = *(&v84 + 5 * (LOBYTE(v52) & 1));
        if ( v56 == v57 )
        {
          v58 = v56 ? 2 * v56 : 1;
          v92 = v58;
          if ( v57 < v58 )
          {
            if ( *(float *)&v58 == 0.0 )
              v59 = 0.0;
            else
              v59 = COERCE_FLOAT(sub_9D4CE0(4 * v58, 16));
            v60 = *(&v83 + v55);
            v61 = 0;
            v93 = v59;
            if ( v60 > 0 )
            {
              v62 = v59;
              do
              {
                if ( v62 != 0.0 )
                  *(_DWORD *)LODWORD(v62) = *(_DWORD *)(*((_DWORD *)&v85 + v55) + 4 * v61);
                ++v61;
                LODWORD(v62) += 4;
              }
              while ( v61 < v60 );
            }
            if ( *((_DWORD *)&v85 + v55) )
            {
              if ( *(&v86 + 4 * v55) )
                sub_9D4D50(*((_DWORD *)&v85 + v55));
              *(&v85 + v55) = 0.0;
            }
            v52 = v94;
            v54 = v95;
            *(&v85 + v55) = v93;
            v63 = v92;
            *(&v86 + 4 * v55) = 1;
            *(&v84 + v55) = v63;
          }
        }
        v64 = (_DWORD *)(*((_DWORD *)&v85 + v55) + 4 * *(&v83 + v55));
        if ( v64 )
          *v64 = *(_DWORD *)(LODWORD(v54) + 4 * LODWORD(v52));
        ++*(&v83 + v55);
        v51 = v81;
        ++LODWORD(v52);
        v94 = v52;
      }
      while ( SLODWORD(v52) < v74 );
    }
  }
  else
  {
    v28 = *(&v96 + 2 * i_1);
    if ( v84 < v28 )
    {
      if ( v28 )
        *(float *)&v29 = COERCE_FLOAT(sub_9D4CE0(4 * v28, 16));
      else
        *(float *)&v29 = 0.0;
      v30 = v83;
      v31 = 0;
      v92 = v29;
      if ( v83 > 0 )
      {
        v32 = (_DWORD *)v29;
        do
        {
          if ( v32 )
            *v32 = *(_DWORD *)(LODWORD(v85) + 4 * v31);
          ++v31;
          ++v32;
        }
        while ( v31 < v30 );
      }
      if ( v85 != 0.0 && v86 )
        sub_9D4D50(LODWORD(v85));
      v85 = *(float *)&v92;
      v33 = *(&v96 + 2 * i_1);
      v86 = 1;
      v84 = v33;
    }
    v34 = v98[2 * i_1 - 1];
    if ( v89 < v34 )
    {
      if ( v34 )
        *(float *)&v35 = COERCE_FLOAT(sub_9D4CE0(4 * v34, 16));
      else
        *(float *)&v35 = 0.0;
      v36 = v88;
      v37 = 0;
      v92 = v35;
      if ( v88 > 0 )
      {
        v38 = (_DWORD *)v35;
        do
        {
          if ( v38 )
            *v38 = *(_DWORD *)(LODWORD(v90) + 4 * v37);
          ++v37;
          ++v38;
        }
        while ( v37 < v36 );
      }
      if ( v90 != 0.0 && v91 )
        sub_9D4D50(LODWORD(v90));
      v90 = *(float *)&v92;
      v39 = v98[2 * i_1 - 1];
      v91 = 1;
      v89 = v39;
    }
    sub_989CD0(v81, &v82, &v87, &v77, (char *)&n1065353216_7 + 16 * i_1);
  }
  v65 = *(float *)(v76 + 4);
  v94 = v65;
  if ( v65 == 0.0 )
  {
    v65 = COERCE_FLOAT(sub_9D4CE0(48, 16));
    v94 = v65;
  }
  else
  {
    *(_DWORD *)(v76 + 4) = 0;
  }
  *(_DWORD *)(LODWORD(v65) + 32) = 0;
  *(_DWORD *)(LODWORD(v65) + 36) = 0;
  *(_DWORD *)(LODWORD(v65) + 40) = 0;
  qmemcpy((void *)LODWORD(v65), dst, 0x20u);
  v66 = v76;
  v67 = sub_98A060(v76, &v82);
  v68 = v94;
  *(_DWORD *)(LODWORD(v94) + 36) = v67;
  *(_DWORD *)(LODWORD(v68) + 40) = sub_98A060(v66, &v87);
  *(float *)(*(_DWORD *)(LODWORD(v68) + 36) + 32) = v68;
  *(float *)(*(_DWORD *)(LODWORD(v68) + 40) + 32) = v68;
  v100 = -1;
  `eh vector destructor iterator'(&v82, 0x14u, 2, (void (__thiscall *)(void *))sub_987800);
  return LODWORD(v68);
}
