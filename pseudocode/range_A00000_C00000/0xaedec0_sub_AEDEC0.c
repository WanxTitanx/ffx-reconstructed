// Function: sub_AEDEC0
// Address: 0xaedec0
// Size: 0xb4
// Prototype: 

int sub_AEDEC0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBF818, (int)Registry, (int)"PPhysicsShapeBullet", 92, 4, (int)dword_CBF2C0, 0);
  unk_CBF8A8 |= 2u;
  dword_CBF818[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsShapeBullet>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF818, (int)&unk_CC58E0);
  Phyre_PObject_SetField68(dword_CBF818, (int)&unk_CC5940);
  Phyre_PObject_SetField6C(dword_CBF818, (int)&unk_CC59A0);
  unk_CBF8A8 &= ~2u;
  dword_CBF818[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsShapeBullet>::`vftable';
  return atexit(sub_B04F90);
}

