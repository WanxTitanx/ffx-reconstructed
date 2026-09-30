// FFX MagicHost: Keyhole texture init
void FFX_MagicHost_KeyholeTexture_Init()
{
  void *blob; // edx
  FFXMagicHost *host; // ecx

  unk_1A85F70 = 0; /*0xa54762*/
  FFX_Magic_SetSlotVisibilityFlag(0); /*0xa5476c*/
  FFX_Magic_SetKeyholeFlag_structural(0); /*0xa54773*/
  if ( !unk_1A85F64 ) /*0xa54782*/
  {
    unk_1A85F64 = 1; /*0xa54789*/
    if ( !*(_BYTE *)MEMORY[0x2305800] ) /*0xa54793*/
    {
      host = 0; /*0xa54798*/
      *((_WORD *)MEMORY[0x2305800] + 2) = 0; /*0xa5479a*/
      *((_WORD *)MEMORY[0x2305800] + 4) = 0; /*0xa547a3*/
      *((_WORD *)MEMORY[0x2305800] + 3) = 0; /*0xa547ac*/
      *((_WORD *)MEMORY[0x2305800] + 5) = 0; /*0xa547b5*/
      *((_WORD *)MEMORY[0x2305800] + 6) = 0; /*0xa547be*/
    }
    // "pppKeThRes48"
    FFX_MagicHost_RelocatePppResourceBlob(host, blob); /*0xa547cf*/
  }
}