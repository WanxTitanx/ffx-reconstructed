// Function: sub_AECA10
// Address: 0xaeca10
// Size: 0xb4
// Prototype: 

int sub_AECA10()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBE778, (int)Registry, (int)"PPhysicsBox", 112, 4, (int)&unk_CBF8B0, 0);
  unk_CBE808 |= 2u;
  dword_CBE778[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsBox>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBE778, (int)&unk_CC6180);
  Phyre_PObject_SetField68(dword_CBE778, (int)&unk_CC61F0);
  Phyre_PObject_SetField6C(dword_CBE778, (int)&unk_CC6260);
  unk_CBE808 &= ~2u;
  dword_CBE778[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsBox>::`vftable';
  return atexit(sub_B04BD0);
}

