// ============================================================================
// FFX Field Events Runtime - IDA decompilation batch
// Source: F:/ffx-reconstructed/extras/ffxoficial_COPY.i64 (FFX.exe Steam HD, copy) via idalib-mcp
// Date: 2026-08-19  Lane: General (research)  Tool: idalib-mcp HTTP (headless, D:/ffx_ida_headless)
// Purpose: EV01/ATEL field events runtime - loading, VM execution, workers,
//          event object spawn, camera script, event text, field interaction
// ============================================================================

// ===========================================================================
// FFX_Event_LoadEv01AndRegisterScript
// addr: 0x797560  purpose: EV01 5-chunk loading -> register ATEL script
// ===========================================================================
// [Jarvis naming goal 2026-06-17] Event loader for EV01 chunk0. Registers the script into channel 2 and hands control to the ATEL/event script runtime.
// FFX Event: Load EV01 and register script
int __cdecl FFX_Event_LoadEv01AndRegisterScript(int a1)
{
  int v1; // eax
  void *script; // edx
  void *channelContext; // edx
  FFX_AtelSubsystem subsystem; // ecx

  // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0x797569*/
  if ( !a1 ) /*0x797569*/
    return 0; /*0x7975c2*/
  FFX_Btl_UI_CameraShotTable_ResolveAndBind_structural(2, 0, 0); /*0x797571*/
  FFX_Btl_UI_CameraShotTable_ResolveAndBind_structural(2, 0, 1); /*0x79757c*/
  FFX_Btl_UI_CameraShotTable_ResolveAndBind_structural(2, 0, 2); /*0x797587*/
  v1 = a1 + *(_DWORD *)(a1 + 8); /*0x797595*/
  *(_DWORD *)&FFX_Battle_CtbPriorityQueue[10792] = a1 + *(_DWORD *)(a1 + 4); /*0x79759b*/
  *(_DWORD *)&FFX_Battle_CtbPriorityQueue[10796] = v1; /*0x7975a1*/
  FFX_Atel_RegisterScriptInChannel(*(FFX_AtelSubsystem *)&FFX_Battle_CtbPriorityQueue[10792], script, 2); /*0x7975a6*/
  FFX_Atel_SizeAndDispatchChannelScripts(subsystem, channelContext); /*0x7975ad*/
  FFX_Battle_CtbPriorityQueue[10788] = -1; /*0x7975b5*/
  return -1; /*0x7975bf*/
}

// ===========================================================================
// FFX_Event_DispatchSceneScriptLoad
// addr: 0x788FB0  purpose: Dispatch scene script load
// ===========================================================================
// [Jarvis naming goal 2026-06-17] Scene-script load dispatcher. Resolves the EV01 buffer and forwards it into the channel-2 registration path.
// FFX Event: Dispatch scene script load
int __cdecl FFX_Event_DispatchSceneScriptLoad(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 3980); // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0x788fbc*/
  if ( MEMORY[0x1133368] ) /*0x788fc4*/
    return FFX_Event_LoadEv01AndRegisterScript(MEMORY[0x1133368]); /*0x788fca*/
  if ( result ) /*0x788fd1*/
  {
    result = *(_DWORD *)(result + 28); /*0x788fd3*/
    if ( result ) /*0x788fd8*/
      return FFX_Event_LoadEv01AndRegisterScript(result); /*0x788fde*/
  }
  return result; /*0x788fc9*/
}

// ===========================================================================
// FFX_Event_CheckAndResetSceneScriptState
// addr: 0x7974F0  purpose: Check/reset scene script state
// ===========================================================================
// FFX Event: Check and reset scene script state
int FFX_Event_CheckAndResetSceneScriptState()
{
  int result; // eax

  if ( FFX_Battle_CtbPriorityQueue[10788] ) /*0x7974f7*/
  {
    FFX_Event_ResetSceneScriptState(); /*0x7974f9*/
    return AtelRemoveCtrlWork(4); /*0x797500*/
  }
  return result; /*0x797506*/
}

