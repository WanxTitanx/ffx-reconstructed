// Function: sub_AE1FE0
// Address: 0xae1fe0
// Size: 0xb4
// Prototype: 

int sub_AE1FE0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C98948, (int)Registry, (int)"PDataBlock", 64, 4, (int)&unk_CB1250, 0);
  unk_C989D8 |= 2u;
  dword_C98948[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PDataBlock>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C98948, (int)&unk_C98C20);
  Phyre_PObject_SetField68(dword_C98948, (int)&unk_C98C60);
  Phyre_PObject_SetField6C(dword_C98948, (int)&unk_C98CA0);
  unk_C989D8 &= ~2u;
  dword_C98948[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PDataBlock>::`vftable';
  return atexit(sub_AFC500);
}

