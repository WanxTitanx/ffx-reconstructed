// Function: sub_AEE2A0
// Address: 0xaee2a0
// Size: 0xb4
// Prototype: 

int sub_AEE2A0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBF5B8, (int)Registry, (int)"PPhysicsTaperedCylinder", 112, 4, (int)dword_CBF358, 0);
  unk_CBF648 |= 2u;
  dword_CBF5B8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsTaperedCylinder>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF5B8, (int)&unk_CC6E70);
  Phyre_PObject_SetField68(dword_CBF5B8, (int)&unk_CC6EE0);
  Phyre_PObject_SetField6C(dword_CBF5B8, (int)&unk_CC6F50);
  unk_CBF648 &= ~2u;
  dword_CBF5B8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsTaperedCylinder>::`vftable';
  return atexit(sub_B05030);
}

