// Function: sub_B051A0
// Address: 0xb051a0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B051A0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC1398;
  v1 = (_DWORD *)unk_CC139C;
  *(_DWORD *)(dword_CC1398 + 4) = unk_CC139C;
  *v1 = v0;
  dword_CC1398 = &dword_CC1398;
  unk_CC139C = &dword_CC1398;
  if ( (unk_CC13A8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC13A4);
}

