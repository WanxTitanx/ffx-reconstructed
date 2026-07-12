// Function: sub_AEE4E0
// Address: 0xaee4e0
// Size: 0xb7
// Prototype: 

int sub_AEE4E0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBFCD8, (int)Registry, (int)"PPhysicsWorldBullet", 168, 4, (int)dword_CBF650, 0);
  unk_CBFD68 |= 2u;
  dword_CBFCD8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsWorldBullet>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBFCD8, (int)&unk_CC90F0);
  Phyre_PObject_SetField68(dword_CBFCD8, (int)&unk_CC91A0);
  Phyre_PObject_SetField6C(dword_CBFCD8, (int)&unk_CC9250);
  unk_CBFD68 &= ~2u;
  dword_CBFCD8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsWorldBullet>::`vftable';
  return atexit(sub_B05090);
}

