// Function: sub_9975A0
// Address: 0x9975a0
_BYTE *__thiscall sub_9975A0(_BYTE *this, int *a2, int a3, int a4, char a5)
{
  int v5; // ebx
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // ecx

  v5 = a4;
  sub_9A8260(a2, a3, a4);
  *(_DWORD *)this = &btConvexConcaveCollisionAlgorithm::`vftable';
  *(this + 8) = a5;
  v6 = *a2;
  v7 = a3;
  if ( a5 )
  {
    v7 = a4;
    v5 = a3;
  }
  *((_DWORD *)this + 4) = &btConvexTriangleCallback::`vftable';
  *((_DWORD *)this + 17) = v6;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 5) = v7;
  *((_DWORD *)this + 6) = v5;
  v8 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v6 + 8))(v6, v7, v5);
  v9 = *((_DWORD *)this + 17);
  *((_DWORD *)this + 21) = v8;
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 16))(v9, v8);
  return this;
}
