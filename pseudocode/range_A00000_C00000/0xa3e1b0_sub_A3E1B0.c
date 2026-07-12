// Function: sub_A3E1B0
// Address: 0xa3e1b0
// Size: 0x3a
// Prototype: 

int __thiscall sub_A3E1B0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  if ( !*(this + 4) )
    return -1;
  if ( a2 )
  {
    *a2 = *(this + 2);
    a2[1] = *(this + 3);
  }
  if ( a3 )
  {
    *a3 = *(this + 2);
    a3[1] = *(this + 3);
  }
  return 0;
}

