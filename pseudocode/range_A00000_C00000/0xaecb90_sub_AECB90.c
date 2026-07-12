// Function: sub_AECB90
// Address: 0xaecb90
// Size: 0xb4
// Prototype: 

int sub_AECB90()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBF8B0, (int)Registry, (int)"PPhysicsBoxBullet", 112, 4, (int)dword_CBE6E0, 0);
  unk_CBF940 |= 2u;
  dword_CBF8B0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsBoxBullet>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF8B0, (int)&unk_CC6030);
  Phyre_PObject_SetField68(dword_CBF8B0, (int)&unk_CC60A0);
  Phyre_PObject_SetField6C(dword_CBF8B0, (int)&unk_CC6110);
  unk_CBF940 &= ~2u;
  dword_CBF8B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsBoxBullet>::`vftable';
  return atexit(sub_B04C10);
}

