// Function: sub_A3F340
// Address: 0xa3f340
// Size: 0x7f
// Prototype: 

_DWORD *__thiscall sub_A3F340(_DWORD *this, _DWORD *a2)
{
  _DWORD *this_2; // esi
  _DWORD *this_1; // ecx
  bool v4; // bl
  unsigned int v5; // edx
  unsigned int v6; // eax
  int v7; // eax

  a2[2] += 1 - (a2[2] & 1);
  this_2 = this + 3;
  *a2 = this;
  a2[1] = this;
  this_1 = (_DWORD *)*(this + 3);
  v4 = 0;
  if ( this_1 == this )
  {
LABEL_8:
    a2[2] = (char *)this_2 + (a2[2] & 1);
    this_2[v4] = a2;
    return 0;
  }
  v5 = a2[3];
  while ( 1 )
  {
    v6 = this_1[3];
    this_2 = this_1;
    if ( v6 <= v5 )
      break;
    v7 = 1;
LABEL_7:
    v4 = v7 < 0;
    this_1 = (_DWORD *)this_1[v7 < 0];
    if ( this_1 == this )
      goto LABEL_8;
  }
  if ( v6 < v5 )
  {
    v7 = -1;
    goto LABEL_7;
  }
  return this_1;
}

