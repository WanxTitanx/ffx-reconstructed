// Jarvis-HEAVY H09: ATEL VM interpreter. Fetches opcode via 0x869D00, strips operand flag, dispatches cases 0..0x7A; CALL/CALLPOPA cases 0x35/0x58 route native call IDs through namespace dispatchers.
// FFX: Field event parser structural — ATEL VM interpreter main loop (4KB, 123-case switch, fetches opcodes via 0x869D00)
// FFX Field: Event parser (ATEL VM interpreter, 123-case switch)
// ATEL VM interpreter main loop. 4208 bytes, 224 basic blocks, 123-case switch (0x00-0x7A). Fetches opcodes via FFX_Atel_FetchOpcode(0x869D00), strips operand flag, dispatches to FFX_AtelOp_* handler functions. Opcodes: NCJMP, JSR, RTS, CALL, REQ, RET, HALT, PUSHN, PUSHT, PUSHVP, PUSHFIX, POPI0-3, POPF0-9, PUSHI0-3, PUSHF0-9, PUSHAINTER, ER, AIT, SYSTEM.
// ATEL VM interpreter. Fetches opcode via FFX_Atel_FetchOpcode(0x869D00), strips operand flag, dispatches cases 0..0x7A (123 cases). Each case calls individual FFX_AtelOp_* handler. 224 basic blocks, cyclomatic complexity 156.
// ARBITRATED 2026-09-14 (MICRO-FIXES/F1a): BATTLE uses this SAME interpreter via wrapper FFX_Atel_ParseEventWithFlag1@0x864160 (5 battle callers: 0x7972F0 camera, 0x797360 ch2 tick, 0x7973C0 actor priorities, 0x7979E0/0x797D60 btl UI menu tree). Direct xrefs stay field-only (0x864160/0x867740/0x8678F0 x2/0x868380). Resolves F24: 'same VM battle+field' is proven, one hop deeper than the direct xrefs.
// [ATEL-NUANCES 2026-09-15] PROLOGUE (disasm 0x864180-0x8641ca): single ATEL VM interpreter is thread-serialized by a lazily-created global mutex (Sys_Mutex_Create + WaitForSingleObject at entry) and is BATTLE-AWARE FROM THE START: after reading worker flags (+0x34 bit1 must be set or bail; bit2 / +0x36 bit6 pass gates) it calls FFX_Battle_IsEncounterSuppressed@0x780D60 and bails if suppressed. Concludes F24/M3: ONE VM shared battle+field — battle enters via wrapper 0x864160, field calls here directly with same (worker, arg2, 1) arg shape. Mutex is relevant to Force Battle lane: ATEL reentry off main thread waits on this lock.
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

  [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = _Jarvis_naming_goal_2026_06_17__proved_navigation_name_from_agg;// [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass.
  if ( _Jarvis_naming_goal_2026_06_17__proved_navigation_name_from_agg == (HANDLE *)-1 )
  {
    [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = (HANDLE *)Sys_Mutex_Create();
    _Jarvis_naming_goal_2026_06_17__proved_navigation_name_from_agg = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg;
  }
  WaitForSingleObject_w([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg);
  v6 = *(_WORD *)(argCount + 52);
  if ( (v6 & 2) == 0
    || (v6 & 4) == 0 && (*(_BYTE *)(argCount + 54) & 0x40) == 0 && FFX_Battle_IsEncounterSuppressed(v4)
    || (*((_BYTE *)AtelCurCtrlWork + 3) & 3) == 1
    || (*((_BYTE *)AtelCurCtrlWork + 3) & 3) == 2 && *(__int16 *)(argCount + 54) >= 0 )
  {
    ReleaseMutex_w(_Jarvis_naming_goal_2026_06_17__proved_navigation_name_from_agg);
    return 0;
  }
  v102 = 0;
  v7 = (int *)(argCount + 196);
  ScriptWorkerContext_structural = FFX_FieldActor_GetScriptWorkerContext_structural(
                                     (_BYTE **)argCount,
                                     *(unsigned __int8 *)(argCount + 50));
  ScriptWorkerContext_structural_1 = ScriptWorkerContext_structural;
  argCountc = *(float *)(argCount + 148) * unk_1326B98;
  v104 = argCountc + *(float *)(argCount + 152);
  if ( argCountc < 1.0 )
  {
    argCounta = 0;
  }
  else
  {
    argCounta = 1;
    v104 = v104 - 1.0;
  }
  *(float *)(argCount + 152) = v104;
  v122 = v104 >= 1.0;
  v105 = 1;
  v103 = -1;
  if ( v127 )
    ((void (__cdecl *)(int, _BYTE **))AtelCurCtrlWork[22])(argCount, ScriptWorkerContext_structural);
  while ( 1 )
  {
    if ( !*((_BYTE *)ScriptWorkerContext_structural + 31) )
      goto LABEL_25;
    if ( *((_BYTE *)ScriptWorkerContext_structural + 31) == 1 )
      break;
    if ( *((_BYTE *)ScriptWorkerContext_structural + 31) != 2 )
      goto LABEL_33;
    v9 = *(int **)(FFX_Field_AiScriptStateMachine_structural(*((unsigned __int16 *)ScriptWorkerContext_structural + 23))
                 + 128);
    if ( v9 )
    {
      while ( 1 )
      {
        v10 = (int *)*v9;
        if ( *((_BYTE *)v9 + 15) != 3
          && *((unsigned __int16 *)v9 + 4) == *((unsigned __int16 *)ScriptWorkerContext_structural + 22) )
        {
          break;
        }
        v9 = (int *)*v9;
        if ( !v10 )
          goto LABEL_22;
      }
LABEL_33:
      v13 = *v7 == 0 ? v105 : 0;
      goto LABEL_207;
    }
LABEL_22:
    *((_BYTE *)ScriptWorkerContext_structural + 31) = 0;
  }
  v11 = FFX_Field_EventNodeSearch(argCount, ScriptWorkerContext_structural);
  if ( !v11 )
    goto LABEL_33;
  FFX_FieldActor_LinkTriggerNode_structural(*(unsigned __int16 *)(argCount + 46), v11);
  *((_BYTE *)ScriptWorkerContext_structural + 31) = 0;
LABEL_25:
  *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x400;
LABEL_26:
  argCounta_1 = argCounta;
LABEL_27:
  if ( ++v102 > 0x10000 )
  {
    argCounta_1 = 0;
    argCounta = 0;
    *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x1400;
    unk_1327098 = 0;
  }
  if ( v126 != 1 )
  {
    if ( !argCounta_1 && !*v7 )
      goto LABEL_206;
    goto LABEL_36;
  }
  if ( argCounta_1 )
  {
LABEL_36:
    v14 = FFX_Atel_FetchOpcode(argCount, (int)ScriptWorkerContext_structural);
    n7_1 = HIBYTE(v14);
    v16 = (unsigned int)&unk_FFFFFF & v14;
    v112 = (unsigned int)&unk_FFFFFF & v14;
    n7 = HIBYTE(v14);
    LOWORD(v105) = 1;
LABEL_37:
    switch ( n7_1 )
    {
      case 0u:
      case 0x1Du:
      case 0x1Eu:
      case 0x76u:
        goto LABEL_52;
      case 1u:
        n0xFFFF = FFX_FieldVM_PopOperand(argCount, v7);
        if ( !FFX_FieldVM_PopOperand(argCount, v7) && !n0xFFFF )
          goto LABEL_50;
        goto LABEL_57;
      case 2u:
        n0xFFFFa = FFX_FieldVM_PopOperand(argCount, v7);
        if ( FFX_FieldVM_PopOperand(argCount, v7) && n0xFFFFa )
LABEL_57:
          v23 = 1;
        else
LABEL_50:
          v23 = 0;
        goto LABEL_51;
      case 3u:
        v28 = FFX_FieldVM_PopOperand(argCount, v7);
        v27 = v28 | FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196));
        goto LABEL_59;
      case 4u:
        v29 = FFX_FieldVM_PopOperand(argCount, v7);
        v27 = v29 ^ FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196));
        goto LABEL_59;
      case 5u:
        v26 = FFX_FieldVM_PopOperand(argCount, v7);
        v27 = v26 & FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196));
        goto LABEL_59;
      case 6u:
      case 7u:
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) )
        {
          v30 = FFX_FieldVM_PopOperand(argCount, v7);
          v33 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) == v30;
          v7 = (int *)(argCount + 196);
          if ( v33 )
          {
            v31 = 1;
            goto LABEL_68;
          }
        }
        else
        {
          v113 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
          v32 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
          v31 = 1;
          if ( v113 == v32 )
            goto LABEL_68;
        }
        v31 = 0;
