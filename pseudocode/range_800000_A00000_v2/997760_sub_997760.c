// Function: sub_997760
// Address: 0x997760
int __thiscall sub_997760(char *this)
{
  char *v2; // esi

  *(_DWORD *)this = &btConvexConcaveCollisionAlgorithm::`vftable';
  v2 = this + 16;
  *((_DWORD *)this + 4) = &btConvexTriangleCallback::`vftable';
  (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this + 17) + 16))(
    *((_DWORD *)this + 17),
    *((_DWORD *)this + 21));
  (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)v2 + 13) + 12))(*((_DWORD *)v2 + 13), *((_DWORD *)v2 + 17));
  sub_98ACB0(v2);
  return sub_9A8280(this);
}
