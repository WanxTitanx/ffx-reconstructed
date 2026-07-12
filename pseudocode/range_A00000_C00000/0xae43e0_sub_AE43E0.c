// Function: sub_AE43E0
// Address: 0xae43e0
// Size: 0xb5
// Prototype: 

int sub_AE43E0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA1500, (int)Registry, (int)"PShaderPassBase", 24, 4, (int)GlobalTypeAccessor, 0);
  unk_CA1590 |= 2u;
  dword_CA1500[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderPassBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA1500, (int)&unk_CA1D40);
  Phyre_PObject_SetField68(dword_CA1500, (int)&unk_CA1D60);
  Phyre_PObject_SetField6C(dword_CA1500, (int)&unk_CA1D80);
  unk_CA1590 &= ~2u;
  dword_CA1500[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderPassBase>::`vftable';
  return atexit(sub_AFD990);
}

