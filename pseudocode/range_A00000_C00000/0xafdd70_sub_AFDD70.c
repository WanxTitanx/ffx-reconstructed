// Function: sub_AFDD70
// Address: 0xafdd70
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFDD70()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA2D4C;
  v1 = (_DWORD *)unk_CA2D50;
  *(_DWORD *)(dword_CA2D4C + 4) = unk_CA2D50;
  *v1 = v0;
  dword_CA2D4C = &dword_CA2D4C;
  unk_CA2D50 = &dword_CA2D4C;
  if ( (unk_CA2D5C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA2D58);
}

