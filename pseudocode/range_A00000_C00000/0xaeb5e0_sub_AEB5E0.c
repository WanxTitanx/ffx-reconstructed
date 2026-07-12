// Function: sub_AEB5E0
// Address: 0xaeb5e0
// Size: 0xb5
// Prototype: 

int sub_AEB5E0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBBB38,
    (int)Registry,
    (int)"PModifierNetworkInstance",
    20,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CBBBC8 |= 2u;
  dword_CBBB38[0] = &Phyre::PClassDescriptorAbstract<Phyre::PDynamicGeometry::PModifierNetworkInstance>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBBB38, (int)&unk_CBBED0);
  Phyre_PObject_SetField68(dword_CBBB38, (int)&unk_CBBEF0);
  Phyre_PObject_SetField6C(dword_CBBB38, (int)&unk_CBBF10);
  unk_CBBBC8 &= ~2u;
  dword_CBBB38[0] = &Phyre::PClassDescriptorConcrete<Phyre::PDynamicGeometry::PModifierNetworkInstance>::`vftable';
  return atexit(sub_B04190);
}

