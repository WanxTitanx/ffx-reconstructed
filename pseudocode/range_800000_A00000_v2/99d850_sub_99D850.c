// Function: sub_99D850
// Address: 0x99d850
_BYTE *__thiscall sub_99D850(_BYTE *this, int a2, int a3, int a4, int a5)
{
  sub_9A8260(a3, a4, a5);
  *(_DWORD *)this = &btBoxBoxCollisionAlgorithm::`vftable';
  *(this + 8) = 0;
  *((_DWORD *)this + 3) = a2;
  if ( !a2
    && (*(unsigned __int8 (__thiscall **)(_DWORD, int, int))(**((_DWORD **)this + 1) + 20))(
         *((_DWORD *)this + 1),
         a4,
         a5) )
  {
    *((_DWORD *)this + 3) = (*(int (__thiscall **)(_DWORD, int, int))(**((_DWORD **)this + 1) + 8))(
                              *((_DWORD *)this + 1),
                              a4,
                              a5);
    *(this + 8) = 1;
  }
  return this;
}
