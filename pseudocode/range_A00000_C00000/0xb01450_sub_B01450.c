// Function: sub_B01450
// Address: 0xb01450
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01450()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADE30;
  v1 = (_DWORD *)unk_CADE34;
  *(_DWORD *)(dword_CADE30 + 4) = unk_CADE34;
  *v1 = v0;
  dword_CADE30 = &dword_CADE30;
  unk_CADE34 = &dword_CADE30;
  if ( (unk_CADE40 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADE3C);
}

