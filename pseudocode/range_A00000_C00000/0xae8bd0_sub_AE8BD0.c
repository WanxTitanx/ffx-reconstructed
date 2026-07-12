// Function: sub_AE8BD0
// Address: 0xae8bd0
// Size: 0xb4
// Prototype: 

int sub_AE8BD0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CAC898,
    (int)Registry,
    (int)"PAnimationWeightedBlenderController",
    28,
    4,
    (int)dword_CAC618,
    0);
  unk_CAC928 |= 2u;
  dword_CAC898[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationWeightedBlenderController>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAC898, (int)&unk_CAC970);
  Phyre_PObject_SetField68(dword_CAC898, (int)&unk_CAC990);
  Phyre_PObject_SetField6C(dword_CAC898, (int)&unk_CAC9B0);
  unk_CAC928 &= ~2u;
  dword_CAC898[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationWeightedBlenderController>::`vftable';
  return atexit(sub_B00EB0);
}

