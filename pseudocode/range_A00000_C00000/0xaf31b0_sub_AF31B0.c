// Function: sub_AF31B0
// Address: 0xaf31b0
// Size: 0xb4
// Prototype: 

int sub_AF31B0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1944510, (int)Registry, (int)"PFXAABase", 112, 4, (int)dword_19435E8, 0);
  unk_19445A0 |= 2u;
  dword_1944510[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PFXAABase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1944510, (int)&unk_1984260);
  Phyre_PObject_SetField68(dword_1944510, (int)&unk_19842D0);
  Phyre_PObject_SetField6C(dword_1944510, (int)&unk_1984340);
  unk_19445A0 &= ~2u;
  dword_1944510[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PFXAABase>::`vftable';
  return atexit(sub_B08790);
}

