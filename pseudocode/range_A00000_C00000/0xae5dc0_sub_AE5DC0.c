// Function: sub_AE5DC0
// Address: 0xae5dc0
// Size: 0xa4
// Prototype: 

int sub_AE5DC0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA4FA8,
    (int)Registry,
    (int)"PParameterBufferBase",
    4,
    16,
    (int)GlobalTypeAccessor,
    0);
  unk_CA5038 |= 2u;
  dword_CA4FA8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PParameterBufferBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA4FA8, (int)&unk_CA5170);
  Phyre_PObject_SetField68(dword_CA4FA8, (int)&unk_CA5180);
  Phyre_PObject_SetField6C(dword_CA4FA8, (int)&unk_CA5190);
  return atexit(sub_AFE8E0);
}

