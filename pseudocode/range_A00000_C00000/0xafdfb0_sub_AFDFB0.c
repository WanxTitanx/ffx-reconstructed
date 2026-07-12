// Function: sub_AFDFB0
// Address: 0xafdfb0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFDFB0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA2C5C;
  v1 = (_DWORD *)unk_CA2C60;
  *(_DWORD *)(dword_CA2C5C + 4) = unk_CA2C60;
  *v1 = v0;
  dword_CA2C5C = &dword_CA2C5C;
  unk_CA2C60 = &dword_CA2C5C;
  if ( (unk_CA2C6C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA2C68);
}

