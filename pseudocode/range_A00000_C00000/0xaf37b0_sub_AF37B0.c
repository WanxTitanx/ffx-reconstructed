// Function: sub_AF37B0
// Address: 0xaf37b0
// Size: 0xb7
// Prototype: 

int sub_AF37B0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1944478, (int)Registry, (int)"PLegacyGlowD3D11", 144, 4, (int)&unk_1944348, 0);
  unk_1944508 |= 2u;
  dword_1944478[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PLegacyGlowD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1944478, (int)&unk_1983F00);
  Phyre_PObject_SetField68(dword_1944478, (int)&unk_1983F90);
  Phyre_PObject_SetField6C(dword_1944478, (int)&unk_1984020);
  unk_1944508 &= ~2u;
  dword_1944478[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PLegacyGlowD3D11>::`vftable';
  return atexit(sub_B08890);
}

