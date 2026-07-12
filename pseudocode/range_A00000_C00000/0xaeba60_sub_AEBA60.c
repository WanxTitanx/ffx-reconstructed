// Function: sub_AEBA60
// Address: 0xaeba60
// Size: 0xcb
// Prototype: 

int sub_AEBA60()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBC388,
    (int)Registry,
    (int)"PModifierNetworkInfoPacket",
    32,
    16,
    (int)GlobalTypeAccessor,
    0);
  unk_CBC418 |= 2u;
  dword_CBC388[0] = &Phyre::PClassDescriptorAbstract<Phyre::PDynamicGeometry::PModifierNetworkInfoPacket>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBC388, (int)&unk_CBD290);
  Phyre_PObject_SetField68(dword_CBC388, (int)&unk_CBD2B0);
  Phyre_PObject_SetField6C(dword_CBC388, (int)&unk_CBD2D0);
  psub_5C52F0 = sub_5C52F0;
  dword_CBC388[0] = &Phyre::PClassDescriptorHeader<Phyre::PDynamicGeometry::PModifierNetworkInfoPacket>::`vftable';
  unk_CBC418 = unk_CBC418 & 0xFFFFFFF1 | 4;
  return atexit(sub_B04310);
}

