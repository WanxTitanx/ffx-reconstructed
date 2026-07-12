// Function: sub_AE0B70
// Address: 0xae0b70
// Size: 0xb5
// Prototype: 

int sub_AE0B70()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C91048, (int)Registry, (int)"PString", 4, 4, (int)GlobalTypeAccessor, 0);
  unk_C910D8 |= 2u;
  dword_C91048[0] = &Phyre::PClassDescriptorAbstract<Phyre::PString>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C91048, (int)&unk_C91150);
  Phyre_PObject_SetField68(dword_C91048, (int)&unk_C91160);
  Phyre_PObject_SetField6C(dword_C91048, (int)&unk_C91170);
  unk_C910D8 &= ~2u;
  dword_C91048[0] = &Phyre::PClassDescriptorConcrete<Phyre::PString>::`vftable';
  return atexit(sub_AFA330);
}

