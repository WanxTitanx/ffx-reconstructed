// Function: sub_AFFD20
// Address: 0xaffd20
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFFD20()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA92E0;
  v1 = (_DWORD *)unk_CA92E4;
  *(_DWORD *)(dword_CA92E0 + 4) = unk_CA92E4;
  *v1 = v0;
  dword_CA92E0 = &dword_CA92E0;
  unk_CA92E4 = &dword_CA92E0;
  if ( (unk_CA92F0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA92EC);
}

