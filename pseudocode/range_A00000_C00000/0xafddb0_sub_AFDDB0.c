// Function: sub_AFDDB0
// Address: 0xafddb0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFDDB0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA2D24;
  v1 = (_DWORD *)unk_CA2D28;
  *(_DWORD *)(dword_CA2D24 + 4) = unk_CA2D28;
  *v1 = v0;
  dword_CA2D24 = &dword_CA2D24;
  unk_CA2D28 = &dword_CA2D24;
  if ( (unk_CA2D34 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA2D30);
}

