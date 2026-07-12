// Function: sub_AE0CF0
// Address: 0xae0cf0
// Size: 0xc0
// Prototype: 

int sub_AE0CF0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C91330,
    (int)Registry,
    (int)"PClassDescriptorDynamic",
    184,
    4,
    (int)MEMORY[0xC90760],
    0);
  unk_C913C0 |= 2u;
  dword_C91330[0] = &Phyre::PClassDescriptorAbstract<Phyre::PClassDescriptorDynamic>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C91330, (int)&unk_C916F0);
  Phyre_PObject_SetField68(dword_C91330, (int)&unk_C917B0);
  Phyre_PObject_SetField6C(dword_C91330, (int)&unk_C91870);
  dword_C91330[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PClassDescriptorDynamic>::`vftable';
  unk_C913C0 = unk_C913C0 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFA3F0);
}

