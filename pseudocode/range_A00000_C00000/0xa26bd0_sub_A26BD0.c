// Function: sub_A26BD0
// Address: 0xa26bd0
// Size: 0x5a
// Prototype: 

int __thiscall sub_A26BD0(_DWORD *this, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int result; // eax

  result = a7;
  if ( *(this + 6) != a2
    || *(this + 7) != a3
    || *(this + 8) != a4
    || *(this + 9) != a5
    || *(this + 10) != a6
    || *(this + 11) != a7 )
  {
    *(this + 6) = a2;
    *(this + 7) = a3;
    *(this + 8) = a4;
    *(this + 9) = a5;
    *(this + 10) = a6;
    *(this + 11) = a7;
    return sub_A265A0(this);
  }
  return result;
}

