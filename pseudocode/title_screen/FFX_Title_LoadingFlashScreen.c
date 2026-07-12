/*
 * Function: FFX_Title_LoadingFlashScreen
 * Address:   0x900F80
 * Prototype: unsigned int __cdecl FFX_Title_LoadingFlashScreen(int n16, int a2, int ha, int a4)
 *
 * Manages loading flash screen state. Tracks up to 16 flash entries
 * in word_18762A0 array.
 *
 * Referenced data:
 *   word_18762A0 - global state array
 */

unsigned int __cdecl FFX_Title_LoadingFlashScreen(int n16, int a2, int ha, int a4)
{
  unsigned int ha_1; // eax

  if ( n16 < 16 )
  {
    if ( a2 != (__int16)word_18762A0[8 * n16 + 1] || (ha_1 = (__int16)word_18762A0[8 * n16 + 2], ha != ha_1) )
    {
      ha_1 = 1;
      word_18762A0[8 * n16] = 1;
      word_18762A0[8 * n16 + 1] = a2;
      word_18762A0[8 * n16 + 2] = ha;
      if ( word_18762A0[8 * n16 + 7] != 1 )
      {
        *(_DWORD *)&word_18762A0[8 * n16 + 4] = 0;
        ha_1 = ((int)((unsigned __int64)(2454267027LL * a4) >> 32) >> 3)
             + ((unsigned int)((unsigned __int64)(2454267027LL * a4) >> 32) >> 31)
             + 2;
        word_18762A0[8 * n16 + 3] = a4;
        word_18762A0[8 * n16 + 6] = ha_1;
      }
    }
  }
  return ha_1;
}
