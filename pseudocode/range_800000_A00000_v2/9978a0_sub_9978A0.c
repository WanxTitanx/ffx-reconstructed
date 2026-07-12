// Function: sub_9978A0
// Address: 0x9978a0
char *__thiscall sub_9978A0(char *this, char a2)
{
  char *v3; // esi

  *(_DWORD *)this = &btConvexConcaveCollisionAlgorithm::`vftable';
  v3 = this + 16;
  *((_DWORD *)this + 4) = &btConvexTriangleCallback::`vftable';
  (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this + 17) + 16))(
    *((_DWORD *)this + 17),
    *((_DWORD *)this + 21));
  (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)v3 + 13) + 12))(*((_DWORD *)v3 + 13), *((_DWORD *)v3 + 17));
  sub_98ACB0(v3);
  sub_9A8280(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
