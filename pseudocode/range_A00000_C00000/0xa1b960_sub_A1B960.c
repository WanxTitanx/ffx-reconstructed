// Function: sub_A1B960
// Address: 0xa1b960
// Size: 0x1e
// Prototype: 

int __thiscall sub_A1B960(_BYTE *this, int a2, int a3)
{
  int result; // eax

  if ( !*(this + 16) )
    return 0;
  result = sub_A23280(a2, a3);
  if ( !result )
    return 0;
  return result;
}

