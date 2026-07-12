// Function: sub_8982A0
// Address: 0x8982a0
void sub_8982A0()
{
  int n31; // edi
  int v1; // esi
  int CheckLockConsistency; // eax

  unk_133D114 = 0;
  unk_133D118 = 0;
  unk_133D11C = 0;
  unk_133D12C = 0;
  unk_133D128 = 0;
  n31 = 0;
  v1 = 1;
  do
  {
    if ( (v1 & unk_133D09C) != 0 )
    {
      if ( FFX_BattleTarget_IsTargetable(n31) == 1 )
        unk_133D114 |= v1;
      CheckLockConsistency = FFX_BattleTarget_CheckLockConsistency(n31, n255_3);
      if ( CheckLockConsistency )
      {
        if ( CheckLockConsistency == 1 )
          unk_133D118 |= v1;
      }
      else
      {
        unk_133D11C |= v1;
      }
      if ( !FFX_BattleTarget_GetCurrentRange(n31) )
        unk_133D12C |= v1;
      if ( !FFX_Battle_IsActorStatusStone(n31) )
        unk_133D128 |= v1;
    }
    v1 = __ROL4__(v1, 1);
    ++n31;
  }
  while ( n31 < 28 );
}
