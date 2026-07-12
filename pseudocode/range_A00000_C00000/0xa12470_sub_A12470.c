// Function: sub_A12470
// Address: 0xa12470
// Size: 0x5e
// Prototype: 

int __thiscall sub_A12470(_DWORD *this, int a2, int a3)
{
  int result; // eax

  if ( !*(this + 4109) )
    return 21;
  result = sub_5BB2D0(0, 0);
  if ( !result )
  {
    result = sub_5BB750(0);
    if ( !result )
    {
      *(_DWORD *)(a3 + 200) = 0;
      return sub_5B6660(*(this + 4110), *(this + 4109));
    }
  }
  return result;
}

