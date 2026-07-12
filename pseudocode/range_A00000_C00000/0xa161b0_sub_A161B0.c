// Function: sub_A161B0
// Address: 0xa161b0
// Size: 0xd
// Prototype: int __thiscall(_DWORD)

int __thiscall sub_A161B0(_DWORD *this)
{
  int v1; // eax

  v1 = *(this + 2);
  if ( v1 )
    return *(_DWORD *)v1;
  else
    return 0;
}

