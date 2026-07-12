// Function: sub_AED4E0
// Address: 0xaed4e0
// Size: 0xb4
// Prototype: 

int sub_AED4E0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBFD70, (int)Registry, (int)"PPhysicsInterfaceBullet", 76, 4, (int)dword_CBEC38, 0);
  unk_CBFE00 |= 2u;
  dword_CBFD70[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsInterfaceBullet>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBFD70, (int)&unk_CC9540);
  Phyre_PObject_SetField68(dword_CBFD70, (int)&unk_CC9590);
  Phyre_PObject_SetField6C(dword_CBFD70, (int)&unk_CC95E0);
  unk_CBFE00 &= ~2u;
  dword_CBFD70[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsInterfaceBullet>::`vftable';
  return atexit(sub_B04DD0);
}

