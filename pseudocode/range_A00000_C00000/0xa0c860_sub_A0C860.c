// Function: sub_A0C860
// Address: 0xa0c860
// Size: 0xb4
// Prototype: 

int __cdecl sub_A0C860(int a1, int a2)
{
  if ( (dword_19450A4 & 1) == 0 )
  {
    dword_19450A4 |= 1u;
    sub_9F96D0();
    unk_19450A0 &= ~2u;
    Size_5[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PPostProcessing::PPostEffectBase *,4>>::`vftable';
    atexit(sub_B08DA0);
  }
  if ( a2 )
    return PhyreLua_PushPhyreObject(a1, a2, (int)Size_5);
  sub_94AC00(a1, 1);
  return LuaStack_PushSlot(a1);
}

