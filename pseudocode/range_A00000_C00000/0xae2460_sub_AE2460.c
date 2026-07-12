// Function: sub_AE2460
// Address: 0xae2460
// Size: 0xb5
// Prototype: 

int sub_AE2460()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C99298, (int)Registry, (int)"PMeshSegmentBase", 40, 4, (int)GlobalTypeAccessor, 0);
  unk_C99328 |= 2u;
  dword_C99298[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PMeshSegmentBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C99298, (int)&unk_C996E0);
  Phyre_PObject_SetField68(dword_C99298, (int)&unk_C99710);
  Phyre_PObject_SetField6C(dword_C99298, (int)&unk_C99740);
  unk_C99328 &= ~2u;
  dword_C99298[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PMeshSegmentBase>::`vftable';
  return atexit(sub_AFC6E0);
}

