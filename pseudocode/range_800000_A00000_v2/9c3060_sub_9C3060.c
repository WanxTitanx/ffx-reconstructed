// Function: sub_9C3060
// Address: 0x9c3060
int __thiscall sub_9C3060(_DWORD *this)
{
  int result; // eax

  *this = &btKinematicCharacterController::`vftable';
  result = *(this + 39);
  if ( result )
  {
    if ( *((_BYTE *)this + 160) )
      result = sub_9D4D50(result);
    *(this + 39) = 0;
  }
  *((_BYTE *)this + 160) = 1;
  *(this + 39) = 0;
  *(this + 37) = 0;
  *(this + 38) = 0;
  *this = &btActionInterface::`vftable';
  return result;
}
