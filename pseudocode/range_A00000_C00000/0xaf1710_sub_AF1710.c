// Function: sub_AF1710
// Address: 0xaf1710
// Size: 0xb4
// Prototype: 

int sub_AF1710()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1940B68, (int)Registry, (int)"PInputSourceKey", 40, 4, (int)dword_1940AD0, 0);
  unk_1940BF8 |= 2u;
  dword_1940B68[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceKey>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1940B68, (int)&unk_1941FE0);
  Phyre_PObject_SetField68(dword_1940B68, (int)&unk_1942010);
  Phyre_PObject_SetField6C(dword_1940B68, (int)&unk_1942040);
  unk_1940BF8 &= ~2u;
  dword_1940B68[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceKey>::`vftable';
  return atexit(sub_B07E80);
}

