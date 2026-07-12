// Function: sub_B08160
// Address: 0xb08160
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B08160()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_1941C8C;
  v1 = (_DWORD *)unk_1941C90;
  *(_DWORD *)(dword_1941C8C + 4) = unk_1941C90;
  *v1 = v0;
  dword_1941C8C = &dword_1941C8C;
  unk_1941C90 = &dword_1941C8C;
  if ( (unk_1941C9C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_1941C98);
}

