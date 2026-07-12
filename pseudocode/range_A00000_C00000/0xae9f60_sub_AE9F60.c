// Function: sub_AE9F60
// Address: 0xae9f60
// Size: 0xb4
// Prototype: 

int sub_AE9F60()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB0FF0, (int)Registry, (int)"PMeshSegmentD3D11", 108, 4, (int)dword_C99298, 0);
  unk_CB1080 |= 2u;
  dword_CB0FF0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PMeshSegmentD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB0FF0, (int)&unk_CB1A10);
  Phyre_PObject_SetField68(dword_CB0FF0, (int)&unk_CB1A80);
  Phyre_PObject_SetField6C(dword_CB0FF0, (int)&unk_CB1AF0);
  unk_CB1080 &= ~2u;
  dword_CB0FF0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PMeshSegmentD3D11>::`vftable';
  return atexit(sub_B02A20);
}

