// Function: sub_AE5FF0
// Address: 0xae5ff0
// Size: 0xb5
// Prototype: 

int sub_AE5FF0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA5660,
    (int)Registry,
    (int)"PContextVariantFoldingTable",
    20,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CA56F0 |= 2u;
  dword_CA5660[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PContextVariantFoldingTable>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA5660, (int)&unk_CA5E60);
  Phyre_PObject_SetField68(dword_CA5660, (int)&unk_CA5E80);
  Phyre_PObject_SetField6C(dword_CA5660, (int)&unk_CA5EA0);
  unk_CA56F0 &= ~2u;
  dword_CA5660[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PContextVariantFoldingTable>::`vftable';
  return atexit(sub_AFE9F0);
}

