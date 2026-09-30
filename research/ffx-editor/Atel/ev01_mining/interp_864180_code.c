// Jarvis-HEAVY H09: ATEL VM interpreter. Fetches opcode via 0x869D00, strips operand flag, dispatches cases 0..0x7A; CALL/CALLPOPA cases 0x35/0x58 route native call IDs through namespace dispatchers.
// FFX: Field event parser structural — ATEL VM interpreter main loop (4KB, 123-case switch, fetches opcodes via 0x869D00)
// FFX Field: Event parser (ATEL VM interpreter, 123-case switch)
// ATEL VM interpreter main loop. 4208 bytes, 224 basic blocks, 123-case switch (0x00-0x7A). Fetches opcodes via FFX_Atel_FetchOpcode(0x869D00), strips operand flag, dispatches to FFX_AtelOp_* handler functions. Opcodes: NCJMP, JSR, RTS, CALL, REQ, RET, HALT, PUSHN, PUSHT, PUSHVP, PUSHFIX, POPI0-3, POPF0-9, PUSHI0-3, PUSHF0-9, PUSHAINTER, ER, AIT, SYSTEM.
// ATEL VM interpreter. Fetches opcode via FFX_Atel_FetchOpcode(0x869D00), strips operand flag, dispatches cases 0..0x7A (123 cases). Each case calls individual FFX_AtelOp_* handler. 224 basic blocks, cyclomatic complexity 156.
// ARBITRATED 2026-09-14 (MICRO-FIXES/F1a): BATTLE uses this SAME interpreter via wrapper FFX_Atel_ParseEventWithFlag1@0x864160 (5 battle callers: 0x7972F0 camera, 0x797360 ch2 tick, 0x7973C0 actor priorities, 0x7979E0/0x797D60 btl UI menu tree). Direct xrefs stay field-only (0x864160/0x867740/0x8678F0 x2/0x868380). Resolves F24: 'same VM battle+field' is proven, one hop deeper than the direct xrefs.
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
  argCountc = *(float *)(argCount + 148) * unk_1326B98; /*0x86421d*/
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
    unk_1327098 = 0; /*0x86434e*/
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
    v16 = (unsigned int)&unk_FFFFFF & v14; /*0x864395*/
    v112 = (unsigned int)&unk_FFFFFF & v14; /*0x86439e*/
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
          unk_1327098 = 0; /*0x864c09*/
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
          unk_1327098 = 0; /*0x864c68*/
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
        unk_1327098 = 0; /*0x865150*/
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
          v16 = (unsigned int)&unk_FFFFFF & v20; /*0x86443a*/
          argCounta_2 = 1; /*0x864443*/
          v112 = v16; /*0x864448*/
          n7 = n7_1; /*0x86444b*/
          argCounta = 1; /*0x86444e*/
          if ( n7_1 <= 0x7A ) /*0x864454*/
            goto LABEL_37; /*0x864454*/
          v22 = v122; /*0x86445a*/
          unk_1327098 = 0; /*0x86445d*/
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