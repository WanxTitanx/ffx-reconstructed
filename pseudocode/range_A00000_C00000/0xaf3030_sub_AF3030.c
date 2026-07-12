// Function: sub_AF3030
// Address: 0xaf3030
// Size: 0xb7
// Prototype: 

int sub_AF3030()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1943978, (int)Registry, (int)"PDepthOfFieldD3D11", 4032, 4, (int)dword_1943848, 0);
  unk_1943A08 |= 2u;
  dword_1943978[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PDepthOfFieldD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1943978, (int)&unk_196C110);
  Phyre_PObject_SetField68(dword_1943978, (int)&unk_196D0D0);
  Phyre_PObject_SetField6C(dword_1943978, (int)&unk_196E090);
  unk_1943A08 &= ~2u;
  dword_1943978[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PDepthOfFieldD3D11>::`vftable';
  return atexit(sub_B08750);
}

