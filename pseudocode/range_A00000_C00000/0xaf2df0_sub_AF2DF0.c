// Function: sub_AF2DF0
// Address: 0xaf2df0
// Size: 0xb7
// Prototype: 

int sub_AF2DF0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_19437B0,
    (int)Registry,
    (int)"PDeferredLightingD3D11",
    16448,
    4,
    (int)dword_1943680,
    0);
  unk_1943840 |= 2u;
  dword_19437B0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PDeferredLightingD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_19437B0, (int)&unk_1951080);
  Phyre_PObject_SetField68(dword_19437B0, (int)&unk_19550C0);
  Phyre_PObject_SetField6C(dword_19437B0, (int)&unk_1959100);
  unk_1943840 &= ~2u;
  dword_19437B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PDeferredLightingD3D11>::`vftable';
  return atexit(sub_B086F0);
}

