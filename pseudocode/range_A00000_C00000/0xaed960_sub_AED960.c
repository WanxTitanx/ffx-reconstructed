// Function: sub_AED960
// Address: 0xaed960
// Size: 0xb4
// Prototype: 

int sub_AED960()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBF060, (int)Registry, (int)"PPhysicsPlane", 112, 4, (int)&unk_CBFB10, 0);
  unk_CBF0F0 |= 2u;
  dword_CBF060[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsPlane>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF060, (int)&unk_CC73B0);
  Phyre_PObject_SetField68(dword_CBF060, (int)&unk_CC7420);
  Phyre_PObject_SetField6C(dword_CBF060, (int)&unk_CC7490);
  unk_CBF0F0 &= ~2u;
  dword_CBF060[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsPlane>::`vftable';
  return atexit(sub_B04E90);
}

