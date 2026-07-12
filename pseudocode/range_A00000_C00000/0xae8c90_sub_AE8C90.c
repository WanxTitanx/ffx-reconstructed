// Function: sub_AE8C90
// Address: 0xae8c90
// Size: 0xb4
// Prototype: 

int sub_AE8C90()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CAC9D0,
    (int)Registry,
    (int)"PAnimationAdditiveBlenderController",
    28,
    4,
    (int)dword_CAC618,
    0);
  unk_CACA60 |= 2u;
  dword_CAC9D0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationAdditiveBlenderController>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAC9D0, (int)&unk_CACAA0);
  Phyre_PObject_SetField68(dword_CAC9D0, (int)&unk_CACAC0);
  Phyre_PObject_SetField6C(dword_CAC9D0, (int)&unk_CACAE0);
  unk_CACA60 &= ~2u;
  dword_CAC9D0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationAdditiveBlenderController>::`vftable';
  return atexit(sub_B00EE0);
}

