// Function: sub_AF4230
// Address: 0xaf4230
// Size: 0xb7
// Prototype: 

int sub_AF4230()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1944770,
    (int)Registry,
    (int)"PScreenSpaceReflection",
    148,
    4,
    (int)dword_1944808,
    0);
  unk_1944800 |= 2u;
  dword_1944770[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PScreenSpaceReflection>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1944770, (int)&unk_1984A10);
  Phyre_PObject_SetField68(dword_1944770, (int)&unk_1984AB0);
  Phyre_PObject_SetField6C(dword_1944770, (int)&unk_1984B50);
  unk_1944800 &= ~2u;
  dword_1944770[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PScreenSpaceReflection>::`vftable';
  return atexit(sub_B08A50);
}

