// Function: sub_9BCCD0
// Address: 0x9bccd0
int __thiscall sub_9BCCD0(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int result; // eax

  *this = &btSequentialImpulseConstraintSolver::`vftable';
  v2 = *(this + 29);
  if ( v2 )
  {
    if ( *((_BYTE *)this + 120) )
      sub_9D4D50(v2);
    *(this + 29) = 0;
  }
  *((_BYTE *)this + 120) = 1;
  *(this + 29) = 0;
  *(this + 27) = 0;
  *(this + 28) = 0;
  v3 = *(this + 24);
  if ( v3 )
  {
    if ( *((_BYTE *)this + 100) )
      sub_9D4D50(v3);
    *(this + 24) = 0;
  }
  *((_BYTE *)this + 100) = 1;
  *(this + 24) = 0;
  *(this + 22) = 0;
  *(this + 23) = 0;
  v4 = *(this + 19);
  if ( v4 )
  {
    if ( *((_BYTE *)this + 80) )
      sub_9D4D50(v4);
    *(this + 19) = 0;
  }
  *((_BYTE *)this + 80) = 1;
  *(this + 19) = 0;
  *(this + 17) = 0;
  *(this + 18) = 0;
  v5 = *(this + 14);
  if ( v5 )
  {
    if ( *((_BYTE *)this + 60) )
      sub_9D4D50(v5);
    *(this + 14) = 0;
  }
  *((_BYTE *)this + 60) = 1;
  *(this + 14) = 0;
  *(this + 12) = 0;
  *(this + 13) = 0;
  v6 = *(this + 9);
  if ( v6 )
  {
    if ( *((_BYTE *)this + 40) )
      sub_9D4D50(v6);
    *(this + 9) = 0;
  }
  *((_BYTE *)this + 40) = 1;
  *(this + 9) = 0;
  *(this + 7) = 0;
  *(this + 8) = 0;
  result = *(this + 4);
  if ( result )
  {
    if ( *((_BYTE *)this + 20) )
      result = sub_9D4D50(result);
    *(this + 4) = 0;
  }
  *((_BYTE *)this + 20) = 1;
  *(this + 4) = 0;
  *(this + 2) = 0;
  *(this + 3) = 0;
  *this = &btConstraintSolver::`vftable';
  return result;
}
