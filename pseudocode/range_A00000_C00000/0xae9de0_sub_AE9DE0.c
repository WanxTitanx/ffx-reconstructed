// Function: sub_AE9DE0
// Address: 0xae9de0
// Size: 0xb5
// Prototype: 

int sub_AE9DE0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CB1088,
    (int)Registry,
    (int)"PIndexDataBlockBufferD3D11",
    20,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CB1118 |= 2u;
  dword_CB1088[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PIndexDataBlockBufferD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB1088, (int)&unk_CB18F0);
  Phyre_PObject_SetField68(dword_CB1088, (int)&unk_CB1910);
  Phyre_PObject_SetField6C(dword_CB1088, (int)&unk_CB1930);
  unk_CB1118 &= ~2u;
  dword_CB1088[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PIndexDataBlockBufferD3D11>::`vftable';
  return atexit(sub_B029E0);
}

