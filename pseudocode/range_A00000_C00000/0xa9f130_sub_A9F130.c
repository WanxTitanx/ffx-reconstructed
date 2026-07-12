// Function: sub_A9F130
// Address: 0xa9f130
// Size: 0x285
// Prototype: _DWORD __cdecl(_DWORD *, int, int (__cdecl *sub_A93CA0)(int *a1, int a2, int a3, int a4))

int __fastcall sub_A9F130(
        _DWORD *a1,
        _DWORD **a2,
        char *a3,
        int a4,
        int (__cdecl *sub_A93CA0)(int *a1, int a2, int a3, int a4))
{
  _DWORD *v5; // edx
  int v6; // ebx
  int v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ebx
  int v12; // esi
  void *v13; // esp
  int v14; // edi
  _DWORD *v15; // edx
  unsigned int Size_1; // esi
  _DWORD *v17; // eax
  void *v18; // eax
  int v19; // eax
  int v20; // ecx
  _DWORD **v21; // eax
  int v22; // ecx
  int v23; // edi
  int v24; // esi
  int v25; // edx
  int v26; // edi
  _DWORD *v27; // esi
  int v28; // eax
  int v29; // edx
  int *v30; // esi
  int v31; // eax
  int v32; // ebx
  int v33; // ecx
  int v34; // edx
  int v35; // eax
  int v36; // edi
  int *v37; // esi
  int v38; // edx
  int *v39; // edx
  size_t Size; // [esp-4h] [ebp-48h]
  int v42; // [esp+0h] [ebp-44h] BYREF
  char *v43; // [esp+Ch] [ebp-38h]
  int v44; // [esp+10h] [ebp-34h]
  int v45; // [esp+14h] [ebp-30h]
  int v46; // [esp+18h] [ebp-2Ch]
  int v47; // [esp+1Ch] [ebp-28h]
  int v48; // [esp+20h] [ebp-24h]
  _DWORD *v49; // [esp+24h] [ebp-20h]
  int *v50; // [esp+28h] [ebp-1Ch]
  int v51; // [esp+2Ch] [ebp-18h]
  int v52; // [esp+30h] [ebp-14h]
  int v53; // [esp+34h] [ebp-10h]
  _DWORD **v54; // [esp+38h] [ebp-Ch]
  int v55; // [esp+3Ch] [ebp-8h]
  _DWORD *v56; // [esp+40h] [ebp-4h]

  v54 = a2;
  v5 = *a2;
  v6 = v5[2];
  v7 = *v54[4];
  v8 = (int)a1[9] >> 1;
  if ( v5[1] < v8 )
    v8 = v5[1];
  v9 = v8 - *v5;
  v56 = a1;
  v49 = v5;
  v53 = v6;
  v45 = v7;
  if ( v9 <= 0 )
    return 0;
  v10 = v9 / v6;
  v11 = a4;
  v52 = v10;
  v12 = (v7 + v10 - 1) / v7;
  v13 = alloca(4 * a4);
  v14 = 0;
  v50 = &v42;
  if ( a4 > 0 )
  {
    v15 = v56;
    Size_1 = (4 * v12 + 7) & 0xFFFFFFF8;
    do
    {
      if ( (signed int)(Size_1 + v15[18]) > v15[19] )
      {
        if ( v15[17] )
        {
          v17 = malloc_0(8u);
          v15 = v56;
          v56[20] += v56[18];
          v17[1] = v15[21];
          *v17 = v15[17];
          v15[21] = v17;
        }
        Size = Size_1;
        v15[19] = Size_1;
        v18 = malloc_0(Size);
        v15 = v56;
        v56[17] = v18;
        v15[18] = 0;
      }
      v19 = v15[18];
      v20 = v19 + v15[17];
      v15[18] = Size_1 + v19;
      v50[v14++] = v20;
    }
    while ( v14 < a4 );
  }
  v21 = v54;
  v22 = 0;
  v51 = 0;
  if ( (int)v54[2] <= 0 )
    return 0;
  v23 = v52;
  while ( 1 )
  {
    v24 = 0;
    v48 = 0;
    if ( v23 > 0 )
      break;
LABEL_40:
    v51 = ++v22;
    if ( v22 >= (int)v21[2] )
      return 0;
  }
  v25 = 0;
  v55 = 0;
  while ( 1 )
  {
    if ( v22 )
      goto LABEL_27;
    v26 = 0;
    if ( v11 > 0 )
      break;
LABEL_26:
    v23 = v52;
LABEL_27:
    v32 = 0;
    v47 = 0;
    if ( v45 > 0 )
    {
      v33 = a4;
      v34 = v53;
      v35 = v53 * v24;
      v46 = v53 * v24;
      while ( 1 )
      {
        if ( v24 >= v23 )
        {
LABEL_38:
          v25 = v55;
          goto LABEL_39;
        }
        v36 = 0;
        if ( v33 > 0 )
          break;
LABEL_37:
        v23 = v52;
        ++v32;
        ++v24;
        v35 += v34;
        v47 = v32;
        v48 = v24;
        v46 = v35;
        if ( v32 >= v45 )
          goto LABEL_38;
      }
      v37 = v50;
      v43 = (char *)(a3 - (char *)v50);
      v44 = 1 << v51;
      while ( 1 )
      {
        v38 = *(_DWORD *)(*(_DWORD *)(v55 + *v37) + 4 * v32);
        v32 = v47;
        if ( (v44 & v49[v38 + 6]) != 0 )
        {
          v39 = *(int **)(v54[5][v38] + 4 * v51);
          if ( v39 )
          {
            if ( sub_A93CA0(v39, *(int *)((char *)v37 + (_DWORD)v43) + 4 * (v35 + *v49), (int)(v56 + 1), v53) == -1 )
              return 0;
          }
        }
        v35 = v46;
        ++v36;
        ++v37;
        if ( v36 >= a4 )
        {
          v33 = a4;
          v24 = v48;
          v34 = v53;
          goto LABEL_37;
        }
      }
    }
LABEL_39:
    v11 = a4;
    v21 = v54;
    v22 = v51;
    v25 += 4;
    v55 = v25;
    if ( v24 >= v23 )
      goto LABEL_40;
  }
  while ( 1 )
  {
    v27 = v21[4];
    if ( (int)v27[2] <= 0 )
      return 0;
    v28 = sub_A94200(v21[4], (int)(v56 + 1));
    if ( v28 < 0 )
      return 0;
    v29 = *(_DWORD *)(v27[6] + 4 * v28);
    if ( v29 == -1 )
      return 0;
    if ( v29 >= v49[4] )
      return 0;
    v30 = v50;
    v31 = v54[7][v29];
    v25 = v55;
    *(_DWORD *)(v55 + v50[v26]) = v31;
    if ( !*(_DWORD *)(v25 + v30[v26]) )
      return 0;
    if ( ++v26 >= v11 )
    {
      v24 = v48;
      goto LABEL_26;
    }
    v21 = v54;
  }
}