LABEL_68:
        v33 = n7 == 7;
        goto LABEL_69;
      case 8u:
      case 0xDu:
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) )
        {
          v34 = FFX_FieldVM_PopOperand(argCount, v7);
          v35 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) <= v34;
          v7 = (int *)(argCount + 196);
          if ( !v35 )
          {
            v33 = n7 == 13;
            v31 = 1;
            goto LABEL_69;
          }
        }
        else
        {
          v114 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
          v36 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
          v31 = 1;
          if ( v114 < v36 )
            goto LABEL_77;
        }
        v31 = 0;
LABEL_77:
        v33 = n7 == 13;
        goto LABEL_69;
      case 9u:
      case 0xCu:
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) )
        {
          v37 = FFX_FieldVM_PopOperand(argCount, v7);
          v38 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) < v37;
          v7 = (int *)(argCount + 196);
          if ( !v38 )
          {
            v33 = n7 == 9;
            v31 = 1;
            goto LABEL_69;
          }
        }
        else
        {
          v115 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
          v39 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
          v31 = 1;
          if ( v115 <= v39 )
            goto LABEL_83;
        }
        v31 = 0;
LABEL_83:
        v33 = n7 == 9;
        goto LABEL_69;
      case 0xAu:
      case 0xFu:
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) )
        {
          v40 = FFX_FieldVM_PopOperand(argCount, v7);
          v35 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) <= v40;
          v7 = (int *)(argCount + 196);
          if ( !v35 )
          {
            v33 = n7 == 15;
            v31 = 1;
            goto LABEL_69;
          }
        }
        else
        {
          v116 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
          v41 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
          v31 = 1;
          if ( v116 < v41 )
            goto LABEL_89;
        }
        v31 = 0;
