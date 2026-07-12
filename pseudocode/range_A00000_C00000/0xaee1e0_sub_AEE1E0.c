// Function: sub_AEE1E0
// Address: 0xaee1e0
// Size: 0xb4
// Prototype: 

int sub_AEE1E0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBF520, (int)Registry, (int)"PPhysicsTaperedCapsule", 112, 4, (int)dword_CBF358, 0);
  unk_CBF5B0 |= 2u;
  dword_CBF520[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsTaperedCapsule>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF520, (int)&unk_CC6FC0);
  Phyre_PObject_SetField68(dword_CBF520, (int)&unk_CC7030);
  Phyre_PObject_SetField6C(dword_CBF520, (int)&unk_CC70A0);
  unk_CBF5B0 &= ~2u;
  dword_CBF520[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsTaperedCapsule>::`vftable';
  return atexit(sub_B05010);
}

