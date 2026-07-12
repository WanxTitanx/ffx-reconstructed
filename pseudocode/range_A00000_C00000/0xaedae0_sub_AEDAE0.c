// Function: sub_AEDAE0
// Address: 0xaedae0
// Size: 0xb4
// Prototype: 

int sub_AEDAE0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBFB10, (int)Registry, (int)"PPhysicsPlaneBullet", 112, 4, (int)dword_CBEFC8, 0);
  unk_CBFBA0 |= 2u;
  dword_CBFB10[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsPlaneBullet>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBFB10, (int)&unk_CC7260);
  Phyre_PObject_SetField68(dword_CBFB10, (int)&unk_CC72D0);
  Phyre_PObject_SetField6C(dword_CBFB10, (int)&unk_CC7340);
  unk_CBFBA0 &= ~2u;
  dword_CBFB10[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsPlaneBullet>::`vftable';
  return atexit(sub_B04ED0);
}