// ===========================================================================
// FFX_Atel_RegisterScriptInChannel
// addr: 0x797A50  purpose: Register ATEL script in channel
// ===========================================================================
// [Jarvis naming goal 2026-06-17] Shared ATEL channel registration. Appends a script pointer into a per-channel table, max 8 scripts/channel; ch1=battle, ch2=event/field.
// FFX Atel: Register script in channel
void __fastcall FFX_Atel_RegisterScriptInChannel(FFX_AtelSubsystem subsystem, void *script, int channelId)
{
  int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; // eax
  int v4; // esi
  int v5; // [esp+14h] [ebp+10h]

  [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = *(_DWORD *)&FFX_Battle_CtbPriorityQueue[84 * channelId + 4260];// [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0x797a5c*/
  if ( [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg < 8 ) /*0x797a65*/
  {
    v4 = 21 * channelId; /*0x797a67*/
    *(_DWORD *)&FFX_Battle_CtbPriorityQueue[4 * v4 /*0x797a70*/
                                          + 4280
                                          + 4 * [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg] = v5;
    *(_DWORD *)&FFX_Battle_CtbPriorityQueue[4 * v4 /*0x797a80*/
                                          + 4312
                                          + 4 * (*(_DWORD *)&FFX_Battle_CtbPriorityQueue[84 * channelId + 4260])++] = 0;
  }
}

// ===========================================================================
// FFX_Atel_FreeAllScriptData
// addr: 0x797AA0  purpose: Free all script data
// ===========================================================================
// FFX Atel: Free all script data
int FFX_Atel_FreeAllScriptData()
{
  unsigned int *v0; // esi

  v0 = (unsigned int *)&FFX_Battle_CtbPriorityQueue[4272]; /*0x797aa1*/
  do /*0x797ace*/
  {
    if ( *(v0 - 2) ) /*0x797aa6*/
      user_free(*(v0 - 2)); /*0x797aae*/
    if ( *v0 ) /*0x797ab6*/
      user_free(*v0); /*0x797abd*/
    v0 += 21; /*0x797ac5*/
  }
  while ( (int)v0 < (int)&FFX_Battle_CtbPriorityQueue[4440] ); /*0x797ace*/
  FFX_Event_CheckAndResetSceneScriptState(); /*0x797ad0*/
  AtelRemoveCtrlWork(2); /*0x797ad7*/
  AtelRemoveCtrlWork(3); /*0x797ade*/
  return FFX_Atel_ResetStateAndClearGlobals(); /*0x797ae6*/
}

// ===========================================================================
// FFX_Atel_ResetStateAndClearGlobals
// addr: 0x797AF0  purpose: Reset state + clear globals
// ===========================================================================
// FFX Atel: Reset state and clear globals
void FFX_Atel_ResetStateAndClearGlobals()
{
  *(_DWORD *)&FFX_Battle_CtbPriorityQueue[4260] = 0; /*0x797afa*/
  *(_DWORD *)&FFX_Battle_CtbPriorityQueue[4264] = 0; /*0x797b04*/
  *(_DWORD *)&FFX_Battle_CtbPriorityQueue[4268] = 0; /*0x797b0e*/
  *(_DWORD *)&FFX_Battle_CtbPriorityQueue[4272] = 0; /*0x797b18*/
  *(_DWORD *)&FFX_Battle_CtbPriorityQueue[4276] = 0; /*0x797b22*/
  *(_DWORD *)&FFX_Battle_CtbPriorityQueue[4344] = 0; /*0x797b2c*/
  *(_DWORD *)&FFX_Battle_CtbPriorityQueue[4348] = 0; /*0x797b36*/
  *(_DWORD *)&FFX_Battle_CtbPriorityQueue[4352] = 0; /*0x797b40*/
  *(_DWORD *)&FFX_Battle_CtbPriorityQueue[4356] = 0; /*0x797b4a*/
  *(_DWORD *)&FFX_Battle_CtbPriorityQueue[4360] = 0; /*0x797b54*/
  FFX_Battle_MemSet(&FFX_Battle_CtbPriorityQueue[4516], 4096); /*0x797b5e*/
  FFX_Battle_MemSet(&FFX_Battle_CtbPriorityQueue[8612], 2048); /*0x797b6d*/
  FFX_Btl_UI_ResetMenuTreeStack_structural(); /*0x797b75*/
}

// ===========================================================================
// FFX_Atel_InitVmAndRegisterFuncspaces
// addr: 0x86D660  purpose: VM init + funcspace registration
// ===========================================================================
// FFX Atel: Init VM and register funcspaces
// ATEL VM initialization. Registers 11 funcspace tables to channel IDs 0-13: Battle(0xC42618), Common(0xC50050), Math(0xC52BE0), Camera(0xC43988), Map(0xC5DC90), Movie(0xC40E20), Mount(0xC5D8C0), SgEvent(0xC88D88), ChEvent(0xC891F8), AbilityMap(0xC85EB0), Debug(0xC52DD8). Each table is FFX_AtelFuncspaceEntry[256] (16 bytes per entry: callpopa_fn, pad, float_return_fn, int_return_fn).
void __fastcall FFX_Atel_InitVmAndRegisterFuncspaces(FFX_AtelSubsystem subsystem, void *vmContext)
{
  void *funcspace; // edx
  FFX_AtelSubsystem subsystem_1; // ecx
  int i; // esi
  void *funcspace_1; // edx
  FFX_AtelSubsystem subsystem_2; // ecx
  void *funcspace_2; // edx
  FFX_AtelSubsystem subsystem_3; // ecx
  void *funcspace_3; // edx
  FFX_AtelSubsystem subsystem_4; // ecx
  void *funcspace_4; // edx
  FFX_AtelSubsystem subsystem_5; // ecx
  void *funcspace_5; // edx
  FFX_AtelSubsystem subsystem_6; // ecx
  void *funcspace_6; // edx
  FFX_AtelSubsystem subsystem_7; // ecx
  void *funcspace_7; // edx
  FFX_AtelSubsystem subsystem_8; // ecx
  void *funcspace_8; // edx
  FFX_AtelSubsystem subsystem_9; // ecx
  void *funcspace_9; // edx
  FFX_AtelSubsystem subsystem_10; // ecx
  void *funcspace_10; // edx
  FFX_AtelSubsystem subsystem_11; // ecx

  byte_1325B58[0] = 2.0; /*0x86d667*/
  *(float *)&byte_1325B5C = 2.0; /*0x86d66d*/
  FFX_Save_InitBufferSlots(); /*0x86d673*/
  *(_DWORD *)&MEMORY[0x1326B2C] = 100; /*0x86d678*/
  *(_DWORD *)&byte_1326CB0 = -1; /*0x86d682*/
  *(_DWORD *)&byte_1326CB4 = -1; /*0x86d68c*/
  *(_DWORD *)&byte_1326CB8 = -1; /*0x86d696*/
  *(_DWORD *)&byte_1326CBC = -1; /*0x86d6a0*/
  FFX_Field_ResetEventStepCounters(); /*0x86d6aa*/
  FFX_Field_SetMapregIndex(255); /*0x86d6b4*/
  byte_1326B42 = 0; /*0x86d6b9*/
  FFX_Atel_ClearScriptStorage(); /*0x86d6c0*/
  *(_DWORD *)&CurrentWorker = 0; /*0x86d6c5*/
  AtelClearShape(); /*0x86d6cf*/
  FFX_Atel_ResetFuncspaceSelectors(); /*0x86d6d4*/
  FFX_Field_ResetControlledActorIndex(); /*0x86d6d9*/
  *(_DWORD *)&byte_1325B50 = 0; /*0x86d6de*/
  *(_DWORD *)&byte_1325B54 = 0; /*0x86d6e8*/
  g_FFX_Encounter_ForceFieldOverride_candidate = -1; /*0x86d6f2*/
  FFX_Atel_ClearQueryFlags(); /*0x86d6fc*/
  byte_132703C[0] = 0; /*0x86d70a*/
  FFX_Field_SetGlobalAngleFloat(179.0); /*0x86d714*/
  FFX_EncounterZone_InitTable(); /*0x86d719*/
  FFX_Atel_SetAreaFaction(0); /*0x86d720*/
  FFX_Battle_SetMusicTrackIndex(-1); /*0x86d727*/
  FFX_Atel_ClearMovieState(); /*0x86d72c*/
  FFX_Atel_Atel_InitVmAndRegisterFuncspaces_Sub_8A96C0(); /*0x86d731*/
  MEMORY[0x1326B40] = 0; /*0x86d73d*/
  byte_1327098 = 0; /*0x86d744*/
  *(_DWORD *)&byte_1327038 = 0; /*0x86d74e*/
  FFX_Input_AnalogStickDeadZone(2, (int (*)())FFX_Field_UpdateSceneTimer); /*0x86d758*/
  *(_DWORD *)&MEMORY[0x1326B08] = 65537; /*0x86d760*/
  *(_DWORD *)&byte_1326B18 = 0; /*0x86d76a*/
  MEMORY[0x1327030] = 0; /*0x86d774*/
  MEMORY[0x1327034] = 0; /*0x86d77e*/
  for ( i = 0; i < 16; ++i ) /*0x86d788*/
    FFX_Atel_RegisterFuncspace(subsystem_1, funcspace); /*0x86d793*/
  FFX_Atel_RegisterFuncspace(subsystem_1, funcspace); /*0x86d7a8*/
  FFX_Atel_RegisterFuncspace(subsystem_2, funcspace_1); /*0x86d7b4*/
  FFX_Atel_RegisterFuncspace(subsystem_3, funcspace_2); /*0x86d7c0*/
  FFX_Atel_RegisterFuncspace(subsystem_4, funcspace_3); /*0x86d7cc*/
  FFX_Atel_RegisterFuncspace(subsystem_5, funcspace_4); /*0x86d7d8*/
  FFX_Atel_RegisterFuncspace(subsystem_6, funcspace_5); /*0x86d7e4*/
  FFX_Atel_RegisterFuncspace(subsystem_7, funcspace_6); /*0x86d7f0*/
  FFX_Atel_RegisterFuncspace(subsystem_8, funcspace_7); /*0x86d7fc*/
  FFX_Atel_RegisterFuncspace(subsystem_9, funcspace_8); /*0x86d80b*/
  FFX_Atel_RegisterFuncspace(subsystem_10, funcspace_9); /*0x86d817*/
  FFX_Atel_RegisterFuncspace(subsystem_11, funcspace_10); /*0x86d823*/
  Controllers[0] &= ~1u; /*0x86d82a*/
  *(float *)&byte_1326B98 = 1.0; /*0x86d831*/
  byte_1325D98 &= ~1u; /*0x86d837*/
  byte_1325FD0 &= ~1u; /*0x86d83e*/
  byte_1326208 &= ~1u; /*0x86d845*/
  byte_1326440 &= ~1u; /*0x86d84c*/
  byte_1326678 &= ~1u; /*0x86d853*/
  byte_13268B0 &= ~1u; /*0x86d85a*/
  byte_1325BA8 = 0; /*0x86d861*/
  *(_DWORD *)&byte_1325DE0 = 0; /*0x86d86b*/
  *(_DWORD *)&byte_1326018 = 0; /*0x86d875*/
  *(_DWORD *)&byte_1326250 = 0; /*0x86d87f*/
  *(_DWORD *)&byte_1326488 = 0; /*0x86d889*/
  *(_DWORD *)&byte_13266C0 = 0; /*0x86d893*/
  *(_DWORD *)&byte_13268F8 = 0; /*0x86d89d*/
  AtelCurCtrlWork = (int *)Controllers; /*0x86d8a7*/
  _cfltcvt_init_90(); /*0x86d8b1*/
  FFX_Sound_InitSystem(); /*0x86d8b6*/
  FFX_Text_ParseHexString("0x0"); /*0x86d8c0*/
}

// ===========================================================================
// FFX_Atel_RegisterFuncspace
// addr: 0x877800  purpose: Register funcspace (namespace dispatch)
// ===========================================================================
// FFX Atel: Register funcspace
void __fastcall FFX_Atel_RegisterFuncspace(FFX_AtelSubsystem subsystem, void *funcspace)
{
  FFX_AtelSubsystem subsystema; // [esp+8h] [ebp+8h]
  void *pTable; // [esp+Ch] [ebp+Ch]

  if ( pTable ) /*0x87780b*/
    *(&AtelCallTargets + subsystema) = (unsigned __int32)pTable; /*0x87780d*/
  else
    *(&AtelCallTargets + subsystema) = (unsigned __int32)AtelCallTargetsDefault; /*0x877816*/
}

// ===========================================================================
// FFX_Atel_FetchOpcode
// addr: 0x869D00  purpose: ATEL opcode fetch
// ===========================================================================
// Jarvis-HEAVY H09: ATEL opcode fetch. Returns (opcode&0x7F)<<24 | u16 operand when high bit is set; no direct 0x707A immediate exists in host code.
// FFX Atel: Fetch opcode
int __cdecl FFX_Atel_FetchOpcode(int argCount, int ScriptWorkerContext_structural)
{
  int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; // eax
  unsigned __int8 v3; // dl

  [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = *(_DWORD *)(ScriptWorkerContext_structural + 24);// [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0x869d06*/
  v3 = *(_BYTE *)[Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; /*0x869d09*/
  if ( *(char *)[Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg < 0 ) /*0x869d0d*/
    return *(unsigned __int16 *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg + 1) /*0x869d3c*/
         | ((v3 & 0x7F) << 24);
  else
    return v3 << 24; /*0x869d1a*/
}

// ===========================================================================
// FFX_Field_EventParser_structural
// addr: 0x864180  purpose: ATEL VM interpreter main loop (123-case switch)
// ===========================================================================
// Jarvis-HEAVY H09: ATEL VM interpreter. Fetches opcode via 0x869D00, strips operand flag, dispatches cases 0..0x7A; CALL/CALLPOPA cases 0x35/0x58 route native call IDs through namespace dispatchers.
// FFX: Field event parser structural — ATEL VM interpreter main loop (4KB, 123-case switch, fetches opcodes via 0x869D00)
// FFX Field: Event parser (ATEL VM interpreter, 123-case switch)
// ATEL VM interpreter main loop. 4208 bytes, 224 basic blocks, 123-case switch (0x00-0x7A). Fetches opcodes via FFX_Atel_FetchOpcode(0x869D00), strips operand flag, dispatches to FFX_AtelOp_* handler functions. Opcodes: NCJMP, JSR, RTS, CALL, REQ, RET, HALT, PUSHN, PUSHT, PUSHVP, PUSHFIX, POPI0-3, POPF0-9, PUSHI0-3, PUSHF0-9, PUSHAINTER, ER, AIT, SYSTEM.
// ATEL VM interpreter. Fetches opcode via FFX_Atel_FetchOpcode(0x869D00), strips operand flag, dispatches cases 0..0x7A (123 cases). Each case calls individual FFX_AtelOp_* handler. 224 basic blocks, cyclomatic complexity 156.
int __fastcall FFX_Field_EventParser_structural(FFX_AtelOpcode opcode, void *vmContext, int argCount)
{
  HANDLE *[Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; // eax
  FFXEncounterState *v4; // ecx
  __int16 v6; // ax
  int *v7; // esi
  _BYTE **ScriptWorkerContext_structural; // edi
  int *v9; // eax
  int *v10; // ecx
  int *v11; // eax
  int argCounta_1; // ecx
  int v13; // esi
  unsigned int v14; // eax
  unsigned int n7_1; // ecx
  unsigned int v16; // edx
  int *AtelCurCtrlWork; // ecx
  int *v18; // ecx
  int n4; // edx
  int v20; // eax
  int argCounta_2; // eax
  __int16 v22; // dx
  int v23; // eax
  unsigned __int8 v24; // cl
  int v25; // esi
  int v26; // esi
  int v27; // eax
  int v28; // esi
  int v29; // esi
  int v30; // esi
  BOOL v31; // edx
  double v32; // st7
  bool v33; // zf
  unsigned int v34; // esi
  bool v35; // cc
  double v36; // st7
  unsigned int v37; // esi
  bool v38; // cf
  double v39; // st7
  int v40; // esi
  double v41; // st7
  int v42; // esi
  double v43; // st7
  char v44; // si
  char v45; // si
  char v46; // si
  char v47; // si
  int v48; // esi
  double v49; // st7
  int v50; // esi
  int v51; // esi
  int v52; // esi
  int v53; // esi
  int v54; // eax
  int v55; // eax
  int v56; // eax
  int v57; // eax
  int v58; // eax
  int v59; // eax
  _DWORD *v60; // eax
  int v61; // edx
  int v62; // eax
  _BYTE *v63; // edx
  char v64; // al
  int v65; // ecx
  int v66; // esi
  int n255b; // eax
  int v68; // esi
  int n255b_1; // eax
  int v70; // eax
  int v71; // esi
  int v72; // esi
  int n255b_2; // eax
  int v74; // eax
  int n255c_1; // esi
  int n255c; // eax
  __int16 v77; // di
  int v78; // esi
  int v79; // eax
  unsigned __int16 v80; // si
  int v81; // eax
  int v82; // eax
  void (__cdecl *v83)(int, int); // ecx
  int v84; // eax
  int v85; // eax
  void (__cdecl *v86)(int, int); // ecx
  int v87; // eax
  int v88; // eax
  int n8; // ecx
  int v90; // ecx
  int v92; // [esp-10h] [ebp-44h]
  int v93; // [esp+0h] [ebp-34h]
  _BYTE **ScriptWorkerContext_structural_1; // [esp+10h] [ebp-24h]
  int n0xFFFF; // [esp+14h] [ebp-20h]
  int n0xFFFFa; // [esp+14h] [ebp-20h]
  int n0xFFFFb; // [esp+14h] [ebp-20h]
  int n0xFFFFc; // [esp+14h] [ebp-20h]
  int n0xFFFFd; // [esp+14h] [ebp-20h]
  int n0xFFFFe; // [esp+14h] [ebp-20h]
  int n0xFFFFf; // [esp+14h] [ebp-20h]
  int v102; // [esp+18h] [ebp-1Ch]
  int v103; // [esp+1Ch] [ebp-18h]
  float v104; // [esp+20h] [ebp-14h]
  int v105; // [esp+20h] [ebp-14h]
  unsigned int n7; // [esp+24h] [ebp-10h]
  char v107; // [esp+24h] [ebp-10h]
  int v108; // [esp+24h] [ebp-10h]
  int n255; // [esp+24h] [ebp-10h]
  __int16 n255b_3; // [esp+24h] [ebp-10h]
  __int16 n255c_2; // [esp+24h] [ebp-10h]
  unsigned int v112; // [esp+2Ch] [ebp-8h]
  float v113; // [esp+2Ch] [ebp-8h]
  float v114; // [esp+2Ch] [ebp-8h]
  float v115; // [esp+2Ch] [ebp-8h]
  float v116; // [esp+2Ch] [ebp-8h]
  float v117; // [esp+2Ch] [ebp-8h]
  float v118; // [esp+2Ch] [ebp-8h]
  float v119; // [esp+2Ch] [ebp-8h]
  float v120; // [esp+2Ch] [ebp-8h]
  float v121; // [esp+2Ch] [ebp-8h]
  int v122; // [esp+30h] [ebp-4h]
  float argCountc; // [esp+3Ch] [ebp+8h]
  int argCounta; // [esp+3Ch] [ebp+8h]
  _DWORD *argCountb; // [esp+3Ch] [ebp+8h]
  int v126; // [esp+40h] [ebp+Ch]
  int v127; // [esp+44h] [ebp+10h]

  [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = _Jarvis_naming_goal_2026_06_17__proved_navigation_name_from_agg;// [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0x864183*/
  if ( _Jarvis_naming_goal_2026_06_17__proved_navigation_name_from_agg == (HANDLE *)-1 ) /*0x86418e*/
  {
    [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = (HANDLE *)Sys_Mutex_Create(); /*0x864190*/
    _Jarvis_naming_goal_2026_06_17__proved_navigation_name_from_agg = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; /*0x864195*/
  }
  WaitForSingleObject_w([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg); /*0x86419c*/
  v6 = *(_WORD *)(argCount + 52); /*0x8641a7*/
  if ( (v6 & 2) == 0 /*0x8641e9*/
    || (v6 & 4) == 0 && (*(_BYTE *)(argCount + 54) & 0x40) == 0 && FFX_Battle_IsEncounterSuppressed(v4)
    || (*((_BYTE *)AtelCurCtrlWork + 3) & 3) == 1
    || (*((_BYTE *)AtelCurCtrlWork + 3) & 3) == 2 && *(__int16 *)(argCount + 54) >= 0 )
  {
    ReleaseMutex_w(_Jarvis_naming_goal_2026_06_17__proved_navigation_name_from_agg); /*0x8651e1*/
    return 0; /*0x8651e9*/
  }
  v102 = 0; /*0x8641f7*/
  v7 = (int *)(argCount + 196); /*0x8641fe*/
  ScriptWorkerContext_structural = FFX_FieldActor_GetScriptWorkerContext_structural( /*0x864209*/
                                     (_BYTE **)argCount,
                                     *(unsigned __int8 *)(argCount + 50));
  ScriptWorkerContext_structural_1 = ScriptWorkerContext_structural; /*0x86421a*/
  argCountc = *(float *)(argCount + 148) * *(float *)&byte_1326B98; /*0x86421d*/
  v104 = argCountc + *(float *)(argCount + 152); /*0x86422b*/
  if ( argCountc < 1.0 ) /*0x864239*/
  {
    argCounta = 0; /*0x864252*/
  }
  else
  {
    argCounta = 1; /*0x86423e*/
    v104 = v104 - 1.0; /*0x86424b*/
  }
  *(float *)(argCount + 152) = v104; /*0x86425f*/
  v122 = v104 >= 1.0; /*0x86426e*/
  v105 = 1; /*0x86427c*/
  v103 = -1; /*0x864283*/
  if ( v127 ) /*0x864286*/
    ((void (__cdecl *)(int, _BYTE **))AtelCurCtrlWork[22])(argCount, ScriptWorkerContext_structural); /*0x864292*/
  while ( 1 )
  {
    if ( !*((_BYTE *)ScriptWorkerContext_structural + 31) ) /*0x86429e*/
      goto LABEL_25; /*0x86429e*/
    if ( *((_BYTE *)ScriptWorkerContext_structural + 31) == 1 ) /*0x8642a1*/
      break; /*0x8642a1*/
    if ( *((_BYTE *)ScriptWorkerContext_structural + 31) != 2 ) /*0x8642a4*/
      goto LABEL_33; /*0x8642a4*/
    v9 = *(int **)(FFX_Field_AiScriptStateMachine_structural(*((unsigned __int16 *)ScriptWorkerContext_structural + 23)) /*0x8642b7*/
                 + 128);
    if ( v9 )
    {
      while ( 1 ) /*0x8642c9*/
      {
        v10 = (int *)*v9; /*0x8642c9*/
        if ( *((_BYTE *)v9 + 15) != 3 /*0x8642d3*/
          && *((unsigned __int16 *)v9 + 4) == *((unsigned __int16 *)ScriptWorkerContext_structural + 22) )
        {
          break; /*0x8642d3*/
        }
        v9 = (int *)*v9; /*0x8642d9*/
        if ( !v10 ) /*0x8642dd*/
          goto LABEL_22; /*0x8642dd*/
      }
LABEL_33:
      v13 = *v7 == 0 ? v105 : 0;
      goto LABEL_207; /*0x864376*/
    }
LABEL_22:
    *((_BYTE *)ScriptWorkerContext_structural + 31) = 0; /*0x8642df*/
  }
  v11 = FFX_Field_EventNodeSearch(argCount, ScriptWorkerContext_structural); /*0x8642e7*/
  if ( !v11 ) /*0x8642f1*/
    goto LABEL_33; /*0x8642f1*/
  FFX_FieldActor_LinkTriggerNode_structural(*(unsigned __int16 *)(argCount + 46), v11); /*0x8642f9*/
  *((_BYTE *)ScriptWorkerContext_structural + 31) = 0; /*0x864301*/
LABEL_25:
  *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x400; /*0x864305*/
LABEL_26:
  argCounta_1 = argCounta; /*0x864320*/
LABEL_27:
  if ( ++v102 > 0x10000 ) /*0x864334*/
  {
    argCounta_1 = 0; /*0x86433d*/
    argCounta = 0; /*0x864347*/
    *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x1400; /*0x86434a*/
    byte_1327098 = 0; /*0x86434e*/
  }
  if ( v126 != 1 ) /*0x864358*/
  {
    if ( !argCounta_1 && !*v7 ) /*0x864381*/
      goto LABEL_206; /*0x864381*/
    goto LABEL_36; /*0x864381*/
  }
  if ( argCounta_1 ) /*0x86435c*/
  {
LABEL_36:
    v14 = FFX_Atel_FetchOpcode(argCount, (int)ScriptWorkerContext_structural); /*0x864387*/
    n7_1 = HIBYTE(v14); /*0x864392*/
    v16 = (unsigned int)&byte_FFC194[15979] & v14; /*0x864395*/
    v112 = (unsigned int)&byte_FFC194[15979] & v14; /*0x86439e*/
    n7 = HIBYTE(v14); /*0x8643a1*/
    LOWORD(v105) = 1; /*0x8643a4*/
LABEL_37:
    switch ( n7_1 ) /*0x8643c7*/
    {
      case 0u: /*0x8643c7*/
      case 0x1Du: /*0x8643c7*/
      case 0x1Eu: /*0x8643c7*/
      case 0x76u: /*0x8643c7*/
        goto LABEL_52;
      case 1u: /*0x8643c7*/
        n0xFFFF = FFX_FieldVM_PopOperand(argCount, v7); /*0x864491*/
        if ( !FFX_FieldVM_PopOperand(argCount, v7) && !n0xFFFF ) /*0x8644a3*/
          goto LABEL_50; /*0x8644a3*/
        goto LABEL_57; /*0x8644a3*/
      case 2u: /*0x8643c7*/
        n0xFFFFa = FFX_FieldVM_PopOperand(argCount, v7); /*0x8644f9*/
        if ( FFX_FieldVM_PopOperand(argCount, v7) && n0xFFFFa ) /*0x86450c*/
LABEL_57:
          v23 = 1; /*0x86450e*/
        else
LABEL_50:
          v23 = 0; /*0x8644a5*/
        goto LABEL_51; /*0x864513*/
      case 3u: /*0x8643c7*/
        v28 = FFX_FieldVM_PopOperand(argCount, v7); /*0x86454a*/
        v27 = v28 | FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)); /*0x864559*/
        goto LABEL_59; /*0x86455b*/
      case 4u: /*0x8643c7*/
        v29 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864564*/
        v27 = v29 ^ FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)); /*0x864573*/
        goto LABEL_59; /*0x864575*/
      case 5u: /*0x8643c7*/
        v26 = FFX_FieldVM_PopOperand(argCount, v7); /*0x86451c*/
        v27 = v26 & FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)); /*0x86452b*/
        goto LABEL_59; /*0x86452b*/
      case 6u: /*0x8643c7*/
      case 7u: /*0x8643c7*/
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) ) /*0x864580*/
        {
          v30 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864593*/
          v33 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) == v30; /*0x8645a5*/
          v7 = (int *)(argCount + 196); /*0x8645a7*/
          if ( v33 ) /*0x8645ad*/
          {
            v31 = 1; /*0x8645af*/
            goto LABEL_68; /*0x8645b4*/
          }
        }
        else
        {
          v113 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x8645bb*/
          v32 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x8645c6*/
          v31 = 1; /*0x8645d3*/
          if ( v113 == v32 ) /*0x8645dd*/
            goto LABEL_68; /*0x8645dd*/
        }
        v31 = 0; /*0x8645df*/
LABEL_68:
        v33 = n7 == 7; /*0x8645e2*/
        goto LABEL_69; /*0x8645e2*/
      case 8u: /*0x8643c7*/
      case 0xDu: /*0x8643c7*/
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) ) /*0x864600*/
        {
          v34 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864613*/
          v35 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) <= v34; /*0x864625*/
          v7 = (int *)(argCount + 196); /*0x864627*/
          if ( !v35 ) /*0x86462d*/
          {
            v33 = n7 == 13; /*0x86462f*/
            v31 = 1; /*0x864633*/
            goto LABEL_69; /*0x864638*/
          }
        }
        else
        {
          v114 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x86463f*/
          v36 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x864644*/
          v31 = 1; /*0x864651*/
          if ( v114 < v36 ) /*0x86465b*/
            goto LABEL_77; /*0x86465b*/
        }
        v31 = 0; /*0x86465d*/
LABEL_77:
        v33 = n7 == 13; /*0x864660*/
        goto LABEL_69; /*0x864664*/
      case 9u: /*0x8643c7*/
      case 0xCu: /*0x8643c7*/
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) ) /*0x86466f*/
        {
          v37 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864682*/
          v38 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) < v37; /*0x864694*/
          v7 = (int *)(argCount + 196); /*0x864696*/
          if ( !v38 ) /*0x86469c*/
          {
            v33 = n7 == 9; /*0x86469e*/
            v31 = 1; /*0x8646a2*/
            goto LABEL_69; /*0x8646a7*/
          }
        }
        else
        {
          v115 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x8646b1*/
          v39 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x8646b6*/
          v31 = 1; /*0x8646c3*/
          if ( v115 <= v39 ) /*0x8646cd*/
            goto LABEL_83; /*0x8646cd*/
        }
        v31 = 0; /*0x8646cf*/
