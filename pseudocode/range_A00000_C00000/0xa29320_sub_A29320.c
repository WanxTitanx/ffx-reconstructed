// Function: sub_A29320
// Address: 0xa29320
// Size: 0x39
// Prototype: 

int __thiscall sub_A29320(_DWORD *this, _DWORD *a2, unsigned int a3)
{
  int result; // eax
  unsigned int v4; // edx
  _DWORD *i; // ecx

  result = a3;
  v4 = *this & 0x7FFFFFFF;
  if ( a3 >= v4 )
    return -1;
  for ( i = (_DWORD *)(*(this + 1) + 48 * a3); *i != *a2; i += 12 )
  {
    if ( ++result >= v4 )
      return -1;
  }
  return result;
}

