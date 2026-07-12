// Function: FFX_Btl_SubmenuInitTargeting
// Address: 0x8978e0
_WORD *FFX_Btl_SubmenuInitTargeting()
{
  _WORD *result; // eax

  FFX_BtlHud_GetAnimTimingWord(2, "dum225", word_133F738);
  FFX_BtlHud_SubmenuStateClear();
  FFX_BtlHud_ShimmerResetAll();
  *(_DWORD *)&byte_133D6B2[2] = 0;
  dword_133D6B8 = 0;
  *(_DWORD *)unk_133D6BC = 0;
  unk_133D6C0 = 0;
  unk_133D6C4 = 0;
  result = FFX_BtlHud_GetAnimTiming(2, (int)"dum217", &unk_133D6B6, &dword_133D6B8);
  *(_DWORD *)((char *)&dword_133D6B8 + 2) = 4;
  return result;
}
