// Function: sub_A3D240
// Address: 0xa3d240
// Size: 0x34
// Prototype: int(void)

int sub_A3D240()
{
  int v0; // esi
  int result; // eax

  v0 = unk_1A858C4;
  if ( unk_1A858C4 )
  {
    if ( *(_DWORD *)(unk_1A858C4 + 4) )
    {
      sub_5B5A20(sub_A34B00, sub_A37960);
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v0 + 4) + 8))(*(_DWORD *)(v0 + 4));
      return FFX_Ps3Tex_ListClear(*(_DWORD *)(v0 + 4));
    }
  }
  return result;
}

