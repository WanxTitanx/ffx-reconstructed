// Function: sub_AF1360
// Address: 0xaf1360
// Size: 0xb5
// Prototype: 

int sub_AF1360()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1941878, (int)Registry, (int)"PInputAction", 16, 4, (int)GlobalTypeAccessor, 4);
  unk_1941908 |= 2u;
  dword_1941878[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputAction>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1941878, (int)&unk_19428E0);
  Phyre_PObject_SetField68(dword_1941878, (int)&unk_19428F0);
  Phyre_PObject_SetField6C(dword_1941878, (int)&unk_1942900);
  unk_1941908 &= ~2u;
  dword_1941878[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputAction>::`vftable';
  return atexit(sub_B07DE0);
}

