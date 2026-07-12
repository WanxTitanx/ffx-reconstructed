// Function: sub_AE10F0
// Address: 0xae10f0
// Size: 0xa6
// Prototype: 

int sub_AE10F0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C92358, (int)Registry, (int)"PCameraProjection", 340, 16, (int)&unk_C922C0, 4);
  unk_C923E8 |= 2u;
  dword_C92358[0] = &Phyre::PClassDescriptorAbstract<Phyre::PCameraProjection>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C92358, (int)&unk_C928C0);
  Phyre_PObject_SetField68(dword_C92358, (int)&unk_C92A20);
  Phyre_PObject_SetField6C(dword_C92358, (int)&unk_C92B80);
  return atexit(sub_AFAA20);
}

