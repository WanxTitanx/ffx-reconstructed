// Function: sub_AFC910
// Address: 0xafc910
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFC910()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C999B4;
  v1 = (_DWORD *)unk_C999B8;
  *(_DWORD *)(dword_C999B4 + 4) = unk_C999B8;
  *v1 = v0;
  dword_C999B4 = &dword_C999B4;
  unk_C999B8 = &dword_C999B4;
  if ( (unk_C999C4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C999C0);
}

