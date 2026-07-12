// Function: sub_997940
// Address: 0x997940
int __thiscall sub_997940(int this, char a2)
{
  *(_DWORD *)this = &btConvexTriangleCallback::`vftable';
  (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 52) + 16))(
    *(_DWORD *)(this + 52),
    *(_DWORD *)(this + 68));
  (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 52) + 12))(
    *(_DWORD *)(this + 52),
    *(_DWORD *)(this + 68));
  sub_98ACB0((_DWORD *)this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free((void *)this);
  return this;
}
