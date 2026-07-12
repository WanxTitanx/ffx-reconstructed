// Function: sub_AE11A0
// Address: 0xae11a0
// Size: 0xb7
// Prototype: 

int sub_AE11A0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C930E8, (int)Registry, (int)"PCameraOrthographic", 344, 4, (int)dword_C92358, 0);
  unk_C93178 |= 2u;
  dword_C930E8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PCameraOrthographic>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C930E8, (int)&unk_C931F0);
  Phyre_PObject_SetField68(dword_C930E8, (int)&unk_C93350);
  Phyre_PObject_SetField6C(dword_C930E8, (int)&unk_C934B0);
  unk_C93178 &= ~2u;
  dword_C930E8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PCameraOrthographic>::`vftable';
  return atexit(sub_AFAC90);
}

