// Function: sub_AEBBF0
// Address: 0xaebbf0
// Size: 0xb5
// Prototype: 

int sub_AEBBF0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBC1C0,
    (int)Registry,
    (int)"PModifierNetworkInfoPacket_ModifierCode",
    32,
    16,
    (int)GlobalTypeAccessor,
    0);
  unk_CBC250 |= 2u;
  dword_CBC1C0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PDynamicGeometry::PModifierNetworkInfoPacket_ModifierCode>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBC1C0, (int)&unk_CBCF80);
  Phyre_PObject_SetField68(dword_CBC1C0, (int)&unk_CBCFA0);
  Phyre_PObject_SetField6C(dword_CBC1C0, (int)&unk_CBCFC0);
  unk_CBC250 &= ~2u;
  dword_CBC1C0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PDynamicGeometry::PModifierNetworkInfoPacket_ModifierCode>::`vftable';
  return atexit(sub_B04350);
}

