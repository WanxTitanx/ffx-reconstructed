// Function: sub_AE7E70
// Address: 0xae7e70
// Size: 0xb4
// Prototype: 

int sub_AE7E70()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CAA298,
    (int)Registry,
    (int)"PAnimationConstantChannel",
    52,
    4,
    (int)dword_CA9F30,
    0);
  unk_CAA328 |= 2u;
  dword_CAA298[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationConstantChannel>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAA298, (int)&unk_CAA370);
  Phyre_PObject_SetField68(dword_CAA298, (int)&unk_CAA3B0);
  Phyre_PObject_SetField6C(dword_CAA298, (int)&unk_CAA3F0);
  unk_CAA328 &= ~2u;
  dword_CAA298[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationConstantChannel>::`vftable';
  return atexit(sub_B003B0);
}

