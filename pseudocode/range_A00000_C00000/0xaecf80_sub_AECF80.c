// Function: sub_AECF80
// Address: 0xaecf80
// Size: 0xb7
// Prototype: 

int sub_AECF80()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBEA70,
    (int)Registry,
    (int)"PPhysicsCharacterController",
    348,
    4,
    (int)&unk_CBFE08,
    0);
  unk_CBEB00 |= 2u;
  dword_CBEA70[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsCharacterController>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBEA70, (int)&unk_CC8B20);
  Phyre_PObject_SetField68(dword_CBEA70, (int)&unk_CC8C80);
  Phyre_PObject_SetField6C(dword_CBEA70, (int)&unk_CC8DE0);
  unk_CBEB00 &= ~2u;
  dword_CBEA70[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsCharacterController>::`vftable';
  return atexit(sub_B04CD0);
}

