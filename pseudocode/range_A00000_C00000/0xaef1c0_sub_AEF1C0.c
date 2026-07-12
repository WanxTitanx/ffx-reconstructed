// Function: sub_AEF1C0
// Address: 0xaef1c0
// Size: 0xbd
// Prototype: 

int sub_AEF1C0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CCBDB8,
    (int)Registry,
    (int)"RadialLineDynamicMeshInstance",
    12,
    4,
    (int)dword_CA7F28,
    0);
  unk_CCBE48 |= 2u;
  dword_CCBDB8[0] = &Phyre::PClassDescriptorAbstract<RadialLineDynamicMeshInstance>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CCBDB8, (int)&unk_CCBE50);
  Phyre_PObject_SetField68(dword_CCBDB8, (int)&unk_CCBE60);
  Phyre_PObject_SetField6C(dword_CCBDB8, (int)&unk_CCBE70);
  dword_CCBDB8[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<RadialLineDynamicMeshInstance>::`vftable';
  unk_CCBE48 = unk_CCBE48 & 0xFFFFFFF5 | 8;
  return atexit(sub_B06A20);
}

