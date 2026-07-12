/*
 * Function: FFX_UI_TitleAndMenuFlow
 * Address:   0x641870
 * Prototype: int FFX_UI_TitleAndMenuFlow()
 *
 * Handles title screen and menu navigation flow.
 * Loads input device icon textures, initializes opening SWF,
 * waits for menu/input gates, and may enter pause/ESC menu SWFs.
 * Key flow: load openingscreen.swf -> wait for flag -> menu loop
 *
 * Callees:
 *   FFX_PS3_GetSaveDataPtr, FFX_PS3_Stub_Return0
 *   AsyncQueue_GetGlobal, AsyncQueue_PushWithMutex
 *   FFX_Menu_LoadInputDeviceIconTextures
 *   FFX_BtlUI_HudMenu_SetSelection
 *   Phyre_FrameBufferSingleton_Init
 *   GetGlobalSystemContext
 *   Phyre_IggyAS3_InitSystem
 *   FFX_Particle_SetTexture
 *   FFX_Flash_LoadOpeningScreenSwf
 *   Phyre_PInputDevice_RefreshAll
 *   FFX_GameLoop_SubTick
 *   FFX_GlobalFlag_Get_CCB9C2
 *   AsyncQueue_IsIdle
 *   FFX_AsyncJobQueue_Push
 *   FFX_FieldRender_DispatchDebugWrapper
 *   FFX_UI_DestroyIggyMenu
 *   FFX_Scene_MainLoopTick
 *   FFX_Engine_CheckFlagByte1
 *   FFX_PS3_Stub3_Return1
 *   JobWorker_IsQueueFull
 *   FFX_Flash_InitPauseEscMenuSwfs
 */

int FFX_UI_TitleAndMenuFlow()
{
  int Global; // eax
  char v1; // bl
  int v2; // edi
  int n30; // esi
  int GlobalSystemContext; // eax
  int v5; // eax
  int n30_1; // esi
  _DWORD *v7; // eax
  int v8; // esi
  int v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  int v12; // esi
  int v13; // eax
  float v15; // [esp+0h] [ebp-Ch] BYREF
  float v16; // [esp+4h] [ebp-8h] BYREF
  int v17; // [esp+8h] [ebp-4h] BYREF

  if ( FFX_PS3_GetSaveDataPtr() )
  {
    FFX_PS3_GetSaveDataPtr();
    FFX_PS3_Stub_Return0();
  }
  Global = AsyncQueue_GetGlobal();
  AsyncQueue_PushWithMutex(Global, (int)FFX_Menu_LoadInputDeviceIconTextures, 0);
  v17 = 0;
  v1 = 1;
  FFX_BtlUI_HudMenu_SetSelection();
  Phyre_FrameBufferSingleton_Init();
  v2 = *(_DWORD *)(GetGlobalSystemContext() + 624);
  n30 = *(_DWORD *)(GetGlobalSystemContext() + 620);
  GlobalSystemContext = GetGlobalSystemContext();
  Phyre_IggyAS3_InitSystem(*(int **)&word_18762A0[554214], GlobalSystemContext + 292, n30, v2);
  *(_BYTE *)(GetGlobalSystemContext() + 928) = 0;
  v15 = 3.0;
  v16 = 0.0;
  FFX_Particle_SetTexture((int)unk_CE516C, &v15, 0, &v16);
  if ( *(int *)(GetGlobalSystemContext() + 936) <= 1 )
    goto LABEL_11;
  v5 = strcmp(*(const char **)(*(_DWORD *)(GetGlobalSystemContext() + 932) + 4), "_ECalm");
  if ( v5 )
    v5 = v5 < 0 ? -1 : 1;
  if ( v5 )
  {
LABEL_11:
    FFX_Flash_LoadOpeningScreenSwf((_DWORD *)MEMORY[0xCCB9D8]);
    while ( FFX_GlobalFlag_Get_CCB9C2() )
    {
      Phyre_PInputDevice_RefreshAll();
      FFX_GameLoop_SubTick((void *)MEMORY[0xCCB9D8]);
      if ( v1 )
      {
        v7 = (_DWORD *)AsyncQueue_GetGlobal();
        if ( AsyncQueue_IsIdle(v7) )
        {
          v8 = GetGlobalSystemContext();
          v9 = GetGlobalSystemContext();
          FFX_AsyncJobQueue_Push(
            unk_CDEDD4,
            (int (__cdecl *)(int, int, int))FFX_FieldRender_DispatchDebugWrapper,
            &v17,
            *(_DWORD *)(v9 + 936),
            *(_DWORD *)(v8 + 932),
            0);
          v1 = 0;
        }
      }
    }
    FFX_UI_DestroyIggyMenu(MEMORY[0xCCB9D8], v2);
    *(_BYTE *)(GetGlobalSystemContext() + 928) = 1;
  }
  else
  {
    *(_BYTE *)(GetGlobalSystemContext() + 928) = 1;
    if ( !FFX_Engine_CheckFlagByte1() )
    {
      n30_1 = 30;
      do
      {
        FFX_Scene_MainLoopTick((void *)MEMORY[0xCCB9D8]);
        --n30_1;
      }
      while ( n30_1 );
    }
  }
  if ( FFX_PS3_GetSaveDataPtr() )
  {
    if ( !FFX_Engine_CheckFlagByte1() )
    {
      FFX_PS3_GetSaveDataPtr();
      while ( !FFX_PS3_Stub3_Return1() )
      {
        if ( !FFX_Engine_CheckFlagByte1() )
          FFX_Scene_MainLoopTick((void *)MEMORY[0xCCB9D8]);
        FFX_PS3_GetSaveDataPtr();
      }
    }
  }
  v10 = (_DWORD *)AsyncQueue_GetGlobal();
  if ( !AsyncQueue_IsIdle(v10) )
  {
    do
    {
      if ( !FFX_Engine_CheckFlagByte1() )
        FFX_Scene_MainLoopTick((void *)MEMORY[0xCCB9D8]);
      if ( unk_CCC7BC )
        return 0;
      v11 = (_DWORD *)AsyncQueue_GetGlobal();
    }
    while ( !AsyncQueue_IsIdle(v11) );
  }
  if ( FFX_Engine_CheckFlagByte1() )
    return 0;
  *(_BYTE *)(GetGlobalSystemContext() + 929) = 1;
  *(_BYTE *)(GetGlobalSystemContext() + 928) = 0;
  if ( v1 )
  {
    v12 = GetGlobalSystemContext();
    v13 = GetGlobalSystemContext();
    FFX_AsyncJobQueue_Push(
      unk_CDEDD4,
      (int (__cdecl *)(int, int, int))FFX_FieldRender_DispatchDebugWrapper,
      &v17,
      *(_DWORD *)(v13 + 936),
      *(_DWORD *)(v12 + 932),
      0);
  }
  while ( !JobWorker_IsQueueFull(unk_CDEDD4, 0) )
    FFX_Scene_MainLoopTick((void *)MEMORY[0xCCB9D8]);
  *(_BYTE *)(GetGlobalSystemContext() + 929) = 0;
  if ( v17 == 1 )
    return FFX_Flash_InitPauseEscMenuSwfs(MEMORY[0xCCB9D8]);
  else
    return 9;
}
