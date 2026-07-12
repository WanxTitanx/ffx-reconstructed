// Function: FFX_Btl_SubmenuCursorInit
// Address: 0x897ee0
_WORD *FFX_Btl_SubmenuCursorInit()
{
  FFX_BtlHud_GetAnimTimingWord(2, "dum225", word_133F738);
  FFX_BtlHud_SubmenuStateClear();
  FFX_BtlHud_ShimmerResetAll();
  memset(&n7_5, 0, 0x2Cu);
  n7_5 = 0;
  FFX_BtlHud_GetAnimTiming(2, (int)"dum209", &unk_133D6CA, &unk_133D6CC);
  MEMORY[0x133D6CE] = 192;
  FFX_BtlHud_GetAnimDataDword(2, "dum210", &unk_133D6D0);
  FFX_BtlHud_GetAnimDataDword(2, "dum211", &unk_133D6D4);
  return FFX_BtlHud_GetAnimTiming(2, (int)"dum212", &unk_133D6D8, &unk_133D6DA);
}
