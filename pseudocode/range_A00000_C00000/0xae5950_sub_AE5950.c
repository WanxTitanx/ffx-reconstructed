// Function: sub_AE5950
// Address: 0xae5950
// Size: 0xb5
// Prototype: 

int sub_AE5950()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA4BC8, (int)Registry, (int)"PNodeContext", 8, 4, (int)GlobalTypeAccessor, 0);
  unk_CA4C58 |= 2u;
  dword_CA4BC8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PNodeContext>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA4BC8, (int)&unk_CA4DC0);
  Phyre_PObject_SetField68(dword_CA4BC8, (int)&unk_CA4DD0);
  Phyre_PObject_SetField6C(dword_CA4BC8, (int)&unk_CA4DE0);
  unk_CA4C58 &= ~2u;
  dword_CA4BC8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PNodeContext>::`vftable';
  return atexit(sub_AFE690);
}

