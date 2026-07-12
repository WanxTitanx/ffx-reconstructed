// Function: sub_AE7C30
// Address: 0xae7c30
// Size: 0xb5
// Prototype: 

int sub_AE7C30()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA9C28,
    (int)Registry,
    (int)"PAnimationChannelTarget",
    28,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CA9CB8 |= 2u;
  dword_CA9C28[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationChannelTarget>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA9C28, (int)&unk_CA9EA0);
  Phyre_PObject_SetField68(dword_CA9C28, (int)&unk_CA9EC0);
  Phyre_PObject_SetField6C(dword_CA9C28, (int)&unk_CA9EE0);
  unk_CA9CB8 &= ~2u;
  dword_CA9C28[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationChannelTarget>::`vftable';
  return atexit(sub_B00190);
}

