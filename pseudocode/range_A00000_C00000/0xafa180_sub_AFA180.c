// Function: sub_AFA180
// Address: 0xafa180
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA180()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C90CD0;
  v1 = (_DWORD *)unk_C90CD4;
  *(_DWORD *)(dword_C90CD0 + 4) = unk_C90CD4;
  *v1 = v0;
  dword_C90CD0 = &dword_C90CD0;
  unk_C90CD4 = &dword_C90CD0;
  if ( (unk_C90CE0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C90CDC);
}

