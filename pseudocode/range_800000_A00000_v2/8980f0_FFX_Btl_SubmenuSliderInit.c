// Function: FFX_Btl_SubmenuSliderInit
// Address: 0x8980f0
int FFX_Btl_SubmenuSliderInit()
{
  FFX_BtlHud_GetAnimTimingWord(2, "dum225", word_133F738);
  FFX_BtlHud_SubmenuStateClear();
  FFX_BtlHud_ShimmerResetAll();
  *(_DWORD *)n9_0 = 0;
  unk_133D6F8 = 0;
  MEMORY[0x133D6FC] = 0;
  unk_133D700 = 0;
  *(_DWORD *)&word_133D704 = 0;
  unk_133D708 = 0;
  n9_0[1] = (int)FFX_Menu2D_ScaleX_1920to512(446.0);
  unk_133D6F8 = (int)FFX_Menu2D_ScaleY_1080to416(511.0);
  unk_133D6FA = (int)FFX_Menu2D_ScaleX_1920to512(1032.0);
  return FFX_BtlHud_GetAnimDataDword(2, "dum203", &unk_133D708);
}
