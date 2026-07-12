// Function: sub_B001F0
// Address: 0xb001f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B001F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA9D38;
  v1 = (_DWORD *)unk_CA9D3C;
  *(_DWORD *)(dword_CA9D38 + 4) = unk_CA9D3C;
  *v1 = v0;
  dword_CA9D38 = &dword_CA9D38;
  unk_CA9D3C = &dword_CA9D38;
  if ( (unk_CA9D48 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA9D44);
}

