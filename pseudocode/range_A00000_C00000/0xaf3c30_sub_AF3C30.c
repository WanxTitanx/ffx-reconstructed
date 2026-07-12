// Function: sub_AF3C30
// Address: 0xaf3c30
// Size: 0xb7
// Prototype: 

int sub_AF3C30()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1943AA8, (int)Registry, (int)"PMotionBlur", 3408, 4, (int)dword_1943B40, 0);
  unk_1943B38 |= 2u;
  dword_1943AA8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PMotionBlur>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1943AA8, (int)&unk_1976F70);
  Phyre_PObject_SetField68(dword_1943AA8, (int)&unk_1977CC0);
  Phyre_PObject_SetField6C(dword_1943AA8, (int)&unk_1978A10);
  unk_1943B38 &= ~2u;
  dword_1943AA8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PMotionBlur>::`vftable';
  return atexit(sub_B08950);
}

