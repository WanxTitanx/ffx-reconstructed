// Function: sub_AF34B0
// Address: 0xaf34b0
// Size: 0xb7
// Prototype: 

int sub_AF34B0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1944218, (int)Registry, (int)"PGlowD3D11", 172, 4, (int)&unk_19440E8, 0);
  unk_19442A8 |= 2u;
  dword_1944218[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PGlowD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1944218, (int)&unk_19837B0);
  Phyre_PObject_SetField68(dword_1944218, (int)&unk_1983860);
  Phyre_PObject_SetField6C(dword_1944218, (int)&unk_1983910);
  unk_19442A8 &= ~2u;
  dword_1944218[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PGlowD3D11>::`vftable';
  return atexit(sub_B08810);
}

