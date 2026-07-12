// Function: sub_99E1F0
// Address: 0x99e1f0
void __thiscall sub_99E1F0(int this)
{
  *(_DWORD *)this = &btSphereTriangleCollisionAlgorithm::`vftable';
  if ( *(_BYTE *)(this + 8) && *(_DWORD *)(this + 12) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 4) + 12))(
      *(_DWORD *)(this + 4),
      *(_DWORD *)(this + 12));
  sub_9A8280((_DWORD *)this);
}
