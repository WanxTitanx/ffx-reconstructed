// Function: sub_AF30F0
// Address: 0xaf30f0
// Size: 0xb4
// Prototype: 

int sub_AF30F0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_19445A8, (int)Registry, (int)"PFXAA", 112, 4, (int)dword_1944640, 0);
  unk_1944638 |= 2u;
  dword_19445A8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PFXAA>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_19445A8, (int)&unk_1984500);
  Phyre_PObject_SetField68(dword_19445A8, (int)&unk_1984570);
  Phyre_PObject_SetField6C(dword_19445A8, (int)&unk_19845E0);
  unk_1944638 &= ~2u;
  dword_19445A8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PFXAA>::`vftable';
  return atexit(sub_B08770);
}

