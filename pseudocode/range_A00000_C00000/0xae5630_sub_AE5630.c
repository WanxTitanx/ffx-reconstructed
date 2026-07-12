// Function: sub_AE5630
// Address: 0xae5630
// Size: 0xa4
// Prototype: 

int sub_AE5630()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA4168, (int)Registry, (int)"PRenderTargetBase", 16, 16, (int)GlobalTypeAccessor, 0);
  unk_CA41F8 |= 2u;
  dword_CA4168[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PRenderTargetBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA4168, (int)&unk_CA42F0);
  Phyre_PObject_SetField68(dword_CA4168, (int)&unk_CA4300);
  Phyre_PObject_SetField6C(dword_CA4168, (int)&unk_CA4310);
  return atexit(sub_AFE460);
}

