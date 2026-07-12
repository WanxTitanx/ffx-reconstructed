// Function: sub_AE5270
// Address: 0xae5270
// Size: 0xb4
// Prototype: 

int sub_AE5270()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA3B60, (int)Registry, (int)"PTexture3D", 104, 4, (int)&unk_CB3A38, 0);
  unk_CA3BF0 |= 2u;
  dword_CA3B60[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PTexture3D>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA3B60, (int)&unk_CA3D10);
  Phyre_PObject_SetField68(dword_CA3B60, (int)&unk_CA3D80);
  Phyre_PObject_SetField6C(dword_CA3B60, (int)&unk_CA3DF0);
  unk_CA3BF0 &= ~2u;
  dword_CA3B60[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PTexture3D>::`vftable';
  return atexit(sub_AFE380);
}

