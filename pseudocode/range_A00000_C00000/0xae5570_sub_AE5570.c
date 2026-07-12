// Function: sub_AE5570
// Address: 0xae5570
// Size: 0xbd
// Prototype: 

int sub_AE5570()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA4200, (int)Registry, (int)"PRenderTarget", 40, 4, (int)&unk_CB3B68, 0);
  unk_CA4290 |= 2u;
  dword_CA4200[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PRenderTarget>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA4200, (int)&unk_CA4320);
  Phyre_PObject_SetField68(dword_CA4200, (int)&unk_CA4350);
  Phyre_PObject_SetField6C(dword_CA4200, (int)&unk_CA4380);
  dword_CA4200[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PRenderTarget>::`vftable';
  unk_CA4290 = unk_CA4290 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFE440);
}

