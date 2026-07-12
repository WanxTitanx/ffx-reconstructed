// Function: sub_AE79F0
// Address: 0xae79f0
// Size: 0xb5
// Prototype: 

int sub_AE79F0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA9810, (int)Registry, (int)"PAnimationSlotArray", 4, 4, (int)GlobalTypeAccessor, 0);
  unk_CA98A0 |= 2u;
  dword_CA9810[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationSlotArray>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA9810, (int)&unk_CA9990);
  Phyre_PObject_SetField68(dword_CA9810, (int)&unk_CA99A0);
  Phyre_PObject_SetField6C(dword_CA9810, (int)&unk_CA99B0);
  unk_CA98A0 &= ~2u;
  dword_CA9810[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationSlotArray>::`vftable';
  return atexit(sub_B00080);
}

