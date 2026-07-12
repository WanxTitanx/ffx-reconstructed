// Function: sub_AF39F0
// Address: 0xaf39f0
// Size: 0xb7
// Prototype: 

int sub_AF39F0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1943DF0, (int)Registry, (int)"PMLAABase", 144, 4, (int)dword_19435E8, 0);
  unk_1943E80 |= 2u;
  dword_1943DF0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PMLAABase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1943DF0, (int)&unk_1979910);
  Phyre_PObject_SetField68(dword_1943DF0, (int)&unk_19799A0);
  Phyre_PObject_SetField6C(dword_1943DF0, (int)&unk_1979A30);
  unk_1943E80 &= ~2u;
  dword_1943DF0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PMLAABase>::`vftable';
  return atexit(sub_B088F0);
}

