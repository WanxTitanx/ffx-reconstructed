// Function: sub_A21CF0
// Address: 0xa21cf0
// Size: 0x81
// Prototype: 

int __thiscall sub_A21CF0(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // ecx
  int v8; // edx
  int result; // eax
  _DWORD *v10; // eax

  if ( *((_BYTE *)this + 16)
    || (!a4 ? (v7 = 0, v8 = 0) : (v7 = *(_DWORD *)(a4 + 32), v8 = *(_DWORD *)(a4 + 28)),
        (result = (*(int (__thiscall **)(_DWORD *, int, int))(*this + 4))(this, v8, v7)) == 0) )
  {
    if ( !a4 )
      return 5;
    if ( *(this + 2) != *(this + 3) )
      (*(void (__thiscall **)(_DWORD *))(*this + 8))(this);
    v10 = (_DWORD *)*(this + 2);
    if ( v10 && *v10 )
    {
      if ( !a6 )
        return 5;
      return sub_A220B0(a2, a3, a4, a5, a6);
    }
    else
    {
      return 21;
    }
  }
  return result;
}