LABEL_89:
        v33 = n7 == 15;
        goto LABEL_69;
      case 0xBu:
      case 0xEu:
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) )
        {
          v42 = FFX_FieldVM_PopOperand(argCount, v7);
          v35 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) < v42;
          v7 = (int *)(argCount + 196);
          if ( !v35 )
          {
            v33 = n7 == 11;
            v31 = 1;
            goto LABEL_69;
          }
        }
        else
        {
          v117 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
          v43 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
          v31 = 1;
          if ( v117 <= v43 )
            goto LABEL_95;
        }
        v31 = 0;
LABEL_95:
        v33 = n7 == 11;
LABEL_69:
        if ( v33 )
          v31 = !v31;
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, v31);
        goto LABEL_52;
      case 0x10u:
        v44 = FFX_FieldVM_PopOperand(argCount, v7);
        if ( (FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) & (1 << v44)) != 0 )
          goto LABEL_97;
        goto LABEL_98;
      case 0x11u:
        v45 = FFX_FieldVM_PopOperand(argCount, v7);
        if ( (FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) & (1 << v45)) != 0 )
          goto LABEL_98;
LABEL_97:
        FFX_FieldVM_PushIntOperand_structural(argCount, (int *)(argCount + 196), 1);
        goto LABEL_52;
      case 0x12u:
        v46 = FFX_FieldVM_PopOperand(argCount, v7);
        v27 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) << v46;
        goto LABEL_59;
      case 0x13u:
        v47 = FFX_FieldVM_PopOperand(argCount, v7);
        v27 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) >> v47;
        goto LABEL_59;
      case 0x14u:
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) )
        {
          v48 = FFX_FieldVM_PopOperand(argCount, v7);
          v27 = v48 + FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196));
          goto LABEL_59;
        }
        v118 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
        v49 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7) + v118;
        goto LABEL_106;
      case 0x15u:
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) )
        {
          v50 = FFX_FieldVM_PopOperand(argCount, v7);
          v27 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) - v50;
          goto LABEL_59;
        }
        v119 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
        v49 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7) - v119;
        goto LABEL_106;
      case 0x16u:
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) )
        {
          v51 = FFX_FieldVM_PopOperand(argCount, v7);
          v27 = v51 * FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196));
          goto LABEL_59;
        }
        v120 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
        v49 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7) * v120;
        goto LABEL_106;
      case 0x17u:
        if ( FFX_Event_CheckFlagBytePair(argCount, v7) )
        {
          v52 = FFX_FieldVM_PopOperand(argCount, v7);
          v27 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) / v52;
