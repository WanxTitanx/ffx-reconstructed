// Function: sub_991A10
// Address: 0x991a10
int __userpurge sub_991A10@<eax>(
        int a1@<ecx>,
        int a2@<ebp>,
        int a3,
        int a4,
        float *a5,
        float *a6,
        float *a7,
        int a8,
        int a9)
{
  double v9; // st7
  int v10; // esi
  int v11; // edi
  int v12; // eax
  double v13; // st6
  float v14; // xmm0_4
  double v15; // st5
  double v16; // st4
  double v17; // st7
  double v18; // st3
  double v19; // st6
  double v20; // st2
  double v21; // st3
  double v22; // st5
  double v23; // st4
  double v24; // st7
  float v25; // edx
  double v26; // st7
  double v27; // st6
  double v28; // st5
  double v29; // st4
  double v30; // st3
  double v31; // st2
  double v32; // st2
  double v33; // rt0
  char v34; // cl
  double v35; // st6
  double v36; // st4
  float v37; // xmm1_4
  double v38; // st5
  double v39; // st4
  double v40; // rt1
  double v41; // st3
  double v42; // st3
  float v43; // eax
  bool v44; // cl
  int v45; // ecx
  int result; // eax
  float v47; // [esp-80h] [ebp-8Ch]
  float v48; // [esp-7Ch] [ebp-88h]
  float v49; // [esp-78h] [ebp-84h]
  float v50; // [esp-70h] [ebp-7Ch]
  float v51; // [esp-6Ch] [ebp-78h]
  float v52[2]; // [esp-68h] [ebp-74h]
  float v53; // [esp-60h] [ebp-6Ch]
  float v54; // [esp-5Ch] [ebp-68h]
  float v55[2]; // [esp-58h] [ebp-64h]
  float v56; // [esp-50h] [ebp-5Ch]
  float v57; // [esp-4Ch] [ebp-58h]
  float v58; // [esp-48h] [ebp-54h]
  int v59; // [esp-44h] [ebp-50h]
  float v60; // [esp-40h] [ebp-4Ch]
  float v61; // [esp-3Ch] [ebp-48h]
  float v62; // [esp-38h] [ebp-44h]
  int v63; // [esp-34h] [ebp-40h]
  float v64; // [esp-2Ch] [ebp-38h]
  int v65; // [esp-28h] [ebp-34h]
  float v66; // [esp-24h] [ebp-30h]
  BOOL v67; // [esp-20h] [ebp-2Ch]
  float v68; // [esp-1Ch] [ebp-28h]
  float v69; // [esp-18h] [ebp-24h]
  float v70; // [esp-14h] [ebp-20h]
  int v71; // [esp-10h] [ebp-1Ch]
  float v72; // [esp-Ch] [ebp-18h]
  float v73; // [esp-8h] [ebp-14h]
  bool v74; // [esp-1h] [ebp-Dh]
  int v75; // [esp+0h] [ebp-Ch]
  void *v76; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v75 = a2;
  v76 = retaddr;
  v9 = *a5;
  v65 = a1;
  v72 = v9;
  v10 = *(_DWORD *)(a1 + 108);
  v56 = *(float *)a4;
  v57 = *(float *)(a4 + 4);
  v58 = *(float *)(a4 + 8);
  v59 = *(_DWORD *)(a4 + 12);
  v60 = *(float *)a4;
  v61 = *(float *)(a4 + 4);
  v11 = 0;
  v62 = *(float *)(a4 + 8);
  v12 = *(_DWORD *)(a4 + 12);
  v71 = 0;
  v63 = v12;
  if ( v56 > (double)v72 )
    v56 = v72;
  v73 = a5[1];
  v13 = v73;
  v14 = v73;
  v15 = v57;
  if ( v57 > (double)v73 )
  {
    v57 = v73;
    v15 = v73;
  }
  v73 = a5[2];
  v16 = v58;
  if ( v58 > (double)v73 )
  {
    v58 = v73;
    v16 = v73;
  }
  v17 = v60;
  if ( v72 > (double)v60 )
  {
    v60 = v72;
    v17 = v72;
  }
  v18 = v13;
  v19 = v61;
  if ( v18 > v61 )
  {
    v61 = v14;
    v19 = v14;
  }
  v20 = v62;
  if ( v73 > (double)v62 )
  {
    v62 = v73;
    v20 = v73;
  }
  v56 = *a6 + v56;
  v57 = v15 + a6[1];
  v58 = v16 + a6[2];
  v60 = v17 + *a7;
  v61 = v19 + a7[1];
  v62 = v20 + a7[2];
  v72 = v72 - *(float *)a4;
  v53 = v72;
  v70 = v18 - *(float *)(a4 + 4);
  v54 = v70;
  v73 = v73 - *(float *)(a4 + 8);
  v64 = v53 * v53 + v54 * v54 + v73 * v73;
  v64 = sqrt(v64);
  v64 = 1.0 / v64;
  v53 = v72 * v64;
  v54 = v70 * v64;
  v55[0] = v64 * v73;
  v66 = v73 * v55[0] + v72 * v53 + v70 * v54;
  v21 = 9.999999843067494e17;
  if ( v53 != 0.0 )
    v21 = 1.0 / v53;
  v47 = v21;
  if ( v54 == 0.0 )
  {
    v22 = v55[0];
    v23 = 9.999999843067494e17;
  }
  else
  {
    v23 = 1.0 / v54;
    v22 = v55[0];
  }
  v48 = v23;
  if ( v55[0] == 0.0 )
    v24 = 9.999999843067494e17;
  else
    v24 = 1.0 / v22;
  v49 = v24;
  LODWORD(v25) = v47 < 0.0;
  v64 = v25;
  LODWORD(v70) = v48 < 0.0;
  v67 = v49 < 0.0;
  if ( *(int *)(v65 + 68) > 0 )
  {
    v26 = v66;
    v27 = v58;
    v28 = v61;
    v29 = v49;
    v30 = v48;
    v31 = v47;
    while ( 1 )
    {
      v50 = *(float *)v10;
      v51 = *(float *)(v10 + 4);
      v52[0] = *(float *)(v10 + 8);
      v52[1] = *(float *)(v10 + 12);
      v53 = *(float *)(v10 + 16);
      v54 = *(float *)(v10 + 20);
      v55[0] = *(float *)(v10 + 24);
      v55[1] = *(float *)(v10 + 28);
      ++v71;
      v34 = 1;
      v50 = v50 - *a7;
      v51 = v51 - a7[1];
      v52[0] = v52[0] - a7[2];
      v53 = v53 - *a6;
      v54 = v54 - a6[1];
      v55[0] = v55[0] - a6[2];
      if ( v56 > (double)*(float *)(v10 + 16) || *(float *)v10 > (double)v60 )
        v34 = 0;
      if ( v27 > *(float *)(v10 + 24) || *(float *)(v10 + 8) > (double)v62 )
        v34 = 0;
      if ( v57 <= (double)*(float *)(v10 + 20) && *(float *)(v10 + 4) <= v28 && v34 )
      {
        v68 = *(float *)a4;
        v73 = (*(&v50 + 4 * LODWORD(v25)) - v68) * v31;
        v35 = v29;
        v72 = v31 * (*(&v53 - 4 * LODWORD(v25)) - v68);
        v68 = *(float *)(a4 + 4);
        v69 = (v52[4 * LODWORD(v70) - 1] - v68) * v30;
        v68 = v30 * (v55[-4 * LODWORD(v70) - 1] - v68);
        v36 = v73;
        if ( v73 <= (double)v68 && v69 <= (double)v72 )
        {
          if ( v69 > v36 )
          {
            v73 = v69;
            v36 = v69;
          }
          if ( v72 <= (double)v68 )
          {
            v37 = v72;
            v40 = v36;
            v39 = v72;
            v38 = v40;
          }
          else
          {
            v37 = v68;
            v38 = v36;
            v72 = v68;
            v39 = v68;
          }
          v68 = *(float *)(a4 + 8);
          v41 = v68;
          v68 = (v52[4 * v67] - v68) * v35;
          v69 = (v55[-4 * v67] - v41) * v35;
          v42 = v38;
          if ( v38 <= v69 && v68 <= v39 )
          {
            if ( v68 > v38 )
            {
              v73 = v68;
              v42 = v68;
            }
            if ( v39 > v69 )
              v37 = v69;
            if ( v26 > v42 && v37 > 0.0 )
            {
              LOBYTE(v43) = 1;
              goto LABEL_51;
            }
          }
        }
      }
      else
      {
        v35 = v29;
      }
      LOBYTE(v43) = 0;
LABEL_51:
      LODWORD(v43) = LOBYTE(v43);
      v44 = *(_DWORD *)(v10 + 32) == -1;
      LODWORD(v68) = LOBYTE(v43);
      v74 = v44;
      if ( !v44 )
        goto LABEL_54;
      if ( LOBYTE(v43) )
      {
        (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)a3 + 4))(
          a3,
          *(_DWORD *)(v10 + 36),
          *(_DWORD *)(v10 + 40));
        v43 = v68;
        v35 = v49;
        v26 = v66;
        v44 = v74;
LABEL_54:
        if ( v43 != 0.0 )
          goto LABEL_57;
      }
      if ( !v44 )
      {
        v45 = *(_DWORD *)(v10 + 32);
        v10 += v45 << 6;
        v11 += v45;
        goto LABEL_58;
      }
LABEL_57:
      v10 += 64;
      ++v11;
LABEL_58:
      v25 = v64;
      if ( v11 >= *(_DWORD *)(v65 + 68) )
        break;
      v32 = v35;
      v27 = v58;
      v33 = v32;
      v28 = v61;
      v30 = v48;
      v31 = v47;
      v29 = v33;
    }
  }
  result = dword_193F244;
  if ( dword_193F244 < v71 )
    result = v71;
  dword_193F244 = result;
  return result;
}
