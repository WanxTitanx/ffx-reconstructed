// Function: sub_B03170
// Address: 0xb03170
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B03170()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB25A0;
  v1 = (_DWORD *)unk_CB25A4;
  *(_DWORD *)(dword_CB25A0 + 4) = unk_CB25A4;
  *v1 = v0;
  dword_CB25A0 = &dword_CB25A0;
  unk_CB25A4 = &dword_CB25A0;
  if ( (unk_CB25B0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB25AC);
}

