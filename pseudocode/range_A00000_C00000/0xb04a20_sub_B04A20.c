// Function: sub_B04A20
// Address: 0xb04a20
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B04A20()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CBDAD8;
  v1 = (_DWORD *)unk_CBDADC;
  *(_DWORD *)(dword_CBDAD8 + 4) = unk_CBDADC;
  *v1 = v0;
  dword_CBDAD8 = &dword_CBDAD8;
  unk_CBDADC = &dword_CBDAD8;
  if ( (unk_CBDAE8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CBDAE4);
}

