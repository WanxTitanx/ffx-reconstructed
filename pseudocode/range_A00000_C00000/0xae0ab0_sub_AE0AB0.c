// Function: sub_AE0AB0
// Address: 0xae0ab0
// Size: 0xbe
// Prototype: 

int sub_AE0AB0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C90F30, (int)Registry, (int)"PTypedObject", 8, 4, (int)GlobalTypeAccessor, 0);
  unk_C90FC0 |= 2u;
  dword_C90F30[0] = &Phyre::PClassDescriptorAbstract<Phyre::PTypedObject>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C90F30, (int)&unk_C91020);
  Phyre_PObject_SetField68(dword_C90F30, (int)&unk_C91030);
  Phyre_PObject_SetField6C(dword_C90F30, (int)&unk_C91040);
  dword_C90F30[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PTypedObject>::`vftable';
  unk_C90FC0 = unk_C90FC0 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFA2F0);
}

