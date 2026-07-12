// Function: sub_AEE120
// Address: 0xaee120
// Size: 0xb4
// Prototype: 

int sub_AEE120()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBFBA8, (int)Registry, (int)"PPhysicsSphereBullet", 100, 4, (int)dword_CBF3F0, 0);
  unk_CBFC38 |= 2u;
  dword_CBFBA8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsSphereBullet>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBFBA8, (int)&unk_CC5C40);
  Phyre_PObject_SetField68(dword_CBFBA8, (int)&unk_CC5CB0);
  Phyre_PObject_SetField6C(dword_CBFBA8, (int)&unk_CC5D20);
  unk_CBFC38 &= ~2u;
  dword_CBFBA8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsSphereBullet>::`vftable';
  return atexit(sub_B04FF0);
}

