// Function: sub_999F40
// Address: 0x999f40
_BYTE *__thiscall sub_999F40(_BYTE *this, int a2, int a3, int a4, char a5)
{
  int v5; // eax

  sub_9A8260(a2, a3, a4);
  *(_DWORD *)this = &btCompoundCollisionAlgorithm::`vftable';
  *(this + 24) = 1;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *(this + 28) = a5;
  *((_DWORD *)this + 8) = *(_DWORD *)(a2 + 4);
  v5 = a3;
  if ( a5 )
    v5 = a4;
  *(this + 36) = 0;
  *((_DWORD *)this + 10) = *(_DWORD *)(*(_DWORD *)(v5 + 204) + 68);
  sub_99B440(a3, a4);
  return this;
}
