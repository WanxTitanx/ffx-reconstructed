// Function: sub_AEE060
// Address: 0xaee060
// Size: 0xb4
// Prototype: 

int sub_AEE060()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBF3F0, (int)Registry, (int)"PPhysicsSphereBase", 96, 4, (int)dword_CBF358, 0);
  unk_CBF480 |= 2u;
  dword_CBF3F0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsSphereBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF3F0, (int)&unk_CC5B20);
  Phyre_PObject_SetField68(dword_CBF3F0, (int)&unk_CC5B80);
  Phyre_PObject_SetField6C(dword_CBF3F0, (int)&unk_CC5BE0);
  unk_CBF480 &= ~2u;
  dword_CBF3F0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsSphereBase>::`vftable';
  return atexit(sub_B04FD0);
}

