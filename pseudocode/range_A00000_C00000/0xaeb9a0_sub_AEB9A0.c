// Function: sub_AEB9A0
// Address: 0xaeb9a0
// Size: 0xb5
// Prototype: 

int sub_AEB9A0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBC090,
    (int)Registry,
    (int)"PModifierNetworkBuffer",
    20,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CBC120 |= 2u;
  dword_CBC090[0] = &Phyre::PClassDescriptorAbstract<Phyre::PDynamicGeometry::PModifierNetworkBuffer>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBC090, (int)&unk_CBD0D0);
  Phyre_PObject_SetField68(dword_CBC090, (int)&unk_CBD0F0);
  Phyre_PObject_SetField6C(dword_CBC090, (int)&unk_CBD110);
  unk_CBC120 &= ~2u;
  dword_CBC090[0] = &Phyre::PClassDescriptorConcrete<Phyre::PDynamicGeometry::PModifierNetworkBuffer>::`vftable';
  return atexit(sub_B042F0);
}

