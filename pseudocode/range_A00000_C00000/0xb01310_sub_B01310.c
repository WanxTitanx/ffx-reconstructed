// Function: sub_B01310
// Address: 0xb01310
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01310()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADE08;
  v1 = (_DWORD *)unk_CADE0C;
  *(_DWORD *)(dword_CADE08 + 4) = unk_CADE0C;
  *v1 = v0;
  dword_CADE08 = &dword_CADE08;
  unk_CADE0C = &dword_CADE08;
  if ( (unk_CADE18 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADE14);
}

