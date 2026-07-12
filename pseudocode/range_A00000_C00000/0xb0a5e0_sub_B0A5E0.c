// Function: sub_B0A5E0
// Address: 0xb0a5e0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B0A5E0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_1A85510;
  v1 = (_DWORD *)unk_1A85514;
  *(_DWORD *)(dword_1A85510 + 4) = unk_1A85514;
  *v1 = v0;
  dword_1A85510 = &dword_1A85510;
  unk_1A85514 = &dword_1A85510;
  if ( (unk_1A85520 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_1A8551C);
}

