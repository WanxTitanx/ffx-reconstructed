// Function: sub_B03FA0
// Address: 0xb03fa0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B03FA0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CBADDC;
  v1 = (_DWORD *)unk_CBADE0;
  *(_DWORD *)(dword_CBADDC + 4) = unk_CBADE0;
  *v1 = v0;
  dword_CBADDC = &dword_CBADDC;
  unk_CBADE0 = &dword_CBADDC;
  if ( (unk_CBADEC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CBADE8);
}

