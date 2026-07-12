// Function: sub_AED8A0
// Address: 0xaed8a0
// Size: 0xb5
// Prototype: 

int sub_AED8A0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBEF30, (int)Registry, (int)"PPhysicsModel", 12, 4, (int)GlobalTypeAccessor, 0);
  unk_CBEFC0 |= 2u;
  dword_CBEF30[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsModel>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBEF30, (int)&unk_CC7DA0);
  Phyre_PObject_SetField68(dword_CBEF30, (int)&unk_CC7DB0);
  Phyre_PObject_SetField6C(dword_CBEF30, (int)&unk_CC7DC0);
  unk_CBEFC0 &= ~2u;
  dword_CBEF30[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsModel>::`vftable';
  return atexit(sub_B04E70);
}

