// Function: sub_AEDC90
// Address: 0xaedc90
// Size: 0xb7
// Prototype: 

int sub_AEDC90()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBFC40, (int)Registry, (int)"PPhysicsRigidBodyBullet", 228, 4, (int)&unk_CBF0F8, 0);
  unk_CBFCD0 |= 2u;
  dword_CBFC40[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsRigidBodyBullet>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBFC40, (int)&unk_CC7800);
  Phyre_PObject_SetField68(dword_CBFC40, (int)&unk_CC78F0);
  Phyre_PObject_SetField6C(dword_CBFC40, (int)&unk_CC79E0);
  unk_CBFCD0 &= ~2u;
  dword_CBFC40[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsRigidBodyBullet>::`vftable';
  return atexit(sub_B04F30);
}

