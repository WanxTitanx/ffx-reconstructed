// Function: sub_938570
// Address: 0x938570
int sub_938570()
{
  int result; // eax

  result = FFX_BtlTick_BattleEndCleanupLate();
  if ( result )
    return sub_938590(result);
  return result;
}
