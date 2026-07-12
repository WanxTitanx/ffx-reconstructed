// Function: sub_A3FFE0
// Address: 0xa3ffe0
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A3FFE0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::POccluderGeometry::POccluderGeometryObject>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

