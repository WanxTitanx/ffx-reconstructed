// Function: sub_B05DE0
// Address: 0xb05de0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05DE0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0B78;
  v1 = (_DWORD *)unk_CC0B7C;
  *(_DWORD *)(dword_CC0B78 + 4) = unk_CC0B7C;
  *v1 = v0;
  dword_CC0B78 = &dword_CC0B78;
  unk_CC0B7C = &dword_CC0B78;
  if ( (unk_CC0B88 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0B84);
}

