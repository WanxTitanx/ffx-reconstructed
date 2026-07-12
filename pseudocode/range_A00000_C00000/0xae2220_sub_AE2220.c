// Function: sub_AE2220
// Address: 0xae2220
// Size: 0xb4
// Prototype: 

int sub_AE2220()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C98F60, (int)Registry, (int)"PIndexDataBlock", 60, 4, (int)&unk_CB1120, 0);
  unk_C98FF0 |= 2u;
  dword_C98F60[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PIndexDataBlock>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C98F60, (int)&unk_C99140);
  Phyre_PObject_SetField68(dword_C98F60, (int)&unk_C99180);
  Phyre_PObject_SetField6C(dword_C98F60, (int)&unk_C991C0);
  unk_C98FF0 &= ~2u;
  dword_C98F60[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PIndexDataBlock>::`vftable';
  return atexit(sub_AFC630);
}

