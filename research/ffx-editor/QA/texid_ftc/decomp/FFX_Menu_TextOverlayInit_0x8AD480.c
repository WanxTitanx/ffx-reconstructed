// FFX Menu: Text overlay init
_DWORD *FFX_Menu_TextOverlayInit()
{
  int ThreadDataDeref; // eax
  int ThreadDataDeref_1; // esi
  void *v2; // ecx
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  void *AreaFtc; // eax
  unsigned int AreaFtc_1; // esi
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  char *v16; // eax
  unsigned int v17; // esi
  int CurrentId; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int n4; // esi
  int v23; // edx
  int v24; // ecx
  int v25; // edx
  int v26; // ecx
  int v27; // edx
  int v28; // ecx
  int v29; // edx
  int v30; // ecx
  int v31; // edx
  int v32; // ecx
  _DWORD *TextOverlayBuf; // eax
  int v34; // edx
  int v35; // ecx
  int v36; // edx
  int v37; // ecx
  int v38; // edx
  int v39; // ecx
  int v40; // edx
  int v41; // ecx
  int v42; // edx
  int v43; // ecx
  void *v44; // ecx
  int i; // esi
  int j; // esi
  int k; // esi
  int m; // esi
  FFX_MenuObjectState state; // ecx
  _DWORD *result; // eax

  ThreadDataDeref = FFX_JobSchedule_GetThreadDataDeref(); /*0x8ad481*/
  ThreadDataDeref_1 = ThreadDataDeref; /*0x8ad486*/
  if ( !ThreadDataDeref || ThreadDataDeref == 3 ) /*0x8ad48f*/
    IsForceDisplaySubtitle = 0; /*0x8ad491*/
  FFX_Font_SetupLocaleFontPage(); /*0x8ad49b*/
  FFX_Menu_ListInputCb(v2); /*0x8ad4a0*/
  FFX_Menu_ClearBufferBlock(); /*0x8ad4a5*/
  FFX_Menu_TextOverlayInitBuffer(); /*0x8ad4aa*/
  unk_1841DCC = 0; /*0x8ad4af*/
  unk_186597C = 0; /*0x8ad4b9*/
  unk_1841CE0 = (FFX_Locale_GetCurrentId(v3) != 1 || ThreadDataDeref_1 == 3) && FFX_Locale_GetCurrentId(v4); /*0x8ad4e7*/
  dbgPrintf(); /*0x8ad4f6*/
  if ( FFX_Locale_GetCurrentId(v5) == 10 || !FFX_Locale_GetCurrentId(v6) || FFX_Locale_GetCurrentId(v7) == 9 ) /*0x8ad519*/
    AreaFtc = FFX_File_LoadAreaFtc("base"); /*0x8ad52e*/
  else
    AreaFtc = FFX_Menu_EditBoxCharInsert(v9, v8, 4, 0); /*0x8ad51f*/
  AreaFtc_1 = (unsigned int)AreaFtc; /*0x8ad536*/
  FFX_FTC_RegisterLoadedFontSlot((int)AreaFtc); /*0x8ad539*/
  Engine_HeapFreeThunk(AreaFtc_1); /*0x8ad53f*/
  if ( FFX_Locale_GetCurrentId(v12) == 10 || !FFX_Locale_GetCurrentId(v13) || FFX_Locale_GetCurrentId(v14) == 9 ) /*0x8ad562*/
  {
    v16 = FFX_File_LoadAreaFtc("newkit"); /*0x8ad569*/
    v17 = (unsigned int)v16; /*0x8ad56e*/
    if ( v16 ) /*0x8ad575*/
    {
      FFX_FTC_RegisterLoadedFontSlot((int)v16); /*0x8ad578*/
      Engine_HeapFreeThunk(v17); /*0x8ad57e*/
    }
  }
  CurrentId = FFX_Locale_GetCurrentId(v15); /*0x8ad586*/
  FFX_MenuFontTexture_LoadByCCC820(CurrentId); /*0x8ad58c*/
  if ( FFX_Locale_GetCurrentId(v19) == 17 || (n4 = 18, FFX_Locale_GetCurrentId(v21) == 9) ) /*0x8ad5ab*/
    n4 = 4; /*0x8ad5ad*/
  unk_1841DC0 = FFX_Menu_EditBoxCharInsert(v21, v20, n4, 11); /*0x8ad5bd*/
  unk_1841DC4 = FFX_Menu_EditBoxCharInsert(v24, v23, n4, 10); /*0x8ad5ca*/
  unk_1841D5C = FFX_Menu_EditBoxCharInsert(v26, v25, n4, 15); /*0x8ad5d7*/
  unk_1841D58 = FFX_Menu_EditBoxCharInsert(v28, v27, n4, 14); /*0x8ad5e4*/
  unk_1841DC8 = FFX_Menu_EditBoxCharInsert(v30, v29, n4, 8); /*0x8ad5f6*/
  FFX_Menu_EditBoxCursorUpdate(v32, v31, n4, 6, (int)&toSpecialDicBuff); /*0x8ad5fb*/
  p_toSpecialDicBuff = &toSpecialDicBuff; /*0x8ad600*/
  TextOverlayBuf = FFX_Menu_GetTextOverlayBuf(); /*0x8ad60a*/
  FFX_Scene_LoadPakGroup("albheddic", TextOverlayBuf); /*0x8ad615*/
  FFX_Menu_EditBoxCursorUpdate(v35, v34, n4, 7, (int)&toFFXToSjisTbl); /*0x8ad622*/
  FFX_Menu_EditBoxCursorUpdate(v37, v36, n4, 22, (int)&unk_1841DD0); /*0x8ad632*/
  unk_1841D54 = FFX_Menu_EditBoxCharInsert(v39, v38, 18, 19); /*0x8ad649*/
  FFX_Menu_EditBoxCursorUpdate(v41, v40, 18, 20, (int)&unk_185F5D0); /*0x8ad64e*/
  FFX_Menu_EditBoxCursorUpdate(v43, v42, 18, 21, (int)&unk_185FDD0); /*0x8ad65c*/
  FFX_Menu_ClearTextOverlay(); /*0x8ad661*/
  FFX_Menu_ClearTextOverlayState(); /*0x8ad666*/
  FFX_Menu_Widget_SetLayerTable(0, (int)&unk_185F5D0); /*0x8ad672*/
  FFX_Menu_Widget_SetLayerTable(1, (int)&unk_185FDD0); /*0x8ad67e*/
  FFX_Menu_Widget_SetLayerTable(2, (int)&unk_1841DD0); /*0x8ad68a*/
  FFX_Menu_InitDummyVarValues(v44); /*0x8ad692*/
  FFX_Save_BufferGrow(); /*0x8ad697*/
  *(_WORD *)separator = 20498; /*0x8ad69e*/
  unk_25D09BE = 0; /*0x8ad6a7*/
  FFX_Save_ToggleBufferBasePointers(1); /*0x8ad6ae*/
  for ( i = 0; i < 8; ++i ) /*0x8ad6b6*/
    FFX_Save_InitBufferSlot(i); /*0x8ad6b9*/
  for ( j = 0; j < 8; ++j ) /*0x8ad6c7*/
    FFX_Save_BufferVerifyIntegrity(j); /*0x8ad6d1*/
  FFX_Save_ToggleBufferBasePointers(0); /*0x8ad6e1*/
  for ( k = 0; k < 8; ++k ) /*0x8ad6e9*/
    FFX_Save_InitBufferSlot(k); /*0x8ad6f1*/
  for ( m = 0; m < 8; ++m ) /*0x8ad6ff*/
    FFX_Save_BufferVerifyIntegrity(m); /*0x8ad702*/
  FFX_Btl_AnimatedBgClipRectSet(); /*0x8ad710*/
  FFX_Menu_StateAdvance(state); /*0x8ad715*/
  result = FFX_BtlUI_ComputeFormationSlotCoords(); /*0x8ad71a*/
  toMonitorFlag = 0; /*0x8ad71f*/
  return result; /*0x8ad726*/
}
