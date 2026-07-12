// Function: sub_AE46E0
// Address: 0xae46e0
// Size: 0xb5
// Prototype: 

int sub_AE46E0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA1630,
    (int)Registry,
    (int)"PShaderPassStateBase",
    4,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CA16C0 |= 2u;
  dword_CA1630[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderPassStateBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA1630, (int)&unk_CA1D10);
  Phyre_PObject_SetField68(dword_CA1630, (int)&unk_CA1D20);
  Phyre_PObject_SetField6C(dword_CA1630, (int)&unk_CA1D30);
  unk_CA16C0 &= ~2u;
  dword_CA1630[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderPassStateBase>::`vftable';
  return atexit(sub_AFDA10);
}

