// Function: sub_AE50F0
// Address: 0xae50f0
// Size: 0xb4
// Prototype: 

int sub_AE50F0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA37D0, (int)Registry, (int)"PTexture2D", 116, 4, (int)&unk_CB39A0, 0);
  unk_CA3860 |= 2u;
  dword_CA37D0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PTexture2D>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA37D0, (int)&unk_CA3950);
  Phyre_PObject_SetField68(dword_CA37D0, (int)&unk_CA39D0);
  Phyre_PObject_SetField6C(dword_CA37D0, (int)&unk_CA3A50);
  unk_CA3860 &= ~2u;
  dword_CA37D0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PTexture2D>::`vftable';
  return atexit(sub_AFE320);
}

