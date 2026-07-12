// Function: sub_AFF410
// Address: 0xaff410
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFF410()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA7928;
  v1 = (_DWORD *)unk_CA792C;
  *(_DWORD *)(dword_CA7928 + 4) = unk_CA792C;
  *v1 = v0;
  dword_CA7928 = &dword_CA7928;
  unk_CA792C = &dword_CA7928;
  if ( (unk_CA7938 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA7934);
}

