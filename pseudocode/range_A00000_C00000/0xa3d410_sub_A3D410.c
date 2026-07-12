// Function: sub_A3D410
// Address: 0xa3d410
// Size: 0xbf
// Prototype: 

char __thiscall sub_A3D410(int *this)
{
  int v2; // edi
  int v3; // ecx
  int v4; // eax
  int v5; // eax

  v2 = unk_1A858C4;
  if ( unk_1A858C4 )
  {
    v3 = *(_DWORD *)(unk_1A858C4 + 4);
    if ( v3 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(v3);
      FFX_Ps3Tex_ListClear(*(_DWORD *)(v2 + 4));
    }
  }
  v4 = *(this + 1);
  if ( v4 )
  {
    if ( *(this + 2) && v4 >= 0 )
      Phyre_Memory_AlignedFree(*(this + 2));
    *(this + 2) = 0;
    *(this + 1) = 0;
  }
  LOBYTE(v5) = ~(*(this + 1) < 0);
  if ( *(this + 1) >= 0 )
  {
    v5 = *(this + 2);
    if ( v5 )
      LOBYTE(v5) = Phyre_Memory_AlignedFree(*(this + 2));
  }
  *(this + 2) = 0;
  *(this + 1) = 0;
  return v5;
}

