// Function: sub_AFA980
// Address: 0xafa980
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA980()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C92178;
  v1 = (_DWORD *)unk_C9217C;
  *(_DWORD *)(dword_C92178 + 4) = unk_C9217C;
  *v1 = v0;
  dword_C92178 = &dword_C92178;
  unk_C9217C = &dword_C92178;
  if ( (unk_C92188 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C92184);
}

