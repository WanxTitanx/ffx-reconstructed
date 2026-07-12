// Function: sub_AFA200
// Address: 0xafa200
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA200()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C90CA8;
  v1 = (_DWORD *)unk_C90CAC;
  *(_DWORD *)(dword_C90CA8 + 4) = unk_C90CAC;
  *v1 = v0;
  dword_C90CA8 = &dword_C90CA8;
  unk_C90CAC = &dword_C90CA8;
  if ( (unk_C90CB8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C90CB4);
}

