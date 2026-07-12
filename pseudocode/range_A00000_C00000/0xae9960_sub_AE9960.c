// Function: sub_AE9960
// Address: 0xae9960
// Size: 0xb4
// Prototype: 

int sub_AE9960()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CAFB70, (int)Registry, (int)"PTimerComponent", 44, 4, (int)dword_CAF780, 0);
  unk_CAFC00 |= 2u;
  dword_CAFB70[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGameplay::PTimerComponent>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAFB70, (int)&unk_CAFCD0);
  Phyre_PObject_SetField68(dword_CAFB70, (int)&unk_CAFD00);
  Phyre_PObject_SetField6C(dword_CAFB70, (int)&unk_CAFD30);
  unk_CAFC00 &= ~2u;
  dword_CAFB70[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGameplay::PTimerComponent>::`vftable';
  return atexit(sub_B02280);
}

