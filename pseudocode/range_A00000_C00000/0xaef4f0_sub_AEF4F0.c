// Function: sub_AEF4F0
// Address: 0xaef4f0
// Size: 0xb4
// Prototype: 

int sub_AEF4F0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CCC058,
    (int)Registry,
    (int)"BrokenScreenPolygonDynamicMesh",
    32,
    4,
    (int)dword_C9A7D0,
    0);
  unk_CCC0E8 |= 2u;
  dword_CCC058[0] = &Phyre::PClassDescriptorAbstract<BrokenScreenPolygonDynamicMesh>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CCC058, (int)&unk_CCC0F0);
  Phyre_PObject_SetField68(dword_CCC058, (int)&unk_CCC110);
  Phyre_PObject_SetField6C(dword_CCC058, (int)&unk_CCC130);
  unk_CCC0E8 &= ~2u;
  dword_CCC058[0] = &Phyre::PClassDescriptorConcrete<BrokenScreenPolygonDynamicMesh>::`vftable';
  return atexit(sub_B06B10);
}

