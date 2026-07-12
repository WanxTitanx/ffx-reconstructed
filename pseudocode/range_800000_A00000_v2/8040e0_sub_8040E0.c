// Function: sub_8040E0
// Address: 0x8040e0
int __cdecl sub_8040E0(int a1)
{
  int CurrentBattleFormationId; // eax

  CurrentBattleFormationId = FFX_Btl_GetCurrentBattleFormationId();
  if ( CurrentBattleFormationId == ::CurrentBattleFormationId )
  {
    *(_WORD *)(a1 + 29) = -32640;
    *(_BYTE *)(a1 + 28) = 0x80;
  }
  if ( CurrentBattleFormationId == CurrentBattleFormationId_0 )
  {
    *(_WORD *)(a1 + 29) = -32640;
    *(_BYTE *)(a1 + 28) = 0x80;
  }
  if ( CurrentBattleFormationId == CurrentBattleFormationId_1 )
  {
    *(_WORD *)(a1 + 29) = -32640;
    *(_BYTE *)(a1 + 28) = 0x80;
  }
  if ( CurrentBattleFormationId == CurrentBattleFormationId_2 )
  {
    *(_WORD *)(a1 + 29) = -32640;
    *(_BYTE *)(a1 + 28) = 0x80;
  }
  if ( CurrentBattleFormationId == CurrentBattleFormationId_3 )
  {
    *(_WORD *)(a1 + 29) = -32640;
    *(_BYTE *)(a1 + 28) = 0x80;
  }
  if ( CurrentBattleFormationId == CurrentBattleFormationId_4 )
  {
    *(_WORD *)(a1 + 29) = -32640;
    *(_BYTE *)(a1 + 28) = 0x80;
  }
  if ( CurrentBattleFormationId == CurrentBattleFormationId_5 )
  {
    *(_WORD *)(a1 + 29) = -32640;
    *(_BYTE *)(a1 + 28) = 0x80;
  }
  if ( (unsigned int)(CurrentBattleFormationId - 622) <= 7 )
  {
    *(_WORD *)(a1 + 29) = -32640;
    *(_BYTE *)(a1 + 28) = 0x80;
  }
  return 0;
}
