// Function: sub_AEDBA0
// Address: 0xaedba0
// Size: 0xb7
// Prototype: 

int sub_AEDBA0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBF228, (int)Registry, (int)"PPhysicsRigidBody", 228, 4, (int)&unk_CBFC40, 0);
  unk_CBF2B8 |= 2u;
  dword_CBF228[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsRigidBody>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF228, (int)&unk_CC7AD0);
  Phyre_PObject_SetField68(dword_CBF228, (int)&unk_CC7BC0);
  Phyre_PObject_SetField6C(dword_CBF228, (int)&unk_CC7CB0);
  unk_CBF2B8 &= ~2u;
  dword_CBF228[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsRigidBody>::`vftable';
  return atexit(sub_B04EF0);
}

