// Function: sub_AEF0B0
// Address: 0xaef0b0
// Size: 0xbd
// Prototype: 

int sub_AEF0B0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CCBCE0,
    (int)Registry,
    (int)"DistortionGridDynamicMeshInstance",
    12,
    4,
    (int)dword_CA7F28,
    0);
  unk_CCBD70 |= 2u;
  dword_CCBCE0[0] = &Phyre::PClassDescriptorAbstract<DistortionGridDynamicMeshInstance>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CCBCE0, (int)&unk_CCBD80);
  Phyre_PObject_SetField68(dword_CCBCE0, (int)&unk_CCBD90);
  Phyre_PObject_SetField6C(dword_CCBCE0, (int)&unk_CCBDA0);
  dword_CCBCE0[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<DistortionGridDynamicMeshInstance>::`vftable';
  unk_CCBD70 = unk_CCBD70 & 0xFFFFFFF5 | 8;
  return atexit(sub_B069D0);
}

