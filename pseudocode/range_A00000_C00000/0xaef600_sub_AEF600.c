// Function: sub_AEF600
// Address: 0xaef600
// Size: 0xb7
// Prototype: 

int sub_AEF600()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CCC158, (int)Registry, (int)"ShadowDynamicMesh", 492, 4, (int)dword_C9A7D0, 0);
  unk_CCC1E8 |= 2u;
  dword_CCC158[0] = &Phyre::PClassDescriptorAbstract<ShadowDynamicMesh>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CCC158, (int)&unk_CCC1F0);
  Phyre_PObject_SetField68(dword_CCC158, (int)&unk_CCC3E0);
  Phyre_PObject_SetField6C(dword_CCC158, (int)&unk_CCC5D0);
  unk_CCC1E8 &= ~2u;
  dword_CCC158[0] = &Phyre::PClassDescriptorConcrete<ShadowDynamicMesh>::`vftable';
  return atexit(sub_B06B60);
}

