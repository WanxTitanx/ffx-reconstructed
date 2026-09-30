// FFX Font: Upload slots to VRAM
int __usercall FFX_Font_UploadSlotsToVram@<eax>(int a1@<ebp>)
{
  int CurrentTextSlot; // esi
  int v2; // ecx
  int result; // eax

  CurrentTextSlot = FFX_Font_GetCurrentTextSlot(); /*0x8b1146*/
  if ( FFX_Locale_GetCurrentId(v2) ) /*0x8b1148*/
  {
    FFX_Menu_ItemListScroll( /*0x8b11c6*/
      a1,
      *((_DWORD *)&unk_1841D60 + 4 * CurrentTextSlot),
      15360,
      20,
      0,
      0,
      *((__int16 *)&unk_1841D6C + 8 * CurrentTextSlot),
      *((__int16 *)&unk_1841D6E + 8 * CurrentTextSlot));
  }
  else
  {
    FFX_Menu_ItemListScroll(a1, unk_1841D60, 15360, 20, 0, 0, unk_1841D6C, unk_1841D6E); /*0x8b1172*/
    FFX_Menu_ItemListScroll(a1, unk_1841DA0, 15680, 20, 0, 0, unk_1841DAC, unk_1841DAE); /*0x8b1198*/
  }
  if ( FFX_Font_GetAreaFtc() ) /*0x8b11ce*/
    FFX_Menu_ItemListScroll(a1, unk_1841D90, 15616, 20, 0, 0, unk_1841D9C, unk_1841D9E); /*0x8b11f9*/
  FFX_Menu_ItemListScroll(a1, unk_1841D54, 15744, 20, 0, 0, 128, 256); /*0x8b121c*/
  FFX_Menu_ItemListScroll(a1, unk_1841D58, 15808, 20, 0, 0, 256, 128); /*0x8b123c*/
  FFX_Menu_ItemListScroll(a1, unk_1841D5C, 16128, 20, 0, 0, 512, 128); /*0x8b125c*/
  result = FFX_Font_IsVramSlotReady(); /*0x8b1264*/
  if ( !result ) /*0x8b126b*/
  {
    FFX_Menu_ItemListScroll(a1, unk_1841DC0, 15872, 19, 0, 0, 256, 256); /*0x8b1286*/
    return FFX_Menu_ItemListScroll(a1, unk_1841DC8, 11936, 0, 0, 0, 64, 64); /*0x8b12a0*/
  }
  return result; /*0x8b12a8*/
}