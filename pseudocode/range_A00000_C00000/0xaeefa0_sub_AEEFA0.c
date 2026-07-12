// Function: sub_AEEFA0
// Address: 0xaeefa0
// Size: 0xb4
// Prototype: 

int sub_AEEFA0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CCBBE0,
    (int)Registry,
    (int)"DistortionGridDynamicMesh",
    28,
    4,
    (int)dword_C9A7D0,
    0);
  unk_CCBC70 |= 2u;
  dword_CCBBE0[0] = &Phyre::PClassDescriptorAbstract<DistortionGridDynamicMesh>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CCBBE0, (int)&unk_CCBC80);
  Phyre_PObject_SetField68(dword_CCBBE0, (int)&unk_CCBCA0);
  Phyre_PObject_SetField6C(dword_CCBBE0, (int)&unk_CCBCC0);
  unk_CCBC70 &= ~2u;
  dword_CCBBE0[0] = &Phyre::PClassDescriptorConcrete<DistortionGridDynamicMesh>::`vftable';
  return atexit(sub_B06980);
}

