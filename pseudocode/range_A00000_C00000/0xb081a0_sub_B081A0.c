// Function: sub_B081A0
// Address: 0xb081a0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B081A0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_1941CB4;
  v1 = (_DWORD *)unk_1941CB8;
  *(_DWORD *)(dword_1941CB4 + 4) = unk_1941CB8;
  *v1 = v0;
  dword_1941CB4 = &dword_1941CB4;
  unk_1941CB8 = &dword_1941CB4;
  if ( (unk_1941CC4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_1941CC0);
}

