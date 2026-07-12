// Function: sub_B013D0
// Address: 0xb013d0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B013D0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADE58;
  v1 = (_DWORD *)unk_CADE5C;
  *(_DWORD *)(dword_CADE58 + 4) = unk_CADE5C;
  *v1 = v0;
  dword_CADE58 = &dword_CADE58;
  unk_CADE5C = &dword_CADE58;
  if ( (unk_CADE68 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADE64);
}