LABEL_59:
          FFX_FieldVM_PushIntOperand_structural(argCount, (int *)(argCount + 196), v27);
        }
        else
        {
          v121 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
          v49 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7) / v121;
LABEL_106:
          *(float *)&v108 = v49;
          FFX_FieldVM_PushFloatOperand_structural(argCount, v7, v108);
        }
        goto LABEL_52;
      case 0x18u:
        v53 = FFX_FieldVM_PopOperand(argCount, v7);
        v92 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196)) % v53;
        FFX_FieldVM_PushIntOperand_structural(argCount, (int *)(argCount + 196), v92);
        goto LABEL_52;
      case 0x19u:
        v54 = FFX_FieldVM_PopOperand(argCount, v7);
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, v54 == 0);
        goto LABEL_52;
      case 0x1Au:
        v49 = FFX_FieldVM_PopFloatOperand_structural(argCount, v7) * -1.0;
        goto LABEL_106;
      case 0x1Cu:
        v55 = FFX_FieldVM_PopOperand(argCount, v7);
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, ~v55);
        goto LABEL_52;
      case 0x1Fu:
        FFX_FieldEvent_ReadArrayToStack((_DWORD *)argCount, v7, v16, 0);
        goto LABEL_52;
      case 0x20u:
        FFX_FieldVM_StoreArrayOperandMode_structural((_DWORD *)argCount, v7, v16, 0);
        goto LABEL_52;
      case 0x21u:
        FFX_FieldVM_StoreArrayOperandMode_structural((_DWORD *)argCount, v7, v16, 1);
        goto LABEL_52;
      case 0x22u:
        FFX_FieldEvent_PopStackValue((_DWORD *)argCount, v7, v16);
        goto LABEL_52;
      case 0x23u:
        FFX_FieldVM_StoreArrayOperandMode_structural((_DWORD *)argCount, v7, v16, 128);
        goto LABEL_52;
      case 0x24u:
        FFX_FieldVM_StoreArrayOperandMode_structural((_DWORD *)argCount, v7, v16, 129);
        goto LABEL_52;
      case 0x25u:
        goto LABEL_169;
      case 0x26u:
        FFX_FieldVM_PushFloatOperand_structural(
          argCount,
          v7,
          COERCE_INT(*((float *)ScriptWorkerContext_structural + 10)));
        goto LABEL_52;
      case 0x27u:
        FFX_FieldVM_PushArrayOperand_structural((_DWORD *)argCount, v7, v16);
        goto LABEL_52;
      case 0x28u:
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, (int)ScriptWorkerContext_structural[8]);
        goto LABEL_52;
      case 0x29u:
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, (int)ScriptWorkerContext_structural[9]);
        goto LABEL_52;
      case 0x2Au:
        ScriptWorkerContext_structural[8] = (_BYTE *)FFX_FieldVM_PopOperand(argCount, v7);
        goto LABEL_52;
      case 0x2Bu:
        v56 = FFX_FieldVM_StackPopValue(argCount, v7);
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, v56);
        goto LABEL_52;
      case 0x2Cu:
        ScriptWorkerContext_structural[9] = (_BYTE *)FFX_FieldVM_PopOperand(argCount, v7);
        goto LABEL_52;
      case 0x2Du:
        FFX_FieldVM_PushIntOperand_structural(
          argCount,
          v7,
          *(_DWORD *)(*(_DWORD *)(*(_DWORD *)argCount + 24) + 4 * v16 + *(_DWORD *)(argCount + 4)));
        goto LABEL_52;
      case 0x2Eu:
        v23 = (__int16)v16;
