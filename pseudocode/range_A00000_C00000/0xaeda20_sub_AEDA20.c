// Function: sub_AEDA20
// Address: 0xaeda20
// Size: 0xb4
// Prototype: 

int sub_AEDA20()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBEFC8, (int)Registry, (int)"PPhysicsPlaneBase", 108, 4, (int)&unk_CBF358, 0);
  unk_CBF058 |= 2u;
  dword_CBEFC8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsPlaneBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBEFC8, (int)&unk_CC7110);
  Phyre_PObject_SetField68(dword_CBEFC8, (int)&unk_CC7180);
  Phyre_PObject_SetField6C(dword_CBEFC8, (int)&unk_CC71F0);
  unk_CBF058 &= ~2u;
  dword_CBEFC8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsPlaneBase>::`vftable';
  return atexit(sub_B04EB0);
}

