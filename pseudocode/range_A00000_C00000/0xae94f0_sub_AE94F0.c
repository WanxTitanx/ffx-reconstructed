// Function: sub_AE94F0
// Address: 0xae94f0
// Size: 0xb5
// Prototype: 

int sub_AE94F0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CAED58, (int)Registry, (int)"PTrigger", 68, 4, (int)GlobalTypeAccessor, 0);
  unk_CAEDE8 |= 2u;
  dword_CAED58[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGameplay::PTrigger>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAED58, (int)&unk_CAF0C0);
  Phyre_PObject_SetField68(dword_CAED58, (int)&unk_CAF110);
  Phyre_PObject_SetField6C(dword_CAED58, (int)&unk_CAF160);
  unk_CAEDE8 &= ~2u;
  dword_CAED58[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGameplay::PTrigger>::`vftable';
  return atexit(sub_B01E20);
}

