// Function: sub_A16100
// Address: 0xa16100
// Size: 0x44
// Prototype: 

int __thiscall sub_A16100(_DWORD *this)
{
  int v2; // esi
  _DWORD **v3; // ecx

  v2 = 0;
  if ( (*this & 0x7FFFFFFF) == 0 )
    return 0;
  while ( 1 )
  {
    v3 = *(_DWORD ***)(*(this + 1) + 4 * v2);
    if ( v3[1] == dword_1943718 )
    {
      if ( ((unsigned __int8 (__thiscall *)(_DWORD **))(*v3)[4])(v3) )
        break;
    }
    if ( ++v2 >= (*this & 0x7FFFFFFFu) )
      return 0;
  }
  return *(_DWORD *)(*(this + 1) + 4 * v2);
}