LABEL_83:
        v33 = n7 == 9; /*0x8646d2*/
        goto LABEL_69; /*0x8646d6*/
      case 0xAu: /*0x8643c7*/
      case 0xFu: /*0x8643c7*/
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) ) /*0x8646e4*/
        {
          v40 = FFX_FieldVM_PopOperand(argCount, v7); /*0x8646f7*/
          v35 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) <= v40; /*0x864709*/
          v7 = (int *)(argCount + 196); /*0x86470b*/
          if ( !v35 ) /*0x864711*/
          {
            v33 = n7 == 15; /*0x864713*/
            v31 = 1; /*0x864717*/
            goto LABEL_69; /*0x86471c*/
          }
        }
        else
        {
          v116 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x864726*/
          v41 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x86472b*/
          v31 = 1; /*0x864738*/
          if ( v116 < v41 ) /*0x864742*/
            goto LABEL_89; /*0x864742*/
        }
        v31 = 0; /*0x864744*/
LABEL_89:
        v33 = n7 == 15; /*0x864747*/
        goto LABEL_69; /*0x86474b*/
      case 0xBu: /*0x8643c7*/
      case 0xEu: /*0x8643c7*/
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) ) /*0x864759*/
        {
          v42 = FFX_FieldVM_PopOperand(argCount, v7); /*0x86476c*/
          v35 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) < v42; /*0x86477e*/
          v7 = (int *)(argCount + 196); /*0x864780*/
          if ( !v35 ) /*0x864786*/
          {
            v33 = n7 == 11; /*0x864788*/
            v31 = 1; /*0x86478c*/
            goto LABEL_69; /*0x864791*/
          }
        }
        else
        {
          v117 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x86479b*/
          v43 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x8647a0*/
          v31 = 1; /*0x8647ad*/
          if ( v117 <= v43 ) /*0x8647b7*/
            goto LABEL_95; /*0x8647b7*/
        }
        v31 = 0; /*0x8647b9*/
