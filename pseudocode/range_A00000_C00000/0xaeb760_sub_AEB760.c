// Function: sub_AEB760
// Address: 0xaeb760
// Size: 0xb5
// Prototype: 

int sub_AEB760()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBBAA0,
    (int)Registry,
    (int)"PModifierNetworkInstancePacketInput",
    8,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CBBB30 |= 2u;
  dword_CBBAA0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PDynamicGeometry::PModifierNetworkInstancePacketInput>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBBAA0, (int)&unk_CBBEA0);
  Phyre_PObject_SetField68(dword_CBBAA0, (int)&unk_CBBEB0);
  Phyre_PObject_SetField6C(dword_CBBAA0, (int)&unk_CBBEC0);
  unk_CBBB30 &= ~2u;
  dword_CBBAA0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PDynamicGeometry::PModifierNetworkInstancePacketInput>::`vftable';
  return atexit(sub_B041D0);
}

