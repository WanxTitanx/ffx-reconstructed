// Function: sub_AED7E0
// Address: 0xaed7e0
// Size: 0xb4
// Prototype: 

int sub_AED7E0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBFA78, (int)Registry, (int)"PPhysicsMeshBullet", 108, 4, (int)dword_CBEE00, 0);
  unk_CBFB08 |= 2u;
  dword_CBFA78[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsMeshBullet>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBFA78, (int)&unk_CC63F0);
  Phyre_PObject_SetField68(dword_CBFA78, (int)&unk_CC6460);
  Phyre_PObject_SetField6C(dword_CBFA78, (int)&unk_CC64D0);
  unk_CBFB08 &= ~2u;
  dword_CBFA78[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsMeshBullet>::`vftable';
  return atexit(sub_B04E50);
}

