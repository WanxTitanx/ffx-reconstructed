// Function: sub_AEDFA0
// Address: 0xaedfa0
// Size: 0xb4
// Prototype: 

int sub_AEDFA0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBF488, (int)Registry, (int)"PPhysicsSphere", 100, 4, (int)&unk_CBFBA8, 0);
  unk_CBF518 |= 2u;
  dword_CBF488[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsSphere>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF488, (int)&unk_CC5D90);
  Phyre_PObject_SetField68(dword_CBF488, (int)&unk_CC5E00);
  Phyre_PObject_SetField6C(dword_CBF488, (int)&unk_CC5E70);
  unk_CBF518 &= ~2u;
  dword_CBF488[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsSphere>::`vftable';
  return atexit(sub_B04FB0);
}

