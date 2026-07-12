// Function: sub_AEBCB0
// Address: 0xaebcb0
// Size: 0xb5
// Prototype: 

int sub_AEBCB0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBC258,
    (int)Registry,
    (int)"PModifierNetworkInfoPacket_ModifierInstance",
    32,
    16,
    (int)GlobalTypeAccessor,
    0);
  unk_CBC2E8 |= 2u;
  dword_CBC258[0] = &Phyre::PClassDescriptorAbstract<Phyre::PDynamicGeometry::PModifierNetworkInfoPacket_ModifierInstance>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBC258, (int)&unk_CBCFE0);
  Phyre_PObject_SetField68(dword_CBC258, (int)&unk_CBD000);
  Phyre_PObject_SetField6C(dword_CBC258, (int)&unk_CBD020);
  unk_CBC2E8 &= ~2u;
  dword_CBC258[0] = &Phyre::PClassDescriptorConcrete<Phyre::PDynamicGeometry::PModifierNetworkInfoPacket_ModifierInstance>::`vftable';
  return atexit(sub_B04370);
}

