// Function: sub_B049A0
// Address: 0xb049a0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B049A0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CBDA88;
  v1 = (_DWORD *)unk_CBDA8C;
  *(_DWORD *)(dword_CBDA88 + 4) = unk_CBDA8C;
  *v1 = v0;
  dword_CBDA88 = &dword_CBDA88;
  unk_CBDA8C = &dword_CBDA88;
  if ( (unk_CBDA98 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CBDA94);
}

