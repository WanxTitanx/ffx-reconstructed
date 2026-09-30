// FFX Menu: Item list refresh
int FFX_Font_RefreshVramAtlases()
{
  int CurrentTextSlot; // eax
  FFXBattleState *v2; // ecx
  int v3; // ecx
  int v4; // eax

  CurrentTextSlot = FFX_Font_GetCurrentTextSlot(); /*0x8b0fd0*/
  FFX_GS_BuildTexUploadPacket_Stubbed( /*0x8b0ff9*/
    *((_DWORD *)&g_FTCFontSlotTable + 4 * CurrentTextSlot),
    15360,
    20,
    0,
    0,
    *((__int16 *)&unk_1841D6C + 8 * CurrentTextSlot),
    *((__int16 *)&unk_1841D6E + 8 * CurrentTextSlot));
  if ( FFX_Battle_QueueGateCheck(v2) ) /*0x8b1001*/
  {
    if ( FFX_Menu_GetItemListCachePtr() ) /*0x8b100a*/
      FFX_GS_BuildTexUploadPacket_Stubbed(unk_1841D80, 15616, 20, 0, 0, unk_1841D8C, unk_1841D8E); /*0x8b1034*/
    if ( !FFX_Locale_GetCurrentId(v3) ) /*0x8b103c*/
      FFX_GS_BuildTexUploadPacket_Stubbed(unk_1841DA0, 15680, 20, 0, 0, unk_1841DAC, unk_1841DAE); /*0x8b1066*/
  }
  else if ( FFX_Field_GetAreaFaction() ) /*0x8b1068*/
  {
    FFX_GS_BuildTexUploadPacket_Stubbed(unk_1841D70, 15616, 20, 0, 0, unk_1841D7C, unk_1841D7E); /*0x8b1092*/
  }
  FFX_GS_BuildTexUploadPacket_Stubbed(unk_1841D54, 15744, 20, 0, 0, 128, 256); /*0x8b10b5*/
  FFX_GS_BuildTexUploadPacket_Stubbed(unk_1841D58, 15808, 20, 0, 0, 256, 128); /*0x8b10d5*/
  FFX_GS_BuildTexUploadPacket_Stubbed(unk_1841DC0, 15872, 19, 0, 0, 256, 256); /*0x8b10f5*/
  v4 = FFX_Menu_TooltipDraw(); /*0x8b1112*/
  FFX_GS_BuildTexUploadPacket_Stubbed(v4, 16128, 19, 0, 0, 256, 256); /*0x8b1118*/
  return FFX_GS_BuildTexUploadPacket_Stubbed(unk_1841DC8, 11936, 0, 0, 0, 64, 64); /*0x8b113a*/
}
