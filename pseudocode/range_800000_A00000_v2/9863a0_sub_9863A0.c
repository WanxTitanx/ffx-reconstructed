// Function: sub_9863A0
// Address: 0x9863a0
int __thiscall sub_9863A0(_DWORD *this)
{
  int v2; // eax

  *this = &btGhostObject::`vftable';
  v2 = *(this + 71);
  if ( v2 )
  {
    if ( *((_BYTE *)this + 288) )
      sub_9D4D50(v2);
    *(this + 71) = 0;
  }
  *((_BYTE *)this + 288) = 1;
  *(this + 71) = 0;
  *(this + 69) = 0;
  *(this + 70) = 0;
  return sub_97A040(this);
}
