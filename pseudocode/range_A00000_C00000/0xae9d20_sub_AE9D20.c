// Function: sub_AE9D20
// Address: 0xae9d20
// Size: 0xb4
// Prototype: 

int sub_AE9D20()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB1250, (int)Registry, (int)"PDataBlockD3D11", 64, 4, (int)dword_C988B0, 0);
  unk_CB12E0 |= 2u;
  dword_CB1250[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PDataBlockD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB1250, (int)&unk_CB1830);
  Phyre_PObject_SetField68(dword_CB1250, (int)&unk_CB1870);
  Phyre_PObject_SetField6C(dword_CB1250, (int)&unk_CB18B0);
  unk_CB12E0 &= ~2u;
  dword_CB1250[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PDataBlockD3D11>::`vftable';
  return atexit(sub_B029C0);
}

