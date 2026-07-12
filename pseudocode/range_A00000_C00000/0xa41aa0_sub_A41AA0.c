// Function: sub_A41AA0
// Address: 0xa41aa0
// Size: 0x67
// Prototype: 

unsigned int __thiscall sub_A41AA0(_DWORD *this, unsigned int a2)
{
  int v2; // esi
  unsigned int result; // eax
  int v4; // esi
  unsigned int v5; // edx
  unsigned int n0x3FFFFFFF; // edx

  v2 = *(this + 1);
  result = (*(this + 2) - v2) >> 2;
  if ( result < a2 )
  {
    v4 = (v2 - *this) >> 2;
    if ( 0x3FFFFFFF - v4 < a2 )
      std::_Xlength_error("vector<T> too long");
    v5 = (*(this + 2) - *this) >> 2;
    if ( 0x3FFFFFFF - (v5 >> 1) >= v5 )
      n0x3FFFFFFF = (v5 >> 1) + v5;
    else
      n0x3FFFFFFF = 0;
    if ( n0x3FFFFFFF < v4 + a2 )
      n0x3FFFFFFF = v4 + a2;
    return (unsigned int)sub_A41A10((int)this, n0x3FFFFFFF);
  }
  return result;
}

