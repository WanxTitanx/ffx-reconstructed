// Function: sub_AED070
// Address: 0xaed070
// Size: 0xb7
// Prototype: 

int sub_AED070()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBFE08,
    (int)Registry,
    (int)"PPhysicsCharacterControllerBullet",
    348,
    4,
    (int)&unk_CBE9D8,
    0);
  unk_CBFE98 |= 2u;
  dword_CBFE08[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsCharacterControllerBullet>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBFE08, (int)&unk_CC8700);
  Phyre_PObject_SetField68(dword_CBFE08, (int)&unk_CC8860);
  Phyre_PObject_SetField6C(dword_CBFE08, (int)&unk_CC89C0);
  unk_CBFE98 &= ~2u;
  dword_CBFE08[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsCharacterControllerBullet>::`vftable';
  return atexit(sub_B04D10);
}