LABEL_95:
        v33 = n7 == 11; /*0x8647bc*/
LABEL_69:
        if ( v33 ) /*0x8645e6*/
          v31 = !v31; /*0x8645ef*/
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, v31); /*0x8645f2*/
        goto LABEL_52; /*0x8645f2*/
      case 0x10u: /*0x8643c7*/
        v44 = FFX_FieldVM_PopOperand(argCount, v7); /*0x8647cc*/
        if ( (FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) & (1 << v44)) != 0 ) /*0x8647e9*/
          goto LABEL_97; /*0x8647e9*/
        goto LABEL_98; /*0x8647e9*/
      case 0x11u: /*0x8643c7*/
        v45 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864813*/
        if ( (FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) & (1 << v45)) != 0 ) /*0x864830*/
          goto LABEL_98; /*0x864830*/
LABEL_97:
        FFX_FieldVM_PushIntOperand_structural(argCount, (int *)(argCount + 196), 1); /*0x8647eb*/
        goto LABEL_52; /*0x8647f8*/
      case 0x12u: /*0x8643c7*/
        v46 = FFX_FieldVM_PopOperand(argCount, v7); /*0x86484b*/
        v27 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) << v46; /*0x86485c*/
        goto LABEL_59; /*0x86485e*/
      case 0x13u: /*0x8643c7*/
        v47 = FFX_FieldVM_PopOperand(argCount, v7); /*0x86486a*/
        v27 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) >> v47; /*0x86487b*/
        goto LABEL_59; /*0x86487d*/
      case 0x14u: /*0x8643c7*/
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) ) /*0x864884*/
        {
          v48 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864897*/
          v27 = v48 + FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)); /*0x8648a6*/
          goto LABEL_59; /*0x8648a8*/
        }
        v118 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x8648b2*/
        v49 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7) + v118; /*0x8648bc*/
        goto LABEL_106; /*0x8648bc*/
      case 0x15u: /*0x8643c7*/
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) ) /*0x8648d9*/
        {
          v50 = FFX_FieldVM_PopOperand(argCount, v7); /*0x8648ec*/
          v27 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) - v50; /*0x8648fb*/
          goto LABEL_59; /*0x8648fd*/
        }
        v119 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x864907*/
        v49 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7) - v119; /*0x864911*/
        goto LABEL_106; /*0x864914*/
      case 0x16u: /*0x8643c7*/
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) ) /*0x864918*/
        {
          v51 = FFX_FieldVM_PopOperand(argCount, v7); /*0x86492b*/
          v27 = v51 * FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)); /*0x86493a*/
          goto LABEL_59; /*0x86493d*/
        }
        v120 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x864947*/
        v49 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7) * v120; /*0x864951*/
        goto LABEL_106; /*0x864954*/
      case 0x17u: /*0x8643c7*/
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) ) /*0x86495b*/
        {
          v52 = FFX_FieldVM_PopOperand(argCount, v7); /*0x86496e*/
          v27 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) / v52; /*0x86497e*/
LABEL_59:
          FFX_FieldVM_PushIntOperand_structural(argCount, (int *)(argCount + 196), v27); /*0x86452d*/
        }
        else
        {
          v121 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x86498a*/
          v49 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7) / v121; /*0x864994*/
LABEL_106:
          *(float *)&v108 = v49; /*0x8648c2*/
          FFX_FieldVM_PushFloatOperand_structural(argCount, v7, v108); /*0x8648cd*/
        }
        goto LABEL_52; /*0x864536*/
      case 0x18u: /*0x8643c7*/
        v53 = FFX_FieldVM_PopOperand(argCount, v7); /*0x8649a3*/
        v92 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) % v53; /*0x8649b5*/
        FFX_FieldVM_PushIntOperand_structural(argCount, (int *)(argCount + 196), v92); /*0x8649b6*/
        goto LABEL_52; /*0x8649b6*/
      case 0x19u: /*0x8643c7*/
        v54 = FFX_FieldVM_PopOperand(argCount, v7); /*0x8649bd*/
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, v54 == 0); /*0x8649ca*/
        goto LABEL_52; /*0x8649d2*/
      case 0x1Au: /*0x8643c7*/
        v49 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7) * -1.0; /*0x8649f7*/
        goto LABEL_106; /*0x864a00*/
      case 0x1Cu: /*0x8643c7*/
        v55 = FFX_FieldVM_PopOperand(argCount, v7); /*0x8649d9*/
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, ~v55); /*0x8649e3*/
        goto LABEL_52; /*0x8649eb*/
      case 0x1Fu: /*0x8643c7*/
        FFX_FieldEvent_ReadArrayToStack((_DWORD *)argCount, v7, v16, 0); /*0x864a4e*/
        goto LABEL_52; /*0x864a56*/
      case 0x20u: /*0x8643c7*/
        FFX_FieldVM_StoreArrayOperandMode_structural((_DWORD *)argCount, v7, v16, 0); /*0x864a60*/
        goto LABEL_52; /*0x864a68*/
      case 0x21u: /*0x8643c7*/
        FFX_FieldVM_StoreArrayOperandMode_structural((_DWORD *)argCount, v7, v16, 1); /*0x864a72*/
        goto LABEL_52; /*0x864a7a*/
      case 0x22u: /*0x8643c7*/
        FFX_FieldEvent_PopStackValue(argCount, v7, v16); /*0x864a08*/
        goto LABEL_52; /*0x864a0d*/
      case 0x23u: /*0x8643c7*/
        FFX_FieldVM_StoreArrayOperandMode_structural((_DWORD *)argCount, v7, v16, 128); /*0x864a27*/
        goto LABEL_52; /*0x864a2f*/
      case 0x24u: /*0x8643c7*/
        FFX_FieldVM_StoreArrayOperandMode_structural((_DWORD *)argCount, v7, v16, 129); /*0x864a3c*/
        goto LABEL_52; /*0x864a44*/
      case 0x25u: /*0x8643c7*/
        goto LABEL_169;
      case 0x26u: /*0x8643c7*/
        FFX_FieldVM_PushFloatOperand_structural( /*0x864a88*/
          argCount,
          v7,
          COERCE_INT(*((float *)ScriptWorkerContext_structural + 10)));
        goto LABEL_52; /*0x864a8d*/
      case 0x27u: /*0x8643c7*/
        FFX_FieldVM_PushArrayOperand_structural((_DWORD *)argCount, v7, v16); /*0x864a15*/
        goto LABEL_52; /*0x864a1a*/
      case 0x28u: /*0x8643c7*/
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, (int)ScriptWorkerContext_structural[8]); /*0x864af6*/
        goto LABEL_52; /*0x864af6*/
      case 0x29u: /*0x8643c7*/
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, (int)ScriptWorkerContext_structural[9]); /*0x864afe*/
        goto LABEL_52; /*0x864afe*/
      case 0x2Au: /*0x8643c7*/
        ScriptWorkerContext_structural[8] = (_BYTE *)FFX_FieldVM_PopOperand(argCount, v7); /*0x864b0d*/
        goto LABEL_52; /*0x864b10*/
      case 0x2Bu: /*0x8643c7*/
        v56 = FFX_FieldVM_StackPopValue(argCount, v7); /*0x864b29*/
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, v56); /*0x864b31*/
        goto LABEL_52; /*0x864b39*/
      case 0x2Cu: /*0x8643c7*/
        ScriptWorkerContext_structural[9] = (_BYTE *)FFX_FieldVM_PopOperand(argCount, v7); /*0x864b1f*/
        goto LABEL_52; /*0x864b22*/
      case 0x2Du: /*0x8643c7*/
        FFX_FieldVM_PushIntOperand_structural( /*0x864b4c*/
          argCount,
          v7,
          *(_DWORD *)(*(_DWORD *)(*(_DWORD *)argCount + 24) + 4 * v16 + *(_DWORD *)(argCount + 4)));
        goto LABEL_52; /*0x864b4c*/
      case 0x2Eu: /*0x8643c7*/
        v23 = (__int16)v16; /*0x864b51*/
