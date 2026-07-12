// Function: sub_AED660
// Address: 0xaed660
// Size: 0xb4
// Prototype: 

int sub_AED660()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBEE98, (int)Registry, (int)"PPhysicsMesh", 108, 4, (int)&unk_CBFA78, 0);
  unk_CBEF28 |= 2u;
  dword_CBEE98[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsMesh>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBEE98, (int)&unk_CC6540);
  Phyre_PObject_SetField68(dword_CBEE98, (int)&unk_CC65B0);
  Phyre_PObject_SetField6C(dword_CBEE98, (int)&unk_CC6620);
  unk_CBEF28 &= ~2u;
  dword_CBEE98[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsMesh>::`vftable';
  return atexit(sub_B04E10);
}

