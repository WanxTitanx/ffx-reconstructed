// Function: sub_B06230
// Address: 0xb06230
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B06230()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC9FBC;
  v1 = (_DWORD *)unk_CC9FC0;
  *(_DWORD *)(dword_CC9FBC + 4) = unk_CC9FC0;
  *v1 = v0;
  dword_CC9FBC = &dword_CC9FBC;
  unk_CC9FC0 = &dword_CC9FBC;
  if ( (unk_CC9FCC & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_CC9FC8);
}

