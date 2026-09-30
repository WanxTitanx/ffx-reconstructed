// ============================================================================
// FFX.exe Sphere Grid RUNTIME — batch decompile (2026-08-19)
// DB: F:fx-reconstructed\extrasfxoficial.exe.i64 (FFX.exe, imagebase 0x400000)
// Imagebase 0x400000; addresses below are RVA+0x400000 (absolute in image)
// ============================================================================

// ============================================================================
// FFX_Abmap_InitStaticMenuStateBuffers @ 0xa572e0 (size 0x235)
// ============================================================================
// FFX Abmap: Init static menu state buffers
unsigned int FFX_Abmap_InitStaticMenuStateBuffers()
{
  void *hudContext; // edx
  FFX_CharacterId charId; // ecx
  void *hudContext_1; // edx
  FFX_CharacterId charId_1; // ecx
  _DWORD *lpamng; // ecx
  unsigned int lpamng_1; // eax

  memset(&MEMORY[0x16AB160], 0, 0x2710u);
  unk_16AD860 = -1;
  lpamng = (unsigned int)&FFX_SphereGrid_LpAbilityMapEngineBuffer;
  memset(&FFX_SphereGrid_LpAbilityMapEngineBuffer, 0, 0x12FC0u);
  lpamng_0 = (int)&MEMORY[0x16AB160];
  FFX_Math_BuildProjectionMatrix(
    (float *)&FFX_SphereGrid_LpAbilityMapEngineBuffer.node_type_ui[13208],
    512.0,
    1.0,
    1.0833334,
    2048.0,
    2048.0,
    1.0,
    16777215.0,
    1.0,
    65536.0);
  FFX_Math_BuildProjectionMatrix((float *)(lpamng + 70816), 512.0, 1.0, 1.0, 0.0, 0.0, 1.0, 16777215.0, 1.0, 65536.0);
  FFX_BtlUI_HudParty_GetElement(charId, hudContext);
  FFX_BtlUI_HudParty_GetElement(charId_1, hudContext_1);
  *(float *)(lpamng + 70420) = 1.0;
  lpamng = (_DWORD *)lpamng;
  *(_DWORD *)(lpamng + 70440) = *(_DWORD *)(lpamng + 70408);
  lpamng[17611] = lpamng[17603];
  lpamng[17612] = lpamng[17604];
  lpamng[17613] = lpamng[17605];
  *(float *)(lpamng + 70492) = 1.0;
  *(float *)(lpamng + 70488) = 1.0;
  *(float *)(lpamng + 70484) = 1.0;
  *(float *)(lpamng + 70480) = 1.0;
  *(_BYTE *)(lpamng + 71108) = 0;
  *(_DWORD *)(lpamng + 71080) = FFX_Abmap_MainInputDispatcher;
  *(_DWORD *)(lpamng + 71084) = FFX_Abmap_DispatchSfxByTableEntry_B;
  *(_DWORD *)(lpamng + 71084) = FFX_Abmap_DispatchSfxByTableEntry_B;
  *(_BYTE *)(lpamng + 71107) = 0;
  *(_BYTE *)(lpamng + 71110) = 0x80;
  *(_BYTE *)(lpamng + 71100) = FFX_MenuState_GetBufferHandle();
  *(_WORD *)(lpamng + 71280) = -1;
  *(_BYTE *)(lpamng + 71099) = 1;
  *(_BYTE *)(lpamng + 71098) = 1;
  *(_DWORD *)(lpamng + 71336) = -2;
  *(_DWORD *)(lpamng + 71340) = 0;
  *(float *)(lpamng + 71348) = 0.0;
  lpamng_1 = lpamng;
  *(_DWORD *)(lpamng + 71352) = 1;
  return lpamng_1;
}


// ============================================================================
// FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells @ 0xa45570 (size 0x258)
// ============================================================================
// FFX Abmap: Load compiled layout and derive node cells
unsigned int FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells()
{
  int *RuntimeContextPtr; // eax
  int v1; // eax
  _BYTE *v2; // esi
  int (__cdecl **WalkStructSkyDataPtr)(_DWORD, _DWORD, _DWORD, _DWORD); // edi
  unsigned int lpamng; // ecx
  int v5; // edi
  unsigned int v6; // ebx
  int n16; // ecx
  unsigned int v8; // edx
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

  RuntimeContextPtr = FFX_Battle_GetRuntimeContextPtr();// [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass.
  byte_1740830[0] = 0;
  v1 = (*RuntimeContextPtr >> 14) & 3;
  v2 = &unk_1740840;
  if ( v1 )
  {
    if ( v1 == 1 )
    {
      WalkStructSkyDataPtr = FFX_Mscd_GetWalkStructSkyDataPtr();
      ((void (__cdecl *)(int))WalkStructSkyDataPtr[4])(37);
      (*WalkStructSkyDataPtr)(10, byte_1740830, 0, 0);
    }
    else
    {
      WalkStructSkyDataPtr = FFX_Mscd_GetWalkStructSkyDataPtr();
      ((void (__cdecl *)(int))WalkStructSkyDataPtr[4])(37);
      (*WalkStructSkyDataPtr)(11, byte_1740830, 0, 0);
    }
  }
  else
  {
    WalkStructSkyDataPtr = FFX_Mscd_GetWalkStructSkyDataPtr();
    ((void (__cdecl *)(int))WalkStructSkyDataPtr[4])(37);
    (*WalkStructSkyDataPtr)(9, byte_1740830, 0, 0);
  }
  ((void (__cdecl *)(_DWORD))WalkStructSkyDataPtr[2])(0);
  if ( byte_1740830[0] == 49 )
  {
    *(_WORD *)lpamng = unk_1740832;
    *(_WORD *)(lpamng + 2) = unk_1740834;
    *(_WORD *)(lpamng + 4) = unk_1740836;
    lpamng = lpamng;
    v5 = *(__int16 *)lpamng;
    v6 = lpamng + 8;
    if ( *(_WORD *)lpamng )
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
      lpamng = lpamng;
    }
    v9 = *(__int16 *)(lpamng + 2);
    v10 = (__int16 *)(lpamng + 2056);
    v22 = (__int16 *)(lpamng + 2056);
    if ( *(_WORD *)(lpamng + 2) )
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
      lpamng = lpamng;
    }
    v15 = *(__int16 *)(lpamng + 4);
    v16 = 0;
    v23 = 0;
    v17 = (unsigned __int16 *)(lpamng + 43016);
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
      lpamng = lpamng;
      if ( (_WORD)v20 == v17[1] || v20 >= *(__int16 *)(lpamng + 2) || v17[1] >= *(__int16 *)(lpamng + 2) )
      {
        v16 = v23;
      }
      else
      {
        FFX_Abmap_RecomputeLinkEndpointBuckets(v17);
        lpamng = lpamng;
        v17 += 10;
        v16 = ++v23;
      }
    }
    *(_WORD *)(lpamng + 4) = v16;
  }
  FFX_Abmap_BuildNodeAdjacencyFromLinks();
  return FFX_Abmap_WriteMenuBboxFloats_structural();
}


