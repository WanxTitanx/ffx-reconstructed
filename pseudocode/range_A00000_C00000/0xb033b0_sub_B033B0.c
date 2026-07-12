// Function: sub_B033B0
// Address: 0xb033b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B033B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB2500;
  v1 = (_DWORD *)unk_CB2504;
  *(_DWORD *)(dword_CB2500 + 4) = unk_CB2504;
  *v1 = v0;
  dword_CB2500 = &dword_CB2500;
  unk_CB2504 = &dword_CB2500;
  if ( (unk_CB2510 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB250C);
}

