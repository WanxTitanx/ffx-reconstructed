// Function: sub_AFA8F0
// Address: 0xafa8f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA8F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C92124;
  v1 = (_DWORD *)unk_C92128;
  *(_DWORD *)(dword_C92124 + 4) = unk_C92128;
  *v1 = v0;
  dword_C92124 = &dword_C92124;
  unk_C92128 = &dword_C92124;
  if ( (unk_C92134 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C92130);
}

