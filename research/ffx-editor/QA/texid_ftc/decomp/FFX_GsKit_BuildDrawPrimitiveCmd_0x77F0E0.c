// FFX GsKit: Build draw primitive command
_DWORD *__cdecl FFX_GsKit_BuildDrawPrimitiveCmd(
        _DWORD *a1,
        int a2,
        int a3,
        int a4,
        int n16,
        int n16_1,
        int a7,
        int SlotWord)
{
  int v8; // edx

  *a1 = 268435462; /*0x77f0ee*/
  a1[1] = 0; /*0x77f0f6*/
  a1[2] = 0; /*0x77f0fc*/
  a1[3] = 0; /*0x77f105*/
  a1[4] = 0; /*0x77f10e*/
  a1[5] = 0; /*0x77f115*/
  a1[6] = 0; /*0x77f11e*/
  a1[7] = 1342177285; /*0x77f127*/
  FFX_GsKit_BuildPrimitiveGifTag(a1 + 8, 14, 0, 1, 0, 0, 0, 1, 4); /*0x77f134*/
  FFX_GsKit_BuildTexFlushGifTag( /*0x77f15d*/
    a1 + 12,
    SlotWord,
    (int)(((((a7 + 63) >> 31) & 0x3F) + a7 + 63) & 0xFFFFFFC0) / 64,
    19,
    0);
  FFX_GsKit_BuildGifTagClut(a1 + 16, n16, n16_1); /*0x77f16d*/
  FFX_GsKit_BuildTexCoordGifTag(a1 + 20, 0, a3, a4); /*0x77f181*/
  FFX_GsKit_BuildGifTagDefault(a1 + 24, 0); /*0x77f18c*/
  a1[28] = (n16_1 * v8 / 16 + 2) | 0x30000000; /*0x77f1a8*/
  a1[29] = a2 & 0x7FFFFFFF; /*0x77f1b6*/
  a1[30] = 0; /*0x77f1b9*/
  a1[31] = 0; /*0x77f1c0*/
  return a1 + 32; /*0x77f1ca*/
}
