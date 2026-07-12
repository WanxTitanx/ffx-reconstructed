// Function: sub_B01EB0
// Address: 0xb01eb0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01EB0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAEF4C;
  v1 = (_DWORD *)unk_CAEF50;
  *(_DWORD *)(dword_CAEF4C + 4) = unk_CAEF50;
  *v1 = v0;
  dword_CAEF4C = &dword_CAEF4C;
  unk_CAEF50 = &dword_CAEF4C;
  if ( (unk_CAEF5C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAEF58);
}

