// Function: sub_AED720
// Address: 0xaed720
// Size: 0xb4
// Prototype: 

int sub_AED720()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBEE00, (int)Registry, (int)"PPhysicsMeshBase", 96, 4, (int)&unk_CBF358, 0);
  unk_CBEE90 |= 2u;
  dword_CBEE00[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsMeshBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBEE00, (int)&unk_CC62D0);
  Phyre_PObject_SetField68(dword_CBEE00, (int)&unk_CC6330);
  Phyre_PObject_SetField6C(dword_CBEE00, (int)&unk_CC6390);
  unk_CBEE90 &= ~2u;
  dword_CBEE00[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsMeshBase>::`vftable';
  return atexit(sub_B04E30);
}

