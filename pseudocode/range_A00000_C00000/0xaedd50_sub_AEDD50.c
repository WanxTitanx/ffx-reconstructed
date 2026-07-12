// Function: sub_AEDD50
// Address: 0xaedd50
// Size: 0xb4
// Prototype: 

int sub_AEDD50()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBF358, (int)Registry, (int)"PPhysicsShape", 92, 4, (int)&unk_CBF818, 0);
  unk_CBF3E8 |= 2u;
  dword_CBF358[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsShape>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF358, (int)&unk_CC5A00);
  Phyre_PObject_SetField68(dword_CBF358, (int)&unk_CC5A60);
  Phyre_PObject_SetField6C(dword_CBF358, (int)&unk_CC5AC0);
  unk_CBF3E8 &= ~2u;
  dword_CBF358[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsShape>::`vftable';
  return atexit(sub_B04F50);
}

