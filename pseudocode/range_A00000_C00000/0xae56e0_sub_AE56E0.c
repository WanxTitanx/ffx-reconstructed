// Function: sub_AE56E0
// Address: 0xae56e0
// Size: 0xb5
// Prototype: 

int sub_AE56E0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA44C8, (int)Registry, (int)"PShadowCaster", 104, 4, (int)GlobalTypeAccessor, 0);
  unk_CA4558 |= 2u;
  dword_CA44C8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShadowCaster>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA44C8, (int)&unk_CA47A0);
  Phyre_PObject_SetField68(dword_CA44C8, (int)&unk_CA4810);
  Phyre_PObject_SetField6C(dword_CA44C8, (int)&unk_CA4880);
  unk_CA4558 &= ~2u;
  dword_CA44C8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShadowCaster>::`vftable';
  return atexit(sub_AFE4A0);
}

