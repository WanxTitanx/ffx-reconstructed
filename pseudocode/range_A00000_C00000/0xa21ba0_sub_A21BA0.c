// Function: sub_A21BA0
// Address: 0xa21ba0
// Size: 0x9c
// Prototype: 

int __thiscall sub_A21BA0(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // ecx
  int v8; // edx
  int result; // eax
  _DWORD *v10; // eax
  int *v11; // eax
  int v12; // eax

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
      {
        result = sub_A139C0(a2, a4);
        if ( !result )
        {
          v11 = (int *)*(this + 42);
          if ( *((_BYTE *)v11 + 4) )
            v12 = 0;
          else
            v12 = *v11;
          return sub_A1D2B0(a2, a3, a4, v12, 1);
        }
      }
      else
      {
        return 21;
      }
    }
    else
    {
      return 5;
    }
  }
  return result;
}

