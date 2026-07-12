// Function: sub_AE5A10
// Address: 0xae5a10
// Size: 0xb5
// Prototype: 

int sub_AE5A10()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA4E28,
    (int)Registry,
    (int)"PMeshSegmentContext",
    20,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CA4EB8 |= 2u;
  dword_CA4E28[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PMeshSegmentContext>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA4E28, (int)&unk_CA4F50);
  Phyre_PObject_SetField68(dword_CA4E28, (int)&unk_CA4F70);
  Phyre_PObject_SetField6C(dword_CA4E28, (int)&unk_CA4F90);
  unk_CA4EB8 &= ~2u;
  dword_CA4E28[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PMeshSegmentContext>::`vftable';
  return atexit(sub_AFE710);
}

