// Function: sub_AE9EA0
// Address: 0xae9ea0
// Size: 0xb4
// Prototype: 

int sub_AE9EA0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB1120, (int)Registry, (int)"PIndexDataBlockD3D11", 60, 4, (int)dword_C98EC8, 0);
  unk_CB11B0 |= 2u;
  dword_CB1120[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PIndexDataBlockD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB1120, (int)&unk_CB1950);
  Phyre_PObject_SetField68(dword_CB1120, (int)&unk_CB1990);
  Phyre_PObject_SetField6C(dword_CB1120, (int)&unk_CB19D0);
  unk_CB11B0 &= ~2u;
  dword_CB1120[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PIndexDataBlockD3D11>::`vftable';
  return atexit(sub_B02A00);
}

