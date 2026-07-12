// Function: sub_AE7330
// Address: 0xae7330
// Size: 0xb4
// Prototype: 

int sub_AE7330()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA8DC8, (int)Registry, (int)"PStructuredBuffer", 72, 4, (int)&unk_CB3CB0, 0);
  unk_CA8E58 |= 2u;
  dword_CA8DC8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PStructuredBuffer>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA8DC8, (int)&unk_CA8F50);
  Phyre_PObject_SetField68(dword_CA8DC8, (int)&unk_CA8FA0);
  Phyre_PObject_SetField6C(dword_CA8DC8, (int)&unk_CA8FF0);
  unk_CA8E58 &= ~2u;
  dword_CA8DC8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PStructuredBuffer>::`vftable';
  return atexit(sub_AFFA30);
}

