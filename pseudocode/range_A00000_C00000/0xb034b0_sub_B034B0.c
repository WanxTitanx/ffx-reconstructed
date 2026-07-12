// Function: sub_B034B0
// Address: 0xb034b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B034B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB25C8;
  v1 = (_DWORD *)unk_CB25CC;
  *(_DWORD *)(dword_CB25C8 + 4) = unk_CB25CC;
  *v1 = v0;
  dword_CB25C8 = &dword_CB25C8;
  unk_CB25CC = &dword_CB25C8;
  if ( (unk_CB25D8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB25D4);
}

