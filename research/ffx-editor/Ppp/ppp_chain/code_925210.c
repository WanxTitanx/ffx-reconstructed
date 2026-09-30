// FFX MagicHost: Init object buffer
int __cdecl FFX_MagicHost_InitObjectBuffer(
        int a1,
        int n2,
        int a3,
        _DWORD *a4,
        int a5,
        int a6,
        int a7,
        int a8,
        _DWORD *[Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg)
{
  int v9; // ebx
  FFX_BattleContext *battleContext; // edx
  FFX_TeamType teamType; // ecx
  int v12; // eax
  int v13; // ecx
  _DWORD *v14; // edx
  int v15; // edi
  int source_copy; // eax
  FFXMagicHost *host; // ecx
  void *blob; // edx

  FFX_MagicHost_AttachPppResourceBuffer([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg, 0, a4, a5); /*0x925222*/
  v9 = a7; /*0x92522f*/
  *(_DWORD *)FFX_PppResourceDescriptorTablePtr = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; /*0x925232*/
  *(_DWORD *)(a1 + 4) = n2; /*0x925237*/
  *(_DWORD *)(a1 + 8) = a3; /*0x92523d*/
  *(_DWORD *)(a1 + 12) = a6; /*0x925243*/
  *(_DWORD *)a1 = 0; /*0x925246*/
  *(_DWORD *)(a1 + 16) = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; /*0x92524c*/
  *(_DWORD *)(a1 + 20) = a7; /*0x92524f*/
  *(_DWORD *)(a1 + 24) = FFX_Menu2D_PppMemAlloc( /*0x92526b*/
                           *(_DWORD *)FFX_PppResourceDescriptorTablePtr,
                           *(_DWORD *)FFX_PppResourceDescriptorTablePtr + 16,
                           4 * a7);
  FFX_Menu2D_InitSlotNode((_DWORD *)(a1 + 28)); /*0x925272*/
  if ( FFX_Battle_IsQueueGateActive() ) /*0x92527a*/
  {
    *(_DWORD *)(a1 + 408) = FFX_MagicHost_ContextSlot02A0_Handler_structural(n2); /*0x925296*/
    FFX_Battle_ComputeTeamProjection(teamType, battleContext); /*0x92529c*/
    v13 = 0; /*0x9252a1*/
    if ( *(int *)(a1 + 412) > 0 ) /*0x9252aa*/
    {
      v14 = (_DWORD *)(a1 + 416); /*0x9252ac*/
      do /*0x9252be*/
      {
        *v14 = *(char *)(v13 + v12); /*0x9252b6*/
        ++v13; /*0x9252b8*/
        ++v14; /*0x9252b9*/
      }
      while ( v13 < *(_DWORD *)(a1 + 412) ); /*0x9252be*/
    }
    v9 = a7; /*0x9252c0*/
  }
  v15 = 0; /*0x9252c3*/
  *(_BYTE *)(a1 + 492) = 68; /*0x9252c5*/
  for ( *(_DWORD *)(a1 + 556) = 0; v15 < v9; ++v15 ) /*0x9252d8*/
  {
    FFX_MagicHost_InvokeRootBufferRangeCallback_structural(*(_DWORD *)(a1 + 8)); /*0x9252e3*/
    *(_DWORD *)(*(_DWORD *)(a1 + 24) + 4 * v15) = FFX_MagicHost_SelectRuntimeTableSlice(*(_DWORD **)(a1 + 8), 8, v15); /*0x9252f6*/
    *(_DWORD *)(*(_DWORD *)(a1 + 16) + 32) = Std_IdentityFunc(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 24) + 4 * v15) /*0x92530a*/
                                                                        + 20));
    *(_DWORD *)(*(_DWORD *)(a1 + 16) + 36) = Std_IdentityFunc(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 24) + 4 * v15) /*0x92531e*/
                                                                        + 24));
    source_copy = Std_IdentityFunc(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 24) + 4 * v15) + 28)); /*0x92532a*/
    host = *(FFXMagicHost **)(a1 + 16); /*0x92532f*/
    host->source_copy_40 = source_copy; /*0x925334*/
    FFX_MagicHost_RelocatePppResourceBlob(host, blob); /*0x925343*/
  }
  if ( FFX_System_IsEmbeddedSystem() && FFX_System_GetPlatformFlag() ) /*0x925359*/
    unk_1B0003C = a1; /*0x925362*/
  FFX_MagicHost_ProcessRuntimeTableRangeAndGateMask(*(_DWORD *)(a1 + 8), 0, 1000, 2048); /*0x925377*/
  return FFX_MagicHost_StateFanoutGate_structural(*(_DWORD *)(a1 + 8), 0, 1000, 2048); /*0x925393*/
}