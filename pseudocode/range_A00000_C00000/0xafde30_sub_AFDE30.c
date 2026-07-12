// Function: sub_AFDE30
// Address: 0xafde30
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFDE30()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA2CD4;
  v1 = (_DWORD *)unk_CA2CD8;
  *(_DWORD *)(dword_CA2CD4 + 4) = unk_CA2CD8;
  *v1 = v0;
  dword_CA2CD4 = &dword_CA2CD4;
  unk_CA2CD8 = &dword_CA2CD4;
  if ( (unk_CA2CE4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA2CE0);
}

