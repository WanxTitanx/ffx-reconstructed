// Function: sub_804070
// Address: 0x804070
int sub_804070()
{
  int CurrentBattleFormationId; // eax
  int v1; // ecx

  CurrentBattleFormationId = FFX_Btl_GetCurrentBattleFormationId();
  if ( CurrentBattleFormationId == 640
    || CurrentBattleFormationId == 485
    || CurrentBattleFormationId == 710
    || CurrentBattleFormationId == 592
    || (unsigned int)(CurrentBattleFormationId - 630) <= 7 )
  {
    return 0;
  }
  v1 = 0;
  while ( CurrentBattleFormationId != word_B587E0[v1] )
  {
    if ( (unsigned int)++v1 >= 9 )
      return 1;
  }
  return 3;
}
