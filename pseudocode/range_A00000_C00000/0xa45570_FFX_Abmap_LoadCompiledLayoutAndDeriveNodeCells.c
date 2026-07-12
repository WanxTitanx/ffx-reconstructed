// Function: FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells
// Address: 0xa45570
// Size: 0x258
// Prototype: int()

int FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells()
{
  int *v0; // eax
  int v1; // eax
  _BYTE *v2; // esi
  void (__cdecl **CoreWorkPtr)(int); // edi
  int v4; // ecx
  int v5; // edi
  int v6; // ebx
  int n16; // ecx
  int v8; // edx
  int v9; // ebx
  __int16 *v10; // edi
  __int16 n512; // cx
  int n12; // edx
  int v13; // edi
  int v14; // kr00_4
  int v15; // ebx
  __int16 v16; // ax
  unsigned __int16 *v17; // edi
  int n8; // ecx
  int v19; // edx
  int v20; // eax
  __int16 *v22; // [esp+8h] [ebp-4h]
  __int16 v23; // [esp+8h] [ebp-4h]

  v0 = (int *)sub_785350();
  byte_1740830[0] = 0;
  v1 = (*v0 >> 14) & 3;
  v2 = &unk_1740840;
  if ( v1 )
  {
    if ( v1 == 1 )
    {
      CoreWorkPtr = (void (__cdecl **)(int))FFX_Btl_GetCoreWorkPtr();
      CoreWorkPtr[4](37);
      ((void (__cdecl *)(int, _BYTE *, _DWORD, _DWORD))*CoreWorkPtr)(10, byte_1740830, 0, 0);
    }
    else
    {
      CoreWorkPtr = (void (__cdecl **)(int))FFX_Btl_GetCoreWorkPtr();
      CoreWorkPtr[4](37);
      ((void (__cdecl *)(int, _BYTE *, _DWORD, _DWORD))*CoreWorkPtr)(11, byte_1740830, 0, 0);
    }
  }
  else
  {
    CoreWorkPtr = (void (__cdecl **)(int))FFX_Btl_GetCoreWorkPtr();
    CoreWorkPtr[4](37);
    ((void (__cdecl *)(int, _BYTE *, _DWORD, _DWORD))*CoreWorkPtr)(9, byte_1740830, 0, 0);
  }
  CoreWorkPtr[2](0);
  if ( byte_1740830[0] == 49 )
  {
    *unk_2305834 = unk_1740832;
    *(_WORD *)(unk_2305834 + 2) = unk_1740834;
    *(_WORD *)(unk_2305834 + 4) = unk_1740836;
    v4 = unk_2305834;
    v5 = (__int16)*unk_2305834;
    v6 = unk_2305834 + 8;
    if ( *unk_2305834 )
    {
      do
      {
        --v5;
        n16 = 16;
        v8 = v6 - (_DWORD)v2;
        do
        {
          v2[v8] = *v2;
          ++v2;
          --n16;
        }
        while ( n16 );
        v6 += 16;
      }
      while ( v5 );
      v4 = unk_2305834;
    }
    v9 = *(__int16 *)(v4 + 2);
    v10 = (__int16 *)(v4 + 2056);
    v22 = (__int16 *)(v4 + 2056);
    if ( *(_WORD *)(v4 + 2) )
    {
      do
      {
        --v9;
        n512 = 0;
        if ( (v9 & 1) != 0 )
          n512 = 512;
        if ( (v9 & 2) != 0 )
          n512 |= 0x100u;
        if ( (v9 & 4) != 0 )
          n512 |= 0x80u;
        if ( (v9 & 8) != 0 )
          n512 |= 0x40u;
        if ( (v9 & 0x10) != 0 )
          n512 |= 0x20u;
        if ( (v9 & 0x20) != 0 )
          n512 |= 0x10u;
        if ( (v9 & 0x40) != 0 )
          n512 |= 8u;
        if ( (v9 & 0x80u) != 0 )
          n512 |= 4u;
        if ( (v9 & 0x100) != 0 )
          n512 |= 2u;
        if ( (v9 & 0x200) != 0 )
          n512 |= 1u;
        n12 = 12;
        v13 = (char *)v10 - v2;
        do
        {
          v2[v13] = *v2;
          ++v2;
          --n12;
        }
        while ( n12 );
        v14 = v22[1] + 2336;
        v22[19] = n512 << 6;
        v10 = v22 + 20;
        v22[5] = (*v22 + 2560) / 256 + 20 * (v14 / 256);
        v22 += 20;
      }
      while ( v9 );
      v4 = unk_2305834;
    }
    v15 = *(__int16 *)(v4 + 4);
    v16 = 0;
    v23 = 0;
    v17 = (unsigned __int16 *)(v4 + 43016);
    while ( v15 )
    {
      --v15;
      n8 = 8;
      v19 = (char *)v17 - v2;
      do
      {
        v2[v19] = *v2;
        ++v2;
        --n8;
      }
      while ( n8 );
      v20 = *v17;
      v4 = unk_2305834;
      if ( (_WORD)v20 == v17[1] || v20 >= *(__int16 *)(unk_2305834 + 2) || v17[1] >= *(__int16 *)(unk_2305834 + 2) )
      {
        v16 = v23;
      }
      else
      {
        FFX_Abmap_RecomputeLinkEndpointBuckets(v17);
        v4 = unk_2305834;
        v17 += 10;
        v16 = ++v23;
      }
    }
    *(_WORD *)(v4 + 4) = v16;
  }
  FFX_Abmap_BuildNodeAdjacencyFromLinks();
  return sub_A5AE40();
}

