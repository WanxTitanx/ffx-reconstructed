// Function: sub_987800
// Address: 0x987800
void __thiscall sub_987800(_DWORD *this)
{
  if ( *(this + 3) )
  {
    if ( *((_BYTE *)this + 16) )
      sub_9D4D50(*(this + 3));
    *(this + 3) = 0;
  }
  *((_BYTE *)this + 16) = 1;
  *(this + 3) = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
}
