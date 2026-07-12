// Function: sub_B019F0
// Address: 0xb019f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B019F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAE6F4;
  v1 = (_DWORD *)unk_CAE6F8;
  *(_DWORD *)(dword_CAE6F4 + 4) = unk_CAE6F8;
  *v1 = v0;
  dword_CAE6F4 = &dword_CAE6F4;
  unk_CAE6F8 = &dword_CAE6F4;
  if ( (unk_CAE704 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAE700);
}

