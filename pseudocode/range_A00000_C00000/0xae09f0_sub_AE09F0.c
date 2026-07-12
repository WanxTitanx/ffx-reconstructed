// Function: sub_AE09F0
// Address: 0xae09f0
// Size: 0xbe
// Prototype: 

int sub_AE09F0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C90E30, (int)Registry, (int)"PWorld", 16, 4, (int)GlobalTypeAccessor, 0);
  unk_C90EC0 |= 2u;
  dword_C90E30[0] = &Phyre::PClassDescriptorAbstract<Phyre::PWorld>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C90E30, (int)&unk_C90EF0);
  Phyre_PObject_SetField68(dword_C90E30, (int)&unk_C90F00);
  Phyre_PObject_SetField6C(dword_C90E30, (int)&unk_C90F10);
  dword_C90E30[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PWorld>::`vftable';
  unk_C90EC0 = unk_C90EC0 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFA290);
}

