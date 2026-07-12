// Function: sub_AEB8E0
// Address: 0xaeb8e0
// Size: 0xb5
// Prototype: 

int sub_AEB8E0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBC420, (int)Registry, (int)"PModifierNetwork", 64, 4, (int)GlobalTypeAccessor, 0);
  unk_CBC4B0 |= 2u;
  dword_CBC420[0] = &Phyre::PClassDescriptorAbstract<Phyre::PDynamicGeometry::PModifierNetwork>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBC420, (int)&unk_CBD190);
  Phyre_PObject_SetField68(dword_CBC420, (int)&unk_CBD1D0);
  Phyre_PObject_SetField6C(dword_CBC420, (int)&unk_CBD210);
  unk_CBC4B0 &= ~2u;
  dword_CBC420[0] = &Phyre::PClassDescriptorConcrete<Phyre::PDynamicGeometry::PModifierNetwork>::`vftable';
  return atexit(sub_B042D0);
}

