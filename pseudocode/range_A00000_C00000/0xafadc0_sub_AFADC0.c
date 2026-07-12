// Function: sub_AFADC0
// Address: 0xafadc0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFADC0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C93BD0;
  v1 = (_DWORD *)unk_C93BD4;
  *(_DWORD *)(dword_C93BD0 + 4) = unk_C93BD4;
  *v1 = v0;
  dword_C93BD0 = &dword_C93BD0;
  unk_C93BD4 = &dword_C93BD0;
  if ( (unk_C93BE0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C93BDC);
}

