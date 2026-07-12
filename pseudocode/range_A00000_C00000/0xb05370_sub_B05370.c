// Function: sub_B05370
// Address: 0xb05370
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05370()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0D44;
  v1 = (_DWORD *)unk_CC0D48;
  *(_DWORD *)(dword_CC0D44 + 4) = unk_CC0D48;
  *v1 = v0;
  dword_CC0D44 = &dword_CC0D44;
  unk_CC0D48 = &dword_CC0D44;
  if ( (unk_CC0D54 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0D50);
}

