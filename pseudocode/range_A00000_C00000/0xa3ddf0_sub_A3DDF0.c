// Function: sub_A3DDF0
// Address: 0xa3ddf0
// Size: 0x95
// Prototype: _DWORD __stdcall(int n0x100000, int, int (__cdecl *)(int), int (__cdecl *)(int))

BOOL __thiscall sub_A3DDF0(
        int this,
        int n0x100000,
        int a3,
        int (__cdecl *a4)(int),
        int (__cdecl *Phyre_Memory_AlignedFree_2)(int))
{
  int (__cdecl *Phyre_Memory_AlignedFree_1)(int); // eax
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  bool v10; // zf

  PhyreEvent_Create((HANDLE *)(this + 28), 3u);
  *(_BYTE *)(this + 32) = 1;
  PhyreEvent_Create((HANDLE *)(this + 36), 1u);
  Phyre_Memory_AlignedFree_1 = Phyre_Memory_AlignedFree_2;
  *(_BYTE *)(this + 40) = 1;
  *(_DWORD *)(this + 48) = n0x100000 + 8;
  *(_DWORD *)(this + 52) = 0;
  *(_DWORD *)(this + 56) = 0;
  if ( !Phyre_Memory_AlignedFree_2 )
    Phyre_Memory_AlignedFree_1 = Phyre_Memory_AlignedFree;
  *(_DWORD *)(this + 60) = Phyre_Memory_AlignedFree_1;
  v7 = n0x100000 + 8 + a3 + 3;
  if ( a4 )
    v8 = a4(v7);
  else
    v8 = sub_42FC20(v7);
  v9 = *(_DWORD *)(this + 48);
  *(_DWORD *)(this + 4) = v8;
  v9 -= 4;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 8) = v9;
  *(_DWORD *)(v9 + v8) = 0;
  v10 = *(_DWORD *)(this + 4) == 0;
  *(_BYTE *)(this + 44) = 1;
  *(_BYTE *)(this + 24) = 1;
  return !v10;
}

