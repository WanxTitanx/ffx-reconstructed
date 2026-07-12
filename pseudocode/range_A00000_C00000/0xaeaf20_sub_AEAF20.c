// Function: sub_AEAF20
// Address: 0xaeaf20
// Size: 0xbe
// Prototype: 

int sub_AEAF20()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CB3610,
    (int)Registry,
    (int)"PStreamInputLayoutD3D11",
    12,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CB36A0 |= 2u;
  dword_CB3610[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PStreamInputLayoutD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB3610, (int)&unk_CB4EA0);
  Phyre_PObject_SetField68(dword_CB3610, (int)&unk_CB4EB0);
  Phyre_PObject_SetField6C(dword_CB3610, (int)&unk_CB4EC0);
  dword_CB3610[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PStreamInputLayoutD3D11>::`vftable';
  unk_CB36A0 = unk_CB36A0 & 0xFFFFFFF5 | 8;
  return atexit(sub_B03890);
}

