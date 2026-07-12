// Function: sub_B05690
// Address: 0xb05690
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05690()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0DE4;
  v1 = (_DWORD *)unk_CC0DE8;
  *(_DWORD *)(dword_CC0DE4 + 4) = unk_CC0DE8;
  *v1 = v0;
  dword_CC0DE4 = &dword_CC0DE4;
  unk_CC0DE8 = &dword_CC0DE4;
  if ( (unk_CC0DF4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0DF0);
}

