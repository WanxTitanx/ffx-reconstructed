// Function: sub_AE5030
// Address: 0xae5030
// Size: 0xb5
// Prototype: 

int sub_AE5030()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA3530, (int)Registry, (int)"PTextureCommonBase", 28, 4, (int)GlobalTypeAccessor, 0);
  unk_CA35C0 |= 2u;
  dword_CA3530[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PTextureCommonBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA3530, (int)&unk_CA36D0);
  Phyre_PObject_SetField68(dword_CA3530, (int)&unk_CA36F0);
  Phyre_PObject_SetField6C(dword_CA3530, (int)&unk_CA3710);
  unk_CA35C0 &= ~2u;
  dword_CA3530[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PTextureCommonBase>::`vftable';
  return atexit(sub_AFE270);
}