LABEL_51:
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, v23); /*0x8644a8*/
        goto LABEL_52; /*0x8644aa*/
      case 0x2Fu: /*0x8643c7*/
        FFX_FieldVM_PushFloatOperand_structural( /*0x864b6d*/
          argCount,
          v7,
          COERCE_INT(*(float *)(*(_DWORD *)(*(_DWORD *)argCount + 28) + 4 * v16 + *(_DWORD *)(argCount + 4))));
        goto LABEL_52; /*0x864b72*/
      case 0x30u: /*0x8643c7*/
        goto LABEL_142;
      case 0x31u: /*0x8643c7*/
        goto LABEL_150;
      case 0x32u: /*0x8643c7*/
        goto LABEL_153;
      case 0x33u: /*0x8643c7*/
        n0xFFFFb = *((char *)ScriptWorkerContext_structural + 29); /*0x864c01*/
        if ( n0xFFFFb >= 3 ) /*0x864c07*/
        {
          byte_1327098 = 0; /*0x864c09*/
          goto LABEL_52; /*0x864c13*/
        }
        ScriptWorkerContext_structural[n0xFFFFb] = &ScriptWorkerContext_structural[6][-*(_DWORD *)(*(_DWORD *)(argCount + 4) /*0x864c2a*/
                                                                                                 + 48)
                                                                                    - *(_DWORD *)(argCount + 4)
                                                                                    + 3];
        *((_WORD *)ScriptWorkerContext_structural + n0xFFFFb + 8) = v16; /*0x864c2d*/
        *((_BYTE *)ScriptWorkerContext_structural + 29) = n0xFFFFb + 1; /*0x864c34*/
        v60 = (_DWORD *)FFX_Field_AiScriptStateMachine_structural(v16); /*0x864c37*/
        v61 = *(_DWORD *)(v60[1] + *(_DWORD *)(*v60 + 32)); /*0x864c47*/
        *((_BYTE *)ScriptWorkerContext_structural + 30) = 0; /*0x864c4a*/
        ScriptWorkerContext_structural[6] = (_BYTE *)(v61 /*0x864c58*/
                                                    + *(_DWORD *)(argCount + 4)
                                                    + *(_DWORD *)(*(_DWORD *)(argCount + 4) + 48));
        goto LABEL_143; /*0x864c5b*/
      case 0x34u: /*0x8643c7*/
        v62 = *((char *)ScriptWorkerContext_structural + 29); /*0x864c60*/
        if ( v62 <= 0 ) /*0x864c66*/
        {
          byte_1327098 = 0; /*0x864c68*/
          goto LABEL_52; /*0x864c72*/
        }
        v63 = ScriptWorkerContext_structural[v62 - 1]; /*0x864c77*/
        *((_BYTE *)ScriptWorkerContext_structural + 30) = 0; /*0x864c7f*/
        ScriptWorkerContext_structural[6] = &v63[*(_DWORD *)(argCount + 4) + *(_DWORD *)(*(_DWORD *)(argCount + 4) + 48)]; /*0x864c90*/
        *((_BYTE *)ScriptWorkerContext_structural + 29) = v62 - 1; /*0x864c93*/
        goto LABEL_143; /*0x864c96*/
      case 0x35u: /*0x8643c7*/
      case 0x58u: /*0x8643c7*/
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x400; /*0x864caf*/
        argCounta = 0; /*0x864cb7*/
        if ( *((_BYTE *)ScriptWorkerContext_structural + 30) ) /*0x864cb3*/
        {
          if ( *((_BYTE *)ScriptWorkerContext_structural + 30) != 1 ) /*0x864cc4*/
            goto LABEL_143; /*0x864cc4*/
        }
        else
        {
          *((_BYTE *)ScriptWorkerContext_structural + 30) = 1; /*0x864cd2*/
          FFX_Atel_DispatchNativeCall(1024); /*0x864cd6*/
          v16 = v112; /*0x864cdb*/
        }
        v64 = FFX_Atel_CallStatusDispatchByNamespace(v16, argCount, (int)(ScriptWorkerContext_structural + 11)); /*0x864ce7*/
        v65 = -((v64 & 2) == 0); /*0x864cfb*/
        LOWORD(v105) = v65 & 1; /*0x864cfd*/
        if ( (v64 & 4) != 0 ) /*0x864d02*/
          argCounta = 1; /*0x864d04*/
        if ( (v64 & 1) != 0 ) /*0x864d0d*/
        {
          FFX_Atel_CallReturnDispatchByNamespace(v65); /*0x864d1c*/
          *((_BYTE *)ScriptWorkerContext_structural + 30) = 0; /*0x864d28*/
          if ( n7 == 88 ) /*0x864d2c*/
LABEL_169:
            *((float *)ScriptWorkerContext_structural + 10) = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x864d32*/
LABEL_52:
          v24 = v103; /*0x8644b2*/
          if ( v103 < 0 ) /*0x8644b7*/
            v24 = *ScriptWorkerContext_structural[6]; /*0x8644bc*/
          v25 = (int)&ScriptWorkerContext_structural[6][-*(_DWORD *)(*(_DWORD *)(argCount + 4) + 48) /*0x8644ca*/
                                                      - *(_DWORD *)(argCount + 4)];
          *((_BYTE *)ScriptWorkerContext_structural + 30) = 0; /*0x8644cc*/
          ScriptWorkerContext_structural[6] = (_BYTE *)(v25 /*0x8644e2*/
                                                      + ((v24 | 0x40u) >> 6)
                                                      + *(_DWORD *)(argCount + 4)
                                                      + *(_DWORD *)(*(_DWORD *)(argCount + 4) + 48));
          v7 = (int *)(argCount + 196); /*0x8644e5*/
        }
        goto LABEL_143; /*0x8644eb*/
      case 0x36u: /*0x8643c7*/
      case 0x45u: /*0x8643c7*/
      case 0x46u: /*0x8643c7*/
      case 0x47u: /*0x8643c7*/
      case 0x48u: /*0x8643c7*/
      case 0x49u: /*0x8643c7*/
        FFX_AtelOp_QueueActorNodeType0_structural(n7_1, (int)ScriptWorkerContext_structural, argCount, v7); /*0x864da8*/
        goto LABEL_52; // Event: Sends 0x15 with index — sends event token 0x15 with index /*0x864db0*/
      case 0x37u: /*0x8643c7*/
      case 0x4Au: /*0x8643c7*/
      case 0x4Bu: /*0x8643c7*/
      case 0x4Cu: /*0x8643c7*/
      case 0x4Du: /*0x8643c7*/
      case 0x4Eu: /*0x8643c7*/
        argCounta = FFX_AtelOp_QueueActorNodeType1_structural(n7_1, argCount, (int)ScriptWorkerContext_structural, v7); /*0x864e6c*/
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x800; /*0x864e82*/
        goto LABEL_52; /*0x864e86*/
      case 0x38u: /*0x8643c7*/
      case 0x4Fu: /*0x8643c7*/
      case 0x50u: /*0x8643c7*/
      case 0x51u: /*0x8643c7*/
      case 0x52u: /*0x8643c7*/
      case 0x53u: /*0x8643c7*/
        argCounta = FFX_AtelOp_QueueActorNodeType2_structural(n7_1, argCount, (int)ScriptWorkerContext_structural, v7); /*0x864ee5*/
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x800; /*0x864eff*/
        goto LABEL_52; /*0x864f03*/
      case 0x39u: /*0x8643c7*/
        n0xFFFFc = FFX_FieldVM_PopOperand(argCount, v7); /*0x864d4d*/
        v66 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864d55*/
        n255 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)); /*0x864d65*/
        n255b = FFX_Field_ResolvePartySlotToActorIndex_structural(v66); /*0x864d68*/
        if ( n0xFFFFc && n255b >= 0 ) /*0x864d7d*/
        {
          v93 = FFX_FieldActor_QueuePriorityNodeIfAbsent_wrapper( /*0x864d97*/
                  *(unsigned __int16 *)(argCount + 46),
                  n255b,
                  0,
                  n255,
                  n0xFFFFc);
          FFX_FieldVM_PushIntOperand_structural(argCount, (int *)(argCount + 196), v93); /*0x864d9f*/
        }
        else
        {
LABEL_98:
          FFX_FieldVM_PushIntOperand_structural(argCount, (int *)(argCount + 196), 0); /*0x8647fd*/
        }
        goto LABEL_52; /*0x864d9f*/
      case 0x3Au: /*0x8643c7*/
        argCountb = (_DWORD *)FFX_FieldVM_PopOperand(argCount, v7); /*0x864dbe*/
        v68 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864dc6*/
        n0xFFFFd = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)); /*0x864dd6*/
        n255b_1 = FFX_Field_ResolvePartySlotToActorIndex_structural(v68); /*0x864dd9*/
        n255b_3 = n255b_1; /*0x864de4*/
        if ( !argCountb || n255b_1 < 0 ) /*0x864ded*/
          goto LABEL_178; /*0x864ded*/
        v70 = FFX_FieldActor_QueuePriorityNodeIfAbsent_wrapper( /*0x864dfb*/
                *(unsigned __int16 *)(argCount + 46),
                n255b_1,
                1,
                n0xFFFFd,
                (int)argCountb);
        goto LABEL_177; /*0x864dfb*/
      case 0x3Bu: /*0x8643c7*/
        argCountb = (_DWORD *)FFX_FieldVM_PopOperand(argCount, v7); /*0x864e94*/
        v72 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864e9c*/
        n0xFFFFd = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)); /*0x864eac*/
        n255b_2 = FFX_Field_ResolvePartySlotToActorIndex_structural(v72); /*0x864eaf*/
        n255b_3 = n255b_2; /*0x864eba*/
        if ( argCountb && n255b_2 >= 0 ) /*0x864ec7*/
        {
          v70 = FFX_FieldActor_QueuePriorityNodeIfAbsent_wrapper( /*0x864ed3*/
                  *(unsigned __int16 *)(argCount + 46),
                  n255b_2,
                  2,
                  n0xFFFFd,
                  (int)argCountb);
LABEL_177:
          v71 = v70; /*0x864e00*/
        }
        else
        {
LABEL_178:
          v71 = 0; /*0x864e07*/
        }
        FFX_FieldVM_PushIntOperand_structural(argCount, (int *)(argCount + 196), v71); /*0x864e12*/
        if ( v71 ) /*0x864e1c*/
        {
          *((_WORD *)ScriptWorkerContext_structural + 22) = (_WORD)argCountb; /*0x864e21*/
          *((_WORD *)ScriptWorkerContext_structural + 23) = n255b_3; /*0x864e28*/
          *((_WORD *)ScriptWorkerContext_structural + 24) = n0xFFFFd; /*0x864e2f*/
          *((_BYTE *)ScriptWorkerContext_structural + 31) = 1; /*0x864e33*/
        }
        argCounta = 0; /*0x864e4b*/
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x800; /*0x864e52*/
        goto LABEL_52; /*0x864e56*/
      case 0x3Cu: /*0x8643c7*/
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0xC00; /*0x86505b*/
        argCounta = 0; /*0x865064*/
        v83 = (void (__cdecl *)(int, int))AtelCurCtrlWork[10]; /*0x86506b*/
        v84 = *(unsigned __int16 *)(argCount + 46); /*0x86506e*/
        if ( v83 ) /*0x865074*/
          v83(v84, 60); /*0x865079*/
        else
          FFX_FieldActor_StopAndUnbindTriggerNode_structural(v84, -1, 0); /*0x865088*/
        goto LABEL_143; /*0x86507e*/
      case 0x3Du: /*0x8643c7*/
        argCounta = 0; /*0x8650a8*/
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0xC00; /*0x8650af*/
        v85 = FFX_FieldVM_PopOperand(argCount, v7); /*0x8650b3*/
        FFX_FieldActor_StopAndUnbindTriggerNode_structural(*(unsigned __int16 *)(argCount + 46), v85, 0); /*0x8650c0*/
        goto LABEL_200; /*0x8650c0*/
      case 0x3Eu: /*0x8643c7*/
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0xC00; /*0x8650e6*/
        argCounta = 0; /*0x8650ef*/
        v86 = (void (__cdecl *)(int, int))AtelCurCtrlWork[10]; /*0x8650f6*/
        v87 = *(unsigned __int16 *)(argCount + 46); /*0x8650f9*/
        if ( v86 ) /*0x8650ff*/
          v86(v87, 62); /*0x865104*/
        else
          FFX_FieldActor_StopAndUnbindTriggerNode_structural(v87, -1, 1); /*0x865113*/
        goto LABEL_143; /*0x865109*/
      case 0x3Fu: /*0x8643c7*/
        argCounta = 0; /*0x865133*/
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0xC00; /*0x86513a*/
        v88 = FFX_FieldVM_PopOperand(argCount, v7); /*0x86513e*/
        FFX_FieldActor_StopAndUnbindTriggerNode_structural(*(unsigned __int16 *)(argCount + 46), v88, 1); /*0x865145*/
