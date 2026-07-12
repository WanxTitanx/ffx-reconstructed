// Function: sub_AEED60
// Address: 0xaeed60
// Size: 0xb4
// Prototype: 

int sub_AEED60()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CCBA18, (int)Registry, (int)"ClassDynamicMesh", 28, 4, (int)dword_C9A7D0, 0);
  unk_CCBAA8 |= 2u;
  dword_CCBA18[0] = &Phyre::PClassDescriptorAbstract<ClassDynamicMesh>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CCBA18, (int)&unk_CCBAB0);
  Phyre_PObject_SetField68(dword_CCBA18, (int)&unk_CCBAD0);
  Phyre_PObject_SetField6C(dword_CCBA18, (int)&unk_CCBAF0);
  unk_CCBAA8 &= ~2u;
  dword_CCBA18[0] = &Phyre::PClassDescriptorConcrete<ClassDynamicMesh>::`vftable';
  return atexit(sub_B068E0);
}

