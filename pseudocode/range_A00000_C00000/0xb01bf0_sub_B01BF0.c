// Function: sub_B01BF0
// Address: 0xb01bf0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01BF0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAE964;
  v1 = (_DWORD *)unk_CAE968;
  *(_DWORD *)(dword_CAE964 + 4) = unk_CAE968;
  *v1 = v0;
  dword_CAE964 = &dword_CAE964;
  unk_CAE968 = &dword_CAE964;
  if ( (unk_CAE974 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAE970);
}