LABEL_51:
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, v23);
        goto LABEL_52;
      case 0x2Fu:
        FFX_FieldVM_PushFloatOperand_structural(
          argCount,
          v7,
          COERCE_INT(*(float *)(*(_DWORD *)(*(_DWORD *)argCount + 28) + 4 * v16 + *(_DWORD *)(argCount + 4))));
        goto LABEL_52;
      case 0x30u:
        goto LABEL_142;
      case 0x31u:
        goto LABEL_150;
      case 0x32u:
        goto LABEL_153;
      case 0x33u:
        n0xFFFFb = *((char *)ScriptWorkerContext_structural + 29);
        if ( n0xFFFFb >= 3 )
        {
          unk_1327098 = 0;
          goto LABEL_52;
        }
        ScriptWorkerContext_structural[n0xFFFFb] = &ScriptWorkerContext_structural[6][-*(_DWORD *)(*(_DWORD *)(argCount + 4)
                                                                                                 + 48)
                                                                                    - *(_DWORD *)(argCount + 4)
                                                                                    + 3];
        *((_WORD *)ScriptWorkerContext_structural + n0xFFFFb + 8) = v16;
        *((_BYTE *)ScriptWorkerContext_structural + 29) = n0xFFFFb + 1;
        v60 = (_DWORD *)FFX_Field_AiScriptStateMachine_structural(v16);
        v61 = *(_DWORD *)(v60[1] + *(_DWORD *)(*v60 + 32));
        *((_BYTE *)ScriptWorkerContext_structural + 30) = 0;
        ScriptWorkerContext_structural[6] = (_BYTE *)(v61
                                                    + *(_DWORD *)(argCount + 4)
                                                    + *(_DWORD *)(*(_DWORD *)(argCount + 4) + 48));
        goto LABEL_143;
      case 0x34u:
        v62 = *((char *)ScriptWorkerContext_structural + 29);
        if ( v62 <= 0 )
        {
          unk_1327098 = 0;
          goto LABEL_52;
        }
        v63 = ScriptWorkerContext_structural[v62 - 1];
        *((_BYTE *)ScriptWorkerContext_structural + 30) = 0;
        ScriptWorkerContext_structural[6] = &v63[*(_DWORD *)(argCount + 4) + *(_DWORD *)(*(_DWORD *)(argCount + 4) + 48)];
        *((_BYTE *)ScriptWorkerContext_structural + 29) = v62 - 1;
        goto LABEL_143;
      case 0x35u:
      case 0x58u:
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x400;
        argCounta = 0;
        if ( *((_BYTE *)ScriptWorkerContext_structural + 30) )
        {
          if ( *((_BYTE *)ScriptWorkerContext_structural + 30) != 1 )
            goto LABEL_143;
        }
        else
        {
          *((_BYTE *)ScriptWorkerContext_structural + 30) = 1;
          FFX_Atel_DispatchNativeCall(1024);
          v16 = v112;
        }
        v64 = FFX_Atel_CallStatusDispatchByNamespace(v16, argCount, (int)(ScriptWorkerContext_structural + 11));
        v65 = -((v64 & 2) == 0);
        LOWORD(v105) = v65 & 1;
        if ( (v64 & 4) != 0 )
          argCounta = 1;
        if ( (v64 & 1) != 0 )
        {
          FFX_Atel_CallReturnDispatchByNamespace(v65);
          *((_BYTE *)ScriptWorkerContext_structural + 30) = 0;
          if ( n7 == 88 )
LABEL_169:
            *((float *)ScriptWorkerContext_structural + 10) = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
LABEL_52:
          v24 = v103;
          if ( v103 < 0 )
            v24 = *ScriptWorkerContext_structural[6];
          v25 = (int)&ScriptWorkerContext_structural[6][-*(_DWORD *)(*(_DWORD *)(argCount + 4) + 48)
                                                      - *(_DWORD *)(argCount + 4)];
          *((_BYTE *)ScriptWorkerContext_structural + 30) = 0;
          ScriptWorkerContext_structural[6] = (_BYTE *)(v25
                                                      + ((v24 | 0x40u) >> 6)
                                                      + *(_DWORD *)(argCount + 4)
                                                      + *(_DWORD *)(*(_DWORD *)(argCount + 4) + 48));
          v7 = (int *)(argCount + 196);
        }
        goto LABEL_143;
      case 0x36u:
      case 0x45u:
      case 0x46u:
      case 0x47u:
      case 0x48u:
      case 0x49u:
        FFX_AtelOp_QueueActorNodeType0_structural(n7_1, (int)ScriptWorkerContext_structural, argCount, v7);
        goto LABEL_52; // Event: Sends 0x15 with index — sends event token 0x15 with index
      case 0x37u:
      case 0x4Au:
      case 0x4Bu:
      case 0x4Cu:
      case 0x4Du:
      case 0x4Eu:
        argCounta = FFX_AtelOp_QueueActorNodeType1_structural(n7_1, argCount, (int)ScriptWorkerContext_structural, v7);
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x800;
        goto LABEL_52;
      case 0x38u:
      case 0x4Fu:
      case 0x50u:
      case 0x51u:
      case 0x52u:
      case 0x53u:
        argCounta = FFX_AtelOp_QueueActorNodeType2_structural(n7_1, argCount, (int)ScriptWorkerContext_structural, v7);
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x800;
        goto LABEL_52;
      case 0x39u:
        n0xFFFFc = FFX_FieldVM_PopOperand(argCount, v7);
        v66 = FFX_FieldVM_PopOperand(argCount, v7);
        n255 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196));
        n255b = FFX_Field_ResolvePartySlotToActorIndex_structural(v66);
        if ( n0xFFFFc && n255b >= 0 )
        {
          v93 = FFX_FieldActor_QueuePriorityNodeIfAbsent_wrapper(
                  *(unsigned __int16 *)(argCount + 46),
                  n255b,
                  0,
                  n255,
                  n0xFFFFc);
          FFX_FieldVM_PushIntOperand_structural(argCount, (int *)(argCount + 196), v93);
        }
        else
        {
LABEL_98:
          FFX_FieldVM_PushIntOperand_structural(argCount, (int *)(argCount + 196), 0);
        }
        goto LABEL_52;
      case 0x3Au:
        argCountb = (_DWORD *)FFX_FieldVM_PopOperand(argCount, v7);
        v68 = FFX_FieldVM_PopOperand(argCount, v7);
        n0xFFFFd = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196));
        n255b_1 = FFX_Field_ResolvePartySlotToActorIndex_structural(v68);
        n255b_3 = n255b_1;
        if ( !argCountb || n255b_1 < 0 )
          goto LABEL_178;
        v70 = FFX_FieldActor_QueuePriorityNodeIfAbsent_wrapper(
                *(unsigned __int16 *)(argCount + 46),
                n255b_1,
                1,
                n0xFFFFd,
                (int)argCountb);
        goto LABEL_177;
      case 0x3Bu:
        argCountb = (_DWORD *)FFX_FieldVM_PopOperand(argCount, v7);
        v72 = FFX_FieldVM_PopOperand(argCount, v7);
        n0xFFFFd = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196));
        n255b_2 = FFX_Field_ResolvePartySlotToActorIndex_structural(v72);
        n255b_3 = n255b_2;
        if ( argCountb && n255b_2 >= 0 )
        {
          v70 = FFX_FieldActor_QueuePriorityNodeIfAbsent_wrapper(
                  *(unsigned __int16 *)(argCount + 46),
                  n255b_2,
                  2,
                  n0xFFFFd,
                  (int)argCountb);
LABEL_177:
          v71 = v70;
        }
        else
        {
LABEL_178:
          v71 = 0;
        }
        FFX_FieldVM_PushIntOperand_structural(argCount, (int *)(argCount + 196), v71);
        if ( v71 )
        {
          *((_WORD *)ScriptWorkerContext_structural + 22) = (_WORD)argCountb;
          *((_WORD *)ScriptWorkerContext_structural + 23) = n255b_3;
          *((_WORD *)ScriptWorkerContext_structural + 24) = n0xFFFFd;
          *((_BYTE *)ScriptWorkerContext_structural + 31) = 1;
        }
        argCounta = 0;
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x800;
        goto LABEL_52;
      case 0x3Cu:
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0xC00;
        argCounta = 0;
        v83 = (void (__cdecl *)(int, int))AtelCurCtrlWork[10];
        v84 = *(unsigned __int16 *)(argCount + 46);
        if ( v83 )
          v83(v84, 60);
        else
          FFX_FieldActor_StopAndUnbindTriggerNode_structural(v84, -1, 0);
        goto LABEL_143;
      case 0x3Du:
        argCounta = 0;
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0xC00;
        v85 = FFX_FieldVM_PopOperand(argCount, v7);
        FFX_FieldActor_StopAndUnbindTriggerNode_structural(*(unsigned __int16 *)(argCount + 46), v85, 0);
        goto LABEL_200;
      case 0x3Eu:
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0xC00;
        argCounta = 0;
        v86 = (void (__cdecl *)(int, int))AtelCurCtrlWork[10];
        v87 = *(unsigned __int16 *)(argCount + 46);
        if ( v86 )
          v86(v87, 62);
        else
          FFX_FieldActor_StopAndUnbindTriggerNode_structural(v87, -1, 1);
        goto LABEL_143;
      case 0x3Fu:
        argCounta = 0;
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0xC00;
        v88 = FFX_FieldVM_PopOperand(argCount, v7);
        FFX_FieldActor_StopAndUnbindTriggerNode_structural(*(unsigned __int16 *)(argCount + 46), v88, 1);