// ============================================================================
// FFX_Abmap_ApplyMenuSnapshot @ 0xa49590 (size 0x204)
// ============================================================================
// FFX Abmap: Apply menu snapshot
unsigned int FFX_Abmap_ApplyMenuSnapshot()
{
  unsigned __int16 *RuntimeStateTable; // eax
  __int16 *lpamng; // ecx
  unsigned __int16 *RuntimeStateTable_1; // edi
  int v3; // esi
  int v4; // edx
  unsigned __int8 v5; // al
  int v6; // edx
  int v7; // esi
  double v8; // st7
  double v9; // st7
  unsigned int lpamng_1; // eax
  float v11; // [esp+8h] [ebp-4h]
  float v12; // [esp+8h] [ebp-4h]

  RuntimeStateTable = FFX_SphereGrid_GetRuntimeStateTable();// [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass.
  lpamng = (__int16 *)lpamng;
  RuntimeStateTable_1 = RuntimeStateTable;
  v3 = 0;
  if ( *(__int16 *)(lpamng + 2) > 0 )
  {
    v4 = 0;
    do
    {
      if ( lpamng[v4 + 1031] != -1 )
      {
        v5 = RuntimeStateTable_1[v3];
        if ( v5 == 0xFF )
          lpamng[v4 + 1031] = -1;
        else
          lpamng[v4 + 1031] = v5;
        HIBYTE(lpamng[v4 + 1044]) = HIBYTE(RuntimeStateTable_1[v3]);
        lpamng = (__int16 *)lpamng;
      }
      ++v3;
      v4 += 20;
    }
    while ( v3 < lpamng[1] );
  }
  v6 = 0;
  if ( lpamng[2] > 0 )
  {
    v7 = 0;
    do
    {
      LOBYTE(lpamng[v7 + 21514]) = *((_BYTE *)RuntimeStateTable_1 + v6 + 2560);
      lpamng = (__int16 *)lpamng;
      ++v6;
      v7 += 10;
    }
    while ( v6 < *(__int16 *)(lpamng + 4) );
  }
  lpamng[34918] = RuntimeStateTable_1[1920];
  *(_WORD *)(lpamng + 69916) = RuntimeStateTable_1[1921];
  *(_WORD *)(lpamng + 69996) = RuntimeStateTable_1[1922];
  *(_WORD *)(lpamng + 70076) = RuntimeStateTable_1[1923];
  *(_WORD *)(lpamng + 70156) = RuntimeStateTable_1[1924];
  *(_WORD *)(lpamng + 70236) = RuntimeStateTable_1[1925];
  *(_WORD *)(lpamng + 70316) = RuntimeStateTable_1[1926];
  *(_BYTE *)(lpamng + 71115) = *((_BYTE *)RuntimeStateTable_1 + 3864);
  *(_BYTE *)(lpamng + 71116) = *((_BYTE *)RuntimeStateTable_1 + 3865);
  if ( *(_BYTE *)(lpamng + 71115) )
  {
    if ( *(_BYTE *)(lpamng + 71115) == 1 )
    {
      v8 = -3640.0;
      goto LABEL_18;
    }
    if ( *(_BYTE *)(lpamng + 71115) == 2 )
    {
      v8 = -7281.0;
      goto LABEL_18;
    }
  }
  v8 = 0.0;
LABEL_18:
  v11 = v8;
  *(_DWORD *)(lpamng + 70464) = (int)v11;
  switch ( *(_BYTE *)(lpamng + 71116) )
  {
    case 1:
      v9 = 0.5;
      break;
    case 2:
      v9 = 0.25;
      break;
    case 3:
      v9 = 0.125;
      break;
    default:
      v9 = 1.0;
      break;
  }
  v12 = v9;
  *(float *)(lpamng + 70488) = v12;
  *(float *)(lpamng + 70484) = v12;
  *(float *)(lpamng + 70480) = v12;
  lpamng_1 = lpamng;
  if ( v12 <= 0.375 )
    *(_DWORD *)(lpamng + 71344) = -2;
  else
    *(_DWORD *)(lpamng + 71344) = 2;
  return lpamng_1;
}


// ============================================================================
// FFX_Abmap_PackMenuSnapshot @ 0xa5bb70 (size 0x127)
// ============================================================================
// FFX Abmap: Pack menu snapshot
int FFX_Abmap_PackMenuSnapshot()
{
  unsigned __int16 *RuntimeStateTable; // eax
  unsigned int lpamng; // ecx
  unsigned __int16 *RuntimeStateTable_1; // edi
  int v3; // edx
  int v4; // esi
  int v5; // edx
  int v6; // esi
  int result; // eax

  RuntimeStateTable = FFX_SphereGrid_GetRuntimeStateTable();// [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass.
  lpamng = lpamng;
  RuntimeStateTable_1 = RuntimeStateTable;
  v3 = 0;
  if ( *(__int16 *)(lpamng + 2) > 0 )
  {
    v4 = 0;
    do
    {
      LOBYTE(RuntimeStateTable[v3]) = *(_BYTE *)(v4 + lpamng + 2062);
      HIBYTE(RuntimeStateTable[v3]) = *(_BYTE *)(v4 + lpamng + 2089);
      lpamng = lpamng;
      ++v3;
      v4 += 40;
    }
    while ( v3 < *(__int16 *)(lpamng + 2) );
  }
  v5 = 0;
  if ( *(__int16 *)(lpamng + 4) > 0 )
  {
    v6 = 0;
    do
    {
      *((_BYTE *)RuntimeStateTable + v5 + 2560) = *(_BYTE *)(v6 + lpamng + 43028);
      lpamng = lpamng;
      ++v5;
      v6 += 20;
    }
    while ( v5 < *(__int16 *)(lpamng + 4) );
  }
  RuntimeStateTable[1920] = *(_WORD *)(lpamng + 69836);
  RuntimeStateTable[1921] = *(_WORD *)(lpamng + 69916);
  RuntimeStateTable[1922] = *(_WORD *)(lpamng + 69996);
  RuntimeStateTable[1923] = *(_WORD *)(lpamng + 70076);
  RuntimeStateTable[1924] = *(_WORD *)(lpamng + 70156);
  RuntimeStateTable[1925] = *(_WORD *)(lpamng + 70236);
  RuntimeStateTable[1926] = *(_WORD *)(lpamng + 70316);
  *((_BYTE *)RuntimeStateTable + 3864) = *(_BYTE *)(lpamng + 71115);
  result = *(unsigned __int8 *)(lpamng + 71116);
  *((_BYTE *)RuntimeStateTable_1 + 3865) = result;
  return result;
}


// ============================================================================
// FFX_Abmap_RecomputePartyStatsAndLearnedMoves @ 0xa54860 (size 0x243)
// ============================================================================
// FFX Abmap: Recompute party stats and learned moves
void __fastcall FFX_Abmap_RecomputePartyStatsAndLearnedMoves(FFX_CharacterId charId, void *abmapContext)
{
  int n7; // eax
  int v3; // ebx
  unsigned __int16 *RuntimeStateTable; // edi
  int n1024; // esi
  int v6; // eax
  char *EntryByIdRange; // eax
  __int16 v8; // dx
  char *PartyDataEntryPtr_1; // edi
  char n255_8; // cl
  char n255_9; // dl
  unsigned int n8_1; // [esp-10h] [ebp-64h]
  int v13; // [esp+0h] [ebp-54h] BYREF
  char *PartyDataEntryPtr; // [esp+4h] [ebp-50h]
  int v15; // [esp+8h] [ebp-4Ch]
  int n255; // [esp+Ch] [ebp-48h]
  int v17; // [esp+10h] [ebp-44h]
  int n255_1; // [esp+14h] [ebp-40h]
  int n7_1; // [esp+18h] [ebp-3Ch]
  int n255_2; // [esp+1Ch] [ebp-38h]
  int n255_3; // [esp+20h] [ebp-34h]
  int n255_7; // [esp+24h] [ebp-30h]
  int n255_4; // [esp+28h] [ebp-2Ch]
  int n255_6; // [esp+2Ch] [ebp-28h]
  int n255_5; // [esp+30h] [ebp-24h]
  int n8[7]; // [esp+34h] [ebp-20h]

  FFX_Btl_ClearAllPartyDataEntries();           // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass.
  n7 = 0;
  n7_1 = 0;
  do
  {
    v3 = 0;
    n8[0] = 0;
    n8[1] = 1;
    n8[2] = 2;
    n8[3] = 3;
    n8[4] = 4;
    n8[5] = 5;
    n8[6] = 6;
    n8_1 = n8[n7];
    v17 = 0;
    n255 = 0;
    n255_1 = 0;
    n255_2 = 0;
    n255_3 = 0;
    n255_4 = 0;
    n255_5 = 0;
    n255_6 = 0;
    n255_7 = 0;
    PartyDataEntryPtr = FFX_Btl_GetPartyDataEntryPtr(n8_1);
    RuntimeStateTable = FFX_SphereGrid_GetRuntimeStateTable();
    n1024 = 0;
    v6 = __ROL4__(1, n7_1);
    v15 = v6;
    do
    {
      if ( ((unsigned __int8)v6 & HIBYTE(RuntimeStateTable[n1024])) != 0 )
      {
        EntryByIdRange = FFX_Table_GetEntryByIdRange(LOBYTE(RuntimeStateTable[n1024]), (__int16 *)panel_bin_ptr, &v13);
        v8 = *((_WORD *)EntryByIdRange + 8);
        if ( (v8 & 1) != 0 )
          n255 += (unsigned __int8)EntryByIdRange[20];
        if ( (v8 & 2) != 0 )
          n255_1 += (unsigned __int8)EntryByIdRange[20];
        if ( (v8 & 4) != 0 )
          n255_2 += (unsigned __int8)EntryByIdRange[20];
        if ( (v8 & 8) != 0 )
          n255_3 += (unsigned __int8)EntryByIdRange[20];
        if ( (v8 & 0x10) != 0 )
          n255_4 += (unsigned __int8)EntryByIdRange[20];
        if ( (v8 & 0x20) != 0 )
          n255_5 += (unsigned __int8)EntryByIdRange[20];
        if ( (v8 & 0x40) != 0 )
          n255_6 += (unsigned __int8)EntryByIdRange[20];
        if ( (v8 & 0x80u) != 0 )
          n255_7 += (unsigned __int8)EntryByIdRange[20];
        if ( (v8 & 0x100) != 0 )
          v17 += (unsigned __int8)EntryByIdRange[20];
        if ( (v8 & 0x200) != 0 )
          v3 += (unsigned __int8)EntryByIdRange[20];
        FFX_SphereGrid_ApplyLearnedMove_structural(n8[n7_1], *((unsigned __int16 *)EntryByIdRange + 9));
        LOBYTE(v6) = v15;
      }
      ++n1024;
    }
    while ( n1024 < 1024 );
    PartyDataEntryPtr_1 = PartyDataEntryPtr;
    n255_8 = n255;
    if ( n255 > 255 )
      n255_8 = -1;
    n255_9 = n255_1;
    if ( n255_1 > 255 )
      n255_9 = -1;
    if ( n255_2 > 255 )
      n255_2 = 255;
    if ( n255_3 > 255 )
      n255_3 = 255;
    if ( n255_4 > 255 )
      n255_4 = 255;
    if ( n255_5 > 255 )
      n255_5 = 255;
    if ( n255_6 > 255 )
      n255_6 = 255;
    if ( n255_7 > 255 )
      n255_7 = 255;
    *(_DWORD *)PartyDataEntryPtr = v17;
    PartyDataEntryPtr_1[10] = n255_2;
    PartyDataEntryPtr_1[11] = n255_3;
    PartyDataEntryPtr_1[12] = n255_4;
    PartyDataEntryPtr_1[13] = n255_5;
    PartyDataEntryPtr_1[14] = n255_6;
    PartyDataEntryPtr_1[15] = n255_7;
    n7 = n7_1 + 1;
    *((_DWORD *)PartyDataEntryPtr_1 + 1) = v3;
    PartyDataEntryPtr_1[8] = n255_8;
    PartyDataEntryPtr_1[9] = n255_9;
    n7_1 = n7;
  }
  while ( n7 < 7 );
  FFX_Btl_ReloadAllAbilitySysBins();
}


