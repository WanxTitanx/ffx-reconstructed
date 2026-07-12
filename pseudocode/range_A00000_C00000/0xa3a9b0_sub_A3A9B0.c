// Function: sub_A3A9B0
// Address: 0xa3a9b0
// Size: 0x39

_DWORD *__stdcall sub_A3A9B0(const void *src)
{
  _DWORD *result; // eax
  _DWORD *dst; // edi

  result = dword_1A858B4; /*0xa3a9b3*/
  if ( src ) /*0xa3a9be*/
  {
    dst = dword_1A858B4 + 467; /*0xa3a9cc*/
    dword_1A858B4[479] = 1; /*0xa3a9d7*/
    qmemcpy(dst, src, 0x30u); /*0xa3a9e1*/
  }
  else
  {
    dword_1A858B4[479] = 0; /*0xa3a9c0*/
  }
  return result; /*0xa3a9c6*/
}