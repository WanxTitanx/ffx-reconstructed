// Function: sub_997650
// Address: 0x997650
_DWORD *__thiscall sub_997650(_DWORD *this, int a2, int a3, int a4, char a5)
{
  int v6; // esi
  int v7; // edi
  int v8; // eax
  int v9; // ecx

  v6 = a4;
  v7 = a3;
  if ( a5 )
  {
    v7 = a4;
    v6 = a3;
  }
  *this = &btConvexTriangleCallback::`vftable';
  *(this + 13) = a2;
  *(this + 14) = 0;
  *(this + 1) = v7;
  *(this + 2) = v6;
  v8 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)a2 + 8))(a2, v7, v6);
  v9 = *(this + 13);
  *(this + 17) = v8;
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 16))(v9, v8);
  return this;
}
