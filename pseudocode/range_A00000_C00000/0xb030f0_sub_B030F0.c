// Function: sub_B030F0
// Address: 0xb030f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B030F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB2618;
  v1 = (_DWORD *)unk_CB261C;
  *(_DWORD *)(dword_CB2618 + 4) = unk_CB261C;
  *v1 = v0;
  dword_CB2618 = &dword_CB2618;
  unk_CB261C = &dword_CB2618;
  if ( (unk_CB2628 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB2624);
}

