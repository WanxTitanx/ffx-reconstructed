// Function: sub_A90A70
// Address: 0xa90a70
// Size: 0x66a
// Prototype: 

int __cdecl sub_A90A70(int a1, int a2)
{
  int *v2; // esi
  _DWORD *v3; // edi
  _DWORD *v4; // ebx
  int v6; // eax
  unsigned int v7; // edx
  unsigned int v8; // ecx
  int v9; // ebx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  float *v13; // ecx
  int v14; // eax
  int v15; // esi
  int v16; // eax
  float *v17; // edx
  int v18; // ebx
  float v19; // xmm0_4
  float v20; // xmm1_4
  int v21; // ebx
  float *v22; // ecx
  int v23; // eax
  int v24; // esi
  float *v25; // edx
  int v26; // ebx
  float v27; // xmm0_4
  float v28; // xmm1_4
  int v29; // eax
  int v30; // esi
  int v31; // ecx
  int v32; // ebx
  int v33; // edi
  float *v34; // edx
  float *v35; // ecx
  int v36; // edi
  int v37; // esi
  float v38; // xmm0_4
  float v39; // xmm1_4
  int v40; // esi
  _DWORD *v41; // edx
  _DWORD *v42; // ecx
  unsigned int v43; // ebx
  _DWORD *v44; // ecx
  int v45; // esi
  int v46; // ebx
  float *v47; // ecx
  int v48; // eax
  int v49; // esi
  float *v50; // edx
  int v51; // ebx
  float v52; // xmm0_4
  float v53; // xmm1_4
  int n4_1; // edx
  int v55; // esi
  int v56; // ebx
  int n4_2; // eax
  _DWORD *v58; // ecx
  int v59; // edi
  unsigned int v60; // esi
  _DWORD *v61; // edx
  int v62; // ebx
  _DWORD *v63; // ecx
  int v64; // edx
  int v65; // eax
  bool v66; // zf
  int v67; // eax
  int v68; // ebx
  unsigned int v69; // edx
  int v70; // esi
  int v71; // eax
  unsigned int v72; // esi
  int v73; // edx
  unsigned int v74; // ecx
  int v75; // eax
  int v76; // esi
  int v77; // [esp+14h] [ebp-40h]
  int v78; // [esp+14h] [ebp-40h]
  int v79; // [esp+18h] [ebp-3Ch]
  int v80; // [esp+18h] [ebp-3Ch]
  int v81; // [esp+1Ch] [ebp-38h]
  int n4_3; // [esp+1Ch] [ebp-38h]
  int v83; // [esp+20h] [ebp-34h]
  int v84; // [esp+24h] [ebp-30h]
  int v85; // [esp+24h] [ebp-30h]
  int v86; // [esp+24h] [ebp-30h]
  int v87; // [esp+28h] [ebp-2Ch]
  int v88; // [esp+2Ch] [ebp-28h]
  int n4; // [esp+30h] [ebp-24h]
  int v90; // [esp+34h] [ebp-20h]
  int v91; // [esp+38h] [ebp-1Ch]
  int v92; // [esp+38h] [ebp-1Ch]
  int *v93; // [esp+3Ch] [ebp-18h]
  int v94; // [esp+40h] [ebp-14h]
  _DWORD *v95; // [esp+44h] [ebp-10h]
  int v96; // [esp+48h] [ebp-Ch]
  int v97; // [esp+4Ch] [ebp-8h]
  int v98; // [esp+50h] [ebp-4h]

  v2 = (int *)a2;
  v3 = (_DWORD *)a1;
  v4 = *(_DWORD **)(a1 + 104);
  v83 = *(_DWORD *)(a1 + 4);
  v93 = *(int **)(v83 + 28);
  v95 = v4;
  v98 = v93[914];
  if ( !a2 )
    return -131;
  v6 = *(_DWORD *)(a1 + 24);
  if ( *(_DWORD *)(a1 + 20) > v6 && v6 != -1 )
    return -131;
  v7 = *(_DWORD *)(a1 + 64);
  v8 = *(_DWORD *)(a1 + 68);
  *(_DWORD *)(a1 + 36) = *(_DWORD *)(a1 + 40);
  *(_DWORD *)(a1 + 40) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(a1 + 44) = -1;
  if ( (v8 & v7) == 0xFFFFFFFF || __PAIR64__(v8, v7) + 1 != *(_QWORD *)(a2 + 56) )
  {
    *(_DWORD *)(a1 + 56) = -1;
    *(_DWORD *)(a1 + 60) = -1;
    v4[32] = -1;
    v4[33] = -1;
  }
  *(_DWORD *)(a1 + 64) = *(_DWORD *)(a2 + 56);
  *(_DWORD *)(a1 + 68) = *(_DWORD *)(a2 + 60);
  if ( *(_DWORD *)a2 )
  {
    v9 = *v93 >> (v98 + 1);
    n4 = v93[*(_DWORD *)(a1 + 40)] >> (v98 + 1);
    v97 = v9;
    v90 = v93[1] >> (v98 + 1);
    *(_QWORD *)(a1 + 72) += *(int *)(a2 + 88);
    *(_QWORD *)(a1 + 80) += *(int *)(a2 + 92);
    *(_QWORD *)(a1 + 88) += *(int *)(a2 + 96);
    *(_QWORD *)(a1 + 96) += *(int *)(a2 + 100);
    v10 = v90;
    if ( *(_DWORD *)(a1 + 48) )
    {
      v88 = v90;
      v94 = 0;
    }
    else
    {
      v88 = 0;
      v94 = v90;
    }
    v11 = 0;
    v96 = 0;
    if ( *(int *)(v83 + 4) > 0 )
    {
      while ( !v3[9] )
      {
        v29 = v95[1] - v98;
        if ( !v3[10] )
        {
          v46 = (int)*(&off_B899B8 + v29);
          v47 = (float *)(*(_DWORD *)(v3[2] + 4 * v11) + 4 * v94);
          v48 = *(_DWORD *)(*v2 + 4 * v96);
          if ( v97 <= 0 )
            goto LABEL_43;
          v49 = v97;
          v50 = (float *)(v46 + 4 * (v97 - 1));
          v78 = v48 - v46;
          v51 = v46 - (_DWORD)v47;
          do
          {
            v52 = *v47 * *v50--;
            v53 = *(float *)((char *)v47 + v51 + v78) * *(float *)((char *)v47 + v51);
            *v47++ = v53 + v52;
            --v49;
          }
          while ( v49 );
          goto LABEL_42;
        }
        v30 = *(_DWORD *)(v3[2] + 4 * v11) + 4 * v94;
        v77 = v9 / 2;
        v79 = v10 / 2;
        v31 = v10 / 2 - v9 / 2;
        v32 = 0;
        v87 = v30;
        v86 = *(_DWORD *)(*(_DWORD *)a2 + 4 * v96) + 4 * v31;
        v91 = 0;
        if ( v97 > 0 )
        {
          v33 = (int)*(&off_B899B8 + v29);
          v81 = *(_DWORD *)(*(_DWORD *)a2 + 4 * v96) + 4 * v31 - v33;
          v34 = (float *)(v33 + 4 * (v97 - 1));
          v35 = (float *)v30;
          v36 = v33 - v30;
          v37 = v97;
          v91 = v97;
          do
          {
            v38 = *v35 * *v34--;
            v39 = *(float *)((char *)v35 + v36 + v81) * *(float *)((char *)v35 + v36);
            *v35++ = v39 + v38;
            --v37;
          }
          while ( v37 );
          v3 = (_DWORD *)a1;
          v32 = v97;
        }
        v40 = v79 + v77;
        if ( v32 < v79 + v77 )
        {
          if ( v40 - v32 >= 4 )
          {
            v41 = (_DWORD *)(v86 + 12 + 4 * v32);
            v42 = (_DWORD *)(v87 + 4 * (v32 + 1));
            v43 = ((unsigned int)(v40 - v91 - 4) >> 2) + 1;
            v92 = v91 + 4 * v43;
            do
            {
              *(v42 - 1) = *(v41 - 3);
              *v42 = *(_DWORD *)((char *)v42 + v86 - v87);
              v42[1] = *(v41 - 1);
              v42[2] = *v41;
              v42 += 4;
              v41 += 4;
              --v43;
            }
            while ( v43 );
            v3 = (_DWORD *)a1;
            v32 = v92;
          }
          if ( v32 < v40 )
          {
            v44 = (_DWORD *)(v87 + 4 * v32);
            v45 = v40 - v32;
            do
            {
              *v44 = *(_DWORD *)((char *)v44 + v86 - v87);
              ++v44;
              --v45;
            }
            while ( v45 );
LABEL_42:
            v3 = (_DWORD *)a1;
          }
        }
LABEL_43:
        n4_1 = n4;
        v55 = 4 * v88 + *(_DWORD *)(v3[2] + 4 * v96);
        v80 = v55;
        v56 = 4 * n4 + *(_DWORD *)(*(_DWORD *)a2 + 4 * v96);
        n4_2 = 0;
        if ( n4 >= 4 )
        {
          v58 = (_DWORD *)(v55 + 4);
          v59 = v56 - v55;
          v60 = ((unsigned int)(n4 - 4) >> 2) + 1;
          v61 = (_DWORD *)(v56 + 12);
          n4_3 = 4 * v60;
          do
          {
            *(v58 - 1) = *(v61 - 3);
            *v58 = *(_DWORD *)((char *)v58 + v59);
            v58[1] = *(v61 - 1);
            v58[2] = *v61;
            v58 += 4;
            v61 += 4;
            --v60;
          }
          while ( v60 );
          v3 = (_DWORD *)a1;
          v55 = v80;
          n4_2 = n4_3;
          n4_1 = n4;
        }
        if ( n4_2 < n4_1 )
        {
          v62 = v56 - v55;
          v63 = (_DWORD *)(v55 + 4 * n4_2);
          v64 = n4_1 - n4_2;
          do
          {
            *v63 = *(_DWORD *)((char *)v63 + v62);
            ++v63;
            --v64;
          }
          while ( v64 );
        }
        v9 = v97;
        v11 = v96 + 1;
        v96 = v11;
        if ( v11 >= *(_DWORD *)(v83 + 4) )
          goto LABEL_51;
        v2 = (int *)a2;
        v10 = v90;
      }
      if ( v3[10] )
      {
        v12 = (int)*(&off_B899B8 + v95[2] - v98);
        v13 = (float *)(*(_DWORD *)(v3[2] + 4 * v11) + 4 * v94);
        v14 = *v2;
        v15 = v90;
        v16 = *(_DWORD *)(v14 + 4 * v96);
        if ( v90 <= 0 )
          goto LABEL_43;
        v17 = (float *)(v12 + 4 * (v90 - 1));
        v84 = v16 - v12;
        v18 = v12 - (_DWORD)v13;
        do
        {
          v19 = *v17-- * *v13;
          v20 = *(float *)((char *)v13 + v18 + v84) * *(float *)((char *)v13 + v18);
          *v13++ = v20 + v19;
          --v15;
        }
        while ( v15 );
      }
      else
      {
        v21 = (int)*(&off_B899B8 + v95[1] - v98);
        v22 = (float *)(*(_DWORD *)(v3[2] + 4 * v96) + 4 * (v94 + v10 / 2 - v97 / 2));
        v23 = *(_DWORD *)(*v2 + 4 * v96);
        if ( v97 <= 0 )
          goto LABEL_43;
        v24 = v97;
        v25 = (float *)(v21 + 4 * (v97 - 1));
        v85 = v23 - v21;
        v26 = v21 - (_DWORD)v22;
        do
        {
          v27 = *v22 * *v25--;
          v28 = *(float *)((char *)v22 + v26 + v85) * *(float *)((char *)v22 + v26);
          *v22++ = v28 + v27;
          --v24;
        }
        while ( v24 );
      }
      goto LABEL_42;
    }
LABEL_51:
    v65 = v90;
    if ( v3[12] )
      v65 = 0;
    v66 = v3[6] == -1;
    v3[12] = v65;
    if ( v66 )
    {
      v3[6] = v88;
      v3[5] = v88;
    }
    else
    {
      v67 = v3[10];
      v3[6] = v94;
      v3[5] = v94 + ((v93[v3[9]] / 4 + v93[v67] / 4) >> v98);
    }
  }
  if ( (v95[33] & v95[32]) == -1 )
  {
    v95[32] = 0;
    v95[33] = 0;
  }
  else
  {
    *((_QWORD *)v95 + 16) += v93[v3[10]] / 4 + v93[v3[9]] / 4;
  }
  if ( (v3[15] & v3[14]) == -1 )
  {
    v68 = a2;
    v69 = *(_DWORD *)(a2 + 52);
    if ( (v69 & *(_DWORD *)(a2 + 48)) != 0xFFFFFFFF )
    {
      v3[14] = *(_DWORD *)(a2 + 48);
      v3[15] = v69;
      if ( *((_QWORD *)v95 + 16) > __SPAIR64__(v69, v3[14]) )
      {
        v70 = v95[32] - *(_DWORD *)(a2 + 48);
        if ( v70 < 0 )
          v70 = 0;
        if ( *(_DWORD *)(a2 + 44) )
        {
          if ( v70 > (v3[5] - v3[6]) << v98 )
            v70 = (v3[5] - v3[6]) << v98;
          v3[5] -= v70 >> v98;
        }
        else
        {
          v71 = v3[5];
          v3[6] += v70 >> v98;
          if ( v3[6] > v71 )
            v3[6] = v71;
        }
      }
    }
  }
  else
  {
    v68 = a2;
    *((_QWORD *)v3 + 7) += v93[v3[10]] / 4 + v93[v3[9]] / 4;
    v72 = *(_DWORD *)(a2 + 48);
    v73 = *(_DWORD *)(a2 + 52);
    if ( (v73 & v72) != 0xFFFFFFFF )
    {
      v74 = v3[14];
      v75 = v3[15];
      if ( v74 != v72 || v75 != v73 )
      {
        if ( v75 >= v73 && (v75 > v73 || v74 > v72) )
        {
          v76 = v74 - *(_DWORD *)(a2 + 48);
          if ( v74 != *(_DWORD *)(a2 + 48) )
          {
            if ( *(_DWORD *)(a2 + 44) )
            {
              if ( v76 > (v3[5] - v3[6]) << v98 )
                v76 = (v3[5] - v3[6]) << v98;
              if ( v76 < 0 )
                v76 = 0;
              v3[5] -= v76 >> v98;
            }
          }
        }
        v3[14] = *(_DWORD *)(a2 + 48);
        v3[15] = *(_DWORD *)(a2 + 52);
      }
    }
  }
  if ( *(_DWORD *)(v68 + 44) )
    v3[8] = 1;
  return 0;
}

