// Function: sub_A0D750
// Address: 0xa0d750
// Size: 0x8b
// Prototype: 

int __cdecl sub_A0D750(int a1, int a2)
{
  if ( (dword_19450A4 & 1) == 0 )
  {
    dword_19450A4 |= 1u;
    sub_9F96D0();
    unk_19450A0 &= ~2u;
    Size_5[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PPostProcessing::PPostEffectBase *,4>>::`vftable';
    atexit(sub_B08DA0);
  }
  return PhyreLua_PushPhyreObject(a1, a2, (int)Size_5);
}

