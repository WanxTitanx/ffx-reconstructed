// Function: sub_AE4920
// Address: 0xae4920
// Size: 0xb5
// Prototype: 

int sub_AE4920()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA2898, (int)Registry, (int)"PSamplerStateBase", 32, 4, (int)GlobalTypeAccessor, 0);
  unk_CA2928 |= 2u;
  dword_CA2898[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PSamplerStateBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA2898, (int)&unk_CA2E20);
  Phyre_PObject_SetField68(dword_CA2898, (int)&unk_CA2E40);
  Phyre_PObject_SetField6C(dword_CA2898, (int)&unk_CA2E60);
  unk_CA2928 &= ~2u;
  dword_CA2898[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PSamplerStateBase>::`vftable';
  return atexit(sub_AFDCA0);
}

