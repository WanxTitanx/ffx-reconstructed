// Function: sub_AFDE70
// Address: 0xafde70
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFDE70()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA2C34;
  v1 = (_DWORD *)unk_CA2C38;
  *(_DWORD *)(dword_CA2C34 + 4) = unk_CA2C38;
  *v1 = v0;
  dword_CA2C34 = &dword_CA2C34;
  unk_CA2C38 = &dword_CA2C34;
  if ( (unk_CA2C44 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA2C40);
}

