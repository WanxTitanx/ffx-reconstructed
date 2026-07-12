// Function: sub_A34670
// Address: 0xa34670
// Size: 0x67
// Prototype: 

int __thiscall sub_A34670(int *this, unsigned int a2)
{
  unsigned int v3; // ecx
  _DWORD *v4; // eax
  _DWORD *v5; // ebx

  v3 = *this & 0x7FFFFFFF;
  if ( a2 != *this )
  {
    if ( a2 < v3 )
      v3 = a2;
    v4 = sub_A334D0(a2, (_DWORD *)*(this + 1), v3);
    v5 = v4;
    if ( !v4 && a2 )
      return 13;
    if ( (_DWORD *)*(this + 1) != v4 && *this >= 0 )
      Phyre_Memory_AlignedFree(*(this + 1));
    *(this + 1) = (int)v5;
    *this = a2;
  }
  return 0;
}

