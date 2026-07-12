// Function: sub_A42520
// Address: 0xa42520
// Size: 0x79
// Prototype: 

int __thiscall sub_A42520(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v4; // esi

  v4 = (_DWORD *)*(this + 6);
  if ( !v4 )
  {
    sub_49C9A0(*(this + 8));
    v4 = (_DWORD *)*(this + 6);
    if ( !v4 )
      return 14;
  }
  *(this + 6) = *v4;
  *v4 = v4;
  v4[1] = v4;
  v4[2] = v4;
  v4[3] = *a2;
  v4[4] = *a3;
  if ( sub_A3F340(this, v4) )
  {
    sub_49CA50(v4);
    return 18;
  }
  else
  {
    sub_574AF0(v4);
    return 0;
  }
}

