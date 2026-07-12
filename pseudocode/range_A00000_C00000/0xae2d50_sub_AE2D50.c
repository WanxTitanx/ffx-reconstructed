// Function: sub_AE2D50
// Address: 0xae2d50
// Size: 0xb5
// Prototype: 

int sub_AE2D50()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9B4C8,
    (int)Registry,
    (int)"PConstantBufferBase",
    12,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_C9B558 |= 2u;
  dword_C9B4C8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PConstantBufferBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9B4C8, (int)&unk_C9B630);
  Phyre_PObject_SetField68(dword_C9B4C8, (int)&unk_C9B640);
  Phyre_PObject_SetField6C(dword_C9B4C8, (int)&unk_C9B650);
  unk_C9B558 &= ~2u;
  dword_C9B4C8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PConstantBufferBase>::`vftable';
  return atexit(sub_AFD250);
}

