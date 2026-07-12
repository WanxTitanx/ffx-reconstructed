// Function: sub_AF0910
// Address: 0xaf0910
// Size: 0xb4
// Prototype: 

int sub_AF0910()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CDEF00,
    (int)Registry,
    (int)"DynamicMeshDefaultImplmenetation",
    28,
    4,
    (int)dword_C9A7D0,
    0);
  unk_CDEF90 |= 2u;
  dword_CDEF00[0] = &Phyre::PClassDescriptorAbstract<Phyre::DynamicMeshDefaultImplmenetation>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CDEF00, (int)&unk_CDF040);
  Phyre_PObject_SetField68(dword_CDEF00, (int)&unk_CDF060);
  Phyre_PObject_SetField6C(dword_CDEF00, (int)&unk_CDF080);
  unk_CDEF90 &= ~2u;
  dword_CDEF00[0] = &Phyre::PClassDescriptorConcrete<Phyre::DynamicMeshDefaultImplmenetation>::`vftable';
  return atexit(sub_B07620);
}

