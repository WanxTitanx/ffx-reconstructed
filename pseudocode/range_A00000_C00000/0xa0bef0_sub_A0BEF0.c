// Function: sub_A0BEF0
// Address: 0xa0bef0
// Size: 0x76

_DWORD *sub_A0BEF0()
{
  if ( (dword_19450A4 & 1) == 0 ) /*0xa0bf19*/
  {
    dword_19450A4 |= 1u; /*0xa0bf1e*/
    sub_9F96D0(); /*0xa0bf2f*/
    unk_19450A0 &= ~2u; /*0xa0bf34*/
    Size_12[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PPostProcessing::PPostEffectBase *,4>>::`vftable'; /*0xa0bf40*/
    atexit(sub_B08DA0); /*0xa0bf4a*/
  }
  return Size_12; /*0xa0bf62*/
}