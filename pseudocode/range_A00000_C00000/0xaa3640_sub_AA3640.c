// Function: sub_AA3640
// Address: 0xaa3640
// Size: 0x62f
// Prototype: int __cdecl(int, int, void *)

int __fastcall sub_AA3640(int a1, int k_2, _DWORD *a3, int *a4, _DWORD *a5)
{
  _DWORD *v7; // ecx
  int v8; // eax
  int *v9; // edx
  int n2; // ebx
  int *v11; // eax
  int n2_3; // edi
  int v13; // ecx
  int v14; // esi
  int v15; // esi
  int v16; // edi
  int *v17; // esi
  int *v18; // ecx
  int v19; // eax
  int v20; // ecx
  int v21; // ebx
  int v22; // edi
  int v23; // edi
  int v24; // eax
  bool v25; // sf
  int v26; // edi
  int v27; // edx
  int v28; // ebx
  int v29; // ecx
  int v30; // esi
  int v31; // ecx
  int v32; // ecx
  char *v33; // eax
  bool v34; // zf
  int v35; // ecx
  int v36; // edx
  unsigned int i_1; // ecx
  unsigned int i; // eax
  int j; // eax
  int v40; // esi
  int v41; // ecx
  unsigned int v42; // eax
  int *v43; // eax
  bool v44; // cc
  int *v45; // edx
  int v46; // esi
  int v47; // edi
  int v48; // ecx
  int v49; // edx
  int v50; // ebx
  int v51; // ecx
  int v52; // edi
  int *v53; // esi
  int v54; // esi
  int v55; // ecx
  int *v56; // edi
  int v57; // eax
  int v58; // eax
  int v59; // eax
  int v60; // esi
  int v61; // eax
  int v62; // eax
  char *v63; // eax
  int v64; // edi
  int v65; // ecx
  int *v66; // edx
  int v67; // ecx
  int v68; // esi
  _DWORD *v69; // ebx
  int v70; // eax
  int v71; // eax
  int *v72; // ecx
  int n2_2; // esi
  int v74; // edi
  int v75; // ebx
  int *v76; // eax
  int v77; // edx
  int v78; // eax
  int v79; // ecx
  int v80; // edi
  int v81; // eax
  int v82; // ecx
  int v83; // edx
  int v84; // eax
  int v85; // ecx
  int v86; // eax
  int k; // ecx
  int v89; // [esp-8h] [ebp-18Ch]
  int v90; // [esp+Ch] [ebp-178h] BYREF
  int v91; // [esp+10h] [ebp-174h]
  _DWORD v92[8]; // [esp+110h] [ebp-74h] BYREF
  _DWORD v93[8]; // [esp+130h] [ebp-54h] BYREF
  int k_1; // [esp+150h] [ebp-34h]
  int v95; // [esp+154h] [ebp-30h]
  int v96; // [esp+158h] [ebp-2Ch]
  int v97; // [esp+15Ch] [ebp-28h]
  char *v98; // [esp+160h] [ebp-24h]
  int v99; // [esp+164h] [ebp-20h]
  int *v100; // [esp+168h] [ebp-1Ch]
  int v101; // [esp+16Ch] [ebp-18h]
  int *v102; // [esp+170h] [ebp-14h]
  int v103; // [esp+174h] [ebp-10h]
  int *v104; // [esp+178h] [ebp-Ch]
  int n2_1; // [esp+17Ch] [ebp-8h]
  int v106; // [esp+180h] [ebp-4h]

  v7 = a3;
  v8 = *(_DWORD *)(*(_DWORD *)(k_2 + 64) + 4);
  v9 = (int *)a3[324];
  n2 = a3[321];
  v97 = *(_DWORD *)(v8 + 28);
  v96 = *(_DWORD *)(v97 + 2848);
  v11 = a4;
  k_1 = k_2;
  v95 = a1;
  v104 = v9;
  if ( a4 )
  {
    n2_3 = 0;
    if ( n2 > 0 )
    {
      do
      {
        v13 = v11[n2_3];
        v14 = v13 & 0x7FFF;
        switch ( v9[208] )
        {
          case 1:
            v14 >>= 2;
            break;
          case 2:
            v14 >>= 3;
            break;
          case 3:
            v14 = (v13 & 0x7FFF) / 12;
            v9 = v104;
            break;
          case 4:
            v14 >>= 4;
            break;
          default:
            break;
        }
        v11 = a4;
        a4[n2_3++] = v14 | v13 & 0x8000;
      }
      while ( n2_3 < n2 );
      v7 = a3;
    }
    v15 = *v11;
    v16 = v11[1];
    v90 = *v11;
    v91 = v16;
    if ( n2 > 2 )
    {
      v17 = a4;
      v18 = v7 + 195;
      v101 = (int)(a4 + 2);
      n2_1 = (int)(v9 + 211);
      v106 = (int)v18;
      v98 = (char *)((char *)&v90 - (char *)a4);
      v102 = (int *)(n2 - 2);
      while ( 1 )
      {
        v19 = v18[63];
        v20 = *v18;
        v21 = v9[v19 + 209];
        v22 = v17[v20];
        v100 = &v17[v19];
        v103 = *v100 & 0x7FFF;
        v23 = (v22 & 0x7FFF) - v103;
        v99 = (int)&v17[v20];
        v24 = (int)((*(_DWORD *)n2_1 - v21) * abs32(v23)) / (v104[v20 + 209] - v21);
        v25 = v23 < 0;
        v26 = v103;
        v27 = v25 ? v103 - v24 : v24 + v103;
        v28 = v101;
        v29 = *(_DWORD *)v101;
        if ( (*(_DWORD *)v101 & 0x8000) != 0 || v27 == v29 )
        {
          v33 = v98;
          *(_DWORD *)v101 = v27 | 0x8000;
          *(_DWORD *)&v33[v28] = 0;
        }
        else
        {
          v30 = v27;
          if ( a3[323] - v27 < v27 )
            v30 = a3[323] - v27;
          v31 = v29 - v27;
          if ( v31 >= 0 )
            v32 = v31 < v30 ? 2 * v31 : v30 + v31;
          else
            v32 = v31 >= -v30 ? -1 - 2 * v31 : v30 - v31 - 1;
          *(_DWORD *)&v98[v101] = v32;
          *v100 = v26;
          *(_DWORD *)v99 &= 0x7FFFu;
        }
        n2_1 += 4;
        v17 = a4;
        v18 = (int *)(v106 + 4);
        v34 = v102 == (int *)1;
        v102 = (int *)((char *)v102 - 1);
        v106 += 4;
        v101 = v28 + 4;
        if ( v34 )
          break;
        v9 = v104;
      }
      v16 = v91;
      v15 = v90;
    }
    sub_42E350(v95, 1, 1);
    v35 = a3[323];
    ++a3[327];
    v36 = 0;
    i_1 = v35 - 1;
    for ( i = i_1; i; i >>= 1 )
      ++v36;
    a3[326] += 2 * v36;
    for ( j = 0; i_1; i_1 >>= 1 )
      ++j;
    v89 = v15;
    v40 = v95;
    sub_42E350(v95, v89, j);
    v41 = 0;
    v42 = a3[323] - 1;
    if ( a3[323] != 1 )
    {
      do
      {
        ++v41;
        v42 >>= 1;
      }
      while ( v42 );
    }
    sub_42E350(v40, v16, v41);
    v43 = v104;
    v44 = *v104 <= 0;
    v101 = 0;
    n2_1 = 2;
    if ( !v44 )
    {
      v45 = v104 + 1;
      v100 = v104 + 1;
      do
      {
        v46 = *v45;
        v47 = v43[*v45 + 32];
        v48 = v43[*v45 + 48];
        v49 = 1 << v48;
        v50 = 0;
        v103 = v46;
        v98 = (char *)v47;
        v99 = 1 << v48;
        memset(v92, 0, sizeof(v92));
        v106 = 0;
        if ( v48 )
        {
          v51 = 0;
          memset(v93, 0, sizeof(v93));
          if ( v49 > 0 )
          {
            v52 = v97;
            v53 = &v104[8 * v46 + 80];
            do
            {
              if ( *v53 >= 0 )
                v93[v51] = *(_DWORD *)(*(_DWORD *)(v52 + 4 * *v53 + 1824) + 4);
              else
                v93[v51] = 1;
              ++v51;
              ++v53;
            }
            while ( v51 < v49 );
            v47 = (int)v98;
          }
          v54 = 0;
          if ( v47 <= 0 )
          {
            v59 = v103;
          }
          else
          {
            v55 = 0;
            v56 = &v90 + n2_1;
            do
            {
              v57 = 0;
              if ( v49 > 0 )
              {
                while ( *v56 >= v93[v57] )
                {
                  if ( ++v57 >= v49 )
                    goto LABEL_54;
                }
                v92[v54] = v57;
LABEL_54:
                v55 = v106;
              }
              v58 = v92[v54++] << v55;
              ++v56;
              v50 |= v58;
              v59 = v103;
              v55 += v104[v103 + 48];
              v49 = v99;
              v106 = v55;
            }
            while ( v54 < (int)v98 );
          }
          v60 = v96 + 56 * v104[v59 + 64];
          if ( v50 < 0 || (v61 = *(_DWORD *)(v60 + 12), v50 >= *(_DWORD *)(v61 + 4)) )
          {
            v62 = 0;
          }
          else
          {
            sub_42E350(v95, *(_DWORD *)(*(_DWORD *)(v60 + 20) + 4 * v50), *(char *)(*(_DWORD *)(v61 + 8) + v50));
            v62 = *(char *)(*(_DWORD *)(*(_DWORD *)(v60 + 12) + 8) + v50);
          }
          v46 = v103;
          a3[325] += v62;
        }
        v63 = v98;
        v64 = 0;
        if ( (int)v98 > 0 )
        {
          v65 = 8 * v46 + 80;
          v66 = &v90 + n2_1;
          v99 = v65;
          v102 = v66;
          do
          {
            v67 = v104[v65 + v92[v64]];
            if ( v67 >= 0 )
            {
              v68 = *v66;
              v69 = (_DWORD *)(v96 + 56 * v67);
              if ( *v66 < v69[1] )
              {
                if ( v68 < 0 || (v70 = v69[3], v68 >= *(_DWORD *)(v70 + 4)) )
                {
                  v71 = 0;
                }
                else
                {
                  sub_42E350(v95, *(_DWORD *)(v69[5] + 4 * v68), *(char *)(*(_DWORD *)(v70 + 8) + v68));
                  v66 = v102;
                  v71 = *(char *)(*(_DWORD *)(v69[3] + 8) + v68);
                }
                a3[326] += v71;
              }
            }
            v63 = v98;
            v65 = v99;
            ++v64;
            v102 = ++v66;
          }
          while ( v64 < (int)v98 );
        }
        n2_1 += (int)v63;
        v43 = v104;
        v45 = v100 + 1;
        ++v101;
        ++v100;
      }
      while ( v101 < *v104 );
    }
    v72 = a4;
    n2_2 = *a4 * v43[208];
    v99 = *(_DWORD *)(v97 + 4 * *(_DWORD *)(k_1 + 28)) / 2;
    v74 = 1;
    v75 = 0;
    v106 = 0;
    v96 = 1;
    if ( (int)a3[321] > 1 )
    {
      v76 = a3 + 66;
      v102 = a3 + 66;
      do
      {
        v77 = *v76;
        v78 = v72[*v76];
        v79 = v78 & 0x7FFF;
        if ( v79 == v78 )
        {
          v75 = v104[v77 + 209];
          n2_1 = v79 * v104[208];
          v103 = abs32(n2_1 - n2_2);
          v80 = v75 - v106;
          v81 = (n2_1 - n2_2) / (v75 - v106);
          v100 = (int *)v75;
          v101 = v81;
          v82 = v81 - 1;
          if ( n2_1 - n2_2 >= 0 )
            v82 = v81 + 1;
          v103 -= abs32(v80 * v81);
          v83 = v99;
          v84 = v106;
          v97 = v82;
          v85 = 0;
          if ( v99 > v75 )
            v83 = v75;
          if ( v106 < v83 )
          {
            a5[v106] = n2_2;
            v75 = (int)v100;
            v84 = v106;
          }
          v86 = v84 + 1;
          if ( v86 < v83 )
          {
            do
            {
              v85 += v103;
              if ( v85 < v80 )
              {
                n2_2 += v101;
              }
              else
              {
                v85 -= v80;
                n2_2 += v97;
              }
              a5[v86++] = n2_2;
            }
            while ( v86 < v83 );
            v75 = (int)v100;
          }
          n2_2 = n2_1;
          v74 = v96;
          v106 = v75;
        }
        ++v74;
        v76 = v102 + 1;
        v44 = v74 < a3[321];
        v72 = a4;
        v96 = v74;
        ++v102;
      }
      while ( v44 );
    }
    for ( k = k_1; v75 < *(_DWORD *)(k + 36) / 2; a5[v75 - 1] = n2_2 )
      ++v75;
    return 1;
  }
  else
  {
    sub_42E350(a1, 0, 1);
    memset(a5, 0, 4 * (*(_DWORD *)(k_2 + 36) / 2));
    return 0;
  }
}

