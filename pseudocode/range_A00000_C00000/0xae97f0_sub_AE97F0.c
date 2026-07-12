// Function: sub_AE97F0
// Address: 0xae97f0
// Size: 0xa3
// Prototype: 

int sub_AE97F0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CAF780, (int)Registry, (int)"PScriptableComponent", 32, 16, (int)dword_C91C18, 4);
  unk_CAF810 |= 2u;
  dword_CAF780[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGameplay::PScriptableComponent>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAF780, (int)&unk_CAF870);
  Phyre_PObject_SetField68(dword_CAF780, (int)&unk_CAF890);
  Phyre_PObject_SetField6C(dword_CAF780, (int)&unk_CAF8B0);
  return atexit(sub_B020E0);
}

