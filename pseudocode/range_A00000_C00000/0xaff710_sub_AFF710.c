// Function: sub_AFF710
// Address: 0xaff710
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFF710()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA78D8;
  v1 = (_DWORD *)unk_CA78DC;
  *(_DWORD *)(dword_CA78D8 + 4) = unk_CA78DC;
  *v1 = v0;
  dword_CA78D8 = &dword_CA78D8;
  unk_CA78DC = &dword_CA78D8;
  if ( (unk_CA78E8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA78E4);
}

