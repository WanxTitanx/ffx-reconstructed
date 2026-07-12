// Function: sub_AEBB30
// Address: 0xaebb30
// Size: 0xb5
// Prototype: 

int sub_AEBB30()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBC2F0,
    (int)Registry,
    (int)"PModifierNetworkInfoPacket_Buffer",
    2,
    2,
    (int)GlobalTypeAccessor,
    0);
  unk_CBC380 |= 2u;
  dword_CBC2F0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PDynamicGeometry::PModifierNetworkInfoPacket_Buffer>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBC2F0, (int)&unk_CBD040);
  Phyre_PObject_SetField68(dword_CBC2F0, (int)&unk_CBD050);
  Phyre_PObject_SetField6C(dword_CBC2F0, (int)&unk_CBD060);
  unk_CBC380 &= ~2u;
  dword_CBC2F0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PDynamicGeometry::PModifierNetworkInfoPacket_Buffer>::`vftable';
  return atexit(sub_B04330);
}

