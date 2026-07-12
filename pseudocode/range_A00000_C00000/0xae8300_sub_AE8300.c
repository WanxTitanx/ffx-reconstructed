// Function: sub_AE8300
// Address: 0xae8300
// Size: 0xb5
// Prototype: 

int sub_AE8300()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CAB4E8, (int)Registry, (int)"PAnimationEvent", 8, 4, (int)GlobalTypeAccessor, 0);
  unk_CAB578 |= 2u;
  dword_CAB4E8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationEvent>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAB4E8, (int)&unk_CAB7D0);
  Phyre_PObject_SetField68(dword_CAB4E8, (int)&unk_CAB7E0);
  Phyre_PObject_SetField6C(dword_CAB4E8, (int)&unk_CAB7F0);
  unk_CAB578 &= ~2u;
  dword_CAB4E8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationEvent>::`vftable';
  return atexit(sub_B00A60);
}

