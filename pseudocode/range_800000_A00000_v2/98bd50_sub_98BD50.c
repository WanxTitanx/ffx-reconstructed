// Function: sub_98BD50
// Address: 0x98bd50
int __thiscall sub_98BD50(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int result; // eax

  *this = &btQuantizedBvh::`vftable';
  v2 = *(this + 43);
  if ( v2 )
  {
    if ( *((_BYTE *)this + 176) )
      sub_9D4D50(v2);
    *(this + 43) = 0;
  }
  *((_BYTE *)this + 176) = 1;
  *(this + 43) = 0;
  *(this + 41) = 0;
  *(this + 42) = 0;
  v3 = *(this + 37);
  if ( v3 )
  {
    if ( *((_BYTE *)this + 152) )
      sub_9D4D50(v3);
    *(this + 37) = 0;
  }
  *((_BYTE *)this + 152) = 1;
  *(this + 37) = 0;
  *(this + 35) = 0;
  *(this + 36) = 0;
  v4 = *(this + 32);
  if ( v4 )
  {
    if ( *((_BYTE *)this + 132) )
      sub_9D4D50(v4);
    *(this + 32) = 0;
  }
  *((_BYTE *)this + 132) = 1;
  *(this + 32) = 0;
  *(this + 30) = 0;
  *(this + 31) = 0;
  v5 = *(this + 27);
  if ( v5 )
  {
    if ( *((_BYTE *)this + 112) )
      sub_9D4D50(v5);
    *(this + 27) = 0;
  }
  *((_BYTE *)this + 112) = 1;
  *(this + 27) = 0;
  *(this + 25) = 0;
  *(this + 26) = 0;
  result = *(this + 22);
  if ( result )
  {
    if ( *((_BYTE *)this + 92) )
      result = sub_9D4D50(result);
    *(this + 22) = 0;
  }
  *((_BYTE *)this + 92) = 1;
  *(this + 22) = 0;
  *(this + 20) = 0;
  *(this + 21) = 0;
  return result;
}
