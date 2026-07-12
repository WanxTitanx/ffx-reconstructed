// Function: sub_983FF0
// Address: 0x983ff0
int __thiscall sub_983FF0(int **this)
{
  int result; // eax
  int *v3; // ebx
  int v4; // esi
  int v5; // eax

  ((void (__thiscall *)(int **))(*this)[1])(this);
  result = (*(int (__thiscall **)(_DWORD, _DWORD))(**(this + 20) + 28))(*(this + 20), *(this + 6));
  v3 = *(this + 6);
  if ( v3 )
  {
    v4 = *v3;
    v5 = (*(int (__thiscall **)(_DWORD, int **, int *))(**(this + 20) + 36))(*(this + 20), this + 7, v3);
    return (*(int (__thiscall **)(int *, int))(v4 + 28))(v3, v5);
  }
  return result;
}
