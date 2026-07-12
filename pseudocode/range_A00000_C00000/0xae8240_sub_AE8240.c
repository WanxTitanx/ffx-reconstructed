// Function: sub_AE8240
// Address: 0xae8240
// Size: 0xb5
// Prototype: 

int sub_AE8240()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CAAEA8, (int)Registry, (int)"PAnimationSet", 24, 4, (int)GlobalTypeAccessor, 0);
  unk_CAAF38 |= 2u;
  dword_CAAEA8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationSet>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAAEA8, (int)&unk_CAB3E0);
  Phyre_PObject_SetField68(dword_CAAEA8, (int)&unk_CAB400);
  Phyre_PObject_SetField6C(dword_CAAEA8, (int)&unk_CAB420);
  unk_CAAF38 &= ~2u;
  dword_CAAEA8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationSet>::`vftable';
  return atexit(sub_B00860);
}

