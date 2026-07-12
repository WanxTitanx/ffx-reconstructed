// Function: sub_B052F0
// Address: 0xb052f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B052F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC12D0;
  v1 = (_DWORD *)unk_CC12D4;
  *(_DWORD *)(dword_CC12D0 + 4) = unk_CC12D4;
  *v1 = v0;
  dword_CC12D0 = &dword_CC12D0;
  unk_CC12D4 = &dword_CC12D0;
  if ( (unk_CC12E0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC12DC);
}

