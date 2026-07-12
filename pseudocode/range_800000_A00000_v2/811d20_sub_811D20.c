// Function: sub_811D20
// Address: 0x811d20
char __cdecl sub_811D20(int a1, float *a2)
{
  int v2; // ebx
  int v3; // eax
  int v4; // eax
  int v5; // edx
  double v6; // st7
  double v7; // st7
  double v8; // st5
  int v9; // ecx
  int v10; // ebx
  int v11; // esi
  double v12; // st6
  double v13; // st7
  int v14; // eax
  int v15; // edx
  int v16; // esi
  int v17; // ebx
  int v18; // esi
  double v19; // st7
  int v20; // eax
  float v21; // ebx
  int v22; // ecx
  int v23; // eax
  double v24; // st7
  double v25; // st6
  double v26; // st7
  int v27; // eax
  double v28; // st6
  double v29; // st5
  double v30; // st6
  double v31; // st5
  double v32; // st5
  double v33; // st5
  double v34; // st6
  double v35; // st6
  double v36; // st6
  double v37; // st7
  float *v38; // eax
  int v39; // ecx
  __int16 v40; // si
  int v41; // ebx
  float v42; // eax
  int v43; // edx
  int v44; // ecx
  unsigned __int16 v45; // si
  float *v46; // ecx
  unsigned __int16 v47; // dx
  unsigned __int16 v48; // ax
  float *v49; // esi
  double v50; // st7
  int v51; // edi
  int v52; // esi
  void *v53; // eax
  float v54; // esi
  int v55; // esi
  bool v56; // zf
  int v57; // eax
  double v58; // st7
  __int64 v60; // [esp-14h] [ebp-B4h]
  __int64 v61; // [esp-4h] [ebp-A4h]
  __int64 n2622; // [esp-4h] [ebp-A4h]
  float v63; // [esp+14h] [ebp-8Ch]
  float v64; // [esp+18h] [ebp-88h]
  int v65; // [esp+20h] [ebp-80h] BYREF
  float v66; // [esp+24h] [ebp-7Ch]
  float v67; // [esp+28h] [ebp-78h]
  float v68; // [esp+2Ch] [ebp-74h]
  float *v69; // [esp+34h] [ebp-6Ch]
  int v70; // [esp+38h] [ebp-68h]
  float v71; // [esp+3Ch] [ebp-64h]
  float v72; // [esp+40h] [ebp-60h]
  float v73; // [esp+44h] [ebp-5Ch]
  int v74; // [esp+4Ch] [ebp-54h]
  int v75; // [esp+50h] [ebp-50h]
  int v76; // [esp+54h] [ebp-4Ch]
  float v77; // [esp+58h] [ebp-48h]
  float v78; // [esp+5Ch] [ebp-44h]
  float v79; // [esp+60h] [ebp-40h]
  int v80; // [esp+64h] [ebp-3Ch]
  float v81; // [esp+68h] [ebp-38h]
  float v82; // [esp+6Ch] [ebp-34h]
  float v83; // [esp+70h] [ebp-30h]
  int v84; // [esp+74h] [ebp-2Ch]
  int v85; // [esp+78h] [ebp-28h]
  float v86; // [esp+7Ch] [ebp-24h]
  double v87; // [esp+80h] [ebp-20h]
  float v88; // [esp+88h] [ebp-18h]
  int v89[4]; // [esp+8Ch] [ebp-14h] BYREF

  v70 = a1;
  v2 = *(int *)(a1 + 544);
  v69 = a2;
  v3 = *(unsigned __int8 *)(v2 + 24);
  v79 = *(float *)&v2;
  LOBYTE(v3) = byte_12A8480[v3];
  if ( ((unsigned __int8)v3 & *(_BYTE *)(v2 + 179)) == 0 )
  {
    v4 = sub_800F80(a2, v2, *(_WORD *)(v2 + 168));
    v5 = *(_DWORD *)(v2 + 188);
    LODWORD(v88) = *(__int16 *)(v2 + 170);
    v75 = v4;
    v85 = v5;
    v86 = (float)SLODWORD(v88);
    if ( v86 < 10000.0 )
    {
      v7 = sub_794FC0(*(unsigned __int8 *)(v2 + 24));
      v5 = v85;
      v8 = v7;
      v6 = 0.0625;
      v81 = v86 * 0.0625 + v8;
    }
    else
    {
      v81 = 65536.0;
      v6 = 0.0625;
    }
    v9 = *(unsigned __int16 *)(v5 + 4);
    v76 = v5 + 16;
    v10 = 32 * v9 + v5 + 16;
    v88 = *(float *)&v9;
    v11 = *(unsigned __int16 *)(v5 + 6);
    v12 = *(float *)(LODWORD(v79) + 76);
    v87 = (double)v9;
    v82 = v6 * (v12 / v87);
    sub_7EA760(a1 + 64, v75 + 64, 0.00390625);
    v13 = 0.0;
    v14 = v85;
    *(_DWORD *)(a1 + 80) = 0;
    v15 = v76 + 16 * (v11 % *(unsigned __int16 *)(v14 + 4));
    *(_QWORD *)&n1065353216 = *(_QWORD *)v15;
    n1065353216_2 = *(_DWORD *)(v15 + 8);
    n1065353216_3 = *(_DWORD *)(v15 + 12);
    *(_QWORD *)(v10 - 16) = *(_QWORD *)&n1065353216;
    *(_DWORD *)(v10 - 8) = n1065353216_2;
    *(float *)(v10 - 4) = 0.0;
    if ( v81 <= (double)*(float *)(v10 - 12) )
    {
      *(float *)(v10 - 12) = v81;
      ++*(_DWORD *)(a1 + 80);
    }
    v16 = v85;
    v17 = v10 - 32;
    v84 = 1;
    v77 = v82 + 0.0;
    if ( *(_WORD *)(v85 + 4) > 1u )
    {
      v18 = v17 + 16;
      do
      {
        sub_6ED3D0(v89, v17, a1 + 64);
        sub_6EDA80(v89, v89, v18);
        sub_6ED830(v89, v89);
        sub_6EDA30((int)v89, (int)v89, v82);
        sub_6ED3D0(v89, v89, v18);
        sub_6ED4B0(v17, v89);
        v19 = v77;
        *(float *)(v18 - 4) = v77;
        if ( *(float *)(v18 - 12) >= (double)v81 )
        {
          *(float *)(v18 - 12) = v81;
          ++*(_DWORD *)(a1 + 80);
        }
        v20 = *(unsigned __int16 *)(v85 + 4);
        v77 = v19 + v82;
        v17 -= 16;
        v18 -= 16;
        ++v84;
      }
      while ( v84 < v20 );
      v13 = 0.0;
      v16 = v85;
    }
    v21 = v79;
    if ( *(_DWORD *)(a1 + 80) >= (int)*(unsigned __int16 *)(v16 + 4) )
      *(_WORD *)(LODWORD(v79) + 176) |= 1u;
    v3 = (int)*(float *)(v75 + 48);
    v74 = v3;
    v80 = v3;
    if ( v3 > 0 )
    {
      v3 = (int)*(float *)(v75 + 76);
      v84 = v3;
      v74 -= v3;
      if ( v74 > 0 )
      {
        v22 = v75;
        v23 = 2 * *(unsigned __int16 *)(v16 + 4);
        v82 = *(float *)(v75 + 52) / *(float *)(v75 + 48) * 0.0625;
        v86 = *(float *)(v16 + 8 * v23 + 28);
        if ( v82 <= v13 )
        {
          v82 = v13;
        }
        else
        {
          v88 = v82 * *(float *)(v75 + 48);
          if ( v88 > (double)v86 )
            v82 = v86 / *(float *)(v75 + 48);
        }
        *(_DWORD *)(a1 + 328) = *(_DWORD *)(LODWORD(v21) + 228);
        v88 = (*(float *)(LODWORD(v21) + 60) - *(float *)(v22 + 60)) / *(float *)(v22 + 48);
        v24 = v88;
        *(float *)(a1 + 324) = v88;
        v88 = (float)v84;
        v25 = *(float *)(LODWORD(v21) + 60) - v24 * v88;
        v26 = v88;
        *(float *)(a1 + 320) = v25;
        v88 = (float)v80;
        v27 = *(unsigned __int8 *)(v22 + 200);
        *(float *)&v84 = v88;
        v88 = *(float *)&v27;
        v87 = (double)v27;
        v28 = v87;
        LODWORD(v88) = *(unsigned __int8 *)(LODWORD(v21) + 200);
        v87 = (double)SLODWORD(v88);
        v29 = (v28 - v87) / *(float *)&v84;
        v30 = *(float *)&v84;
        *(float *)(a1 + 352) = v29;
        LODWORD(v88) = *(unsigned __int8 *)(v22 + 201);
        v87 = (double)SLODWORD(v88);
        v31 = v87;
        LODWORD(v88) = *(unsigned __int8 *)(LODWORD(v21) + 201);
        v87 = (double)SLODWORD(v88);
        *(float *)(a1 + 356) = (v31 - v87) / v30;
        LODWORD(v88) = *(unsigned __int8 *)(v22 + 202);
        v87 = (double)SLODWORD(v88);
        v32 = v87;
        LODWORD(v88) = *(unsigned __int8 *)(LODWORD(v21) + 202);
        v87 = (double)SLODWORD(v88);
        *(float *)(a1 + 360) = (v32 - v87) / v30;
        LODWORD(v88) = *(unsigned __int8 *)(v22 + 203);
        v87 = (double)SLODWORD(v88);
        v33 = v87;
        LODWORD(v88) = *(unsigned __int8 *)(LODWORD(v21) + 203);
        v87 = (double)SLODWORD(v88);
        *(float *)(a1 + 364) = (v33 - v87) / v30;
        v34 = *(float *)(a1 + 352) * v26;
        LODWORD(v88) = *(unsigned __int8 *)(LODWORD(v21) + 200);
        v87 = (double)SLODWORD(v88);
        *(float *)(a1 + 336) = v34 + v87;
        v35 = *(float *)(a1 + 356);
        LODWORD(v88) = *(unsigned __int8 *)(LODWORD(v21) + 201);
        v87 = (double)SLODWORD(v88);
        *(float *)(a1 + 340) = v35 * v26 + v87;
        v36 = *(float *)(a1 + 360);
        LODWORD(v88) = *(unsigned __int8 *)(LODWORD(v21) + 202);
        v87 = (double)SLODWORD(v88);
        *(float *)(a1 + 344) = v36 * v26 + v87;
        LODWORD(v88) = *(unsigned __int8 *)(LODWORD(v21) + 203);
        v37 = v26 * *(float *)(a1 + 364);
        v87 = (double)SLODWORD(v88);
        *(float *)(a1 + 348) = v37 + v87;
        HIDWORD(v87) = sub_801E20((_DWORD *)a1, (unsigned __int16 *)LODWORD(v21));
        sub_7E7F20(a1 + 64, HIDWORD(v87));
        v77 = 0.0;
        *(_WORD *)(a1 + 2) = 128;
        *(_DWORD *)(a1 + 16) = a1 + 128;
        v38 = v69;
        *(_DWORD *)(a1 + 8) = 0;
        *(_DWORD *)(a1 + 12) = 0;
        *(_BYTE *)(a1 + 24) = 0;
        v39 = *(unsigned __int16 *)(v16 + 4);
        v88 = v38[21];
        v40 = v39 - 1;
        v76 += 16 * v39;
        v41 = 0;
        *((float *)&v60 + 1) = v79;
        LODWORD(v60) = 0;
        v84 = (unsigned __int16)(v39 - 1);
        v83 = 0.0;
        v86 = v79;
        if ( !sub_645580(v60) )
        {
          v65 = unknown_libname_742(*(_DWORD *)(LODWORD(v79) + 212));
          sub_7114B0(0, LODWORD(v86), &v65, *(unsigned __int16 *)(v85 + 4), 8);
        }
        *((float *)&v61 + 1) = v86;
        LODWORD(v61) = 0;
        v42 = COERCE_FLOAT(sub_645580(v61));
        v43 = LODWORD(v42);
        v81 = v42;
        if ( v42 == 0.0 || *(int *)(LODWORD(v42) + 144) <= 0 )
        {
LABEL_28:
          sub_713370(0, LODWORD(v86));
          v80 = 0;
          if ( v74 > 0 )
          {
            while ( 1 )
            {
              v45 = v40 - 1;
              v46 = (float *)(v76 + 16 * (v45 % (int)*(unsigned __int16 *)(v85 + 4)));
              if ( v46[3] < (double)v77 )
                break;
LABEL_33:
              v49 = (float *)(v76 + 16 * ((unsigned __int16)v84 % (int)*(unsigned __int16 *)(v85 + 4)));
              v66 = *v49;
              v67 = v49[1];
              v68 = v49[2];
              v63 = v46[1];
              v64 = v46[2];
              v71 = *v46 - v66;
              v72 = v63 - v67;
              v73 = v64 - v68;
              v83 = sqrt(v71 * v71 + v72 * v72 + v73 * v73);
              v78 = v77 - v49[3];
              v50 = v83;
              if ( 0.0 == v83 )
              {
                v73 = 0.0;
                v72 = 0.0;
                v71 = 0.0;
              }
              else
              {
                v71 = v71 * v78 / v50;
                v72 = v72 * v78 / v50;
                v73 = v78 * v73 / v50;
              }
              v51 = v70;
              v52 = v70 + 240;
              v53 = (void *)(v70 + 256);
              *(float *)(v70 + 240) = v71 + v66;
              *(float *)(v51 + 244) = v72 + v67;
              *(float *)(v51 + 248) = v73 + v68;
              v78 = *(float *)(v51 + 320) * 0.000244140625;
              sub_7EA610(v53, v78);
              sub_7E78B0(v51 + 304, HIDWORD(v87), v52);
              sub_7E7F20(v51 + 128, v51 + 256);
              v54 = v79;
              if ( *(_WORD *)(LODWORD(v79) + 198) )
              {
                *(_DWORD *)(v51 + 28) = v51 + 256;
                LODWORD(v78) = *(__int16 *)(LODWORD(v54) + 198);
                v78 = (float)SLODWORD(v78);
                *(float *)(v51 + 312) = v78 * 0.0625 + *(float *)(v51 + 312);
              }
              else
              {
                *(_DWORD *)(v51 + 28) = 0;
              }
              *(float *)(v51 + 20) = v88;
              v55 = *(_DWORD *)(*(_DWORD *)(LODWORD(v54) + 224)
                              + 4
                              * ((*(_DWORD *)(v51 + 328) >> 8) % (unsigned int)*(unsigned __int16 *)(LODWORD(v54) + 232)));
              *(_BYTE *)(v51 + 4) = (int)*(float *)(v51 + 336);
              *(_BYTE *)(v51 + 5) = (int)*(float *)(v51 + 340);
              *(_BYTE *)(v51 + 6) = (int)*(float *)(v51 + 344);
              v56 = LODWORD(v81) == 0;
              *(_BYTE *)(v51 + 7) = (int)*(float *)(v51 + 348);
              *(float *)(v51 + 336) = *(float *)(v51 + 352) + *(float *)(v51 + 336);
              *(float *)(v51 + 340) = *(float *)(v51 + 356) + *(float *)(v51 + 340);
              *(float *)(v51 + 344) = *(float *)(v51 + 344) + *(float *)(v51 + 360);
              *(float *)(v51 + 348) = *(float *)(v51 + 364) + *(float *)(v51 + 348);
              if ( !v56 )
                sub_71A5C0(0, LODWORD(v86), v55, v51);
              v57 = (int)*(float *)(v75 + 56);
              *(float *)(v51 + 320) = *(float *)(v51 + 320) - *(float *)(v51 + 324);
              v58 = v77 + v82;
              *(_DWORD *)(v51 + 328) += -2 * v57;
              v77 = v58;
              v40 = v84;
              if ( ++v80 >= v74 )
                goto LABEL_42;
            }
            v47 = *(_WORD *)(v85 + 8);
            LODWORD(v83) = v47;
            while ( 1 )
            {
              v48 = v45;
              ++v41;
              v84 = v45;
              if ( (unsigned __int16)v41 >= v47 )
                break;
              --v45;
              v47 = LOWORD(v83);
              v46 = (float *)(v76 + 16 * ((unsigned __int16)(v48 - 1) % (int)*(unsigned __int16 *)(v85 + 4)));
              if ( v46[3] >= (double)v77 )
                goto LABEL_33;
            }
          }
LABEL_42:
          v56 = (*(_WORD *)(LODWORD(v79) + 192) & 0x4000) == 0;
          *(_WORD *)(LODWORD(v79) + 192) &= 0x4000u;
          if ( v56 )
            *(_DWORD *)(v75 + 228) += 512;
          v56 = LODWORD(v81) == 0;
          v69[21] = v88;
          if ( !v56 )
          {
            *((float *)&n2622 + 1) = v86;
            LODWORD(n2622) = 0;
            FFX_MagicHost_CommitDrawableResources(n2622);
          }
          LOBYTE(v3) = sub_644CC0(0, LODWORD(v86));
        }
        else
        {
          v44 = 0;
          v80 = 0;
          while ( 1 )
          {
            *(float *)&v3 = COERCE_FLOAT(
                              sub_63FF60(
                                v43,
                                SLODWORD(v83),
                                *(_DWORD *)(v44 + *(_DWORD *)(v43 + 148) + 100),
                                *(_DWORD *)(v44 + *(_DWORD *)(v43 + 148) + 104)));
            if ( *(float *)&v3 == 0.0 )
              break;
            memset(
              *(void **)(v80 + *(_DWORD *)(LODWORD(v81) + 148) + 28),
              0,
              2 * *(_DWORD *)(v80 + *(_DWORD *)(LODWORD(v81) + 148) + 104));
            v43 = LODWORD(v81);
            v44 = v80 + 108;
            ++LODWORD(v83);
            v80 += 108;
            if ( SLODWORD(v83) >= *(_DWORD *)(LODWORD(v81) + 144) )
              goto LABEL_28;
          }
        }
      }
    }
  }
  return v3;
}
