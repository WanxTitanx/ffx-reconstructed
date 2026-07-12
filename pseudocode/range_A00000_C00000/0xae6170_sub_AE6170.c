// Function: sub_AE6170
// Address: 0xae6170
// Size: 0xb5
// Prototype: 

int sub_AE6170()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA55C8, (int)Registry, (int)"PShaderPassInfo", 32, 4, (int)GlobalTypeAccessor, 0);
  unk_CA5658 |= 2u;
  dword_CA55C8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderPassInfo>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA55C8, (int)&unk_CA5E00);
  Phyre_PObject_SetField68(dword_CA55C8, (int)&unk_CA5E20);
  Phyre_PObject_SetField6C(dword_CA55C8, (int)&unk_CA5E40);
  unk_CA5658 &= ~2u;
  dword_CA55C8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderPassInfo>::`vftable';
  return atexit(sub_AFEA30);
}

