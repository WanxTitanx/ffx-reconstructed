// Function: sub_AEDE10
// Address: 0xaede10
// Size: 0xa4
// Prototype: 

int sub_AEDE10()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBF2C0, (int)Registry, (int)"PPhysicsShapeBase", 88, 16, (int)GlobalTypeAccessor, 4);
  unk_CBF350 |= 2u;
  dword_CBF2C0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsShapeBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF2C0, (int)&unk_CC5440);
  Phyre_PObject_SetField68(dword_CBF2C0, (int)&unk_CC54A0);
  Phyre_PObject_SetField6C(dword_CBF2C0, (int)&unk_CC5500);
  return atexit(sub_B04F70);
}

