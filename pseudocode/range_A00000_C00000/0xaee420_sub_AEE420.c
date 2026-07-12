// Function: sub_AEE420
// Address: 0xaee420
// Size: 0xb5
// Prototype: 

int sub_AEE420()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBF650, (int)Registry, (int)"PPhysicsWorldBase", 84, 4, (int)GlobalTypeAccessor, 0);
  unk_CBF6E0 |= 2u;
  dword_CBF650[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsWorldBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF650, (int)&unk_CC8FD0);
  Phyre_PObject_SetField68(dword_CBF650, (int)&unk_CC9030);
  Phyre_PObject_SetField6C(dword_CBF650, (int)&unk_CC9090);
  unk_CBF6E0 &= ~2u;
  dword_CBF650[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsWorldBase>::`vftable';
  return atexit(sub_B05070);
}

