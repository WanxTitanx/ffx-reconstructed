// Function: sub_AFDEF0
// Address: 0xafdef0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFDEF0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA2D74;
  v1 = (_DWORD *)unk_CA2D78;
  *(_DWORD *)(dword_CA2D74 + 4) = unk_CA2D78;
  *v1 = v0;
  dword_CA2D74 = &dword_CA2D74;
  unk_CA2D78 = &dword_CA2D74;
  if ( (unk_CA2D84 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA2D80);
}