// ============================================================================
// FFX_Abmap_ActivateNode @ 0xa48910 (size 0x166)
// ============================================================================
// FFX Abmap: Activate node
unsigned int __cdecl FFX_Abmap_ActivateNode(int a1, int a2)
{
  _DWORD *RuntimeContextPtr; // esi
  void *abmapContext; // edx
  FFX_CharacterId charId; // ecx
  unsigned int lpamng_2; // eax
  unsigned int lpamng_1; // ecx
  float v8; // [esp+4h] [ebp-30h]
  float v9; // [esp+8h] [ebp-2Ch]
  float v10; // [esp+Ch] [ebp-28h]
  float v11; // [esp+10h] [ebp-24h]
  float v12; // [esp+14h] [ebp-20h]
  float v13; // [esp+18h] [ebp-1Ch]
  float v14; // [esp+1Ch] [ebp-18h]
  float v15; // [esp+20h] [ebp-14h]
  float v16; // [esp+30h] [ebp-4h]
  float v17; // [esp+30h] [ebp-4h]
  unsigned int lpamng; // [esp+40h] [ebp+Ch]

  lpamng = lpamng;
  RuntimeContextPtr = FFX_Battle_GetRuntimeContextPtr();
  FFX_MagicHost_LinkResourceBufferRange(
    _Jarvis_naming_goal_2026_06_17__proved_navigation_name_from_agg_4,
    &FFX_SphereGrid_LpAbilityMapEngineBuffer.node_type_ui[24504],
    512000);
  v15 = 0.5;
  v14 = 0.5;
  v13 = 0.5;
  v12 = 0.0;
  v11 = 0.0;
  v10 = 0.0;
  v9 = 0.0;
  v16 = (float)*(__int16 *)(lpamng + 40 * a2 + 2058);
  v8 = v16;
  v17 = (float)*(__int16 *)(lpamng + 40 * a2 + 2056);
  if ( (*RuntimeContextPtr & 0xC000) == 0x8000 )
    FFX_Abmap_QueuePlacementAnim((int)&unk_1A86060, 4, v17, v8, v9, v10, v11, v12, v13, v14, v15);
  else
    FFX_Abmap_QueuePlacementAnim((int)&unk_1A86060, 0, v17, v8, v9, v10, v11, v12, v13, v14, v15);
  *(_BYTE *)(lpamng + 40 * a2 + 2089) |= 1 << a1;
  *(_DWORD *)(lpamng + 71336) = a2;
  FFX_Abmap_PackMenuSnapshot();
  FFX_Abmap_RecomputePartyStatsAndLearnedMoves(charId, abmapContext);
  FFX_Abmap_ApplyActivationStats();
  lpamng_2 = FFX_Abmap_DispatchActivationAnim(a1, a2);
  lpamng_1 = lpamng;
  if ( !*(_DWORD *)(lpamng + 71092) )
  {
    *(_DWORD *)(lpamng + 71092) = *(_DWORD *)(lpamng + 71084);
    lpamng_2 = lpamng;
    *(_DWORD *)(lpamng + 71084) = FFX_Abmap_PlacementFxCallback;
    lpamng_1 = lpamng;
  }
  if ( !*(_DWORD *)(lpamng_1 + 71088) )
  {
    *(_DWORD *)(lpamng_1 + 71088) = *(_DWORD *)(lpamng_1 + 71080);
    lpamng_2 = lpamng;
    *(_DWORD *)(lpamng + 71080) = FFX_Abmap_SwapAnimCallbackChain;
  }
  return lpamng_2;
}


