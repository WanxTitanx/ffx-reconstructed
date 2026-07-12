// Function: sub_AE2760
// Address: 0xae2760
// Size: 0xb5
// Prototype: 

int sub_AE2760()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C99BE8,
    (int)Registry,
    (int)"PSkeletonJointBounds",
    32,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_C99C78 |= 2u;
  dword_C99BE8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PSkeletonJointBounds>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C99BE8, (int)&unk_C9A510);
  Phyre_PObject_SetField68(dword_C99BE8, (int)&unk_C9A530);
  Phyre_PObject_SetField6C(dword_C99BE8, (int)&unk_C9A550);
  unk_C99C78 &= ~2u;
  dword_C99BE8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PSkeletonJointBounds>::`vftable';
  return atexit(sub_AFC970);
}

