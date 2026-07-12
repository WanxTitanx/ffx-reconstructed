// Function: sub_B01D30
// Address: 0xb01d30
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01D30()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAE98C;
  v1 = (_DWORD *)unk_CAE990;
  *(_DWORD *)(dword_CAE98C + 4) = unk_CAE990;
  *v1 = v0;
  dword_CAE98C = &dword_CAE98C;
  unk_CAE990 = &dword_CAE98C;
  if ( (unk_CAE99C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAE998);
}

