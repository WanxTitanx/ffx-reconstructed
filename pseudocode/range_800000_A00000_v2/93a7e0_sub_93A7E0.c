// Function: sub_93A7E0
// Address: 0x93a7e0
int sub_93A7E0()
{
  int v0; // eax
  unsigned int v2; // [esp-4h] [ebp-4h]

  v2 = ((unsigned int)sub_908F10() >> 12) & 1;
  v0 = FFX_BtlTick_BattleEndCleanupLate();
  return sub_93A800(v0, v2);
}
