// Function: sub_AEAE60
// Address: 0xaeae60
// Size: 0xb5
// Prototype: 

int sub_AEAE60()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CB3578,
    (int)Registry,
    (int)"PStreamInputDescD3D11",
    20,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CB3608 |= 2u;
  dword_CB3578[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PStreamInputDescD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB3578, (int)&unk_CB4E40);
  Phyre_PObject_SetField68(dword_CB3578, (int)&unk_CB4E60);
  Phyre_PObject_SetField6C(dword_CB3578, (int)&unk_CB4E80);
  unk_CB3608 &= ~2u;
  dword_CB3578[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PStreamInputDescD3D11>::`vftable';
  return atexit(sub_B03870);
}

