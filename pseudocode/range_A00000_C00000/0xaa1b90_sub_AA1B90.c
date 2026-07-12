// Function: sub_AA1B90
// Address: 0xaa1b90
// Size: 0x309
// Prototype: 

_DWORD *__cdecl sub_AA1B90(_DWORD *a1, _DWORD *a2)
{
  int v2; // ebx
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // edi
  int v6; // edx
  unsigned int v7; // ecx
  int v8; // edx
  unsigned int v9; // eax
  int v10; // eax
  int *v11; // edx
  int *v12; // ecx
  int v13; // esi
  int v14; // edi
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  _DWORD *v18; // edi
  int v19; // eax
  int v20; // ebx
  int i_1; // eax
  int *v22; // esi
  char v23; // cl
  int v24; // eax
  int v25; // edx
  _DWORD *v26; // edi
  int v27; // eax
  int v28; // eax
  int v29; // eax
  _DWORD *v30; // ecx
  int v31; // eax
  int v32; // ebx
  int v33; // eax
  int v34; // edx
  int n2_2; // ebx
  int v36; // eax
  int v37; // esi
  int v38; // ecx
  _DWORD *v39; // ecx
  int v41; // [esp+Ch] [ebp-2Ch]
  int v42; // [esp+10h] [ebp-28h]
  int v43; // [esp+14h] [ebp-24h]
  int i; // [esp+14h] [ebp-24h]
  int v45; // [esp+18h] [ebp-20h]
  int v46; // [esp+18h] [ebp-20h]
  int *v47; // [esp+1Ch] [ebp-1Ch]
  int n2_1; // [esp+1Ch] [ebp-1Ch]
  int v49; // [esp+20h] [ebp-18h]
  int v50; // [esp+24h] [ebp-14h]
  int n2; // [esp+28h] [ebp-10h]
  _DWORD *v52; // [esp+28h] [ebp-10h]
  int v53; // [esp+2Ch] [ebp-Ch]
  _DWORD *v54; // [esp+2Ch] [ebp-Ch]
  char v55; // [esp+30h] [ebp-8h]
  int *v56; // [esp+34h] [ebp-4h]
  _DWORD *v57; // [esp+40h] [ebp+8h]

  v2 = (int)(a1 + 1);
  v56 = (int *)a2[324];
  v50 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1[16] + 4) + 28) + 2848);
  v45 = (int)(a1 + 1);
  if ( sub_42EB10(a1 + 1, 1) != 1 )
    return 0;
  v3 = (_DWORD *)sub_A92150(a1, 4 * a2[321]);
  v4 = a2;
  v5 = v3;
  v57 = v3;
  v6 = 0;
  v7 = a2[323] - 1;
  if ( a2[323] != 1 )
  {
    do
    {
      ++v6;
      v7 >>= 1;
    }
    while ( v7 );
  }
  *v3 = sub_42EB10(v2, v6);
  v8 = 0;
  v9 = a2[323] - 1;
  if ( a2[323] != 1 )
  {
    do
    {
      ++v8;
      v9 >>= 1;
    }
    while ( v9 );
  }
  v10 = sub_42EB10(v2, v8);
  v11 = v56;
  v5[1] = v10;
  v49 = 0;
  n2 = 2;
  if ( *v56 > 0 )
  {
    v12 = v56 + 1;
    v47 = v56 + 1;
    do
    {
      v13 = *v12;
      v14 = 0;
      v15 = v11[*v12 + 32];
      v16 = v11[*v12 + 48];
      v53 = v15;
      v17 = 1 << v16;
      v55 = v16;
      v43 = 1 << v16;
      if ( v16 )
      {
        v18 = (_DWORD *)(v50 + 56 * v11[v13 + 64]);
        if ( (int)v18[2] <= 0 )
          return 0;
        v19 = sub_A94200(v18, v2);
        if ( v19 < 0 )
          return 0;
        v14 = *(_DWORD *)(v18[6] + 4 * v19);
        if ( v14 == -1 )
          return 0;
        v17 = v43;
        v11 = v56;
      }
      v20 = 0;
      if ( v53 > 0 )
      {
        v42 = 8 * v13 + 80;
        i_1 = v17 - 1;
        v22 = &v57[n2];
        v23 = v55;
        for ( i = i_1; ; i_1 = i )
        {
          v24 = v42 + (v14 & i_1);
          v14 >>= v23;
          v25 = v11[v24];
          v41 = v14;
          if ( v25 < 0 )
          {
            *v22 = 0;
          }
          else
          {
            v26 = (_DWORD *)(v50 + 56 * v25);
            if ( (int)v26[2] <= 0 || (v27 = sub_A94200(v26, v45), v27 < 0) )
              v28 = -1;
            else
              v28 = *(_DWORD *)(v26[6] + 4 * v27);
            *v22 = v28;
            if ( v28 == -1 )
              return 0;
            v14 = v41;
            v23 = v55;
          }
          v29 = v53;
          v11 = v56;
          ++v20;
          ++v22;
          if ( v20 >= v53 )
            goto LABEL_27;
        }
      }
      v29 = v53;
LABEL_27:
      n2 += v29;
      v2 = v45;
      v12 = v47 + 1;
      ++v49;
      ++v47;
    }
    while ( v49 < *v11 );
    v5 = v57;
    v4 = a2;
  }
  n2_1 = 2;
  if ( (int)v4[321] > 2 )
  {
    v30 = v4 + 195;
    v54 = v4 + 195;
    v52 = v11 + 211;
    do
    {
      v31 = v30[63];
      v46 = v57[v31] & 0x7FFF;
      v32 = (v57[*v30] & 0x7FFF) - v46;
      v33 = (int)((*v52 - v11[v31 + 209]) * abs32(v32)) / (v56[*v30 + 209] - v11[v31 + 209]);
      if ( v32 >= 0 )
        v34 = v33 + v46;
      else
        v34 = v46 - v33;
      n2_2 = n2_1;
      v5 = v57;
      v36 = v57[n2_1];
      v37 = a2[323] - v34;
      if ( v36 )
      {
        v38 = v34;
        if ( v37 < v34 )
          v38 = a2[323] - v34;
        if ( v36 < 2 * v38 )
        {
          if ( (v36 & 1) != 0 )
            v36 = -((v36 + 1) >> 1);
          else
            v36 >>= 1;
        }
        else if ( v37 <= v34 )
        {
          LOWORD(v36) = v37 - v36 - 1;
        }
        else
        {
          LOWORD(v36) = v36 - v34;
        }
        v39 = v54;
        v57[n2_1] = ((_WORD)v34 + (_WORD)v36) & 0x7FFF;
        v57[v54[63]] &= 0x7FFFu;
        v57[*v54] &= 0x7FFFu;
      }
      else
      {
        v39 = v54;
        v57[n2_1] = v34 | 0x8000;
      }
      ++v52;
      v11 = v56;
      v30 = v39 + 1;
      ++n2_1;
      v54 = v30;
    }
    while ( n2_2 + 1 < a2[321] );
  }
  return v5;
}

