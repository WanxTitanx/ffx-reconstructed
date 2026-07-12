// Function: sub_B03270
// Address: 0xb03270
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B03270()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB23E8;
  v1 = (_DWORD *)unk_CB23EC;
  *(_DWORD *)(dword_CB23E8 + 4) = unk_CB23EC;
  *v1 = v0;
  dword_CB23E8 = &dword_CB23E8;
  unk_CB23EC = &dword_CB23E8;
  if ( (unk_CB23F8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB23F4);
}

