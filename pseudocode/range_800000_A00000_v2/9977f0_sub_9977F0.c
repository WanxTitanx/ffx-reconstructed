// Function: sub_9977F0
// Address: 0x9977f0
void __thiscall sub_9977F0(int this)
{
  *(_DWORD *)this = &btConvexTriangleCallback::`vftable';
  (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 52) + 16))(
    *(_DWORD *)(this + 52),
    *(_DWORD *)(this + 68));
  (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 52) + 12))(
    *(_DWORD *)(this + 52),
    *(_DWORD *)(this + 68));
  sub_98ACB0((_DWORD *)this);
}
