// Function: sub_B030B0
// Address: 0xb030b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B030B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB25F0;
  v1 = (_DWORD *)unk_CB25F4;
  *(_DWORD *)(dword_CB25F0 + 4) = unk_CB25F4;
  *v1 = v0;
  dword_CB25F0 = &dword_CB25F0;
  unk_CB25F4 = &dword_CB25F0;
  if ( (unk_CB2600 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB25FC);
}

