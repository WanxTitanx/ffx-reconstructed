// Function: sub_B01B10
// Address: 0xb01b10
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01B10()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAE93C;
  v1 = (_DWORD *)unk_CAE940;
  *(_DWORD *)(dword_CAE93C + 4) = unk_CAE940;
  *v1 = v0;
  dword_CAE93C = &dword_CAE93C;
  unk_CAE940 = &dword_CAE93C;
  if ( (unk_CAE94C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAE948);
}

