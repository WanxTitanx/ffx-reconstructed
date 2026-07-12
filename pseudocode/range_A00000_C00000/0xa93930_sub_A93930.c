// Function: sub_A93930
// Address: 0xa93930
// Size: 0x367
// Prototype: 

int __fastcall sub_A93930(_DWORD *a1, char *buf, _DWORD *a3, int a4)
{
  _DWORD *v4; // edi
  int v5; // esi
  _DWORD *v6; // ebx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // edx
  unsigned int v14; // edx
  unsigned int v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // ecx
  int v18; // edx
  int v19; // eax
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  int v23; // ebx
  int v24; // edi
  int v25; // edx
  int v26; // ecx
  int v27; // eax
  int v28; // ecx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // edx
  int v33; // ecx
  char *v34; // edx
  int v35; // ecx
  int v36; // ecx
  int v37; // ecx
  _DWORD *v38; // edx
  int v40; // edx
  int v41; // edi
  int v42; // esi
  int v44; // [esp+10h] [ebp-1Ch]
  char v45; // [esp+10h] [ebp-1Ch]
  unsigned int v46; // [esp+14h] [ebp-18h]
  char v48; // [esp+1Ch] [ebp-10h]
  int v49; // [esp+1Ch] [ebp-10h]
  int v50; // [esp+20h] [ebp-Ch]
  int v51; // [esp+24h] [ebp-8h]
  int v52; // [esp+28h] [ebp-4h]
  int v53; // [esp+28h] [ebp-4h]
  int v54; // [esp+28h] [ebp-4h]

  v4 = a1;
  if ( (int)a1[2] <= 0 )
  {
    if ( a4 > 0 )
      memset(buf, 0, 4 * a4);
    return 0;
  }
  v5 = 0;
  v51 = 0;
  if ( a4 <= 0 )
    return 0;
  v6 = a3;
  while ( 1 )
  {
    v50 = v4[10];
    v7 = sub_42E840(v6, v4[9]);
    if ( v7 < 0 )
      break;
    v8 = *(_DWORD *)(v4[8] + 4 * v7);
    v52 = v8;
    if ( v8 < 0 )
    {
      v53 = (v8 >> 15) & 0x7FFF;
      v9 = v4[2] - (*(_DWORD *)(v4[8] + 4 * v7) & 0x7FFF);
      goto LABEL_12;
    }
    v10 = v6[1] + *(char *)(v4[7] + v8 - 1);
    v48 = *((_BYTE *)v6 + 4) + *(_BYTE *)(v4[7] + v8 - 1);
    v11 = *v6;
    if ( *v6 <= v6[4] - ((v10 + 7) >> 3) )
    {
      v6[3] += v10 / 8;
      *v6 = v11 + v10 / 8;
      v6[1] = v48 & 7;
    }
    else
    {
      *v6 = v6[4];
      v6[3] = 0;
      v6[1] = 1;
    }
    v12 = v52 - 1;
LABEL_24:
    if ( v12 == -1 )
      return -1;
    v32 = v4[4] + 4 * v12 * *v4;
    v33 = 0;
    v54 = v32;
    if ( a4 - v5 >= 4 )
    {
      v34 = &buf[4 * v5 + 8];
      while ( 1 )
      {
        if ( v33 >= *v4 )
          goto LABEL_40;
        v35 = v33 + 1;
        *((_DWORD *)v34 - 2) = *(_DWORD *)(v54 + 4 * v35 - 4);
        if ( v35 >= *v4 )
        {
          ++v5;
          goto LABEL_39;
        }
        v36 = v35 + 1;
        *((_DWORD *)v34 - 1) = *(_DWORD *)(v54 + 4 * v36 - 4);
        if ( v36 >= *v4 )
          break;
        v37 = v36 + 1;
        *(_DWORD *)v34 = *(_DWORD *)(v54 + 4 * v37 - 4);
        if ( v37 >= *v4 )
        {
          v5 += 3;
LABEL_39:
          v51 = v5;
          goto LABEL_40;
        }
        v5 += 4;
        *((_DWORD *)v34 + 1) = *(_DWORD *)(v54 + 4 * v37);
        v33 = v37 + 1;
        v34 += 16;
        v51 = v5;
        if ( v5 >= a4 - 3 )
        {
          v32 = v54;
          goto LABEL_33;
        }
      }
      v5 += 2;
      goto LABEL_39;
    }
LABEL_33:
    if ( v5 >= a4 )
      return 0;
    v38 = (_DWORD *)(v32 + 4 * v33);
    while ( v33 < *v4 )
    {
      *(_DWORD *)&buf[4 * v5] = *v38;
      v6 = a3;
      ++v5;
      ++v33;
      ++v38;
      v51 = v5;
      if ( v5 >= a4 )
        return 0;
    }
LABEL_40:
    if ( v5 >= a4 )
      return 0;
  }
  v9 = v4[2];
  v53 = 0;
LABEL_12:
  v49 = v9;
  v13 = sub_42E840(v6, v50);
  if ( v13 < 0 )
  {
    while ( v50 > 1 )
    {
      v13 = sub_42E840(v6, --v50);
      if ( v13 >= 0 )
        goto LABEL_15;
    }
    return -1;
  }
LABEL_15:
  v14 = __ROL4__(v13, 16);
  v15 = (v14 << 8) ^ (unsigned int)&unk_FF00FF & ((v14 << 8) ^ (v14 >> 8));
  v16 = (16 * v15) ^ ((16 * v15) ^ (v15 >> 4)) & 0xF0F0F0F;
  v17 = (4 * v16) ^ ((4 * v16) ^ (v16 >> 2)) & 0x33333333;
  v18 = ((2 * v17) ^ (v17 >> 1)) & 0x55555555;
  v19 = 2 * v17;
  v20 = v53;
  v46 = v19 ^ v18;
  v21 = v49 - v53;
  if ( v49 - v53 > 1 )
  {
    v22 = v4[5];
    v23 = v53;
    v24 = v49;
    v44 = v22;
    do
    {
      v25 = v21 >> 1;
      v26 = v46 < *(_DWORD *)(v22 + 4 * (v25 + v23));
      v27 = v25 & (v26 - 1);
      v24 -= v25 & -v26;
      v22 = v44;
      v23 += v27;
      v21 = v24 - v23;
    }
    while ( v24 - v23 > 1 );
    v5 = v51;
    v4 = a1;
    v53 = v23;
    v6 = a3;
    v20 = v53;
  }
  v28 = *(char *)(v4[7] + v20);
  if ( v28 <= v50 )
  {
    v29 = v28 + v6[1];
    v45 = v28 + *((_BYTE *)v6 + 4);
    v30 = *v6;
    if ( *v6 <= v6[4] - ((v29 + 7) >> 3) )
    {
      v6[3] += v29 / 8;
      *v6 = v30 + v29 / 8;
      v6[1] = v45 & 7;
    }
    else
    {
      v31 = v6[4];
      v6[3] = 0;
      *v6 = v31;
      v6[1] = 1;
    }
    v12 = v53;
    goto LABEL_24;
  }
  v40 = v6[4];
  v41 = *v6;
  v42 = v50 + v6[1];
  if ( *v6 > v40 - ((v42 + 7) >> 3) )
  {
    v6[3] = 0;
    *v6 = v40;
    v6[1] = 1;
    return -1;
  }
  v6[3] += v42 / 8;
  *v6 = v41 + v42 / 8;
  v6[1] = v42 & 7;
  return -1;
}

