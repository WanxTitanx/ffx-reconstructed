// Function: sub_AE7B70
// Address: 0xae7b70
// Size: 0xb5
// Prototype: 

int sub_AE7B70()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA99B8,
    (int)Registry,
    (int)"PAnimationChannelTimes",
    12,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CA9A48 |= 2u;
  dword_CA99B8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationChannelTimes>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA99B8, (int)&unk_CA9BD0);
  Phyre_PObject_SetField68(dword_CA99B8, (int)&unk_CA9BE0);
  Phyre_PObject_SetField6C(dword_CA99B8, (int)&unk_CA9BF0);
  unk_CA9A48 &= ~2u;
  dword_CA99B8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationChannelTimes>::`vftable';
  return atexit(sub_B00100);
}

