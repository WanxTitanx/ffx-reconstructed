// Function: sub_AE23A0
// Address: 0xae23a0
// Size: 0xb4
// Prototype: 

int sub_AE23A0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C99330, (int)Registry, (int)"PMeshSegment", 108, 4, (int)&unk_CB0FF0, 0);
  unk_C993C0 |= 2u;
  dword_C99330[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PMeshSegment>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C99330, (int)&unk_C99770);
  Phyre_PObject_SetField68(dword_C99330, (int)&unk_C997E0);
  Phyre_PObject_SetField6C(dword_C99330, (int)&unk_C99850);
  unk_C993C0 &= ~2u;
  dword_C99330[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PMeshSegment>::`vftable';
  return atexit(sub_AFC6C0);
}

