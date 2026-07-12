// Function: sub_AF2F70
// Address: 0xaf2f70
// Size: 0xb7
// Prototype: 

int sub_AF2F70()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1943848, (int)Registry, (int)"PDepthOfFieldBase", 4016, 4, (int)dword_19435E8, 0);
  unk_19438D8 |= 2u;
  dword_1943848[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PDepthOfFieldBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1943848, (int)&unk_1969200);
  Phyre_PObject_SetField68(dword_1943848, (int)&unk_196A1B0);
  Phyre_PObject_SetField6C(dword_1943848, (int)&unk_196B160);
  unk_19438D8 &= ~2u;
  dword_1943848[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PDepthOfFieldBase>::`vftable';
  return atexit(sub_B08730);
}

