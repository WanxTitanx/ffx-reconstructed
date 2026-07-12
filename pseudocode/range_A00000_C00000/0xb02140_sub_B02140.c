// Function: sub_B02140
// Address: 0xb02140
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02140()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAFA90;
  v1 = (_DWORD *)unk_CAFA94;
  *(_DWORD *)(dword_CAFA90 + 4) = unk_CAFA94;
  *v1 = v0;
  dword_CAFA90 = &dword_CAFA90;
  unk_CAFA94 = &dword_CAFA90;
  if ( (unk_CAFAA0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAFA9C);
}

