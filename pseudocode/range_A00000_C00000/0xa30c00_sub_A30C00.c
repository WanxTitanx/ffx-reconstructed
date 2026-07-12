// Function: sub_A30C00
// Address: 0xa30c00
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A30C00(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::POccluderGeometry::POccluderGeometryInstance>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

