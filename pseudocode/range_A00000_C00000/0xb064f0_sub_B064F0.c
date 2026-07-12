// Function: sub_B064F0
// Address: 0xb064f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B064F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CCA1E4;
  v1 = (_DWORD *)unk_CCA1E8;
  *(_DWORD *)(dword_CCA1E4 + 4) = unk_CCA1E8;
  *v1 = v0;
  dword_CCA1E4 = &dword_CCA1E4;
  unk_CCA1E8 = &dword_CCA1E4;
  if ( (unk_CCA1F4 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_CCA1F0);
}

