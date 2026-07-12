// Function: sub_AE5CF0
// Address: 0xae5cf0
// Size: 0xc7
// Prototype: 

int sub_AE5CF0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA5040, (int)Registry, (int)"PParameterBuffer", 16, 4, (int)&unk_CA4FA8, 0);
  unk_CA50D0 |= 2u;
  dword_CA5040[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PParameterBuffer>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA5040, (int)&unk_CA51A0);
  Phyre_PObject_SetField68(dword_CA5040, (int)&unk_CA51B0);
  Phyre_PObject_SetField6C(dword_CA5040, (int)&unk_CA51C0);
  dword_CA5040[0] = &Phyre::PClassDescriptorHeaderWithoutDefaultConstructor<Phyre::PRendering::PParameterBuffer>::`vftable';
  psub_4D6D40 = sub_4D6D40;
  unk_CA50D0 = unk_CA50D0 & 0xFFFFFFF1 | 0xC;
  return atexit(sub_AFE8C0);
}

