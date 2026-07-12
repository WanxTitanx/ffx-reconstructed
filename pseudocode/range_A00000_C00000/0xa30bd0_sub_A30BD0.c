// Function: sub_A30BD0
// Address: 0xa30bd0
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A30BD0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::POccluderGeometry::POccluderGeometryInstance>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

