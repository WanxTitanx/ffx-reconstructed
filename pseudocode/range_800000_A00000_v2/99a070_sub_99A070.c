// Function: sub_99A070
// Address: 0x99a070
int __thiscall sub_99A070(_DWORD *this)
{
  int v2; // eax

  *this = &btCompoundCollisionAlgorithm::`vftable';
  sub_99C2C0();
  v2 = *(this + 5);
  if ( v2 )
  {
    if ( *((_BYTE *)this + 24) )
      sub_9D4D50(v2);
    *(this + 5) = 0;
  }
  *((_BYTE *)this + 24) = 1;
  *(this + 5) = 0;
  *(this + 3) = 0;
  *(this + 4) = 0;
  return sub_9A8280(this);
}
