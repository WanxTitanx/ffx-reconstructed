// Function: sub_AFF390
// Address: 0xaff390
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFF390()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA78B0;
  v1 = (_DWORD *)unk_CA78B4;
  *(_DWORD *)(dword_CA78B0 + 4) = unk_CA78B4;
  *v1 = v0;
  dword_CA78B0 = &dword_CA78B0;
  unk_CA78B4 = &dword_CA78B0;
  if ( (unk_CA78C0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA78BC);
}