LABEL_200:
        v22 = v122;
        argCounta_2 = 0;
        goto LABEL_145;
      case 0x40u:
        AtelCurCtrlWork = AtelCurCtrlWork;
        argCounta = 0;
        *(_WORD *)(argCount + 52) &= 0xE3FFu;
        v18 = AtelCurCtrlWork + 25;
        n4 = 0;
        break;
      case 0x54u:
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x1000;
        argCounta = 0;
        FFX_FieldActor_StopAndUnbindTriggerNode_structural(*(unsigned __int16 *)(argCount + 46), 0, 0);
        v22 = v122;
        argCounta_2 = 0;
        goto LABEL_145;
      case 0x55u:
        v57 = FFX_FieldVM_PopOperand(argCount, v7);
        v16 = v112;
        ScriptWorkerContext_structural[8] = (_BYTE *)v57;
        goto LABEL_142;
      case 0x56u:
        v58 = FFX_FieldVM_PopOperand(argCount, v7);
        v16 = v112;
        ScriptWorkerContext_structural[8] = (_BYTE *)v58;
LABEL_150:
        if ( ScriptWorkerContext_structural[8] )
          goto LABEL_142;
        goto LABEL_52;
      case 0x57u:
        v59 = FFX_FieldVM_PopOperand(argCount, v7);
        v16 = v112;
        ScriptWorkerContext_structural[8] = (_BYTE *)v59;
