// Function: sub_AEB820
// Address: 0xaeb820
// Size: 0xb5
// Prototype: 

int sub_AEB820()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBC128, (int)Registry, (int)"PModifierAndInputs", 20, 4, (int)GlobalTypeAccessor, 0);
  unk_CBC1B8 |= 2u;
  dword_CBC128[0] = &Phyre::PClassDescriptorAbstract<Phyre::PDynamicGeometry::PModifierAndInputs>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBC128, (int)&unk_CBD130);
  Phyre_PObject_SetField68(dword_CBC128, (int)&unk_CBD150);
  Phyre_PObject_SetField6C(dword_CBC128, (int)&unk_CBD170);
  unk_CBC1B8 &= ~2u;
  dword_CBC128[0] = &Phyre::PClassDescriptorConcrete<Phyre::PDynamicGeometry::PModifierAndInputs>::`vftable';
  return atexit(sub_B042B0);
}

