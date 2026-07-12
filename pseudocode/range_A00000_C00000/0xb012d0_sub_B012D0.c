// Function: sub_B012D0
// Address: 0xb012d0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B012D0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADD18;
  v1 = (_DWORD *)unk_CADD1C;
  *(_DWORD *)(dword_CADD18 + 4) = unk_CADD1C;
  *v1 = v0;
  dword_CADD18 = &dword_CADD18;
  unk_CADD1C = &dword_CADD18;
  if ( (unk_CADD28 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADD24);
}