LABEL_153:
        if ( ScriptWorkerContext_structural[8] )
          goto LABEL_52;
LABEL_142:
        FFX_Atel_JumpToLabel((_DWORD *)argCount, (int)ScriptWorkerContext_structural, v16);
        goto LABEL_143;
      case 0x59u:
      case 0x5Au:
      case 0x5Bu:
      case 0x5Cu:
        *(_DWORD *)(argCount + 4 * n7 - 284) = FFX_FieldVM_PopOperand(argCount, v7);
        goto LABEL_52;
      case 0x5Du:
      case 0x5Eu:
      case 0x5Fu:
      case 0x60u:
      case 0x61u:
      case 0x62u:
      case 0x63u:
      case 0x64u:
      case 0x65u:
      case 0x66u:
        *(float *)(argCount + 4 * n7 - 284) = FFX_FieldVM_PopFloatOperand_structural(argCount, v7);
        goto LABEL_52;
      case 0x67u:
      case 0x68u:
      case 0x69u:
      case 0x6Au:
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, *(_DWORD *)(argCount + 4 * n7_1 - 340));
        goto LABEL_52;
      case 0x6Bu:
      case 0x6Cu:
      case 0x6Du:
      case 0x6Eu:
      case 0x6Fu:
      case 0x70u:
      case 0x71u:
      case 0x72u:
      case 0x73u:
      case 0x74u:
        FFX_FieldVM_PushFloatOperand_structural(argCount, v7, COERCE_INT(*(float *)(argCount + 4 * n7_1 - 340)));
        goto LABEL_52;
      case 0x75u:
        FFX_FieldVM_PushIntOperand_structural(argCount, v7, FFX_Field_Global_C52704[v16]);
        goto LABEL_52;
      case 0x77u:
        n0xFFFFf = FFX_FieldVM_PopOperand(argCount, v7);
        n255c = FFX_FieldVM_PopOperand(argCount, v7);
        n255c_2 = n255c;
        if ( !FFX_Atel_CanSetActorCtxPair_structural(n255c, n0xFFFFf) )
          goto LABEL_52;
        *((_WORD *)ScriptWorkerContext_structural + 23) = n255c_2;
        *((_WORD *)ScriptWorkerContext_structural + 22) = n0xFFFFf;
        goto LABEL_190;
      case 0x78u:
        n0xFFFFe = FFX_FieldVM_PopOperand(argCount, v7);
        v74 = FFX_FieldVM_PopOperand(argCount, v7);
        n255c_1 = FFX_Field_ResolvePartySlotToActorIndex_structural(v74);
        if ( !FFX_Atel_CanSetActorCtxPair_structural(n255c_1, n0xFFFFe) || n255c_1 < 0 )
          goto LABEL_52;
        *((_WORD *)ScriptWorkerContext_structural + 23) = n255c_1;
        *((_WORD *)ScriptWorkerContext_structural + 22) = n0xFFFFe;