LABEL_200:
        v22 = v122; /*0x8650c5*/
        argCounta_2 = 0; /*0x8650cb*/
        goto LABEL_145; /*0x8650cd*/
      case 0x40u: /*0x8643c7*/
        AtelCurCtrlWork = AtelCurCtrlWork; /*0x8643ce*/
        argCounta = 0; /*0x8643d6*/
        *(_WORD *)(argCount + 52) &= 0xE3FFu; /*0x8643de*/
        v18 = AtelCurCtrlWork + 25; /*0x8643e2*/
        n4 = 0; /*0x8643e5*/
        break; /*0x8643e5*/
      case 0x54u: /*0x8643c7*/
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x1000; /*0x865021*/
        argCounta = 0; /*0x86502e*/
        FFX_FieldActor_StopAndUnbindTriggerNode_structural(*(unsigned __int16 *)(argCount + 46), 0, 0); /*0x865035*/
        v22 = v122; /*0x86503a*/
        argCounta_2 = 0; /*0x865040*/
        goto LABEL_145; /*0x865042*/
      case 0x55u: /*0x8643c7*/
        v57 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864b79*/
        v16 = v112; /*0x864b7e*/
        ScriptWorkerContext_structural[8] = (_BYTE *)v57; /*0x864b84*/
        goto LABEL_142; /*0x864b84*/
      case 0x56u: /*0x8643c7*/
        v58 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864bc7*/
        v16 = v112; /*0x864bcc*/
        ScriptWorkerContext_structural[8] = (_BYTE *)v58; /*0x864bd2*/
LABEL_150:
        if ( ScriptWorkerContext_structural[8] ) /*0x864bd5*/
          goto LABEL_142; /*0x864bd9*/
        goto LABEL_52; /*0x864bd9*/
      case 0x57u: /*0x8643c7*/
        v59 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864be3*/
        v16 = v112; /*0x864be8*/
        ScriptWorkerContext_structural[8] = (_BYTE *)v59; /*0x864bee*/
LABEL_153:
        if ( ScriptWorkerContext_structural[8] ) /*0x864bf1*/
          goto LABEL_52; /*0x864bf5*/
LABEL_142:
        FFX_Atel_JumpToLabel((_DWORD *)argCount, (int)ScriptWorkerContext_structural, v16); /*0x864b87*/
        goto LABEL_143; /*0x864b8a*/
      case 0x59u: /*0x8643c7*/
      case 0x5Au: /*0x8643c7*/
      case 0x5Bu: /*0x8643c7*/
      case 0x5Cu: /*0x8643c7*/
        *(_DWORD *)(argCount + 4 * n7 - 284) = FFX_FieldVM_PopOperand(argCount, v7); /*0x864ac2*/
        goto LABEL_52; /*0x864ac9*/
      case 0x5Du: /*0x8643c7*/
      case 0x5Eu: /*0x8643c7*/
      case 0x5Fu: /*0x8643c7*/
      case 0x60u: /*0x8643c7*/
      case 0x61u: /*0x8643c7*/
      case 0x62u: /*0x8643c7*/
      case 0x63u: /*0x8643c7*/
      case 0x64u: /*0x8643c7*/
      case 0x65u: /*0x8643c7*/
      case 0x66u: /*0x8643c7*/
        *(float *)(argCount + 4 * n7 - 284) = FFX_FieldVM_PopFloatOperand_structural(argCount, v7); /*0x864adb*/
        goto LABEL_52; /*0x864ae2*/
      case 0x67u: /*0x8643c7*/
      case 0x68u: /*0x8643c7*/
      case 0x69u: /*0x8643c7*/
      case 0x6Au: /*0x8643c7*/
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, *(_DWORD *)(argCount + 4 * n7_1 - 340)); /*0x864a99*/
        goto LABEL_52; /*0x864a99*/
      case 0x6Bu: /*0x8643c7*/
      case 0x6Cu: /*0x8643c7*/
      case 0x6Du: /*0x8643c7*/
      case 0x6Eu: /*0x8643c7*/
      case 0x6Fu: /*0x8643c7*/
      case 0x70u: /*0x8643c7*/
      case 0x71u: /*0x8643c7*/
      case 0x72u: /*0x8643c7*/
      case 0x73u: /*0x8643c7*/
      case 0x74u: /*0x8643c7*/
        FFX_FieldVM_PushFloatOperand_structural(argCount, v7, COERCE_INT(*(float *)(argCount + 4 * n7_1 - 340))); /*0x864aab*/
        goto LABEL_52; /*0x864ab0*/
      case 0x75u: /*0x8643c7*/
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, FFX_Field_Global_C52704[v16]); /*0x864aee*/
        goto LABEL_52; /*0x864aee*/
      case 0x77u: /*0x8643c7*/
        n0xFFFFf = FFX_FieldVM_PopOperand(argCount, v7); /*0x864f79*/
        n255c = FFX_FieldVM_PopOperand(argCount, v7); /*0x864f7c*/
        n255c_2 = n255c; /*0x864f86*/
        if ( !FFX_Atel_CanSetActorCtxPair_structural(n255c, n0xFFFFf) ) /*0x864f93*/
          goto LABEL_52; /*0x864f93*/
        *((_WORD *)ScriptWorkerContext_structural + 23) = n255c_2; /*0x864f9c*/
        *((_WORD *)ScriptWorkerContext_structural + 22) = n0xFFFFf; /*0x864fa0*/
        goto LABEL_190; /*0x864fa4*/
      case 0x78u: /*0x8643c7*/
        n0xFFFFe = FFX_FieldVM_PopOperand(argCount, v7); /*0x864f11*/
        v74 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864f14*/
        n255c_1 = FFX_Field_ResolvePartySlotToActorIndex_structural(v74); /*0x864f22*/
        if ( !FFX_Atel_CanSetActorCtxPair_structural(n255c_1, n0xFFFFe) || n255c_1 < 0 ) /*0x864f37*/
          goto LABEL_52; /*0x864f37*/
        *((_WORD *)ScriptWorkerContext_structural + 23) = n255c_1; /*0x864f40*/
        *((_WORD *)ScriptWorkerContext_structural + 22) = n0xFFFFe; /*0x864f44*/
