// Function: sub_AEB460
// Address: 0xaeb460
// Size: 0xb4
// Prototype: 

int sub_AEB460()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBB300,
    (int)Registry,
    (int)"PModifierNetworkDynamicMesh",
    60,
    4,
    (int)dword_C9A7D0,
    0);
  unk_CBB390 |= 2u;
  dword_CBB300[0] = &Phyre::PClassDescriptorAbstract<Phyre::PDynamicGeometry::PModifierNetworkDynamicMesh>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBB300, (int)&unk_CBB8B0);
  Phyre_PObject_SetField68(dword_CBB300, (int)&unk_CBB8F0);
  Phyre_PObject_SetField6C(dword_CBB300, (int)&unk_CBB930);
  unk_CBB390 &= ~2u;
  dword_CBB300[0] = &Phyre::PClassDescriptorConcrete<Phyre::PDynamicGeometry::PModifierNetworkDynamicMesh>::`vftable';
  return atexit(sub_B03FE0);
}

