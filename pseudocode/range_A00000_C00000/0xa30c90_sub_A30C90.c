// Function: sub_A30C90
// Address: 0xa30c90
// Size: 0x181
// Prototype: 

_DWORD *sub_A30C90()
{
  int v0; // eax
  int v1; // esi
  _DWORD *v2; // eax

  Phyre_TypeRegistry_Register(Size_5);
  v0 = dword_1A854E0;
  if ( (dword_1A854E0 & 1) == 0 )
  {
    dword_1A854E0 |= 1u;
    Phyre_PClassDataMember_Init(dword_1A854B4, (size_t)Size_5, (int)dword_1A85990, "m_occluder", 0, 2, 0);
    atexit(sub_B0A630);
    v0 = dword_1A854E0;
  }
  if ( (v0 & 2) == 0 )
  {
    dword_1A854E0 = v0 | 2;
    Phyre_PClassDataMember_Init(dword_1A854E4, (size_t)Size_5, (int)&unk_C92090, "m_localToWorldMatrix", 4, 2, 0);
    atexit(sub_B0A620);
    v0 = dword_1A854E0;
  }
  if ( (v0 & 4) == 0 )
  {
    dword_1A854E0 = v0 | 4;
    Phyre_ChainNode_Create(&dword_1A85510, (size_t)Size_5, "getLocalToWorldMatrix", 0);
    p_p____7__PMethodCallerConcrete_VPOccluderGeometryInstance_POcc = 0;
    v1 = (int)(dword_1A85518 + 19);
    if ( dword_1A8551C && !Phyre_Namespace_FindByName(dword_1A85518, dword_1A8551C) )
    {
      v2 = *(_DWORD **)(v1 + 4);
      dword_1A85510 = v1;
      unk_1A85514 = v2;
      *v2 = &dword_1A85510;
      *(_DWORD *)(v1 + 4) = &dword_1A85510;
    }
    atexit(sub_B0A5E0);
  }
  p____7__PMethodCallerConcrete_VPOccluderGeometryInstance_POcclu = &Phyre::PInternal::PCallerImplementation::PCallerImplementation0::PMethodCallerConcrete<Phyre::POccluderGeometry::POccluderGeometryInstance,Phyre::PWorldMatrix *>::`vftable';
  psub_A32220 = sub_A32220;
  p_p____7__PMethodCallerConcrete_VPOccluderGeometryInstance_POcc = &p____7__PMethodCallerConcrete_VPOccluderGeometryInstance_POcclu;
  return Phyre_PClassDescriptor_RegisterWithNamespace((int)Size_5);
}

