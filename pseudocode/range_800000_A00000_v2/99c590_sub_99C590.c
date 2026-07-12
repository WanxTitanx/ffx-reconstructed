// Function: sub_99C590
// Address: 0x99c590
_DWORD *__thiscall sub_99C590(_DWORD *this, int a2, int a3, int a4, int a5, char a6, int a7, int a8)
{
  int v9; // edi
  int v10; // ebx

  sub_9A9B20(a3);
  v9 = a5;
  v10 = a4;
  if ( a6 )
  {
    v10 = a5;
    v9 = a4;
  }
  *(this + 5) = a7;
  *this = &btConvexPlaneCollisionAlgorithm::`vftable';
  *((_BYTE *)this + 8) = 0;
  *(this + 3) = a2;
  *((_BYTE *)this + 16) = a6;
  *(this + 6) = a8;
  if ( !a2 && (*(unsigned __int8 (__thiscall **)(_DWORD, int, int))(*(_DWORD *)*(this + 1) + 20))(*(this + 1), v10, v9) )
  {
    *(this + 3) = (*(int (__thiscall **)(_DWORD, int, int))(*(_DWORD *)*(this + 1) + 8))(*(this + 1), v10, v9);
    *((_BYTE *)this + 8) = 1;
  }
  return this;
}
