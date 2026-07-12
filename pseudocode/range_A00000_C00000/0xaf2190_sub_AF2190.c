// Function: sub_AF2190
// Address: 0xaf2190
// Size: 0xb4
// Prototype: 

int sub_AF2190()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1941028, (int)Registry, (int)"PInputSourceTouchDragX", 24, 4, (int)dword_1940AD0, 0);
  unk_19410B8 |= 2u;
  dword_1941028[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceTouchDragX>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1941028, (int)&unk_1942460);
  Phyre_PObject_SetField68(dword_1941028, (int)&unk_1942480);
  Phyre_PObject_SetField6C(dword_1941028, (int)&unk_19424A0);
  unk_19410B8 &= ~2u;
  dword_1941028[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceTouchDragX>::`vftable';
  return atexit(sub_B08040);
}

