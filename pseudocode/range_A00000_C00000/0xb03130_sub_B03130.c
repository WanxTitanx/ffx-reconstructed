// Function: sub_B03130
// Address: 0xb03130
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B03130()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB2640;
  v1 = (_DWORD *)unk_CB2644;
  *(_DWORD *)(dword_CB2640 + 4) = unk_CB2644;
  *v1 = v0;
  dword_CB2640 = &dword_CB2640;
  unk_CB2644 = &dword_CB2640;
  if ( (unk_CB2650 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB264C);
}

