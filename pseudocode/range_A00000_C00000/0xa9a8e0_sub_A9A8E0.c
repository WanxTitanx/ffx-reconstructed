// Function: sub_A9A8E0
// Address: 0xa9a8e0
// Size: 0x452
// Prototype: 

int __fastcall sub_A9A8E0(int n2_2, float *a2, int a3, float *a4, int a5, int a6, float *a7)
{
  int result; // eax
  int n2; // edx
  int v9; // ecx
  float *v10; // esi
  int v11; // ebx
  int v12; // edi
  float *v13; // ecx
  int v14; // eax
  float v15; // xmm2_4
  float v16; // xmm1_4
  int v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm0_4
  bool v20; // zf
  int v21; // ebx
  int v22; // eax
  unsigned int v23; // eax
  float *v24; // edx
  int v25; // ecx
  float *v26; // ebx
  float v27; // xmm5_4
  float v28; // xmm4_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm5_4
  float v32; // xmm4_4
  float v33; // xmm7_4
  float v34; // xmm4_4
  float v35; // xmm7_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm4_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm6_4
  float v42; // xmm5_4
  float v43; // xmm0_4
  float v44; // xmm4_4
  float v45; // xmm3_4
  int v46; // ecx
  float *v47; // ebx
  float *v48; // edx
  float *v49; // esi
  float *v50; // edi
  float v51; // xmm2_4
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  float v55; // xmm0_4
  int v56; // [esp+Ch] [ebp-5Ch]
  int v57; // [esp+Ch] [ebp-5Ch]
  int n2_1; // [esp+10h] [ebp-58h]
  float *v59; // [esp+14h] [ebp-54h]
  float v60; // [esp+14h] [ebp-54h]
  float *v61; // [esp+1Ch] [ebp-4Ch]
  float *v62; // [esp+1Ch] [ebp-4Ch]
  int v63; // [esp+20h] [ebp-48h]
  int v64; // [esp+24h] [ebp-44h]
  int v65; // [esp+28h] [ebp-40h]
  float *v66; // [esp+28h] [ebp-40h]
  float *v67; // [esp+28h] [ebp-40h]
  float *v68; // [esp+2Ch] [ebp-3Ch]
  float *v69; // [esp+30h] [ebp-38h]
  int v70; // [esp+34h] [ebp-34h]
  float *v71; // [esp+38h] [ebp-30h]
  float *v72; // [esp+3Ch] [ebp-2Ch]
  float *v73; // [esp+40h] [ebp-28h]
  float v74; // [esp+44h] [ebp-24h]
  float v75; // [esp+44h] [ebp-24h]
  float *v76; // [esp+48h] [ebp-20h]
  float *v77; // [esp+4Ch] [ebp-1Ch]
  float *v78; // [esp+50h] [ebp-18h]
  float *v79; // [esp+54h] [ebp-14h]
  float *v80; // [esp+54h] [ebp-14h]
  float *v81; // [esp+58h] [ebp-10h]
  float *v82; // [esp+58h] [ebp-10h]
  float *v83; // [esp+5Ch] [ebp-Ch]
  float v84; // [esp+5Ch] [ebp-Ch]
  int v85; // [esp+5Ch] [ebp-Ch]
  float *v86; // [esp+60h] [ebp-8h]
  int v87; // [esp+64h] [ebp-4h]

  result = (int)a2;
  n2 = n2_2;
  v9 = result * n2_2;
  v10 = a4;
  v11 = 0;
  v12 = a3;
  v86 = (float *)result;
  n2_1 = n2;
  v87 = v9;
  if ( result > 0 )
  {
    v13 = (float *)(a3 + 4 * v9);
    v79 = v13;
    v81 = (float *)(a3 + 12 * v87);
    v83 = (float *)(a3 + 8 * v87);
    v65 = result;
    v14 = 4 * n2;
    do
    {
      v15 = *v81 + *v13;
      v10 = a4;
      v16 = *(float *)(a3 + 4 * v11) + *v83;
      a4[4 * v11] = v16 + v15;
      a4[4 * v11 - 1 + v14] = v16 - v15;
      v17 = 4 * v11 + 2 * n2;
      v18 = *(float *)(a3 + 4 * v11) - *v83;
      v11 += n2;
      a4[v17 - 1] = v18;
      v19 = *v81 - *v79;
      v14 = 4 * n2;
      v83 += n2;
      v81 += n2;
      a4[v17] = v19;
      v13 = &v79[n2];
      v20 = v65-- == 1;
      v79 = v13;
    }
    while ( !v20 );
    v9 = v87;
    result = (int)v86;
  }
  if ( n2 >= 2 )
  {
    if ( n2 == 2 )
      goto LABEL_16;
    v21 = 0;
    v70 = 0;
    if ( result > 0 )
    {
      v56 = 16 * n2;
      v69 = v10;
      v66 = (float *)(a3 + 12 * v9);
      v68 = (float *)(a3 + 4 * v9);
      v61 = v86;
      do
      {
        v22 = 4 * v21 + 2 * n2;
        if ( n2 > 2 )
        {
          v59 = &v10[v22];
          v72 = &v10[2 * n2 + v22];
          v76 = v69;
          v71 = a7;
          v80 = v68;
          v73 = &v10[4 * v21 + 2 * n2];
          v77 = (float *)(4 * v21 + v12);
          v82 = (float *)(v12 + 4 * (v70 + 2 * v87));
          v23 = n2 - 3;
          v24 = (float *)(a5 + 4);
          v78 = v66;
          v25 = a6 - (_DWORD)a7;
          v26 = v59;
          v64 = (v23 >> 1) + 1;
          do
          {
            v80 += 2;
            v82 += 2;
            v78 += 2;
            v27 = *(v24 - 1);
            v28 = (float)(v27 * *v80) - (float)(*v24 * *(v80 - 1));
            v29 = *(v82 - 1);
            v30 = *(float *)((char *)v24 + a6 - a5);
            v31 = (float)(v27 * *(v80 - 1)) + (float)(*v80 * *v24);
            v84 = v28;
            v77 += 2;
            v32 = *(float *)((char *)v71 + v25);
            v33 = v32 * *v82;
            v34 = (float)(v32 * v29) + (float)(v30 * *v82);
            v76 += 2;
            v73 += 2;
            v35 = v33 - (float)(v30 * v29);
            v36 = *(float *)((char *)v24 + (_DWORD)a7 - a5);
            v60 = v34;
            v37 = *(v77 - 1);
            v38 = (float)(*v78 * *v71) - (float)(v36 * *(v78 - 1));
            v74 = (float)(*(v78 - 1) * *v71) + (float)(v36 * *v78);
            v39 = v37 + v60;
            v40 = v37 - v60;
            v41 = v74 + v31;
            v75 = v74 - v31;
            v42 = v38 + v84;
            v43 = v84 - v38;
            v44 = *v77 + v35;
            v26 -= 2;
            v72 -= 2;
            v45 = *v77 - v35;
            *(v76 - 1) = v39 + v41;
            *v76 = v44 + v42;
            *(v26 - 1) = v40 - v43;
            *v26 = v75 - v45;
            v71 += 2;
            v25 = a6 - (_DWORD)a7;
            *(v73 - 1) = v40 + v43;
            v24 += 2;
            v20 = v64-- == 1;
            *v73 = v45 + v75;
            *(v72 - 1) = v39 - v41;
            *v72 = v42 - v44;
          }
          while ( !v20 );
          n2 = n2_1;
          v10 = a4;
          v12 = a3;
          v21 = v70;
          v9 = v87;
        }
        v69 = (float *)((char *)v69 + v56);
        v68 += n2;
        v66 += n2;
        v21 += n2;
        v20 = v61 == (float *)1;
        v61 = (float *)((char *)v61 - 1);
        v70 = v21;
      }
      while ( !v20 );
      result = (int)v86;
    }
    if ( (n2 & 1) == 0 )
    {
LABEL_16:
      v85 = v9 + n2 - 1;
      v57 = v85 + 2 * v9;
      if ( result > 0 )
      {
        v63 = 16 * n2;
        v46 = 4 * n2;
        v67 = (float *)(v12 + 4 * v57);
        v47 = &v10[n2];
        v62 = (float *)(v12 + 4 * v85);
        v48 = &v10[3 * n2];
        result = v12 + 4 * (v87 + v85);
        v49 = (float *)(v12 + 4 * (v85 - v87));
        v50 = v67;
        do
        {
          v51 = *v62;
          v62 = (float *)((char *)v62 + v46);
          v52 = (float)(v51 - *v50) * 0.70710677;
          v53 = (float)(v51 + *v50) * -0.70710677;
          v50 = &v67[v46 / 4u];
          v67 = (float *)((char *)v67 + v46);
          *(v47 - 1) = *v49 + v52;
          v54 = *v49 - v52;
          v49 = (float *)((char *)v49 + v46);
          *(v48 - 1) = v54;
          *v47 = v53 - *(float *)result;
          v47 = (float *)((char *)v47 + v63);
          v55 = *(float *)result + v53;
          result += v46;
          *v48 = v55;
          v48 = (float *)((char *)v48 + v63);
          v86 = (float *)((char *)v86 - 1);
        }
        while ( v86 );
      }
    }
  }
  return result;
}

