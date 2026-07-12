// Function: sub_A2AE60
// Address: 0xa2ae60
// Size: 0x76

_DWORD *sub_A2AE60()
{
  if ( (dword_1A85144 & 1) == 0 ) /*0xa2ae89*/
  {
    dword_1A85144 |= 1u; /*0xa2ae8e*/
    sub_A2B780(); /*0xa2ae9f*/
    unk_1A85140 &= ~2u; /*0xa2aea4*/
    dword_1A850B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PText::PBitmapFontCharInfo,4>>::`vftable'; /*0xa2aeb0*/
    atexit(sub_B090E0); /*0xa2aeba*/
  }
  return dword_1A850B0; /*0xa2aed2*/
}