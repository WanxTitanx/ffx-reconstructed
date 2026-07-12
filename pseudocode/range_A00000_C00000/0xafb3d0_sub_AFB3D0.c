// Function: sub_AFB3D0
// Address: 0xafb3d0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB3D0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C94644;
  v1 = (_DWORD *)unk_C94648;
  *(_DWORD *)(dword_C94644 + 4) = unk_C94648;
  *v1 = v0;
  dword_C94644 = &dword_C94644;
  unk_C94648 = &dword_C94644;
  if ( (unk_C94654 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C94650);
}

