// Function: sub_808BD0
// Address: 0x808bd0
int sub_808BD0()
{
  int n422; // eax

  if ( FFX_Btl_GetCurrentBattleFormationId() == 283 )
    return sub_644DF0(0, 1);
  n422 = FFX_Btl_GetCurrentBattleFormationId();
  if ( n422 == 422 )
    return sub_644DF0(0, 1);
  return n422;
}
