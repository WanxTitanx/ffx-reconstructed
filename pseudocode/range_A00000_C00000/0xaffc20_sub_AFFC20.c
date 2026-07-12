// Function: sub_AFFC20
// Address: 0xaffc20
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFFC20()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA92B8;
  v1 = (_DWORD *)unk_CA92BC;
  *(_DWORD *)(dword_CA92B8 + 4) = unk_CA92BC;
  *v1 = v0;
  dword_CA92B8 = &dword_CA92B8;
  unk_CA92BC = &dword_CA92B8;
  if ( (unk_CA92C8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA92C4);
}

