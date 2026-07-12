// Function: sub_B05510
// Address: 0xb05510
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05510()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC13C0;
  v1 = (_DWORD *)unk_CC13C4;
  *(_DWORD *)(dword_CC13C0 + 4) = unk_CC13C4;
  *v1 = v0;
  dword_CC13C0 = &dword_CC13C0;
  unk_CC13C4 = &dword_CC13C0;
  if ( (unk_CC13D0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC13CC);
}

