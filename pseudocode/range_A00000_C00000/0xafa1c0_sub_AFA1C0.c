// Function: sub_AFA1C0
// Address: 0xafa1c0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA1C0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C90C54;
  v1 = (_DWORD *)unk_C90C58;
  *(_DWORD *)(dword_C90C54 + 4) = unk_C90C58;
  *v1 = v0;
  dword_C90C54 = &dword_C90C54;
  unk_C90C58 = &dword_C90C54;
  if ( (unk_C90C64 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C90C60);
}

