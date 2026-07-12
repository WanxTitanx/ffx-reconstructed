// Function: sub_98AF90
// Address: 0x98af90
_DWORD *__thiscall sub_98AF90(_DWORD *this, char a2)
{
  *this = &btTriangleMeshShape::`vftable';
  sub_993AC0();
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
