// Function: sub_A1B9B0
// Address: 0xa1b9b0
// Size: 0x1e
// Prototype: 

int __thiscall sub_A1B9B0(_BYTE *this, int a2, int a3)
{
  int result; // eax

  if ( !*(this + 16) )
    return 0;
  result = sub_A23780(a2, a3);
  if ( !result )
    return 0;
  return result;
}

