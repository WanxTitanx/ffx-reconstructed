// Function: sub_A3F280
// Address: 0xa3f280
// Size: 0x44
// Prototype: 

_DWORD *__thiscall sub_A3F280(_DWORD *this, unsigned int *a2)
{
  _DWORD *this_1; // edx
  unsigned int v4; // esi
  unsigned int v5; // eax
  int v6; // ecx

  this_1 = (_DWORD *)*(this + 3);
  if ( this_1 == this )
    return 0;
  v4 = *a2;
  while ( 1 )
  {
    v5 = this_1[3];
    if ( v5 <= v4 )
      break;
    v6 = 1;
LABEL_7:
    this_1 = (_DWORD *)this_1[v6 < 0];
    if ( this_1 == this )
      return 0;
  }
  if ( v5 < v4 )
  {
    v6 = -1;
    goto LABEL_7;
  }
  return this_1;
}

