// Function: sub_A1B980
// Address: 0xa1b980
// Size: 0x1e
// Prototype: 

int __thiscall sub_A1B980(_BYTE *this, int a2, int a3)
{
  int result; // eax

  if ( !*(this + 16) )
    return 0;
  result = sub_A235F0(a2, a3);
  if ( !result )
    return 0;
  return result;
}