LABEL_190:
        *(_WORD *)(argCount + 52) = *(_WORD *)(argCount + 52) & 0xE3FF | 0x400;
        argCounta = 0;
        *((_BYTE *)ScriptWorkerContext_structural + 31) = 2;
        goto LABEL_52;
      case 0x79u:
        v77 = FFX_FieldVM_PopOperand(argCount, v7);
        v78 = FFX_FieldVM_PopOperand(argCount, v7);
        v79 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196));
        FFX_AtelOp_79_StoreActorWordSlot_structural((unsigned __int8 **)argCount, v79, v78, v77);
        ScriptWorkerContext_structural = ScriptWorkerContext_structural_1;
        goto LABEL_52;
      case 0x7Au:
        v80 = FFX_FieldVM_PopOperand(argCount, v7);
        v81 = FFX_FieldVM_PopOperand(argCount, (int *)(argCount + 196));
        v82 = FFX_FieldVM_ResolveActorSlotIndex(argCount, v81, v80);
        FFX_FieldVM_PushIntOperand_structural(argCount, (int *)(argCount + 196), v82);
        goto LABEL_52;
      default:
        argCounta_2 = argCounta;
        v22 = v122;
        unk_1327098 = 0;
        goto LABEL_145;
    }
    while ( n4 < 4 )
    {
      v103 = *((unsigned __int8 *)v18 + 14);
      if ( *v18 >= 0 && (_BYTE *)v18[2] == ScriptWorkerContext_structural[6] )
      {
        if ( *((_BYTE *)v18 + 15) || v126 == 1 )
        {
          *((_BYTE *)v18 + 15) = 0;
          v107 = *((_BYTE *)v18 + 14);
          v20 = FFX_EventData_PackSignedByteWord(v107 & 0x80, (int)ScriptWorkerContext_structural[6]);
          n7_1 = v107 & 0x7F;
          v16 = (unsigned int)&unk_FFFFFF & v20;
          argCounta_2 = 1;
          v112 = v16;
          n7 = n7_1;
          argCounta = 1;
          if ( n7_1 <= 0x7A )
            goto LABEL_37;
          v22 = v122;
          unk_1327098 = 0;
LABEL_145:
          v103 = -1;
          if ( v126 != 1 )
            goto LABEL_26;
          if ( argCounta_2 )
            v22 |= 0x4000u;
          argCounta_1 = 0;
          argCounta = 0;
          v122 = v22 & 0xC000;
          goto LABEL_27;
        }
        v22 = v122 | 0x8000;
        *((_BYTE *)v18 + 15) = 1;
        v122 |= 0x8000u;
        v126 = 1;
LABEL_144:
        argCounta_2 = argCounta;
        goto LABEL_145;
      }
      ++n4;
      v18 += 4;
    }
LABEL_143:
    v22 = v122;
    goto LABEL_144;
  }
  if ( *v7 )
  {
    v105 = 0;
    goto LABEL_33;
  }
LABEL_206:
  LOWORD(v13) = v105;
LABEL_207:
  n8 = *(unsigned __int8 *)(argCount + 50);
  if ( (unsigned __int8)(**(_BYTE **)argCount - 5) > 1u )
  {
    if ( *(unsigned __int8 *)(argCount + 50) >= 9u )
      n8 = 8;
  }
  else if ( *(unsigned __int8 *)(argCount + 50) >= 2u )
  {
    n8 = 1;
  }
  v90 = 76 * n8;
  if ( v127 )
    ((void (__cdecl *)(int, int))AtelCurCtrlWork[23])(argCount, v90 + argCount + 300);
  *(_WORD *)(argCount + 52) ^= (*(_WORD *)(argCount + 52) ^ (8 * v13)) & 8;
  ReleaseMutex_w(_Jarvis_naming_goal_2026_06_17__proved_navigation_name_from_agg);
  return v122;
}