// Function: sub_B00270
// Address: 0xb00270
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B00270()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA9CBC;
  v1 = (_DWORD *)unk_CA9CC0;
  *(_DWORD *)(dword_CA9CBC + 4) = unk_CA9CC0;
  *v1 = v0;
  dword_CA9CBC = &dword_CA9CBC;
  unk_CA9CC0 = &dword_CA9CBC;
  if ( (unk_CA9CCC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA9CC8);
}

