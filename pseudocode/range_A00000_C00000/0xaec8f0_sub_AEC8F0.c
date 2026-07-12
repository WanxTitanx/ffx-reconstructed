// Function: sub_AEC8F0
// Address: 0xaec8f0
// Size: 0xb5
// Prototype: 

int sub_AEC8F0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBE410, (int)Registry, (int)"PScript", 40, 4, (int)GlobalTypeAccessor, 0);
  unk_CBE4A0 |= 2u;
  dword_CBE410[0] = &Phyre::PClassDescriptorAbstract<Phyre::PScripting::PScript>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBE410, (int)&unk_CBE620);
  Phyre_PObject_SetField68(dword_CBE410, (int)&unk_CBE650);
  Phyre_PObject_SetField6C(dword_CBE410, (int)&unk_CBE680);
  unk_CBE4A0 &= ~2u;
  dword_CBE410[0] = &Phyre::PClassDescriptorConcrete<Phyre::PScripting::PScript>::`vftable';
  return atexit(sub_B04AA0);
}

