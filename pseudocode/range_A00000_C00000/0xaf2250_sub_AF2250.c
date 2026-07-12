// Function: sub_AF2250
// Address: 0xaf2250
// Size: 0xb4
// Prototype: 

int sub_AF2250()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_19410C0, (int)Registry, (int)"PInputSourceTouchDragY", 24, 4, (int)dword_1940AD0, 0);
  unk_1941150 |= 2u;
  dword_19410C0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceTouchDragY>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_19410C0, (int)&unk_19424C0);
  Phyre_PObject_SetField68(dword_19410C0, (int)&unk_19424E0);
  Phyre_PObject_SetField6C(dword_19410C0, (int)&unk_1942500);
  unk_1941150 &= ~2u;
  dword_19410C0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceTouchDragY>::`vftable';
  return atexit(sub_B08060);
}

