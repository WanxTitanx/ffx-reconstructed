// Function: sub_AECD10
// Address: 0xaecd10
// Size: 0xb4
// Prototype: 

int sub_AECD10()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBE8A8, (int)Registry, (int)"PPhysicsCapsule", 112, 4, (int)&unk_CBF948, 0);
  unk_CBE938 |= 2u;
  dword_CBE8A8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsCapsule>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBE8A8, (int)&unk_CC6D20);
  Phyre_PObject_SetField68(dword_CBE8A8, (int)&unk_CC6D90);
  Phyre_PObject_SetField6C(dword_CBE8A8, (int)&unk_CC6E00);
  unk_CBE938 &= ~2u;
  dword_CBE8A8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsCapsule>::`vftable';
  return atexit(sub_B04C50);
}

