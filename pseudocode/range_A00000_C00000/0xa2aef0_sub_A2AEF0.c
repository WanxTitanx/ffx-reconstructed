// Function: sub_A2AEF0
// Address: 0xa2aef0
// Size: 0x82

int sub_A2AEF0()
{
  if ( (dword_1A85144 & 1) == 0 ) /*0xa2af19*/
  {
    dword_1A85144 |= 1u; /*0xa2af1e*/
    sub_A2B780(); /*0xa2af2f*/
    unk_1A85140 &= ~2u; /*0xa2af34*/
    dword_1A850B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PText::PBitmapFontCharInfo,4>>::`vftable'; /*0xa2af40*/
    atexit(sub_B090E0); /*0xa2af4a*/
  }
  return Phyre_PObject_ComputeLayout(dword_1A850B0); /*0xa2af6e*/
}