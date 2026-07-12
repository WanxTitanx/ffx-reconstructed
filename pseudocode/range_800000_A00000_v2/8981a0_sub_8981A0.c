// Function: sub_8981A0
// Address: 0x8981a0
int sub_8981A0()
{
  int result; // eax

  FFX_BtlHud_SubmenuStateClear();
  result = FFX_BtlHud_GetAnimTimingWord(2, "dum225", word_133F738);
  unk_133C8FF = 0;
  return result;
}
