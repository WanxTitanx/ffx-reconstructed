// Function: sub_AFA0D0
// Address: 0xafa0d0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA0D0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = unk_C90AAC;
  v1 = (_DWORD *)unk_C90AB0;
  *(_DWORD *)(unk_C90AAC + 4) = unk_C90AB0;
  *v1 = v0;
  unk_C90AAC = &unk_C90AAC;
  unk_C90AB0 = &unk_C90AAC;
  if ( (unk_C90ABC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C90AB8);
}

