// Function: sub_AE73F0
// Address: 0xae73f0
// Size: 0xb5
// Prototype: 

int sub_AE73F0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA8D30,
    (int)Registry,
    (int)"PStructuredBufferBase",
    20,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CA8DC0 |= 2u;
  dword_CA8D30[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PStructuredBufferBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA8D30, (int)&unk_CA8EF0);
  Phyre_PObject_SetField68(dword_CA8D30, (int)&unk_CA8F10);
  Phyre_PObject_SetField6C(dword_CA8D30, (int)&unk_CA8F30);
  unk_CA8DC0 &= ~2u;
  dword_CA8D30[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PStructuredBufferBase>::`vftable';
  return atexit(sub_AFFA50);
}

