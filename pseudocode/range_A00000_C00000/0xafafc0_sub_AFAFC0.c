// Function: sub_AFAFC0
// Address: 0xafafc0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFAFC0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C941C8;
  v1 = (_DWORD *)unk_C941CC;
  *(_DWORD *)(dword_C941C8 + 4) = unk_C941CC;
  *v1 = v0;
  dword_C941C8 = &dword_C941C8;
  unk_C941CC = &dword_C941C8;
  if ( (unk_C941D8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C941D4);
}

