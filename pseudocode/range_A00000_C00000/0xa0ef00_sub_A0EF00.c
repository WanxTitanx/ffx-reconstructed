// Function: sub_A0EF00
// Address: 0xa0ef00
// Size: 0x5f
// Prototype: 

int __thiscall sub_A0EF00(_DWORD *this, int a2, int a3, int a4)
{
  int v5; // ebx
  unsigned int v6; // esi
  int v7; // ecx
  int v8; // ecx

  v5 = 0;
  v6 = 0;
  if ( (*this & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v7 = *(_DWORD *)(*(this + 1) + 4 * v6);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v7 + 16))(v7) )
      {
        v8 = *(_DWORD *)(*(this + 1) + 4 * v6);
        if ( (*(unsigned __int8 (__thiscall **)(int, int, int))(*(_DWORD *)v8 + 20))(v8, a3, a4) )
          *(_DWORD *)(a2 + 4 * v5++) = *(_DWORD *)(*(this + 1) + 4 * v6);
      }
      ++v6;
    }
    while ( v6 < (*this & 0x7FFFFFFFu) );
  }
  return v5;
}

