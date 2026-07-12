// Function: sub_A26C50
// Address: 0xa26c50
// Size: 0x3f
// Prototype: 

void __thiscall sub_A26C50(_DWORD *this, int a2)
{
  int v2; // eax
  unsigned int v3; // edx
  _DWORD *i_1; // edi
  _DWORD *i; // ecx

  if ( a2 )
  {
    v2 = 0;
    v3 = *(this + 2) & 0x7FFFFFFF;
    if ( v3 )
    {
      i_1 = (_DWORD *)*(this + 3);
      for ( i = i_1; *i != a2; ++i )
      {
        if ( ++v2 >= v3 )
          return;
      }
      i_1[v2] = 0;
    }
  }
}

