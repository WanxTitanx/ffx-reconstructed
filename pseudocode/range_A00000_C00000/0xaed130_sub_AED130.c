// Function: sub_AED130
// Address: 0xaed130
// Size: 0xb4
// Prototype: 

int sub_AED130()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBEBA0, (int)Registry, (int)"PPhysicsCylinder", 108, 4, (int)&unk_CBF9E0, 0);
  unk_CBEC30 |= 2u;
  dword_CBEBA0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsCylinder>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBEBA0, (int)&unk_CC6930);
  Phyre_PObject_SetField68(dword_CBEBA0, (int)&unk_CC69A0);
  Phyre_PObject_SetField6C(dword_CBEBA0, (int)&unk_CC6A10);
  unk_CBEC30 &= ~2u;
  dword_CBEBA0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsCylinder>::`vftable';
  return atexit(sub_B04D30);
}

