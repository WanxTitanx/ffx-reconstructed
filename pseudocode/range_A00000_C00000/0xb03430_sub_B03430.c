// Function: sub_B03430
// Address: 0xb03430
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B03430()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB24D8;
  v1 = (_DWORD *)unk_CB24DC;
  *(_DWORD *)(dword_CB24D8 + 4) = unk_CB24DC;
  *v1 = v0;
  dword_CB24D8 = &dword_CB24D8;
  unk_CB24DC = &dword_CB24D8;
  if ( (unk_CB24E8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB24E4);
}

