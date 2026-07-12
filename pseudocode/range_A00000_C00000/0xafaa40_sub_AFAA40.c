// Function: sub_AFAA40
// Address: 0xafaa40
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFAA40()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C92810;
  v1 = (_DWORD *)unk_C92814;
  *(_DWORD *)(dword_C92810 + 4) = unk_C92814;
  *v1 = v0;
  dword_C92810 = &dword_C92810;
  unk_C92814 = &dword_C92810;
  if ( (unk_C92820 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C9281C);
}

