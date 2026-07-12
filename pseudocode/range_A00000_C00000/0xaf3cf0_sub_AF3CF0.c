// Function: sub_AF3CF0
// Address: 0xaf3cf0
// Size: 0xb7
// Prototype: 

int sub_AF3CF0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1943A10, (int)Registry, (int)"PMotionBlurBase", 3404, 4, (int)dword_19435E8, 0);
  unk_1943AA0 |= 2u;
  dword_1943A10[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PMotionBlurBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1943A10, (int)&unk_1971F90);
  Phyre_PObject_SetField68(dword_1943A10, (int)&unk_1972CE0);
  Phyre_PObject_SetField6C(dword_1943A10, (int)&unk_1973A30);
  unk_1943AA0 &= ~2u;
  dword_1943A10[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PMotionBlurBase>::`vftable';
  return atexit(sub_B08970);
}

