// Function: sub_AFA7F0
// Address: 0xafa7f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA7F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C91EF0;
  v1 = (_DWORD *)unk_C91EF4;
  *(_DWORD *)(dword_C91EF0 + 4) = unk_C91EF4;
  *v1 = v0;
  dword_C91EF0 = &dword_C91EF0;
  unk_C91EF4 = &dword_C91EF0;
  if ( (unk_C91F00 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C91EFC);
}

