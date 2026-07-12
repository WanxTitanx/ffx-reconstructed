// Function: sub_AED2B0
// Address: 0xaed2b0
// Size: 0xb4
// Prototype: 

int sub_AED2B0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBF9E0, (int)Registry, (int)"PPhysicsCylinderBullet", 108, 4, (int)dword_CBEB08, 0);
  unk_CBFA70 |= 2u;
  dword_CBF9E0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsCylinderBullet>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF9E0, (int)&unk_CC67E0);
  Phyre_PObject_SetField68(dword_CBF9E0, (int)&unk_CC6850);
  Phyre_PObject_SetField6C(dword_CBF9E0, (int)&unk_CC68C0);
  unk_CBFA70 &= ~2u;
  dword_CBF9E0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsCylinderBullet>::`vftable';
  return atexit(sub_B04D70);
}

