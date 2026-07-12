// Function: sub_98AE70
// Address: 0x98ae70
_DWORD *__thiscall sub_98AE70(_DWORD *this, int a2)
{
  sub_993AA0();
  *this = &btTriangleMeshShape::`vftable';
  *(this + 12) = a2;
  *(this + 1) = 21;
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)a2 + 36))(a2) )
    (*(void (__thiscall **)(int, _DWORD *, _DWORD *))(*(_DWORD *)a2 + 44))(a2, this + 4, this + 8);
  else
    sub_98B8C0(this);
  return this;
}
