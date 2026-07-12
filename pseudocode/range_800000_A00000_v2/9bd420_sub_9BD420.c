// Function: sub_9BD420
// Address: 0x9bd420
int __userpurge sub_9BD420@<eax>(
        int a1@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        char a5@<efl>,
        _DWORD *a6,
        int a7)
{
  int v8; // ecx
  int v9; // edx
  int result; // eax
  int v11; // edi
  float v12; // xmm0_4
  bool v13; // cf
  bool v14; // zf
  char v15; // sf
  char v16; // of
  char v17; // pf
  float v18; // xmm0_4
  float v19; // edi
  float v20; // eax
  int v21; // eax
  float v22; // eax
  int v23; // ecx
  int v24; // edx
  float v25; // eax
  _DWORD *v26; // eax
  int v27; // edi
  int v28; // ecx
  int v29; // edx
  int v30; // eax
  int v31; // eax
  double v32; // st7
  double v33; // st7
  double v34; // st7
  float *v35; // eax
  double v36; // st7
  double v37; // st7
  double v38; // st5
  double v39; // st4
  double v40; // st6
  double v41; // st2
  double v42; // st4
  double v43; // st3
  double v44; // st5
  double v45; // st7
  double v46; // st7
  double v47; // st7
  int v48; // ecx
  double v49; // st7
  double v50; // st7
  double v51; // st7
  double v52; // st6
  bool v53; // cc
  int v54; // [esp-14h] [ebp-ECh]
  int v55; // [esp+Ch] [ebp-CCh]
  int v56; // [esp+10h] [ebp-C8h]
  float v57[4]; // [esp+1Ch] [ebp-BCh] BYREF
  float v58; // [esp+2Ch] [ebp-ACh]
  float v59; // [esp+30h] [ebp-A8h]
  float v60; // [esp+34h] [ebp-A4h]
  _BYTE v61[16]; // [esp+3Ch] [ebp-9Ch] BYREF
  _BYTE v62[28]; // [esp+4Ch] [ebp-8Ch] BYREF
  float v63; // [esp+68h] [ebp-70h] BYREF
  float v64; // [esp+6Ch] [ebp-6Ch]
  float v65; // [esp+70h] [ebp-68h]
  float v66; // [esp+74h] [ebp-64h]
  int v67; // [esp+78h] [ebp-60h]
  float v68; // [esp+7Ch] [ebp-5Ch]
  float v69; // [esp+80h] [ebp-58h]
  float v70; // [esp+84h] [ebp-54h]
  int v71; // [esp+88h] [ebp-50h]
  int v72; // [esp+90h] [ebp-48h]
  int v73; // [esp+94h] [ebp-44h]
  int v74; // [esp+98h] [ebp-40h]
  int v75; // [esp+9Ch] [ebp-3Ch]
  int v76; // [esp+A0h] [ebp-38h]
  int v77; // [esp+A4h] [ebp-34h]
  int v78; // [esp+A8h] [ebp-30h]
  float v79; // [esp+ACh] [ebp-2Ch] BYREF
  _DWORD *v80; // [esp+B0h] [ebp-28h]
  float v81; // [esp+B4h] [ebp-24h]
  int v82; // [esp+B8h] [ebp-20h]
  int v83; // [esp+BCh] [ebp-1Ch]
  float v84; // [esp+C0h] [ebp-18h]
  float v85; // [esp+C4h] [ebp-14h]
  float v86; // [esp+C8h] [ebp-10h]
  int v87; // [esp+CCh] [ebp-Ch]
  void *v88; // [esp+D0h] [ebp-8h]
  void *retaddr; // [esp+D8h] [ebp+0h]

  v87 = a2;
  v88 = retaddr;
  v56 = a4;
  v8 = a6[292];
  v9 = a6[293];
  result = 0;
  if ( (*(_BYTE *)(v8 + 244) & 2) != 0 )
    result = a6[292];
  v55 = a3;
  v11 = 0;
  if ( (*(_BYTE *)(v9 + 244) & 2) != 0 )
    v11 = a6[293];
  v74 = a1;
  v82 = v8;
  v83 = v9;
  v76 = result;
  v78 = v11;
  if ( result )
  {
    v12 = *(float *)(result + 352);
    v13 = v12 < 0.0;
    v17 = 0;
    v14 = v12 == 0.0;
    v15 = 0;
    v16 = 0;
    BYTE1(result) = a5;
    if ( v12 != 0.0 )
      goto LABEL_59;
  }
  if ( v11 )
  {
    v18 = *(float *)(v11 + 352);
    v13 = v18 < 0.0;
    v17 = 0;
    v14 = v18 == 0.0;
    v15 = 0;
    v16 = 0;
    BYTE1(result) = a5;
    if ( v18 != 0.0 )
    {
LABEL_59:
      result = (int)a6;
      v75 = 0;
      if ( (int)a6[294] > 0 )
      {
        LODWORD(v19) = a6 + 21;
        LODWORD(v81) = a6 + 21;
        while ( *(float *)(result + 1184) < (double)*(float *)(LODWORD(v19) + 12) )
        {
LABEL_56:
          ++v75;
          result = (int)a6;
          LODWORD(v19) += 288;
          v53 = v75 < a6[294];
          a1 = v74;
          v81 = v19;
          if ( !v53 )
            return result;
        }
        v20 = *(float *)(a1 + 8);
        v77 = LODWORD(v20);
        v86 = v20;
        if ( LODWORD(v20) == *(_DWORD *)(a1 + 12) )
        {
          if ( v20 == 0.0 )
            v21 = 1;
          else
            v21 = 2 * LODWORD(v20);
          v85 = *(float *)&v21;
          if ( *(_DWORD *)(a1 + 12) < v21 )
          {
            if ( *(float *)&v21 == 0.0 )
              v22 = 0.0;
            else
              v22 = COERCE_FLOAT(sub_9D4CE0(192 * v21, 16));
            v23 = *(_DWORD *)(a1 + 8);
            v84 = v22;
            v80 = (_DWORD *)v23;
            if ( v23 > 0 )
            {
              v24 = 0;
              do
              {
                if ( v22 != 0.0 )
                {
                  qmemcpy((void *)LODWORD(v22), (const void *)(v24 + *(_DWORD *)(a1 + 16)), 0xC0u);
                  a1 = v74;
                  v23 = (int)v80;
                }
                v24 += 192;
                LODWORD(v22) += 192;
                v80 = (_DWORD *)--v23;
              }
              while ( v23 );
            }
            if ( *(_DWORD *)(a1 + 16) )
            {
              if ( *(_BYTE *)(a1 + 20) )
                sub_9D4D50(*(_DWORD *)(a1 + 16));
              *(_DWORD *)(a1 + 16) = 0;
            }
            v8 = v82;
            v9 = v83;
            *(float *)(a1 + 16) = v84;
            v25 = v85;
            *(_BYTE *)(a1 + 20) = 1;
            *(float *)(a1 + 12) = v25;
          }
          v20 = v86;
        }
        ++*(_DWORD *)(a1 + 8);
        v26 = (_DWORD *)(*(_DWORD *)(a1 + 16) + 192 * LODWORD(v20));
        v27 = 0;
        if ( (*(_BYTE *)(v8 + 244) & 2) != 0 )
          v27 = v8;
        v28 = 0;
        if ( (*(_BYTE *)(v9 + 244) & 2) != 0 )
          v28 = v9;
        v29 = v27;
        v80 = v26;
        v73 = v27;
        v72 = v28;
        if ( !v27 )
        {
          v30 = sub_9BDD30(v55, v56);
          v28 = v72;
          v29 = v30;
          v26 = v80;
        }
        v26[32] = v29;
        if ( !v28 )
        {
          v28 = sub_9BDD30(v55, v56);
          v26 = v80;
        }
        v19 = v81;
        v26[33] = v28;
        v54 = v83;
        v26[34] = LODWORD(v19) - 68;
        sub_9BFD90(v26, v82, v54, LODWORD(v19) - 68, a7, v57, &v63, &v79, v61, v62);
        v80[31] = *(_DWORD *)(a1 + 48);
        if ( (*(_BYTE *)(a7 + 60) & 0x20) != 0 && *(_BYTE *)(LODWORD(v19) + 48) )
        {
          sub_9BCFB0(
            a1,
            LODWORD(v19) + 92,
            v76,
            v78,
            v77,
            LODWORD(v19) - 68,
            (int)v61,
            (int)v62,
            v82,
            v83,
            v79,
            *(float *)(LODWORD(v19) + 60),
            *(float *)(LODWORD(v19) + 68));
          v31 = a7;
          if ( (*(_BYTE *)(a7 + 60) & 0x10) == 0 )
          {
LABEL_55:
            sub_9BF640(v80, v73, v72, LODWORD(v19) - 68, v31);
            v8 = v82;
            v9 = v83;
            goto LABEL_56;
          }
          sub_9BCFB0(
            a1,
            LODWORD(v19) + 108,
            v76,
            v78,
            v77,
            LODWORD(v19) - 68,
            (int)v61,
            (int)v62,
            v82,
            v83,
            v79,
            *(float *)(LODWORD(v19) + 64),
            *(float *)(LODWORD(v19) + 72));
LABEL_54:
          v31 = a7;
          goto LABEL_55;
        }
        v67 = 0;
        v58 = v63 * *(float *)(LODWORD(v19) - 4);
        v59 = *(float *)LODWORD(v19) * v63;
        v60 = v63 * *(float *)(LODWORD(v19) + 4);
        v64 = v57[0] - v58;
        v32 = v57[1];
        *(float *)(LODWORD(v19) + 92) = v64;
        v65 = v32 - v59;
        v33 = v57[2];
        *(float *)(LODWORD(v19) + 96) = v65;
        v66 = v33 - v60;
        *(float *)(LODWORD(v19) + 100) = v66;
        *(_DWORD *)(LODWORD(v19) + 104) = v67;
        v34 = *(float *)(LODWORD(v19) + 96);
        v14 = (*(_BYTE *)(a7 + 60) & 0x40) == 0;
        v85 = *(float *)(LODWORD(v19) + 92);
        v86 = v85 * v85 + v34 * v34 + *(float *)(LODWORD(v19) + 100) * *(float *)(LODWORD(v19) + 100);
        if ( v14 && v86 > 0.00000011920929 )
        {
          v86 = sqrt(v86);
          v35 = (float *)(LODWORD(v19) + 92);
          v86 = 1.0 / v86;
          v36 = v86;
          *(float *)(LODWORD(v19) + 92) = v86 * v85;
          v86 = v36 * *(float *)(LODWORD(v19) + 96);
          v85 = v86;
          *(float *)(LODWORD(v19) + 96) = v86;
          v86 = v36 * *(float *)(LODWORD(v19) + 100);
          v84 = v86;
          *(float *)(LODWORD(v19) + 100) = v86;
          if ( (*(_BYTE *)(a7 + 60) & 0x10) == 0 )
          {
LABEL_53:
            sub_9BD190(v82, (int)v35);
            sub_9BD190(v83, LODWORD(v19) + 92);
            sub_9BCFB0(
              a1,
              LODWORD(v19) + 92,
              v76,
              v78,
              v77,
              LODWORD(v19) - 68,
              (int)v61,
              (int)v62,
              v82,
              v83,
              v79,
              0.0,
              0.0);
            *(_BYTE *)(LODWORD(v19) + 48) = 1;
            goto LABEL_54;
          }
          v86 = *(float *)(LODWORD(v19) + 4);
          v71 = 0;
          v81 = *(float *)LODWORD(v19);
          v37 = v85;
          v38 = v86;
          v39 = v84;
          v40 = v81;
          v68 = v85 * v86 - v84 * v81;
          v86 = *(float *)(LODWORD(v19) - 4);
          v85 = *v35;
          *(float *)(LODWORD(v19) + 108) = v68;
          v41 = v39 * v86;
          v42 = v85;
          v43 = v41 - v38 * v85;
          v44 = v86;
          v69 = v43;
          *(float *)(LODWORD(v19) + 112) = v69;
          v70 = v40 * v42 - v37 * v44;
          *(float *)(LODWORD(v19) + 116) = v70;
          *(_DWORD *)(LODWORD(v19) + 120) = v71;
          v85 = *(float *)(LODWORD(v19) + 112);
          v86 = *(float *)(LODWORD(v19) + 108);
          v84 = *(float *)(LODWORD(v19) + 116);
          v81 = v86 * v86 + v85 * v85 + v84 * v84;
          v81 = sqrt(v81);
          v81 = 1.0 / v81;
          v45 = v81;
          *(float *)(LODWORD(v19) + 108) = v86 * v81;
          *(float *)(LODWORD(v19) + 112) = v85 * v45;
          *(float *)(LODWORD(v19) + 116) = v45 * v84;
          sub_9BD190(v82, LODWORD(v19) + 108);
          sub_9BD190(v83, LODWORD(v19) + 108);
          a1 = v74;
          sub_9BCFB0(
            v74,
            LODWORD(v19) + 108,
            v76,
            v78,
            v77,
            LODWORD(v19) - 68,
            (int)v61,
            (int)v62,
            v82,
            v83,
            v79,
            0.0,
            0.0);
        }
        else
        {
          v86 = *(float *)(LODWORD(v19) + 4);
          v46 = v86;
          v86 = fabs(v86);
          if ( v86 <= 0.70710677 )
          {
            v86 = *(float *)LODWORD(v19);
            v85 = *(float *)(LODWORD(v19) - 4) * *(float *)(LODWORD(v19) - 4) + v86 * v86;
            v84 = sqrt(v85);
            v48 = LODWORD(v19) + 108;
            v84 = 1.0 / v84;
            v51 = v84;
            *(float *)(LODWORD(v19) + 92) = -v86 * v84;
            v52 = v51 * *(float *)(LODWORD(v19) - 4);
            *(_DWORD *)(LODWORD(v19) + 100) = 0;
            *(float *)(LODWORD(v19) + 96) = v52;
            *(float *)(LODWORD(v19) + 108) = -*(float *)(LODWORD(v19) + 4) * *(float *)(LODWORD(v19) + 96);
            *(float *)(LODWORD(v19) + 112) = *(float *)(LODWORD(v19) + 92) * *(float *)(LODWORD(v19) + 4);
            v50 = v51 * v85;
          }
          else
          {
            v86 = v46 * v46 + *(float *)LODWORD(v19) * *(float *)LODWORD(v19);
            v85 = sqrt(v86);
            v47 = v85;
            *(_DWORD *)(LODWORD(v19) + 92) = 0;
            v48 = LODWORD(v19) + 108;
            v85 = 1.0 / v47;
            v49 = v85;
            *(float *)(LODWORD(v19) + 96) = -*(float *)(LODWORD(v19) + 4) * v85;
            *(float *)(LODWORD(v19) + 100) = *(float *)LODWORD(v19) * v49;
            *(float *)(LODWORD(v19) + 108) = v49 * v86;
            *(float *)(LODWORD(v19) + 112) = -*(float *)(LODWORD(v19) - 4) * *(float *)(LODWORD(v19) + 100);
            v50 = *(float *)(LODWORD(v19) + 96) * *(float *)(LODWORD(v19) - 4);
          }
          *(float *)(LODWORD(v19) + 116) = v50;
          if ( (*(_BYTE *)(a7 + 60) & 0x10) != 0 )
          {
            sub_9BD190(v82, v48);
            sub_9BD190(v83, LODWORD(v19) + 108);
            sub_9BCFB0(
              a1,
              LODWORD(v19) + 108,
              v76,
              v78,
              v77,
              LODWORD(v19) - 68,
              (int)v61,
              (int)v62,
              v82,
              v83,
              v79,
              0.0,
              0.0);
          }
        }
        v35 = (float *)(LODWORD(v19) + 92);
        goto LABEL_53;
      }
    }
  }
  return result;
}
