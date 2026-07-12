// Function: sub_AE1260
// Address: 0xae1260
// Size: 0xb7
// Prototype: 

int sub_AE1260()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C93608, (int)Registry, (int)"PCameraPerspective", 344, 4, (int)dword_C92358, 0);
  unk_C93698 |= 2u;
  dword_C93608[0] = &Phyre::PClassDescriptorAbstract<Phyre::PCameraPerspective>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C93608, (int)&unk_C936D0);
  Phyre_PObject_SetField68(dword_C93608, (int)&unk_C93830);
  Phyre_PObject_SetField6C(dword_C93608, (int)&unk_C93990);
  unk_C93698 &= ~2u;
  dword_C93608[0] = &Phyre::PClassDescriptorConcrete<Phyre::PCameraPerspective>::`vftable';
  return atexit(sub_AFAD00);
}

