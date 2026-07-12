// Function: sub_AED1F0
// Address: 0xaed1f0
// Size: 0xb4
// Prototype: 

int sub_AED1F0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBEB08, (int)Registry, (int)"PPhysicsCylinderBase", 104, 4, (int)&unk_CBF358, 0);
  unk_CBEB98 |= 2u;
  dword_CBEB08[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsCylinderBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBEB08, (int)&unk_CC6690);
  Phyre_PObject_SetField68(dword_CBEB08, (int)&unk_CC6700);
  Phyre_PObject_SetField6C(dword_CBEB08, (int)&unk_CC6770);
  unk_CBEB98 &= ~2u;
  dword_CBEB08[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsCylinderBase>::`vftable';
  return atexit(sub_B04D50);
}

