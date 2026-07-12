// Function: sub_AFF750
// Address: 0xaff750
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFF750()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA797C;
  v1 = (_DWORD *)unk_CA7980;
  *(_DWORD *)(dword_CA797C + 4) = unk_CA7980;
  *v1 = v0;
  dword_CA797C = &dword_CA797C;
  unk_CA7980 = &dword_CA797C;
  if ( (unk_CA798C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA7988);
}

