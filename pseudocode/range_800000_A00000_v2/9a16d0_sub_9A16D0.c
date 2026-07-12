// Function: sub_9A16D0
// Address: 0x9a16d0
int __thiscall sub_9A16D0(_DWORD *this, int a2, int a3, int a4)
{
  int v4; // edx
  int v6; // ecx
  int v7; // ebx
  int v8; // edx
  int v9; // esi
  int v10; // edx
  _DWORD *v11; // ecx
  int v13; // esi
  int *v14; // ebx
  int v15; // eax
  int v16; // esi
  int v17; // ecx
  int v18; // edx
  int v19; // ecx
  int v20; // ebx
  _DWORD *v21; // ecx
  int v22; // edx
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // edx
  _DWORD *v27; // ecx
  _DWORD *v28; // edx
  int v29; // [esp+Ch] [ebp-8h]
  int v30; // [esp+10h] [ebp-4h]
  int v31; // [esp+10h] [ebp-4h]
  int *v32; // [esp+20h] [ebp+Ch]
  int v33; // [esp+24h] [ebp+10h]

  ++unk_193F634;
  v4 = a3;
  v6 = a2;
  if ( *(_DWORD *)(a2 + 12) > *(_DWORD *)(a3 + 12) )
  {
    v6 = a3;
    v4 = a2;
    a2 = a3;
    a3 = v4;
  }
  v7 = *(_DWORD *)(v4 + 12);
  v30 = *(_DWORD *)(v6 + 12);
  v8 = ~((((9
          * (((~((v30 | (v7 << 16)) << 15) + (v30 | (v7 << 16))) >> 10)
           ^ (~((v30 | (v7 << 16)) << 15) + (v30 | (v7 << 16))))) >> 6)
        ^ (9
         * (((~((v30 | (v7 << 16)) << 15) + (v30 | (v7 << 16))) >> 10)
          ^ (~((v30 | (v7 << 16)) << 15) + (v30 | (v7 << 16)))))) << 11)
     + (((9
        * (((~((v30 | (v7 << 16)) << 15) + (v30 | (v7 << 16))) >> 10)
         ^ (~((v30 | (v7 << 16)) << 15) + (v30 | (v7 << 16))))) >> 6)
      ^ (9
       * (((~((v30 | (v7 << 16)) << 15) + (v30 | (v7 << 16))) >> 10) ^ (~((v30 | (v7 << 16)) << 15) + (v30 | (v7 << 16))))));
  v29 = 4 * ((*(this + 3) - 1) & (v8 ^ (v8 >> 16)));
  v9 = *(_DWORD *)(v29 + *(this + 11));
  if ( v9 == -1 )
    return 0;
  v10 = *(this + 4);
  while ( 1 )
  {
    v11 = (_DWORD *)(v10 + 16 * v9);
    v10 = *(this + 4);
    if ( *(_DWORD *)(*v11 + 12) == v30 && *(_DWORD *)(v11[1] + 12) == v7 )
      break;
    v9 = *(_DWORD *)(*(this + 16) + 4 * v9);
    if ( v9 == -1 )
      return 0;
  }
  v13 = v10 + 16 * v9;
  if ( !v13 )
    return 0;
  (*(void (__thiscall **)(_DWORD *, int, int))(*this + 28))(this, v13, a4);
  v14 = (int *)(*(this + 11) + v29);
  v31 = *(_DWORD *)(v13 + 12);
  v15 = *v14;
  v16 = (v13 - *(this + 4)) >> 4;
  if ( *v14 == v16 )
    goto LABEL_15;
  v17 = *(this + 16);
  do
  {
    v18 = v15;
    v15 = *(_DWORD *)(v17 + 4 * v15);
  }
  while ( v15 != v16 );
  if ( v18 == -1 )
LABEL_15:
    *v14 = *(_DWORD *)(*(this + 16) + 4 * v16);
  else
    *(_DWORD *)(v17 + 4 * v18) = *(_DWORD *)(v17 + 4 * v16);
  v19 = *(this + 18);
  v20 = *(this + 2) - 1;
  if ( v19 )
    (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v19 + 8))(v19, a2, a3, a4);
  if ( v20 != v16 )
  {
    v21 = (_DWORD *)(16 * v20 + *(this + 4));
    v22 = ((9
          * (((~((*(_DWORD *)(*v21 + 12) | (*(_DWORD *)(v21[1] + 12) << 16)) << 15)
             + (*(_DWORD *)(*v21 + 12) | (*(_DWORD *)(v21[1] + 12) << 16))) >> 10)
           ^ (~((*(_DWORD *)(*v21 + 12) | (*(_DWORD *)(v21[1] + 12) << 16)) << 15)
            + (*(_DWORD *)(*v21 + 12) | (*(_DWORD *)(v21[1] + 12) << 16))))) >> 6)
        ^ (9
         * (((~((*(_DWORD *)(*v21 + 12) | (*(_DWORD *)(v21[1] + 12) << 16)) << 15)
            + (*(_DWORD *)(*v21 + 12) | (*(_DWORD *)(v21[1] + 12) << 16))) >> 10)
          ^ (~((*(_DWORD *)(*v21 + 12) | (*(_DWORD *)(v21[1] + 12) << 16)) << 15)
           + (*(_DWORD *)(*v21 + 12) | (*(_DWORD *)(v21[1] + 12) << 16)))));
    v23 = ~(v22 << 11) + v22;
    v32 = (int *)(4 * ((*(this + 3) - 1) & (v23 ^ (v23 >> 16))) + *(this + 11));
    v24 = *v32;
    v33 = 4 * ((*(this + 3) - 1) & (v23 ^ (v23 >> 16)));
    if ( *v32 == v20 )
      goto LABEL_24;
    v25 = *(this + 16);
    do
    {
      v26 = v24;
      v24 = *(_DWORD *)(v25 + 4 * v24);
    }
    while ( v24 != v20 );
    if ( v26 == -1 )
LABEL_24:
      *v32 = *(_DWORD *)(*(this + 16) + 4 * v20);
    else
      *(_DWORD *)(v25 + 4 * v26) = *(_DWORD *)(v25 + 4 * v20);
    v27 = (_DWORD *)(*(this + 4) + 16 * v20);
    v28 = (_DWORD *)(*(this + 4) + 16 * v16);
    *v28 = *v27;
    v28[1] = v27[1];
    v28[2] = v27[2];
    v28[3] = v27[3];
    *(_DWORD *)(*(this + 16) + 4 * v16) = *(_DWORD *)(v33 + *(this + 11));
    *(_DWORD *)(v33 + *(this + 11)) = v16;
  }
  --*(this + 2);
  return v31;
}
