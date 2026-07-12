// Function: sub_AE9C60
// Address: 0xae9c60
// Size: 0xb5
// Prototype: 

int sub_AE9C60()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CB11B8,
    (int)Registry,
    (int)"PDataBlockBufferD3D11",
    20,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CB1248 |= 2u;
  dword_CB11B8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PDataBlockBufferD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB11B8, (int)&unk_CB17D0);
  Phyre_PObject_SetField68(dword_CB11B8, (int)&unk_CB17F0);
  Phyre_PObject_SetField6C(dword_CB11B8, (int)&unk_CB1810);
  unk_CB1248 &= ~2u;
  dword_CB11B8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PDataBlockBufferD3D11>::`vftable';
  return atexit(sub_B029A0);
}