LABEL_190:
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x400; /*0x864f48*/
        argCounta = 0; /*0x864f60*/
        *((_BYTE *)ScriptWorkerContext_structural + 31) = 2; /*0x864f67*/
        goto LABEL_52; /*0x864f6b*/
      case 0x79u: /*0x8643c7*/
        v77 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864faf*/
        v78 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864fb6*/
        v79 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)); /*0x864fc0*/
        FFX_AtelOp_79_StoreActorWordSlot_structural((unsigned __int8 **)argCount, v79, v78, v77); /*0x864fc9*/
        ScriptWorkerContext_structural = ScriptWorkerContext_structural_1; /*0x864fce*/
        goto LABEL_52; /*0x864fd4*/
      case 0x7Au: /*0x8643c7*/
        v80 = FFX_FieldVM_PopOperand(argCount, v7); /*0x864fe0*/
        v81 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)); /*0x864fea*/
        v82 = FFX_FieldVM_ResolveActorSlotIndex(argCount, v81, v80); /*0x864ff2*/
        FFX_FieldVM_PushIntOperand_structural(argCount, (int *)(argCount + 196), v82); /*0x865000*/
        goto LABEL_52; /*0x865008*/
      default:
        argCounta_2 = argCounta; /*0x86514a*/
        v22 = v122; /*0x86514d*/
        byte_1327098 = 0; /*0x865150*/
        goto LABEL_145; /*0x86515a*/
    }
    while ( n4 < 4 ) /*0x8643ea*/
    {
      v103 = *((unsigned __int8 *)v18 + 14); /*0x8643f7*/
      if ( *v18 >= 0 && (_BYTE *)v18[2] == ScriptWorkerContext_structural[6] ) /*0x864402*/
      {
        if ( *((_BYTE *)v18 + 15) || v126 == 1 ) /*0x864414*/
        {
          *((_BYTE *)v18 + 15) = 0; /*0x864416*/
          v107 = *((_BYTE *)v18 + 14); /*0x86442a*/
          v20 = FFX_EventData_PackSignedByteWord(v107 & 0x80, (int)ScriptWorkerContext_structural[6]); /*0x86442d*/
          n7_1 = v107 & 0x7F; /*0x864437*/
          v16 = (unsigned int)&byte_FFC194[15979] & v20; /*0x86443a*/
          argCounta_2 = 1; /*0x864443*/
          v112 = v16; /*0x864448*/
          n7 = n7_1; /*0x86444b*/
          argCounta = 1; /*0x86444e*/
          if ( n7_1 <= 0x7A ) /*0x864454*/
            goto LABEL_37; /*0x864454*/
          v22 = v122; /*0x86445a*/
          byte_1327098 = 0; /*0x86445d*/
LABEL_145:
          v103 = -1; /*0x864b98*/
          if ( v126 != 1 ) /*0x864ba2*/
            goto LABEL_26; /*0x864ba2*/
          if ( argCounta_2 ) /*0x864baa*/
            v22 |= 0x4000u; /*0x864bac*/
          argCounta_1 = 0; /*0x864bb2*/
          argCounta = 0; /*0x864bba*/
          v122 = v22 & 0xC000; /*0x864bbd*/
          goto LABEL_27; /*0x864bc0*/
        }
        v22 = v122 | 0x8000; /*0x86446f*/
        *((_BYTE *)v18 + 15) = 1; /*0x864475*/
        v122 |= 0x8000u; /*0x864479*/
        v126 = 1; /*0x86447c*/
LABEL_144:
        argCounta_2 = argCounta; /*0x864b95*/
        goto LABEL_145; /*0x864b95*/
      }
      ++n4; /*0x864404*/
      v18 += 4; /*0x864405*/
    }
LABEL_143:
    v22 = v122; /*0x864b92*/
    goto LABEL_144; /*0x864b92*/
  }
  if ( *v7 ) /*0x86435e*/
  {
    v105 = 0; /*0x864366*/
    goto LABEL_33; /*0x864366*/
  }
LABEL_206:
  LOWORD(v13) = v105; /*0x86515f*/
LABEL_207:
  n8 = *(unsigned __int8 *)(argCount + 50); /*0x865162*/
  if ( (unsigned __int8)(**(_BYTE **)argCount - 5) > 1u ) /*0x865178*/
  {
    if ( *(unsigned __int8 *)(argCount + 50) >= 9u ) /*0x865189*/
      n8 = 8; /*0x86518b*/
  }
  else if ( *(unsigned __int8 *)(argCount + 50) >= 2u ) /*0x86517d*/
  {
    n8 = 1; /*0x86517f*/
  }
  v90 = 76 * n8; /*0x865190*/
  if ( v127 ) /*0x86519f*/
    ((void (__cdecl *)(int, int))AtelCurCtrlWork[23])(argCount, v90 + argCount + 300); /*0x8651ab*/
  *(_WORD *)(argCount + 52) ^= (*(_WORD *)(argCount + 52) ^ (8 * v13)) & 8; /*0x8651bf*/
  ReleaseMutex_w(_Jarvis_naming_goal_2026_06_17__proved_navigation_name_from_agg); /*0x8651c9*/
  return v122; /*0x8651d7*/
}

// ===========================================================================
// FFX_Atel_GetScriptWorkerCount
// addr: 0x86A5E0  purpose: Get script worker count
// ===========================================================================
// [Jarvis naming goal 2026-06-17] ATEL script worker count accessor; returns u16 at script+0x36.
// FFX Atel: Get script worker count
int __cdecl FFX_Atel_GetScriptWorkerCount(int a1)
{
  // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0x86a5ea*/
  return *(unsigned __int16 *)(a1 + 54); /*0x86a5ea*/
}

// ===========================================================================
// FFX_Atel_GetScriptWorkerByIndex
// addr: 0x86BB10  purpose: Get script worker by index
// ===========================================================================
// [Jarvis naming goal 2026-06-17] ATEL script worker-by-index accessor; returns script + u32(script+0x38+4*index).
// FFX Atel: Get script worker by index
int __cdecl FFX_Atel_GetScriptWorkerByIndex(int a1, int a2)
{
  // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0x86bb1f*/
  return a1 + *(_DWORD *)(a1 + 4 * a2 + 56); /*0x86bb1f*/
}

// ===========================================================================
// FFX_Field_InitScriptWorkerDefaults
// addr: 0x871130  purpose: Init script worker defaults
// ===========================================================================
// FFX Field: Init script worker defaults
int __cdecl FFX_Field_InitScriptWorkerDefaults(int n3)
{
  _BYTE *v1; // esi
  int result; // eax

  v1 = &Controllers[568 * n3]; /*0x87113d*/
  *v1 |= 1u; /*0x871143*/
  result = -(*((_DWORD *)v1 + 7) != 0); /*0x87114b*/
  byte_1327098 &= result; /*0x87114d*/
  if ( !*((_DWORD *)v1 + 8) ) /*0x871153*/
    *((_DWORD *)v1 + 8) = FFX_Field_AiScriptStateMachine_structural; /*0x871159*/
  if ( !*((_DWORD *)v1 + 11) ) /*0x871160*/
  {
    result = (int)(AtelGetEventSaveRamAdrs() + 123); /*0x87116b*/
    *((_DWORD *)v1 + 11) = result; /*0x871170*/
  }
  if ( !*((_DWORD *)v1 + 19) ) /*0x871173*/
    *((_DWORD *)v1 + 19) = FFX_Field_UpdateTickSimple; /*0x871179*/
  if ( !*((_DWORD *)v1 + 22) ) /*0x871180*/
    *((_DWORD *)v1 + 22) = FFX_Event_SetActorPositionConditional; /*0x871186*/
  if ( !*((_DWORD *)v1 + 23) ) /*0x87118d*/
    *((_DWORD *)v1 + 23) = FFX_FieldActor_DispatchTriggerTypeEvaluation_structural; /*0x871193*/
  if ( !*((_DWORD *)v1 + 24) ) /*0x87119a*/
    *((_DWORD *)v1 + 24) = FFX_Const_Return1; /*0x8711a0*/
  return result; /*0x8711a7*/
}

// ===========================================================================
// FFX_Field_IsScriptWorkerActive
// addr: 0x874F80  purpose: Is script worker active
// ===========================================================================
// FFX Field: Is script worker active
BOOL __cdecl FFX_Field_IsScriptWorkerActive(int a1)
{
  return *(_DWORD *)&byte_1327F10[256 * a1] != 0; /*0x874f94*/
}

// ===========================================================================
// FFX_Field_ShiftRemoveScriptWorker
// addr: 0x875030  purpose: Shift/remove script worker
// ===========================================================================
// FFX Field: Shift remove script worker
BOOL __cdecl FFX_Field_ShiftRemoveScriptWorker(int a1)
{
  int v1; // ebx
  int (__cdecl *v2)(char *); // ecx
  char *v3; // edi
  int n15; // ebx
  char *v5; // esi
  char *v6; // eax
  char v7; // cl
  int v9; // [esp+Ch] [ebp+8h]

  v1 = a1 << 8; /*0x875037*/
  v9 = v1; /*0x87503a*/
  v2 = *(int (__cdecl **)(char *))&byte_1327F10[v1]; /*0x87503d*/
  if ( !v2 ) /*0x875045*/
    return 1; /*0x8750b2*/
  if ( v2(&byte_1327F14[v1]) ) /*0x87504e*/
  {
    v3 = &byte_1327F20[v1]; /*0x875059*/
    n15 = 15; /*0x87505f*/
    v5 = v3 - 8; /*0x875064*/
    do /*0x875093*/
    {
      *((_DWORD *)v5 - 2) = *(_DWORD *)v3; /*0x875069*/
      *((_DWORD *)v5 - 1) = *((_DWORD *)v5 + 3); /*0x87506f*/
      v6 = v5 + 16; /*0x875072*/
      do /*0x87508a*/
      {
        v7 = *v6; /*0x875080*/
        *(v6 - 16) = *v6; /*0x875082*/
        ++v6; /*0x875085*/
      }
      while ( v7 ); /*0x87508a*/
      v3 += 16; /*0x87508c*/
      v5 += 16; /*0x87508f*/
      --n15; /*0x875092*/
    }
    while ( n15 ); /*0x875093*/
    v1 = v9; /*0x875095*/
    *(_DWORD *)&byte_1328000[v9] = 0; /*0x875099*/
  }
  return *(_DWORD *)&byte_1327F10[v1] == 0; /*0x8750ac*/
}

