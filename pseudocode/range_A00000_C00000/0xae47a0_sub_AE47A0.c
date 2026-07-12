// Function: sub_AE47A0
// Address: 0xae47a0
// Size: 0xb5
// Prototype: 

int sub_AE47A0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA2548, (int)Registry, (int)"PShader", 32, 4, (int)GlobalTypeAccessor, 0);
  unk_CA25D8 |= 2u;
  dword_CA2548[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShader>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA2548, (int)&unk_CA2800);
  Phyre_PObject_SetField68(dword_CA2548, (int)&unk_CA2820);
  Phyre_PObject_SetField6C(dword_CA2548, (int)&unk_CA2840);
  unk_CA25D8 &= ~2u;
  dword_CA2548[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShader>::`vftable';
  return atexit(sub_AFDBC0);
}

