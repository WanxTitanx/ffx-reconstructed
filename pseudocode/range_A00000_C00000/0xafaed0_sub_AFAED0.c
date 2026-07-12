// Function: sub_AFAED0
// Address: 0xafaed0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFAED0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C93EFC;
  v1 = (_DWORD *)unk_C93F00;
  *(_DWORD *)(dword_C93EFC + 4) = unk_C93F00;
  *v1 = v0;
  dword_C93EFC = &dword_C93EFC;
  unk_C93F00 = &dword_C93EFC;
  if ( (unk_C93F0C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C93F08);
}

