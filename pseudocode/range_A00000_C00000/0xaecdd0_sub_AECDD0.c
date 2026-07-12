// Function: sub_AECDD0
// Address: 0xaecdd0
// Size: 0xb4
// Prototype: 

int sub_AECDD0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBE810, (int)Registry, (int)"PPhysicsCapsuleBase", 108, 4, (int)&unk_CBF358, 0);
  unk_CBE8A0 |= 2u;
  dword_CBE810[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsCapsuleBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBE810, (int)&unk_CC6A80);
  Phyre_PObject_SetField68(dword_CBE810, (int)&unk_CC6AF0);
  Phyre_PObject_SetField6C(dword_CBE810, (int)&unk_CC6B60);
  unk_CBE8A0 &= ~2u;
  dword_CBE810[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsCapsuleBase>::`vftable';
  return atexit(sub_B04C70);
}

