// Function: sub_AED370
// Address: 0xaed370
// Size: 0xa3
// Prototype: 

int sub_AED370()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBECD0, (int)Registry, (int)"PPhysicsInterface", 76, 16, (int)&unk_CBFD70, 0);
  unk_CBED60 |= 2u;
  dword_CBECD0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsInterface>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBECD0, (int)&unk_CC5680);
  Phyre_PObject_SetField68(dword_CBECD0, (int)&unk_CC56D0);
  Phyre_PObject_SetField6C(dword_CBECD0, (int)&unk_CC5720);
  return atexit(sub_B04D90);
}

