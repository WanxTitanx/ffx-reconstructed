// Function: sub_AE6F40
// Address: 0xae6f40
// Size: 0xbd
// Prototype: 

int sub_AE6F40()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA8020,
    (int)Registry,
    (int)"PModifierNetworkDynamicMeshInstance",
    20,
    4,
    (int)dword_CA7F28,
    0);
  unk_CA80B0 |= 2u;
  dword_CA8020[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PModifierNetworkDynamicMeshInstance>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA8020, (int)&unk_CA8210);
  Phyre_PObject_SetField68(dword_CA8020, (int)&unk_CA8230);
  Phyre_PObject_SetField6C(dword_CA8020, (int)&unk_CA8250);
  dword_CA8020[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PModifierNetworkDynamicMeshInstance>::`vftable';
  unk_CA80B0 = unk_CA80B0 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFF800);
}

