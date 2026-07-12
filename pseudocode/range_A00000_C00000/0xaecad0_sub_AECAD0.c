// Function: sub_AECAD0
// Address: 0xaecad0
// Size: 0xb4
// Prototype: 

int sub_AECAD0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBE6E0, (int)Registry, (int)"PPhysicsBoxBase", 108, 4, (int)&unk_CBF358, 0);
  unk_CBE770 |= 2u;
  dword_CBE6E0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsBoxBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBE6E0, (int)&unk_CC5EE0);
  Phyre_PObject_SetField68(dword_CBE6E0, (int)&unk_CC5F50);
  Phyre_PObject_SetField6C(dword_CBE6E0, (int)&unk_CC5FC0);
  unk_CBE770 &= ~2u;
  dword_CBE6E0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsBoxBase>::`vftable';
  return atexit(sub_B04BF0);
}

