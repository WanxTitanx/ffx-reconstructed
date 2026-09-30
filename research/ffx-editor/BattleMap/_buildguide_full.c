// FFX FieldMap: Build guide mesh from mapout polys
void __cdecl FFX_FieldMap_BuildGuideMeshFromMapoutPolys(float *a1)
{
  unsigned int ActiveGuideMapRoot; // ebx
  int n512_1; // esi
  int v3; // edi
  int n512; // ecx
  int v5; // edi
  int *v6; // eax
  int *v7; // esi
  int v8; // eax
  int v9; // edi
  int *v10; // edi
  void *hudContext; // edx
  FFX_CharacterId charId; // ecx
  int v13; // esi
  int v14; // edi
  int v15; // eax
  int v16; // ebx
  _WORD *v17; // edi
  int v18; // [esp+10h] [ebp-20h]
  int v19; // [esp+10h] [ebp-20h]
  float v20; // [esp+1Ch] [ebp-14h]
  float ScaleDiv10; // [esp+1Ch] [ebp-14h]
  int v22; // [esp+1Ch] [ebp-14h]
  int *v23; // [esp+20h] [ebp-10h]
  unsigned int ActiveGuideMapRoot_1; // [esp+24h] [ebp-Ch]
  int v25; // [esp+28h] [ebp-8h]
  int v26; // [esp+28h] [ebp-8h]
  int n512_2; // [esp+2Ch] [ebp-4h]
  int *inited; // [esp+2Ch] [ebp-4h]

  // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0x91d5eb*/
  if ( *((_DWORD *)a1 + 2) ) /*0x91d5eb*/
  {
    FFX_RcBg_FreeModelBuffer(*((_DWORD *)a1 + 2)); /*0x91d5f3*/
    a1[2] = 0.0; /*0x91d5fb*/
  }
  *a1 = 0.0; /*0x91d602*/
  ActiveGuideMapRoot = FFX_FieldMap_GetActiveGuideMapRoot(); /*0x91d60d*/
  ActiveGuideMapRoot_1 = ActiveGuideMapRoot; /*0x91d60f*/
  *((_DWORD *)a1 + 1) = ActiveGuideMapRoot; /*0x91d612*/
  if ( ActiveGuideMapRoot ) /*0x91d617*/
  {
    n512_1 = 0; /*0x91d61e*/
    v3 = 0; /*0x91d622*/
    n512_2 = 0; /*0x91d624*/
    if ( *(__int16 *)(ActiveGuideMapRoot + 6) > 0 ) /*0x91d62b*/
    {
      do /*0x91d652*/
      {
        n512 = *(__int16 *)(Std_IdentityFunc(*(_DWORD *)(ActiveGuideMapRoot + 28)) + n512_1 + 8) + n512_2; /*0x91d640*/
        ++v3; /*0x91d646*/
        n512_2 = n512; /*0x91d64a*/
        n512_1 += 16; /*0x91d64d*/
      }
      while ( v3 < *(__int16 *)(ActiveGuideMapRoot + 6) ); /*0x91d652*/
      if ( n512 >= 512 ) /*0x91d65a*/
      {
        rcPrint(); /*0x91d667*/
        return; /*0x91d675*/
      }
      n512_1 = n512; /*0x91d676*/
    }
    v5 = *(__int16 *)(ActiveGuideMapRoot + 10); /*0x91d679*/
    v18 = v5; /*0x91d67d*/
    inited = FFX_RcBg_AllocAndInitSceneObject(); /*0x91d68c*/
    FFX_RcBg_BuildDeclFromMeshSubset((int)inited, 0, n512_1, v5, 0); /*0x91d68f*/
    v6 = FFX_Heap_AllocGameArena(16 * v5); /*0x91d6a4*/
    v23 = v6; /*0x91d6b3*/
    v25 = 0; /*0x91d6b6*/
    v20 = 1.0 / *(float *)(ActiveGuideMapRoot + 12); /*0x91d6bd*/
    if ( v5 > 0 ) /*0x91d6c2*/
    {
      v7 = v6 + 2; /*0x91d6c4*/
      do /*0x91d720*/
      {
        *((float *)v7 - 2) = (double)*(__int16 *)(Std_IdentityFunc(*(_DWORD *)(ActiveGuideMapRoot + 24)) + 8 * v25) /*0x91d6e5*/
                           * v20;
        *((float *)v7 - 1) = 0.0; /*0x91d6ea*/
        v8 = *(__int16 *)(Std_IdentityFunc(*(_DWORD *)(ActiveGuideMapRoot + 24)) + 8 * (v25 + 1) - 4); /*0x91d6f9*/
        v7 += 4; /*0x91d704*/
        ++v25; /*0x91d70a*/
        *((float *)v7 - 4) = (double)v8 * v20; /*0x91d716*/
        *((float *)v7 - 3) = 0.0; /*0x91d71b*/
      }
      while ( v25 < v5 ); /*0x91d720*/
      v6 = v23; /*0x91d722*/
    }
    FFX_Render_ComputeAABB((float *)inited + 36, (int)v6, v5); /*0x91d731*/
    v9 = inited[5] + *(_DWORD *)(inited[5] + 8); /*0x91d740*/
    ScaleDiv10 = FFX_Render_SceneProcessTick((float *)inited + 36); /*0x91d747*/
    FFX_BtlUI_ConvertIconCoordsInt16(v9, v23, v18, ScaleDiv10); /*0x91d75a*/
    v10 = inited; /*0x91d762*/
    FFX_RcBg_SetScale10(charId, hudContext, (int)inited, ScaleDiv10); /*0x91d76d*/
    v13 = FFX_RcBg_CalcBufferSizeWithExtra((int)inited, 0); /*0x91d77a*/
    v22 = 0; /*0x91d781*/
    if ( *(__int16 *)(ActiveGuideMapRoot + 6) > 0 ) /*0x91d78c*/
    {
      v14 = 0; /*0x91d792*/
      v26 = 0; /*0x91d794*/
      do /*0x91d841*/
      {
        v15 = Std_IdentityFunc(*(_DWORD *)(ActiveGuideMapRoot + 28)); /*0x91d79a*/
        v19 = Std_IdentityFunc(*(_DWORD *)(v15 + v14 + 12)); /*0x91d7a9*/
        v16 = 0; /*0x91d7af*/
        if ( *(__int16 *)(Std_IdentityFunc(*(_DWORD *)(ActiveGuideMapRoot_1 + 28)) + v14 + 8) > 0 ) /*0x91d7c3*/
        {
          v17 = (_WORD *)(v19 + 4); /*0x91d7c8*/
          do /*0x91d827*/
          {
            *(_DWORD *)(v13 + 1) = -8323073; /*0x91d7d0*/
            *(_BYTE *)v13 = -1; /*0x91d7d7*/
            *(_DWORD *)(v13 + 5) = -8323073; /*0x91d7da*/
            *(_WORD *)(v13 + 9) = -1; /*0x91d7e1*/
            *(_BYTE *)(v13 + 11) = 0x80; /*0x91d7e7*/
            *(_WORD *)(v13 + 12) = *(v17 - 2); /*0x91d7ef*/
            *(_WORD *)(v13 + 14) = *(v17 - 1); /*0x91d7f7*/
            *(_WORD *)(v13 + 16) = *v17; /*0x91d7fe*/
            *(_WORD *)(v13 + 18) = 0; /*0x91d804*/
            v13 += 20; /*0x91d80b*/
            ++v16; /*0x91d811*/
            v17 += 8; /*0x91d812*/
          }
          while ( v16 < *(__int16 *)(Std_IdentityFunc(*(_DWORD *)(ActiveGuideMapRoot_1 + 28)) + v26 + 8) ); /*0x91d827*/
          v14 = v26; /*0x91d829*/
        }
        ActiveGuideMapRoot = ActiveGuideMapRoot_1; /*0x91d82b*/
        v14 += 16; /*0x91d836*/
        ++v22; /*0x91d839*/
        v26 = v14; /*0x91d83c*/
      }
      while ( v22 < *(__int16 *)(ActiveGuideMapRoot_1 + 6) ); /*0x91d841*/
      v10 = inited; /*0x91d847*/
    }
    v10[4] |= 6u; /*0x91d84d*/
    if ( v23 ) /*0x91d853*/
      FFX_Heap_FreeGameArena((unsigned int)v23); /*0x91d856*/
    *((_DWORD *)a1 + 2) = v10; /*0x91d862*/
    FFX_BuildGuideMeshDimensions(a1); /*0x91d865*/
  }
}