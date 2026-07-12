// Function: sub_AE17C0
// Address: 0xae17c0
// Size: 0xb5
// Prototype: 

int sub_AE17C0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C96AA8, (int)Registry, (int)"PClusterHeaderBase", 72, 4, (int)GlobalTypeAccessor, 0);
  unk_C96B38 |= 2u;
  dword_C96AA8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PSerialization::PBinary::PClusterHeaderBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C96AA8, (int)&unk_C96EF0);
  Phyre_PObject_SetField68(dword_C96AA8, (int)&unk_C96F40);
  Phyre_PObject_SetField6C(dword_C96AA8, (int)&unk_C96F90);
  unk_C96B38 &= ~2u;
  dword_C96AA8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PSerialization::PBinary::PClusterHeaderBase>::`vftable';
  return atexit(sub_AFB740);
}

