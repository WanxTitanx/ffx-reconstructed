// Function: sub_A265F0
// Address: 0xa265f0
// Size: 0xb5
// Prototype: 

void __thiscall sub_A265F0(_DWORD *this, int a2)
{
  unsigned int v3; // esi
  unsigned int v4; // ecx
  _DWORD *v5; // eax
  int v6; // eax

  if ( a2 )
  {
    v3 = 0;
    v4 = *(this + 2) & 0x7FFFFFFF;
    if ( v4 )
    {
      v5 = (_DWORD *)*(this + 3);
      while ( *v5 )
      {
        ++v3;
        ++v5;
        if ( v3 >= v4 )
          goto LABEL_6;
      }
      *(_DWORD *)(*(this + 3) + 4 * v3) = a2;
      sub_A28F30(*this);
      if ( *(_DWORD *)(*(this + 3) + 4 * v3) )
        sub_A28F40(*(this + 6), *(this + 11) - *(this + 7) - *(this + 9), *(this + 8), *(this + 9));
    }
    else
    {
LABEL_6:
      sub_A28F30(*this);
      sub_A28F40(*(this + 6), *(this + 11) - *(this + 7) - *(this + 9), *(this + 8), *(this + 9));
      v6 = sub_42FC60(4 * ((*(this + 2) & 0x7FFFFFFF) + 1), 4);
      sub_A26480(v6, &a2);
    }
  }
}

