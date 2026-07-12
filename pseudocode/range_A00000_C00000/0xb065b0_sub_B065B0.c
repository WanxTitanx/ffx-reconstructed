// Function: sub_B065B0
// Address: 0xb065b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B065B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CCA25C;
  v1 = (_DWORD *)unk_CCA260;
  *(_DWORD *)(dword_CCA25C + 4) = unk_CCA260;
  *v1 = v0;
  dword_CCA25C = &dword_CCA25C;
  unk_CCA260 = &dword_CCA25C;
  if ( (unk_CCA26C & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_CCA268);
}

