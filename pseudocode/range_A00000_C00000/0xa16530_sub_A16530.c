// Function: sub_A16530
// Address: 0xa16530
// Size: 0x28
// Prototype: 

int __thiscall sub_A16530(_DWORD *this, unsigned int a2)
{
  int v3; // eax

  if ( a2 < (*this & 0x7FFFFFFFu) && (v3 = *(_DWORD *)(*(this + 1) + 4 * a2)) != 0 )
    return *(_DWORD *)(v3 + 4);
  else
    return 0;
}

