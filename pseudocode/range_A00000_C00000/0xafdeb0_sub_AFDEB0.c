// Function: sub_AFDEB0
// Address: 0xafdeb0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFDEB0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA2CFC;
  v1 = (_DWORD *)unk_CA2D00;
  *(_DWORD *)(dword_CA2CFC + 4) = unk_CA2D00;
  *v1 = v0;
  dword_CA2CFC = &dword_CA2CFC;
  unk_CA2D00 = &dword_CA2CFC;
  if ( (unk_CA2D0C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA2D08);
}

