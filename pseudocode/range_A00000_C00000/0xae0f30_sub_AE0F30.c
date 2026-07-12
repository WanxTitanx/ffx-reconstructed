// Function: sub_AE0F30
// Address: 0xae0f30
// Size: 0xb5
// Prototype: 

int sub_AE0F30()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C91DD8, (int)Registry, (int)"PEntity", 28, 4, (int)GlobalTypeAccessor, 0);
  unk_C91E68 |= 2u;
  dword_C91DD8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PEntity>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C91DD8, (int)&unk_C92000);
  Phyre_PObject_SetField68(dword_C91DD8, (int)&unk_C92020);
  Phyre_PObject_SetField6C(dword_C91DD8, (int)&unk_C92040);
  unk_C91E68 &= ~2u;
  dword_C91DD8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PEntity>::`vftable';
  return atexit(sub_AFA670);
}

