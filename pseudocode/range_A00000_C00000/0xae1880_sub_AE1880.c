// Function: sub_AE1880
// Address: 0xae1880
// Size: 0xb4
// Prototype: 

int sub_AE1880()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C970F8, (int)Registry, (int)"PClusterHeaderD3D11", 84, 4, (int)dword_C96AA8, 0);
  unk_C97188 |= 2u;
  dword_C970F8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PSerialization::PBinary::PClusterHeaderD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C970F8, (int)&unk_C97220);
  Phyre_PObject_SetField68(dword_C970F8, (int)&unk_C97280);
  Phyre_PObject_SetField6C(dword_C970F8, (int)&unk_C972E0);
  unk_C97188 &= ~2u;
  dword_C970F8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PSerialization::PBinary::PClusterHeaderD3D11>::`vftable';
  return atexit(sub_AFB880);
}

