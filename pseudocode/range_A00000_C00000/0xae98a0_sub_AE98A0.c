// Function: sub_AE98A0
// Address: 0xae98a0
// Size: 0xb4
// Prototype: 

int sub_AE98A0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CAF8D0, (int)Registry, (int)"PScriptedComponent", 48, 4, (int)dword_CAF780, 0);
  unk_CAF960 |= 2u;
  dword_CAF8D0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGameplay::PScriptedComponent>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAF8D0, (int)&unk_CAFAD0);
  Phyre_PObject_SetField68(dword_CAF8D0, (int)&unk_CAFB00);
  Phyre_PObject_SetField6C(dword_CAF8D0, (int)&unk_CAFB30);
  unk_CAF960 &= ~2u;
  dword_CAF8D0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGameplay::PScriptedComponent>::`vftable';
  return atexit(sub_B02120);
}

