// Function: sub_AF2310
// Address: 0xaf2310
// Size: 0xb4
// Prototype: 

int sub_AF2310()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1940F90, (int)Registry, (int)"PInputSourceTouchPinch", 24, 4, (int)dword_1940AD0, 0);
  unk_1941020 |= 2u;
  dword_1940F90[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceTouchPinch>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1940F90, (int)&unk_1942340);
  Phyre_PObject_SetField68(dword_1940F90, (int)&unk_1942360);
  Phyre_PObject_SetField6C(dword_1940F90, (int)&unk_1942380);
  unk_1941020 &= ~2u;
  dword_1940F90[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceTouchPinch>::`vftable';
  return atexit(sub_B08080);
}

