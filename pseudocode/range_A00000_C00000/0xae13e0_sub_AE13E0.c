// Function: sub_AE13E0
// Address: 0xae13e0
// Size: 0xbd
// Prototype: 

int sub_AE13E0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C93E38, (int)Registry, (int)"PNameComponent", 24, 4, (int)dword_C91C18, 0);
  unk_C93EC8 |= 2u;
  dword_C93E38[0] = &Phyre::PClassDescriptorAbstract<Phyre::PNameComponent>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C93E38, (int)&unk_C93F30);
  Phyre_PObject_SetField68(dword_C93E38, (int)&unk_C93F50);
  Phyre_PObject_SetField6C(dword_C93E38, (int)&unk_C93F70);
  dword_C93E38[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PNameComponent>::`vftable';
  unk_C93EC8 = unk_C93EC8 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFAEB0);
}

