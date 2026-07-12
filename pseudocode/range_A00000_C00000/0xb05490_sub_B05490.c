// Function: sub_B05490
// Address: 0xb05490
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05490()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0C78;
  v1 = (_DWORD *)unk_CC0C7C;
  *(_DWORD *)(dword_CC0C78 + 4) = unk_CC0C7C;
  *v1 = v0;
  dword_CC0C78 = &dword_CC0C78;
  unk_CC0C7C = &dword_CC0C78;
  if ( (unk_CC0C88 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0C84);
}

