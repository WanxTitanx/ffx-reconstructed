// Function: sub_AE5F30
// Address: 0xae5f30
// Size: 0xb5
// Prototype: 

int sub_AE5F30()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA51D0, (int)Registry, (int)"PMaterialSwitch", 8, 4, (int)GlobalTypeAccessor, 0);
  unk_CA5260 |= 2u;
  dword_CA51D0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PMaterialSwitch>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA51D0, (int)&unk_CA5470);
  Phyre_PObject_SetField68(dword_CA51D0, (int)&unk_CA5480);
  Phyre_PObject_SetField6C(dword_CA51D0, (int)&unk_CA5490);
  unk_CA5260 &= ~2u;
  dword_CA51D0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PMaterialSwitch>::`vftable';
  return atexit(sub_AFE950);
}