// ============================================================================
// FFX_Abmap_ApplyActivationStats @ 0xa47210 (size 0x1bd)
// ============================================================================
// Jarvis 2026-06-23 docsweep: renamed from LoadDefaultStateResourceAndValidate after SGM IDA docs; activation stats/SFX path, not the GPU batch writer.
// FFX Abmap: Apply activation stats
void FFX_Abmap_ApplyActivationStats()
{
  char v0; // bl
  int v1; // eax
  int (__cdecl **WalkStructSkyDataPtr)(_DWORD, _DWORD, _DWORD, _DWORD); // esi
  int RuntimeStateTable; // eax
  unsigned __int8 *achievement; // ecx
  int n7; // esi
  int v6; // edi
  unsigned __int8 *achievement_5; // edx
  unsigned __int16 *RuntimeStateTable_3; // esi
  int n255; // eax
  int RuntimeStateTable_4; // edx
  int v11; // esi
  unsigned __int8 *achievement_2; // ebx
  int n255_1; // eax
  int RuntimeStateTable_2; // [esp+8h] [ebp-494h]
  int n7_1; // [esp+Ch] [ebp-490h]
  unsigned __int16 *RuntimeStateTable_1; // [esp+10h] [ebp-48Ch]
  unsigned __int8 *achievement_1; // [esp+14h] [ebp-488h]
  __int16 n49; // [esp+18h] [ebp-484h] BYREF
  _WORD achievement_3[3]; // [esp+1Ah] [ebp-482h] BYREF
  _BYTE achievement_4[1144]; // [esp+20h] [ebp-47Ch] BYREF

  FFX_Abmap_CheckStatRequirementsForSlots(3);   // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass.
  FFX_Abmap_CheckStatRequirementsForSlots(2);
  FFX_Abmap_CheckStatRequirementsForSlots(4);
  FFX_Abmap_CheckStatRequirementsForSlots(5);
  v0 = 1;
  v1 = ((int)*FFX_Battle_GetRuntimeContextPtr() >> 14) & 3;
  if ( v1 )
  {
    if ( v1 == 1 )
    {
      WalkStructSkyDataPtr = FFX_Mscd_GetWalkStructSkyDataPtr();
      ((void (__cdecl *)(int))WalkStructSkyDataPtr[4])(37);
      (*WalkStructSkyDataPtr)(18, &n49, 0, 0);
    }
    else
    {
      WalkStructSkyDataPtr = FFX_Mscd_GetWalkStructSkyDataPtr();
      ((void (__cdecl *)(int))WalkStructSkyDataPtr[4])(37);
      (*WalkStructSkyDataPtr)(19, &n49, 0, 0);
    }
  }
  else
  {
    WalkStructSkyDataPtr = FFX_Mscd_GetWalkStructSkyDataPtr();
    ((void (__cdecl *)(int))WalkStructSkyDataPtr[4])(37);
    (*WalkStructSkyDataPtr)(17, &n49, 0, 0);
  }
  ((void (__cdecl *)(_DWORD))WalkStructSkyDataPtr[2])(0);
  RuntimeStateTable = (int)FFX_SphereGrid_GetRuntimeStateTable();
  achievement = (unsigned __int8 *)achievement_3;
  RuntimeStateTable_1 = (unsigned __int16 *)RuntimeStateTable;
  achievement_1 = (unsigned __int8 *)achievement_3;
  if ( n49 == 49 )
  {
    RuntimeStateTable = achievement_3[0];
    achievement = achievement_4;
    achievement_1 = achievement_4;
  }
  n7 = 7;
  RuntimeStateTable_2 = RuntimeStateTable;
  n7_1 = 7;
  do
  {
    v6 = 1;
    achievement_5 = achievement;
    if ( RuntimeStateTable <= 0 )
      goto LABEL_15;
    achievement = (unsigned __int8 *)RuntimeStateTable_1 + 1;
    RuntimeStateTable_3 = (unsigned __int16 *)RuntimeStateTable;
    do
    {
      n255 = *achievement_5++;
      if ( n255 != 255 )
        v6 = (unsigned __int8)(v0 & *achievement) != 0 ? v6 : 0;
      achievement += 2;
      RuntimeStateTable_3 = (unsigned __int16 *)((char *)RuntimeStateTable_3 - 1);
    }
    while ( RuntimeStateTable_3 );
    n7 = n7_1;
    if ( v6 == 1 )
LABEL_15:
      FFX_Achievement_TryUnlock((FFX_SteamAchievement)achievement);
    RuntimeStateTable = RuntimeStateTable_2;
    achievement = achievement_1;
    v0 *= 2;
    n7_1 = --n7;
  }
  while ( n7 );
  RuntimeStateTable_4 = RuntimeStateTable_2;
  v11 = 1;
  if ( RuntimeStateTable_2 <= 0 )
    goto LABEL_23;
  achievement_2 = achievement_1;
  achievement = (unsigned __int8 *)RuntimeStateTable_1 + 1;
  do
  {
    n255_1 = *achievement_2++;
    if ( n255_1 != 255 )
      v11 = *achievement != 127 ? 0 : v11;
    achievement += 2;
    --RuntimeStateTable_4;
  }
  while ( RuntimeStateTable_4 );
  if ( v11 == 1 )
LABEL_23:
    FFX_Achievement_TryUnlock((FFX_SteamAchievement)achievement);
}


// ============================================================================
// FFX_Abmap_BuildNodeAdjacencyFromLinks @ 0xa5b140 (size 0xea)
// ============================================================================
// FFX Abmap: Build node adjacency from links
unsigned int FFX_Abmap_BuildNodeAdjacencyFromLinks()
{
  unsigned int lpamng; // esi
  unsigned int i_1; // eax
  int v2; // ebx
  int n5; // edx
  _WORD *v4; // edi
  _DWORD *j; // eax
  unsigned int v6; // ecx
  _WORD *v7; // esi
  _DWORD *j_1; // [esp+8h] [ebp-Ch]
  int n5_1; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  lpamng = lpamng;                              // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass.
  i_1 = lpamng + 2056;
  v2 = 0;
  for ( i = lpamng + 2056; v2 < *(__int16 *)(lpamng + 2); i_1 += 40 )
  {
    if ( *(_WORD *)(i_1 + 6) != 0xFFFF )
    {
      n5 = 0;
      v4 = 0;
      for ( j = (_DWORD *)(i_1 + 12); ; j = j_1 + 1 )
      {
        j_1 = j;
        n5_1 = n5;
        v6 = lpamng + 4 * (*(__int16 *)(lpamng + 4) + 4 * *(__int16 *)(lpamng + 4) + 10754);
        v7 = (_WORD *)(lpamng + 43016);
        if ( v4 )
          v7 = v4 + 10;
        if ( (unsigned int)v7 >= v6 )
          break;
        while ( *v7 != (_WORD)v2 && v7[1] != (_WORD)v2 )
        {
          v7 += 10;
          if ( (unsigned int)v7 >= v6 )
            goto LABEL_10;
        }
        v4 = v7;
        if ( n5 >= 5 )
        {
          dbgPrintf();
          n5 = n5_1;
        }
        ++n5;
        *j_1 = v7;
        lpamng = lpamng;
      }
LABEL_10:
      if ( n5 < 5 )
        memset((void *)(i + 12 + 4 * n5), 0, 4 * (5 - n5));
      i_1 = i;
      lpamng = lpamng;
    }
    i = i_1 + 40;
    ++v2;
  }
  return i_1;
}


// ============================================================================
// FFX_Abmap_RecomputeLinkEndpointBuckets @ 0xa5a760 (size 0x9d)
// ============================================================================
// FFX Abmap: Recompute link endpoint buckets
int __cdecl FFX_Abmap_RecomputeLinkEndpointBuckets(unsigned __int16 *a1)
{
  unsigned int v1; // esi
  int result; // eax

  a1[4] = (*(__int16 *)(lpamng + 40 * *a1 + 2056) + 2560) / 256
        + 20 * ((*(__int16 *)(lpamng + 40 * *a1 + 2058) + 2336) / 256);// [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass.
  v1 = lpamng + 40 * a1[1];
  result = (*(__int16 *)(v1 + 2056) + 2560) / 256 + 20 * ((*(__int16 *)(v1 + 2058) + 2336) / 256);
  a1[5] = result;
  return result;
}


// ============================================================================
// FFX_Abmap_UpdateRuntimeLinkGeometry @ 0xa5a800 (size 0xda)
// ============================================================================
// FFX Abmap: Update runtime link geometry
unsigned int FFX_Abmap_UpdateRuntimeLinkGeometry()
{
  unsigned int lpamng; // eax
  int v1; // ebx
  float *v2; // edi
  unsigned int v3; // esi
  double v4; // st7
  unsigned __int16 v5; // ax
  float *v6; // eax
  unsigned __int16 v7; // [esp+4h] [ebp-4Ch]
  int v8[4]; // [esp+18h] [ebp-38h] BYREF
  int v9[4]; // [esp+28h] [ebp-28h] BYREF
  int v10[4]; // [esp+38h] [ebp-18h] BYREF
  float v11; // [esp+48h] [ebp-8h]
  float v12; // [esp+4Ch] [ebp-4h]

  lpamng = lpamng;                              // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass.
  v1 = *(__int16 *)(lpamng + 4);
  v2 = *(float **)(lpamng + 71272);
  v3 = lpamng + 43016;
  if ( *(_WORD *)(lpamng + 4) )
  {
    do
    {
      v7 = *(_WORD *)v3;
      --v1;
      *(_DWORD *)(v3 + 16) = v2;
      v11 = FFX_Abmap_LookupNodeLinkCoords(v7, (float *)v9);
      v4 = FFX_Abmap_LookupNodeLinkCoords(*(_WORD *)(v3 + 2), (float *)v10);
      v5 = *(_WORD *)(v3 + 4);
      v12 = v4;
      if ( v5 == 0xFFFF )
      {
        v6 = FFX_Abmap_BuildLinkBatchEnd(v2, (float *)v9, (float *)v10, v11, v12, (_BYTE *)(v3 + 13));
      }
      else
      {
        FFX_Abmap_LookupNodeLinkCoords(v5, (float *)v8);
        v6 = FFX_Abmap_BuildLinkBatchSegment_structural(
               v2,
               (float *)v9,
               (float *)v10,
               (float *)v8,
               v11,
               v12,
               (_BYTE *)(v3 + 13));
      }
      v3 += 20;
      v2 = v6;
    }
    while ( v1 );
    lpamng = lpamng;
  }
  *(_DWORD *)(lpamng + 71272) = v2;
  return lpamng;
}


