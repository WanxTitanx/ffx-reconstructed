// Function: sub_AE7570
// Address: 0xae7570
// Size: 0xb5
// Prototype: 

int sub_AE7570()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA9038,
    (int)Registry,
    (int)"PIndirectArgsBufferBase",
    8,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CA90C8 |= 2u;
  dword_CA9038[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PIndirectArgsBufferBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA9038, (int)&unk_CA9170);
  Phyre_PObject_SetField68(dword_CA9038, (int)&unk_CA9180);
  Phyre_PObject_SetField6C(dword_CA9038, (int)&unk_CA9190);
  unk_CA90C8 &= ~2u;
  dword_CA9038[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PIndirectArgsBufferBase>::`vftable';
  return atexit(sub_AFFAC0);
}

