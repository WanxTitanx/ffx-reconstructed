// Function: sub_AED5A0
// Address: 0xaed5a0
// Size: 0xb5
// Prototype: 

int sub_AED5A0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBED68, (int)Registry, (int)"PPhysicsMaterial", 12, 4, (int)GlobalTypeAccessor, 0);
  unk_CBEDF8 |= 2u;
  dword_CBED68[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsMaterial>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBED68, (int)&unk_CC58B0);
  Phyre_PObject_SetField68(dword_CBED68, (int)&unk_CC58C0);
  Phyre_PObject_SetField6C(dword_CBED68, (int)&unk_CC58D0);
  unk_CBEDF8 &= ~2u;
  dword_CBED68[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsMaterial>::`vftable';
  return atexit(sub_B04DF0);
}

