// Function: sub_AE8B20
// Address: 0xae8b20
// Size: 0xa3
// Prototype: 

int sub_AE8B20()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CAC618,
    (int)Registry,
    (int)"PAnimationBlenderController",
    20,
    16,
    (int)dword_CABD28,
    0);
  unk_CAC6A8 |= 2u;
  dword_CAC618[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationBlenderController>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAC618, (int)&unk_CAC6F0);
  Phyre_PObject_SetField68(dword_CAC618, (int)&unk_CAC710);
  Phyre_PObject_SetField6C(dword_CAC618, (int)&unk_CAC730);
  return atexit(sub_B00E30);
}

