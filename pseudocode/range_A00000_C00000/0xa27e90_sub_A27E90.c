// Function: sub_A27E90
// Address: 0xa27e90
// Size: 0x4e
// Prototype: 

char __thiscall sub_A27E90(_DWORD *this)
{
  int n2; // eax
  int v2; // eax
  int v4; // eax

  n2 = *(this + 57);
  if ( n2 == 1 )
  {
    v2 = *(this + 168);
    *(this + 57) = 2;
    if ( v2 )
    {
      FMOD::Channel::setPaused(v2, 1);
      return 1;
    }
  }
  else if ( n2 == 2 )
  {
    v4 = *(this + 168);
    *(this + 57) = 1;
    if ( v4 )
      FMOD::Channel::setPaused(v4, 0);
  }
  return 1;
}

