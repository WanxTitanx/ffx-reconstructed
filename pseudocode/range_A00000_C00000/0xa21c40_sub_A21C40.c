// Function: sub_A21C40
// Address: 0xa21c40
// Size: 0x7b
// Prototype: 

int __thiscall sub_A21C40(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // ecx
  int v8; // edx
  int result; // eax
  _DWORD *v10; // eax

  if ( *((_BYTE *)this + 16)
    || (!a4 ? (v7 = 0, v8 = 0) : (v7 = *(_DWORD *)(a4 + 32), v8 = *(_DWORD *)(a4 + 28)),
        (result = (*(int (__thiscall **)(_DWORD *, int, int))(*this + 4))(this, v8, v7)) == 0) )
  {
    if ( a4 )
    {
      if ( *(this + 2) != *(this + 3) )
        (*(void (__thiscall **)(_DWORD *))(*this + 8))(this);
      v10 = (_DWORD *)*(this + 2);
      if ( v10 && *v10 )
        return sub_A1EB10(a2, a3, *(_DWORD *)(a2 + 92), a4, a5);
      else
        return 21;
    }
    else
    {
      return 5;
    }
  }
  return result;
}