// ============================================================================
// FFX_Abmap_DrawRuntimePanelNodes @ 0xa51340 (size 0x217)
// ============================================================================
// FFX Abmap: Draw runtime panel nodes
int __usercall FFX_Abmap_DrawRuntimePanelNodes@<eax>(
        int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg@<ebp>)
{
  char v1; // cl
  unsigned int v2; // edi
  int result; // eax
  double v4; // st7
  unsigned int v5; // esi
  _DWORD *v6; // edx
  float v7; // [esp+0h] [ebp-130h]
  unsigned int v8; // [esp+18h] [ebp-118h]
  int v9; // [esp+1Ch] [ebp-114h]
  int v10; // [esp+1Ch] [ebp-114h]
  unsigned __int8 v11; // [esp+23h] [ebp-10Dh]
  _WORD v12[2]; // [esp+24h] [ebp-10Ch] BYREF
  int v13; // [esp+28h] [ebp-108h]
  int v14; // [esp+2Ch] [ebp-104h]
  int v15; // [esp+30h] [ebp-100h]
  _BYTE *v16; // [esp+34h] [ebp-FCh]
  char v17; // [esp+3Ch] [ebp-F4h]
  __int64 *p_n1006632960; // [esp+40h] [ebp-F0h]
  _BYTE v19[64]; // [esp+5Ch] [ebp-D4h] BYREF
  _BYTE v20[64]; // [esp+9Ch] [ebp-94h] BYREF
  __int64 n1006632960; // [esp+DCh] [ebp-54h] BYREF
  FFX_CharacterId FFX_Render_SharedTransformContext; // [esp+E4h] [ebp-4Ch]
  float v23; // [esp+E8h] [ebp-48h]
  __int64 n1006632960_1; // [esp+ECh] [ebp-44h]
  FFX_CharacterId FFX_Render_SharedTransformContext_1; // [esp+F4h] [ebp-3Ch]
  float v26; // [esp+F8h] [ebp-38h]
  __int64 n1006632960_2; // [esp+FCh] [ebp-34h]
  FFX_CharacterId FFX_Render_SharedTransformContext_2; // [esp+104h] [ebp-2Ch]
  float v29; // [esp+108h] [ebp-28h]
  __int64 n1006632960_3; // [esp+10Ch] [ebp-24h]
  float v31; // [esp+114h] [ebp-1Ch]
  float v32; // [esp+118h] [ebp-18h]
  int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1; // [esp+124h] [ebp-Ch]
  void *v34; // [esp+128h] [ebp-8h]
  void *retaddr; // [esp+130h] [ebp+0h]

  [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg;// [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass.
  v34 = retaddr;
  v9 = *(__int16 *)(lpamng + 2);
  v1 = *(_BYTE *)(lpamng + 71100);
  v2 = lpamng + 2056;
  v8 = lpamng + 63528;
  v16 = v20;
  p_n1006632960 = &n1006632960;
  v23 = MEMORY[0xC8F514][0];
  v26 = MEMORY[0xC8F514][0];
  v29 = MEMORY[0xC8F514][0];
  v12[1] = 20;
  result = v9;
  v31 = 16384.0;
  v4 = 1.0;
  v11 = 1 << v1;
  v32 = 1.0;
  v14 = 0;
  v15 = 0;
  v17 = 0;
  n1006632960 = n1006632960_1;
  FFX_Render_SharedTransformContext = FFX_Render_SharedTransformContext;
  n1006632960_1 = n1006632960_1;
  FFX_Render_SharedTransformContext_1 = FFX_Render_SharedTransformContext;
  n1006632960_2 = n1006632960_1;
  FFX_Render_SharedTransformContext_2 = FFX_Render_SharedTransformContext;
  n1006632960_3 = n1006632960_1;
  if ( v9 )
  {
    while ( 1 )
    {
      v10 = result - 1;
      if ( *(_WORD *)(v2 + 6) == 0xFFFF )
      {
        FFX_Menu2D_DrawQuadIndexedBatch(0, (int)v12, 0xFFFF);
      }
      else
      {
        v7 = v4;
        FFX_Abmap_BuildNodePlacementMatrix((int)v19, (__int16 *)v2, v7);
        FFX_Menu2D_ProjectNodeCoords_structural((int)v20, lpamng + 70624, (int)v19);
        v5 = v8 + 48 * *(unsigned __int16 *)(v2 + 6);
        if ( (v11 & *(_BYTE *)(v2 + 33)) != 0 )
        {
          v13 = -2142943931;
          v6 = *(_DWORD **)v5;
        }
        else
        {
          v13 = -2146299374;
          v6 = *(_DWORD **)(v5 + 4);
        }
        FFX_Menu2D_DrawQuadIndexedBatch(v6, (int)v12, *(__int16 *)(lpamng + 2) - v10 + 860);
        v13 = 0;
        FFX_Menu2D_DrawQuadIndexedBatch(*(_DWORD **)(v5 + 8), (int)v12, -862);
      }
      result = v10;
      v2 += 40;
      if ( !v10 )
        break;
      v4 = 1.0;
    }
  }
  return result;
}


// ============================================================================
// FFX_Abmap_RenderPathNodes @ 0xa50290 (size 0x341)
// ============================================================================
// FFX Abmap: Render path nodes
void __usercall FFX_Abmap_RenderPathNodes(int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg@<ebp>)
{
  unsigned int v1; // edi
  unsigned int lpamng; // ecx
  int v3; // esi
  double v4; // st7
  double v5; // st7
  int v6; // eax
  double v7; // st5
  double v8; // st6
  double v9; // rt1
  double v10; // st5
  int n0x4000; // eax
  int n0x10000; // edx
  float v13; // [esp+10h] [ebp-160h]
  float v14; // [esp+14h] [ebp-15Ch]
  int v15; // [esp+18h] [ebp-158h]
  int v16; // [esp+1Ch] [ebp-154h]
  int v17; // [esp+20h] [ebp-150h]
  float v18; // [esp+20h] [ebp-150h]
  float v19; // [esp+20h] [ebp-150h]
  float v20; // [esp+20h] [ebp-150h]
  float n0x4000_1; // [esp+20h] [ebp-150h]
  _DWORD p_n4[2]; // [esp+24h] [ebp-14Ch] BYREF
  __int16 n72; // [esp+2Ch] [ebp-144h]
  char v24; // [esp+2Eh] [ebp-142h]
  int v25; // [esp+30h] [ebp-140h]
  int v26; // [esp+34h] [ebp-13Ch]
  int v27; // [esp+38h] [ebp-138h]
  int v28; // [esp+3Ch] [ebp-134h]
  int v29; // [esp+40h] [ebp-130h]
  _BYTE *v30; // [esp+44h] [ebp-12Ch]
  unsigned int v31; // [esp+48h] [ebp-128h]
  unsigned int v32; // [esp+4Ch] [ebp-124h]
  float *v33; // [esp+50h] [ebp-120h]
  int v34; // [esp+5Ch] [ebp-114h]
  int v35; // [esp+60h] [ebp-110h]
  int v36; // [esp+64h] [ebp-10Ch]
  __int64 *p_n1006632960; // [esp+68h] [ebp-108h]
  char v38; // [esp+70h] [ebp-100h]
  char v39; // [esp+71h] [ebp-FFh]
  _BYTE v40[64]; // [esp+9Ch] [ebp-D4h] BYREF
  float v41[16]; // [esp+DCh] [ebp-94h] BYREF
  __int64 n1006632960; // [esp+11Ch] [ebp-54h] BYREF
  FFX_CharacterId FFX_Render_SharedTransformContext; // [esp+124h] [ebp-4Ch]
  float v44; // [esp+128h] [ebp-48h]
  __int64 n1006632960_1; // [esp+12Ch] [ebp-44h]
  FFX_CharacterId FFX_Render_SharedTransformContext_1; // [esp+134h] [ebp-3Ch]
  float v47; // [esp+138h] [ebp-38h]
  __int64 n1006632960_2; // [esp+13Ch] [ebp-34h]
  FFX_CharacterId FFX_Render_SharedTransformContext_2; // [esp+144h] [ebp-2Ch]
  float v50; // [esp+148h] [ebp-28h]
  __int64 n1006632960_3; // [esp+14Ch] [ebp-24h]
  FFX_CharacterId FFX_Render_SharedTransformContext_3; // [esp+154h] [ebp-1Ch]
  float v53; // [esp+158h] [ebp-18h]
  int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1; // [esp+164h] [ebp-Ch]
  void *v55; // [esp+168h] [ebp-8h]
  void *retaddr; // [esp+170h] [ebp+0h]

  [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg;
  v55 = retaddr;
  v17 = *(__int16 *)(lpamng + 2);
  v15 = unk_23057F4;
  v30 = v40;
  p_n1006632960 = &n1006632960;
  v1 = lpamng + 2056;
  v33 = v41;
  FFX_Render_SharedTransformContext = FFX_Render_SharedTransformContext;
  FFX_Render_SharedTransformContext_1 = FFX_Render_SharedTransformContext;
  FFX_Render_SharedTransformContext_2 = FFX_Render_SharedTransformContext;
  FFX_Render_SharedTransformContext_3 = FFX_Render_SharedTransformContext;
  lpamng = lpamng;
  v44 = MEMORY[0xC8F514][0];
  v53 = 1.0;
  v47 = MEMORY[0xC8F514][0];
  v50 = MEMORY[0xC8F514][0];
  v32 = 0;
  v31 = 0;
  n1006632960 = n1006632960_1;
  n1006632960_1 = n1006632960_1;
  n1006632960_2 = n1006632960_1;
  n1006632960_3 = n1006632960_1;
  v29 = 0;
  v24 = 0;
  v35 = 0;
  v34 = 0;
  p_n4[1] = byte_1740830;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v36 = 0;
  v3 = v17;
  v16 = 0;
  v14 = 65536.0 / *(float *)(lpamng + 71072);
  v4 = *(float *)(lpamng + 71072) * *(float *)(lpamng + 71072);
  v32 = lpamng + 70944;
  v31 = lpamng + 71008;
  v13 = v4 * 0.5;
  if ( v17 )
  {
    v5 = 1.299999952316284;
    do
    {
      v6 = *(unsigned __int16 *)(v1 + 6);
      --v3;
      if ( (_WORD)v6 != 0xFFFF )
      {
        v18 = v5 * *(float *)(lpamng + 48 * v6 + 63544);
        FFX_Abmap_BuildNodePlacementMatrix((int)v41, (__int16 *)v1, v18);
        lpamng = lpamng;
        v7 = *(float *)(lpamng + 70944) - v41[12];
        v8 = *(float *)(lpamng + 70952) - v41[14];
        v9 = v7 * v7;
        v10 = *(float *)(lpamng + 70948) - v41[13];
        v19 = v9 + v10 * v10 + v8 * v8;
        if ( v13 <= (double)v19 )
        {
          v39 = 0;
        }
        else
        {
          p_n4[0] = 68;
          v20 = sqrt(fabs(v19));
          n0x4000_1 = v20 * v14;
          n0x4000 = (int)n0x4000_1;
          n0x10000 = n0x4000;
          if ( n0x4000 >= 0x4000 || (n0x10000 = 4 * (20480 - n0x4000), n0x10000 < 0x10000) )
          {
            if ( ++v16 > 25 )
              return;
            *(float *)&FFX_Render_SharedTransformContext_3 = 5.0;
            v28 = -2139062144;
            HIBYTE(v28) = (unsigned __int8)((unsigned int)(96 * (0x10000 - n0x10000)) >> 16) >> 3;
            n72 = 72;
            v38 = 0;
            v39 = 2 * ((unsigned int)(96 * (0x10000 - n0x10000)) >> 16);
            FFX_Menu2D_ProjectNodeCoords_structural((int)v40, lpamng + 70624, (int)v41);
            FFX_Menu2D_RenderCaptureNoTexture(v15, (int)p_n4);
          }
          lpamng = lpamng;
        }
        v5 = 1.299999952316284;
      }
      v1 += 40;
    }
    while ( v3 );
  }
}


// ============================================================================
// FFX_Abmap_SphereGridBuildVertices @ 0xa505e0 (size 0x56d)
// ============================================================================
// FFX Abmap: Sphere grid build vertices
// ABMAP Sphere Grid build vertices (1.4KB). Builds vertex data for Sphere Grid rendering. Creates nodes, links, and stat bonus indicators. Uses ABMAP data from ps3data/menu/abmap/.
int __usercall FFX_Abmap_SphereGridBuildVertices@<eax>(
        int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg@<ebp>)
{
  double v1; // st7
  unsigned int lpamng; // edi
  int result; // eax
  double v4; // st6
  double v5; // st5
  double v6; // st4
  unsigned int v7; // ecx
  int v8; // eax
  int v9; // eax
  unsigned __int8 v10; // al
  int v11; // eax
  double v12; // st6
  unsigned __int8 v13; // cl
  int n7_2; // esi
  float *j_1; // ecx
  int v16; // eax
  void *hudContext_2; // edx
  FFX_CharacterId charId_2; // ecx
  int n7_1; // esi
  float *i_1; // eax
  void *hudContext_1; // edx
  FFX_CharacterId charId_1; // ecx
  int n7; // esi
  void *hudContext; // edx
  FFX_CharacterId charId; // ecx
  float v26; // [esp+0h] [ebp-1A0h]
  int v27; // [esp+14h] [ebp-18Ch]
  int v28; // [esp+18h] [ebp-188h]
  int v29; // [esp+1Ch] [ebp-184h]
  int v30; // [esp+20h] [ebp-180h]
  int v31; // [esp+24h] [ebp-17Ch]
  int v32; // [esp+28h] [ebp-178h]
  int n7_3; // [esp+2Ch] [ebp-174h]
  int v34; // [esp+30h] [ebp-170h]
  int v35; // [esp+34h] [ebp-16Ch]
  int v36; // [esp+38h] [ebp-168h]
  __int16 *v37; // [esp+40h] [ebp-160h]
  int v38; // [esp+44h] [ebp-15Ch]
  int v39; // [esp+44h] [ebp-15Ch]
  int v40; // [esp+48h] [ebp-158h]
  float *j; // [esp+48h] [ebp-158h]
  float *i; // [esp+48h] [ebp-158h]
  __int16 *v43; // [esp+4Ch] [ebp-154h]
  unsigned __int8 v44; // [esp+53h] [ebp-14Dh]
  _DWORD v45[2]; // [esp+54h] [ebp-14Ch] BYREF
  __int16 v46; // [esp+5Ch] [ebp-144h]
  char v47; // [esp+5Eh] [ebp-142h]
  int v48; // [esp+60h] [ebp-140h]
  int v49; // [esp+64h] [ebp-13Ch]
  int v50; // [esp+68h] [ebp-138h]
  unsigned int v51; // [esp+6Ch] [ebp-134h]
  int v52; // [esp+70h] [ebp-130h]
  _BYTE *v53; // [esp+74h] [ebp-12Ch]
  unsigned int v54; // [esp+78h] [ebp-128h]
  unsigned int v55; // [esp+7Ch] [ebp-124h]
  _BYTE *v56; // [esp+80h] [ebp-120h]
  int v57; // [esp+8Ch] [ebp-114h]
  int v58; // [esp+90h] [ebp-110h]
  int v59; // [esp+94h] [ebp-10Ch]
  __int64 *p_n1006632960; // [esp+98h] [ebp-108h]
  _BYTE v61[64]; // [esp+CCh] [ebp-D4h] BYREF
  _BYTE v62[64]; // [esp+10Ch] [ebp-94h] BYREF
  __int64 n1006632960; // [esp+14Ch] [ebp-54h] BYREF
  FFX_CharacterId FFX_Render_SharedTransformContext; // [esp+154h] [ebp-4Ch]
  float v65; // [esp+158h] [ebp-48h]
  __int64 n1006632960_1; // [esp+15Ch] [ebp-44h]
  FFX_CharacterId FFX_Render_SharedTransformContext_1; // [esp+164h] [ebp-3Ch]
  float v68; // [esp+168h] [ebp-38h]
  __int64 n1006632960_2; // [esp+16Ch] [ebp-34h]
  FFX_CharacterId FFX_Render_SharedTransformContext_2; // [esp+174h] [ebp-2Ch]
  float v71; // [esp+178h] [ebp-28h]
  __int64 n1006632960_3; // [esp+17Ch] [ebp-24h]
  FFX_CharacterId FFX_Render_SharedTransformContext_3; // [esp+184h] [ebp-1Ch]
  float v74; // [esp+188h] [ebp-18h]
  int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1; // [esp+194h] [ebp-Ch]
  void *v76; // [esp+198h] [ebp-8h]
  void *retaddr; // [esp+1A0h] [ebp+0h]

  [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg;
  v76 = retaddr;
  v1 = 1.0;
  lpamng = lpamng;
  v38 = *(__int16 *)(lpamng + 2);
  v43 = (__int16 *)(lpamng + 2056);
  v31 = *(_DWORD *)(lpamng + 71320) << 11;
  v53 = v61;
  p_n1006632960 = &n1006632960;
  v56 = v62;
  v65 = MEMORY[0xC8F514][0];
  v68 = MEMORY[0xC8F514][0];
  v74 = 1.0;
  v71 = MEMORY[0xC8F514][0];
  v55 = lpamng + 70944;
  v54 = lpamng + 71008;
  result = v38;
  v52 = 0;
  v47 = 0;
  v58 = 0;
  v57 = 0;
  v45[1] = byte_1740830;
  v48 = 0;
  v49 = 0;
  v50 = 0;
  v59 = 0;
  n1006632960 = n1006632960_1;
  FFX_Render_SharedTransformContext = FFX_Render_SharedTransformContext;
  n1006632960_1 = n1006632960_1;
  FFX_Render_SharedTransformContext_1 = FFX_Render_SharedTransformContext;
  n1006632960_2 = n1006632960_1;
  FFX_Render_SharedTransformContext_2 = FFX_Render_SharedTransformContext;
  n1006632960_3 = n1006632960_1;
  FFX_Render_SharedTransformContext_3 = FFX_Render_SharedTransformContext;
  if ( v38 )
  {
    v4 = 0.1500000059604645;
    v5 = -96.0;
    v36 = v30;
    v6 = 6.0;
    v35 = v29;
    v32 = v28;
    v34 = v27;
    v7 = lpamng + 2056;
    while ( 1 )
    {
      v39 = result - 1;
      v8 = *(unsigned __int16 *)(v7 + 6);
      if ( (_WORD)v8 == 0xFFFF )
      {
        n7 = 0;
        while ( 1 )
        {
          v26 = v1;
          FFX_Abmap_BuildNodePlacementMatrix((int)v62, (__int16 *)v7, v26);
          FFX_Menu2D_ProjectNodeCoords_structural((int)v61, lpamng + 70624, (int)v62);
          *(float *)&FFX_Render_SharedTransformContext_3 = -1.0;
          v51 = 0;
          FFX_Menu2D_BuildNoTextureVertices(
            charId,
            hudContext,
            dword_23057EC,
            (int)v45,
            *(__int16 *)(lpamng + 2) - v39 - 1,
            n7++);
          if ( n7 >= 7 )
            break;
          lpamng = lpamng;
          v1 = 1.0;
          v7 = (unsigned int)v43;
        }
      }
      else
      {
        v9 = 48 * v8;
        v40 = v9;
        v37 = (__int16 *)(v9 + lpamng + 63548);
        if ( *v37 == 4096 )
        {
          n7_1 = 0;
          i_1 = (float *)(lpamng + v9 + 63544);
          for ( i = i_1; ; i_1 = i )
          {
            FFX_Abmap_BuildNodePlacementMatrix((int)v62, (__int16 *)v7, *i_1);
            FFX_Menu2D_ProjectNodeCoords_structural((int)v61, lpamng + 70624, (int)v62);
            *(float *)&FFX_Render_SharedTransformContext_3 = -1.0;
            v51 = 0;
            FFX_Menu2D_BuildNoTextureVertices(
              charId_1,
              hudContext_1,
              dword_23057EC,
              (int)v45,
              *(__int16 *)(lpamng + 2) - v39 - 1,
              n7_1++);
            if ( n7_1 >= 7 )
              break;
            lpamng = lpamng;
            v7 = (unsigned int)v43;
          }
        }
        else
        {
          v10 = *(_BYTE *)(v7 + 33) & *(_BYTE *)(lpamng + 71113);
          v44 = v10;
          if ( v10 )
          {
            v11 = (int)(v4 * eff_sin_t[((v31 + *(unsigned __int16 *)(v7 + 38)) >> 4) & 0xFFF] * v5);
            v12 = v6;
            v1 = 1.0;
            v13 = 108 - v11;
            v10 = v44;
            v36 = v13;
            v34 = v13;
            v32 = v13;
            v35 = v13;
          }
          else
          {
            v12 = v6;
          }
          v46 = -32668;
          n7_2 = 0;
          j_1 = (float *)(lpamng + v40 + 63544);
          n7_3 = 0;
          for ( j = j_1; ; j_1 = j )
          {
            if ( (v10 & 1) != 0 )
            {
              v16 = FFX_Abmap_Global_C8659C[n7_2];
              j_1 = j;
              n7_2 = n7_3;
              v51 = ((unsigned int)&unk_1FFFFFF & ((v34 * (unsigned __int8)v16) >> 7))
                  + ((((unsigned int)&unk_1FFFFFF & ((v32 * BYTE1(v16)) >> 7))
                    + ((((unsigned int)&unk_1FFFFFF & ((v35 * BYTE2(v16)) >> 7))
                      + (((unsigned int)&unk_1FFFFFF & ((v36 * HIBYTE(v16)) >> 7)) << 8)) << 8)) << 8);
              HIBYTE(v51) = 0x80;
              v45[0] = 44;
            }
            else
            {
              v1 = v12;
              v51 = FFX_Abmap_Global_C86644[n7_2];
              v45[0] = 36;
            }
            *(float *)&FFX_Render_SharedTransformContext_3 = v1;
            FFX_Abmap_BuildNodePlacementMatrix((int)v62, v43, *j_1);
            FFX_Abmap_BuildNodeTransformMatrix((int)v62, v43, v37, 0.00079999998);
            FFX_Menu2D_ProjectNodeCoords_structural((int)v61, lpamng + 70624, (int)v62);
            FFX_Menu2D_BuildNoTextureVertices(
              charId_2,
              hudContext_2,
              dword_23057EC,
              (int)v45,
              *(__int16 *)(lpamng + 2) - v39 - 1,
              n7_2);
            v37 += 2;
            ++n7_2;
            v10 = v44 >> 1;
            n7_3 = n7_2;
            v44 >>= 1;
            if ( n7_2 >= 7 )
              break;
            v1 = 1.0;
            lpamng = lpamng;
            v12 = 6.0;
          }
        }
      }
      result = v39;
      v7 = (unsigned int)(v43 + 20);
      v43 += 20;
      if ( !v39 )
        break;
      v1 = 1.0;
      lpamng = lpamng;
      v5 = -96.0;
      v6 = 6.0;
      v4 = 0.1500000059604645;
    }
  }
  return result;
}


// ============================================================================
// FFX_Abmap_WalkLinkedNodeRequirementChain_structural @ 0xa59760 (size 0x99)
// ============================================================================
// Jarvis goal lot11: structural walk of linked node requirement chain.
// FFX Abmap: Walk linked node requirement chain
unsigned __int16 *__cdecl FFX_Abmap_WalkLinkedNodeRequirementChain_structural(
        __int16 a1,
        int (__cdecl *sub_A49440)(int, int),
        _DWORD *a3)
{
  unsigned __int16 *result; // eax
  unsigned __int16 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int16 v6; // cx

  result = (unsigned __int16 *)sub_A49440(lpamng + 40 * (unsigned __int16)a1 + 2056, (int)a3);
  if ( !result )
  {
    v4 = 0;
    do
    {
      v5 = lpamng + 4 * (5 * *(__int16 *)(lpamng + 4) + 10754);
      result = (unsigned __int16 *)(lpamng + 43016);
      if ( v4 )
        result = v4 + 10;
      if ( (unsigned int)result >= v5 )
        break;
      while ( *result != a1 )
      {
        if ( result[1] == a1 )
        {
          v6 = *result;
          goto LABEL_12;
        }
        result += 10;
        if ( (unsigned int)result >= v5 )
          return result;
      }
      v6 = result[1];
LABEL_12:
      v4 = result;
      result = (unsigned __int16 *)sub_A49440(lpamng + 8 * (5 * v6 + 257), (int)a3);
    }
    while ( !result );
  }
  return result;
}


// ============================================================================
// FFX_Abmap_CheckActivationRuleByNodeType @ 0xa5d120 (size 0x233)
// ============================================================================
// Jarvis goal lot11: checks activation rule by node type; candidate until node-rule ABI is fully recovered.
// FFX Abmap: Check activation rule by node type
BOOL __cdecl FFX_Abmap_CheckActivationRuleByNodeType(int a1, int a2, char *EntryByIdRange, int n7)
{
  bool v4; // zf
  int v6; // esi
  int n7_1; // edi
  bool v8; // zf
  int MatchingChrSlot; // eax
  int n7_2; // esi
  char n0xC; // al
  char n0xC_1; // al

  switch ( a1 )
  {
    case 1:
      v4 = EntryByIdRange[22] == 18;
      goto LABEL_3;
    case 2:
      return EntryByIdRange[22] == 17;
    case 3:
      return !EntryByIdRange[22];
    case 4:
      return EntryByIdRange[22] == 16;
    case 5:
    case 6:
    case 7:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
      return EntryByIdRange[22] == 1;
    case 8:
      v6 = a2;
      n7_1 = n7;
      if ( FFX_Abmap_TestNodeActivationBit(n7, a2) )
        return 0;
      v8 = EntryByIdRange[22] == 15;
      goto LABEL_15;
    case 9:
      v6 = a2;
      n7_1 = n7;
      if ( FFX_Abmap_TestNodeActivationBit(n7, a2) )
        return 0;
      v8 = EntryByIdRange[22] == 14;
      goto LABEL_15;
    case 10:
      v6 = a2;
      n7_1 = n7;
      if ( FFX_Abmap_TestNodeActivationBit(n7, a2) )
        return 0;
      v8 = EntryByIdRange[22] == 12;
      goto LABEL_15;
    case 11:
      v6 = a2;
      n7_1 = n7;
      if ( FFX_Abmap_TestNodeActivationBit(n7, a2) )
        return 0;
      v8 = EntryByIdRange[22] == 13;
LABEL_15:
      if ( !v8 )
        return 0;
      MatchingChrSlot = FFX_Abmap_FindMatchingChrSlot(n7_1, v6);
      return MatchingChrSlot != 0;
    case 12:
      if ( FFX_Abmap_GetSlotNodeIdIfActive(n7) == a2 )
        return 0;
      MatchingChrSlot = FFX_Abmap_TestNodeActivationBit(n7, a2);
      return MatchingChrSlot != 0;
    case 13:
      if ( FFX_Abmap_GetSlotNodeIdIfActive(n7) == a2 )
        return 0;
      MatchingChrSlot = FFX_Abmap_FindMatchingChrSlot(n7, a2);
      return MatchingChrSlot != 0;
    case 14:
      if ( FFX_Abmap_GetSlotNodeIdIfActive(n7) == a2 )
        return 0;
      n7_2 = 0;
      break;
    case 15:
      if ( FFX_Abmap_GetSlotNodeIdIfActive(n7) != a2 )
      {
        v4 = *((_WORD *)EntryByIdRange + 8) >= 0;
LABEL_3:
        if ( v4 )
          return 1;
      }
      return 0;
    case 23:
      n0xC = EntryByIdRange[22];
      return (unsigned __int8)n0xC > 1u && (unsigned __int8)n0xC < 0xCu;
    case 24:
      if ( FFX_Abmap_TestNodeActivationBit(n7, a2) )
        return 0;
      n0xC_1 = EntryByIdRange[22];
      return (unsigned __int8)n0xC_1 > 1u && (unsigned __int8)n0xC_1 < 0xCu && FFX_Abmap_FindMatchingChrSlot(n7, a2);
    default:
      return 0;
  }
  do
  {
    if ( n7 != n7_2 && FFX_Chr_GetSlotFlagBit4(n7_2) && FFX_Abmap_GetSlotNodeIdIfActive(n7_2) == a2 )
      return 1;
    ++n7_2;
  }
  while ( n7_2 < 7 );
  return 0;
}


// ============================================================================
// FFX_Abmap_DispatchNodeActivationRuleReward @ 0xa5cf30 (size 0x188)
// ============================================================================
// Jarvis goal lot11: dispatches node activation rule/reward handling; candidate semantics.
// FFX Abmap: Dispatch node activation rule reward
void __fastcall FFX_Abmap_DispatchNodeActivationRuleReward(FFX_AbmapNodeActivationRule rule, void *nodeData)
{
  int i; // esi
  int v3; // [esp+8h] [ebp+8h]
  int v4; // [esp+Ch] [ebp+Ch]
  int v5; // [esp+10h] [ebp+10h]

  switch ( v3 )
  {
    case 1:
    case 2:
    case 3:
    case 4:
      abmap_cheng_panel(1, v4);
      FFX_Abmap_RenderModeNotify_6E();
      break;
    case 5:
      abmap_cheng_panel(25, v4);
      FFX_Abmap_RenderModeNotify_6D();
      break;
    case 6:
      abmap_cheng_panel(35, v4);
      FFX_Abmap_RenderModeNotify_6D();
      break;
    case 7:
      abmap_cheng_panel(36, v4);
      FFX_Abmap_RenderModeNotify_6D();
      break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 24:
      FFX_Abmap_ActivateNodeWithNotify(v5, v4);
      break;
    case 12:
    case 13:
    case 14:
    case 15:
      FFX_Abmap_MarkActivationPosted(v5, v4);
      break;
    case 16:
      abmap_cheng_panel(5, v4);
      FFX_Abmap_RenderModeNotify_6D();
      break;
    case 17:
      abmap_cheng_panel(9, v4);
      FFX_Abmap_RenderModeNotify_6D();
      break;
    case 18:
      abmap_cheng_panel(13, v4);
      FFX_Abmap_RenderModeNotify_6D();
      break;
    case 19:
      abmap_cheng_panel(17, v4);
      FFX_Abmap_RenderModeNotify_6D();
      break;
    case 20:
      abmap_cheng_panel(21, v4);
      FFX_Abmap_RenderModeNotify_6D();
      break;
    case 21:
      abmap_cheng_panel(29, v4);
      FFX_Abmap_RenderModeNotify_6D();
      break;
    case 22:
      abmap_cheng_panel(33, v4);
      FFX_Abmap_RenderModeNotify_6D();
      break;
    case 23:
      abmap_cheng_panel(1, v4);
      for ( i = 0; i < 7; ++i )
        FFX_Abmap_ClearNodeActivationBit(i, v4);
      FFX_Abmap_RenderModeNotify_6E();
      break;
    default:
      return;
  }
}


// ============================================================================
// FFX_Abmap_ConsumeItemAndActivateNode @ 0xa5bca0 (size 0xa4)
// ============================================================================
// Jarvis goal lot11: consumes selected item and activates node; calls FFX_Inventory_AddItem(-1).
// FFX Abmap: Consume item and activate node
void __cdecl FFX_Abmap_ConsumeItemAndActivateNode(int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // ebx
  unsigned __int8 v5; // al
  void *nodeData; // edx
  FFX_AbmapNodeActivationRule rule; // ecx
  char *EntryByIdRange; // eax

  v3 = a2;
  if ( (*(_BYTE *)(lpamng + 40 * a2 + 2090) & 3) != 0 )
  {
    v4 = a3;
    if ( FFX_Abmap_TestAndMarkInventoryItemForNode(a1, a2, a3) )
    {
      if ( !FFX_Inventory_AddItem(v4, -1) )
      {
        v5 = FFX_Menu_GetCommandTableEntry(v4, &a2)[93];
        if ( v5 == 0xFF )
          EntryByIdRange = 0;
        else
          EntryByIdRange = FFX_Table_GetEntryByIdRange(v5, (__int16 *)sphere_bin_ptr, &a2);
        if ( EntryByIdRange[13] )
        {
          FFX_Abmap_DispatchNodeActivationRuleReward(rule, nodeData);
        }
        else
        {
          FFX_RenderEngine_ModeNotify();
          FFX_Abmap_ActivateNode(a1, v3);
        }
      }
    }
  }
}


// [FAIL] FFX_SphereGrid_ApplyLearnedMove_structural @ 0x798850 — decompile returned None
// [FAIL] FFX_SphereGrid_SetGlobalAbilityLearned @ 0x785e00 — decompile returned None
// [FAIL] FFX_SphereGrid_SetCharacterAbilityLearned @ 0x785ec0 — decompile returned None
// [FAIL] FFX_SphereGrid_IsAbilityLearned @ 0x785170 — decompile returned None
// [FAIL] FFX_SphereGrid_IsCharacterAbilityLearned @ 0x785200 — decompile returned None
// [FAIL] FFX_SphereGrid_AddApAndCheckLevelUp @ 0x7846c0 — decompile returned None
// [FAIL] FFX_SphereGrid_ConsumeLevelAndTrackOverflow @ 0x786fb0 — decompile returned None
// [FAIL] FFX_SphereGrid_ComputeNextLevelApRequirement @ 0x784f50 — decompile returned None
// ============================================================================
// DONE: 17 OK, 8 FAIL
// ============================================================================