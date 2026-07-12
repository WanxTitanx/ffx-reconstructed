// Function: sub_AF2EB0
// Address: 0xaf2eb0
// Size: 0xb7
// Prototype: 

int sub_AF2EB0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_19438E0, (int)Registry, (int)"PDepthOfField", 4032, 4, (int)dword_1943978, 0);
  unk_1943970 |= 2u;
  dword_19438E0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PDepthOfField>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_19438E0, (int)&unk_196F050);
  Phyre_PObject_SetField68(dword_19438E0, (int)&unk_1970010);
  Phyre_PObject_SetField6C(dword_19438E0, (int)&unk_1970FD0);
  unk_1943970 &= ~2u;
  dword_19438E0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PDepthOfField>::`vftable';
  return atexit(sub_B08710);
}

