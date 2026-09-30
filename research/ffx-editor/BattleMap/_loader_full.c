// FFX FieldMap: Load encounter guide from ffxmap ID
int FFX_FieldMap_LoadEncounterGuideFromFfxmapId()
{
  const char *v0; // edi
  const char *v1; // ebx
  int EncounterGuideIdx; // eax
  int v3; // eax
  char *v4; // ecx
  char *v5; // edx
  char *v6; // edi
  char v7; // al
  char *v8; // edx
  char v9; // al
  int *FfxmapIdFile; // eax
  const char */ffx/proj/map/master/%s/%s/bin; // [esp-Ch] [ebp-DCh]
  const char *v13; // [esp-8h] [ebp-D8h]
  const char *v14; // [esp-4h] [ebp-D4h]
  char Buffer_1[64]; // [esp+Ch] [ebp-C4h] BYREF
  char Buffer[64]; // [esp+4Ch] [ebp-84h] BYREF
  char ArgList[64]; // [esp+8Ch] [ebp-44h] BYREF

  FFX_FieldMap_ResetStateAndGuidemap(); // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0x844d26*/
  sg_buf = 0; /*0x844d33*/
  v0 = &unk_1303540[64 * dword_C4DF50]; /*0x844d3a*/
  v1 = &unk_1303480[64 * dword_C4DF50]; /*0x844d40*/
  unk_1303600 = v0; /*0x844d46*/
  unk_1303604 = v1; /*0x844d4c*/
  EncounterGuideIdx = FFX_FieldMap_GetEncounterGuideIdx(); /*0x844d52*/
  if ( !EncounterGuideIdx ) /*0x844d60*/
  {
    v14 = v1; /*0x844e00*/
    v13 = v0; /*0x844e01*/
    /ffx/proj/map/master/%s/%s/bin = "/ffx/proj/map/master/%s/%s/bin"; /*0x844e02*/
    goto LABEL_12; /*0x844e02*/
  }
  v3 = EncounterGuideIdx - 1; /*0x844d66*/
  if ( !v3 ) /*0x844d67*/
  {
    v14 = v1; /*0x844d83*/
    v13 = v0; /*0x844d84*/
    /ffx/proj/map/master/%s/%s/bin = "/ffx/proj/map/sugi/data/%s/%s/map"; /*0x844d85*/
    if ( unk_1303479 ) /*0x844d8a*/
    {
      sprintf(&sg_buf, "/ffx/proj/map/sugi/data/%s/%s/map", v0, v1); /*0x844d91*/
      v4 = (char *)unk_1303604; /*0x844d93*/
      v5 = (char *)unk_1303604; /*0x844d9f*/
      v6 = &ArgList[-unk_1303604]; /*0x844da1*/
      do /*0x844dad*/
      {
        v7 = *v5; /*0x844da3*/
        v5[(_DWORD)v6] = *v5; /*0x844da5*/
        ++v5; /*0x844da8*/
      }
      while ( v7 ); /*0x844dad*/
      v8 = (char *)(Buffer_1 - v4); /*0x844db5*/
      do /*0x844dc1*/
      {
        v9 = *v4; /*0x844db7*/
        v4[(_DWORD)v8] = *v4; /*0x844db9*/
        ++v4; /*0x844dbc*/
      }
      while ( v9 ); /*0x844dc1*/
      ArgList[4] = 0; /*0x844dc3*/
      Buffer_1[6] = 0; /*0x844dc6*/
      sprintf(Buffer, "/ffx/proj/map/master/%s/%s/bin", ArgList, Buffer_1); /*0x844de3*/
      dbgPrintf(); /*0x844df6*/
      goto LABEL_13; /*0x844dfe*/
    }
LABEL_12:
    sprintf(Buffer, /ffx/proj/map/master/%s/%s/bin, v13, v14); /*0x844e07*/
    goto LABEL_13; /*0x844e0e*/
  }
  if ( v3 == 1 ) /*0x844d6a*/
    sprintf(Buffer, "/ffx/proj/map/btlmaster/%s/%s/bin", v0, v1); /*0x844d77*/
LABEL_13:
  sprintf(ArgList, "%s/mapobjdata.vpb", Buffer); /*0x844e13*/
  sprintf(Buffer_1, "%s/maptexdata.txb", Buffer); /*0x844e38*/
  FFX_FieldMap_LoadAndProcessFieldVpa(ArgList); /*0x844e45*/
  if ( !sg_buf /*0x844e74*/
    || (sprintf(ArgList, "%s/ffxmap.id", &sg_buf), (FfxmapIdFile = FFX_FieldMap_ReadFfxmapIdFile(ArgList)) == 0) )
  {
    sprintf(ArgList, "%s/ffxmap.id", Buffer); /*0x844e86*/
    FfxmapIdFile = FFX_FieldMap_ReadFfxmapIdFile(ArgList); /*0x844e8c*/
  }
  return FFX_FieldMap_RegisterGuideMapBlob((unsigned int)FfxmapIdFile); /*0x844ea0*/
}