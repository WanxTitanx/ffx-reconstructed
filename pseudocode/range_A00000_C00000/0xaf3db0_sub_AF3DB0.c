// Function: sub_AF3DB0
// Address: 0xaf3db0
// Size: 0xb7
// Prototype: 

int sub_AF3DB0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1943B40, (int)Registry, (int)"PMotionBlurD3D11", 3408, 4, (int)dword_1943A10, 0);
  unk_1943BD0 |= 2u;
  dword_1943B40[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PMotionBlurD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1943B40, (int)&unk_1974780);
  Phyre_PObject_SetField68(dword_1943B40, (int)&unk_19754D0);
  Phyre_PObject_SetField6C(dword_1943B40, (int)&unk_1976220);
  unk_1943BD0 &= ~2u;
  dword_1943B40[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PMotionBlurD3D11>::`vftable';
  return atexit(sub_B08990);
}

