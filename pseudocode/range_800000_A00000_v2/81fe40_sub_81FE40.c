// Function: sub_81FE40
// Address: 0x81fe40
int sub_81FE40()
{
  int CurrentBattleFormationId; // edi
  int CurrentModuleId; // esi
  int IsProcessingSafe; // ebx
  int v3; // eax
  int GlobalModeId_1; // ecx
  __int16 n1470; // ax
  int v7; // ecx
  bool v8; // zf
  int v9; // [esp+Ch] [ebp-14h]
  int n2; // [esp+10h] [ebp-10h]
  int v11; // [esp+14h] [ebp-Ch]
  int v12; // [esp+18h] [ebp-8h]
  int GlobalModeId; // [esp+1Ch] [ebp-4h]

  CurrentBattleFormationId = FFX_Btl_GetCurrentBattleFormationId();
  CurrentModuleId = FFX_Sys_GetCurrentModuleId();
  GlobalModeId = FFX_Btl_GetGlobalModeId();
  IsProcessingSafe = FFX_Btl_IsProcessingSafe();
  v11 = sub_641EA0();
  if ( sub_76F0D0() || (v12 = 0, unk_112A00C) )
    v12 = 1;
  v9 = sub_8224F0();
  ((void (*)(void))sub_787400)();
  n2 = sub_86C840();
  LOBYTE(v3) = __uncaught_exception();
  if ( v3 )
    return 1;
  if ( (!v11 || v12)
    && (CurrentBattleFormationId != 330 && CurrentBattleFormationId != 332 && CurrentBattleFormationId != 381
     || n113 != 208)
    && CurrentBattleFormationId != 306
    && CurrentBattleFormationId != 169
    && CurrentBattleFormationId != 437
    && CurrentBattleFormationId != 438
    && CurrentBattleFormationId != 205 )
  {
    if ( n113 == 164 )
    {
      GlobalModeId_1 = GlobalModeId;
      if ( CurrentModuleId != 7382 )
        goto LABEL_32;
      n1470 = 1470;
    }
    else
    {
      if ( n113 == 95 || n113 == 120 || n113 == 127 )
      {
        GlobalModeId_1 = GlobalModeId;
        if ( !IsProcessingSafe && (_WORD)GlobalModeId == 734 )
          return 0;
      }
      else
      {
        GlobalModeId_1 = GlobalModeId;
      }
      if ( n113 != 59 || CurrentModuleId != 1389 || IsProcessingSafe )
        goto LABEL_32;
      n1470 = 777;
    }
    if ( (_WORD)GlobalModeId_1 == n1470 )
      return 0;
LABEL_32:
    if ( unk_13407E4 )
      return 0;
    if ( CurrentModuleId == 9465 )
    {
      if ( (sub_787400(GlobalModeId_1) & 4) != 0 && (sub_787400(v7) & 0x80u) == 0 )
        return 0;
    }
    else if ( CurrentModuleId == 6991 )
    {
      if ( n2 == 2 )
      {
        v8 = IsProcessingSafe == 0;
        goto LABEL_49;
      }
    }
    else if ( CurrentModuleId == 1972 && (_WORD)GlobalModeId_1 == 3135 )
    {
      v8 = IsProcessingSafe == 0;
      goto LABEL_49;
    }
    if ( !IsProcessingSafe && CurrentModuleId == 7321 )
      return 0;
    if ( CurrentModuleId == 458 )
    {
      v8 = (_WORD)GlobalModeId == 2920;
    }
    else
    {
      if ( CurrentModuleId != 1761 || !IsProcessingSafe )
        return (!v9
             || CurrentModuleId != 7044
             && CurrentModuleId != 503
             && CurrentModuleId != 6297
             && CurrentModuleId != 7457
             && CurrentModuleId != 3076
             && CurrentModuleId != 7752
             && CurrentModuleId != 2990
             && CurrentModuleId != 7237)
            && !unk_12F2064
            && !unk_12F2068
            && !unk_12F206C;
      v8 = CurrentBattleFormationId == -1;
    }
LABEL_49:
    if ( v8 )
      return 0;
    return (!v9
         || CurrentModuleId != 7044
         && CurrentModuleId != 503
         && CurrentModuleId != 6297
         && CurrentModuleId != 7457
         && CurrentModuleId != 3076
         && CurrentModuleId != 7752
         && CurrentModuleId != 2990
         && CurrentModuleId != 7237)
        && !unk_12F2064
        && !unk_12F2068
        && !unk_12F206C;
  }
  return 0;
}
