// Function: sub_B028E0
// Address: 0xb028e0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B028E0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB0C8C;
  v1 = (_DWORD *)unk_CB0C90;
  *(_DWORD *)(dword_CB0C8C + 4) = unk_CB0C90;
  *v1 = v0;
  dword_CB0C8C = &dword_CB0C8C;
  unk_CB0C90 = &dword_CB0C8C;
  if ( (unk_CB0C9C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB0C98);
}

