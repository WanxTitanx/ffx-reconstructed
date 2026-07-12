// Function: sub_9B4680
// Address: 0x9b4680
int __thiscall sub_9B4680(_DWORD *this)
{
  int v2; // eax

  *this = &btRigidBody::`vftable';
  v2 = *(this + 129);
  if ( v2 )
  {
    if ( *((_BYTE *)this + 520) )
      sub_9D4D50(v2);
    *(this + 129) = 0;
  }
  *((_BYTE *)this + 520) = 1;
  *(this + 129) = 0;
  *(this + 127) = 0;
  *(this + 128) = 0;
  return sub_97A040(this);
}
