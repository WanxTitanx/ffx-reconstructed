// Function: sub_B01490
// Address: 0xb01490
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01490()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAE038;
  v1 = (_DWORD *)unk_CAE03C;
  *(_DWORD *)(dword_CAE038 + 4) = unk_CAE03C;
  *v1 = v0;
  dword_CAE038 = &dword_CAE038;
  unk_CAE03C = &dword_CAE038;
  if ( (unk_CAE048 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAE044);
}

