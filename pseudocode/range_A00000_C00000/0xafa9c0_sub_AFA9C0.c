// Function: sub_AFA9C0
// Address: 0xafa9c0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA9C0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C92150;
  v1 = (_DWORD *)unk_C92154;
  *(_DWORD *)(dword_C92150 + 4) = unk_C92154;
  *v1 = v0;
  dword_C92150 = &dword_C92150;
  unk_C92154 = &dword_C92150;
  if ( (unk_C92160 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C9215C);
}

