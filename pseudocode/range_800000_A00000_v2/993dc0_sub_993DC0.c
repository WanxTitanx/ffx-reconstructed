// Function: sub_993DC0
// Address: 0x993dc0
void __thiscall sub_993DC0(int this)
{
  *(_DWORD *)this = &btConvexConvexAlgorithm::`vftable';
  if ( *(_BYTE *)(this + 16) && *(_DWORD *)(this + 20) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 4) + 12))(
      *(_DWORD *)(this + 4),
      *(_DWORD *)(this + 20));
  sub_9A8280((_DWORD *)this);
}
