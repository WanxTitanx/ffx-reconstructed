// Function: sub_AECE90
// Address: 0xaece90
// Size: 0xb4
// Prototype: 

int sub_AECE90()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBF948, (int)Registry, (int)"PPhysicsCapsuleBullet", 112, 4, (int)dword_CBE810, 0);
  unk_CBF9D8 |= 2u;
  dword_CBF948[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsCapsuleBullet>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF948, (int)&unk_CC6BD0);
  Phyre_PObject_SetField68(dword_CBF948, (int)&unk_CC6C40);
  Phyre_PObject_SetField6C(dword_CBF948, (int)&unk_CC6CB0);
  unk_CBF9D8 &= ~2u;
  dword_CBF948[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsCapsuleBullet>::`vftable';
  return atexit(sub_B04C90);
}

