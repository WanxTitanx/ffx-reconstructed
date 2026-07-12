// Function: sub_A0C6F0
// Address: 0xa0c6f0
// Size: 0x76
// Prototype: 

_DWORD *sub_A0C6F0()
{
  if ( (dword_19450A4 & 1) == 0 )
  {
    dword_19450A4 |= 1u;
    sub_9F96D0();
    unk_19450A0 &= ~2u;
    Size_5[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PPostProcessing::PPostEffectBase *,4>>::`vftable';
    atexit(sub_B08DA0);
  }
  return Size_5;
}

