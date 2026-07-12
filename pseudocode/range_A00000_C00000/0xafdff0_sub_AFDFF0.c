// Function: sub_AFDFF0
// Address: 0xafdff0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFDFF0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA2C84;
  v1 = (_DWORD *)unk_CA2C88;
  *(_DWORD *)(dword_CA2C84 + 4) = unk_CA2C88;
  *v1 = v0;
  dword_CA2C84 = &dword_CA2C84;
  unk_CA2C88 = &dword_CA2C84;
  if ( (unk_CA2C94 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA2C90);
}

