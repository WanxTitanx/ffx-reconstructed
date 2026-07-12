// Function: sub_AF3AB0
// Address: 0xaf3ab0
// Size: 0xb7
// Prototype: 

int sub_AF3AB0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1943F20, (int)Registry, (int)"PMLAAD3D11", 144, 4, (int)dword_1943DF0, 0);
  unk_1943FB0 |= 2u;
  dword_1943F20[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PMLAAD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1943F20, (int)&unk_1979AC0);
  Phyre_PObject_SetField68(dword_1943F20, (int)&unk_1979B50);
  Phyre_PObject_SetField6C(dword_1943F20, (int)&unk_1979BE0);
  unk_1943FB0 &= ~2u;
  dword_1943F20[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PMLAAD3D11>::`vftable';
  return atexit(sub_B08910);
}

