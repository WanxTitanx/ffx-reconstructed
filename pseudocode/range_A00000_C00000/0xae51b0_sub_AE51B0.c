// Function: sub_AE51B0
// Address: 0xae51b0
// Size: 0xb4
// Prototype: 

int sub_AE51B0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA3738, (int)Registry, (int)"PTexture2DBase", 36, 4, (int)dword_CA3530, 0);
  unk_CA37C8 |= 2u;
  dword_CA3738[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PTexture2DBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA3738, (int)&unk_CA38C0);
  Phyre_PObject_SetField68(dword_CA3738, (int)&unk_CA38F0);
  Phyre_PObject_SetField6C(dword_CA3738, (int)&unk_CA3920);
  unk_CA37C8 &= ~2u;
  dword_CA3738[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PTexture2DBase>::`vftable';
  return atexit(sub_AFE340);
}

