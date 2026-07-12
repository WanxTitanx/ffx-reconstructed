// Function: sub_AE2520
// Address: 0xae2520
// Size: 0xb5
// Prototype: 

int sub_AE2520()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C99200, (int)Registry, (int)"PSkinBoneRemap", 4, 2, (int)GlobalTypeAccessor, 0);
  unk_C99290 |= 2u;
  dword_C99200[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PSkinBoneRemap>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C99200, (int)&unk_C996B0);
  Phyre_PObject_SetField68(dword_C99200, (int)&unk_C996C0);
  Phyre_PObject_SetField6C(dword_C99200, (int)&unk_C996D0);
  unk_C99290 &= ~2u;
  dword_C99200[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PSkinBoneRemap>::`vftable';
  return atexit(sub_AFC700);
}

