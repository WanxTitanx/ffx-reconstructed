// Function: sub_A98E20
// Address: 0xa98e20
// Size: 0x4a4
// Prototype: 

int __fastcall sub_A98E20(int n2, int a2, float *a3, float *a4, int a5, int a6, float *a7)
{
  int v7; // ebx
  float *v8; // esi
  int result; // eax
  int v10; // eax
  float *v11; // ebx
  int v12; // edx
  float *i_1; // eax
  float *v14; // edi
  float *v15; // ecx
  float v16; // xmm2_4
  float v17; // xmm1_4
  float *v18; // eax
  float v19; // xmm4_4
  float v20; // xmm3_4
  float *v21; // eax
  int v22; // eax
  int v23; // edi
  int v24; // edx
  float *v25; // edi
  float *v26; // ebx
  int v27; // eax
  float *v28; // edx
  int v29; // ecx
  unsigned int v30; // eax
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm5_4
  float v34; // xmm6_4
  float v35; // xmm3_4
  float v36; // xmm2_4
  float v37; // xmm5_4
  float v38; // xmm7_4
  float v39; // xmm6_4
  float v40; // xmm1_4
  float v41; // xmm4_4
  float v42; // xmm1_4
  float v43; // xmm0_4
  float v44; // xmm6_4
  float v45; // xmm3_4
  float v46; // xmm7_4
  float v47; // xmm1_4
  float v48; // xmm0_4
  bool v49; // zf
  int v50; // edx
  float *v51; // edi
  float *v52; // ebx
  int v53; // eax
  float *v54; // ecx
  float *v55; // eax
  float *v56; // esi
  float v57; // xmm1_4
  float v58; // xmm4_4
  float v59; // xmm2_4
  float v60; // xmm3_4
  float v61; // xmm4_4
  int v62; // [esp+Ch] [ebp-58h]
  float *v63; // [esp+Ch] [ebp-58h]
  char *v64; // [esp+10h] [ebp-54h]
  float v65; // [esp+14h] [ebp-50h]
  float *v66; // [esp+14h] [ebp-50h]
  float v67; // [esp+18h] [ebp-4Ch]
  int v68; // [esp+1Ch] [ebp-48h]
  float *v69; // [esp+1Ch] [ebp-48h]
  int v70; // [esp+20h] [ebp-44h]
  float *v71; // [esp+20h] [ebp-44h]
  float *v72; // [esp+24h] [ebp-40h]
  int v73; // [esp+24h] [ebp-40h]
  int v74; // [esp+24h] [ebp-40h]
  int v75; // [esp+28h] [ebp-3Ch]
  float *v76; // [esp+28h] [ebp-3Ch]
  int v77; // [esp+30h] [ebp-34h]
  int v78; // [esp+30h] [ebp-34h]
  int v79; // [esp+34h] [ebp-30h]
  int n2_1; // [esp+38h] [ebp-2Ch]
  float *v81; // [esp+40h] [ebp-24h]
  float *v82; // [esp+44h] [ebp-20h]
  float *v83; // [esp+48h] [ebp-1Ch]
  int v84; // [esp+4Ch] [ebp-18h]
  float *i; // [esp+50h] [ebp-14h]
  float *v86; // [esp+50h] [ebp-14h]
  float *v87; // [esp+54h] [ebp-10h]
  float *v88; // [esp+54h] [ebp-10h]
  float *v89; // [esp+58h] [ebp-Ch]
  float *v90; // [esp+58h] [ebp-Ch]
  int v91; // [esp+5Ch] [ebp-8h]
  int v92; // [esp+60h] [ebp-4h]

  v7 = a2 * n2;
  v8 = a4;
  v91 = a2;
  n2_1 = n2;
  v92 = a2 * n2;
  result = 4 * n2;
  v84 = 2 * n2;
  if ( a2 > 0 )
  {
    v75 = 16 * n2;
    v72 = &a4[v7];
    v89 = &a4[2 * v7];
    v10 = 3 * v7;
    v11 = a3;
    v87 = &a4[v10];
    v12 = 4 * n2;
    i_1 = &a3[4 * n2 - 1];
    v14 = &a3[2 * n2];
    v77 = v91;
    v15 = v72;
    for ( i = &a3[2 * v84 - 1]; ; i_1 = i )
    {
      v16 = *v11 + *i_1;
      v17 = *v11 - *i_1;
      v18 = v89;
      v89 = (float *)((char *)v89 + v12);
      v19 = *(v14 - 1) + *(v14 - 1);
      v20 = *v14 + *v14;
      *v8 = v16 + v19;
      v8 = (float *)((char *)v8 + v12);
      *v15 = v17 - v20;
      *v18 = v16 - v19;
      v21 = v87;
      v87 = (float *)((char *)v87 + v12);
      *v21 = v17 + v20;
      result = v75;
      i = (float *)((char *)i + v75);
      v15 = (float *)((char *)v15 + v12);
      v14 = (float *)((char *)v14 + v75);
      v11 = (float *)((char *)v11 + v75);
      if ( !--v77 )
        break;
    }
    n2 = n2_1;
    v8 = a4;
    v7 = v92;
    a2 = v91;
  }
  if ( n2 >= 2 )
  {
    if ( n2 == 2 )
      goto LABEL_18;
    v22 = 0;
    v70 = 0;
    if ( a2 > 0 )
    {
      v23 = 0;
      v62 = -3 * n2;
      v79 = 0;
      v78 = 3 * v7;
      v68 = a2;
      do
      {
        v24 = 4 * v22;
        v8 = a4;
        if ( n2 > 2 )
        {
          v88 = &a3[v24 + v84];
          v25 = v88;
          v90 = &a3[4 * v22];
          v86 = &a3[4 * v22 + 2 * n2 + v84];
          v76 = a7;
          v83 = &a4[v24 - v79];
          v82 = &a4[v7 + v24 - v79];
          v26 = &a4[v24 + 2 * v7 - v79];
          v27 = v24 + v78;
          v28 = (float *)(a5 + 4);
          v81 = &a4[v27];
          v73 = a6 - a5;
          v64 = (char *)a7 - a5;
          v29 = a6 - (_DWORD)a7;
          v30 = ((unsigned int)(n2_1 - 3) >> 1) + 1;
          while ( 1 )
          {
            v90 += 2;
            v31 = *(v86 - 2);
            v83 += 2;
            v82 += 2;
            v81 += 2;
            v32 = v25[2];
            v25 += 2;
            v33 = *(v88 - 2);
            v86 -= 2;
            v88 -= 2;
            v34 = *(v86 - 1);
            v35 = *v90 - v31;
            v36 = v32 - v33;
            v37 = v33 + *v25;
            v67 = *v90 + v31;
            v38 = *(v90 - 1) - v34;
            v39 = v34 + *(v90 - 1);
            v40 = *(v88 - 1);
            v41 = *(v25 - 1) - v40;
            v42 = v40 + *(v25 - 1);
            v43 = v39 + v42;
            v44 = v39 - v42;
            *(v83 - 1) = v43;
            *v83 = v36 + v35;
            v65 = v35 - v36;
            v45 = v38 - v37;
            v46 = v38 + v37;
            *(v82 - 1) = (float)(*(v28 - 1) * v45) - (float)(*v28 * (float)(v41 + v67));
            *v82 = (float)(*v28 * v45) + (float)(*(v28 - 1) * (float)(v41 + v67));
            v26[1] = (float)(v44 * *(float *)((char *)v76 + v29)) - (float)(*(float *)((char *)v28 + v73) * v65);
            v26[2] = (float)(*(float *)((char *)v28 + v73) * v44) + (float)(v65 * *(float *)((char *)v76 + v29));
            v47 = *v76 * v46;
            v48 = *(float *)((char *)v28 + (_DWORD)v64) * (float)(v67 - v41);
            v28 += 2;
            v76 += 2;
            *(v81 - 1) = v47 - v48;
            *v81 = (float)(*(float *)((char *)v28 + (_DWORD)v64 - 8) * v46) + (float)(*(v76 - 2) * (float)(v67 - v41));
            if ( !--v30 )
              break;
            v26 += 2;
          }
          n2 = n2_1;
          v8 = a4;
          v7 = v92;
          v23 = v79;
          v22 = v70;
        }
        v23 += 3 * n2;
        v78 += v62;
        v22 += n2;
        v49 = v68-- == 1;
        v70 = v22;
        v79 = v23;
      }
      while ( !v49 );
      a2 = v91;
    }
    result = n2 % 2;
    if ( n2 % 2 != 1 )
    {
LABEL_18:
      if ( a2 > 0 )
      {
        v74 = 16 * n2;
        v50 = 4 * n2;
        v63 = &v8[n2 - 1];
        v51 = &a3[n2];
        v52 = &a3[3 * n2];
        v71 = v51;
        v66 = &v8[2 * v92 - 1 + n2];
        v53 = n2 + 2 * v92 - 1;
        v54 = &v8[n2 - 1 + v92];
        v55 = &v8[v92 + v53];
        v56 = v66;
        v69 = v55;
        result = (int)v63;
        do
        {
          v57 = *(v52 - 1);
          v58 = *v52;
          v52 = (float *)((char *)v52 + v74);
          v59 = *(v51 - 1) - v57;
          v60 = *v51 + v58;
          v61 = v58 - *v51;
          *(float *)result = (float)(v57 + *(v51 - 1)) + (float)(v57 + *(v51 - 1));
          *v54 = (float)(v59 - v60) * 1.4142135;
          *v56 = v61 + v61;
          *v69 = (float)(v60 + v59) * -1.4142135;
          v69 = (float *)((char *)v69 + v50);
          v51 = &v71[v74 / 4u];
          result += v50;
          v54 = (float *)((char *)v54 + v50);
          v56 = (float *)((char *)v56 + v50);
          v49 = v91-- == 1;
          v71 = (float *)((char *)v71 + v74);
        }
        while ( !v49 );
      }
    }
  }
  return result;
}

