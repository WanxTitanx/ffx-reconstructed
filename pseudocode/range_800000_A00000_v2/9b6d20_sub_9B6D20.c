// Function: sub_9B6D20
// Address: 0x9b6d20
int __thiscall sub_9B6D20(_BYTE *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  *(_DWORD *)this = &btDiscreteDynamicsWorld::`vftable';
  if ( *(this + 244) )
  {
    (***((void (__thiscall ****)(_DWORD, _DWORD))this + 45))(*((_DWORD *)this + 45), 0);
    sub_9D4D50(*((_DWORD *)this + 45));
  }
  if ( *(this + 245) )
  {
    (***((void (__thiscall ****)(_DWORD, _DWORD))this + 44))(*((_DWORD *)this + 44), 0);
    sub_9D4D50(*((_DWORD *)this + 44));
  }
  v2 = *((_DWORD *)this + 65);
  if ( v2 )
  {
    if ( *(this + 264) )
      sub_9D4D50(v2);
    *((_DWORD *)this + 65) = 0;
  }
  *(this + 264) = 1;
  *((_DWORD *)this + 65) = 0;
  *((_DWORD *)this + 63) = 0;
  *((_DWORD *)this + 64) = 0;
  v3 = *((_DWORD *)this + 54);
  if ( v3 )
  {
    if ( *(this + 220) )
      sub_9D4D50(v3);
    *((_DWORD *)this + 54) = 0;
  }
  *(this + 220) = 1;
  *((_DWORD *)this + 54) = 0;
  *((_DWORD *)this + 52) = 0;
  *((_DWORD *)this + 53) = 0;
  v4 = *((_DWORD *)this + 49);
  if ( v4 )
  {
    if ( *(this + 200) )
      sub_9D4D50(v4);
    *((_DWORD *)this + 49) = 0;
  }
  *(this + 200) = 1;
  *((_DWORD *)this + 49) = 0;
  *((_DWORD *)this + 47) = 0;
  *((_DWORD *)this + 48) = 0;
  *(_DWORD *)this = &btDynamicsWorld::`vftable';
  return sub_97C4A0();
}
