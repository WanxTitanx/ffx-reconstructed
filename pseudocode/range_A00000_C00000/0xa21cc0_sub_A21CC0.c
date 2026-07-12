// Function: sub_A21CC0
// Address: 0xa21cc0
// Size: 0x2f
// Prototype: 

int __thiscall sub_A21CC0(_BYTE *this, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // edx
  int v7; // esi
  int result; // eax

  if ( *(this + 16) )
    return 0;
  if ( a4 )
  {
    v6 = *(_DWORD *)(a4 + 32);
    v7 = *(_DWORD *)(a4 + 28);
  }
  else
  {
    v6 = 0;
    v7 = 0;
  }
  result = (*(int (__thiscall **)(_BYTE *, int, int))(*(_DWORD *)this + 4))(this, v7, v6);
  if ( !result )
    return 0;
  return result;
}

