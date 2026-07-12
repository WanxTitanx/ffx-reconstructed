// Function: sub_AEEE70
// Address: 0xaeee70
// Size: 0xbd
// Prototype: 

int sub_AEEE70()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CCBB10, (int)Registry, (int)"ClassDynamicMeshInstance", 16, 4, (int)dword_CA7F28, 0);
  unk_CCBBA0 |= 2u;
  dword_CCBB10[0] = &Phyre::PClassDescriptorAbstract<ClassDynamicMeshInstance>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CCBB10, (int)&unk_CCBBB0);
  Phyre_PObject_SetField68(dword_CCBB10, (int)&unk_CCBBC0);
  Phyre_PObject_SetField6C(dword_CCBB10, (int)&unk_CCBBD0);
  dword_CCBB10[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<ClassDynamicMeshInstance>::`vftable';
  unk_CCBBA0 = unk_CCBBA0 & 0xFFFFFFF5 | 8;
  return atexit(sub_B06930);
}

