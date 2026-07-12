// Function: sub_AFC8A0
// Address: 0xafc8a0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFC8A0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C99A04;
  v1 = (_DWORD *)unk_C99A08;
  *(_DWORD *)(dword_C99A04 + 4) = unk_C99A08;
  *v1 = v0;
  dword_C99A04 = &dword_C99A04;
  unk_C99A08 = &dword_C99A04;
  if ( (unk_C99A14 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C99A10);
}

