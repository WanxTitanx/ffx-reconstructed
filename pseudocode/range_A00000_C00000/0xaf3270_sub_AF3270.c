// Function: sub_AF3270
// Address: 0xaf3270
// Size: 0xb4
// Prototype: 

int sub_AF3270()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1944640, (int)Registry, (int)"PFXAAD3D11", 112, 4, (int)dword_1944510, 0);
  unk_19446D0 |= 2u;
  dword_1944640[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PFXAAD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1944640, (int)&unk_19843B0);
  Phyre_PObject_SetField68(dword_1944640, (int)&unk_1984420);
  Phyre_PObject_SetField6C(dword_1944640, (int)&unk_1984490);
  unk_19446D0 &= ~2u;
  dword_1944640[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PFXAAD3D11>::`vftable';
  return atexit(sub_B087B0);
}

