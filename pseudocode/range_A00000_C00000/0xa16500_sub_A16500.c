// Function: sub_A16500
// Address: 0xa16500
// Size: 0x28
// Prototype: 

int __thiscall sub_A16500(_DWORD *this, unsigned int a2)
{
  int v2; // eax

  if ( a2 < (*this & 0x7FFFFFFFu) && (v2 = *(_DWORD *)(*(this + 1) + 4 * a2)) != 0 )
    return v2 + 4;
  else
    return 0;
}

