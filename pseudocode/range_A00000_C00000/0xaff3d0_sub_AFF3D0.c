// Function: sub_AFF3D0
// Address: 0xaff3d0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFF3D0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA7888;
  v1 = (_DWORD *)unk_CA788C;
  *(_DWORD *)(dword_CA7888 + 4) = unk_CA788C;
  *v1 = v0;
  dword_CA7888 = &dword_CA7888;
  unk_CA788C = &dword_CA7888;
  if ( (unk_CA7898 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA7894);
}

