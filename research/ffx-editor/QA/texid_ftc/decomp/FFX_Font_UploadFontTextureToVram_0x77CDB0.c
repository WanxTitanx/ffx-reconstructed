// FFX Font: Upload font texture to VRAM
int __cdecl FFX_Font_UploadFontTextureToVram(int a1, int a2, int a3, int n2, int a5)
{
  int n2_1; // esi
  int v6; // edi
  int n2_2; // eax
  _DWORD v8[2]; // [esp+8h] [ebp-8h]

  n2_1 = n2; /*0x77cdbb*/
  v6 = n2 + 1024; /*0x77cdbf*/
  v8[0] = 416; /*0x77cdc5*/
  v8[1] = 0; /*0x77cdcc*/
  if ( a5 ) /*0x77cdd3*/
  {
    n2 = 0; /*0x77ce2d*/
    do /*0x77ce7d*/
    {
      FFX_Virtuos_MovieNotImplemented_make_yi_font16(); /*0x77ce36*/
      FFX_GsKit_UploadTextureToVram(v6, n2_1, a1, a2 + v8[n2], 16, 16, 512, 0, 0, 0, 0); /*0x77ce5c*/
      FFX_Movie_SignalRenderComplete(v6); /*0x77ce62*/
      FFX_GenericStub_Return0(); /*0x77ce6b*/
      n2_2 = n2 + 1; /*0x77ce73*/
      n2 = n2_2; /*0x77ce77*/
    }
    while ( n2_2 < 2 ); /*0x77ce7d*/
  }
  else
  {
    FFX_Magic_GetRuntimeScratchBase_structural(&n2); /*0x77cdd9*/
    n2 &= 1u; /*0x77cde1*/
    FFX_Virtuos_MovieNotImplemented_make_yi_font16(); /*0x77cde6*/
    FFX_GsKit_UploadTextureToVram(v6, n2_1, a1, a2 + v8[n2], 16, 16, 512, 0, 0, 0, 0); /*0x77ce0c*/
    FFX_Movie_SignalRenderComplete(v6); /*0x77ce12*/
    return FFX_GenericStub_Return0(); /*0x77ce1b*/
  }
  return n2_2; /*0x77ce23*/
}