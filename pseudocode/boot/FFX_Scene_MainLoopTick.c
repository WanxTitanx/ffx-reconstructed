/*
 * Function: FFX_Scene_MainLoopTick
 * Address:   0x66B370
 * Prototype: int __thiscall FFX_Scene_MainLoopTick(void *this)
 *
 * Main loop tick. Drives the game's main loop:
 * - Updates frame delta timer (Phyre)
 * - Processes color fade (post-processing)
 * - Emits particles
 * - Destroys frame buffers
 * - Begins render scene
 * - Peeks and dispatches Windows messages
 * - Releases cluster handles
 * - Sleeps when not in active state (100ms idle, 60ms active)
 *
 * Callees:
 *   GetGlobalSystemContext
 *   Phyre_Timer_UpdateFrameDelta
 *   FFX_PostProc_UpdateColorFade
 *   FFX_Particle_Emit
 *   Phyre_FrameBuffer_DestroyAll
 *   Phyre_Renderer_BeginSceneWithTimeline
 *   FFX_Win32_PeekAndDispatchMessage
 *   Sys_Sleep
 *   FFX_Scene_ReleaseAllClusterHandles
 *   ExitProcess (on WM_QUIT)
 */

int __thiscall FFX_Scene_MainLoopTick(void *this)
{
  int result; // eax
  _BYTE *fieldE4; // esi
  float *GlobalSystemContext; // eax
  int v5; // eax
  float v6; // [esp+Ch] [ebp-4h]

  if ( *(_BYTE *)(GetGlobalSystemContext() + 928) || *(_BYTE *)(GetGlobalSystemContext() + 929) )
  {
    fieldE4 = (_BYTE *)(GetGlobalSystemContext() + 292);
    GlobalSystemContext = (float *)GetGlobalSystemContext();
    Phyre_Timer_UpdateFrameDelta(GlobalSystemContext);
    v6 = *(float *)(GetGlobalSystemContext() + 36);
    *unk_CE516C = 1;
    FFX_PostProc_UpdateColorFade(unk_CE516C, v6);
    FFX_Particle_Emit(unk_CE516C, (int)fieldE4);
    *unk_CE516C = 0;
    if ( *(_DWORD *)&word_18762A0[554214] )
      Phyre_FrameBuffer_DestroyAll(*(int *)&word_18762A0[554214]);
    result = Phyre_Renderer_BeginSceneWithTimeline(fieldE4);
    if ( !result )
    {
      result = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)fieldE4 + 8))(fieldE4);
      if ( !result )
      {
        v5 = GetGlobalSystemContext();
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 40))(v5);
        if ( FFX_Win32_PeekAndDispatchMessage() )
          ExitProcess(0);
        Sys_Sleep(0x3Cu);
        FFX_Scene_ReleaseAllClusterHandles((int)this);
        return 0;
      }
    }
  }
  else
  {
    if ( FFX_Win32_PeekAndDispatchMessage() )
      ExitProcess(0);
    Sys_Sleep(0x64u);
    return 0;
  }
  return result;
}
