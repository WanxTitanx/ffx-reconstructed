// Function: sub_AEB6A0
// Address: 0xaeb6a0
// Size: 0xb4
// Prototype: 

int sub_AEB6A0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBBA08,
    (int)Registry,
    (int)"PModifierNetworkInstanceInput",
    20,
    4,
    (int)&unk_CBBF60,
    0);
  unk_CBBA98 |= 2u;
  dword_CBBA08[0] = &Phyre::PClassDescriptorAbstract<Phyre::PDynamicGeometry::PModifierNetworkInstanceInput>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBBA08, (int)&unk_CBBE40);
  Phyre_PObject_SetField68(dword_CBBA08, (int)&unk_CBBE60);
  Phyre_PObject_SetField6C(dword_CBBA08, (int)&unk_CBBE80);
  unk_CBBA98 &= ~2u;
  dword_CBBA08[0] = &Phyre::PClassDescriptorConcrete<Phyre::PDynamicGeometry::PModifierNetworkInstanceInput>::`vftable';
  return atexit(sub_B041B0);
}

