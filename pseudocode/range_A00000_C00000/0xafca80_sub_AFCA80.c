// Function: sub_AFCA80
// Address: 0xafca80
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFCA80()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C99F48;
  v1 = (_DWORD *)unk_C99F4C;
  *(_DWORD *)(dword_C99F48 + 4) = unk_C99F4C;
  *v1 = v0;
  dword_C99F48 = &dword_C99F48;
  unk_C99F4C = &dword_C99F48;
  if ( (unk_C99F58 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C99F54);
}

