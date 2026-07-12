// Function: sub_B01BB0
// Address: 0xb01bb0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01BB0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAE9B4;
  v1 = (_DWORD *)unk_CAE9B8;
  *(_DWORD *)(dword_CAE9B4 + 4) = unk_CAE9B8;
  *v1 = v0;
  dword_CAE9B4 = &dword_CAE9B4;
  unk_CAE9B8 = &dword_CAE9B4;
  if ( (unk_CAE9C4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAE9C0);
}

