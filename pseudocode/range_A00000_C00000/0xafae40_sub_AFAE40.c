// Function: sub_AFAE40
// Address: 0xafae40
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFAE40()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C93B7C;
  v1 = (_DWORD *)unk_C93B80;
  *(_DWORD *)(dword_C93B7C + 4) = unk_C93B80;
  *v1 = v0;
  dword_C93B7C = &dword_C93B7C;
  unk_C93B80 = &dword_C93B7C;
  if ( (unk_C93B8C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C93B88);
}

