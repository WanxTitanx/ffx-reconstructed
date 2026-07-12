// Function: sub_AEB520
// Address: 0xaeb520
// Size: 0xb5
// Prototype: 

int sub_AEB520()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBB268,
    (int)Registry,
    (int)"PModifierNetworkDynamicMeshSegment",
    16,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CBB2F8 |= 2u;
  dword_CBB268[0] = &Phyre::PClassDescriptorAbstract<Phyre::PDynamicGeometry::PModifierNetworkDynamicMeshSegment>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBB268, (int)&unk_CBB880);
  Phyre_PObject_SetField68(dword_CBB268, (int)&unk_CBB890);
  Phyre_PObject_SetField6C(dword_CBB268, (int)&unk_CBB8A0);
  unk_CBB2F8 &= ~2u;
  dword_CBB268[0] = &Phyre::PClassDescriptorConcrete<Phyre::PDynamicGeometry::PModifierNetworkDynamicMeshSegment>::`vftable';
  return atexit(sub_B04000);
}

