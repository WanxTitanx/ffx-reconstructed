// Function: sub_A0BE60
// Address: 0xa0be60
// Size: 0x76

_DWORD *sub_A0BE60()
{
  if ( (dword_19450A4 & 1) == 0 ) /*0xa0be89*/
  {
    dword_19450A4 |= 1u; /*0xa0be8e*/
    sub_9F96D0(); /*0xa0be9f*/
    unk_19450A0 &= ~2u; /*0xa0bea4*/
    Size_12[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PPostProcessing::PPostEffectBase *,4>>::`vftable'; /*0xa0beb0*/
    atexit(sub_B08DA0); /*0xa0beba*/
  }
  return Size_12; /*0xa0bed2*/
}