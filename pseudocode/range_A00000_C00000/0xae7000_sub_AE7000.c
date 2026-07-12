// Function: sub_AE7000
// Address: 0xae7000
// Size: 0xb4
// Prototype: 

int sub_AE7000()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA8298, (int)Registry, (int)"PSceneWideParameterBuffer", 8, 4, (int)dword_CA4FA8, 0);
  unk_CA8328 |= 2u;
  dword_CA8298[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PSceneWideParameterBuffer>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA8298, (int)&unk_CA8970);
  Phyre_PObject_SetField68(dword_CA8298, (int)&unk_CA8980);
  Phyre_PObject_SetField6C(dword_CA8298, (int)&unk_CA8990);
  unk_CA8328 &= ~2u;
  dword_CA8298[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PSceneWideParameterBuffer>::`vftable';
  return atexit(sub_AFF880);
}

