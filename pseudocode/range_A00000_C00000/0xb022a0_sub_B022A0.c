// Function: sub_B022A0
// Address: 0xb022a0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B022A0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAFC30;
  v1 = (_DWORD *)unk_CAFC34;
  *(_DWORD *)(dword_CAFC30 + 4) = unk_CAFC34;
  *v1 = v0;
  dword_CAFC30 = &dword_CAFC30;
  unk_CAFC34 = &dword_CAFC30;
  if ( (unk_CAFC40 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAFC3C);
}

