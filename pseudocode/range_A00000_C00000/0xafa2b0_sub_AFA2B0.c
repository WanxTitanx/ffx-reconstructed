// Function: sub_AFA2B0
// Address: 0xafa2b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA2B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C90EC4;
  v1 = (_DWORD *)unk_C90EC8;
  *(_DWORD *)(dword_C90EC4 + 4) = unk_C90EC8;
  *v1 = v0;
  dword_C90EC4 = &dword_C90EC4;
  unk_C90EC8 = &dword_C90EC4;
  if ( (unk_C90ED4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C90ED0);
}