// ===========================================================================
// FFX_AtelOp_SpawnCharacterInstance
// addr: 0x85E4D0  purpose: Event object spawning
// ===========================================================================
// FFX AtelOp: Spawn character instance
int __cdecl FFX_AtelOp_SpawnCharacterInstance(int a1, int a2, int *a3)
{
  int v4; // ebx
  int v5; // eax
  _WORD *inited; // eax
  int v7; // eax
  int v9; // [esp+Ch] [ebp-4h]
  int v10; // [esp+18h] [ebp+8h]

  v9 = FFX_FieldVM_PopOperand(a1, a3); /*0x85e4e6*/
  v10 = FFX_FieldVM_PopOperand(a1, a3); /*0x85e4f0*/
  v4 = FFX_FieldVM_PopOperand(a1, a3); /*0x85e4f8*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, v4); /*0x85e4fd*/
  v5 = FFX_FieldVM_PopOperand(a1, a3); /*0x85e504*/
  FFX_Chr_DisposeSlotCharacter(a1, v5); /*0x85e50b*/
  if ( !*(_DWORD *)(a1 + 156) || !v10 ) /*0x85e525*/
    return 0; /*0x85e5fc*/
  inited = FFX_Chr_AllocateAndInitModel(v10); /*0x85e52c*/
  *(_DWORD *)(a1 + 4 * v4 + 2804) = inited; /*0x85e537*/
  *(_DWORD *)(a1 + 4 * v4 + 2812) = v9; /*0x85e53e*/
  FFX_Chr_SetByte388((int)inited, 15); /*0x85e545*/
  v7 = *(_DWORD *)(a1 + 4 * v4 + 2804); /*0x85e54a*/
  if ( v7 ) /*0x85e556*/
  {
    FFX_Chr_SetAttachmentWithHide( /*0x85e573*/
      *(unsigned __int16 *)(a1 + 168),
      v7,
      *(_DWORD *)(a1 + 156),
      *(_DWORD *)(a1 + 4 * v4 + 2812),
      v4);
    FFX_Chr_SetGravityMode(*(_DWORD *)(a1 + 4 * v4 + 2804), 0); /*0x85e581*/
    FFX_Chr_ToggleNavmeshAndSetFall(*(_DWORD *)(a1 + 4 * v4 + 2804), 0); /*0x85e58f*/
    FFX_Chr_SetVisibilityEnabled(*(_DWORD *)(a1 + 4 * v4 + 2804), 0); /*0x85e59d*/
    FFX_Chr_ToggleFlag11In404(*(_DWORD *)(a1 + 4 * v4 + 2804), *(_WORD *)(a1 + 4 * v4 + 2824) & 1); /*0x85e5b4*/
    FFX_Chr_SetByte39F(*(_DWORD *)(a1 + 4 * v4 + 2804), (*(_DWORD *)(a1 + 4 * v4 + 2824) >> 1) & 1); /*0x85e5cd*/
    *(_WORD *)(a1 + 2836) |= 1 << v4; /*0x85e5df*/
    *(_WORD *)(a1 + 2 * v4 + 2820) = v10; /*0x85e5e6*/
  }
  return 1; /*0x85e5ee*/
}

// ===========================================================================
// FFX_AtelOp_EventStringDispatch_structural
// addr: 0x860AA0  purpose: Event text display dispatch
// ===========================================================================
// FFX AtelOp: Event string dispatch
// ATEL op: event string dispatch. Dispatches event dialogue strings for field events. Part of the ATEL VM opcode handler set.
int __cdecl FFX_AtelOp_EventStringDispatch_structural(int a1, int a2, int *a3, int n8)
{
  int v4; // ebx
  int v5; // edi
  int v6; // esi
  int v7; // eax
  int v8; // edi
  int v9; // eax
  char *EventStruct; // esi
  float *v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // esi
  int v15; // eax
  char *v16; // eax
  int v18; // [esp+Ch] [ebp-14h]
  int v19; // [esp+10h] [ebp-10h]
  int v20; // [esp+14h] [ebp-Ch]
  int v21; // [esp+18h] [ebp-8h]
  int v22; // [esp+1Ch] [ebp-4h]

  v4 = FFX_FieldVM_PopOperand(a1, a3); /*0x860ab8*/
  v5 = FFX_FieldVM_PopOperand(a1, a3); /*0x860ac3*/
  v6 = FFX_FieldVM_PopOperand(a1, a3); /*0x860acd*/
  v19 = FFX_FieldVM_PopOperand(a1, a3); /*0x860ada*/
  v20 = FFX_FieldVM_PopOperand(a1, a3); /*0x860ae8*/
  v18 = FFX_FieldVM_PopOperand(a1, a3); /*0x860af6*/
  v21 = FFX_FieldVM_PopOperand(a1, a3); /*0x860b04*/
  v22 = FFX_FieldVM_PopOperand(a1, a3); /*0x860b12*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, v22); /*0x860b1c*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, v6); /*0x860b29*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, v5); /*0x860b34*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, v4); /*0x860b3e*/
  FFX_AtelOp_CreateEventStructWithLocaleFixup(a1, a2, a3); /*0x860b48*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, v22); /*0x860b53*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, 0); /*0x860b5f*/
  LOBYTE(v4) = FFX_FieldVM_PopOperand(a1, a3); /*0x860b6f*/
  v7 = FFX_FieldVM_PopOperand(a1, a3); /*0x860b71*/
  FFX_Field_GetEventStruct(v7)[32] = v4; /*0x860b7c*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, v22); /*0x860b87*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, v21); /*0x860b91*/
  v8 = FFX_FieldVM_PopOperand(a1, a3); /*0x860ba0*/
  v9 = FFX_FieldVM_PopOperand(a1, a3); /*0x860ba4*/
  *(_DWORD *)&FFX_Battle_CtbPriorityQueue[2041532] = v8; /*0x860baa*/
  EventStruct = FFX_Field_GetEventStruct(v9); /*0x860bb6*/
  v11 = FFX_EventString_ResolveById(v8); /*0x860bb8*/
  *((_DWORD *)EventStruct + 2) = v11; /*0x860bbd*/
  *((_DWORD *)EventStruct + 3) = v11; /*0x860bc0*/
  MsGetSaveConfigEnglish(); /*0x860bc3*/
  *((_WORD *)EventStruct + 11) = FFX_Atel_GetFieldStringTableWordByIndex(v8); /*0x860bd3*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, v22); /*0x860bdc*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, 0); /*0x860be5*/
  v12 = FFX_FieldVM_PopOperand(a1, a3); /*0x860bf5*/
  v13 = FFX_FieldVM_PopOperand(a1, a3); /*0x860bf7*/
  *((_DWORD *)FFX_Field_GetEventStruct(v13) + 6) = v12; /*0x860c06*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, v22); /*0x860c0e*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, v20); /*0x860c18*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, v19); /*0x860c22*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, v18); /*0x860c2c*/
  v14 = FFX_FieldVM_PopOperand(a1, a3); /*0x860c3c*/
  LOBYTE(v18) = FFX_FieldVM_PopOperand(a1, a3); /*0x860c46*/
  LOBYTE(v4) = FFX_FieldVM_PopOperand(a1, a3); /*0x860c55*/
  v15 = FFX_FieldVM_PopOperand(a1, a3); /*0x860c5a*/
  v16 = FFX_Field_GetEventStruct(v15); /*0x860c60*/
  v16[34] = v4; /*0x860c68*/
  *((_DWORD *)v16 + 9) = v14; /*0x860c6f*/
  v16[35] = v18; /*0x860c77*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, v22); /*0x860c7a*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, n8 | 0x42); /*0x860c88*/
  FFX_Atel_Common_DrawItemChoiceList(a1, a2, a3); /*0x860c95*/
  FFX_FieldVM_PushIntOperand_structural(a1, a3, v22); /*0x860ca0*/
  return FFX_Atel_Common_Func007D_CALL_structural(a1, a2, a3); /*0x860cb3*/
}

// ===========================================================================
// FFX_Atel_Camera_camSetPolar_CALL
// addr: 0x7B9260  purpose: Camera script exec (camSetPolar)
// ===========================================================================
// FFX Atel Camera: camSetPolar call
int __cdecl FFX_Atel_Camera_camSetPolar_CALL(int vmCtx, int *pResult, int *pStack)
{
  FFX_Camera_SetPolar_FromAtelStack(vmCtx, (int)pResult, pStack, 1, 0);// [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0x7b9270*/
  return 0; /*0x7b927a*/
}

// ===========================================================================
// FFX_Field_ProcessInputAndEvents
// addr: 0x644B40  purpose: Field input + events processing
// ===========================================================================
// Field frame pipeline: async queue → input processing → Iggy events → dispatch
// FFX Field: Process input and events
void __cdecl FFX_Field_ProcessInputAndEvents(FFXField *pField, float deltaTime)
{
  float *Context; // eax
  _DWORD *GlobalIggyEventState; // eax
  void *v4; // ecx

  Context = (float *)FFX_AsyncQ_GetContext(); /*0x644b40*/
  ProcessObjectQueue(Context); /*0x644b47*/
  GlobalIggyEventState = (_DWORD *)Phyre_GetGlobalIggyEventState();// step 2: get global Iggy event state /*0x644b4c*/
  Phyre_InputState_BuildEventList(GlobalIggyEventState);// step 3: build Iggy event list from input state /*0x644b53*/
  Phyre_IggyEvent_ProcessAll(*(_DWORD **)&byte_1981AC0[12716]);// step 4: process all pending Iggy events /*0x644b5e*/
  inputClear(v4); /*0x644b63*/
}
