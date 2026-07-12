// Function: sub_B051F0
// Address: 0xb051f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B051F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0DBC;
  v1 = (_DWORD *)unk_CC0DC0;
  *(_DWORD *)(dword_CC0DBC + 4) = unk_CC0DC0;
  *v1 = v0;
  dword_CC0DBC = &dword_CC0DBC;
  unk_CC0DC0 = &dword_CC0DBC;
  if ( (unk_CC0DCC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0DC8);
}

