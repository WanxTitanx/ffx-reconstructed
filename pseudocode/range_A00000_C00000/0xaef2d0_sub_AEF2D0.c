// Function: sub_AEF2D0
// Address: 0xaef2d0
// Size: 0xb4
// Prototype: 

int sub_AEF2D0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CCBE88, (int)Registry, (int)"RadialLineDynamicMesh", 32, 4, (int)dword_C9A7D0, 0);
  unk_CCBF18 |= 2u;
  dword_CCBE88[0] = &Phyre::PClassDescriptorAbstract<RadialLineDynamicMesh>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CCBE88, (int)&unk_CCBF20);
  Phyre_PObject_SetField68(dword_CCBE88, (int)&unk_CCBF40);
  Phyre_PObject_SetField6C(dword_CCBE88, (int)&unk_CCBF60);
  unk_CCBF18 &= ~2u;
  dword_CCBE88[0] = &Phyre::PClassDescriptorConcrete<RadialLineDynamicMesh>::`vftable';
  return atexit(sub_B06A70);
}

