// Function: sub_AE7CF0
// Address: 0xae7cf0
// Size: 0xb4
// Prototype: 

int sub_AE7CF0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA9F30, (int)Registry, (int)"PAnimationChannelBase", 36, 4, (int)dword_CA9C28, 0);
  unk_CA9FC0 |= 2u;
  dword_CA9F30[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationChannelBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA9F30, (int)&unk_CAA030);
  Phyre_PObject_SetField68(dword_CA9F30, (int)&unk_CAA060);
  Phyre_PObject_SetField6C(dword_CA9F30, (int)&unk_CAA090);
  unk_CA9FC0 &= ~2u;
  dword_CA9F30[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationChannelBase>::`vftable';
  return atexit(sub_B00320);
}

